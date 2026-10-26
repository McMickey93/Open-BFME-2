# ModelConditionUpgrade declaration-scan prerequisite, 2026-10-26

Allocated family A, shard 1/2 destination:
`Code/GameEngine/Source/GameLogic/Object/Upgrade/ModelConditionUpgrade.cpp`.
The Upgrade-scoped planner and its currency check pass. Current routing is
rebuilt in memory, with ten approved rows and four mixed donors. The planner
is evidence, not merge approval. No game source, ledger, register or path moves.

The earlier Luna handoff and re_attempts.log already record this false reject:
a merge lifts the trailing `// ??_7WeaponSetUpgradeModuleData@@6B@` off the
module-data constructor's extern data declaration. The frozen scanner binds
that standalone data comment to the following constructor, then rejects it
although its matched function row exists. The original donor passes because
the comment is trailing rather than a standalone annotation.

## Repair and acceptance

`find_declared_unmatched.py` now recognizes a vftable decoration (`??_7`) as
data metadata and clears the pending function annotation. It still scans the
following body and requires its matched function name. This also prevents a
vtable annotation with an unmatched/absent marker, or a vtable name present in
the declared set, from excusing an unrowed constructor. Function annotations
and all ordinary frozen-file requirements remain in place.

- The three new parser regressions fail before the repair and pass afterward.
  Two additional main-entry regressions accept the matched constructor and
  reject the unrowed constructor even when the data name is declared.
- `python3 -m pytest -q tools/tests/test_find_declared_unmatched.py
  tools/tests/test_gate_exploits.py`: 78 passed, one pre-existing open-escape
  fixture skipped by that suite; no new skip or exemption.
- A real normal `tu_skeleton.py --merge TU --dry-run` still accepts the same
  four existing files / five rows, rejecting the primary constructor's missing
  getModuleNameKey declaration. No class/vtable adjustment is attempted.
- `build/codex4-vtable-annotation-proof.py` extracts that exact emitted TU and
  narrowly filters the five current matched ledger rows into a scratch ledger.
  With identical source and rows, the old scanner exits 1 naming the constructor;
  the repaired scanner exits 0. No source rewrite or fake symbol annotation is
  involved. This demonstrates the declaration-scan unblock for those five rows,
  not a confirmed Luna merge or proof of the final composed provider set.
- Official `./build.sh` on all four existing files: 5/5 exact, two literals,
  one float literal, imports and scoped source claims pass. Frozen scans on
  all four original files pass. `check_csv.py` and diff whitespace checks pass.
  Snapshot currency agrees. Receipts are `build/codex4-modelcondition-current.txt`
  and `build/codex4-vtable-annotation-{build,proof.py,functions.csv}`.

## Binding, path and debt boundary

This commit changes only the scanner, its tests and this handoff. There is no
composition applied or published, no changed object provider, source consumer,
COMDAT selection, code/data identity, queue owner or ledger binding. The source
trial is kept in ignored build scratch. Luna must still compare actual composed
providers and consumer bindings before publishing its merge, per consolidation.md.
The primary constructor ABI/declaration blocker, mixed sources and existing
protected data debt remain. No MessageStream identity decision is made.

The complete pending range is empty before this commit; the staged change has
no source renames, moves or deletions. Active tools, hooks, workflows, includes,
build inputs and registries continue using the same scanner path. No path
consumer needs repointing, and original EA strings/history remain intact.
File reduction 0; recovered C++ bytes 0; identity/data/header debt retired 0.
The verified improvement is removing a reproduced checker false reject while
adding negative coverage for unrowed bodies.

Inherited recovery: all four prior dispatcher/seed/collector commits are already
on origin/master, so their six retained file claims were released. No inherited
source edits or preparation backups were discarded. The unrelated untracked
reverse/zh_sweep directory is preserved.

Other allocated review: LocomotorSetUpgrade's fresh normal trial still accepts
no donors because both competing class views lack getModuleNameKey. Its private
multi-interface layouts require coherent ABI evidence; no declaration-only fix,
claim, source edit or repeated experiment was made. The existing handoff stands.

Keep scanner/test/handoff file claims until this tooling commit lands, then
release them. No function/RVA claim or downstream landing is claimed here.
