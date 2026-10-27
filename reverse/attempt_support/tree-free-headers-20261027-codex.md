# Standard allocator declarations for two tree cleanup units

Inspected revision: `0ab37b3468`, 2026-10-27. Claimed both sources under
`Code/GameEngine/Source/Common/System/` before editing.

The Microsoft-header picker selected Rva007590B0TreeFree.cpp. The same
local C-linkage allocator prototype occurs in Rva0028F662TreeFree.cpp.
Both now include `<stdlib.h>` instead of redeclaring `free`; `/D_CRTIMP=`
preserves their observed direct-call ABI while retaining `/MD`.

Each retail call was independently decoded and checked against the old
and new objects' `_free` REL32 relocation:

| Source | Row RVA | Row bytes | Displacement offset | Native target RVA |
| --- | --- | ---: | --- | --- |
| Rva007590B0TreeFree.cpp | 0x007590B0 | 51 | +0x20 | 0x00030830 |
| Rva0028F662TreeFree.cpp | 0x0028F662 | 45 | +0x1C | 0x00030830 |

The native opcode is E8 in both cases. The destination is the existing
GameMemoryFree.cpp wrapper, which forwards to `__gameMemFreePtr` with
memory class 3. This evidence requires the direct declaration supplied by
VS2003 stdlib.h with empty `_CRTIMP`; its default dllimport decoration
would change the calls. No provider, pin, class identity or row changed.

Normal `./build.sh` passes all three rows, totaling 147 bytes, including
Rva007590B0TreeFree.cpp's 51-byte sentinel reset at 0x00759AE0. The two
frozen-file checks pass. `ms_header_audit.py show` reports both sources
clean, removing two local Microsoft-header declarations. The historical
queue was not regenerated.

Before/after COFF inspection confirms identical complete bytes and
relocation tuples for all three functions, and identical external symbol
sets (names, values, defined/undefined state and types) in both units.
`git diff --check` passes. No census-linked-byte or runtime gain is claimed.
