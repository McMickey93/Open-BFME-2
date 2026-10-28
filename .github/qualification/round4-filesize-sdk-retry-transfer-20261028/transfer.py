"""Commit the reviewed source through native hooks; publish receipts only in this public fork."""
import base64, hashlib, json, os, subprocess, sys, time, urllib.request
from pathlib import Path

CONTROL = Path(__file__).resolve().parent
DATA = json.loads((CONTROL / "manifest.json").read_text(encoding="utf-8"))
ROOT = Path.cwd()
OUT = ROOT.parent / "source-transfer-evidence"
OUT.mkdir(exist_ok=True)
RESULT = {"schema": 1, "status": "starting", "outcome": "sdk-cleanup", "commands": []}

def require(ok, message):
    if not ok:
        raise RuntimeError(message)

def save():
    (OUT / "result.json").write_text(json.dumps(RESULT, indent=2) + "\n", encoding="utf-8")

def run(label, args, stdin=None, env=None):
    print(">>> " + label, flush=True)
    log = OUT / ("%02d-%s.log" % (len(RESULT["commands"]), label))
    entry = {"label": label, "exit_code": None, "log": log.name}
    RESULT["commands"].append(entry)
    save()
    with log.open("wb") as stream:
        proc = subprocess.Popen([str(x) for x in args], cwd=ROOT, env=env,
                                stdin=subprocess.PIPE if stdin is not None else subprocess.DEVNULL,
                                stdout=stream, stderr=subprocess.STDOUT)
        if stdin is not None:
            proc.stdin.write(stdin)
            proc.stdin.close()
        deadline = time.monotonic() + 600
        while proc.poll() is None:
            if time.monotonic() > deadline:
                proc.terminate()
                proc.wait(timeout=30)
                entry["exit_code"] = proc.returncode
                save()
                raise RuntimeError(label + " exceeded its ten-minute command limit")
            try:
                proc.wait(timeout=25)
            except subprocess.TimeoutExpired:
                print("    " + label + ": still running", flush=True)
        entry["exit_code"] = proc.returncode
    save()
    output = log.read_bytes()
    print(output.decode("utf-8", errors="replace")[-3000:], flush=True)
    require(proc.returncode == 0, label + " failed")
    return output

def git(label, *args, **kwargs):
    return run(label, ["git", *args], **kwargs)

def rev(ref):
    return subprocess.check_output(["git", "rev-parse", "--verify", ref], cwd=ROOT, text=True).strip()

def claim():
    for ref in DATA["claim_refs"]:
        git("fetch-own-claim", "fetch", "-q", "--depth=1", "--no-tags", "--recurse-submodules=no", "origin", ref)
        info = json.loads(subprocess.check_output(["git", "show", "-s", "--format=%B", "FETCH_HEAD"], cwd=ROOT, text=True))
        require(info.get("owner") == DATA["claim_owner"] and info.get("lease") == DATA["claim_lease"]
                and info.get("expires", 0) > time.time(), "Reservation changed: " + ref)
    foreign = git("fresh-target-scope-reservations", "ls-remote", "--refs", "origin", *DATA["foreign_claim_refs"])
    require(not foreign.strip(), "A foreign namespace or type reservation needs review")


def object_path(source):
    sys.path.insert(0, str(ROOT / "tools"))
    import build
    return build.obj_path(Path(source))

def coff_summary(path, rename=None):
    import struct
    data = Path(path).read_bytes()
    u16 = lambda p: struct.unpack_from("<H", data, p)[0]
    u32 = lambda p: struct.unpack_from("<I", data, p)[0]
    i16 = lambda p: struct.unpack_from("<h", data, p)[0]
    require(u16(0) == 0x14c, "Expected x86 COFF")
    count, at = u32(12), u32(8)
    strings = at + count * 18
    symbols, defined, undefined = {}, [], []
    i = 0
    while i < count:
        p = at + i * 18
        start = strings + u32(p + 4) if u32(p) == 0 else p
        stop = data.index(b"\0", start) if u32(p) == 0 else p + 8
        name = data[start:stop].split(b"\0", 1)[0].decode("ascii")
        sym = (name, u32(p + 8), i16(p + 12), data[p + 16])
        symbols[i] = sym
        if sym[3] == 2:
            (undefined if sym[2] == 0 and sym[1] == 0 else defined).append(name)
        i += 1 + data[p + 17]
    sections = []
    for n in range(u16(2)):
        h = 20 + u16(16) + n * 40
        name = data[h:h + 8].split(b"\0", 1)[0].decode("ascii")
        if name.startswith(".debug"):
            continue
        size, raw, rel_at, rel_count = u32(h + 16), u32(h + 20), u32(h + 24), u16(h + 32)
        relocs = []
        for j in range(rel_count):
            p = rel_at + 10 * j
            sym = symbols[u32(p + 4)]
            target = ("local", sym[2], sym[1]) if sym[3] != 2 and sym[2] > 0 else (
                "external", (rename or {}).get(sym[0], sym[0]))
            relocs.append((u32(p), u16(p + 8), target))
        sections.append((n + 1, name, u32(h + 36), size,
                         data[raw:raw + size].hex() if raw else None, relocs))
    return sections, sorted(defined), sorted(undefined)

def verify_object_same(before, after):
    a = coff_summary(before)
    b = coff_summary(after)
    require(a == b, "Runtime COFF sections, relocations or external symbols changed")
    require("__imp__GetFileSize@8" in b[2] and "__imp__GetLastError@0" in b[2], "Expected imports absent")
    proof = {"runtime_sections_identical": True, "section_count": len(b[0]),
             "external_definitions_identical": True, "undefined_symbols_identical": True,
             "imports": ["__imp__GetFileSize@8", "__imp__GetLastError@0"]}
    (OUT / "object-proof.json").write_text(json.dumps(proof, indent=2) + "\n", encoding="utf-8")
    RESULT["object_proof"] = proof
    save()
    return proof

def freshness_preflight():
    old = rev("HEAD:reference/open-bfme-1")
    require(old == DATA["old_reference"], "Reference changed before freshness check")
    git("fetch-current-bfme1-master", "-C", "reference/open-bfme-1", "fetch", "--no-tags",
        "--depth=1", "--recurse-submodules=no", "origin", "master")
    fetched = subprocess.check_output(["git", "-C", "reference/open-bfme-1", "rev-parse", "FETCH_HEAD"],
                                     cwd=ROOT, text=True).strip()
    require(fetched != old, "Reference is current: re-evaluate the planned blocked-update preflight")
    run("current-native-reference-witnesses", [sys.executable, "tools/build.py", *DATA["witness_sources"]])
    code = ("import sys;sys.path.insert(0,'tools');import build;"
            "sources=" + repr(DATA["witness_sources"]) + ";"
            "rows=[r for r in build.load_function_rows() if r['source'] in sources];"
            "print('SCOPED current DIR32 witness; not a full verification');"
            "build.verify_dir32_consistency(rows)")
    log = OUT / "current-reference-dir32-witness.log"
    with log.open("wb") as stream:
        proc = subprocess.run([sys.executable, "-c", code], cwd=ROOT, stdout=stream,
                              stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
    output = log.read_text(encoding="utf-8", errors="replace")
    print(output[-5000:], flush=True)
    require(proc.returncode == 1 and "??_7Rva0035A97EVisitor@@6B@" in output
            and "c153d4" in output.lower() and "c1c780" in output.lower(),
            "Known pre-existing reference blocker was not reproduced: stop for review")
    RESULT["reference_preflight"] = {"retained_reference": old, "fetched_bfme1_master": fetched,
        "diagnostic_exit": proc.returncode, "log": log.name,
        "witness_symbol": "??_7Rva0035A97EVisitor@@6B@", "bases": ["0x00c153d4", "0x00c1c780"],
        "native_witness_sources": DATA["witness_sources"], "full_gate_run": False,
        "updated_reference_verified": False, "success_stamp_written": False}
    save()


def preview(label):
    print(">>> " + label + " (diagnostic; actual exit code retained)", flush=True)
    log = OUT / (label + ".log")
    with log.open("wb") as stream:
        proc = subprocess.Popen([sys.executable, "tools/link_check.py",
                                 *DATA["verify_sources"], "--compile-limit", "0", "--hook", "--deadline", "30"],
                                cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT,
                                stdin=subprocess.DEVNULL)
        while proc.poll() is None:
            try:
                proc.wait(timeout=25)
            except subprocess.TimeoutExpired:
                print("    " + label + ": still running", flush=True)
    output = log.read_text(encoding="utf-8", errors="replace")
    verdict = "unknown-or-unresolved" if proc.returncode else "completed"
    entry = {"label": label, "exit_code": proc.returncode, "verdict": verdict, "log": log.name}
    RESULT.setdefault("link_previews", []).append(entry)
    save()
    print(output[-4000:], flush=True)
    return entry

def actual_release():
    # Generate the original branch-host release marker; the app applies its
    # fresh fencing tokens only after publication and the final progress check.
    sys.path.insert(0, str(ROOT / "tools"))
    import claims
    made = claims._record(DATA["claim_owner"], 0, "released")
    record = json.loads(subprocess.check_output(["git", "show", "-s", "--format=%B", made], cwd=ROOT, text=True))
    record.pop("host", None)
    require(record.get("owner") == DATA["claim_owner"] and record.get("note") == "released"
            and record.get("expires", time.time() + 1) <= time.time(), "Invalid project release marker")
    (OUT / "release-record.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    return record

def main():
    token = os.environ.pop("BFME_TRANSFER_TOKEN", "")
    require(token and "\n" not in token and "\r" not in token, "Fork credential absent")
    require(sys.platform == "win32" and sys.version_info[:2] == (3, 12), "Native Windows Python 3.12 required")
    require(os.environ["GITHUB_REPOSITORY"] == DATA["fork"]
            and os.environ["GITHUB_REF"] == "refs/heads/" + DATA["control_branch"]
            and os.environ["GITHUB_EVENT_NAME"] == "create", "Wrong workflow context")
    event = json.loads(Path(os.environ["GITHUB_EVENT_PATH"]).read_text(encoding="utf-8"))
    require(event["repository"]["fork"] is True and event["repository"]["private"] is False
            and event["ref_type"] == "branch" and event["ref"] == DATA["control_branch"], "Wrong fork event")
    require(rev("HEAD") == DATA["base"] and rev("HEAD:AGENTS.md") == DATA["agents_blob"], "Wrong initial base or AGENTS")
    require(DATA.get("native_preparation") is True, "Reviewed native preparation required")
    require(not os.environ.get("BUILD_RECOMPILE_ONLY") and not os.environ.get("CL") and not os.environ.get("_CL_"),
            "Unexpected compiler override")
    git("public-author", "config", "user.name", "McMickey93")
    git("public-email", "config", "user.email", "347452154+McMickey93@users.noreply.github.com")
    git("new-native-branch", "switch", "-c", DATA["branch"].removeprefix("refs/heads/"))
    require(rev("HEAD:" + DATA["source"]) == DATA["source_before"], "Source preimage changed")
    for path, digest in DATA["reviewed_blobs"].items():
        require(rev("HEAD:" + path) == digest, "Reviewed input changed: " + path)
    bash = os.environ["BFME_QUALIFICATION_BASH"]
    require(Path(bash).is_file(), "Real Git Bash missing")
    git("verified-canonical-reference", "-c", "submodule.recurse=false", "submodule", "update",
        "--init", "--depth=1", "--", "reference/open-bfme-1")
    run("verification-requirements", [sys.executable, "-m", "pip", "install",
        "--disable-pip-version-check", "-r", "reference/open-bfme-1/tools/requirements.txt"])
    run("normal-hook-setup", [bash, "tools/setup_hooks.sh"])
    claim()
    run("pre-edit-frozen-body-check", [sys.executable, "tools/find_declared_unmatched.py", DATA["source"]])
    freshness_preflight()
    run("paired-original-byte-verification", [sys.executable, "tools/build.py", DATA["source"]])
    run("original-header-audit", [sys.executable, "tools/ms_header_audit.py", "show", DATA["source"]])
    original_object = OUT / "helper-before.obj"
    original_object.write_bytes(object_path(DATA["source"]).read_bytes())
    original_queue = (ROOT / "reverse/ms_header_queue.tsv").read_bytes()
    planned = (CONTROL / "planned-source.cpp.txt").read_bytes().replace(b"\r\n", b"\n")
    require(hashlib.sha1(b"blob " + str(len(planned)).encode() + b"\0" + planned).hexdigest()
            == DATA["source_blob"], "Reviewed source blob differs")
    (ROOT / DATA["source"]).write_bytes(planned)
    run("paired-modified-byte-verification", [sys.executable, "tools/build.py", DATA["source"]])
    changed_object = OUT / "helper-after.obj"
    changed_object.write_bytes(object_path(DATA["source"]).read_bytes())
    proof = verify_object_same(original_object, changed_object)
    run("sdk-helper-eh-verification", [sys.executable, "tools/eh_verify.py", DATA["source"]])
    meta = json.loads(object_path(DATA["source"]).with_suffix(".deps.json").read_text(encoding="utf-8"))
    sdk_deps = [k for k in meta["deps"] if k.replace("\\", "/").lower().endswith("/vc7/platformsdk/include/windows.h")]
    require(len(sdk_deps) == 1 and (ROOT / sdk_deps[0]).is_file(), "Real Platform SDK windows.h absent from dependency receipt")
    RESULT["sdk_header_dependency"] = sdk_deps[0].replace("\\", "/")
    save()
    audit_code = (
        "import sys;from pathlib import Path;sys.path.insert(0,'tools');import ms_header_audit as a;"
        "p=" + repr(DATA["source"]) + ";i=a.load_index(jobs=1);r=a.scan_text(p,Path(p).read_text(encoding='latin-1'),i);"
        "assert not r.get('error'),r;assert a.classify(p,r,i)[0] is None,'Local Microsoft definitions remain';"
        "assert not [o for o in r['occ'] if o[3] not in a.NOT_DEFINITIONS],r;"
        "assert a.refresh_queue({p:r},i,occurrences=Path('build/round4-sdk-ms-occurrences.tsv')),'Queue was not retired';"
        "print('Scoped queue refresh: clean; no local Microsoft definitions')")
    run("scoped-ms-header-queue-refresh", [sys.executable, "-c", audit_code])
    expected_queue = b"".join(line for line in original_queue.splitlines(keepends=True)
        if line.split(b"\t", 1)[0].decode("utf-8") != DATA["source"])
    require((ROOT / "reverse/ms_header_queue.tsv").read_bytes() == expected_queue,
            "Unrelated header queue rows changed")
    run("real-header-declaration-check", [sys.executable, "tools/ms_header_audit.py", "check", DATA["source"]])
    run("declared-body-check", [sys.executable, "tools/find_declared_unmatched.py", DATA["source"]])
    note = (CONTROL / "evidence.md").read_text(encoding="utf-8")
    note += "\n## Native qualification receipts\n\n"
    note += "Original and updated source each verify the existing 50-byte body at RVA 0x0001D240 with the unmodified original-compiler driver.\n"
    note += "Runtime COFF sections, relocation targets, external definitions and undefined symbols are identical. EH verification passes.\n"
    note += "The normal compiler dependency receipt records the vendored Vc7/PlatformSDK/Include/windows.h.\n"
    note += "The owning Microsoft-header audit classifies the updated file as clean; its scoped refresh removes only this file's two-definition queue row.\n"
    ref = RESULT["reference_preflight"]
    note += "\n## Reference freshness preflight\n\n"
    note += "Fetched official BFME 1 master: " + ref["fetched_bfme1_master"] + ". Retained canonical inputs: " + ref["retained_reference"] + ".\n"
    note += "A fresh normal native build of both listed TerrainResourceManager witness TUs reproduces the pre-existing DIR32 consistency conflict: ??_7Rva0035A97EVisitor@@6B@ resolves to 0x00c153d4 and 0x00c1c780. The actual scoped consistency check exits 1.\n"
    note += "This is a positive scoped blocker witness, not a full old/new gate or successful reference update. No reference pointer or success stamp is changed. The prior full comparison is recorded in 20261027-bfme1-reference-refresh.md; the committed canonical reference has since been advanced upstream with published full verification receipts.\n"
    note += "Independent SDK cleanup remains qualified against the retained canonical inputs. Future sessions must retry freshness after the remaining gate debt is repaired.\n"
    note += "\nWindows evidence: https://github.com/" + DATA["fork"] + "/actions/runs/" + os.environ["GITHUB_RUN_ID"] + "\n"
    (ROOT / DATA["evidence"]).write_text(note, encoding="utf-8", newline="\n")
    run("record-filesize-sdk-cleanup", [sys.executable, "tools/re_log.py", "record",
        "?Rva00849E80FileSize@@YAJPAX@Z", "0x0001D240", "50", "solved",
        "t=%smin model=OpenAI-Codex real Windows SDK header cleanup; " % max(1, int((time.time()-DATA["started"]+59)//60)) +
        "native original/updated 50B body and import refs verify; runtime COFF sections, relocs, definitions and undefineds identical; "
        "SDK dependency receipt proves real windows.h; two local API declarations and private LARGE_INTEGER removed; "
        "owning scoped ms_header_audit refresh retires only this file; no new C++ bytes or census gain. "
        "Canonical BFME1 reference retained after fresh pre-existing scoped DIR32 blocker witness. Evidence: " + DATA["evidence"]])
    git("stage-exact-reviewed-paths", "add", "--", *DATA["files"])
    require(rev(":" + DATA["source"]) == DATA["source_blob"], "Staged source differs")
    message = OUT / "source-commit-message.txt"
    message.write_text(DATA["commit_message"], encoding="utf-8")
    git("normal-native-commit", "commit", "-F", str(message))
    prepared_commit = rev("HEAD")
    original_source = rev("HEAD:" + DATA["source"])
    require(original_source == DATA["source_blob"], "Committed source differs")
    RESULT.update(normal_precommit_passed=True, native_commit=prepared_commit)
    save()
    installed = True
    expected = DATA["transport_expected"]

    def fork_api(path, payload):
        req = urllib.request.Request("https://api.github.com/repos/" + DATA["fork"] + "/git/" + path,
              data=json.dumps(payload).encode("utf-8"),
              headers={"Authorization": "Bearer " + token, "Accept": "application/vnd.github+json",
                       "X-GitHub-Api-Version": "2022-11-28", "Content-Type": "application/json"},
              method="POST")
        try:
            with urllib.request.urlopen(req, timeout=30) as response:
                return json.load(response)
        except urllib.error.HTTPError as error:
            raise RuntimeError("Fork metadata API " + str(error.code) + ": " +
                               error.read().decode("utf-8", errors="replace")[:2000]) from error
    for attempt in range(16):
        print("PUBLICATION_ATTEMPT " + str(attempt + 1), flush=True)
        git("normal-rebase", "pull", "--rebase", "origin", "master")
        require(rev("HEAD:AGENTS.md") == DATA["agents_blob"], "AGENTS changed: review required")
        require(rev("HEAD:" + DATA["source"]) == original_source, "Reviewed consumer changed")
        for path, digest in DATA["reviewed_blobs"].items():
            require(rev("HEAD:" + path) == digest, "Reviewed provider or consumer changed: " + path)
        base, tip = rev("origin/master"), rev("HEAD")
        changed = set(subprocess.check_output(["git", "diff", "--name-only", "-z", base, tip], cwd=ROOT).decode().strip("\0").split("\0"))
        require(changed == set(DATA["files"]), "Unexpected outgoing paths")
        require(subprocess.check_output(["git", "rev-list", "--count", base + ".." + tip], cwd=ROOT, text=True).strip() == "1", "Not one source commit")
        git("reference-inputs", "-c", "submodule.recurse=false", "submodule", "status", "--", "reference/open-bfme-1")
        bash = os.environ["BFME_QUALIFICATION_BASH"]
        require(Path(bash).is_file(), "Real Git Bash missing")
        if not installed:
            run("verification-requirements", [sys.executable, "-m", "pip", "install", "--disable-pip-version-check", "-r",
                                            "tools/requirements.txt"])
            run("normal-hook-setup", [bash, "tools/setup_hooks.sh"])
            installed = True
        claim()
        wire = (DATA["branch"] + " " + tip + " refs/heads/master " + base + "\n").encode()
        run("actual-official-pre-push", [bash, ".githooks/pre-push", "origin",
                                       "https://github.com/Open-BFME/Open-BFME-2.git"], stdin=wire)
        run("helper-publication-byte-verification", [sys.executable, "tools/build.py", *DATA["verify_sources"]])
        run("declared-body-recheck", [sys.executable, "tools/find_declared_unmatched.py", DATA["source"]])
        claim()
        git("refresh-before-transfer", "fetch", "-q", "--no-tags", "--recurse-submodules=no", "origin", "master")
        if rev("origin/master") != base:
            print("UPSTREAM_MOVED: rebase and run the normal gate again", flush=True)
            continue
        run("required-progress", [sys.executable, "tools/progress.py", "origin/master"])
        git("preseed-fast-forward-lineage", "merge-base", "--is-ancestor", DATA["base"], tip)
        RESULT.update(status="qualified", base=base, commit=tip, tree=rev("HEAD^{tree}"),
                      normal_official_prepush_passed=True, new_cpp_bytes=0)
        save()
        print("QUALIFIED_SOURCE " + json.dumps(RESULT), flush=True)
        url = "https://github.com/McMickey93/Open-BFME-2.git"
        target = "refs/heads/" + DATA["result_branch"]
        env = dict(os.environ)
        count = int(env.get("GIT_CONFIG_COUNT", "0"))
        auth = "AUTHORIZATION: basic " + base64.b64encode(("x-access-token:" + token).encode()).decode()
        env.update({"GIT_CONFIG_COUNT": str(count + 1), "GIT_CONFIG_KEY_" + str(count): "http." + url + ".extraheader",
                    "GIT_CONFIG_VALUE_" + str(count): auth, "GIT_TERMINAL_PROMPT": "0"})
        # Publish only checkpoint.json on a new, parentless fork metadata branch.
        # The app bridge seeds the transport branch at this exact official base.
        # Thus the unmodified fork push hook verifies our one-commit delta.
        checkpoint = dict(RESULT, status="awaiting-fork-base", run_id=os.environ["GITHUB_RUN_ID"],
                          source_blob=original_source, files=sorted(changed), attempt=attempt + 1)
        public_identity = {"name": "McMickey93", "email": "347452154+McMickey93@users.noreply.github.com"}
        checkpoint_text = json.dumps(checkpoint, sort_keys=True)
        metadata_tree = fork_api("trees", {"tree": [{"path": "checkpoint.json", "mode": "100644",
                                    "type": "blob", "content": checkpoint_text + "\n"}]})["sha"]
        metadata = fork_api("commits", {"message": checkpoint_text,
                    "tree": metadata_tree, "parents": [], "author": public_identity, "committer": public_identity})
        checkpoint_ref = "refs/heads/" + DATA["checkpoint_prefix"] + "-" + str(attempt + 1)
        fork_api("refs", {"ref": checkpoint_ref, "sha": metadata["sha"]})
        print("FORK_BASE_CHECKPOINT " + checkpoint_ref + " " + base, flush=True)
        deadline = time.monotonic() + 600
        while True:
            observed = subprocess.check_output(["git", "ls-remote", "--exit-code", url, target],
                                               cwd=ROOT, text=True).split()
            require(len(observed) == 2 and observed[1] == target, "Transport ref absent")
            if observed[0] == base:
                expected = base
                break
            require(time.monotonic() < deadline, "Awaiting exact fork base timed out")
            time.sleep(5)
        claim()
        git("refresh-after-fork-base", "fetch", "-q", "--no-tags", "--recurse-submodules=no", "origin", "master")
        if rev("origin/master") != base:
            print("UPSTREAM_MOVED: qualify the new official parent before transferring", flush=True)
            continue
        git("normal-hook-fork-push", "-c", "core.hooksPath=.githooks", "push", "--porcelain",
            "--force-with-lease=" + target + ":" + expected, url, "HEAD:" + target, env=env)
        expected = tip
        readback = git("fork-readback", "ls-remote", "--exit-code", url, target).decode().split()
        require(readback == [tip, target], "Fork readback differs")
        git("refresh-after-transfer", "fetch", "-q", "--no-tags", "--recurse-submodules=no", "origin", "master")
        if rev("origin/master") != base:
            print("UPSTREAM_MOVED: native objects banked; rebase and qualify the new parent", flush=True)
            continue
        RESULT.update(status="transferred", base=base, commit=tip, tree=rev("HEAD^{tree}"),
                      source_blob=original_source, normal_official_prepush_passed=True,
                      normal_fork_push_passed=True, files=sorted(changed), new_cpp_bytes=0)
        save()
        # Expose the completed normal-push receipt before artifact upload/cleanup.
        # This fork-only metadata lets the app perform a prompt expected-base CAS.
        complete = dict(RESULT, run_id=os.environ["GITHUB_RUN_ID"],
                        native_commit=prepared_commit, agents_blob=DATA["agents_blob"])
        complete_text = json.dumps(complete, sort_keys=True)
        complete_tree = fork_api("trees", {"tree": [{"path": "result.json", "mode": "100644",
                                     "type": "blob", "content": complete_text + "\n"}]})["sha"]
        complete_commit = fork_api("commits", {"message": complete_text,
                         "tree": complete_tree, "parents": [], "author": public_identity,
                         "committer": public_identity})
        fork_api("refs", {"ref": "refs/heads/" + DATA["completion_branch"] + "-" + str(attempt + 1),
                         "sha": complete_commit["sha"]})
        print("SOURCE_TRANSFER_COMPLETE " + json.dumps(RESULT), flush=True)
        # Let the app apply its expected-base CAS promptly; retry in this same
        # already-prepared runner when another worker wins the publication race.
        publication_deadline = time.monotonic() + 300
        while time.monotonic() < publication_deadline:
            observed_master = subprocess.check_output(
                ["git", "ls-remote", "--exit-code", "origin", "refs/heads/master"],
                cwd=ROOT, text=True).split()
            require(len(observed_master) == 2 and observed_master[1] == "refs/heads/master",
                    "Official master readback absent")
            published = observed_master[0] == tip
            if observed_master[0] != base and not published:
                git("refresh-publication-readback", "fetch", "-q", "--no-tags",
                    "--recurse-submodules=no", "origin", "master")
                ancestry = subprocess.run(["git", "merge-base", "--is-ancestor", tip,
                                           "origin/master"], cwd=ROOT)
                require(ancestry.returncode in (0, 1), "Official ancestry check failed")
                published = ancestry.returncode == 0
                if not published:
                    print("UPSTREAM_MOVED: rebase and repeat every normal gate before publication", flush=True)
                    break
            if published:
                RESULT.update(status="published")
                save()
                git("normal-post-publication-pull", "pull", "--rebase", "origin", "master")
                run("required-final-progress", [sys.executable, "tools/progress.py", "origin/master"])
                record = actual_release()
                observed_claim = subprocess.check_output(
                    ["git", "ls-remote", "--exit-code", "origin", DATA["claim_ref"]],
                    cwd=ROOT, text=True).split()
                require(len(observed_claim) == 2 and observed_claim[1] == DATA["claim_ref"],
                        "Release claim ref absent")
                observed_claims = {}
                for ref in DATA["claim_refs"]:
                    parts = subprocess.check_output(["git", "ls-remote", "--exit-code", "origin", ref], cwd=ROOT, text=True).split()
                    require(len(parts) == 2 and parts[1] == ref, "Reservation readback absent")
                    observed_claims[ref] = parts[0]
                release = {"schema": 1, "run_id": os.environ["GITHUB_RUN_ID"],
                           "source_commit": tip, "claim_ref": DATA["claim_ref"],
                           "observed_claim": observed_claim[0], "observed_claims": observed_claims,
                           "claim_refs": DATA["claim_refs"], "owner": DATA["claim_owner"],
                           "lease": DATA["claim_lease"], "record": record}
                release_text = json.dumps(release, sort_keys=True)
                release_tree = fork_api("trees", {"tree": [{"path": "release.json", "mode": "100644",
                    "type": "blob", "content": release_text + "\n"}]})["sha"]
                release_commit = fork_api("commits", {"message": release_text, "tree": release_tree,
                    "parents": [], "author": public_identity, "committer": public_identity})
                fork_api("refs", {"ref": "refs/heads/" + DATA["release_branch"],
                                 "sha": release_commit["sha"]})
                RESULT.update(claim_release_metadata_emitted=True, final_progress_passed=True)
                save()
                print("SOURCE_PUBLICATION_COMPLETE " + json.dumps(RESULT), flush=True)
                return
            time.sleep(3)
        else:
            raise RuntimeError("Awaiting app expected-base publication timed out; verified native objects remain banked")
    raise RuntimeError("Upstream did not settle within sixteen verified attempts; native objects remain banked")

try:
    main()
except BaseException:
    RESULT["status"] = "failed"
    save()
    raise
