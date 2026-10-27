# AutoAbilityQueryEntry TU approval

Inspected `7ed44e8ffd` on 2026-10-27. The default picker claimed
`file:Code/GameEngine/Source/GameLogic/Object/Behavior/AutoAbilityQueryEntry.cpp`:
eight proposed rows in six sources, six classified as brackets and two as
unanchored. This destination does not exist; no source was edited or moved.

The supported planner was run with
`python3 tools/name_lane.py consolidate --under Code/GameEngine/Source/GameLogic/Object/Behavior/`.
Its subsequent `--check build/consolidation` passed. The current-input
`tu_skeleton.py --plan` for the proposed destination reports **0 approved rows,
0 donor files, 0 mixed files, 0 refused files**. The committed map is stale;
the plan rebuilds its routing in memory, without writing the map.

Target facts: the existing 18-byte init at RVA `0x0045A1D9` and eight-byte
destructor at `0x0045A226` are already matched C++ in
AutoAbilityQueryEntryInit.cpp and AutoAbilityBehaviorModuleDataDtor.cpp.
The latter also owns the module-data destructor and its EH rows, so it is
not an independently movable query-entry file. Their planner packets mark
the query-entry bodies unresolved, with no target path or alternative.
The other four proposed addresses `0x0045A203`, `0x0045A20A`, `0x0045A211`
and `0x0045A21F` are already rowed getters in shared sweep sources. The
interleaved `0x0045A218` is already rowed as RingRenderObjClass::Get_Name;
that short body's existing placement does not prove a query-entry identity.

Original-path evidence: the catalogue records
`Code/GameEngine/Source/GameLogic/Object/Behavior/AutoAbilityBehavior.cpp`
from WorldBuilder at image offset/RVA `0x01AD57D8`, with no retail path or
Zero Hour counterpart. The BFME 1 counterpart is path-existence evidence,
not a BFME 2 routing witness. The module-data destructor has only a stale-map
N hint for AutoAbilityBehavior.cpp. No catalogue path establishes a separate
AutoAbilityQueryEntry.cpp. The current WorldBuilder lead table contains no
query-entry pairing; module-data/behavior name leads cannot anchor these
query-entry rows by adjacency.

Blocked on an independent, supported routing witness for the bracket owners.
Naming and address order alone cannot approve this TU. Resume after admissible
target path evidence or a validated structural signal supplies that witness;
rebuild the plan before any merge. No name, pin, ledger, map, register or source
change is justified by this investigation. No byte or linking gain is claimed.
