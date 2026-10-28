# WinMain Microsoft-header migration

Inspected base: `46f3656491`; date: 2026-10-28; preview index: `41c28839bf`.
The default picker claimed `file:Code/GameEngine/Source/Main/WinMain.cpp`.
BFME 1's verified reference check remains within its 72-hour interval.

Replace the unit's local Windows and CRT declarations with the VS2003
Platform SDK and CRT headers. `NO_STRICT` preserves its existing void-pointer
handle signatures; `_WIN32_WINNT=0x0400` exposes `WM_MOUSEWHEEL`. The SDK
supplies the window structures, message/style constants and imported APIs.
The CRT supplies string, conversion, formatting and allocation declarations.

Target evidence: trimArgument at 0x00001C2E calls the `_mbscpy` import thunk
at 0x00629176 using E8; WinMain inlines the same operation. The thunk resolves
through IAT slot 0x00BBA6D0. Ordinary dllimport mbstring declarations changed
both bodies and were rejected by the byte gate. Include mbstring.h with its
supported `_CRTIMP` setting empty, then restore dllimport for subsequent
headers. Cast the existing character pointers to the header's unsigned-character
types. This preserves both native calls without a private function declaration.

Verification:

- `ms_header_audit.py show`: the original conflicting unit has 140 queued local
  definitions; the migrated unit is clean. Remaining reported occurrences are
  configuration macros, a forward declaration and the WinMain implementation.
  The tool's `scan_text`/`refresh_queue` path removes only this completed source
  from `ms_header_queue.tsv`, preserving every unrelated queued record.
- `./build.sh`: all 13 rows exact before and after; 12 literals, one empty-string
  reference and 51 named imports verified. No ledger or pin changes.
- `link_check.py --prepare-current`: strict reusable compiler receipt passes.
- `eh_verify.py`: the WinMain EH graph is EXACT; existing parent-EH verification
  resolves all four renumbered funclet labels without changing ledger hints.
- `find_declared_unmatched.py`: all defined functions are already matched.
- `data_check.py`: zero findings. Staged code identity: zero new findings.
- All 35 external COMDAT byte-and-relocation digests are identical to the saved
  original object. All 144 external definition/reference entries, including
  54 definitions, and the object relocation-reference graph are unchanged.
- Ordinary before/after previews retain LINKS for 3,224 authored bytes.
- Staged outgoing audit: INCONCLUSIVE because index `41c28839bf` predates the
  base and affected consumer `Common/0CreateAHeroManager21FE49.cpp` lacks a
  current receipt. Carry this provider/consumer scope into the next census.

Raw local checks: `build/winmain-headers-codexb/`. No shared headers, source paths,
protected debt registers or census figures change. This completes the unit's Microsoft-header
cleanup; no new linked-byte or runtime result is claimed.
