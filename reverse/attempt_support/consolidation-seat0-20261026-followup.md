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
