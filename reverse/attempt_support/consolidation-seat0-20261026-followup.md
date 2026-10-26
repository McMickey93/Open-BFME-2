# Mechanical consolidation follow-up, 2026-10-26

## Freshness prerequisite

Fetched official BFME 1 `master` and verified the pinned-to-upstream update from `de077dd5dd8339716a6abe453a1d81dfdf77e651` to `aa39a9441911f8fa6f4f230b0d8d6481a35167fc` against BFME 2 `469bf57d60`. `./build.sh` completed FULL GATE OK: 98,271/98,271 functions, 2,214 data rows, 31,537 string literals plus 2,257 empty-string references, 9,116 float refs, 6,419 import refs, 20,501 DIR32 symbols, 15,653 pin checks, 329 module registrations and 22,636 source claims. The verified pointer and result are recorded in ignored `build/bfme1-last-check.txt`; the submodule pointer is included in this handoff commit.

## Allocated candidates checked

The mechanical allocator's full `--limit 100000` listing for shard 0/5 had 36 destinations. `--check-tu` passed for each trial destination. Current scoped planner reports and `--check build/consolidation` passed for the selected parents. No merge was applied; no file/RVA claims were acquired.

- `DemoTrapUpdate.cpp`: current dry run accepted only `DemoTrapUpdateModuleDataCtor.cpp`. Existing handoff `consolidation-demotrapupdate-20261026.md` records that composition's unresolved `_vtbl_00C4ED70` code/data identity findings. The current dry run also rejects unchanged `DemoTrapUpdatePoolKey.cpp` with C2039/C2270 for `getModuleNameKey`, `DemoTrapUpdateConstructor.cpp` with C2511 for the constructor overload, `DemoTrapUpdate_onObjectCreated.cpp` with C2039 for `onObjectCreated`, `Rva00495A2B.cpp` with C2065 (`STATUS_2`/`STATUS_13`), and `DemoTrapUpdateXfer.cpp` with C2039 for `xfer`. Do not repeat before Sol resolves the prerequisites.
- `SpawnPointProductionExitUpdate.cpp`: current plan and prior handoffs record unchanged declaration, `Coord3D` redefinition, allocator specialization, protected-register and data/view blockers. No trial was repeated.
- `ProneUpdate.cpp`: dry run accepted no donors. `ProneUpdatePoolKey.cpp` fails C2039/C2270 (`getModuleNameKey` absent from class); `ProneUpdateModuleDataCtor.cpp` fails C2143/C2501 around `getProneUpdateModuleData`; `ProneUpdateCtor.cpp` fails C2504 (`UpdateModule` base undefined) and C2511 (constructor overload). No change.
- `FireWeaponWhenDeadBehavior.cpp`: dry run accepted no donors. `FireWeaponWhenDeadBehaviorOnDie.cpp` fails C2504 (`UpgradeMux` base undefined); `FireWeaponWhenDeadBehaviorPoolKey.cpp` fails C2039 (`getModuleNameKey` absent). Split trial of mixed `Rva00589079Derived.cpp` was refused by hatch counter rule 3 because a copied helper or datum carries a hatch. No change.
- `PoisonedBehavior.cpp`: after the previously busy claims expired, dry run accepted no donors. Pool-key and update donors fail missing class members/base interfaces; xfer donor fails missing `PoisonedBehavior::xfer`. No change.
- `AIGroup.cpp`: 131 approved rows, 40 donor files and 10 mixed files; dry run accepted no donor. Failures require `PathfindLayerEnum`, `CommandSourceType`, AIGroup/Object member declarations, or other class/header prerequisites. No change.
- `WWLib/thread.cpp`: despite the prior Sol prerequisite handoff, the current dry run accepts no donor; `ThreadClassLifecycle.cpp` fails C3861 (`_beginthreadex` identifier not found). No change.

Other destinations in the allocated listing have current blocker handoffs in `reverse/attempt_support/`, including StatusBitsUpgrade, MessageStream, BridgeTowerBehavior, WeaponBonusUpgrade, RebuildHoleExposeDie, RadiusDecalUpdate, ProcessAnimateWindow, ShipSlowDeathBehavior, SpecialPowerCreate, CommandButtonHuntUpdate, AITNGuard, W3DTreeDraw, AIGuard, CostModifierUpgrade, W3DTreeBuffer, Snow, OCLUpdate, AIFlankAttackTactic, GameResultsThread, AptValueGCAllocator, LoadScreen, Win32DIKeyboard, AudioEventRTS, NetCommandList, W3DVegetationBufferBase, Credits and SidesList. Current residual tasks need their recorded declaration, identity, provider, claim or audit prerequisites before another unchanged trial.

Net TU merges and source-file reduction this session: 0. No C++ bytes or debt retirement are claimed.

## 2026-10-26 continuation: batch audit blocker

After the earlier shard review, two merges were applied and verified locally:
`LifetimeUpdate.cpp` absorbed two unchanged donors (6 rows, net -2 source
files), and `StatusBitsUpgrade.cpp` absorbed two donors (4 rows, net -2
source files). Both printed tool trailers were preserved in their local
commits. The third candidate, `ProneUpdate.cpp`, accepted only
`ProneUpdateModuleDataCtor.cpp` (5 rows total); its current byte build passed
5/5, but that trial was restored when the required outgoing-batch
provider/consumer audit remained inconclusive. Its patch and full audit output
are preserved in ignored `build/consolidation/prone-seat0/`.

Current batch checks after rebasing onto `origin/master` `c01848c0b1`:
`check_csv.py` passed; the three-TU `build.sh` passed 15/15; unmatched-file
checks passed (LifetimeUpdate reports one existing unclaimed definition note);
staged TU ownership passed. Shadow checks retain one ProneUpdate alternate-name
identity finding and one wrong-name data finding for `_vtbl_00C4ED70`, already
present in its module-data donor. No debt retirement is claimed. The path
consumer audit found only merge provenance comments, the retained
`reverse/link_status.csv` census snapshot, a historical recipe comment in
`SubObjectsUpgradePoolKey.cpp`, and an existing attempt-log entry.

The full outgoing link audit used fetched index `d1f046749a` (census 2026-10-26
13:18) against outgoing base `origin/master` `c01848c0b1`. It reports an
inconclusive baseline, 3 current objects and 191 retired objects, followed by
413 provisional `provider disappeared` findings. The index predates the base;
these findings are not attributable to these three TUs and do not verify their
selected-provider or consumer bindings. Do not publish this batch until a
current census/index or a supported scoped before/after composition comparison
resolves LINK-017. The run output and exact staged trial patch are preserved at
`build/consolidation/prone-seat0/link-batch-audit.txt` and
`build/consolidation/prone-seat0/prone-trial.patch`.

The ProneUpdate trial claims were released after restoration. **Correction as
of the next fetched master:** the earlier `LifetimeUpdate` and
`StatusBitsUpgrade` merge commits are ancestors of `origin/master`; the older
statement that they remained unpublished is stale. Their 18 remaining scope
and RVA claims were manually released after verifying the landed commits.
ProneUpdate remains restored pending its LINK-017 provider/consumer audit.

## 2026-10-26 continuation: fresh shard checks

Upstream advanced to `519f7cfef1` during this session; `git pull --rebase
origin master` fast-forwarded cleanly, and `check_csv.py` passed (98,269
functions, 15,635 symbols, 2,223 data rows). The current published link index
is census `d1f046749a` at base `47e030bafc`, which predates `origin/master`.
`link_check.py --fetch-index` confirmed it is the latest published index;
`--prepare-current W3DTreeBuffer.cpp` passed the strict byte receipt for the
composed file, but this does not establish selected-provider or consumer
bindings against the current base.

`W3DTreeDraw.cpp` was freshly planned and dry-run. It accepted two donors, but
the apply pass acquired no edits or claims because another worker held
`W3DTreeDrawModuleDataBuildFieldParse.cpp`. Its file claim must clear before a
retry; unchanged rejected declaration and mixed-source blockers remain as
recorded in the current plan.

`W3DTreeBuffer.cpp` accepted unchanged `W3DTreeBufferRva000EA48D.cpp` (31
matched rows, four code bodies). Its tool merge, destination build (32/32),
`find_declared_unmatched.py`, staged COMDAT shadow check and data shadow check
passed. The code-identity shadow check reported four new findings:
`??0Vector3@@QAE@ABV0@@Z`,
`??A?$PtrVector@H@@QAEAAHI@Z`,
`??A?$PtrVector@PAVVertexBufferClass@@@@QAEAAPAVVertexBufferClass@@I@Z`, and
`??AMatrix3D@@QBEABVVector4@@H@Z`. The source/ledger trial was restored because
the current-index provider/consumer comparison remains inconclusive; no source
files were removed. All 65 claims acquired by that trial were released.
Other donors remain blocked on missing class members/layout declarations,
including C2039/C2065 failures; mixed files were not edited. The four identity
findings and exact rejected compile diagnostics are prerequisites for a
future Sol pass. Do not repeat this unchanged merge before resolving the
current-base audit and identity findings.

After the upstream fast-forward, the fresh allocator still assigns shard 0/5
and returns 20 destinations. Its current plans include W3DTreeDraw and
W3DTreeBuffer; the refreshed scoped W3D planner snapshot passes its currency
check. The queue has more candidates, but any accepted source-path merge still
requires provider/consumer comparison against the outgoing base. At the time
of the audit, the published index remained at census base `47e030bafc`, behind
`origin/master`; this is the shared LINK-017 blocker. No further TU merge was
eligible for application/publication in that state. No file reduction or debt
retirement is claimed for this continuation.

The handoff-only commit is queued by `/opt/runner/publish` with the runner's
five-commit batch. After rebasing it onto the latest `origin/master`, the
audited outgoing range contains only this attempt-support note: no source path
moves and no outstanding claims from this pass. The W3DTreeBuffer trial was
restored before the rebase.
