# E0322 resize: use the CRT free declaration

Scope: `Code/GameEngine/Source/Common/Rva000E0322Rva000E0322.cpp`,
`?rva000E0322@Rva000E0322@@QAEXI@Z`, RVA `0x000E0322`, 187 bytes.
Selected by the Microsoft-header queue and claimed before editing.

Replace the handwritten C++ `free(void *)` declaration with `<stdlib.h>`.
The TU keeps its existing `/EHs- /EHc-` context and adds `/D_CRTIMP=` so the
header declares a direct C call to the game's allocator override.

The retail REL32 operand at body offset 176 resolves to RVA `0x00030830`.
That 17-byte `_free` row belongs to
`Code/GameEngine/Source/Common/System/GameMemoryFree.cpp`, whose C definition
calls `__gameMemFreePtr(block, 3)`. Its existing C++ free alias also resolves
there. This establishes the callee for this body; it does not justify replacing
other queued free declarations without inspecting their native calls.

The before and after objects contain identical 187-byte body data. Four
relocations are unchanged; the final relocation changes from
`?free@@YAXPAX@Z` to `_free` at offset 176, retaining REL32 type 20 and the
same retail provider. No alias, pin, function row or hatch is added.

Verification:

- `./build.sh` for the source: 1/1 exact, literal/float/import checks pass.
- `find_declared_unmatched.py`: all defined functions matched, before and after.
- `ms_header_audit.py scan` for the source: zero local Microsoft definitions.
  Its `refresh_queue` API removes exactly this source's queue row and preserves
  every unrelated row byte-for-byte.
- `data_check.py`: zero findings. `eh_verify.py`: zero EH rows (EH disabled).
- Ordinary `link_check.py` for this source and GameMemoryFree: 2/2 LINKS,
  204 -> 204 authored bytes, index `bf3dd31211`, retail-truth-4. This is a bounded
  preview preserving existing providers, with no census gain claimed.
- Current dependency receipt and before/after relocation comparison recorded
  locally in `build/ms-header-e0322-20261027/relocations.json`.

Recovery reconciliation (2026-10-28): upstream commit `b321462042` already
uses `<stdlib.h>` with a local `_CRTIMP` definition and has retired this queue
row. Keep that implementation, including upstream's inline-provider suppression,
instead of reintroducing the command-line `/D_CRTIMP=` variant described above.
The relocation comparison above records the original attempt's evidence.
