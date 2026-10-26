# TunnelTracker consolidation handoff (2026-10-26)

The allocated `Code/GameEngine/Source/Common/RTS/TunnelTracker.cpp` merge trial
was discarded before commit. The unchanged dry run accepted the destination plus
three donors and 12 rows, but the path-consumer audit found active
`reverse/name_basis.csv` entries 524 and 525 still assigning moved rows to
`Code/GameEngine/Source/Common/Thing/TunnelTracker_isValidContainerFor.cpp`
and `Code/GameEngine/Source/Common/Thing/TunnelTracker.cpp`. This mechanical
lane cannot repair that path-keyed registry. The trial was restored and all 16
file/RVA claims were released.

The merge dry run rejected these unchanged donors; a Sol pass must resolve the
declaration/layout prerequisites before retrying:

- `TunnelTrackerCtorBfme.cpp`: C2600, cannot define compiler-generated
  `TunnelTracker::TunnelTracker` because it was not declared in the class.
- `TunnelTrackerDtor.cpp`: C2600, same issue for `TunnelTracker::~TunnelTracker`.
- `Rva004F56FCAdd.cpp`: C2664, `list::push_back` cannot convert `int` to
  `const ObjectID &`.
- `Rva004F571BReplaceContainedOwner.cpp`: C2039, `tunnelContainer` and
  `onContainedBy` are not members of `Object`.
- `TunnelTrackerXfer.cpp`: C2039, `xfer` is not a member of `TunnelTracker`;
  C2065, `m_tunnelIDs` is undeclared.
- `TunnelTrackerLoadPostProcess.cpp`: C2039, `loadPostProcess` is not a member
  of `TunnelTracker`; C2065, `m_containList` is undeclared.
- `TunnelTrackerDeleter.cpp`: C2511, `TunnelTracker(EmitVtableTag *)` is not a
  member overload declared in `TunnelTracker`.

Trial checks before restoration: `./build.sh TunnelTracker.cpp` passed 12/12
matched rows; `find_declared_unmatched.py` passed; `code_identity_gate.py
--staged` reported one shadow finding (`Object::getBodyModule` definition
divergent); `data_check.py --staged` reported no findings; ownership, class and
staged link checks did not refuse the composition. No identity debt was retired.
