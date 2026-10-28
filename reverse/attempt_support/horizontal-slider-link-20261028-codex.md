# Horizontal slider renderer dependency cleanup

Inspected revision: `e0be65e163`; BFME 1 reference:
`e74410b3738a2bb75d626085d9ebfd3406a43ff7`, with the 2026-10-27
freshness receipt. Preview index: `41c28839bf`, 2026-10-28 11:08;
its underlying census is `c8734bec0c`, 10:03. The default picker claimed
0x000A166A and the W3DHorizontalSlider.cpp file scope.

The current object failed ordinary preview only on the selected
`??_EPendingSurfaceStruct@Render2DSentenceClass@@QAEPAXI@Z` copy.
This is a consumer subset of LINK-132's fold-row ordering obstacle.
W3DGadget.h includes W3DGameWindow.h, which includes Render2DSentence.h.
The slider callbacks use GameWindow and the 1.0f border-width macro, but
never W3DGameWindow or its renderer. Include GameWindow.h directly and
retain the exact donor macro value locally. No shared header, row, pin,
compiler option or function body changes.

The donor include graph explains the surplus machinery; target byte checks
prove that removing the dependency preserves these BFME 2 callbacks.
The source's existing comments retain their separate target and donor name
provenance. No additional name or layout claim is made here.

The object loses only the PendingSurfaceStruct vector deleting destructor
and the vector-construction iterator. All 54 retained external COMDAT
byte-and-relocation fingerprints are identical, including all four drawing
callbacks. Strong definitions and weak aliases are unchanged; four unused
undefined dependencies disappear and none are added. The index has other
retail-proven copies of both removed helpers. These indexed providers are
historical facts, not a new current whole-tree consumer verification.
[Object comparison](horizontal-slider-object-20261028-codex.json).

Verification:

- `./build.sh` passes all seven rows, six string literals and fifteen float
  literals. Parent-derived EH verification resolves the renumbered local
  funclet labels without changing their ledger entries.
- Frozen-file checks pass before and after; `eh_verify.py` reports one EXACT
  graph, with no exceptions or missing objects.
- Same-index ordinary preview changes from blocked to LINKS for 2,675 authored
  nonpadding bytes. This is a preview result; no new census-linked bytes,
  image-ownership result or runtime result is claimed.

Scratch inputs and object receipt: `build/horizontal-slider-link-20261028/`.

Strict preparation verifies the edited source with a reusable receipt;
data_check reports zero findings. The final ordinary preview still reports
LINKS for 2,675 authored bytes.

The staged-tree batch audit is INCONCLUSIVE: index `41c28839bf` predates
the outgoing base, and affected consumer
`Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp` lacks a current
receipt. Full external consumer selection remains unverified. Carry this
removed-helper scope into the next normal census; no whole-batch clearance
is claimed. The source adds no provider and changes no retained COMDAT.
