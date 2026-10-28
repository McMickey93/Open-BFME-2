# Static-text renderer dependency cleanup

Inspected revision: `4154365966`. BFME 1 reference:
`0424131c818fba6641613ef826222ecf30845025`; its freshness receipt is
2026-10-28 11:47 UTC. The default picker claimed 0x000A08FD and
`file:Code/GameEngineDevice/Source/W3DDevice/GameClient/GUI/Gadget/W3DStaticText.cpp`.
The fetched published index remains `41c28839bf`, 2026-10-28 11:08,
with underlying census `c8734bec0c`, 10:03.

The ordinary current-object preview fails solely on the selected
`??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z` copy.
This is a consumer subset of LINK-132/LINK-133. The donor's W3DGadget.h
includes W3DGameWindow.h, which includes WW3D2/Render2DSentence.h.
These static-text callbacks use GameWindow and the gadget border-width
macro, without accessing a W3DGameWindow renderer. Include GameWindow.h
directly and retain the donor's exact `WIN_DRAW_LINE_WIDTH (1.0f)` value.
No shared header, compiler flag, function body, row or pin changes.

The donor include graph and macro definition explain the removable dependency.
Target byte verification proves preservation of the BFME 2 callbacks; this
change makes no additional target name, layout or original-TU claim.

[Object comparison](static-text-object-20261028-codex3.json) shows only the
PendingSurfaceStruct vector deleting destructor and vector-construction
iterator disappear. All 14 retained external COMDAT byte-and-relocation
fingerprints are identical. Both strong definitions and the empty weak-alias
set are unchanged. Four unused undefined dependencies disappear; none are
added. The index has other retail-proven copies of both removed helpers;
those historical provider facts do not establish current whole-tree closure.

Verification:

- `./build.sh` passes all three function rows (341, 280 and 216 bytes).
- Frozen-file checks pass before and after; EH verification finds no EH rows
  and no missing objects. Scoped data checking reports zero findings.
- `link_check.py --prepare-current` verifies the source with a strict reusable
  compiler receipt, without changing census/index/status.
- Same-index ordinary preview changes from blocked to LINKS for 836 authored
  nonpadding bytes. This is a preview result; census and runtime confirmation
  remain pending. No measured linked-byte or image-ownership gain is claimed.

Scratch objects, comparison and staged-tree audit are under
`build/static-text-link-20261028/`.

The staged-tree batch audit exits 2, INCONCLUSIVE: its index predates the
outgoing base, and affected consumer
`Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp` lacks a current
receipt. Carry this removed-helper scope and that consumer into the next
normal census. Full external consumer selection remains unverified; the
scoped preview result above is not a whole-batch clearance.
