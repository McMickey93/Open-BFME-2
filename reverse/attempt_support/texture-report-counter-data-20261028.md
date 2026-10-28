# Texture reporting counter ownership

2026-10-28; control revision `c5dcd40bdf09359d5c5650981d63c7694927b154`.
Both source scopes were claimed before editing.

The earlier whole-family attempt in
[the current-frame handoff](texture-current-frame-data-20261027.md) established
that externalizing the recording function's two remaining counters changes its
load ordering. This repair limits sharing to the reset owner and reporting
consumer; the recording function's separate registered duplicates remain.

The existing provisional data ledger places `_record_count` at RVA `009EE8B4`
and `_texture_change_count` at `009EE888`, both owned by
`Code/Libraries/Source/WWVegas/WW3D2/TextureStatisticsVector.cpp`.
Give those existing four-byte definitions external C linkage and replace the
reporting unit's two private definitions with declarations. C linkage preserves
the existing COFF names. This is a target binding repair, with no new claim
about donor names, layout or original translation-unit membership.

## Verification

- Normal `./build.sh` passes all 21 rows across TextureStatisticsVector.cpp and
  DebugStatisticsRecordTextureEnd.cpp; both declared-unmatched checks pass.
- Saved control objects versus final objects retain all 38 executable sections
  (26 reset, 12 reporting), including compiler-generated code, with identical
  raw bytes, symbolic relocation tuples and code-symbol linkage. The owner's
  two counters change from static definitions to external definitions at the
  same object offsets. The reporting counters become undefined externals.
- Both EH graphs are EXACT. Enforced converged-data checking covers ten
  addresses with zero second names and zero unjudged rows.
- `repair_queue.py retire data` removes exactly two reporting duplicate-def
  keys. Enforced data checking finds seven remaining keys across the two
  sources, all already registered. No protected key is removed by hand.
- Ledger validation passes. No function, initializer, lifetime object, pin,
  name or source path is added, removed or repointed.
- `link_check.py --prepare-current` verifies both explicit sources and produces
  strict reusable receipts. Ordinary current-object previews both report LINKS,
  preserving the census's combined 1,728 authored bytes.

Ordinary link previews use census index `73061d9452` (2026-10-27 14:34).
The existing census records 1,006 reporting and 722 reset authored bytes as
linked. No new census-linked-byte, image-ownership or runtime gain is claimed.
The index predates the control revision; outgoing batch verification and the
next normal maintainer census still own wider provider/selection conclusions.

Remaining prerequisites are the recording function's alias/load contract,
reporting-mode scheduling, and vector/handle/string storage extent and
initializer/teardown ownership. The reporting unit retains four data keys and
the reset unit retains three. This repair does not close the statistics family.
