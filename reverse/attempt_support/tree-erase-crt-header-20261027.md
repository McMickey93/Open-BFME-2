# Tree-erase CRT declarations

Inspected revision: `90b5ece91e`, 2026-10-27. Claimed each edited source.

The Microsoft-header picker selected Rva002CF2D5Erase.cpp. The same bounded
change applies to Rva002CF302Erase.cpp, Rva002CF32FErase.cpp and
Rva002CFD61Erase.cpp, all under Code/Libraries/Source/WWVegas/WWLib/.
Each replaces its local `free` declaration with `<stdlib.h>`, keeping `/MD`
and adding `/D_CRTIMP=` to preserve the native direct-call ABI.

Target evidence, independently checked for each body:

| Row RVA | Bytes | `_free` REL32 offset | Native target RVA |
| --- | --- | --- | --- |
| 0x002CF2D5 | 45 | 0x1C | 0x00030830 |
| 0x002CF302 | 45 | 0x1C | 0x00030830 |
| 0x002CF32F | 45 | 0x1C | 0x00030830 |
| 0x002CFD61 | 53 | 0x24 | 0x00030830 |

The retail opcode is E8 at each call; signed displacement plus the instruction
end gives the target above. This is the game allocator, not the CRT IAT.
The VS2003 stdlib.h declaration is `_CRTIMP void __cdecl free(void *);`.
The flag removes only its import decoration in these TUs; no private prototype
or linker alias remains necessary.

Validation: normal `./build.sh` passes 4/4 rows (188 bytes), string, float and
import checks. `find_declared_unmatched.py` passes. `ms_header_audit.py show`
reports all four clean, removing four local Microsoft-header declarations.
Before/after COFF inspection confirms identical external defined/undefined
symbol sets and identical complete function bytes and relocation tuples.
The joint ordinary link preview reports 4/4 LINKS, 188 -> 188 authored bytes,
against index `73061d9452` (2026-10-27 14:34). No census gain is claimed.
The committed Microsoft-header queue is an older scan; it was not regenerated.

## Initial linking lead released

The default picker first selected EvacuateDamageCtorModuleFactoryBody.cpp.
The current ordinary preview still reports U1/L2/S2 against the same index.
Its 0x0002CD7B row remains misidentified: the INIMacroTable lifetime reaches
the nocase tree at 0x0002CC38 and hashtable at 0x0002CCC3, not EvacuateDamage's
members. The TU map marks this row displaced, with no approved destination.
The existing LINK-006 prerequisite still applies: resolve the actual macro
table types and approved ownership before replacing the row and EH identity;
do not suppress the only providers. No source trial was made or retained,
and both the RVA and source claims were released before the header work.
