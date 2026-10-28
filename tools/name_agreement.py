#!/usr/bin/env python3
"""Review of an inferred name: one definition for the lane that
records votes (tools/name_lane.py) and the engine that lands names
(tools/rename.py).

An uncontested parameter or local name needs one worker's proposal. Every
other inferred name, including a contested scoped name, still needs two
independent blind proposals. Two things make that rule checkable:

  workers   every vote carries the identity of the worker that cast it, taken
            from the environment, not from a flag the caller types. A session
            label (`--session`) is a free string, so one agent could serve
            itself twice under two labels and outvote nobody but itself; the
            worker identity is BFME_CLAIM_OWNER or BFME_RUN_ID (the identity
            tools/claims.py claims under -- an orchestrator gives each seat its
            own), else the harness's CLAUDE_CODE_SESSION_ID, else
            tools/claims.py's default owner. It is stored hashed (w-<12 hex>),
            so no user, host or session id enters the repository. Agreement
            counts distinct workers, never distinct session labels.
  votes     reverse/name_votes.csv (append-only, union-merged) holds each vote
            as sha256(key|canon(name))[:24]. The agreement record in
            reverse/name_agreed.csv is only an index into those votes: the
            engine recomputes the approval from them (the required distinct
            workers voted the landed spelling's hash, no rival spelling has as
            many, the record and the spelling are not disputed), so a
            hand-written agreement row authorises nothing.

canon() folds word order, plurals and common abbreviations, so
m_ladderComboBox and m_comboBoxLadder are one vote.

    python3 tools/name_agreement.py whoami      # this environment's worker id
"""
import argparse
import collections
import hashlib
import os
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

VOTES = "reverse/name_votes.csv"
AGREED = "reverse/name_agreed.csv"
VOTE_COLUMNS = ["key", "hash", "model", "session", "worker", "date"]
AGREED_COLUMNS = ["id", "kind", "old", "new", "rva", "agents", "key", "status", "detail"]
SYNONYMS = {"num": "count", "number": "count", "cnt": "count", "idx": "index", "len": "length", "pos": "position",
            "str": "string", "msg": "message", "btn": "button", "wnd": "window", "tex": "texture", "obj": "object"}
WORKER = re.compile(r"w-[0-9a-f]{12}")


def canon(name):
    """Word order, plurals and common abbreviations are style, not meaning."""
    words = re.findall(r"[A-Z]+(?![a-z])|[A-Z]?[a-z]+|\d+", re.sub(r"^[msg]_", "", name or ""))
    words = [SYNONYMS.get(w.lower(), w.lower()) for w in words]
    return " ".join(sorted(w[:-1] if len(w) > 3 and w.endswith("s") else w for w in words))


def digest(key, name):
    return hash_canon(key, canon(name))


def hash_canon(key, canonical):
    return hashlib.sha256(f"{key}|{canonical}".encode()).hexdigest()[:24]


def worker_identity(root=None):
    """This environment's worker id, `w-<12 hex>`. The raw identity is
    BFME_CLAIM_OWNER / BFME_RUN_ID through tools/claims.py's owner(), else
    CLAUDE_CODE_SESSION_ID, else claims.owner()'s default (branch or
    user@host/checkout): never a value the voter passes on the command line."""
    env = os.environ
    if env.get("BFME_CLAIM_OWNER") or env.get("BFME_RUN_ID") or not env.get("CLAUDE_CODE_SESSION_ID"):
        import claims
        raw = "owner:" + claims.owner(root)
    else:
        raw = "session:" + env["CLAUDE_CODE_SESSION_ID"]
    return "w-" + hashlib.sha256(raw.encode("utf-8")).hexdigest()[:12]


def tally(votes):
    """key -> hash -> {worker: model}. A vote without a well-formed worker id
    counts for nothing: it cannot be told apart from its voter's other votes."""
    out = collections.defaultdict(lambda: collections.defaultdict(dict))
    for v in votes:
        worker = (v.get("worker") or "").strip()
        if WORKER.fullmatch(worker):
            out[v.get("key", "")][v.get("hash", "")][worker] = v.get("model", "")
    return out


def disputed(agreed_rows):
    """key -> canon spellings a dispute refused for it."""
    out = collections.defaultdict(set)
    for row in agreed_rows:
        if row.get("status") == "disputed":
            out[row.get("key", "")].add(canon(row.get("new", "")))
    return out


def review_workers(key, rivals):
    """One worker for an uncontested scoped name; two for every other name.

    A missing or malformed key never opts into lighter review. Rivals are
    already filtered for disputed spellings by the caller.
    """
    parts = (key or "").split("|")
    scoped = (len(parts) == 4 and parts[0].startswith("Code/")
              and parts[1] in ("param", "local") and parts[2] and parts[3])
    return 1 if scoped and not any(rivals) else 2


def review_detail(key, voters, rivals=()):
    policy = "single-worker scoped approval" if review_workers(key, rivals) == 1 and len(voters) == 1 \
        else "two-agent agreement"
    agents = ";".join(f"{w}@{m}" for w, m in sorted(voters.items()))
    return f"{policy}: {agents}"


def wins(mine, rivals, *, lead=2, min_models=1, key=None):
    """`mine` and each rival are {worker: model} for one spelling. Uncontested
    scoped keys need one worker; all others need two and the requested lead.
    `min_models` applies to either policy. `key=None` keeps the two-worker rule."""
    needed = review_workers(key, rivals)
    # --lead still governs competing proposals; an uncontested local or
    # parameter needs one proposal. --min-models remains an independent floor.
    margin = 1 if needed == 1 else lead
    return (len(mine) >= needed and len(set(mine.values())) >= min_models
            and len(mine) - max((len(r) for r in rivals), default=0) >= margin)


def standing(votes, agreed_rows, key, name):
    """(mine, rivals) for spelling `name` of `key`: the workers that voted its
    hash, and the voter sets of every other spelling not refused by a dispute."""
    counts = tally(votes)[key]
    gone = {hash_canon(key, c) for c in disputed(agreed_rows).get(key, ())}
    h = digest(key, name)
    return dict(counts.get(h, {})), [v for h2, v in counts.items() if h2 != h and h2 not in gone]


def verify(votes, agreed_rows, key, name, *, lead=1):
    """Problems (empty when the votes carry `name` for `key`): the floor the
    engine enforces whatever --lead the lane ran with: one worker for an
    uncontested scoped name, otherwise two and no equally supported rival
    (`lead` 1). The spelling and the record must not be disputed."""
    problems = []
    if canon(name) in disputed(agreed_rows).get(key, ()):
        problems.append(f"{name} was disputed for {key}")
    mine, rivals = standing(votes, agreed_rows, key, name)
    needed = review_workers(key, rivals)
    if len(mine) < needed:
        requirement = "one is needed for an uncontested scoped name" if needed == 1 else "two are needed"
        problems.append(f"{len(mine)} distinct worker(s) voted it in {VOTES} ({requirement})")
    top = max((len(r) for r in rivals), default=0)
    if mine and len(mine) - top < (1 if needed == 1 else lead):
        problems.append(f"a rival spelling has {top} worker(s) against its {len(mine)}")
    return problems


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    sub = ap.add_subparsers(dest="cmd", required=True)
    sub.add_parser("whoami", help="print this environment's worker id")
    args = ap.parse_args(argv)
    if args.cmd == "whoami":
        print(worker_identity())
    return 0


if __name__ == "__main__":
    sys.exit(main())
