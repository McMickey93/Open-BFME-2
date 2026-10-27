# UpgradeDie local storage index repair

Inspected at `e1a73387fd`, 2026-10-27, seat codexb.

The data queue served the historical guard spelling at RVA `0x00A03898`.
The first supported retirement refused: the current getter emits both its key
and guard under `getModuleNameKey`, while the index retains `rva000486B75`
and the former external `g_Va00E03898`. This is existing data-identity cleanup.

Commit `d43852c029` renamed the getter. Commit `e44def7a6f` removed the separate
guard definition and rowed its rollback under the parent's exact EH graph.
`GlobalFlagClearers_E038xx.cpp` now defines only `g_Va00E038C4`; source search
finds no remaining E03898 global or old getter spelling in Code.

`python3 tools/data_ledger.py --out build/codexb-data-ledger-20261027.csv`
generates 34,367 addresses and reports five sources without objects. Copy only
its exact generated rows for `0x00A03894` and `0x00A03898` into the index;
unrelated inventory is preserved. Both rows are four-byte owned globals in
UpgradeDie.cpp, with one definition each and respectively two and four
references. The guard is the compiler's TU-local static, not an external alias.
No source, function row, pin, data ownership row or converged name is changed.

Validation:

- `./build.sh Code/GameEngine/Source/GameLogic/Object/Die/UpgradeDie.cpp`:
  all four rows and its literal pass.
- `eh_verify.py`: one EXACT graph, including the rowed guard rollback.
- `data_check.py`: zero findings. `data_check.py --converged` passes.
- `repair_queue.py retire data Code/GameEngine/Source/GameLogic/Object/Die/UpgradeDie.cpp`:
  PASS, one registered key retired, zero remaining. The initial refusal changed
  nothing; only this successful tool call removes the baseline key.
- Ordinary `link_check.py`, index `bf3dd31211`, 2026-10-27 00:39,
  retail-truth-4: LINKS, 120 -> 120 authored bytes. No census gain claimed.
- `check_csv.py` and `git diff --check` pass.

The unchanged UpgradeDie object SHA-256 is
`e1b503f672b0bf4d2f6b71175b6e453dbaab7e7823f16cfaa7d32584a50f4785`.

An earlier default draw served GameEngineExecuteRva0022D290.cpp's historical
thread-wrapper blocker. Current-object preview with BfmeDfe6e4_rva00225492.cpp
already gives LINKS for both (1,395 and 78 authored bytes). The execute unit's
five rows pass `./build.sh`. This verifies the existing LINK-106 repair;
no new source change or census gain is attributed to this check.
