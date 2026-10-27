# StringBase lock data ownership

Inspected `9fef84f164` on 2026-10-27 under the picker's file claim for
`Code/Libraries/Source/WWVegas/WWLib/StringBaseLockGetters.cpp`.

`find_declared_unmatched.py` is clean. `./build.sh` passes all six rows,
including both EH handlers and guard-rollback funclets. The owning
`repair_queue.py retire data` check retains all four registered findings.

The getters construct function-local `Rva00041004 obj(1)` objects at retail
RVAs 0x009E0828 and 0x009E0850. Their source and header describe 36-byte lock
objects and guards at 0x009E084C and 0x009E0874. The data index instead names
four address-derived unsigned globals. `Rva007B6880Thunks.cpp` defines the
first two as four-byte unsigned objects, and its cleanup bodies at 0x007B6A90
and 0x007B6A80 use those separate objects as destructor receivers. These
definitions are backed by explicit data rows; changing only the data index
would leave the duplicate storage unresolved.

The next repair needs the compiler-emitted local-static cleanup ownership,
the existing thunk rows and the explicit data owners reconciled together.
Preserve the getter's guarded initialization, atexit registration and rollback
EH graph. Replacing the local static with an external unsigned does not model
that lifetime. No alias, new baseline entry, source edit or retirement was
made in this pass.

The official BFME 1 fetch found upstream a0940f921 beyond the verified
4fa9d591 pointer. The reference file claim is held by yasinschroeder-codex;
the verified inputs were retained and the freshness marker was not advanced.
