# Object/Update pool-key static data index refresh

Inspected `9fe8d7a9af` on 2026-10-27. The data queue served
`MonitorConditionUpdatePoolKey.cpp` (key at RVA `0x00A039C0`); the same
stale-index shape covers 91 `Code/GameEngine/Source/GameLogic/Object/Update/`
`*PoolKey.cpp` sources, repaired here as one homogeneous batch.

## Target facts

Each source defines one cached module-name key accessor
(`getModuleNameKey`, or a not-yet-renamed `rva*` static) with a
function-local static key and its compiler guard `$S1`. The committed
`reverse/data_ledger.csv` still named the guard after a retired
`GlobalFlagClearers_E03xxx.cpp` address global (`?g_Va00E03xxx@@3IA`,
status provisional), and in renamed sources also spelled the key and guard
under the pre-rename `rva*` static function. data_check therefore reported
one or two wrong-name findings per source against the stale index.

## Tool-derived replacement

After `./build.sh` of every batch source (all rows matched, 12 groups of at
most 8), generated a separate index with
`python3 tools/data_ledger.py --out build/dl-claude.csv` (9 unrelated matched
sources had no object, so the whole output is not committed). For each
source, took the addresses data_check flags on its current object plus its
register keys, and accepted the source only when every such address has a
generated row owned by that same source with status `owned` and one
definition. Copied only those complete, unmodified generated rows (169 rows)
into `reverse/data_ledger.csv`; every other line is unchanged. These are
compiler-local COMDAT identities of the current objects, not claims about
retail identifier names or `data_rows.csv` ownership.

`HordeAIUpdatePoolKey.cpp` has the same shape but another worker holds its
claim; it was left untouched.

## Verification

- `./build.sh`: every group OK, all rows matched (277 rows across 91 sources, 12 groups).
- `tools/data_check.py` on the batch: 0 findings after the refresh.
- `tools/data_check.py --all`: 1,568 findings (1,310 outside the register)
  versus 1,737 (1,464) at the base commit; 169 fewer, none new.
- `tools/repair_queue.py retire data SOURCE` for each source: PASS, 92 keys
  retired from `reverse/data_check_baseline.txt`, zero still found.
- `tools/check_csv.py`: OK, row counts unchanged.

No source, function row, pin, hatch or link claim changes.

## Sources

- `Code/GameEngine/Source/GameLogic/Object/Update/AIGateUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AISpecialPowerUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate/WanderAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AnimalAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ArrowStormUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AssistedTargetingUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AttachUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AttributeModifierAuraUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AttributeModifierPoolUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AudioLoopUpgradePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/AutoPickUpUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/BannerCarrierUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/BloodthirstyUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/BoneFXDamagePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/BoneFXUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/BoredUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/BroadcastStealthUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/CivilianSpawnUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DamageFieldUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DefaultProductionExitUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DelayedLuaEventUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DelayedWeaponSetUpgradeUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DeletionUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DeployStyleAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DestroyEnvironmentUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/DynamicShroudClearingRangeUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/EmotionTrackerUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/EntEnragedUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FadeAndDieOrnamentUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FireSpreadUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FireWeaponUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FlammableUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FlingPassengerSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FloatUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FloodUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/FoundationAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/GiantBirdAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/GiveUpgradeUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/GloriousChargeUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/HeightDieUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/HeroModeSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/HijackerUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/HordeNotifyTargetsOfImminentProbableCrushingUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/HordeWorkerAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/InvisibilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/LargeGroupAudioUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/LargeGroupBonusUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/LaserUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/MissileUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ModelConditionSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/MonitorConditionUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/MonsterDockUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/NotifyTargetsOfImminentProbableCrushingUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/OilSpillUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/OneRingPenaltyUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/PartTheHeavensUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/PickupStuffUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ProductionUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ProjectileStreamUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/QueueProductionExitUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/RadiateFearUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/RainOfFireUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ReplaceObjectUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/RespawnUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/RousingSpeechUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/RubbleRiseUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ScaleWallSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SiegeAIUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SlavedUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SpawnPointProductionExitUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SpecialDisguiseUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SpecialEnemySenseUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SpecialPowerTimerRefreshPoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/StealthUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/StrafeAreaUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/StructureCollapseUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SupplyCenterDockUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SupplyCenterProductionExitUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/SupplyWarehouseDockUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/TeleportSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/TemporarilyDefectUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ThreatFinderUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ToggleDeploySpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ToggleHiddenSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/ToggleMountedSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/WallUpgradeUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/WeaponFireSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/WeaponModeSpecialPowerUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/WeaponSetSpecialAbilityUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/WoundArrowUpdatePoolKey.cpp`
