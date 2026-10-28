# Pathfinder inline floor linkage

Inspected base: `7c27ac5b25`; BFME 1 pointer at this base:
`7c48cfd16763638cdd7440ecd74466631e977b9f`. The existing successful
reference check is dated 2026-10-26 and still within 72 hours.
Fetched preview index: `41c28839bf`, 2026-10-28 11:08;
underlying census: `c8734bec0c`, 2026-10-28 10:03.

The default picker claimed ClassifyBridgeCells (0x00366E2E). Its current
ordinary preview fails solely on the selected `_floorf`. A bounded sweep
found the same sole blocker in PathfinderNewMap.cpp and
PathfinderBridgeUpdateRva0052ED74.cpp; both file scopes were claimed.
The object-footprint classifier has the same lead, but its claim was
unconfirmed and it was left unchanged. The globally selected wrong provider,
Render2DSentenceDrawBFME2.cpp, belongs to another worker and was not edited.

Each edited object emits an unused public 18-byte `_floorf` wrapper,
digest `d9d07276ff39`. No code COMDAT in these objects calls that symbol;
inlined conversions call `__imp__floor` directly. Following mapper.cpp and
the verified terrain-projection repair, give the math-header inline internal
linkage. This preserves the arithmetic and removes the public helper copy.
No row, pin, layout, compiler flag, source path or shared header changes.

[Before/after object receipts](pathfinder-inline-floor-object-20261028-codexb4.json)
show exactly one removed external COMDAT per source (`_floorf`), no added
external symbols, and unchanged external dependencies and weak aliases.
All 14, six and 21 retained external COMDAT byte-and-relocation digests,
respectively, are identical.

Verification:

- Normal `./build.sh` verifies all six edited-source rows and the two
  bridge-neighbor data rows. Float and import checks pass.
- `find_declared_unmatched.py` passes before and after for all three sources;
  NewMap's EH graph is EXACT. Its renumbered funclet label is verified through
  the real parent graph without changing the ledger.
- `link_check.py --prepare-current` verifies the three sources together with
  the existing TerrainLogicAmbientColorRva0027DA6A.cpp `_floorf` owner:
  eight function rows, two data rows, 30 float literals and 15 imports.
  All four objects have strict reusable receipts.
- Same-index ordinary preview changes all three consumers from blocked to
  LINKS: ClassifyBridgeCells 1,338, bridge update 2,431, NewMap 580 authored
  nonpadding bytes (4,349 total). The separate `_floorf` owner still reports
  the global selected-copy blocker. These are previews, not census gains.
- CSV and diff checks pass. The staged-tree batch audit exits 2,
  INCONCLUSIVE: the index predates the base and affected consumer
  Common/0CreateAHeroManager21FE49.cpp lacks a current receipt.

Carry the removed-helper scope and affected consumers into the next normal
census. This clears only the three consumers in ordinary preview; it does not
clear LINK-133 globally, prove full consumer selection, or change measured
linked coverage, image ownership, debt or runtime results.
