# Animation debugger CRT declaration cleanup

Inspected revision: `3459c2524c`. Scope:
`Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DDisplayGatherAnimationDebuggingInfo.cpp`.
The Microsoft-header picker claimed this file and served three local declarations.

## Target facts and change

The animation debugger at RVA 0x0004B31C has two direct log calls:

| Call RVA | Retail bytes | Target RVA |
| --- | --- | --- |
| 0x0004B71F | e8 1e 35 28 00 | 0x002CEC42 |
| 0x0004B73F | e8 fe 34 28 00 | 0x002CEC42 |

The existing 108-byte owner in Common/FprintfAppendLine.cpp defines
`extern "C" void fprintf(FprintfTarget *, const char *, ...)`. Its body formats
and appends an AsciiString to the target's vector. The caller's private
`int fprintf(_iobuf *, ...)` declaration incorrectly described a CRT stream.
Use the existing provider's signature, forward-declare its opaque target and
cast the existing log pointer at the calls. No target layout, symbol rename,
pin, new body or ledger row is introduced.

Include the toolchain's `<stdlib.h>` for atexit and delete its private prototype.
The obsolete `_iobuf` forward declaration disappears with the stream view.
The scoped owning `ms_header_audit.refresh_queue` reduces this file's local
Microsoft declaration count from three to one, preserving all unrelated queue
records. Its remaining fprintf item stays queued: the game provider's identity
and callers need reconciliation before stdio adoption. A FILE replacement would
misdescribe the verified game object ABI. This is the same prerequisite as the
[melee logging cleanup](20261027-melee-log-game-abi.md).

## Verification and limits

- Ordinary `./build.sh` passes 13/13 rows across the debugger and existing log
  provider, plus both data rows, 27 literals, 19 empty-string references, two
  float literals and the provider's named import, with no skipped references.
- All 74 external COMDAT names, sizes and byte-plus-named-relocation digests
  in the debugger object equal the saved ordinary before object. No external
  COMDAT is added or removed (`link_census._comdat_sections`).
- Both EH graphs are EXACT. The debugger's declared-body check passes; its
  shadow data check has zero findings.
- Paired ordinary link previews before and after retain 2/2 LINKS and 3,137
  authored nonpadding bytes: debugger 3,019; provider 118. Published index
  `14dc3d2467`, 2026-10-28 02:44. These are predictions, not a new census.

Local object comparison receipts live in `build/codexb5-animation-headers/`.
The last successful BFME 1 freshness receipt is 2026-10-26 21:12 UTC, within
the required 72 hours at this pass. No reference inputs change.

No new matched bytes, census-linked bytes, image ownership or full fprintf
identity clearance is claimed. The remaining game/CRT name collision is separate
work; carry this scope into the next normal maintainer census if the outgoing
batch audit cannot verify external consumers.
