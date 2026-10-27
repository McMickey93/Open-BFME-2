# Inherited TU merge handoff (2026-10-27)

Prepared publication of the pending ClickReactionBehavior and AIUnitBuilder merges from
`0bcdf574f6` and `c62b493a75` after rechecking them in the current checkout.

Both destination builds pass their matched rows (4/4 and 13/13), including the
AIUnitBuilder EH funclet pins. `find_declared_unmatched.py` reports no unmatched
definitions for either file. `data_check.py --converged` reports 0 duplicate
addresses across 10 addresses. The shadow data check still reports the existing
`_vtbl_00C4ED70` wrong-name finding in ClickReactionBehavior. The full code
identity gate still stops at an unverified `$L4775` funclet label; no identity
debt retirement is claimed.

The active tooling/path-consumer search found no references to absorbed source
paths outside the resulting AIUnitBuilder provenance comments and an existing
header comment. The previous consolidation review recorded no COMDAT shadow
findings. The outgoing link batch audit remains inconclusive against the stale
`bf3dd31211` census index; preserve that as pending next-census evidence rather
than claiming current census linkage.

## Allocated trials with no source changes

The following destinations passed `consolidation_queue.py --check-tu`; their
guarded dry runs accepted no donors, so nothing was applied:

- `InstantDeathBehavior.cpp`: no verified merge. The pool-key donor lacks the
  `rva00045CF10` declaration; other donors fail on byte mismatch, duplicate
  `GameLogic`, missing `object`, illegal `DestroyDieModuleData` initialization,
  missing `parseOCL`, or missing `m_sounds`. Split inspection of
  `DieModuleDerived.cpp` found no row approved for the TU; splitting
  `RvaVectorDtorFamily.cpp` refuses because a namespace block defines code.
- `LivingWorldAIInformation.cpp`: the only donor fails because `_STL::_Rb_tree`
  is already defined (`C2953`).
- `QueueProductionExitUpdate.cpp`: all merge donors fail on incompatible
  `BitFlags`, duplicate `Xfer`/`Coord3D`, missing class members, or missing
  `rva0004A00C2`. The split of `ModuleNameGetters3.cpp` fails on duplicate
  `QueueProductionExitUpdate`. The separate split trial for
  `Disp8ByteChaseGetters.cpp` passes compile, byte, and split link checks for
  row `0x004A0107`, but was not applied because it did not unblock a merge.
- `ProjectileStreamUpdate.cpp`: donors fail on duplicate `INVALID_ID`,
  `Xfer`, or `GameLogic` declarations, missing `rva0033EE84`, and class-view
  members; no donor was accepted.
- `OneRingPenaltyUpdate.cpp`: donors fail on missing `xfer`, `getModuleNameKey`,
  `update`, and row methods in existing class views, or lose bytes under the
  carried `-G7 -arch:SSE` override; no donor was accepted.
- `ProcessAnimateWindow.cpp`: donor trials fail on duplicate `ICoord2D` and
  missing `finished`/`BfmeVciAnchorElem` declarations; no donor was accepted.
- `MultiplayerSettings.cpp`: the carried `-G7 -arch:SSE` override loses rows;
  other donors have no baseline match. The merge link guard also shows the seed
  itself would stop linking due to unresolved `?parseRGBColor@INI@@SAXPAV1@PAX1PBX@Z`.

These are prerequisites for Sol's source, header, flag and identity lanes; this
seat made no manual repairs. The allocator reported shard `1/3` and 20
destinations; later entries from that first page remain unexamined. No
additional TU merge or net file reduction is claimed. The two inherited merges
remain ahead of `origin/master`, with source and RVA claims still held pending
runner publication.
