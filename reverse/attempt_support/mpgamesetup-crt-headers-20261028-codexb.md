# Multiplayer setup Microsoft-header cleanup

Inspected base: `38c5c62536`, 2026-10-28. Claimed scope:
`Code/GameEngine/Source/GameClient/GUI/MpGameSetupSlots.cpp`.

Replace the five local declarations of atoi, _mbscpy, strcmp, sprintf and
timeGetTime with their Microsoft headers. The owning header scanner now reports
CLEAN; its scoped `refresh_queue` removes only this file's queue entry.

## Target evidence and ABI

Retail AptMpGameSetup::ExternFunc at RVA 0x00442F65 joins its four string-copy
branches at the direct call at RVA 0x00442FCD to 0x00629176. The existing symbol
ledger identifies that target as __mbscpy, the six-byte CRT import thunk through
VA 0x00BBA6D0. This is target evidence, not an inferred donor identity.

The mbstring header supplies the unsigned-byte signature; explicit pointer casts
adapt the existing char buffer and string literals. Including mbstring with an
empty _CRTIMP preserves the direct thunk call. Restore dllimport before the
remaining CRT headers, and use the Windows multimedia header for timeGetTime.
NOMINMAX protects the existing local STL max overload. No new pin, provider,
class view, ledger row, source path or hatch is introduced.

## Verification

- Before and after `./build.sh` pass all 98 rows, 41 string literals plus two
  empty strings, and three named imports.
- `eh_verify.py` reports 13 exact EH graphs, zero missing or nonexact. Compiler
  funclet-label renumbering is covered by these parent graphs.
- Frozen-file checks before and after report all defined functions matched.
- Class gate passes; data_check shadow reports zero findings.
- COFF comparison with the saved pre-edit object finds all 141 external COMDAT
  body digests and sizes identical, and the 251 external symbol name/definedness
  entries identical. No external COMDAT is added or removed.
- Before/after ordinary `link_check.py` previews both report LINKS for 7,530
  authored bytes against fetched index `41c28839bf` (2026-10-28 11:08).

Local logs and object comparison: `build/mpgamesetup-header/`; baseline build:
`build/mpgamesetup-header-before.log`. These are scratch evidence, not progress
receipts. No linked-byte census gain or full-game clearance is claimed.

The staged-tree `link_batch_audit.py` exits 2, INCONCLUSIVE: the census index
is at `41c28839bf`, not the outgoing base, and MpGameSetupSlots.cpp lacks a
current strict census receipt. The ordinary build/preview and before/after
object comparison above do not establish full consumer clearance. Carry the
unit into the next normal census; no census or smoke run was started.

## Default-picker selection review

The initial default pick was EvacuateDamageCtorModuleFactoryBody.cpp,
RVA 0x0002CD76. Current source, TU-map ownership and prior LINK-006 handoffs retain
the existing blockers: the destructor at 0x0002CD7B is identified as an
INIMacroTable lifetime, with displaced/unapproved TU ownership and unresolved
member identity. The BFME1 analogous source retains the conflicting view and
provides no independent resolution. No source trial or fresh preview was run
for that family; its claims were released before taking the header cleanup.
The next work there remains actual member/type identity and approved TU evidence.
