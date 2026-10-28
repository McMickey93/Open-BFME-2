# Verified BFME 1 reference refresh

The overdue freshness check fetched official Open-BFME/Open-BFME-1 master at
7c48cfd16763638cdd7440ecd74466631e977b9f. The clean old checkout and committed
pin were e74410b3738a2bb75d626085d9ebfd3406a43ff7. The reference file scope was
claimed before changing the checkout. Nested cross-repository references were
not initialized, and no dirty or unpublished submodule work was discarded.

The paired comparison fixes BFME 2 at 45e593a068a79a62afcff66598199f9566849ad9.
input-receipt.json records the identical Code tree, function ledger and data-row
ledger. The reference diff has 197 paths, including 112 game source files and
zero game headers. It introduces no compiler-setting or reference-layout change;
the existing game/ and inputs/reference/ resolver remains applicable.

Both ordinary full ./build.sh runs exit zero with FULL GATE: OK. Each verifies
98,941 function rows across 21,919 sources; 223 STLport constructor folds;
31,537 string literals plus 2,248 empty-string references; 9,117 float literals;
6,423 named imports; DIR32, pin and module consistency; all source claims;
2,202 data rows; and the no-op patch. The old run restores 3,123 objects and
rebuilds the rest of its 7,063 stale units. The new run finds all 21,918 compiled
units dependency-current. The new inputs introduce no failing check.

The donor scan is refreshed with tools/bfme1_sweep.py scan --min-size 16 at the
new revision: 5,538 unique placements, all covered; 5,531 independently matched
boundaries, above the 4,100 control floor; zero free placements and 617 near
misses. The new match.json SHA256 is recorded in input-receipt.json. The prior
scratch match is preserved locally. No stale donor compile trial is used for a
transfer, and no donor implementation is imported by this update.

Only after both full gates and the donor scan pass is the ignored local
freshness stamp advanced. This commit publishes the verified gitlink and these
receipts directly from the worktree whose submodule is synchronized. An earlier
reference bump was reverted because the fleet publisher did not synchronize its
checkout; that is not the publication route used here.

No BFME 2 source path, ledger row, gate, baseline or whitelist changes. No new
matched bytes, linking census gain, source-file reduction or debt retirement is
claimed. The published link index was refreshed to 14dc3d2467, 2026-10-28 02:44;
the normal pre-push audit still determines publication-time evidence limits.

## Publication checks

The rebased full gate at 53d182808d43ae12ef2a9ce9c1058c70895333ed passes all
98,941 functions across 21,898 sources, all 2,203 data rows and the no-op patch.
Tree-wide converged-data enforcement passes all 21,897 compiled sources at eleven
addresses. Git rejects that transfer because master advances during the gate.

The normal carried-gate retry at d6b63c72d87b5a456d55d99cf3afc14713250b52
passes 1,208 rows across 23 sources changed since the proof, 25 exact EH graphs,
converged-data enforcement and tree-wide DIR32/module checks. Those sources are
upstream changes, not reference-update gains. Its link audit remains UNVERIFIED:
the index predates outgoing base 48fed8267aa, and 21 objects lack current strict
receipts (first BfmeThingRE.cpp). Carry that LINK-008 input-freshness limitation
into the next census; no selected-provider or lost-byte clearance is claimed.
Git rejects this transfer on another master race. All hooks remain enabled.
