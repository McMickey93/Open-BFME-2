"""Materialize the opt-in BFME patch layer without modifying upstream STLport."""
import hashlib
import os
import re
from pathlib import Path

from portable_lock import lock

ROOT = Path(__file__).resolve().parents[1]
TREE = ROOT / "vendor/stlport-4.6"
PATCHES = ROOT / "vendor/stlport-4.6-bfme"
SHIMS = ("bfmealloc", "bfmealloc_alloconly", "bfmehashtable", "bfmelist")
LOCALE_SOURCE = "src/c_locale_win32/c_locale_win32.c"


def patch_input(rel):
    """Only STL headers and the explicitly migrated locale source are patchable."""
    if (Path(rel).is_absolute() or ".." in Path(rel).parts or "\\" in rel
            or not (rel.startswith("stl/") or rel == LOCALE_SOURCE)):
        raise ValueError("invalid STLport patch path")
    return TREE / rel if rel == LOCALE_SOURCE else TREE / "stlport" / rel


def selected(source):
    if source is None:
        return False
    try:
        return re.search(r"^// stlport46[ \t]*$", Path(source).read_text(encoding="utf-8-sig", errors="replace"), re.M) is not None
    except OSError:
        return False


def verify_tree(tree):
    listed = set()
    for line in (tree / "SHA256SUMS").read_text().splitlines():
        digest, rel = line.split("  ", 1)
        path = tree / rel
        if Path(rel).is_absolute() or ".." in Path(rel).parts or rel in listed:
            raise ValueError("invalid STLport manifest path: " + rel)
        listed.add(rel)
        if not path.is_file() or hashlib.sha256(path.read_bytes()).hexdigest() != digest:
            raise ValueError("STLport 4.6 missing or changed: " + rel)
    actual = {p.relative_to(tree).as_posix() for sub in ("src", "stlport")
              for p in (tree / sub).rglob("*") if p.is_file()} | {"README"}
    if actual != listed:
        raise ValueError("STLport 4.6 manifest inventory differs")


def apply_patch(original, patch):
    """Apply exact unified hunks; refuse fuzzy, stale, or malformed patches."""
    lines = patch.splitlines(keepends=True)
    if len(lines) < 3 or not lines[0].startswith("--- a/") or not lines[1].startswith("+++ b/"):
        raise ValueError("invalid STLport patch headers")
    rel = lines[1][6:].strip()
    if lines[0][6:].strip() != rel:
        raise ValueError("invalid STLport patch path")
    patch_input(rel)
    source = original.splitlines(keepends=True)
    result, cursor, i = [], 0, 2
    while i < len(lines):
        match = re.fullmatch(r"@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@[^\n]*\n", lines[i])
        if match is None:
            raise ValueError("invalid STLport patch hunk")
        start, old_count, new_start, new_count = (int(v) if v is not None else 1 for v in match.groups())
        index = start - 1 if old_count else start
        if index < cursor or index > len(source):
            raise ValueError("overlapping STLport patch hunk")
        result.extend(source[cursor:index]); cursor = index
        if len(result) != (new_start - 1 if new_count else new_start):
            raise ValueError("STLport patch new offset differs")
        i += 1
        old_seen = new_seen = 0
        while i < len(lines) and not lines[i].startswith("@@ "):
            line = lines[i]; i += 1
            if line[0] in " -":
                if cursor >= len(source) or source[cursor] != line[1:]:
                    raise ValueError("STLport patch context differs")
                cursor += 1; old_seen += 1
            if line[0] in " +":
                result.append(line[1:]); new_seen += 1
            if line[0] not in " +-":
                raise ValueError("invalid STLport patch line")
        if (old_seen, new_seen) != (old_count, new_count):
            raise ValueError("STLport patch extent differs")
    result.extend(source[cursor:])
    return rel, "".join(result)


def materialize():
    # Validate even when the compiled object is cached: compiler_environment calls
    # here before cache reuse. Patch bytes enter the generated include path, which
    # enters the normal command receipt; generated headers enter dependency hashes.
    verify_tree(TREE)
    patch_files = sorted(PATCHES.rglob("*.patch"))
    if not patch_files:
        raise ValueError("missing STLport BFME patch layer")
    digest = hashlib.sha256((TREE / "SHA256SUMS").read_bytes())
    for patch in patch_files:
        digest.update(patch.relative_to(PATCHES).as_posix().encode())
        digest.update(patch.read_bytes())
    destination = ROOT / "build/stlport46" / digest.hexdigest()[:24]
    destination.parent.mkdir(parents=True, exist_ok=True)
    with (destination.parent / "materialize.lock").open("a+b") as handle:
        lock(handle, exclusive=True)
        base = {}
        expected = set()
        for patch in patch_files:
            group = patch.relative_to(PATCHES).parts
            parent = "base" if len(group) == 1 else group[0]
            if parent not in ("base",) + SHIMS:
                raise ValueError("unknown STLport overlay: " + parent)
            text = patch.read_text(encoding="utf-8")
            headers = text.splitlines()
            if len(headers) < 2 or not headers[1].startswith("+++ b/"):
                raise ValueError("invalid STLport patch path")
            rel = headers[1][6:].strip()
            input_path = patch_input(rel)
            if rel == LOCALE_SOURCE and parent != "base":
                raise ValueError("invalid STLport patch path")
            # Base patches sort before the named shim directories (underscore filenames).
            original = base.get(rel, input_path.read_text(encoding="utf-8"))
            checked_rel, transformed = apply_patch(original, text)
            assert checked_rel == rel
            if parent == "base":
                base[rel] = transformed
            target = destination / parent / rel
            expected.add(target.relative_to(destination).as_posix())
            payload = ("// Modified for Open-BFME: opt-in STLport 4.6 overlay.\n" + transformed).encode()
            if not target.exists() or target.read_bytes() != payload:
                target.parent.mkdir(parents=True, exist_ok=True)
                temp = target.with_suffix(target.suffix + ".tmp")
                temp.write_bytes(payload); os.replace(temp, target)
        actual = {p.relative_to(destination).as_posix() for p in destination.rglob("*") if p.is_file()}
        if actual != expected:
            raise ValueError("unlisted generated STLport overlay file")
    return destination


def include_dirs(source, flags):
    """Return mapped explicit flags and a final base overlay include directory."""
    if not selected(source):
        return flags
    overlay = materialize()
    mapped = []
    for flag in flags:
        normalized = flag[2:].replace("\\", "/").rstrip("/") if flag.startswith(("-I", "/I")) else ""
        shim = next((s for s in SHIMS if normalized == "reference/shims/" + s), None)
        if shim:
            mapped.append("-I" + (overlay / shim).relative_to(ROOT).as_posix())
        else:
            mapped.append(flag)
    return mapped + ["-I" + (overlay / "base").relative_to(ROOT).as_posix()]
