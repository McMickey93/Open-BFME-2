# Flex-shard unchanged consolidation blockers — 2026-10-26

## BridgeBehavior

The allocated `BridgeBehavior.cpp` plan approved 41 rows from 21 donors, with
ten mixed files and one explicitly refused row. The unchanged merge trial
accepted no donors. The refused row at `0x004565BD` and two other bodies in
`BridgeBehaviorAreaEffects.cpp` expand `__FILE__` into verified bytes. Donor
compile failures were:

- `BridgeBehaviorPoolKey.cpp`, `BridgeBehaviorCreateScaffolding.cpp`,
  `BridgeBehaviorCtor.cpp`, `BridgeBehaviorDtor.cpp`,
  `BridgeBehaviorHandleObjectsOnBridgeOnDie.cpp`,
  `BridgeBehaviorListValueCopy.cpp`, `BridgeBehaviorOnBodyDamageStateChange.cpp`,
  `BridgeBehaviorParseTimeAndLocation.cpp`, and `BridgeBehaviorResolveFX.cpp`:
  lose matched rows under the carried `-G7 -arch:SSE` override.
- `BridgeBehaviorGetInterfaceFromObject.cpp`, `BridgeBehaviorIsScaffoldInMotion.cpp`,
  `BridgeBehaviorListOperations.cpp`, `BridgeBehaviorOnHealing.cpp`,
  `BridgeBehaviorParseOCL.cpp`, `BridgeBehaviorRemoveScaffolding.cpp`,
  `BridgeBehaviorRva00456725.cpp`, `BridgeBehaviorRva0045674D.cpp`,
  `BridgeBehaviorRva00456774.cpp`, `BridgeBehaviorSetScaffoldData.cpp`, and
  `Rva004581FDOnDie.cpp`: no baseline match.

Mixed split trials did not provide an applied merge. `DestroyInstances.cpp`
(`0x0045710A`) and `BridgeBehaviorListCleanup.cpp` (`0x00457441`) have no
definition spelling the target; module-data ctor and Xfer splits would grow a
hatch; module-data dtor and parse-FX splits are blocked by namespace/extern-C
definitions; field-parse split `0x00458268` fails on missing
`PhysicsBehaviorModuleData::m_fieldParse`; module-name getter and Vslot splits
fail with a duplicate `BridgeBehavior` declaration and undefined
`ChecklistUIItemMovieClip`, respectively. The `DispByteFieldGetters.cpp`
`0x004571F4` split trial compiles unchanged, but was not applied because the
remaining donor is 176 rows and no merge is unblocked. The observed compiler
errors and routing report are retained in the session output.

## MetaEvent

The allocated `MetaEvent.cpp` plan approved 11 rows from six donors and one
mixed source. The unchanged merge trial accepted no donor:

- `MetaMap.cpp`: `SubsystemInterface` redefinition plus missing `m_head`.
- `MetaMapFindGameMessageMetaType.cpp` and `parseDebugCommandMap.cpp`:
  `ICoord2D` redefinition in the donor reference headers.
- `MetaMapRecDtor.cpp`: `StringBase` template redefinition.
- `MetaMapParseMetaMap.cpp`: `parseMetaMap` and
  `findGameMessageMetaType` are not members of `MetaMap`.

The mixed `GameClientDrawableTOC.cpp` row at `0x001DB432` is inside a
namespace/extern-C block the split tool cannot carve. No trial changed source,
ledgers, claims, or routing.

## Additional allocated trials

- `HealContain.cpp`: its unchanged merge dry run accepted
  `HealContainModuleDataParse.cpp`, but the required accepted split donor
  `ConstIntGetters4.cpp` was held by another worker, so no part was applied.
  The `FlatMultiVptrDestructors.cpp` split for `0x00466B45` was blocked because
  a copied helper or datum would grow a hatch. My destination/donor/RVA claims
  were released; the other worker's claims were untouched.
- `MoneyCrateCollide.cpp`: unchanged merge accepted no donors. Its ctor donor
  fails with C2504 (`CrateCollide` base undefined); its pool-key donor fails
  with C2039 (`getModuleNameKey` not a member of `MoneyCrateCollide`).
- `W3DSnow.cpp`: unchanged merge accepted no donors. The constructor trial
  fails on undeclared `WeatherSetting`/`OVERRIDE`; getters, reset, blend-phase
  and state-transition trials fail on missing `W3DSnowManager` members/fields;
  render-sub-box and render trials lack `W3DSnowManager`; the game-client
  finish donor lacks its `SnowManager` base. The mixed render-as-quads split
  for `0x00093CC3` was rejected because the residual loses matched row
  `0x00083BD4`.
- `SupplyCenterProductionExitUpdate.cpp`: merge accepted no donors. The pool
  key has no declared `getModuleNameKey`; the ctor has undefined `UpdateModule`;
  the accepted-donor verification also fails on explicit instantiation of
  `_STL::allocator<char>`. Its mixed source has no rows approved for this TU.
- `StealthUpgrade.cpp`: its three-row constructor donor stopped compiling
  after the accepted split added a class view, and the pool-key and
  implementation donors still fail on undeclared members. The verified split
  of `0x004B532D` from `ModuleNameGetters3.cpp` was retained. It creates the
  previously absent `StealthUpgrade.cpp`, increasing the source-file count by
  one.

The PreorderCreate merge audit records two new shadow `wrong-name` findings
for its transferred local-static data keys (`0x00A03F90` and `0x00A03F94`).
The converged data check remains clean; neither key was claimed retired.

## Flex seat 4/5 follow-up

- `RiderChangeContain.cpp`: unchanged merge accepted no donors. The ctor
  requires a `TransportContain` default constructor; pool key is already
  defined; Xfer has an `Xfer` redefinition/`Version1` issue; several module
  data and behavior donors hit duplicate `AsciiString` declarations; the
  parse donor triggers an MSVC internal compiler error; `RemoveFirst` needs
  inaccessible `Module::m_moduleData`; `Rva047E59EKill.cpp` lacks
  `Rva047E59EDamage8`. No edits or claims were made.
- `UnpauseSpecialPowerUpgrade.cpp`: the merge trial accepted its pool key,
  module-data ctor and upgrade-name-ref donors and byte-verified all four
  rows. The two remaining donors need `getModuleNameKey` declarations. Staged
  identity audit found a new unreferenced `/alternatename` for
  `_vtbl_00BF2558`; `repair_queue.py retire data` refused two wrong-name local
  static keys at `0x00A03E68` and `0x00A03E64`. The trial was restored and
  claims released for Sol's identity review.
- `AIUnitUpgrader.cpp`: the accepted destructor donor byte-verified six rows,
  but staged identity audit found the destructor's binding at `0x00506B28`
  collides with the existing `Rva00506B28DwordImmSetter::apply` owner. The
  trial was restored and claims released.
- `HealContain.cpp`: merged the accepted module-data parse donor; pool-key and
  Xfer donors still need member declarations.
- `ProjectileStreamUpdate.cpp`: merged the accepted `Rva0033EF86.cpp`; ctor,
  pool-key, Xfer and `getAllPoints` donors remain blocked by missing declarations
  or duplicate declarations.
- `DynamicShroudClearingRangeUpdate.cpp`: merged accepted animate-grid-decals
  and Xfer donors. Ctor, pool key, update and module-data ctor still require
  declaration or special-member work.

Publication handoff: the publisher stopped once with `Cannot rebase onto multiple
branches`. A subsequent explicit `git pull --rebase origin master` fetched
`5db17fb47684656adf2563faf60b3c9e4872f069` and rebased the complete 14-commit
pending batch cleanly. No merge conflict or source change resulted; publication
is still pending.

## Flex seat follow-up — Luna session 2026-10-26

Two tool-accepted unchanged merges landed in the verified staging set:

- `MoneyCrateCollidePoolKey.cpp` merged into `CrateCollide/MoneyCrateCollide.cpp`;
  four matched rows were byte-verified. The ctor remains rejected: C2511,
  `MoneyCrateCollide(Thing *, const ModuleData *)` is absent from the target
  class view. The merge tool transferred its data-check and data-ledger keys;
  converged data check passes, while shadow data check still reports two
  wrong-name local-static keys at `0x00A04058` and `0x00A04054`.
- `SupplyCenterProductionExitUpdateExitDoor.cpp` merged into
  `ProductionExitUpdate/SupplyCenterProductionExitUpdate.cpp`; three matched
  rows were byte-verified. The pool key remains rejected because
  `getModuleNameKey` is absent from the class view (C2039); the behavior ctor
  lacks the `UpdateModule` base declaration (C2504).

Both destination builds and `find_declared_unmatched.py` pass. The staged
TU-ownership check, `repair_queue.py verify-removed`, and converged data check
pass. Staged code-identity shadow audit reports two new divergent-definition
findings (`??0Vector3@@QAE@ABV0@@Z` and `??AMatrix3D@@QBEABVVector4@@H@Z`);
no identity key was retired.

Further allocated unchanged trials accepted no donors and remain for a source
prerequisite pass: `StealthUpgrade.cpp` (ctor overload absent; pool key and
upgrade methods absent), `DockUpdate.cpp` (member declarations/fields absent,
duplicate `ObjectID`/`GameLogic` definitions, and special-member destructor
cannot be declared), `FireWeaponCollide.cpp` (`CollideModule` base and several
member declarations absent), `HealContain.cpp` (`getModuleNameKey` and `xfer`
absent), and `TunnelContain.cpp` (ctor/member declarations and destructor
special member absent). For `RiderChangeContain.cpp`, no donor merged; its
`ModuleNameGetters.cpp` carve matches alone but donor composition fails with
C2953 `StringBase` template redefinition. The `DockUpdate.cpp` dry run was
allowed to finish; no second compiler trial was started.

## Luna shard continuation — W3DPropDraw and Keyboard

- `W3DPropDraw.cpp`: accepted the unchanged `W3DPropDrawModuleDataDtor.cpp`
  donor and byte-verified five rows including the three EH rows. Its staged TU,
  data and ownership checks pass. Shadow identity reports one new divergent
  `??1ModuleData@@UAE@XZ` definition. The pool-key row lacks its class member
  declaration (C2039), the module-data ctor initializes absent member
  `m_distanceFog` (C2614), and the react donor duplicates `Coord3D` (C2011).
- `Keyboard.cpp`: dry-run accepted its three donors plus the TU seed and
  byte-verified 15 rows; `KeyboardInitUpdate.cpp` loses a member declaration
  and duplicates `KEY_STATE_DOWN`, while `KeyboardRva00232AE8.cpp` and
  `rva00232B7BRva00232B7BFarm.cpp` conflict on `_STL::allocator`. Applying the
  accepted donors was refused before writing because `hatch_counters.py`
  requires the prior W3D merge's modified files to be committed first. Retry
  after that commit; no Keyboard source or ledger change was applied.
- `MaxHealthUpgrade.cpp`: accepted no donors. Its module and implementation
  donors both require an undeclared `getModuleNameKey` member (C2039).

## Keyboard.cpp follow-up, 2026-10-26

Applied the unchanged accepted split for `Code/GameEngine/Source/GameClient/Input/Keyboard.cpp`: absorbed `KeyboardInitKeyNames.cpp`, `KeyboardCheckKeyRepeat.cpp`, and `KeyboardRva00232A42.cpp`; retained 15 matched rows. The unchanged dry-run accepted exactly those three donors. It rejected `KeyboardInitUpdate.cpp` (duplicate `KEY_STATE_DOWN`, missing `init` member), `KeyboardRva00232AE8.cpp` and `rva00232B7BRva00232B7BFarm.cpp` (STL allocator redefinition). No rejected donor was changed.

`./build.sh Code/GameEngine/Source/GameClient/Input/Keyboard.cpp` passed: 15/15 rows matched; `find_declared_unmatched.py` passed. `code_identity_gate.py --staged` found 0 new findings in shadow mode; `data_check.py --staged` found 0; `tu_ownership.py --staged --shadow`, `repair_queue.py verify-removed`, and `hatch_counters.py --staged` passed. The merge carried the protected-register key of three absorbed donors and kept the total unchanged using the tool-required `Verifier-Change` trailer. No debt key retired.

## FloatUpdate.cpp trial, 2026-10-26

The current allocator served `Code/GameEngine/Source/GameLogic/Object/Update/FloatUpdate.cpp` (7 rows). Fresh planner snapshot/check passed; unchanged `tu_skeleton --merge ... --dry-run` accepted no donors. `FloatUpdatePoolKey.cpp` fails because `rva00048D761` is not declared on `FloatUpdate`; `FloatUpdateModuleDataCtor.cpp` fails because `m_vtable` is undeclared. No source or ledger changes were made; claim released. Skip this unchanged failure unless the declarations or donor change.

## UnpauseSpecialPowerUpgrade.cpp merge, 2026-10-26

Applied the unchanged accepted split for `Code/GameEngine/Source/GameLogic/Object/Upgrade/UnpauseSpecialPowerUpgrade.cpp`: absorbed `UnpauseSpecialPowerUpgradePoolKey.cpp`, `UnpauseSpecialPowerUpgradeModuleDataCtor.cpp`, and `Rva004B555FUpgradeNameRef.cpp`; 4 matched rows. Rejected constructor and implementation donors still lack `getModuleNameKey` declarations in their classes. Build and frozen-file check passed, 4/4 rows matched. TU ownership, removed-row verification, and hatch counters passed. The merge tool carried the data register entries and moved the one `alternatename` hatch to the new owner, totals preserved.

The suggested owner command `repair_queue.py retire data Code/GameEngine/Source/GameLogic/Object/Upgrade/UnpauseSpecialPowerUpgrade.cpp` refused and retired nothing: fresh findings remain wrong-name at `0x00A03E68` and `0x00A03E64`. Staged shadow identity also reports the moved `alternatename` as one new finding. These are retained for the register owners; no manual baseline or source changes were made. Path audit found no consumers of the three removed donors outside comments in the consolidated TU.

## Luna shard continuation — W3DSnow and AutoDepositUpdate

- `W3DSnow.cpp`: merged four unchanged accepted donors and retained four
  matched rows. Build (20/20), frozen-file check, code-identity, data, ownership,
  EH and path-consumer checks passed. The commit gate reports one shadow
  invented-name finding for existing `g_Va00BBB8D8`; no identity key was
  retired. Commit `be2b7e26b0` is waiting in the publisher's batch and has not
  yet been confirmed landed.
- `AutoDepositUpdate.cpp`: merged the unchanged pool-key and update donors;
  eight rows build byte-exactly and the frozen-file check passes. The ctor
  donor remains rejected with C2511 because the class view has no matching
  `AutoDepositUpdate(Thing *, const ModuleData *)` declaration. The merge
  preserved the data-register keys at `0x00A03B14` and `0x00A03B10`; the owner's
  prescribed `repair_queue.py retire data` check refused them because the
  fresh verdict still reports two `wrong-name` static-local symbols. The
  converged data check, staged code-identity check, TU ownership, removed-row
  verification and hatch counters pass. No data key retired. Active tooling
  search found no consumer of the absorbed donor filenames; historical link
  and attempt records retain their original provenance paths.

## W3DDisplayStringManager.cpp trial, 2026-10-26

The allocated full-queue fallback listed `W3DDisplayStringManager.cpp` after
first-page work was exhausted. Fresh planner/check passed; unchanged dry-run
accepted no donors. `Rva00090360Ctor.cpp` is rejected because the class view
lacks `rva00090381` (C2039); `W3DDisplayStringManager.cpp` from the Common TU
is rejected because `m_14` is absent and `rva00090381` is undeclared (C2065,
C3861). No source or ledger changes were applied. Skip unless the class view
or donor changes.

## W3DBibBuffer.cpp trial, 2026-10-26

The allocated full-queue fallback listed this TU with three removable rows and
no mixed donors. Its merge dry-run ran a single trial process for about two
minutes, then exited without returning its output to the session. It left no
source/ledger changes or live trial process. Result is inconclusive; do not
repeat the unchanged compile in this session.

## debug_io_net.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The only donor,
`DebugIONet_Create.cpp`, is rejected on duplicate allocator definitions:
C2375 `operator new` has different linkage and C2084 `operator delete` is
already defined. No source or ledger changes were applied; skip unless donor
composition changes.

## GlobalData.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. Five donor
trials were rejected: `GlobalDataSetTimeOfDay.cpp` needs absent terrain fields;
`rva00235312Rva00235312Farm.cpp` lacks the method and terrain fields;
`GlobalDataOptionPreferences.cpp` needs absent preference fields;
`Rva00236285Ctor.cpp` has an undefined base and negative subscript; and
`Rva002362B4Dtor.cpp` fails parsing at `m_basicTutorialMap`. No source or ledger
changes were applied. Skip these unchanged donors pending a source-prerequisite
pass.

## CrushDie.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The
`CrushDieOnDie.cpp` donor lacks the `DieModuleInterface` base and `CrushDie::onDie`
member (C2504, C2039). The allocated TU's mixed `DieModuleDerived.cpp` donor
was inspected; its split dry-run refused because no row is approved for
`CrushDie.cpp`. No source or ledger changes were applied.

## debug_io_ods.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors because the
alternate `DebugIOOds.cpp` donor repeats the already-defined constructor
(C2084, followed by C2264). The allocated mixed `DebugIOOds_Create.cpp` donor
was inspected; split dry-run refused because carving `0x0003F3D0` would grow a
hatch count. No source or ledger changes were applied.

## GlobalLanguage.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The destructor
and constructor donors lack `TheGlobalLanguageData` declarations, the list
clear donor lacks `Rva001EA443`/template declarations, the exit callback lacks
platform declarations, and the parser lacks `INI::getNextAsciiString`. All
three allocated mixed donors were inspected: `StringRecordCopyBFME2.cpp` split
is unsupported across its namespace/extern-C block; both STL list donors have
no definition spelling their candidate symbols. No source or ledger changes
were applied.

## WindowLayout.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The lowercase
`window_layout.cpp` donor lacks `GameWindowManager::managerSlot35` (C2039); the
quick-match base default ctor cannot be defined as a compiler-generated
special member without a declaration (C2600). The `AsciiStringFoldDeleters.cpp`
mixed split for `0x00538C5F` was compiler accepted but would not unblock an
accepted merge, so it was not applied. The constructor mixed split for
`0x00538C6D` was refused because copying its helper/data grows a hatch count.
No source or ledger changes were applied.

## W3DProjectileStreamDraw.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The module-data
dtor donor is a byte mismatch; the module and object dtors need declarations;
the ctor lacks its `DrawModule` base; and the pool-key class view lacks
`getModuleNameKey`. The `W3DDrawNameGetters.cpp` split for `0x000D1401` was
accepted as an isolated row but did not unblock its donor's merge (still
missing `setFullyObscuredByShroud`), so it was not applied. Splits for the
mixed deleting dtor and render inline rows refused because no definition spells
their symbols. No source or ledger changes were applied.

## W3DLaserDraw.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The module-data
ctor duplicates `RefCountPtr`; `doDrawModule` duplicates `AsciiString`; module
data dtor and vector overflow donors are byte mismatches; the object dtor has a
`void *`/`RefCountPtr` type mismatch; and the pool key lacks a class member.
The `W3DDrawNameGetters.cpp` split for `0x000C9C11` was compiler accepted in
isolation but did not unblock any donor merge, so it was not applied. Both STL
mixed donors' rows had no definition spelling the target symbols. No source or
ledger changes were applied.

## CommandSetUpgrade.cpp trial, 2026-10-26

Fresh planner/check passed; unchanged dry-run accepted no donors. The pool-key
donor lacks `CommandSetUpgrade::getModuleNameKey` in the class view (C2039),
and `Rva004B3AFFNotify.cpp` lacks a `TheControlBar` declaration. Its mixed
`FireWeaponWhenDeadBehaviorDerived.cpp` split was refused because no row is
approved for this TU. No source or ledger changes were applied.

## StealthDetectorUpdate.cpp split and merge follow-up, 2026-10-26

Fresh planning and unchanged dry-run accepted the `GapBodiesGE10.cpp` row at
`0x004A2BF0` and the `ModuleNameGetters3.cpp` name getter at `0x004A2BEA` as
approved splits into this retail TU. Both splits were applied with
`tu_skeleton.py`; the three affected sources build with 125/125 matched rows,
all three frozen-file checks pass, and staged code identity, data, TU ownership,
removed-row and hatch checks report no new findings. The mixed
`ModuleDataBuildFieldParse.cpp` row at `0x004A2D82` remains unsplit because
another worker holds that source file. The refreshed merge dry-run accepted
`Rva004A2D49.cpp` and `Rva004A2D67Init.cpp`; its earlier accepted donors were
rejected after the split changed TU composition. Apply the latest dry-run only
after this split batch is committed, then record any remaining donor failures
from a fresh plan.
