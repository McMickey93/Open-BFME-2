# ResolveBattles unused STL include cleanup

Inspected `344e3c3b1e` on 2026-10-27. The three file scopes were claimed
before editing. All paths below are under
`Code/GameEngine/Source/GameClient/LivingWorld/InGameUI/`:

- `StrategicInGameUIResolveRegionOwnership576834.cpp`
- `StrategicInGameUIResolveBattlesBehavior_OnMouseLeftClick.cpp`
- `StrategicInGameUIResolveBattlesBehavior_OnMouseLeftClick_OnMouseLeftClick.cpp`

Each source included `<vector>` through a handwritten `_STL::free`
declaration and macro, but used neither vector nor free. Removing the unused
block preserves the existing `<stdlib.h>` include. The base
`StrategicInGameUIResolveBattlesBehavior.cpp` actually uses vector and was not
changed. A scoped `ms_header_audit.refresh_queue` removes precisely the three
clean rows; the scanner finds zero local Microsoft declarations in them.

Verification: `./build.sh` passes all 11 rows across the three sources, and
`find_declared_unmatched.py` is clean for each. All three parent EH graphs are
EXACT. The mouse-handler objects retain identical executable-section bytes and
relocation targets; internal compiler labels were compared by their section
content and offset after label renumbering. CSV and whitespace checks pass.

Ordinary link previews before and after preserve LINKS for the ownership
resolver (161 authored bytes) and long mouse handler (537 bytes). The short
handler (191 bytes) retains the same unresolved
`?IsLocalPlayerAllowedToEndPhase@Rva002B5EB5@@QAE_NXZ` in the published index.
That name already has a matched owner in
`Code/GameEngine/Source/GameLogic/System/LivingWorld/LivingWorldLogic.cpp` at
0x002B5EB5. Supplying that current provider produces 4/4 LINKS, including all
three edited consumers and the 20,081-byte provider. The preview uses index
`bf3dd31211` (2026-10-27 00:39, retail-truth-4). No new body or link repair is
needed for this scope; no census gain is claimed.

The BFME 1 reference remains at verified `4fa9d591`: the official upstream
freshness check found `a0940f921`, but the reference scope was held by another
worker. No reference input or freshness marker was changed.
