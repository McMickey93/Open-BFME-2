# String-record TU approval boundary

Inspected BFME 2 `715e03219f` on 2026-10-28. The default picker served
`Code/GameEngine/Source/Common/BfmeStringRecord00448113.cpp` as an unanchored
TU-approval candidate. This is a proposed destination, not an existing source.

## Target facts

- The existing 61-byte copy constructor at RVA `0x00448113` belongs to
  `StringRecordInlineCopyBFME2.cpp`, alongside its placement-copy wrapper
  `0x00448D0F` and compiler-emitted EH rows. No lost row was found.
- Its current declaration contains two `UnicodeString` members. The separate
  comparator at `0x00448D3C` compares the first string; the tree helpers use
  this placeholder record. These facts establish operations, not an
  application class name.
- The committed TU map routes the constructor by naming hint `N` only, with
  status `proposed`. A fresh `tu_skeleton.py --plan` for the suggested
  destination reports zero approved rows and zero donors.
- `find_declared_unmatched.py` on the actual owner reports 116 matched rows
  and no unmatched defined functions.

## Donor facts and remaining prerequisite

The planner (`name_lane.py consolidate --under Code/GameEngine/Source/Common/`)
groups related sources near LANGameInfo but explicitly reports
`placement-needs-target-corroboration` and mixed routing for the actual owner.
The WorldBuilder lead at `0x00448352` names `LANGameInfo::setSlot`; there is no
lead at this constructor. Zero Hour's `LANGameInfo.h` does not name this
two-string record. Neither nearby placement nor equal string layout proves
the constructor's application identity or translation unit.

No source, name, row, TU approval or map change was made. Resume with independent
target evidence identifying the record or its original TU; then use the guarded
naming/approval tools and verify all affected providers and consumers. Do not
move this row using the proposed path or infer a canonical name from adjacency.
