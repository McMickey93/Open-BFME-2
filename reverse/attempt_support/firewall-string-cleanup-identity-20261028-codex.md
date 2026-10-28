# Firewall string cleanup identity

Base: `1ea6ad2c86`. Source: `Code/GameEngine/Source/Common/Rva00595D95Firewall.cpp`.

The existing header adoption and local nonthrowing comparison specialization
already preserve the firewall probe's retail comparison contract. Its remaining
`BFME_ASCII_DTOR_DECL` switch instead makes two ordinary cleanup calls name
`~AsciiString` at the native `StringBase<char>::releaseBuffer` address
0x00036410. The genuine out-of-line AsciiString destructor is the five-byte
forwarder at 0x0048BA39. The identity scan reports both references as divergent
and records one debt key for their parent at 0x00595D95.

Remove the switch and use the shared header's existing inline cleanup. No shared
header, code-generation flag, ledger row or symbol pin changes. This uses the
existing one-pointer string ownership implementation; it asserts no recovered
name for the enclosing firewall class.

Verification:

- `./build.sh Code/GameEngine/Source/Common/Rva00595D95Firewall.cpp`: 3/3
  matched rows; both string literals verified.
- `eh_verify.py` reports one EXACT graph; `find_declared_unmatched.py` finds
  every defined function matched. The existing funclet hint is renumbered in
  both objects and resolves through the exact parent graph.
- Comparing every external COMDAT by `link_census._comdat_sections` finds all
  22 previous definitions retained. Only the 177-byte parent digest changes:
  its raw bytes are identical, and its REL32 references at offsets 62 and 115
  now name `?releaseBuffer@?$StringBase@D@@AAEXXZ`. All other existing
  byte/relocation digests remain identical. The sole added definition is the
  genuine five-byte AsciiString destructor, a jump to the same release worker.
- `allowed_symbols.py --source` reports 12 references before and after:
  owner 6 -> 8, divergent 2 -> 0, alias 3 and EH 1 unchanged; zero rows with
  wrong bindings after the fix.
- `repair_queue.py retire identity` passes and removes exactly one registered
  key, with zero remaining findings for this source.
- Before/after ordinary `link_check.py` previews both report LINKS for 177
  authored bytes against census index `14dc3d2467` (2026-10-28 02:44).

Raw before/after objects and local logs are under
`build/firewall-identity-20261028/`. This retires source-local identity debt;
new census-linked bytes, strict closure and runtime results are unclaimed.
