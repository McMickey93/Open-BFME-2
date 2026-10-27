# BFME 1 reference freshness, 2026-10-27

The ignored freshness receipt was over 72 hours old. Before further source
work, fetched official `https://github.com/Open-BFME/Open-BFME-1.git` master.
The clean checkout and committed BFME 2 gitlink were both
`4fa9d591641a743b86f2320343b7a276585b814b`; official master resolved to
`e74410b3738a2bb75d626085d9ebfd3406a43ff7`. The two tips have one commit on
each side of their common ancestor. This is a verified reference replacement,
not a fast-forward claim. The old pointer remains recoverable from BFME 2's
parent commit; no dirty or private checkout work was discarded.

The comparison fixes BFME 2 game inputs at `e1a73387fd8b18b30558d5b78b586c37dc10f207`:

- `Code/` tree: `07fa2619d5900e0fbad4d1c07994325993db9d76`.
- `reverse/functions.csv` blob: `eb954351cb939fb5ffaa68fe5f5f7d69793feac5`.

The intervening header-debt retirement commit changes only documentation and
one obsolete queue entry. Game source and build ledgers stayed fixed throughout
the comparison. The old-pointer full gate completed before changing the donor
checkout; the new checkout was then staged so the normal reference guard could
verify the intended input.

`donor-changed.txt` records all 46 changed paths, including 13 game C++ sources.
There are no changed headers, include fragments, toolchain inputs or vendored
libraries. Existing `game/`, `inputs/reference/`, `inputs/toolchains/`,
`inputs/baselines/`, `inputs/vendor/` and `targets/game/reverse/` directories
were checked on disk; no layout migration was needed. Nested cross-repository
references were not initialized.

Normal dependency validation was enabled for both `./build.sh` runs. The old
run rebuilt 3,047 of 22,557 TUs; the new run found all 22,557 current. The
dependency audit in `dependency-diff.json` found none of the changed donor paths
in 25,675 recorded dependency sets. This explains cache reuse; the full byte
verification still checks every function row.

Both full gates exited zero with `FULL GATE: OK`: 98,276/98,276 function rows,
13,032 funclet rows, 222 STLport constructor folds, 2,226 data rows, 31,537
string literals plus 2,254 empty-string references, 9,117 floating literals and
6,419 named imports. DIR32 and pin consistency, module registration, source
claims and the no-op patch also passed. `old-full.txt` and `new-full.txt` retain
the complete output. There were no pre-existing failures or update regressions.
The ignored freshness receipt was updated only after the second gate passed.

Refreshed the donor scan with `python3 tools/bfme1_sweep.py scan --min-size 16`,
then `ranked --limit 1000`, `near --limit 1000`, and the donor's
`tools/lift_lane.py --limit 1000`. The scan reproduced 5,531 independent target
boundaries, above its 4,100 control floor: 5,538 unique placements, all already
covered, zero free bytes, and 617 near misses. The filtered ranked and near
queues serve zero candidates. These results neither exhaust linking leads nor
establish donor identity for any BFME 2 body. `donor-cache-revision.json`
records the donor revision and refreshed `match.json` digest; prior cached
donor compile-trial verdicts were not used to justify a transfer or this update.
No donor implementation was imported.

This update changes the reference pointer and records verification evidence.
It claims no new matched bytes, linked coverage or image ownership reduction.
