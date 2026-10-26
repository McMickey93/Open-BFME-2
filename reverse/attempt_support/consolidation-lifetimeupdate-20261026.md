# LifetimeUpdate consolidation handoff (2026-10-26)

The shard 0/5 allocator approved `Code/GameEngine/Source/GameLogic/Object/Update/LifetimeUpdate.cpp`. The scoped `name_lane.py consolidate` report passed `--check` before the merge trial.

`tu_skeleton.py --merge .../LifetimeUpdate.cpp --dry-run` accepted the seed and two unchanged donors: `LifetimeUpdateCalcSleepDelay.cpp` and `LifetimeUpdateModuleDataConstructor.cpp`. The applied merge moved six matched rows and removed those two source files. `./build.sh .../LifetimeUpdate.cpp` passed all 6/6 rows, source claims, string references and other byte checks; `find_declared_unmatched.py` reported all definitions already matched.

Rejected donors remain for Sol to reconcile; no rejected donor was changed:

- `LifetimeUpdatePoolKey.cpp`: `C2039: 'getModuleNameKey' is not a member of 'LifetimeUpdate'`; the compiler also reported `C2270` for the method definition.
- `Rva003A49D1Xfer.cpp`: `C2504: 'UpdateModule' : base class undefined` and `C3861: 'setWakeFrame': identifier not found`.
- `LifetimeUpdateCtor.cpp`: `C2504: 'UpdateModule' : base class undefined` and `C3861: 'setWakeFrame': identifier not found`.

The three mixed donors (`GlobalFlagClearers_E028xx.cpp`, `Rva0024A797Derived.cpp`, and `ModuleDataBuildFieldParse.cpp`) remain untouched. The pool-key and class/header prerequisites need a Sol pass before retrying those rows.

Identity and data checks remain shadow findings, not cleanup: `code_identity_gate.py --staged` reported the `_vtbl_00C4ED70` alternatename in the merged TU; `data_check.py --staged` reported its existing `wrong-name` finding at `0x0084ED70`. The alternatename and reference already existed verbatim in the old constructor donor, and `reverse/data_ledger.csv` already contains that address. No identity or data register key changed. Sol owns any repair or retirement.

The merge tool carried the donor hatch keys with totals kept. Tooling/path search found no active consumers of the two absorbed source paths; the only source mentions are generated provenance comments and the compiler-significant original `__FILE__` literal. Provider/consumer and selected-COMDAT results remain pending the required pre-push `link_batch_audit.py` report.
