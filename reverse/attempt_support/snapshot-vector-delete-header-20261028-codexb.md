# Snapshot vector deleting destructor: canonical header adoption

Inspected base: `9d85e4da519a83ee02257126f78f13aa38d651d9`.
Scope: `Code/GameEngine/Source/Common/VectorDeletingDtorsV07.cpp` only;
no shared header, function row, pin or compiler option changes.

The previous blocked attempt at RVA 0x00001750 tried array construction of a
concrete subclass. That produced a scalar-deleting weak alias instead of the
74-byte vector deleting destructor. The existing target-project pattern in
`System/XferVectorDeletingDtor.cpp` supplies a different emission mechanism:
call `snapshot->Snapshot::__vecDelDtor(3)` from the existing non-retail anchor.
This compiler-generated member emits the actual array-capable destructor while
the canonical Snapshot remains abstract. The helper is not called by retail.
This is an emission technique, not evidence of an original retail source path.

Target evidence and object comparison:

* The rowed vector deleting destructor at 0x00001750 remains 74 bytes and has
  identical bytes and relocations (COMDAT digest `b391c630ae69`). All seven
  retained COMDATs other than the Snapshot table and non-retail helper are
  unchanged, including all three rowed bodies.
* The emitted Snapshot table grows from one slot to four. Native RVA
  0x007BB554 contains `[0x00401750, 0x0043B810, 0x0043B810, 0x0043B810]`.
  The new relocations are exactly the vector deleting destructor and three
  `__purecall` slots. Thus the canonical header restores the observed table
  shape rather than merely agreeing with another private definition.
* The new scalar deleting destructor is 29 bytes with COMDAT digest
  `4bd655b2fdee`, identical in bytes and relocations to the existing rowed
  provider in `System/LivingWorldRegionConnectionCopy.cpp` at 0x000053AF.
* Array construction no longer emits the 9-byte Snapshot constructor here.
  Its existing owner, `System/Snapshot.cpp`, retains the exact constructor.
  The helper changes signature and body; its honest absent-from-retail marker
  remains. No retail body depends on the helper.

Verification:

* `find_declared_unmatched.py` passes before and after the edit.
* `./build.sh` for V07, `System/Snapshot.cpp` and
  `System/LivingWorldRegionConnectionCopy.cpp`: 11/11 exact, including the
  associated string, float and import checks.
* `header_adopt_lane.py accept --class Snapshot` for V07 passes and retires
  its one queue entry. `hatch_counters.py --update` removes precisely its
  obsolete class-gate exception (46 to 45 overall).
* `data_check.py` on V07: zero findings.
* Ordinary link previews against index `14dc3d2467` (2026-10-28 02:44) retain
  LINKS for all three units: V07 153 -> 153, Snapshot 32 -> 32 and region
  connection copy 122 -> 122 authored bytes.

These are bounded byte and ordinary-preview checks, not a census or strict
global-link receipt. No new linked bytes are claimed; carry the table/provider
change into the next scheduled census. Other Snapshot queue entries retain
their distinct allocator-name, record-identity, derived-virtual and constructor
prerequisites recorded in LINK-098 and LINK-092.
