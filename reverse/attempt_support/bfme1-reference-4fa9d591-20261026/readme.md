# BFME 1 reference freshness and Skirmish follow-up, 2026-10-26

The fixed comparison uses BFME 2 `ff4455c2afc652f419c4c5a2555d99ed2964c880`.
The clean reference checkout initially agrees with the committed, previously
verified pointer `001ccd8e27686e9887235b62ff797627f2dde7f5`. Official
Open-BFME/Open-BFME-1 master was fetched as
`4fa9d591641a743b86f2320343b7a276585b814b`. The reference scope is claimed before
changing its checkout or gitlink. No dirty or unpublished reference work is
discarded, and no nested reference is initialized.

The update changes 92 paths, including 67 game C++ sources, but no headers,
inline files, toolchains, baseline images or vendor inputs. Its only changed
`inputs/` path is the nested `inputs/reference/open-bfme-2` gitlink. The existing
layout resolver applies: `game/`, `inputs/reference/`, `inputs/toolchains/`,
`inputs/baselines/` and `inputs/vendor/` all exist. No source/include layout
repair or compiler flag change is needed.

BFME 2's game inputs remain fixed throughout the comparison: Code tree
`b786efa00daa6cd1f27c686b8aa2359d3801544f`, function-ledger blob
`93b3b7715c555ddcf84ead6d24f2061194c5971d`. Normal dependency-currency checks
remain enabled. The full runs are polled to completion without duplicate builds.

## Selected linking lead

The default picker claims `0x0043BC0A` and its source
`Code/GameEngine/Source/Common/SkirmishPreferencesLoad.cpp`. Current coverage,
prior verdicts and LINK-041 show this is already a recovered body, with its
global declaration repaired in `f598ec4226`. No new reconstruction is needed.

The fetched ordinary index is dated 2026-10-26 19:02 at `5ce093a71a`.
`link_check.py` with the current source reports LINKS, with 299 authored
nonpadding bytes versus zero in that historical census. This is confirmation
of the existing repair, not a new linked-byte gain. The source owns six matched
rows totaling 342 ledger bytes; its standalone build passes all six rows,
two literals plus one empty-string reference, and two named imports. EH
verification reports one EXACT graph and no baseline exceptions. The frozen-file
check finds every defined function already matched. No game source or ledger
row is changed for this lead. The historical LINK-041 family remains subject to
the next normal census; no maintainer-only measurement is run.

## Dependency and donor evidence

The changed-path set has no intersection with the source and dependency paths
in 22,767 object dependency receipts. The receipt scan does not replace the
build's normal dependency-currency checks. No compile trial involving a changed
BFME 1 source is reused, and no consolidation planner is used in this pass.

`python3 tools/bfme1_sweep.py scan --min-size 16` succeeds against `4fa9d591`:
5,538 unique placements, all on already claimed ground, with 5,531 independently
matched exact boundaries, no free placements, and 617 near misses. The new
scratch match.json SHA256 is
`9e0257f8b2ce2e30ea1b8310c652790b39896c80e4fea370546341ea7670f1a4`.
`build/bfme1_sweep/codexb5-20261026-inputs.json` associates that result with its
exact donor revision and scan command; the previous scratch result is preserved
separately. These placements do not recover or rename BFME 2 source.

## Full comparison

The old-pointer `./build.sh`, captured in
[`old-full.txt`](old-full.txt), exits zero with FULL GATE: OK. It passes
98,273/98,273 functions across 22,723 sources, 2,223 data rows, 31,537 literals
plus 2,257 empty-string references, 9,116 float references, 6,419 imports,
DIR32/pin/module/source consistency and the no-op patch.

The updated-pointer `./build.sh`, captured in [`new-full.txt`](new-full.txt),
also exits zero with FULL GATE: OK. Its function, literal, float, import,
DIR32/pin/module/source, data and no-op patch verdicts agree with the old run.
There are no update regressions or residual failures. The fixed BFME 2 Code
tree and function-ledger blob still agree with the values listed above; only
the staged gitlink selects the updated reference through the ordinary pin guard.

Only after this successful comparison is the ignored freshness receipt written
for verified/upstream `4fa9d591`. The update moves no BFME 2 source path and
requires no source, layout, flag, tool or baseline repair. The normal commit
and push hooks remain enabled. The passed full build may be recorded for the
identical committed build inputs with `tools/full_gate_receipt.py`; the push
hook then checks any rebased delta and retains its tree-wide cross-source checks.

This maintenance and the LINK-041 follow-up claim no new matched bytes, linked
census gain, ownership reduction or debt retirement.
