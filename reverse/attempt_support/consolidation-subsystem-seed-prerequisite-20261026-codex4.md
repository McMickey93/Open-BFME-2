# SubsystemInterface seed include prerequisite, 2026-10-26 (codex4)

Allocated target: `Code/GameEngine/Source/Common/System/SubsystemInterface.cpp`
(family A, codex4 half). The destination and this handoff are claimed. This is
a source prerequisite, not a merge, class ABI recovery or new matched body.

The seed included PreRTS, the reference SubsystemInterface and Xfer although
its rowed bodies use independent local views. Their transitive graph supplied
a second AsciiString and blocked every pair in the inherited merge trial.
Replace those unused includes with the same `_STLP_USE_NEWALLOC` setting and
the list method declaration actually defined here. Compiler flags, existing
views, row bodies, source paths and ledgers are unchanged.

## Acceptance and binding evidence

- Normal `./build.sh` before and after: all three seed rows exact. No manual
  compilation was used; saved old object is
  `build/codex4-subsystem-seed-before.obj`.
- `find_declared_unmatched.py`, `class_gate.py`, `check_csv.py` pass.
  `allowed_symbols.py --source`: 3 references, all owned, zero wrong owners.
  `data_check.py --converged`: 10 addresses, zero second symbols or unjudged
  bindings. `eh_verify.py`: no EH rows or missing bodies.
- Scoped snapshots `build/codex4-subsystem-seed-{before,after}.json` use
  upstream allowed_symbols and data_check object readers. The supplementary
  `build/codex4-subsystem-seed-proof.py`/`.txt` compares the saved original
  object with the normal rebuilt object using `allowed_symbols.Obj`, digest,
  `_object_defs` and `link_census._comdat_selections`: all 24 surviving external
  code definitions have identical bytes, relocation identities, sizes,
  exclusivity and actual selection modes. Undefined references are identical.
- Removed emission consists of the unreferenced array-constructor helper,
  538 external header constants and three static frame-rate constants. None
  has a relocation targeting it anywhere in the original object; the strict
  current object inventory reports no undefined consumers for the removed
  external definitions. The helper still has 905 other copies; the selected
  definition remains the ATL vector-constructor iterator. No surviving data
  definition changes. Thus no runtime provider/consumer binding changes in
  this standalone prerequisite. These are scoped facts, not a new census.
- The five accepted donors were also normally rebuilt: 13/13 rows exact.
  No consumer needs recompilation for an altered runtime binding here.

## Demonstrated unblock and composition boundary

`tu_skeleton.py --plan` uses current routing (34 approved rows). The inherited
trial `build/codex4-subsystem-after-trial.txt` accepted no pair. The new
`build/codex4-subsystem-seed-after-trial.txt` accepts the seed and five donors:
SubsystemInterfaceListDtor, Rva001B4EABExport, Rva001B4E21Get, Rva001B4F8B and
SubsystemInterfaceList: 16 rows / 712 retail bytes in total (including the
three seed rows / 180 bytes). This clears their compile prerequisite. This is not a
Luna landing or permission to publish that composition.

An explicit donor-union/composed-object comparison using
`build/codex4-composition-evidence.py` detected added/dropped STL template
providers and a changed SubsystemInterfaceList constructor. Its report is
`build/codex4-subsystem-seed-composition.txt`. Byte checks alone do not verify
those bindings. Leave the merge unapplied until those changes are explained
against provider/consumer evidence; this prerequisite itself changes none.

Other rejected donors remain behind: loadIniFiles has duplicate placement
new[] via GameMemory; the collector needs ModuleData declaration ordering;
reset/add donors need compatible list-method declarations. Two mixed sources
require supported split/routing review. No manual merge or split was made.
No generated TU map, protected register or identity key was changed/retired.
File reduction 0; recovered C++ bytes 0; debt retirement 0 for this commit.
The inherited dispatcher commit separately retires two header-queue rows.

## Planner and publication audit

Reviewed Common planner original-path evidence, alternatives and prerequisites;
regenerated after the source change. `name_lane.py consolidate --check
build/consolidation` passes. Its report is evidence, not routing approval.
Current census index fetched by `link_check.py --fetch-index`: d1f046749a,
2026-10-26 13:18. No maintainer-only cycle, smoke or nightly was run.

Before committing, reviewed `origin/master..HEAD` plus this edit. The two
outgoing commits are inherited dispatcher repair and its recovery receipt;
three intervening upstream commits touch unrelated lookup-table/attempt files.
No outgoing source paths move, so no include, registry, tool, hook, workflow or
build consumer needs repointing. Combined basename/path search of active tools,
hooks, workflows and header/identity/data registers found no affected consumer.
Historical EA paths are retained. The changed source and this handoff are the
only new staged paths; unrelated untracked reverse/zh_sweep is preserved.
Retain the five file claims until the publisher confirms the batch landed.
