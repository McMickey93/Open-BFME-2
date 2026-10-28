# Consolidation shard 1 trial — 2026-10-27

Allocated TU: `Code/Libraries/Source/Apt/AptObject/AptScriptColour.cpp` (queue check passed). The current planner snapshot passed `--check`.

`tu_skeleton.py --merge ... --dry-run` accepted no donors and blocked because no verified merge of two or more donors was possible. `Rva006F2C50Siblings.cpp` was rejected with `compile: ...AptScriptColour...tu_skeleton.cpp(121) : error C2039: 'DestroyGCPointers' : is not a member of 'AptObject'` (same C2039 diagnostic repeated). Leave this for a source/header repair.

Inspected all three mixed-file paths shown by the plan:

- `AptFactoryConstructors.cpp`: split blocked because a copied helper carries an escape hatch and would grow its count (hatch_counters rule 3).
- `Rva006D6470Derived.cpp`: split blocked by SplitLinkGuard; moved selected COMDATs `??1Rva006F25D0@@UAE@XZ` and `??_7Rva006F25D0@@6B@` lack matching private/weak-free context.
- `BfmeConv1082.cpp`: split dry run accepted one carved row and moved four data globals, but leaves an unapproved residual row and removes no source file; no merge was unblocked by this trial, so it was not applied.

No TU, source, ledger or hatch files were changed by these trials. This candidate is handed to Sol for the declaration prerequisite and to a future consolidation seat only if its blockers change.

## ControlBarScheme allocated trial

`Code/GameEngine/Source/GameClient/GUI/ControlBar/ControlBarScheme.cpp` passed its allocation check and planner snapshot check. Its merge dry run accepted no donors. LinkGuard blocked the seed composition because the census-linked seed would gain unresolved `??0INI@@QAE@XZ`; another census-linked donor would gain unresolved `?findCommandButton@ControlBar@@QAEPBVCommandButton@@ABVAsciiString@@@Z`. Remaining rejected donors had duplicate `sqr`/`_STL::_List_base`/`StringBase` definitions, absent class members (`init`, `update`, `m_08`) or unspellable rows. No merge was applied.

Both mixed sources were inspected. `ControlBarScheme_ControlBarSchemeManager_newControlBarScheme.cpp` split refused because a namespace/extern-C block defines something. `Rva004CEB76ListSort.cpp` has no definition spelling target row `0x00320095`, so no row could be carved. No source, ledger or map changes were made.

## PartitionManager allocated trial

`Code/GameEngine/Source/GameLogic/Object/PartitionManager.cpp` passed allocation and planner checks. Its merge dry run accepted no donors. Census-linked candidates would introduce unresolved `canEnterObject`, `clientSafeQuickDoesPathExist`, and `AsciiString::freeBytes` (some also `CDEArraySlot`); two donors have empty flag overrides versus carried `-O2`. Other exact first failures were `PartitionData::maybePrepend`/`m_field14` absent, no `PartitionData::makeDirty` overload, private `CellAndObjectIntersection::m_cell`, duplicate `AsciiString`, and disallowed `friend_updateCellsTouched` redeclaration.

All five mixed files were inspected. The `PartitionManagerShroudThunks.cpp`, `SubsystemNameGetters5.cpp`, and `Rva00170C0Siblings.cpp` splits reached compile/byte checks but were blocked because the destination TU path holds four unplaced rows. `Bfme5ThirtyFour.cpp` was blocked by hatch count growth from a copied helper. `Open2Twins006.cpp` would leave matched row `0x007396E0` behind. No split or merge was applied.

## W3DVideoBuffer allocated trial

`Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DVideoBuffer.cpp` passed allocation and planner checks. The merge dry run accepted no donors. Four donors lost matched rows under the carried empty flag override. Census-linked donors would add unresolved `VideoBuffer::VideoBuffer`, `RefCountClass::Dec_Total_Refs`, and `SurfaceClass::Lock`. Other donors had no baseline match. No merge was applied.

Inspected all four mixed files. Splits from `Bfme5FiftySeven.cpp` were flag-bound; `S1ZeroingConstructors.cpp` passed one row's compile/byte check but the destination has one unplaced row; `VslotSmallBodiesB.cpp` refuses a namespace/extern-C definition; and `VtableSlotBodiesR3.cpp` passed two row checks but hit the same unplaced destination row. Inspecting the destination split confirms none of its rows are approved for carving to itself. No split or source/ledger changes were applied.

## FireWeaponWhenDamagedBehavior accepted trial left for path repair

The allocated `Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDamagedBehavior.cpp` dry run accepted its seed plus unchanged `FireWeaponWhenDamagedBehaviorDtor.cpp` and `StlSweepR3Rva00482A4D.cpp`; `Rva00482641Xfer.cpp`, `FireWeaponWhenDamagedBehaviorPoolKey.cpp`, and `FireWeaponWhenDamagedBehaviorUpdate.cpp` were rejected on missing class declarations. Before applying, the path-consumer search found the deleting donor explicitly listed as an open target in `docs/linking_targets.md:421`. No tool or hook consumes that document, but its current manual target entry must be reconciled by Sol before the deletion. Left the trial unapplied and released the destination, donor, and both RVA claims. No source or ledger changes.

## FloatUpdate allocated trial

`Code/GameEngine/Source/GameLogic/Object/Update/FloatUpdate.cpp` passed allocation and planner checks. The merge dry run accepted no donors: `FloatUpdatePoolKey.cpp` fails because `rva00048D761` is undeclared on the class; `FloatUpdateModuleDataCtor.cpp` fails because `m_vtable` is undeclared. Both are census-linked and preserved as separate objects.

Inspected all four mixed sources. `ModuleNameGetters3.cpp`'s carved getter fails on duplicate `FloatUpdate`; `Rva0024A797Derived.cpp` has no row approved for this TU; `FloatUpdateUpdate.cpp` would grow an escape hatch via a copied helper; and `ModuleDataBuildFieldParse.cpp`'s carved row fails on duplicate `FloatUpdateModuleData`. Nothing was applied.

## Additional allocated trials

`LivingWorldAIInformation.cpp` passed allocation and planner checks. Its merge dry run accepted no donors; `stlport_map_004FF8DA.cpp` fails because `_STL::_Rb_tree` is already defined. It has no mixed sources. No changes.

`MultiplayerSettings.cpp` passed allocation and planner checks. The merge dry run accepted no donors: five donors are flag-bound (their byte-matched rows fail under the destination's carried `-G7 -arch:SSE` flags); other rejected donors have no baseline match. The `MultiplayerColorMapOperator.cpp` split is blocked by a namespace/extern-C block defining something; `stlport_construct_stl_types2.cpp` cannot carve a row because no definition spells the target. No changes.

`DockUpdate.cpp` passed allocation and planner checks. Its merge dry run accepted no donors. Compile blockers include missing `loadDockPositions`, duplicate `ObjectID`/`GameLogic`, undeclared `onApproachReached`, `m_owners`, and `xfer`, missing `m_id`, and a compiler-generated special-member failure. Of seven mixed sources, `GapBodiesGE32.cpp`, `VslotSmallBodiesAF.cpp`, and `DockUpdateCtor.cpp` are blocked by namespace/extern-C definitions; `VectorObjectIDFillInsert.cpp` has no carveable definitions; `ModuleNameGetters.cpp` fails because `DockUpdate::isClearToApproach` is absent; two other split dry runs accepted rows but unblocked no merge. No changes.

`FirewallHelper.cpp` passed allocation and planner checks. Its merge dry run accepted no donors; the seed itself failed byte verification under all tested merged flag sets. Other rejected candidates have missing/mismatched declarations, duplicate `StringBase`, or a compiler-generated destructor failure. `Rva0059510DClear.cpp` split would lose matched row `0x004D4B8B`; `Disp8WordFieldGetters.cpp` and `GapBodiesGE17.cpp` were blocked by SplitLinkGuard because outside consumers lose `findEmptyMessage` / `findSpareSocketByPort` providers and selected implementations change. No changes.

`ExperienceScalarUpgrade.cpp` passed allocation and planner checks. The merge dry run accepted no donors; `ExperienceScalarUpgradeConstructor.cpp` and `ExperienceScalarUpgradeUpgradeImplementation.cpp` both fail because `ExperienceScalarUpgrade::getModuleNameKey` is missing. `FireWeaponWhenDeadBehaviorDerived.cpp` has no row approved for this destination. `ModuleDataBuildFieldParseChained.cpp` passed a one-row split dry run for `0x004B61A4` and `BfmeExperienceScalarUpgradeFields`, but no merge was unblocked, so it was not applied. No changes.

`CrateCollide.cpp` passed allocation and planner checks. Its merge dry run accepted no donors. `CrateCollideXfer.cpp` fails because `BehaviorModule` is an undefined base class; `CrateCollideIsValidToExecute.cpp` fails because `CrateCollide(Thing *, const ModuleData *)` has no declaration. The plan has two mixed sources: `Rva004BB68EDerived.cpp` has no row approved for this destination; `CollideModuleDataBuildFieldParse.cpp`'s one-row carve (`0x004BC7FE`) leaves three matched rows in an uncompilable residual (`CrateCollideModuleData` is not a class or namespace). No changes.

These are source/header prerequisites for Sol; no TU, source, ledger or map changes were applied in these additional trials.

`WindowLayout.cpp` passed allocation and planner checks. Its merge dry run accepted no donors: `window_layout.cpp` fails because `GameWindowManager::managerSlot35` is undeclared, while `BfmeQuickMatchScreenBaseDefaultCtor.cpp` cannot define the compiler-generated constructor. `AsciiStringFoldDeleters.cpp`'s carved `0x00538C5F` compiles and matches alone, but SplitLinkGuard rejects it because the moved selected destructor/vtable COMDATs lack matching private/weak-free context. `BfmeQuickMatchScreenBaseConstructor.cpp`'s carved `0x00538C6D` is refused because a copied helper would grow an escape-hatch count. No changes.

`AutoDepositUpdate.cpp` passed allocation and planner checks. Its merge dry run accepted no donors: `AutoDepositUpdateCtor.cpp` has no declaration for `AutoDepositUpdate(Thing *, const ModuleData *)`, and `GlobalFlagClearers_E03Bxx.cpp` fails byte verification. The only mixed source, `Rva0024A797Derived.cpp`, has no row approved for this destination. No changes.

## 2026-10-27 resumed-seat trials

After rebasing the inherited handoff commits on current `origin/master`, these allocated TUs passed `--check-tu`, their scoped planner snapshots passed `--check`, and their merge dry runs made no source or ledger changes:

- `GameEngine.cpp`: accepted none. Seed fails every merged flag set with C2226 `NetworkInterface` syntax and undeclared `TheNetwork`; LinkGuard names the seed plus eight other census-linked units. Donors fail on missing `GameEngine` declarations/members and a compiler-generated constructor.
- `ProcessAnimateWindow.cpp`: accepted none. Donors fail on duplicate `ICoord2D`, missing `finished`/other class members, and undeclared `BfmeVciAnchorElem`; LinkGuard lists seven census-linked units.
- `W3DDisplayString.cpp`: accepted none. Seed is blocked by LinkGuard because merged object loses `?TheNullChr@?1??str_RV@UnicodeString@@QBEPBGXZ@4GB`, still referenced by the census. Other donors fail on undeclared constructor and string/member declarations.
- `RankInfo.cpp`: accepted none. Donors hit duplicate `_STL::vector::begin` and global `operator new`/`delete` linkage definitions. LinkGuard lists three census-linked units.
- `Snow.cpp`: accepted none. Donors require missing `SnowManager` and `WeatherSetting` declarations/special members; plan reports `adopt_first: SubsystemInterface`. LinkGuard lists five census-linked units.
- `TacticalAI.cpp`: accepted none. Donors fail on absent `AITargetChooser::rva00505408`, duplicate `_STL::allocator`, incompatible `void *` constructor argument, and absent `Object::m_ptr4`; LinkGuard lists six census-linked units.
- `AIUnitBuilder.cpp`: accepted none. Donors fail on absent `AIUnitBuilder::rva00598016`/`getAI`, duplicate `_STL::hashtable`, and missing declarations; LinkGuard lists five census-linked units.
- `INIWater.cpp`: accepted none. One donor is `bytes`; others fail on duplicate `_STL::allocator`/`vector`, a missing `WaterTransparencySetting(int)` declaration, and duplicate `OVERRIDE`; LinkGuard lists five census-linked units.
- `Mouse.cpp`: merge stopped before donor trials because the TU itself loses one row under the carried flag override. `adopt_first` reports `SubsystemInterface` for `Rva001EE3DEDtor.cpp`; LinkGuard lists 15 census-linked units.

No destination or donor claims were taken, so there are no live claims to release. All remaining failures need source/header, flag, or provider work outside this mechanical seat. No TU was merged; net source-file reduction is zero and all matched rows remain untouched.

Additional full-list allocated trials from the resumed seat, all with current scoped planner checks and no source or ledger writes:

- `PlayerTemplate.cpp`: accepted none. Donors require `PlayerTemplateVector::operator[]`, `PlayerTemplateStore` methods/members, and `TheNameKeyGenerator`; other donors duplicate `_STL::_List_iterator::operator!=`, `_STL::_Rb_tree`, and `StringBase`, or fail bytes. LinkGuard lists 14 census-linked units.
- `udp.cpp`: accepted none. Three donors require missing `UDP::rva00594976`, `UDP::rva00594A06`, or `UDP::rva00594B2E` and corresponding socket/error members. LinkGuard lists the seed and all three donors.
- `frustum.cpp`: accepted none. `FrustumInitWrappers.cpp` requires absent `FrustumClass::rva00133400` and `Init`. LinkGuard lists both objects.
- `AptValueGCAllocator.cpp`: accepted none. `Rva006D29E0Cluster.cpp` duplicates `Rva006D2A60::isAllocated(int)` and references undeclared `mValueBitfield`. LinkGuard lists both objects.

Allocator `--limit 100000` was inspected after exhausting the first 20. Additional allocated TUs remain for a future mechanical seat; no claims are held. This session made no merge, split, source, ledger, map, register or identity changes. Net source-file reduction: 0; verified TUs merged: 0; matched rows touched or lost: 0. Remaining allocator candidates need their own scoped planner and guarded dry runs.

Resumed mechanical seat merge:

- `Code/Libraries/Source/WWVegas/WWLib/BfmeContainerRecord005FDEC7.cpp` absorbed five unchanged donors (`Rva005F921FButton.cpp`, `Rva005F9330FadeOut.cpp`, and the three `Rva005F93CB/3D3/DBForward.cpp` files). Guarded dry run accepted five rows; the two remaining button donors were rejected with exact missing-member errors for `SetRealTimeButtonEnabled` and `SetRetreatButtonEnabled` in `StrategicHUD::BattlePromptMovieClip::Impl`; left for Sol. Four mixed donors remain untouched.
- LinkGuard accepted the five-row composition while listing the seven affected census-linked units. `./build.sh <TU>` passed with all 5/5 rows matched and string/import/float reference checks clean; `find_declared_unmatched.py <TU>` reported every definition already matched. No data rows moved. `tu_ownership.py --staged --shadow` and `invented_names.py --staged --shadow` reported no findings; staged `data_check` had 0 findings and converged data had 0 second names. Case-collision check passed.
- The path consumer search found no active tool, hook, workflow, include, build, or registry reference to the five removed donor paths. Remaining old-path references are the committed census snapshot, historical attempt evidence, donor provenance comments emitted in the TU, and unrelated C++ evidence/comments. The census snapshot was left to its owning census workflow. `tu_map.py --check` reports the map stale after this merge; no regenerated map was written, per lane rules.
- No identity baseline or data identity register changed; the merge tool repointed only `reverse/functions.csv` and `reverse/tu_map.csv`. The outgoing link-batch audit still runs in the pre-push hook and must be read before this path move is considered published. Current net for this merge: five source files removed, five matched rows preserved; no byte recovery or identity-debt retirement claimed.

Second allocated TU trial:

- `Code/GameEngine/Source/Common/AreaPolygonBase.cpp` absorbed ten unchanged donors across Common and WWLib, repointing 14 rows. Guarded dry run and apply accepted the same ten donors. It rejected `Rva0030B7C2PointQuery.cpp` because combining it would break another unit's `??0Rva0030D111Point@@QAE@ABU0@@Z` provider; that donor remains untouched. Other rejected donors need private-view/header or class declaration repairs (`AreaPolygonBase::parse`, `rva0030B135`, `rva0030B1A7`, `rva0030B232`, `rva0030B3D1`, `deletePoint`, `reserve`, `setPoint`, and `operator=`); they remain for Sol, with no retry.
- `./build.sh <TU>` passed, all 14/14 moved rows matched, and `find_declared_unmatched.py <TU>` found no unrowed definitions. The staged identity ownership check had no blocking finding; B2 only reported a diagnostic layout fingerprint for `Rva0030B2B6Elem` resembling registered `Coord2D`. Staged data checks had 0 findings, converged data had 0 second names, case-collision and whitespace checks passed. No data rows moved.
- The combined path audit across both merge commits found no active tool, hook, workflow, include, build, or registry consumers of removed donor paths. Old path strings remain in the census snapshot, historical naming/attempt evidence, and generated TU provenance comments. Header and MS-header queues had no entries keyed to either destination or the absorbed donors. Do not edit the census snapshot or historical evidence in this lane. LinkGuard preserved the accepted donors' census-linked bindings and rejected the point-query donor for the specific provider break above; pre-push link-batch audit remains pending.
- Current net across both verified merges: 15 `.cpp` files removed, 19 matched rows preserved across two approved TUs; 0 data rows moved and no byte recovery or debt retirement claimed. The first merge commit was handed to the fleet publisher; the second merge and this handoff update are the current pending path-change batch. `tu_map.py --check` remains stale after the moved rows; no regenerated map was written.

Third allocated TU trial:

- `Code/GameEngine/Source/Common/BfmeStringRecord00426A5B.cpp` absorbed four unchanged getter donors and repointed four rows. The two remaining setters fail because their private `Rva004266A1` view lacks the sibling getter declaration; left for Sol without retry. Three mixed donors remain untouched.
- Build and declaration scan passed, with all 4/4 moved rows matched. Staged TU ownership and invented-name checks had no findings; data checks had 0 findings, converged data had 0 second names, and case/whitespace checks passed. Header, MS-header, code-identity and data-identity searches had no rows keyed to this TU or its four donors.
- The path search found only the committed census snapshot and generated donor provenance comments. The census data remains owned by the census workflow. No data rows moved and no identity retirement is claimed. Combined pending source moves are checked before the next publish.
- Mixed-donor split checks required by the allocated plan: `GapBodiesGE01.cpp` could carve `0x00426A15` but refused because a namespace/`extern "C"` block defines something; `OpaqueScalarDeletingDtorsB10.cpp` refused `0x00426A3F` because no definition spells its name; `StringRecordCopyBFME2.cpp` found `0x00426A5B` and `0x004267CC` but refused because a namespace/`extern "C"` block defines something. No split was applied.
- The combined path-consumer scan for the four removed getter paths found no active tooling, hook, workflow, or other source consumers; occurrences in the destination are generated TU provenance comments. Hidden `.*.tu_skeleton.cpp` scan under `Code/` was empty. Tooling compatibility audit found no consumer updates required. LinkGuard accepted the four donors; pre-push link-batch audit remains pending.
