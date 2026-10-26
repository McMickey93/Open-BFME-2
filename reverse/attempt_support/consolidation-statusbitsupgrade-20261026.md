# StatusBitsUpgrade consolidation handoff (2026-10-26)

The shard 0/5 allocator approved `Code/GameEngine/Source/GameLogic/Object/Upgrade/StatusBitsUpgrade.cpp`. The scoped `name_lane.py consolidate` snapshot passed `--check` before the trial.

`tu_skeleton.py --merge .../StatusBitsUpgrade.cpp --dry-run` accepted two unchanged donors, `StatusBitsUpgradePoolKey.cpp` and `StatusBitsUpgradeUpgradeImplementation.cpp`. The applied merge moved four matched rows and removed those two files. The tool carried one data-check key and two data-ledger entries by transfer; no key was retired. `./build.sh .../StatusBitsUpgrade.cpp` passed 4/4 rows, source claims, string references and byte checks; `find_declared_unmatched.py` reported all definitions already matched. `tu_ownership.py --staged` passed; `code_identity_gate.py --staged` reported zero new findings.

The unchanged constructor donor remains blocked for Sol: `StatusBitsUpgradeConstructor.cpp` reports `C2511: 'StatusBitsUpgrade::StatusBitsUpgrade(Thing *,const ModuleData *)' : overloaded member function not found in 'StatusBitsUpgrade'`. The three mixed donors remain untouched.

`data_check.py --staged` reports two shadow `wrong-name` findings for the function-local pool key globals at `0x00A03E28` and `0x00A03E24`. They were already defined by the absorbed pool-key donor; keep them for Sol's data-identity lane. Do not retire the transferred data key on this merge.

The path consumer search found no active tooling or build references to the two absorbed source paths. `reverse/link_status.csv` keeps its last-census rows under the old paths; this lane preserves that measurement snapshot and does not run or edit a census. The source comment in `SubObjectsUpgradePoolKey.cpp` is a historical recipe reference. Provider/consumer and selected-COMDAT results remain pending the required pre-push `link_batch_audit.py` report.
