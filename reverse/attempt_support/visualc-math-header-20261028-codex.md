# visualc.h: use the pinned CRT math constants

Inspected BFME 2 revision `2b9f5c4d64`, 2026-10-28 UTC. The Microsoft-header
queue selected `Code/Libraries/Source/WWVegas/WWLib/visualc.h`, and its file
scope was claimed before editing.

The twelve removed definitions are exact textual copies of lines 142-153 of
the pinned MSVC 7.1 `Vc7/include/math.h` under
`reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual
Studio .NET 2003/`. The replacement opts into the CRT's `_USE_MATH_DEFINES`
interface and includes `<math.h>`. The two remaining Westwood definitions,
`M_1_SQRTPI` and `M_SQRT_2`, have no identically named definition in that header.
No upstream source recovery or new code identity is inferred from this copy.

The frozen-file check and staged whitespace check pass.
`tools/ms_header_audit.py scan` reports zero local Microsoft definitions or
declarations, zero failed files and zero CRT import conflicts in this header.
The supported staged include graph selects 892 ledger sources for byte
verification; the original header has no ledger function row of its own.

The supported `./build.sh` dependent-source gate passes (exit 0): 8,026/8,026
functions across 892 sources and all 140 data rows byte-match retail. It rebuilt
105 function TUs and reused 787 current objects. String references pass with
1,639 literals and 165 empty strings, float references with 2,412 compiler
literals, and import references with 654 named imports. The five reported
funclet-label renumberings are resolved by the existing parent EH verification.

This cleanup removes twelve local Microsoft definitions, with no new matched
bytes, census-linked bytes or image-ownership result.
