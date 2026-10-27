# Consolidation shard 1 trial — 2026-10-27

Allocated TU: `Code/Libraries/Source/Apt/AptObject/AptScriptColour.cpp` (queue check passed). The current planner snapshot passed `--check`.

`tu_skeleton.py --merge ... --dry-run` accepted no donors and blocked because no verified merge of two or more donors was possible. `Rva006F2C50Siblings.cpp` was rejected with `compile: ...AptScriptColour...tu_skeleton.cpp(121) : error C2039: 'DestroyGCPointers' : is not a member of 'AptObject'` (same C2039 diagnostic repeated). Leave this for a source/header repair.

Inspected all three mixed-file paths shown by the plan:

- `AptFactoryConstructors.cpp`: split blocked because a copied helper carries an escape hatch and would grow its count (hatch_counters rule 3).
- `Rva006D6470Derived.cpp`: split blocked by SplitLinkGuard; moved selected COMDATs `??1Rva006F25D0@@UAE@XZ` and `??_7Rva006F25D0@@6B@` lack matching private/weak-free context.
- `BfmeConv1082.cpp`: split dry run accepted one carved row and moved four data globals, but leaves an unapproved residual row and removes no source file; no merge was unblocked by this trial, so it was not applied.

No TU, source, ledger or hatch files were changed by these trials. This candidate is handed to Sol for the declaration prerequisite and to a future consolidation seat only if its blockers change.
