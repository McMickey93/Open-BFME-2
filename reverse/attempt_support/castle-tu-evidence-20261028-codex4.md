# Castle-area TU evidence investigation

At the 2026-10-28 checkout, the TU-evidence picker selected the nine rows at
0x003970E7..0x003973EB. `tu_evidence.py --source
Code/GameEngine/Source/Common/Rva0039718BOwnedPlayerCheck.cpp` returned no
layout signal. The picker's two neighbouring naming hints point at different
CastleBehavior paths and are proposed, not independent anchors.

The target ledger describes a player-name lookup and owned-player check at
0x003970E7/0x0039718B, ObjectID range operations at 0x003971BF..0x00397357,
and a name-tree check at 0x003973EB. The WorldBuilder leads for these addresses
are placeholders or pin-only, and the checked string-xref entries contain no
file path for them. The matched ScriptConditions caller identifies a castle
context for 0x003971BF, but that alone does not prove a method name or TU.

BFME 1 has CastleBehavior-shaped code and an upgrade operation, but its
agent-assigned names and placement are donor leads, not proof of BFME 2 names
or source paths. No rename or map change was made. The next useful check is a
specific, unique same-body donor with independently supported naming, or a
retail `__FILE__` anchor; then rebuild the map in memory and check the full run.
