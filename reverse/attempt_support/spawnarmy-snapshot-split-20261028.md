# SpawnArmy snapshot split trial

At `a6d64019bb`, the current TU map assigns seven rows of
`Code/GameEngine/Source/Common/Rva004E179ADtor.cpp` to the approved
`Code/Libraries/Source/WWVegas/WWLib/SpawnArmy.cpp`; one row remains without
an approved TU. The destination did not yet exist. The supported split dry run
carved definitions at 0x004E1794 and 0x004E179A, carrying seven rows; it
reported 7/7 exact in isolation under the destination flags and one residual
row. No data or hatch moved.

The split link guard rejected the candidate: the moved selected COMDAT
`??_7Rva004E179A@@6B@` lacks matching private/weak-free context. No split was
applied. The existing [snapshot proof](spawn-building-snapshot-link-20261020/readme.md)
describes the native table and earlier provider binding reconciliation; it
does not by itself establish the split guard's required context. Inspect the
table's object relocations and weak bindings in both resulting objects and the
selected consumer context before retrying; do not bypass the guard.

The whole-TU merge dry run from the preceding session was interrupted during
composition trials after more than 15 minutes, without a donor verdict. It is
not evidence of an accepted or rejected full merge. No source-file, linked-byte
or census gain is claimed.
