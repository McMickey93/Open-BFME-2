# Function-local static data index refresh (non-pool-key sources)

Inspected `69af5a370a` on 2026-10-27. Continues
`module-poolkey-data-index-20261027-claude.md` with the same recipe over the
remaining register sources whose generated data-ledger rows are owned and
singly defined by the flagged source: Rva-named accessors, cached-key and
init helpers, script action/condition statics, WW3D2 render statics and a
few pool-key files freed by other workers.

## Target facts

Each flagged address is a function-local static or its `$S` guard in the
current object. The committed `reverse/data_ledger.csv` still named most
of them after retired `GlobalFlagClearers_*.cpp` address globals (status
provisional) or after an older accessor spelling.

## Tool-derived replacement

Built the 100 claimed sources with `./build.sh` (13 groups of at most 8,
all OK), regenerated `build/dl-claude.csv` with `tools/data_ledger.py
--out` and accepted a source only when every flagged address and register
key has a generated row owned by that source, status `owned`, one def.
86 sources qualified; copied their 137 complete generated rows unmodified.
These are compiler-local identities of current objects, not retail names.

Six refreshed rows shrink because the old row was a provisional blob sized
to a retired address global (0x009FD8E4 80->4, 0x009FE9CC 12->4,
0x009FED18 8->4, 0x00A03A6C 92->4, 0x00A04280 8->4, 0x00A06930 8->4). The
generator has separate rows for the uncovered addresses; they belong to
other sources and were left for their owners.

Skipped (a flagged address lacks a sole owned generated row, or the source
has duplicate-def findings): Rva00515921Permuted, Rva005F2FEFApt,
Rva007AB8D0StringInits, Rva007ABBB3CtorInits, Rva007B6880Thunks,
GameStateInit, ControlBarUpdateConstruction, InGameUISelectDrawable,
ScriptActions_rva003C31F3, ScriptConditions_Rva003EA566,
bfmedynamicvertexbuffer, boxrobj, StringBaseLockGetters,
stlport_map_int_ptr_init_002213D9. Held by other workers:
ToppleUpdatePoolKey, Rva00219B9EAccessor, AptPalantirCallbacks,
BfmeObserverDispatchYU_Rva002d4f2d, FireWeaponWhenDamagedBehaviorPoolKey,
CreateObjectDieIfEldestKindofOnDie, CreateObjectDiePoolKey,
AllowBannerSpawnUpgradePoolKey, W3DProjectileStreamDrawModule.

## Verification

- `./build.sh`: every group OK.
- `tools/data_check.py` on the 86 sources: 0 findings.
- `tools/data_check.py --all`: 1,108 findings (937 outside the register)
  versus 1,245 (1,008) at the base commit; 137 fewer, none new.
- `tools/repair_queue.py retire data SOURCE` for each source: PASS, 102
  keys retired from `reverse/data_check_baseline.txt`.
- `tools/check_csv.py`: OK.

No source, function row, pin, hatch or link claim changes.

## Sources

- `Code/GameEngine/Source/Common/Rva0030062CGet.cpp`
- `Code/GameEngine/Source/Common/Rva00300678Get.cpp`
- `Code/GameEngine/Source/Common/Rva003FEE43.cpp`
- `Code/GameEngine/Source/Common/Rva003FEECB.cpp`
- `Code/GameEngine/Source/Common/Rva003FEF80.cpp`
- `Code/GameEngine/Source/Common/Rva003FF02EPowerCap.cpp`
- `Code/GameEngine/Source/Common/Rva004A9660Delay.cpp`
- `Code/GameEngine/Source/Common/Rva0052906BUpdate.cpp`
- `Code/GameEngine/Source/Common/Rva005C7889Init.cpp`
- `Code/GameEngine/Source/Common/Rva005F632AFormat.cpp`
- `Code/GameEngine/Source/Common/Rva009F66F0.cpp`
- `Code/GameEngine/Source/Common/System/RegistryLanguage.cpp`
- `Code/GameEngine/Source/Common/System/Rva00074AFFInit.cpp`
- `Code/GameEngine/Source/Common/VersionDestructor.cpp`
- `Code/GameEngine/Source/GameClient/Drawable/Update/AnimatedParticleSysBoneClientUpdate.cpp`
- `Code/GameEngine/Source/GameClient/Drawable/Update/SwayClientUpdate.cpp`
- `Code/GameEngine/Source/GameClient/Drawable_Rva00309ffd.cpp`
- `Code/GameEngine/Source/GameClient/Drawable_Rva0030a040.cpp`
- `Code/GameEngine/Source/GameClient/FXParticleSystemDefaults.cpp`
- `Code/GameEngine/Source/GameClient/GUI/ControlBar/Rva005257F6SelectAllHeroes.cpp`
- `Code/GameEngine/Source/GameClient/GUI/GUICallbacks/GeneralsExpPoints_Rva0050dd9f.cpp`
- `Code/GameEngine/Source/GameClient/Rva0055C8BCCtor.cpp`
- `Code/GameEngine/Source/GameClient/Rva00560135Ctor.cpp`
- `Code/GameEngine/Source/GameClient/Rva005613B2Ctor.cpp`
- `Code/GameEngine/Source/GameClient/System/FXParticleSystem/Rva00561D3D.cpp`
- `Code/GameEngine/Source/GameClient/System/FXParticleSystem/Rva005635CDCtor.cpp`
- `Code/GameEngine/Source/GameClient/System/FXParticleSystem/Rva00563D2ECtor.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/CastleBehaviorPoolKey2.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/CastleMemberBehaviorFind.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ClickReactionBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/MineshaftPortalBehaviourFind.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ReplenishUnitsBehaviorUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/Rva00128780GateBehaviorResolver.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/Rva00395C80Check.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/SupplyWarehouseCripplingBehavior.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/RespawnBodyApply.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/MoneyCrateCollide.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Create/PreorderCreate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Create/SpecialPowerCreate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Create/SupplyCenterCreate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Damage/BoneFXDamage.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/CreateCrateDie.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/CrushDie.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/DestroyDie.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/KeepObjectDie.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/RebuildHoleExposeDie.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/RebuildHoleExposeDieFind.cpp`
- `Code/GameEngine/Source/GameLogic/Object/ObjectFindAttributeModifierPoolUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/ObjectFindDynamicPortalBehaviour.cpp`
- `Code/GameEngine/Source/GameLogic/Object/ObjectFindSpecialPowerCompletionDie.cpp`
- `Code/GameEngine/Source/GameLogic/Object/ObjectRva0028EBDA.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Object_Object_topple.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/SiegeDeploySpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/SpecialPowerModuleCreateViewObject.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AssaultTransportAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AutoFindHealingUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/RepairDockUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FireSpreadUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/HordeAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/RadarUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/Rva002EFB20Helper_Rva003bc27b.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/Rva00468E26Get.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/Rva00496B48Finish.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/Rva004A44B1.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/StructureCollapseUpdate.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ToggleHiddenSpecialAbilityUpdateSlots23And24.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/WallUpgradeUpdateFind.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/ExperienceScalarUpgrade.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/LocomotorSetUpgrade.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/MaxHealthUpgrade.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/StatusBitsUpgradeIfEldestKindofSlot2.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/UnpauseSpecialPowerUpgrade.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/WeaponSetUpgrade.cpp`
- `Code/GameEngine/Source/GameLogic/ScriptEngine/Rva003E4921Finish.cpp`
- `Code/GameEngine/Source/GameLogic/ScriptEngine/Rva003E4B83Siege.cpp`
- `Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptActions_rva003C30D9.cpp`
- `Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptActions_rva003C3175.cpp`
- `Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptConditions_evaluateNamedUnit.cpp`
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DDefaultDraw.cpp`
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DLaserDrawBfmeDoDraw.cpp`
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/W3DDebrisDrawPoolKey.cpp`
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/W3DHordeModelDrawPoolKey.cpp`
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/W3DScriptedModelDrawPoolKey.cpp`
- `Code/Libraries/Source/WWVegas/WW3D2/ShroudTexture_getFilter.cpp`
- `Code/Libraries/Source/WWVegas/WW3D2/particle_buffer_render_line.cpp`
