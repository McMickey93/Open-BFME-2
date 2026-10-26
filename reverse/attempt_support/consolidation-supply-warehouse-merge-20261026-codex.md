# SupplyWarehouseCripplingBehavior TU consolidation — 2026-10-26

Mechanical merge of the two unchanged donors accepted by `tu_skeleton.py` into the approved `SupplyWarehouseCripplingBehavior.cpp` TU. The merge preserved three matched rows and removed two source files. No identity debt is claimed retired by the merge.

## Verification

- Allocator `--check-tu`: approved; plan had 4 rows, 3 donors and one mixed source.
- `tu_skeleton.py --merge ... --dry-run`: accepted `SupplyWarehouseCripplingBehaviorPoolKey.cpp` and `SupplyWarehouseCripplingBehaviorModuleDataCtor.cpp`; retained `ModuleDataBuildFieldParse.cpp` as mixed. Rejected `Update/SupplyWarehouseCripplingBehaviorCtor.cpp` at compile with C2039: `getModuleNameKey` is not a member of `SupplyWarehouseCripplingBehavior`.
- `./build.sh Code/GameEngine/Source/GameLogic/Object/Behavior/SupplyWarehouseCripplingBehavior.cpp`: 3/3 matched functions, byte/string/float/import verification passed.
- `find_declared_unmatched.py` and `check_csv.py`: passed.
- `allowed_symbols.py --source ...`: 4 references; 0 wrong bindings.
- `data_check.py --staged`: three shadow wrong-name findings (two function-local names and `_vtbl_00C4ED70`); preserve for Sol, do not claim cleanup.
- `code_identity_gate.py --staged`: one shadow unreferenced alternate-name finding (`_vtbl_00C4ED70`); preserve for Sol.
- Tooling compatibility search over both the pending Science merge and this merge found no active references to the absorbed donor filenames in `tools/`, `.githooks/`, `.github/` or `Code/`. Historical source-path references remain in ledgers and handoffs.
- Provider/consumer comparison remains subject to the outgoing batch's `link_batch_audit.py` after commit; no census gain is claimed.

## Remaining prerequisites

The rejected constructor donor needs a declaration repair for `getModuleNameKey` by Sol before another dry run. The mixed parse donor is untouched. The data and code-identity findings above remain open; the merge itself did not retire them.
