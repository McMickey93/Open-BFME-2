# BFME 1 reference freshness: native comparison, 2026-10-27

The prior verified BFME 1 pointer is `e74410b3738a2bb75d626085d9ebfd3406a43ff7`.
The reviewed upstream pointer is `eb60756a8aa6ba1648edd234b16bcc778fcbbe7b`.
The full old/new comparison uses one fixed BFME 2 revision; publication rebases and runs the normal gates again.

The previous peer reservation has gone. The project claim protocol's file scope was
rechecked in both namespaces, reserved under a fresh lease, and passed its conflict check.
The optional machine identifier is omitted from public claim metadata.

## Input review

Upstream changes 31 game source files, with no header changes and no layout migration.
The four source-specific flag-line differences are:
- `Common/Bfme/Rva00C6DB80StaticInit.cpp`: `/O2 /MD` becomes `/EHsc`.
- New `Common/RTS/Team_notifyTeamOfObjectDeath.cpp`: its own NDEBUG/Windows/CRT/EH/STL and WWLib include flags.
- Removed `Object/Contain/GarrisonContain_xfer_Thunk.cpp`: its former NDEBUG/CRT/EH flags disappear with the donor.
- New `W3DViewRva00743CE0.cpp`: its own root include and NDEBUG/Windows/CRT/EH flags.

These are donor settings, not new BFME 2 compiler overrides. No target layouts,
offsets, function bodies, flags, verifier or baseline are edited. All six current
reference directories resolve to the existing `game/`, `inputs/` and
`targets/game/reverse/` layout. The sole changed nested input is the BFME 2
reference gitlink; it is deliberately not initialized, avoiding reference recursion.

A local full-gate attempt stopped before completing the byte comparison because
Windows refused to launch a legacy compiler with WinError 623 (system DLL relocation).
It is not a successful verification. The independent native Windows runner below
performs both complete checks with the original compiler and unmodified build driver.

A fresh runner starts without earlier donor compile trials. A successful refresh
also regenerates the project donor sweep and records its exact input revisions.
No old trial is represented as current. A failed check keeps the canonical pointer
and records the blocker; it never writes a success stamp.
