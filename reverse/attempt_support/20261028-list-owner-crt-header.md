# List-owner destructor CRT declaration

Inspected `a2002051b5`, 2026-10-28; owner `yasinschroeder-codex`.
The Microsoft-header picker claimed
`Code/GameEngine/Source/Common/Rva0053947DDtor.cpp`.

Replace its local C-linkage `free` declaration with `<stdlib.h>`, keeping
`/MD /EHs` and adding `/D_CRTIMP=` for the existing direct-call ABI.
The retail destructor at RVA `0x0053947D` has an E8 call whose REL32 operand
is at body offset `0x44`; independently decoding that displacement gives
`0x00030830`, the game allocator wrapper in
`Code/GameEngine/Source/Common/System/GameMemoryFree.cpp`.
It does not call the CRT IAT entry. No class, function row, pin or alias changes.

Normal `./build.sh` passes all eight consumer/provider rows before and after
the edit. Both EH graphs are EXACT. The constructor (108 bytes), destructor
(87 bytes) and virtual method (42 bytes) have identical complete bytes and
relocation tuples before and after. All external symbol names, values, types
and defined/undefined states are identical. The frozen-file check passes;
`ms_header_audit.py show` changes the source from conflicting to clean,
removing its one local Microsoft-header declaration. The historical queue
is not regenerated. Included-reference findings remain separate.

Ordinary joint `link_check.py` reports both sources LINKS, preserving
254 authored bytes (237 consumer, 17 allocator), against index
`73061d9452` (2026-10-27 14:34). No census-linked-byte gain is claimed.

Object SHA-256, before then after:

- `b416c41dec77fe6e6bc863fce5a1956cf4e90c4d0b9d2a7443f17bf2aa9e9cb1`
- `7138b2718dd1cd68fa7f34ccfe6f199c6c2b6260b6b9b45dafcda539b8f6ab3c`

## Initial linking lead released

The default picker first served `Rva008312E0StringReplace.cpp` at
`0x000284D0`. Current source includes the earlier erase-binding repair.
The tracked string-erase evidence and replaceBase handoff still require an
admissible owner/signature transition at `0x0002A610` before the banked
member-template trial can proceed. No new evidence resolves that prerequisite;
no string source edit or repeated compile trial was made. Its claim was
released before taking the independent header work. LINK-006 remains open.
