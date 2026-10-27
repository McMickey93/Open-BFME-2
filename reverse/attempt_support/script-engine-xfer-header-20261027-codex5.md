# ScriptEngine canonical Xfer adoption

Inspected revision: `e43a9aad40`, 2026-10-27. The default picker claimed
`class:Xfer` and its queued source scopes. The function CSV check passed, and
the verified BFME 1 reference receipt was less than 72 hours old.

## Retained change

`Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptEngineDoXfer.cpp` now uses
the canonical `Common/BfmeXfer.h` interface instead of its private Xfer class.
Local operand forward declarations support the shared header. Calls use its
reference overloads and `XferRawBytes`; the existing two-byte version operand
is passed as the canonical opaque `Xfer::Version` reference. No shared header,
compiler flags, function rows, symbols or pins changed.

Verification:

- Frozen-file checks pass before and after the edit.
- Normal `./build.sh` runs pass all 79 rows before and after, including the
  6,131-byte `ScriptEngine::doXfer` body. String and float reference checks pass.
- Final `tools/eh_verify.py` reports four EXACT graphs, with no baseline use
  or missing objects.
- Comparing the original and final COFF objects finds the same 434 COMDAT
  names and byte/relocation digests. Their undefined external-reference sets
  are identical.
- Scoped shadow `tools/data_check.py` reports zero findings.
- The ordinary current-object link preview preserves LINKS for all 7,117
  authored bytes. The fetched index is `bf3dd31211`, dated 2026-10-27 00:39,
  under `retail-truth-4`; this is a preview, not a new census.
- `tools/header_adopt_lane.py accept --class Xfer` accepts the source and
  retires its one header-queue row. No queue row for this source remains.

This retires header debt. It does not claim new matched bytes, new linked
bytes, ownership progress or runtime verification.

## Restored SaveGameInfo trial

`Code/GameEngine/Source/Common/System/SaveGame/SaveGameInfoCopyBFME2.cpp`
passes its original 53 rows and previews LINKS for 2,435 authored bytes.
A canonical-Xfer trial with operand declarations reaches C2259: its
stack-instantiated `XferMD5CRC` and `BFMECRCWriter` views remain abstract.
The compiler names `BeginBlock`, `EndBlock`, `SkipBlock`, the container-name
`operator==`, and `XferData` as missing pure-virtual implementations.

Reconcile the native derived writer interfaces before retrying this source;
operand declarations alone do not resolve it. The entire source was restored,
then normal verification again passed all 53 rows and the current-object link
preview again preserved 2,435 bytes. Its header queue entry remains. The
separate LINK-095 generated-unwind prerequisites are unchanged.

The other claimed Xfer sources were not edited. Their previously recorded
LINK-004 prerequisites remain open.
