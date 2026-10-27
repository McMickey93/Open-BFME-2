"""Verify a reference refresh and commit its result through normal native hooks."""
import base64, hashlib, json, os, subprocess, sys, time, urllib.request
from pathlib import Path

CONTROL = Path(__file__).resolve().parent
DATA = json.loads((CONTROL / "manifest.json").read_text(encoding="utf-8"))
ROOT = Path.cwd()
OUT = ROOT.parent / "source-transfer-evidence"
OUT.mkdir(exist_ok=True)
RESULT = {"schema": 1, "status": "starting", "commands": []}

def require(ok, message):
    if not ok:
        raise RuntimeError(message)

def save():
    (OUT / "result.json").write_text(json.dumps(RESULT, indent=2) + "\n", encoding="utf-8")

def run(label, args, stdin=None, env=None, diagnostic=False):
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
        while proc.poll() is None:
            try:
                proc.wait(timeout=25)
            except subprocess.TimeoutExpired:
                print("    " + label + ": still running", flush=True)
        entry["exit_code"] = proc.returncode
    save()
    output = log.read_bytes()
    print(output.decode("utf-8", errors="replace")[-3000:], flush=True)
    if not diagnostic:
        require(proc.returncode == 0, label + " failed")
    return output

def git(label, *args, **kwargs):
    return run(label, ["git", *args], **kwargs)

def rev(ref):
    return subprocess.check_output(["git", "rev-parse", "--verify", ref], cwd=ROOT, text=True).strip()

def claim():
    git("fetch-own-claim", "fetch", "-q", "--depth=1", "--no-tags", "--recurse-submodules=no",
        "origin", DATA["claim_ref"])
    info = json.loads(subprocess.check_output(["git", "show", "-s", "--format=%B", "FETCH_HEAD"], cwd=ROOT, text=True))
    require(info.get("owner") == DATA["claim_owner"] and info.get("lease") == DATA["claim_lease"]
            and info.get("expires", 0) > time.time(), "Claim changed or expired")

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
    require(DATA.get("native_preparation") is True, "Native preparation required")
    require(not os.environ.get("BUILD_RECOMPILE_ONLY") and not os.environ.get("CL") and not os.environ.get("_CL_"),
            "Unexpected compiler override")
    git("public-author", "config", "user.name", "McMickey93")
    git("public-email", "config", "user.email", "347452154+McMickey93@users.noreply.github.com")
    git("new-native-branch", "switch", "-c", DATA["branch"].removeprefix("refs/heads/"))
    require(rev("HEAD:reference/open-bfme-1") == DATA["old_reference"], "Reference preimage changed")
    git("original-reference-inputs", "-c", "submodule.recurse=false", "submodule", "update",
        "--init", "--depth=1", "--", "reference/open-bfme-1")
    bash = os.environ["BFME_QUALIFICATION_BASH"]
    require(Path(bash).is_file(), "Real Git Bash missing")
    run("verification-requirements", [sys.executable, "-m", "pip", "install", "--disable-pip-version-check", "-r",
                                    "reference/open-bfme-1/tools/requirements.txt"])
    run("normal-hook-setup", [bash, "tools/setup_hooks.sh"])
    claim()
    run("original-reference-layout", [sys.executable, "-c", "import json,sys;from pathlib import Path;sys.path.insert(0,'tools');import build;r={k:{'relative':build.bfme1_subtree(k),'exists':build.bfme1_path(k).is_dir()} for k in ('game','reference','toolchains','baselines','vendor','ledger')};print(json.dumps(r,sort_keys=True));assert all(x['exists'] for x in r.values()),'Missing canonical reference directory'"])
    old_output = run("original-reference-full-verification", [sys.executable, "tools/build.py"], diagnostic=True)
    old_exit = RESULT["commands"][-1]["exit_code"]
    require(not subprocess.check_output(["git", "status", "--porcelain", "--untracked-files=no"], cwd=ROOT),
            "Original full gate changed tracked inputs")
    claim()
    git("fetch-reviewed-reference", "-C", "reference/open-bfme-1", "-c", "submodule.recurse=false",
        "fetch", "--depth=1", "--no-tags", "--recurse-submodules=no", "origin", DATA["new_reference"])
    git("checkout-reviewed-reference", "-C", "reference/open-bfme-1", "-c", "submodule.recurse=false",
        "checkout", "--detach", DATA["new_reference"])
    git("stage-trial-reference", "add", "--", "reference/open-bfme-1")
    require(rev(":reference/open-bfme-1") == DATA["new_reference"], "Wrong trial reference index")
    run("updated-reference-layout", [sys.executable, "-c", "import json,sys;from pathlib import Path;sys.path.insert(0,'tools');import build;r={k:{'relative':build.bfme1_subtree(k),'exists':build.bfme1_path(k).is_dir()} for k in ('game','reference','toolchains','baselines','vendor','ledger')};print(json.dumps(r,sort_keys=True));assert all(x['exists'] for x in r.values()),'Missing canonical reference directory'"])
    new_output = run("new-reference-full-verification", [sys.executable, "tools/build.py"], diagnostic=True)
    new_exit = RESULT["commands"][-1]["exit_code"]
    sweep_exit = None
    if old_exit == 0 and new_exit == 0:
        run("refresh-reference-donor-sweep", [sys.executable, "tools/bfme1_sweep.py", "scan"], diagnostic=True)
        sweep_exit = RESULT["commands"][-1]["exit_code"]
        if sweep_exit == 0:
            Path("build/bfme1_sweep/round3-inputs.json").write_text(
                json.dumps({"bfme1_commit": DATA["new_reference"], "bfme2_commit": DATA["base"]}, indent=2) + "\n",
                encoding="utf-8")
    accepted = old_exit == 0 and new_exit == 0 and sweep_exit == 0
    if not accepted:
        git("restore-verified-reference-index", "restore", "--staged", "--", "reference/open-bfme-1")
        git("restore-verified-reference-checkout", "-C", "reference/open-bfme-1", "-c", "submodule.recurse=false",
            "checkout", "--detach", DATA["old_reference"])
        DATA["files"] = [DATA["evidence"]]
        DATA["source_blob"] = DATA["old_reference"]
        DATA["reviewed_blobs"]["reference/open-bfme-1"] = DATA["old_reference"]
    else:
        Path("build/bfme1-last-check.txt").write_text(
            time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()) + " " + DATA["new_reference"] + "\n", encoding="utf-8")
    mode = "reference-update" if accepted else "blocked-reference-handoff"
    import re
    def summary(output, exit_code):
        lines = output.decode("utf-8", errors="replace").splitlines()
        failures = [line for line in lines if re.search(r"\bFAIL\b|Traceback|Error:|failed|Full gate", line, re.I)]
        headline = [line for line in lines if re.match(
            r"^(Baseline:|Compile:|Functions:|String|Float|Import|DIR32|PIN|Pin|Data|Full verification|Full gate|FULL GATE)", line)]
        return {"exit_code": exit_code, "failure_count": len(failures), "failures": failures[:24],
                "headline": headline[-18:], "sha256": hashlib.sha256(output).hexdigest()}
    old_summary, new_summary = summary(old_output, old_exit), summary(new_output, new_exit)
    def failure_set(output):
        return {line.strip() for line in output.decode("utf-8", errors="replace").splitlines()
                if re.search(r"\bFAIL\b", line)}
    old_failures, new_failures = failure_set(old_output), failure_set(new_output)
    comparison = {"common_failure_lines": sorted(old_failures & new_failures),
                  "old_only_failure_lines": sorted(old_failures - new_failures),
                  "new_only_failure_lines": sorted(new_failures - old_failures)}
    qualification = {"mode": mode, "old_reference": DATA["old_reference"], "new_reference": DATA["new_reference"],
                     "bfme2_revision": DATA["base"], "old_gate": old_summary, "new_gate": new_summary,
                     "donor_sweep_exit": sweep_exit, "new_cpp_bytes": 0, "failure_comparison": comparison}
    (OUT / "reference-comparison.json").write_text(json.dumps(qualification, indent=2) + "\n", encoding="utf-8")
    note = (CONTROL / "evidence.md").read_text(encoding="utf-8")
    note += "\n## Native Windows qualification\n\n"
    note += "Mode: **" + mode + "**. Both complete byte checks use the unmodified driver and original compiler.\n"
    note += "Both runs use BFME 2 revision " + DATA["base"] + " with valid dependency caches.\n"
    note += "Original input exit: **%s**. Updated input exit: **%s**. Donor sweep exit: **%s**.\n\n" % (
        old_exit, new_exit, sweep_exit)
    for title, result in (("Original reference", old_summary), ("Updated reference", new_summary)):
        note += "### " + title + "\n\nFull log SHA-256: " + result["sha256"] + ".\n\n"
        note += "~~~text\n" + "\n".join(result["headline"] + result["failures"]) + "\n~~~\n\n"
    note += "Failure-line comparison: %s common, %s old-only, %s new-only. Full line sets are retained in the comparison receipt.\n\n" % (
        len(comparison["common_failure_lines"]), len(comparison["old_only_failure_lines"]),
        len(comparison["new_only_failure_lines"]))
    note += ("Both full gates and the regenerated donor sweep pass. The verified pointer is advanced.\n"
             if accepted else
             "The update is blocked by the recorded full-gate result. The canonical pointer is kept; "
             "no successful freshness stamp is written. Resolve these checks before retrying the reference refresh.\n")
    note += "No new C++ body, byte coverage, linked bytes or source-recovery gain is claimed.\n\n"
    note += "Native logs and comparison receipt: https://github.com/" + DATA["fork"] + "/actions/runs/" + os.environ["GITHUB_RUN_ID"] + "\n"
    evidence = ROOT / DATA["evidence"]
    evidence.parent.mkdir(parents=True, exist_ok=True)
    evidence.write_text(note, encoding="utf-8", newline="\n")
    git("stage-exact-reviewed-paths", "add", "--", *DATA["files"])
    message = OUT / "source-commit-message.txt"
    message.write_text(
        ("Refresh BFME 1 reference after full native verification" if accepted else
         "Record the native blockers to the BFME 1 reference refresh") +
        "\n\n" + ("Advance the verified reference and regenerate donor placement evidence." if accepted else
                    "Keep the canonical verified reference; preserve both full-gate results for follow-up.") +
        "\nNo new C++ bytes are claimed.\n\nAgent-Authored: OpenAI Codex\n", encoding="utf-8")
    git("normal-native-commit", "commit", "-F", str(message))
    prepared_commit = rev("HEAD")
    original_source = rev("HEAD:" + DATA["source"])
    require(original_source == DATA["source_blob"], "Committed reference differs")
    DATA["reviewed_blobs"][DATA["evidence"]] = rev("HEAD:" + DATA["evidence"])
    RESULT.update(normal_precommit_passed=True, native_commit=prepared_commit,
                  reference_mode=mode, reference_qualification=qualification)
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
    for attempt in range(8):
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
        git("reference-inputs", "-c", "submodule.recurse=false", "submodule", "update", "--init", "--depth=1", "--", "reference/open-bfme-1")
        bash = os.environ["BFME_QUALIFICATION_BASH"]
        require(Path(bash).is_file(), "Real Git Bash missing")
        if not installed:
            run("verification-requirements", [sys.executable, "-m", "pip", "install", "--disable-pip-version-check", "-r",
                                            "reference/open-bfme-1/tools/requirements.txt"])
            run("normal-hook-setup", [bash, "tools/setup_hooks.sh"])
            installed = True
        claim()
        wire = (DATA["branch"] + " " + tip + " refs/heads/master " + base + "\n").encode()
        run("actual-official-pre-push", [bash, ".githooks/pre-push", "origin",
                                       "https://github.com/Open-BFME/Open-BFME-2.git"], stdin=wire)
        run("publication-ledger-integrity", [sys.executable, "tools/check_csv.py"])
        if RESULT["reference_mode"] == "reference-update":
            run("publication-full-byte-verification", [sys.executable, "tools/build.py"])
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
                print("SOURCE_PUBLICATION_COMPLETE " + json.dumps(RESULT), flush=True)
                git("normal-post-publication-pull", "pull", "--rebase", "origin", "master")
                run("required-final-progress", [sys.executable, "tools/progress.py", "origin/master"])
                RESULT.update(final_progress_passed=True)
                save()
                print("SOURCE_FINAL_PROGRESS_COMPLETE " + json.dumps(RESULT), flush=True)
                return
            time.sleep(3)
        else:
            raise RuntimeError("Awaiting app expected-base publication timed out; verified native objects remain banked")
    raise RuntimeError("Upstream did not settle within eight verified attempts; native objects remain banked")

try:
    main()
except BaseException:
    RESULT["status"] = "failed"
    save()
    raise
