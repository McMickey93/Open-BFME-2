# Army details inline floor linkage

Inspected BFME 2 revision: `88160d0cb79ffad492171d17c3f74eb47b126fcd`.
Published preview index: `41c28839bf`, 2026-10-28 11:08, based on census
`c8734bec0c`, 2026-10-28 10:03. The default picker claimed the source and
0x00068E15; that row is an existing folded allocator, not a missing body.

The current ordinary preview of
`Code/GameEngine/Source/Common/Rva005F2CBAProgress.cpp` fails only on
`_floorf`: the selected Render2DSentenceDrawBFME2.cpp copy has digest
`39fd7295f71e` and is not retail's wrapper. The public copy emitted here
is unused: the source calls `floor` directly. Give math.h's inline wrapper
internal linkage using the established mapper/terrain-projection spelling.
No arithmetic, class view, compiler option, row or pin changes.

The ordinary same-index preview changes from blocked to LINKS for 4,242
authored nonpadding bytes. This is a scoped preview, not a census gain or
a repair of the globally selected wrapper.

Verification:

- `./build.sh` passes 67/67 rows, 31 literals and 12 empty-string references,
  nine float literals and eight named imports. The frozen-file check passes.
- `eh_verify.py` reports six EXACT graphs. Compiler-label renumbering is
  resolved through the existing parent graphs, without ledger edits.
- The before/after objects remove exactly the public `_floorf` copy. All 138
  retained external COMDAT byte/relocation digests, exclusive definitions,
  undefined externals and weak aliases are unchanged. Compact receipt:
  [object comparison](army-details-floor-object-20261028-codex3.json).
- `link_check.py --prepare-current` byte-verifies the edited provider and
  produces its strict reusable receipt. No census/index/status is updated.
- The existing public wrapper owner at 0x0004D649 in
  `Code/GameEngine/Source/GameLogic/Map/TerrainLogicAmbientColorRva0027DA6A.cpp`
  also passes strict preparation: two rows, seven floats and three imports.
- The full tree gate with this repair and the pinned BFME 1 reference
  `7c48cfd167` passes all 98,941 function rows, all 2,203 data rows,
  reference checks and the no-op patch.

No source paths, registered debt or image ownership change. The global
selected-copy repair and the next normal census remain prerequisites for
broader linking claims. Scratch logs: `build/army-details-floor-20261028/`.

The staged-tree batch audit exits 2, INCONCLUSIVE: index `41c28839bf`
predates the outgoing base, and affected consumer
`Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp` lacks a current
receipt. Full external consumer selection remains unverified. Carry this
removed-copy scope and consumer into the next normal census.

Publication preflight at the inspected base refuses an obsolete flag override
for deleted BfmeThingDGDRva007F8400.cpp. Upstream `88a465d1dd` removes that
stale entry; pulling through `16a385868f` resolves the refusal, with this source
unchanged and check_csv green. No verifier or override is changed locally.
The identity check also reports the existing `??0Rva0086EE20@@QAE@XZ`
definition divergence in shadow mode. Its retained COMDAT digest is unchanged
by this wrapper-only repair; no constructor identity repair is claimed.
