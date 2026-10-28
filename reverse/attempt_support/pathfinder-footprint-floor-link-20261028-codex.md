# Pathfinder footprint inline math linkage

Inspected base: `72a0f2d577e1ac578136a03405aa962a14369f30`.
BFME 1 reference: `e74410b3738a2bb75d626085d9ebfd3406a43ff7`, with
the verified 2026-10-27 freshness receipt. Published preview index:
`41c28839bf`, 2026-10-28 11:08; underlying census: `c8734bec0c`.

The default picker claimed 0x00530212 and its source,
`Code/GameEngine/Source/GameLogic/AI/PathfinderClassifyObjectFootprint.cpp`.
The earlier missing ClassifyWall prerequisite is resolved: its current owner
is rowed at 0x0052F63F. The selected source already byte-matches, and its
current ordinary preview fails only on the globally selected `_floorf`.
This is the existing LINK-132/LINK-133 selected-copy issue.

The classifier inlines every floor operation and calls `__imp__floor`
directly. Its external `_floorf` COMDAT has no incoming runtime reference
from any section of this object. Give math.h's existing inline local linkage,
following the mapper.cpp and terrain-projection repairs. The declaration
must precede math.h; placing it after the definition produces C2375 and was
corrected before verification. No arithmetic, flags, class layout, ledger,
pin, shared header or source path changes.

The [before/after object receipt](pathfinder-footprint-floor-object-20261028-codex.json)
shows exactly one removed external COMDAT, `_floorf`. All 19 retained
COMDAT byte/relocation fingerprints, exclusive definitions, undefined
externals, weak aliases, runtime roots and retained reference edges are
unchanged. The existing ledger owner in
`GameLogic/Map/TerrainLogicAmbientColorRva0027DA6A.cpp` still emits the
retail 18-byte `d9d07276ff39` copy.

Verification:

- `./build.sh` passes the edited source's complete 3,381-byte row,
  24 float literals and ten named imports.
- Frozen-file checks pass before and after; class gate passes and the scoped
  data check has zero findings. `git diff --check` passes.
- `link_check.py --prepare-current` verifies both explicit sources: 3/3
  rows, 31 float literals, 13 named imports and strict reusable receipts.
- Same-index ordinary preview changes the classifier from blocked to LINKS
  for 3,378 authored nonpadding bytes. The paired preview confirms this;
  the unchanged lightmap owner still has its global selected-copy blocker.
- The staged batch audit exits 2, INCONCLUSIVE: the index predates the base
  and affected consumer `Common/0CreateAHeroManager21FE49.cpp` lacks a
  current receipt. Carry this removed-provider scope into the next normal
  census; full external consumer selection is unverified.

The repair clears only this classifier's preview. The global selected-copy
issue and census confirmation remain open. No census-linked byte, debt,
runtime or image-ownership gain is claimed. Scratch evidence is under
`build/pathfinder-footprint-floor-20261028/`.
