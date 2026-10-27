# EA compression allocator declarations

Inspected revision: `13680f484b`, 2026-10-27. The default queue first served
Coord3D and Xfer header work with existing blocked verdicts and unchanged
prerequisites. Those class claims were released without editing the sources.
The Microsoft-header picker then served `Compression/EAC/refencode.cpp`;
the two neighboring encoder files have the same private allocator declarations
and were claimed separately.

## Change

`btreeencode.cpp`, `huffencode.cpp` and `refencode.cpp` now include the real
`<stdlib.h>` instead of declaring `malloc` and `free` locally. `/MD` makes
the compiler's header declare these functions as CRT imports, preserving the
existing retail IAT calls. No function bodies, layouts, ledger rows, symbols,
pins or shared headers changed.

## Verification

- Frozen-file checks pass before and after the changes.
- Original and final normal builds pass all 25 function rows. The final build
  also verifies all eight named import references, with no baselined checks.
- Full COFF comparison excluding debug sections and `.drectve` proves identical
  section bytes, flags, definitions and relocation targets in each object:
  BTree 8 sections / 4,102 bytes; Huffman 13 / 6,288; RefPack 4 / 1,318.
  Undefined external-reference sets are identical. BTree has one malloc and
  one free relocation; Huffman three malloc and one free; RefPack one each.
- The intended `.drectve` difference is `/DEFAULTLIB:"LIBC"` becoming
  `/DEFAULTLIB:"MSVCRT"`; `OLDNAMES` is unchanged. This follows the imported
  allocator ABI already proven by the retail import checks.
- `ms_header_audit.py scan` reports zero local Microsoft declarations in all
  three sources. Its scoped `refresh_queue` removes just these three queue
  entries, preserving unrelated records.
- Ordinary `link_check.py` against census index `bf3dd31211` (2026-10-27
  00:39, retail-truth-4) preserves LINKS for each unit: BTree 4,094 authored
  bytes, Huffman 6,259 and RefPack 1,318, totaling 11,671 before and after.
- `git diff --check` passes.

Original sources/objects and the comparison receipt are local scratch under
`build/ms-headers-refencode-20261027-codex5/`. This is Microsoft-header cleanup,
not new matched bytes, census linking progress, ownership progress or runtime
verification. No maintainer-only measurement was run.
