# Mechanical consolidation fallback blockers (2026-10-26)

These allocations were checked after the interrupted TerrainBackground trial.
No rejected trial was applied except the temporary ShroudCrateCollide and
AIUpgradeScienceBuilder merges; both were restored with their tool-generated
patches preserved under `build/consolidation/handoffs/` for review. No claims
remain from these trials.

- `W3DTerrainBackground.cpp`: splitting
  `Rva00729300BitPlanes.cpp` was refused because the target path already held
  three rows the TU map did not place there. Splitting
  `W3DTerrainBackgroundDoPartialUpdate.cpp` carved `0x00115044`, but the
  residual loses matched row `0x000ABD19`. The previous session's merge
  dry-run was interrupted and has no verdict.
- `Code/Tools/WW3D/pluglib/matrix4.cpp`: the mixed donor's three rows
  (`0x00715550`, `0x007158F0`, `0x00715BC0`) were each refused because
  “3 definitions spell its name”.
- `Code/GameEngine/Source/Common/Thing/Module.cpp`: the mixed split carved
  `0x00306B13` beside the TU but was refused because the target held two
  unplaced rows. Merge donors failed with `C2375` redefinitions of `AsObject`
  and `AsDrawable` (“different linkage”).
- `Code/Libraries/Source/WWVegas/WWMath/obbox.cpp`: the mixed row
  `0x000B29D3` had “no definition spells its name”; the clean transform donor
  was rejected with “no baseline match”.
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/UnpauseSpecialPowerUpgrade.cpp`:
  both clean donors failed because `getModuleNameKey` is not a member of
  `UnpauseSpecialPowerUpgrade` (`C2039`).
- `Code/GameEngine/Source/GameClient/Drawable/Update/AnimatedParticleSysBoneClientUpdate.cpp`:
  the constructor donor failed with `C2511`, because the constructor overload
  is not declared in the destination class view.
- `Code/GameEngine/Source/GameLogic/Object/Create/SupplyCenterCreate.cpp`:
  its constructor donor failed with `C2039`, because `getModuleNameKey` is
  not a member of `SupplyCenterCreate`.
- `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/ShroudCrateCollide.cpp`:
  the constructor donor failed because the destination view lacked
  `getModuleNameKey`. A temporary one-donor merge passed byte verification,
  but data retirement refused new `wrong-name` findings at `0x00A04060` and
  `0x00A0405C`; post-merge link check could not preview a TU absent from the
  census. The patch and checks are in the build handoff directory above.
- `Code/GameEngine/Source/GameLogic/SkirmishAI/AIUpgrade/AIUpgradeScienceBuilder/AIUpgradeScienceBuilder.cpp`:
  four accepted donors built and matched `16/16`, but post-merge link check
  reported duplicate `UnRegister`, `rva005977D3`, `rva0059781D`, and `shutdown`
  and `1,006 -> 0` linked bytes. `--refresh --current-ledger` could not judge
  the composition because SquishCollide, UnitCrateCollide, and HighlanderBody
  objects were missing. The trial was restored; its patch and checks are in
  the build handoff directory above.

All remaining action is tool-approved unchanged consolidation or a Sol repair
of the specific declaration, data-identity, or link-verification prerequisites.

## Follow-up screen (2026-10-26)

- `Code/GameEngine/Source/GameLogic/Object/Update/DemoTrapUpdate.cpp`:
  the unchanged `Rva00495A2B.cpp` donor passed the merge trial and all five rows
  built byte-exactly. Both inputs linked before (`425 + 73` bytes), but after
  composition the TU lost all 425 linked bytes due to duplicate
  `?rva00495A2B@Rva00495A2B@@QAEXXZ`. Refreshing the destination object
  reproduced the duplicate. The trial was restored; refreshing the restored
  inputs confirmed `425 + 73` linked bytes again. The other donors still need
  class declaration repairs: `getModuleNameKey`, the constructor overload,
  `onObjectCreated`, and `xfer` are absent from the destination view.
- `Code/GameEngine/Source/GameLogic/Object/Die/FXListDie.cpp`: the unchanged
  `FXListDiePoolKey.cpp` donor was accepted and both inputs link (`25 + 78`
  bytes). The required `find_declared_unmatched.py` check reports one
  unclaimed definition in the destination, so no merge was applied. The
  constructor donor was separately rejected because merging would stop
  defining `??_7FXListDie@@6BDieModuleInterface@@@` still referenced by the
  census. `DieModuleDerived.cpp` and `FXListDieOnDie.cpp` remain mixed.
- `Code/Libraries/Source/Apt/AptValueVector.cpp`: the accepted value donor
  matched, but composition removed 204 linked bytes because it duplicated
  `?aptHasAll@Rva004959E0Value@@QAEHXZ`; a refreshed object reproduced the
  loss. Restored inputs linked again (`204 + 17` bytes).
- `Code/Libraries/Source/Apt/DogmaAllocator.cpp`: accepted pool-byte/free-block
  donors matched, but composition removed 239 linked bytes and selected
  duplicate `GetTotalBytesUsed`, `freeBlock`, `g_bfmeAptAllocAtE17728`, and
  `g_bfmeAptFreeSizeAtE17730` providers. Refresh reproduced it; restored inputs
  linked again (`239 + 24 + 205` bytes).
- Other unchanged merge trials produced no accepted donors: `AIGuard.cpp`
  (missing `StateMachine` and `Object` nested declarations),
  `Connection.cpp` (2 rows lost under a carried flag override),
  `GiantBirdAIUpdate.cpp` (missing AI command/type/class declarations),
  `LocomotorSetUpgrade.cpp` and `LifetimeUpdate.cpp` (missing
  `getModuleNameKey`, plus `UpdateModule`), `ActionManager.cpp` (missing
  `CanAttackResult`, `ObjectStatusTypes`, nested types and methods),
  `MessageStream.cpp` (`bytes`, protected allocator, duplicate coordinate and
  subsystem declarations), `AITactic.cpp` (undefined `Xfer::Version`), and
  `CrateSystem.cpp` (duplicate subsystem/STL declarations and undeclared
  generated assignment operator).

No follow-up trial is authorized until the code seat resolves the listed
declaration, frozen-file, data-identity, or provider-selection prerequisites.
