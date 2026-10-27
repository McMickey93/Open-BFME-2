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
