# Color-picker inline floor linkage

Base: `cea5d968c5`; BFME 1 reference freshness receipt: 2026-10-26,
verified `001ccd8e27686e9887235b62ff797627f2dde7f5`. Published preview index:
`41c28839bf` (2026-10-28 11:08), underlying census `c8734bec0c`.
The default picker claimed 0x0004D754 and its color-picker source.

The prior 2026-10-19 repair removed the public WWMath::Floor copy. The
current source still emits math.h's unused external `_floorf`, and its
ordinary preview fails solely because the globally selected copy is not
retail's. The runtime relocation graph has no incoming `_floorf` reference:
the color-picker operations inline and call `__imp__floor` directly.
This is the existing LINK-132/LINK-133 selection issue, not a lost code row.

Declare `floorf` static with C linkage before the includes, following the
verified terrain/pathfinder repair. The inline operation and compiler flags
stay the same. The [object receipt](color-picker-floor-object-20261028-codexb.json)
shows only `_floorf` removed: all 29 retained external COMDAT byte/relocation
fingerprints, exclusive definitions, unresolved externals, weak aliases,
runtime roots and retained reference edges are unchanged. The receipt's
COMDAT verdicts are deliberately unassessed; equality is the comparison here,
while the normal build and preview provide retail/link verification.

Checks:

- Normal build: 14/14 function rows exact; ten strings, four empty-string
  references, four float literals and eight named imports verified.
- Both complete EH graphs are EXACT. Frozen-file checks pass before/after;
  class gate and diff whitespace checks pass.
- Strict preparation of the changed source and existing retail `_floorf`
  owner, TerrainLogicAmbientColorRva0027DA6A.cpp: 16/16 rows exact, two reusable
  receipts. The owner is unchanged and still supplies its retail 18-byte row.
- Same-index ordinary preview: color picker changes from blocked to LINKS,
  0 -> 1,660 authored bytes. Paired preview preserves that result; the
  unchanged retail floor owner retains its global selected-copy blocker.
- Scoped data check retains the existing shadow wrong-name reference
  `?TheRva00222A8BTarget@@3PAVRva00222A8BTarget@@A` at 0x009FE4CC. Its source
  declaration and all external object bindings are unchanged. No data debt
  retirement or global identity repair is claimed.
- Outgoing staged batch audit: INCONCLUSIVE (exit 2). The index predates the
  base and affected consumer Common/0CreateAHeroManager21FE49.cpp lacks a
  current receipt. Carry this removed-copy scope and consumer into the next
  scheduled census; full external selected-consumer coverage is unverified.

No ledger, pin, shared header or source path changes. This clears the scoped
preview only; no new census-linked bytes, runtime or image-ownership gain is
claimed. Scratch objects and comparison script: build/color-picker-link-20261028/.
