"""Read-only session finalization for the normally committed/pushed SDK cleanup."""
import base64, json, os, subprocess, sys, time, urllib.request
from pathlib import Path

ROOT = Path.cwd()
OUT = ROOT.parent / "session-final-evidence"
OUT.mkdir(exist_ok=True)
FORK = "McMickey93/Open-BFME-2"
SOURCE = "Code/stlport/FileSizeHelper.cpp"
TIP = "b68907753fd95893ac590a1ea4f69833e8411488"
SOURCE_BLOB = "27b5e219e22cf3f81740d7c26a813428f58c523f"
OWNER = "github:McMickey93:bfme2:round4-20261028"
LEASE = "deaf68660cc641a6aa1a4d2e24790fe2"
REFS = ["refs/heads/claims/0x0001D240", "refs/heads/claims/file/0b4a7f866d179718"]
RESULT = {"schema": 1, "source_commit": TIP, "source_blob": SOURCE_BLOB,
          "mode": "banked-verified-cleanup-protected-master", "commands": [],
          "qualification_run": 40731823379, "pr": 125}
TOKEN = os.environ.pop("BFME_FINAL_TOKEN", "")
def need(ok, message):
    if not ok: raise RuntimeError(message)
def save():
    (OUT / "result.json").write_text(json.dumps(RESULT, indent=2) + "\n", encoding="utf-8")
def command(label, args):
    log = OUT / (label + ".log")
    print(">>> " + label, flush=True)
    with log.open("wb") as stream:
        proc = subprocess.Popen(args, cwd=ROOT, stdout=stream, stderr=subprocess.STDOUT,
                                stdin=subprocess.DEVNULL)
        started = time.monotonic()
        while proc.poll() is None:
            need(time.monotonic() - started < 1200, label + " exceeded twenty minutes")
            try: proc.wait(timeout=25)
            except subprocess.TimeoutExpired: print(label + ": still running", flush=True)
    RESULT["commands"].append({"label": label, "exit_code": proc.returncode, "log": log.name})
    save()
    print(log.read_text(encoding="utf-8", errors="replace")[-4500:], flush=True)
    need(proc.returncode == 0, label + " failed")
def api(path, body=None):
    need(path.startswith("repos/" + FORK + "/"), "Only the owned public fork API is allowed")
    request = urllib.request.Request("https://api.github.com/" + path,
        data=None if body is None else json.dumps(body).encode("utf-8"),
        headers={"Authorization": "Bearer " + TOKEN, "Accept": "application/vnd.github+json",
                 "Content-Type": "application/json"},
        method="GET" if body is None else "POST")
    with urllib.request.urlopen(request, timeout=30) as response:
        return json.load(response)
def rev(ref):
    return subprocess.check_output(["git", "rev-parse", "--verify", ref], cwd=ROOT, text=True).strip()
def main():
    need(sys.platform == "win32" and sys.version_info[:2] == (3,12), "Native Windows Python 3.12 required")
    need(TOKEN and "\r" not in TOKEN and "\n" not in TOKEN, "Fork token missing")
    need(os.environ["GITHUB_REPOSITORY"] == FORK and
         os.environ["GITHUB_REF"] == "refs/heads/codex/20261028-round4-filesize-finalize-b6890775-control"
         and os.environ["GITHUB_EVENT_NAME"] == "create", "Wrong finalization context")
    event = json.loads(Path(os.environ["GITHUB_EVENT_PATH"]).read_text(encoding="utf-8"))
    need(event["repository"]["fork"] and not event["repository"]["private"], "Expected public fork")
    deadline = time.monotonic() + 1000
    while True:
        run = api("repos/" + FORK + "/actions/runs/40731823379")
        if run["status"] == "completed": break
        need(time.monotonic() < deadline, "Earlier publication worker has not stopped; leave claims intact")
        print("Awaiting the earlier publication worker's regular completion", flush=True)
        time.sleep(15)
    RESULT["qualification_workflow_conclusion"] = run["conclusion"]
    proof_file = api("repos/" + FORK + "/contents/result.json?ref=" +
                     "codex/20261028-round4-filesize-sdk-finish-7e542652-completed-1")
    proof = json.loads(base64.b64decode(proof_file["content"]))
    need(proof["commit"] == TIP and proof["source_blob"] == SOURCE_BLOB
         and proof["normal_precommit_passed"] and proof["normal_official_prepush_passed"]
         and proof["normal_fork_push_passed"] and str(proof["run_id"]) == "40731823379"
         and all(c["exit_code"] == 0 for c in proof["commands"]), "Native source receipt not green")
    bank = api("repos/" + FORK + "/git/ref/heads/codex/20261028-round4-filesize-sdk-finish-7e542652-native-1")
    need(bank["object"]["sha"] == TIP, "Verified source bank moved")
    command("public-author", ["git","config","user.name","McMickey93"])
    command("public-email", ["git","config","user.email","347452154+McMickey93@users.noreply.github.com"])
    command("fresh-official-master", ["git","fetch","--no-tags","--recurse-submodules=no","origin","master"])
    command("current-official-tree", ["git","switch","--detach","origin/master"])
    need(rev("HEAD:AGENTS.md") == "a2358475408be34cc5d0c16e28565982f494e8a6", "AGENTS changed: review required")
    RESULT["official_head_at_final_progress"] = rev("HEAD")
    RESULT["official_source_blob_at_final_progress"] = rev("HEAD:" + SOURCE)
    command("current-canonical-reference", ["git","-c","submodule.recurse=false","submodule","update",
                                           "--init","--depth=1","--","reference/open-bfme-1"])
    command("progress-requirements", [sys.executable,"-m","pip","install","--disable-pip-version-check",
                                     "-r","reference/open-bfme-1/tools/requirements.txt"])
    command("required-final-progress", [sys.executable,"tools/progress.py","origin/master"])
    RESULT["final_progress_passed"] = True
    observed = {}
    for ref in REFS:
        command("fresh-claim-" + str(len(observed)),
                ["git","fetch","-q","--no-tags","--depth=1","--recurse-submodules=no","origin",ref])
        sha = rev("FETCH_HEAD")
        old = json.loads(subprocess.check_output(["git","show","-s","--format=%B",sha],cwd=ROOT,text=True))
        need(old["owner"] == OWNER and old["lease"] == LEASE and old["expires"] > time.time(),
             "Claim changed; leave reservations intact")
        observed[ref] = sha
    sys.path.insert(0, str(ROOT / "tools"))
    import claims
    made = claims._record(OWNER,0,"released",root=ROOT,lease=LEASE,since=1793183734,
                         scope=SOURCE,locks=(0x0001D240,"file/0b4a7f866d179718"))
    record = json.loads(subprocess.check_output(["git","show","-s","--format=%B",made],cwd=ROOT,text=True))
    record.pop("host",None)
    need(record["owner"] == OWNER and record["lease"] == LEASE and record["note"] == "released"
         and record["expires"] <= time.time(), "Invalid project release marker")
    RESULT.update(status="banked-session-finalized", observed_claims=observed, claim_refs=REFS,
                  owner=OWNER, lease=LEASE, record=record, new_cpp_bytes=0,
                  normal_source_gates_passed=True, run_id=os.environ["GITHUB_RUN_ID"])
    save()
    content = json.dumps(RESULT,sort_keys=True) + "\n"
    identity = {"name":"McMickey93","email":"347452154+McMickey93@users.noreply.github.com"}
    tree = api("repos/" + FORK + "/git/trees", {"tree":[{"path":"completion.json","mode":"100644",
                                                      "type":"blob","content":content}]})["sha"]
    commit = api("repos/" + FORK + "/git/commits", {"tree":tree,"parents":[],
                 "message":"Finalize the verified cleanup handoff and project release record",
                 "author":identity,"committer":identity})["sha"]
    api("repos/" + FORK + "/git/refs", {"ref":"refs/heads/codex/20261028-round4-filesize-finalize-b6890775-receipt",
                                      "sha":commit})
    print("SESSION_FINALIZED " + content,flush=True)
try:
    main()
except BaseException:
    RESULT["status"]="failed"
    save()
    raise
