# Canonical AsciiString cleanup bindings

Inspected base: `362bf9a27888b582a6eb3c9bce1e1486e5c2e12d`.
Ordinary preview index: `41c28839bf`, published 2026-10-28 11:08 UTC.

## Target facts and change

The existing draw-data parser (0x00315DB1), string registry setter
(0x00234621) and unsigned registry setter (0x002346EA) bind cleanup calls to
`??1AsciiString@@QAE@XZ` at retail's `StringBase<char>::releaseBuffer`
(0x00036410). The actual out-of-line AsciiString destructor is the five-byte
forwarder at 0x0048BA39; the earlier investigation is recorded in
[the destructor-pin handoff](asciistring-dtor-pin-20261019.md).

Route these three consumers through the existing canonical BFME 2 string
header, using its existing Common/AsciiString.h adapter. Remove the replaced
donor ASCII include paths. The inline destructor now names releaseBuffer
directly, including the compiler's exception cleanup. No shared header,
ledger row, pin or source path changes.

## Verification

- Normal verifier: all ten function rows exact; 28 literals, two empty-string
  references and seven named imports verified. All three EH graphs are EXACT.
- All three frozen-file checks pass; class gate passes; scoped data check has
  zero findings. `git diff --check` passes.
- Each owning `repair_queue.py retire identity SOURCE` verdict removes exactly
  one key with zero remaining source findings. The register shrinks by three.
  Its first attempt refused four missing ledger objects; normal `./build.sh`
  rebuilt those sources, passing 52/52 rows and two data rows before retrying.
- [Object comparison](ascii-cleanup-binding-20261028-codex3.json): the parser's
  567 other COMDAT digests and each registry setter's two other COMDAT digests
  are unchanged. Exclusive definitions and weak externals are unchanged.
  Each unit replaces the destructor dependency with releaseBuffer and emits
  the same retail-proven five-byte destructor copy (`d08bf29c9c2b`). No
  existing COMDAT is removed. The three parent fingerprints change with
  their intended relocation identities; their retail bytes remain exact.
- Ordinary previews before and after are LINKS for all three units:
  1,099 + 201 + 158 = 1,458 authored bytes retained. This is a preview scope,
  not an increase in census-linked coverage.
- The outgoing batch audit against the staged tree is INCONCLUSIVE (exit 2):
  its index predates the base, and all three ordinary verified objects lack
  the census-grade include-inventory receipts required by that audit. It
  stops before checking affected consumers. The object comparison above
  supports this narrow change but does not replace that consumer audit.

## Remaining work

The other registered AsciiString bindings and LINK-099/LINK-100 consumer
prerequisites remain separate work. The old destructor pin is unchanged.
Full affected-consumer selection awaits current census-grade receipts and
the next scheduled census; no runtime or image-ownership result is claimed.
