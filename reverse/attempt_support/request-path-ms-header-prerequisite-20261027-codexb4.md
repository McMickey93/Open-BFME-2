# requestPath Microsoft-header prerequisite

Inspected BFME 2 revision `48cba50b7d` on 2026-10-27. Source:
`Code/GameEngine/Source/GameLogic/Object/Update/AIUpdateInterface_requestPath_Rva0026893F.cpp`.

The Microsoft-header picker classifies the local `fprintf` declaration as a
conflicting `<stdio.h>` copy. No source trial was retained or needed: the
existing declaration intentionally binds a different game operation.

Target and current-owner facts:

- The source owns requestPath at RVA 0x0026893F (248 bytes) and
  canComputeQuickPath at 0x00262A64 (38 bytes). The declaration check finds no
  unrowed definitions. Ordinary `./build.sh` verifies both bodies, including
  their existing named call references and one logging string.
- The caller's `_fprintf` binding resolves to RVA 0x002CEC42. Its current owner
  is `Code/GameEngine/Source/Common/FprintfAppendLine.cpp`, a matched 108-byte
  game helper, not the CRT stream formatter. The owner formats with imported
  `_vsnprintf`, constructs a temporary string and appends it to an object's
  vector at +4. Its `FprintfTarget*` argument and void return agree with the
  caller's declaration. The first object field remains unproven padding.
- `reverse/symbols.csv` still calls this address a statically linked CRT
  fprintf. That older description contradicts the current recovered owner and
  must not justify adopting `FILE*` or the imported CRT function.

Next: establish the game helper's actual identity and reconcile its owner and
callers through the normal naming/identity workflow before replacing these
declarations. This handoff supplies no canonical name evidence and makes no
layout claim beyond the current owner's documented offsets. Do not infer a
real CRT call from the existing `_fprintf` spelling.

The source is unchanged, the blocked verdict was recorded with `re_log.py`,
and the file claim was released. No debt key or queue row was retired; no new
matched bytes, link clearance or census gain is claimed.
