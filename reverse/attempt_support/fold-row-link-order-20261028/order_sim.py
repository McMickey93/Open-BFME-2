#!/usr/bin/env python3
"""Evidence script (not a tool): re-rank the census index's objects with
link_census.link_order's rule minus `fold-proof=` rows and report which COMDAT
names would have retail's copy first, and the census units that changes.

Run from the repo root after `python3 tools/link_check.py --fetch-index`:
    python3 reverse/attempt_support/fold-row-link-order-20261028/order_sim.py
"""
import collections
import csv
import pickle
import sys

sys.path.insert(0, "tools")
import build  # noqa: E402

idx = pickle.load(open("build/link_census/link_index.pkl", "rb"))
objs = idx["objects"]
cur = {o: i for i, o in enumerate(objs)}
rows = [r for r in csv.DictReader(open("reverse/functions.csv")) if r["status"] == "matched"]
lo_all, lo_own = {}, {}
for r in rows:
    o, v = build.row_object(r).name, int(r["target_rva"], 16)
    lo_all[o] = min(lo_all.get(o, v), v)
    if "fold-proof=" not in r["notes"]:
        lo_own[o] = min(lo_own.get(o, v), v)


def key(o):
    if o in lo_all:  # code objects by lowest non-fold RVA; data-only objects keep their census order
        return (0, lo_own.get(o, lo_all[o]), cur[o])
    return (1, cur[o], cur[o])


new = {o: i for i, o in enumerate(sorted(objs, key=key))}
gain, loss = set(), set()
for name, copies in idx["comdat"].items():
    verdicts = {v for _, _, v in copies}
    if not {"retail", "wrong"} <= verdicts:
        continue
    before = min(copies, key=lambda c: c[0])[2]
    after = min(copies, key=lambda c: new[objs[c[0]]])[2]
    if (before, after) == ("wrong", "retail"):
        gain.add(name)
    elif (before, after) == ("retail", "wrong"):
        loss.add(name)
print(f"index {idx['meta']['date']} at {idx['meta']['commit'][:10]}")
print(f"names whose first copy turns retail: {len(gain)}; turns non-retail: {len(loss)}")
for n in sorted(gain):
    print("  +", n)
for n in sorted(loss):
    print("  -", n)
bl = idx["blockers"]
freed = []
for src, e in bl.items():
    ws = set(e["wrong_selected"])
    if ws & gain and ws <= gain and not (e["unresolved"] or e["duplicates"] or e["losers"] or e["addresses"]):
        freed.append((src, idx["bytes"].get(src, 0)))
obj2src = {e["object"]: s for s, e in bl.items()}
hurt = sorted({(obj2src[o], idx["bytes"].get(obj2src[o], 0)) for o, names in idx["touches"].items()
               if names & loss and o in obj2src and bl[obj2src[o]].get("linked")})
print(f"unlinked units blocked only by wrong_selected on gained names: {len(freed)}, "
      f"{sum(b for _, b in freed):,} B (upper bound: other new conflicts are not re-judged)")
for s, b in sorted(freed):
    print(f"  + {s} {b}")
print(f"linked units touching a lost name: {len(hurt)}, {sum(b for _, b in hurt):,} B (upper bound)")
for s, b in hurt:
    print(f"  - {s} {b}")
