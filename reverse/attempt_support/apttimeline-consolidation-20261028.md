# AptTimeLine consolidation handoff (2026-10-28)

Scope: the approved AptTimeLine translation unit and its donors, including
`AptTimeLineCtor.cpp` (constructor 0x005202C8). The constructor is already
matched; the blocked work is combining its source with the timeline unit.

The earlier merge dry run rejected donor combinations with placement
`operator new[]` and `operator delete[]` redefinitions. The timeline seed's
`vector2.h` includes `always.h`, which defines these inline operators; the
constructor includes STL `<vector>`, which brings in `<new>`. Other donor
combinations also have incompatible private class views. Those view conflicts
still need individual reconciliation and verification before a merge.

A local trial included `<new>` and defined `_OPERATOR_NEW_DEFINED_` before
`vector2.h` in the seed. `./build.sh` still matched all 4 seed rows. The seed
and constructor both remained link-clean in `link_check.py` (292 and 822 bytes,
respectively), and the seed object's external symbol set and 10 COMDAT section
name/digest/size tuples were unchanged. This verifies only the seed, not a
combined translation unit. An exhaustive `tu_skeleton.py --merge ... --dry-run`
with the trial was interrupted while still checking combinations, so there is
no completed merge result or proof that this trial resolves the donor conflict.
The trial was reverted; no source or ledger paths moved. A future attempt should
first establish a narrowly scoped, independently verified composition and then
address the class-view conflicts without repeating the interrupted exhaustive
search blindly.
