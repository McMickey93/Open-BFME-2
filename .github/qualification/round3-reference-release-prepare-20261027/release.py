import json, os, subprocess, sys, time, urllib.request
from pathlib import Path
CONTROL = Path(__file__).resolve().parent
DATA = json.loads((CONTROL / "manifest.json").read_text())
ROOT = Path.cwd()
token = os.environ.pop("BFME_TRANSFER_TOKEN")
def git(*args):
    return subprocess.check_output(["git", *args], cwd=ROOT, text=True).strip()
def require(test, message):
    if not test:
        raise RuntimeError(message)
require(os.environ["GITHUB_REPOSITORY"] == DATA["fork"]
        and os.environ["GITHUB_REF"] == "refs/heads/" + DATA["cleanup_branch"],
        "Wrong cleanup context")
require(git("rev-parse", "HEAD") == DATA["generation_revision"], "Wrong claim-generator checkout")
require(git("rev-parse", "HEAD:tools/claims.py") == DATA["claims_blob"], "Claim generator changed")
require(git("rev-parse", "HEAD:AGENTS.md") == DATA["agents_blob"], "AGENTS changed")
git("fetch", "-q", "--depth=1", "--no-tags", "--recurse-submodules=no",
    "origin", DATA["claim_ref"])
observed = git("rev-parse", "FETCH_HEAD")
info = json.loads(git("show", "-s", "--format=%B", observed))
require(info.get("owner") == DATA["claim_owner"]
        and info.get("lease") == DATA["claim_lease"], "Reservation ownership changed")
require(info.get("expires", 0) > time.time(), "Reservation already expired; recheck instead of overwriting")
sys.path.insert(0, str(ROOT / "tools"))
import claims
# Generate the original branch-host release marker; do not update any official ref.
# The app applies this only after official publication and final progress verification.
made = claims._record(DATA["claim_owner"], -1, "released")
record = json.loads(git("show", "-s", "--format=%B", made))
record.pop("host", None)
require(record.get("note") == "released" and record["expires"] <= time.time(),
        "Project did not produce an expired release marker")
packet = {"schema": 1, "run_id": os.environ["GITHUB_RUN_ID"],
          "generation_revision": DATA["generation_revision"], "qualification_run": DATA["qualification_run"],
          "phase": "prepared-expired-record-only", "claim_ref": DATA["claim_ref"],
          "observed_claim": observed, "owner": DATA["claim_owner"],
          "lease": DATA["claim_lease"], "record": record}
text = json.dumps(packet, sort_keys=True)
print("CLAIM_RELEASE_METADATA " + text, flush=True)
def api(path, payload):
    req = urllib.request.Request("https://api.github.com/repos/" + DATA["fork"] + "/git/" + path,
        data=json.dumps(payload).encode(),
        headers={"Authorization": "Bearer " + token, "Accept": "application/vnd.github+json",
                 "Content-Type": "application/json"}, method="POST")
    with urllib.request.urlopen(req, timeout=30) as response:
        return json.load(response)
identity = {"name": "McMickey93", "email": "347452154+McMickey93@users.noreply.github.com"}
tree = api("trees", {"tree": [{"path": "release.json", "mode": "100644",
                              "type": "blob", "content": text + "\n"}]})["sha"]
commit = api("commits", {"message": text, "tree": tree, "parents": [],
                         "author": identity, "committer": identity})["sha"]
api("refs", {"ref": "refs/heads/" + DATA["release_branch"], "sha": commit})
print("CLAIM_RELEASE_METADATA_PUBLISHED", flush=True)
