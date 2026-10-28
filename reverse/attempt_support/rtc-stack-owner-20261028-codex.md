# RTC stack checker ownership prerequisite

Inspected revision: `51fa553a3c`, 2026-10-28. Ordinary preview index:
`41c28839bf` (2026-10-28 11:08). No source or ledger ownership changed.

`Code/Libraries/Source/CRT/RtcStack.cpp` owns the 90-byte fastcall checker
at `0x0075A5C5`. The ordinary current-input preview still reports exactly
one duplicate, `@_RTC_CheckStackVars@8`, and zero linked authored bytes
(86 authored preview bytes; the ledger extent is 90).

The archive member `..\build\intel\dll_obj\stack.obj` also defines this
symbol. It is included for the 35-byte `__RTC_CheckEsp` row at `0x0075A5A2`
in `vendor/msvc71crt/msvcrt.lib`. The archive provenance explicitly records
both sections and requires the recovered checker to remain C++.
`tools/conversion_gate.py` forbids moving clean C++ back into an archive.
The committed TU map currently approves neither address's destination.
Thus restoring the former MASM sibling is a source move needing placement
approval first, not an unverified local workaround for the duplicate.

The earlier inline trial in LINK-020 removed the matched symbol and failed
byte verification. It was not repeated. No compiler machinery was rewritten,
no archive was altered, and no census or runtime improvement is claimed.

Checks: `find_declared_unmatched.py` reports all definitions matched;
`./build.sh Code/Libraries/Source/CRT/RtcStack.cpp` verifies the unchanged
row. `link_check.py` confirms the duplicate described above.

Next: settle and approve the native stack unit's ownership, retaining the
checker as clean C++ and the flag-consuming helper as proven compiler
machinery; verify all consumers when changing archive-member inclusion.
The blocked attempt verdict now makes the default picker defer this known
prerequisite behind untried work.
