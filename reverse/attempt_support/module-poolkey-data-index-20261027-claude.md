# Module pool-key static data index refresh (non-Update directories)

Inspected `8fe46c5c89` on 2026-10-27. Continues
`update-poolkey-data-index-20261027-claude.md` with the same recipe over the
remaining `*PoolKey.cpp` sources outside `GameLogic/Object/Update/` and
outside GameEngineDevice: Common/System upgrades, GameClient drawable
client updates, GameLogic AI helpers and Module, and the Object Behavior,
Body, Collide, Contain, Die, SpecialPower and Upgrade directories.

## Target facts

Each source defines one cached module-name key accessor with a
function-local static key and its compiler guard `$S1`. The committed
`reverse/data_ledger.csv` named the guard after a retired
`GlobalFlagClearers_*.cpp` address global (status provisional) and, for
renamed accessors, the key and guard under the old `rva*` static spelling.

## Tool-derived replacement

After `./build.sh` of every batch source (21 groups of at most 8, all rows
matched), generated `build/dl-claude.csv` with `tools/data_ledger.py --out`
(not committed: 14 unrelated matched sources had no object). A source was
accepted only when every address data_check flags on its current object, plus
its register keys, has a generated row owned by that same source with status
`owned` and one definition; all 168 qualified. Copied only those 317
complete, unmodified rows. These are compiler-local COMDAT identities of the
current objects, not retail identifier names or `data_rows.csv` ownership.

Skipped because another worker holds the file: ModelConditionUpgradePoolKey,
FireWeaponWhenDamagedBehaviorPoolKey and AllowBannerSpawnUpgradePoolKey;
also earlier ClickReactionBehavior, CreateObjectDie and
SiegeDeploySpecialPower pool keys (consolidation claims elsewhere).

## Verification

- `./build.sh`: every group OK, all rows matched.
- `tools/data_check.py` on the batch: 0 findings after the refresh.
- `tools/data_check.py --all`: 1,251 findings (1,012 outside the register)
  versus 1,568 (1,310) at the base commit; 317 fewer, none new.
- `tools/repair_queue.py retire data SOURCE` for each source: PASS, 168 keys
  retired from `reverse/data_check_baseline.txt`, zero still found.
- `tools/check_csv.py`: OK.

No source, function row, pin, hatch or link claim changes.

## Sources

- `Code/GameEngine/Source/Common/System/ArmorUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/AttributeModifierUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/BaseUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/BuildableHeroListUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/CastleUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/CommandPointsUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/CommandSetUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/DelayedUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/DoCommandUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/ExperienceLevelCreatePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/GarrisonUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/GeometryUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/LevelUpUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/RadarUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/RemoveUpgradeUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/ReplaceSelfUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/SpellRechargeModifierUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/StatusBitsUpgradeIfEldestKindofPoolKey.cpp`
- `Code/GameEngine/Source/Common/System/StealthUpgradePoolKey.cpp`
- `Code/GameEngine/Source/Common/System/SubObjectsUpgradePoolKey.cpp`
- `Code/GameEngine/Source/GameClient/Drawable/Update/AnimationSoundClientBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameClient/Drawable/Update/EvaAnnounceClientCreatePoolKey.cpp`
- `Code/GameEngine/Source/GameClient/Drawable/Update/RadarMarkerClientUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/AI/CritterEmitterUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/AI/ObjectDefectionHelperPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/AI/ObjectGuardingHelperPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/AI/ObjectSMCHelperPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/AI/ObjectWeaponStatusHelperPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/AIUpdateInterfacePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/BridgeBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/DozerAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/GarrisonContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/OpenContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/PillageModulePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/SlowDeathBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/StructureToppleUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/WeaponChangePowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Module/WorkerAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/AimWeaponBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/AnnounceBirthAndDeathBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/AutoAbilityBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/AutoHealBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/BezierProjectileBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeScaffoldBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeTowerBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/BuildingBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/CastleBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/CastleMemberBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ClearanceTestingSlowDeathBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/DualWeaponBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/DynamicPortalBehaviourPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/EnragedBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/FakePathfindPortalBehaviourPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/FireWeaponWhenDeadBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/GateOpenAndCloseBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/GateProxyBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/GettingBuiltBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/GiantBirdSlowDeathBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/HitReactionBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/InstantDeathBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/MineshaftPortalBehaviourPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ModelConditionAudioLoopClientBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ModelConditionSoundSelectorClientBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/OathbreakersFadeAwayBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/PassiveAreaEffectBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/PhysicsBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/PropagandaTowerBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/RampageBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/RandomSoundSelectorClientBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/RebuildHoleBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ReplenishUnitsBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/RunOffMapBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ShareExperienceBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/ShipSlowDeathBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/SiegeDockingBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/SlaveWatcherBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/SpawnBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/SpawnUnitBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/StancesBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/TerrainResourceBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/TerrainResourceClientBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/UpgradeSoundSelectorClientBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/WallHubBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Behavior/WargBehaviorPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/ActiveBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/DelayedDeathBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/FreeLifeBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/ImmortalBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/OathbreakerBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/PorcupineFormationBodyModulePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/RespawnBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/StructureBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Body/SymbioticStructuresBodyPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/AODCrushCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/ShroudCrateCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/VeterancyCrateCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Collide/HealCrateCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Collide/SalvageCrateCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/AODHordeContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/CaveContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/CitadelSlaughterHordeContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/HealContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/HordeContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/HordeGarrisonContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/HordeSiegeEngineContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/HorseHordeContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/ProductionQueueHordeContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/SiegeEngineContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/SlaughterHordeContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Contain/TunnelContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/CallHelpOnDamagePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/CivilianSpawnCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/DamageFilteredCreateObjectDiePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/EvacuateDamagePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/FXListDiePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/HeroDiePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/HordeMemberCollidePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/HordeTransportContainDamagePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/HordeTransportContainPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/ReflectDamagePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/RefundDiePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/SpecialPowerCompletionDiePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Die/TransitionDamageFXPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/FiringTrackerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/ObjectRecoveryHelperPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/ObjectRepulsorHelperPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpawnedModelConditionCreatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/ActivateModuleSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/CashHackSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/CloudBreakSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/CombineHordeSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/CurseSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/DarknessSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/DefectorSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/DeflectSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/DevastateSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/DominateEnemySpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/ElvenWoodSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/EvacuateGarrisonSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/FellBeastSwoopPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/FreezingRainSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/GiveOrRestoreUpgradeSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/GrabPassengerSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/HordeDispatchSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/InvisibilitySpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/LevelGrantSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/ManTheWallsSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/OCLSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/PlayerHealSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/PlayerUpgradeSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/ProductionSpeedBonusPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/RepairSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/ScavengerSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/SiegeDeployHordeSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/SpecialPowerModulePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/SplitHordeSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/StopSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/StoreObjectsSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/TaintSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/TeleportToCasterSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/UnleashSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/SpecialPower/UntamedAllegianceSpecialPowerPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/CostModifierUpgradePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/GrantUpgradeCreatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/InheritUpgradeCreatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/LockWeaponCreatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/SupplyWarehouseCreatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Upgrade/TooltipUpgradePoolKey.cpp`
