# Coordinate constructor companion acceptance

Inspected BFME 2 revision `f651f320c0` on 2026-10-27. The default picker
claimed `class:Coord2D` and selected Rva000A953BCtor.cpp. Its source already
includes Coord2DCtorView.h and declares no private Coord2D body. The frozen
check and ordinary build pass all three rows. No game source needs editing.

The default adoption verdict nevertheless reports only
`does not #include Code/Libraries/Include/Lib/Coord2D.h` when the byte gate
passes. This reproduces the previously recorded `false-reject` reports in
reverse/re_attempts.log for the coordinate companions and verify-removed.
An explicit `--header` workaround would leave the trusted-base hook verdict
disagreeing with the CLI, so no queue row is removed with the checker repair.

The existing Coord2DCtorView.h documents the native empty default constructor
at 0x0047A6A9, copy constructor at 0x005CFBC2, component constructor at
0x00003F3A and destructor at 0x000B3FD0. Rva000A953BCtor.cpp requires the
external default constructor callback for arrays of three and two elements.
Coord3DCtorView.h documents the corresponding non-POD Coord3D view. Both
companions deliberately take their plain header's guard rather than include
the conflicting POD definition; plain-header consumers must retain their view.
These are existing codegen interfaces, not newly inferred donor layouts.

The checker recognizes exactly these two class/canonical-header/companion
relationships. It uses the existing include resolver, requires the companion
file to exist, still rejects a private body, and still runs the byte gate.
It does not derive approval from a basename convention or copied include guard.
Both the default verdict and an explicit canonical-header verdict use the
same rule, including when loaded from a committed trusted base by repair_queue.

Validation:

- Before the repair, the new regression cases produce four failures: both
  coordinate companions are refused, including when the byte gate reports a
  mismatch. Sixteen rejection controls already pass.
- After the repair, `python3 -m pytest -q
  tools/tests/test_header_adopt_lane.py tools/tests/test_repair_queue.py
  tools/tests/test_gate_exploits.py` passes 297 tests, with one existing skip.
  Controls cover private bodies, comments, disabled includes, absent files,
  ambiguous basenames, unapproved paths, the other coordinate class, an
  unrelated explicit header, and mismatching bytes. A failed byte verdict
  preserves the queue row.
- `./build.sh Code/GameEngine/Source/Common/Rva000A953BCtor.cpp` passes
  3/3 rows. Its real default `verdict`, including the normal byte gate, returns
  no problems after the repair, without changing the source or ledger.
- `git diff --check` passes.

This checker-only repair retires no debt and claims no linked-byte or runtime
gain. A later separate acceptance commit must reverify each queued source and
let the owning tool retire its row under the committed checker.
