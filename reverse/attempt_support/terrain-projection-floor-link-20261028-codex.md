# Terrain projection inline math linkage

Inspected BFME 2 revision: `483b6ac114`; BFME 1 reference:
`e74410b3738a2bb75d626085d9ebfd3406a43ff7`. The reference freshness receipt
is dated 2026-10-27. Preview index: `54b83e4f69`, 2026-10-28 09:35.

The default picker claimed `0x000687EF` and
`Code/GameEngineDevice/Source/W3DDevice/GameClient/BaseHeightMapRva000687EF.cpp`.
All four rows already matched. Its current ordinary link preview failed only
on the selected `_floorf` definition. The indexed earliest copy belongs to
Render2DSentenceDrawBFME2.cpp and has digest `39fd7295f71e`, judged wrong.
That source is held by another worker; no edit was attempted there.

The terrain projection's own `_floorf` copy is the correct 18-byte inline
wrapper, digest `d9d07276ff39`, but nothing in its object calls it. Its uses
are inlined and call `__imp__floor` directly. Give the existing math-header
inline internal linkage, following the existing mapper.cpp repair. No
arithmetic, layout, row, pin, compiler option or shared header changes.
This addresses the selected consumer only; it does not repair the globally
selected wrong copy or other consumers.

Before/after object comparison removes exactly the public `_floorf` copy.
All ten retained external COMDAT byte/relocation digests are identical; the
strong-definition, undefined-external and weak-alias sets are unchanged.
The existing ledger owner in TerrainLogicAmbientColorRva0027DA6A.cpp still
emits the exact 18-byte `d9d07276ff39` wrapper. The paired strict preparation
verifies all six rows across both units. Raw object hashes and comparisons
are in [the object receipt](terrain-projection-floor-object-20261028-codex.json).

Checks:

- `./build.sh` passes all four edited-source rows, twelve float literals and
  four named imports. The verifier derives the two renumbered local funclet
  labels from the real parent EH graph; no ledger-label edit is needed.
- `find_declared_unmatched.py` passes before and after. `eh_verify.py`
  reports one EXACT graph.
- `link_check.py --prepare-current` prepares both explicit providers with
  strict reusable receipts: six of six rows, nineteen float literals and
  seven named imports verified.
- Same-index ordinary preview changes the terrain projection from blocked
  to LINKS for 1,369 authored nonpadding bytes. The paired preview confirms
  that result; the lightmap owner still has the separate selected `_floorf`
  blocker. No new census-linked bytes are claimed.
- The staged-tree batch audit is INCONCLUSIVE: the index predates the base,
  and affected consumer Common/0CreateAHeroManager21FE49.cpp lacks a current
  receipt. Full external consumer selection remains unverified. Carry this
  removed-copy scope into the next normal census.

No source-path move, debt retirement, image-ownership or runtime result is
claimed. Scratch receipts are under `build/terrain-projection-floor-20261028/`.
