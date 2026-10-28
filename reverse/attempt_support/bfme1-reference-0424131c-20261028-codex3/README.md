# Verified BFME 1 reference refresh

Fetched official Open-BFME/Open-BFME-1 master without recursive initialization.
The previous clean checkout and committed pin were
`7c48cfd16763638cdd7440ecd74466631e977b9f`; selected upstream is
`0424131c818fba6641613ef826222ecf30845025`. The reference file scope was
claimed before changing it. No dirty or unpublished reference work was removed.

Both full gates use BFME 2 base `88160d0cb79ffad492171d17c3f74eb47b126fcd`
with the same three-line ArmyDetailsMovieClip math-wrapper linkage repair.
The Code tree, patch and function/data ledger digests are recorded in
[input-receipt.json](input-receipt.json). No BFME 2 source or ledger input
changed between the old-reference and new-reference runs.

The reference delta has 19 paths, including five game C++ sources and no
headers, compiler settings or reference-layout change. The previously verified
`game/` and `inputs/reference/` resolution remains applicable. Searching Code
and reference/shims for the five changed source basenames finds only an
AsciiString.cpp provenance comment, not a textual include of changed source.

Both ordinary `BUILD_POOL=12 ./build.sh` runs exit zero with FULL GATE: OK.
Each verifies 98,941 functions across 21,807 sources, 223 STLport folds,
31,537 string literals plus 2,248 empty-string references, 9,117 floats,
6,423 named imports, DIR32/pin/module consistency, source claims, all 2,203
data rows and the no-op patch. The old run restores 1,734 of its 1,766 stale
objects; the new run finds all 21,806 compiled units dependency-current.
The update introduces no failing gate check. Full logs are retained beside
this receipt. The new checkout's initial pin preflight refused it until its
gitlink was explicitly staged; no verification ran with a mismatched pin.

The refreshed `bfme1_sweep.py scan --min-size 16` passes its control floor:
5,538 unique placements, all covered; 5,531 independently matched boundaries;
zero free placements; 617 near misses. The exact donor revision and match.json
digest are recorded with the cached results and in the receipt. No donor
compile trial is reused, and no donor implementation is imported. The prior
match cache remains in local scratch.

Only after both full gates and the donor scan pass is the ignored local
freshness stamp advanced. This commit publishes the verified reference pin;
the runner publisher synchronizes its reference after picking commits. No
BFME 2 source paths, ledger rows, gates, baselines or whitelists change in
this reference update. No headline coverage or debt gain is claimed.
