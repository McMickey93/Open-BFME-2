StatusBitsUpgrade consolidation handoff, 2026-10-26

`python3 tools/tu_skeleton.py --merge Code/GameEngine/Source/GameLogic/Object/Upgrade/StatusBitsUpgrade.cpp --dry-run` accepted `StatusBitsUpgradePoolKey.cpp` and `StatusBitsUpgradeUpgradeImplementation.cpp`. It rejected `StatusBitsUpgradeConstructor.cpp`: C2511, `StatusBitsUpgrade::StatusBitsUpgrade(Thing *,const ModuleData *)` overloaded member function not found in `StatusBitsUpgrade`.

The accepted merge built byte-exact (4/4 rows), but `data_check.py --staged` reported two new shadow wrong-name findings at 0x00A03E24 and 0x00A03E28 for the merged pool-key function's local static and guard. The converged check still reported 10 addresses, 0 second names and 0 unjudged rows; code identity reported 0 new findings. Since the new shadow data findings need owner reconciliation, the trial was restored and all destination, donor and RVA claims were released. Do not retry the unchanged composition before Sol resolves those findings.
