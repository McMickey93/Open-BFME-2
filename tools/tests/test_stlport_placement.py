"""Exercise the real hook placement allowlist without bypassing any gates."""
import re
import shutil
import sys
import subprocess
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[2]

@pytest.mark.parametrize("path,accepted", [
    ("vendor/stlport-4.6/src/locale.cpp", True),
    ("vendor/stlport-4.6/stlport/stl/_alloc.h", True),
    ("Code/Libraries/Source/STLport/LocaleFacets.cpp", True),
    ("vendor/stlport-4.6/injected.cpp", False),
    ("vendor/other/src/locale.cpp", False),
    ("src/locale.cpp", False),
])
def test_stlport_import_has_a_bounded_placement_exception(path, accepted):
    hook = (ROOT / ".githooks/pre-commit").read_text()
    block = re.search(r'case "\$path" in\n(.*?)\n    esac\ndone < <\(grep', hook, re.S).group(1)
    # Select the final case block, not earlier unrelated hook checks.
    block = block.rsplit('case "$path" in\n', 1)[-1]
    script = 'fail() { exit 1; }; path="$1"; case "$path" in\n' + block + '\nesac'
    bash = "C:/Program Files/Git/bin/bash.exe" if sys.platform == "win32" else shutil.which("bash")
    result = subprocess.run([bash, "-c", script, "placement", path], capture_output=True)
    assert (result.returncode == 0) == accepted, result.stderr.decode(errors="replace")

