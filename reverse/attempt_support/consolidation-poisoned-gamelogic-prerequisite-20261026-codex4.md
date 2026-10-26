# PoisonedBehavior GameLogic prerequisite, 2026-10-26

Allocated family A, shard 1/2 destination:
`Code/GameEngine/Source/GameLogic/Object/Behavior/PoisonedBehavior.cpp`.
The Behavior-scoped planner was read before editing. Current routing approves
17 rows, with three mixed donors retained. No merge, split or path move applied.

## Verified prerequisite

`PoisonedBehaviorUpdate.cpp` now includes the registered native
`Common/GameLogicObjectLookupView.h` instead of declaring a private GameLogic
body. Its two frame reads use the canonical const getFrame accessor. The old
TU-specific accessor emitted the same four bytes, `8b 41 40 c3`, reading +0x40.
The canonical header and all other consumers are unchanged.

- Before and after `./build.sh .../PoisonedBehaviorUpdate.cpp`: 4/4 exact,
  322 retail bytes retained; string, float, import and scoped claim checks pass.
- `header_adopt_lane.py accept --class GameLogic SOURCE`: PASS; retired exactly
  one row through the queue's acceptance path.
- `find_declared_unmatched.py SOURCE`: all defined functions already matched.
- `allowed_symbols.py --source SOURCE`: ten references, nine owner and one fold,
  zero wrong bindings. `data_check.py SOURCE`: zero findings.
- `link_check.py SOURCE`: LINKS, predicts 322 -> 322 linked bytes. This is a
  scoped prediction, not a new census or a claimed linked-byte increase.
- Before/after normal `tu_skeleton.py --merge TU --dry-run`: the GameLogic
  `adopt_first` finding disappears for the four-row update donor. Accepted
  donors remain zero: UpdateModuleInterface is undefined in composition and
  the seed lacks update; pool/key lacks getModuleNameKey, and Xfer lacks xfer.
  Their virtual layouts need coherent evidence, not extra declarations.

## Provider and identity comparison

Saved the verified pre-edit object in ignored build scratch. The upstream
`allowed_symbols._object_defs` and `link_census._comdat_sections` readers compare
it with the normally rebuilt object. All nine common code definitions,
undefined external references, and every common code/data COMDAT retain their
digests. The only definition change replaces the private frame helper with the
canonical getter; both have digest 84449fef877c, size four, nonexclusive.

The published census index (2026-10-26 13:18, d1f046749a) has no reference-graph
edge targeting the removed helper. All 394 existing canonical getter copies
have the same digest. A scoped overlay with the current object retains the
selected canonical getter provider, FiringTrackerXfer.obj. The four row bodies
retain every relocation binding; no affected row consumer needs a change.
This records scoped evidence against the recorded index, not whole-tree input
freshness or a final composed-TU selection proof. Receipts:
`build/codex4-poisoned-{before-build,after-build,bindings,identity,data,link}.txt`
and `build/codex4-poisoned-{current,after-dryrun}.txt`.

There are no existing code-identity keys for this source and none retired.
Data/code identity registers remain unchanged. Header debt retired: one.
File reduction: zero. Recovered C++ bytes: zero. No downstream Luna landing is
claimed; only the canonical-header prerequisite for four rows is cleared.

## Publication and audit

The entire pending range, including the earlier scanner repair and this staged
source/header-queue change, has no source move, rename or deletion. Active
tools, hooks, workflows, includes, build inputs and registries keep their paths;
no path consumer needs repointing. Historical EA strings remain intact.
The original helper's only source references were local and are replaced here.
The header queue row is removed only by accept; other debt is preserved.

Keep the source, header-queue and this handoff's file claims until publication
is confirmed. If publishing is held, the runner's next session should release
them after landing, along with the earlier scanner/test/handoff claims. No RVA
claims were acquired. The unrelated reverse/zh_sweep directory is preserved.
