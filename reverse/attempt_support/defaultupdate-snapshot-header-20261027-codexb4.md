# DefaultUpdateModuleInfo transfer unit: canonical Snapshot adoption

Inspected BFME 2 revision: `a2285825383df225eab344f8814da897c376dddb`.
Date: 2026-10-27. Scope:
`Code/GameEngine/Source/GameClient/System/FXParticleSystem/DefaultUpdateModuleInfoXfer.cpp`.

## Repair and evidence boundaries

The prior `Snapshot-header-DefaultUpdateModuleInfoXfer` verdict (re_attempts.log)
failed because removing the local base made the embedded info abstract. The
local base supplied non-pure slots that the canonical base declares pure.

Use the registered Snapshot header, its existing name-slot and non-const getter
switches, and declaration-only overrides in DefaultUpdateModuleInfo. This
completes the embedded class's contract without defining any additional body.
The getter signature is independently named by the retail export at 0x003A6133;
the other exported slots are LoadPostProcess at 0x000B3FD0 and DoXfer(Xfer&) at
0x0055F67C. This unit retains its existing lower-case load/transfer compatibility
surface and pointer transfer signature; no export rename or complete FX-family
interface reconciliation is claimed. The canonical header already supports that
compatibility surface. The existing transfer reads and layout stay unchanged.
No donor source or donor placement was used for this change.

## Verification

`./build.sh` passes all four rows (357 bytes) both before and after. String,
float and import checks pass. `find_declared_unmatched.py` is clean.
`header_adopt_lane.py accept --class Snapshot` passes and retires exactly this
source's one queue entry; no header or class exception is added.

A controlled before/after verification used only normal `./build.sh` builds.
`link_census._comdat_sections`, `build.read_object_symbols` and
`link_census.object_references` give identical facts for both objects:

| Body | Size | Byte-and-relocation digest (both) |
| --- | ---: | --- |
| `?rva0055F710@Rva0055F710@@UAEXPAVXfer@@@Z` | 28 | `36239395df36` |
| `?rva0055F805@Rva0055F805@@UAEXPAVXfer@@@Z` | 28 | `a73803fab00e` |
| `?xfer@DefaultUpdateModuleInfo@FXParticleSystem@@UAEXPAVXfer@@@Z` | 148 | `6bb24609c189` |
| `?xfer@Rva0055F76C@@UAEXPAVXfer@@@Z` | 153 | `0eda6387776d` |

These are also the complete four external definitions in each object. There
is no emitted Snapshot/info vtable, constructor, destructor or new slot body.
The root references are identical (there are no discardable reference edges):

- `?Version1@Xfer@@QAEXXZ`
- `?XferRotationType@@YAXPAVXfer@@PAH@Z`
- `?xfer@DefaultUpdateModuleInfo@FXParticleSystem@@UAEXPAVXfer@@@Z`
- `?xfer@Rva0055F76C@@UAEXPAVXfer@@@Z`
- `?xferRandomVariable@@YAAAVXfer@@AAV1@AAVGameClientRandomVariable@@@Z`

Raw normal-build logs, source snapshots and object-fact JSON are retained locally
under `build/defaultupdate-snapshot-20261027/`.

Ordinary `link_check.py` against index `bf3dd31211` (2026-10-27 00:39,
retail-truth-4) reports LINKS, 357 -> 357 authored bytes. This is one header-debt
retirement in an already census-linked file, with no new linked-byte, C++
conversion, closed-strict or ownership claim. The other Snapshot queue entries
retain their existing prerequisites in LINK-098.

## Initial picker lead

ProductionUpdate.cpp was served first. Normal verification passes 14/14 rows,
and its paired ordinary preview with stlport_construct_stl_types.cpp gives
LINKS (1,101 and 1,791 authored bytes). The upstream `ddc2f5a284` repair already
accounts for this result; no source trial or new linking gain was made there.
Its claim was released. The placeholder row-name follow-up remains LINK-111.
