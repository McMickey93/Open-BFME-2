# Angle helper Microsoft-header cleanup

Inspected `b8156cd386` on 2026-10-27. Source:
`Code/GameEngine/Source/Common/Rva004D6B6EAngle.cpp`.

Replace the local `atan` and `tan` declarations with `<math.h>`. Explicit
double arguments select the same functions as the old declarations; the
header's float overload otherwise moves one stack pop in the tangent helper.
Compiler flags, function identities and rows are unchanged.

Verification:

- Ordinary byte gate: 4/4 matched rows, eight float references verified.
- Complete COFF comparison: all 12 non-debug sections (219 bytes), 12
  relocations and 14 external symbol records unchanged. TU-local relocation
  targets compared by section and offset. Local before-object retained in
  `build/codex-angle-headers/before.obj`.
- Declaration check, Microsoft-header check and enforced data check pass;
  the data check reports zero findings. The owning header scanner reports no
  local definitions or include-closure findings; its scoped `refresh_queue`
  removes only this source's queue entry.
- Ordinary link preview remains LINKS, 146 authored bytes, against census
  `bf3dd31211` (2026-10-27 00:39). No census gain is claimed.

## AI logger prerequisite

The header picker selected
`Code/GameEngine/Source/GameLogic/AI/AIAttackApproachTargetStateOnExit.cpp`.
Its local `fprintf` declaration refers to the game helper at RVA 0x002CEC42,
owned by `FprintfAppendLine.cpp`. That helper takes an opaque vector-backed
`FprintfTarget`, formats a line and appends it. It is distinct from the real
CRT `fprintf` thunk at RVA 0x006298C2 (IAT VA 0x00BBA5C4).

A `<stdio.h>` trial with `_CRTIMP` empty byte-matched all five rows, but
assigning `FILE *` to this game's logger was semantically incorrect. The trial
was discarded. This is a game logger identity/type prerequisite, not evidence
that the CRT header should be adopted. The older `_fprintf` pin note calling
the helper statically linked CRT is contradicted by its matched provider body.
No new identity, layout, marker or hatch is admitted here.

## Existing thread-wrapper repair confirmation

The default picker served
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Rva000E6B99FreeBuffers.cpp`.
All four existing rows byte-verify. Paired with current
`Code/Libraries/Source/WWVegas/WW3D2/BfmeDX8ThreadLock.cpp`, both ordinary
previews LINKS (229 and 247 authored bytes). This confirms LINK-106's existing
repair for this caller; no source repair or new census gain is claimed.
