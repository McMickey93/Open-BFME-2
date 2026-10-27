# RemoveUpgrade destructor: canonical Snapshot adoption

Inspected BFME 2 revision: `a5bffaa9a98c1c653957d691950ddd5651d67c49`.
Date: 2026-10-27. Source:
`Code/GameEngine/Source/GameLogic/Object/Update/RemoveUpgradeUpgradeModuleDataDtor.cpp`.

## Evidence and scope

The earlier `Snapshot-header-RemoveUpgradeUpgradeModuleDataDtor` trial replaced
a private Snapshot containing 0x114 bytes of opaque payload with the four-byte
canonical Snapshot, moving both vectors. That layout change caused its failure.
The payload is not part of engine Snapshot. The existing constructor view and
native constructor at 0x004B7FF1 place the end of the inherited storage at
+0x118, the two vectors at +0x118 and +0x124, and the flags at +0x130/+0x131.
The native destructor at 0x004B8050..0x004B8095 destroys those vectors and then
inlines the Snapshot vtable restore, with no other base destructor call.

Include the registered Snapshot header and retain the inherited storage as an
explicit opaque prefix in this destructor-only derived view, as the existing
CivilianSpawnCollide and ModelConditionSoundSelector destructor views already
do for their inherited storage. Its comment identifies the prefix as inherited
storage, not recovered derived fields. This removes the false oversized
Snapshot definition without claiming recovery of the intermediate ModuleData
hierarchy or its fields. No donor facts or donor source were needed.

## Verification

Normal `./build.sh` builds pass all four rows before and after; the destructor
is 69 bytes and the rows total 79 bytes. Both funclets remain verified through
the parent EH data despite local label renumbering. `eh_verify.py` reports one
EXACT graph, and `find_declared_unmatched.py` is clean. Shadow `data_check.py`
reports zero findings. The shared header and all ledgers of code/data identity
remain unchanged.

`link_census._comdat_sections`, `build.read_object_symbols` and
`link_census.object_references` produce identical complete COMDAT, external
definition, root-reference and discardable-edge facts before and after:

| COMDAT | Size | Byte-and-relocation digest, both builds |
| --- | ---: | --- |
| `??1RemoveUpgradeUpgradeModuleData@@UAE@XZ` | 69 | `8e2129c90804` |
| `??1Snapshot@@UAE@XZ` | 7 | `c88b6d4dab56` |
| `??_7Snapshot@@6B@` | 16 | `a72f3681fb3a` |
| `??_GSnapshot@@UAEPAXI@Z` | 29 | `4bd655b2fdee` |

The canonical Snapshot table and destructor therefore replace identical
existing emissions; no new helper, table, body or reference is introduced.
Local object snapshots and full fact JSON are in
`build/removeupgrade-snapshot-20261027/`.

`header_adopt_lane.py accept --class Snapshot` passes and retires exactly one
queue row. The paired ordinary `link_check.py` preview with
RemoveUpgradeUpgradeModuleDataCtor.cpp reports LINKS for both: 79 and 95 authored
bytes, unchanged, using index `bf3dd31211` (2026-10-27 00:39, retail-truth-4).
This retires header debt in an already linked unit. No new census-linked byte,
closed-strict, image-ownership or complete class-layout claim is made.

## Other picker scope

The default picker assigned Snapshot, led by LivingWorldBattleCtor.cpp. The
remaining ten queue entries were inspected against the prior recorded verdicts
and LINK-098. No unchanged failed trial was repeated. The constructor-vptr,
nested allocator-name collision, Xfer access, Money identity and FX-interface
prerequisites remain with their existing evidence. Only the RemoveUpgrade
layout issue above was changed.
