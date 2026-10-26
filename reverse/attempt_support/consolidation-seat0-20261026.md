# Mechanical consolidation allocation handoff, 2026-10-26

Shard 0/5 was exhausted against the current allocation. The full read-only
listing (`consolidation_queue.py --limit 100000`) contained 36 destinations;
the first 20 were reviewed earlier this session against allocation checks,
current plans, and existing handoffs. No unchanged trial in the remaining
eligible tail produced a merge of two or more donors.

Additional current dry runs:

- `LoadScreen.cpp`: allocation and scoped planner currency checks passed. The
  23-row plan has two mixed donors. The unchanged merge accepts none. Three
  ordinary donors fail because `TheDisplay`, `TheWindowManager`, or
  `TheDisplayStringManager` declarations are unavailable in the destination;
  another fails because `_STL::list` was already explicitly instantiated.
  This requires Sol declaration/template reconciliation.
- `Credits.cpp`: allocation and scoped planner currency checks passed. The
  16-row plan has two mixed donors. The unchanged merge accepts none.
  `Rva005B72E7Dtor.cpp` fails because `TheDisplayStringManager` is unavailable;
  `Rva005B7DC3Box.cpp` fails with C2908/C2766 because `_STL::list` has already
  been instantiated/specialized. This requires Sol declaration/template
  reconciliation.
- `AptValueGCAllocator.cpp`: allocation passed, but the current dry run repeats
  the existing blocker: duplicate `Rva006D2A60::isAllocated(int)` and
  undeclared `mValueBitfield` in the generated TU. No retry or changes.
- `Win32DIKeyboard.cpp` and `WWLib/thread.cpp`: existing handoffs already
  record the unchanged `m_table` interface mismatch and `_beginthreadex`
  declaration blocker, respectively. No retry or changes.

Earlier in this allocation, a temporary `ModelConditionUpgrade.cpp` merge
passed its 5-row byte build but introduced two shadow wrong-name findings at
`0x00A03EC8` and one code-identity alternatename finding for
`_vtbl_00BF2558=??_7WeaponSetUpgradeModuleData@@`. The trial was fully restored;
these findings are a Sol reconciliation prerequisite, not a completed merge.

No claims remain from these dry runs. The pre-existing ShipSlowDeathBehavior
commit and its publication claims are preserved. No source or ledger change is
claimed by this handoff.
