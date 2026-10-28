# Matrix3 TU-approval handoff

Inspected base `7e8f2e0cd9`, 2026-10-28, seat codex3. No game source,
ledger row, TU map or placement rule changed.

The default picker served `Code/Libraries/Source/WWVegas/WWMath/matrix3.cpp`
with eight proposed rows. The supported planner was run with
`name_lane.py consolidate --under Code/Libraries/Source/WWVegas/WWMath/`;
its snapshot is under ignored `build/consolidation/`. The map is stale on
disk, so the supported `tu_skeleton.py --plan` rebuilt it in memory. That
plan has 50 approved rows, 17 whole-file donors and ten mixed sources.

Target facts: the proposed tail includes the string-slice copiers at
0x003FD05E and 0x003FD0CC, a constructor at 0x003FD14D, and a deleting
destructor at 0x003FD173. The approved portion includes many LivingWorldVisual
methods and the two Matrix3x3 Z-rotation rows at 0x003FBF50 and 0x003FC4C2.
The existing `matrix3.cpp` source itself owns ten Matrix3 rows at
0x007167E0..0x00717389; the planner reports a different donor-site alternative,
`Code/Tools/WW3D/pluglib/WWmatrix3.cpp`, for those rows. Source names and the
current map therefore do not independently establish this candidate's boundary.

Donor facts: the pinned Zero Hour
`Code/Libraries/Source/WWVegas/WWMath/matrix3.h` defines both
`Matrix3x3::Rotate_Z` overloads with WWINLINE at lines 851 and 856.
Its `matrix3.cpp` defines other Matrix3x3 methods. The two retail rotation
rows' current S anchors come from this class site, not from an out-of-line
definition of either rotation in that source. `tu_map.header_comdat` currently
screens header constructors and virtual methods, not these nonvirtual inline
members. Their S anchors participate in the cluster that absorbs the
LivingWorldVisual naming hints (U).

Inference / next check: a header-inline rotation's class site is insufficient
independent evidence for attributing the surrounding BFME 2 LivingWorld and
particle/string code to the donor math TU. Establish the retail containing
unit and review nonvirtual header-inline site propagation before attempting
approval of the tail or a merge of this group. This is an evidence limitation,
not a demonstrated byte or link regression. No rule change, speculative rename,
merge, source-path move or regenerated map was applied. The existing source
passes `find_declared_unmatched.py`; no new bytes or approval gain is claimed.
