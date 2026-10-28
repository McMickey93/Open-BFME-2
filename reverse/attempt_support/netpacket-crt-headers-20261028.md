# NetPacket CRT declaration cleanup, 2026-10-28

Inspected revision: c64f680554. Scope: NetPacket.cpp's four local Microsoft
function declarations, served by the Microsoft-header audit.

Replacing memcpy, _mbscpy, operator new and operator new[] with string.h,
mbstring.h and new together does not preserve the retail bytes. Under this
TU's /EHs configuration the message readers acquire exception-state stores;
readFrameMessage at RVA 0x0058DCEB is one affected parent. This trial was
reverted. It does not establish that each C prototype fails independently.

The retained change replaces only the two allocation declarations with new.
The explicit throw() contracts on the C declarations remain. All 196 rows
match; all 65 EH graphs are EXACT with no baseline exceptions. The 246 COMDAT
fingerprints, external definitions and undefined symbols are identical to
the baseline object. The declared-function check passes. A scoped header
audit reduces this queue entry from four local functions to two; other queue
entries are preserved.

The ordinary link preview remains clean against census index 14dc3d2467
(2026-10-28 02:44); its projected 30,374 -> 32,987 bytes is the same before
and after this cleanup. No census improvement is claimed. No source path,
ledger, shared header, allocator binding or escape hatch changed.
