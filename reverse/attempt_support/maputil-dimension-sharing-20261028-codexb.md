# MapUtil dimension sharing: rejected source trials

Inspected `9bc910b28f` on 2026-10-28. Claimed
`file:Code/GameEngine/Source/GameClient/MapUtil.cpp`. No source change is retained.

## Target facts

`?getExtent@@YAXPAURegion3D@@@Z`, RVA `0x003000B5`, is already matched
(65 bytes) in `Code/GameEngine/Source/GameClient/MapUtil.cpp`. This is data
ownership cleanup, not recovery of an unrowed function. The file defines static
`m_mapDX` and `m_mapDY`. The separate
`MapUtil_unk_YA_NAAVDataChunkInput_PAUDataChunkInfo_PAX_Z.cpp` defines external
C-linkage dimensions and owns their data rows at VAs `0x00DFF124`/`0x00DFF128`.

`repair_queue.py retire data Code/GameEngine/Source/GameClient/MapUtil.cpp`
refuses retirement on the dimension duplicates. The four registered supply/tech
position keys remain untouched. The earlier data-retirement log already records
that simply making the dimensions external breaks getExtent; this pass tested
source scheduling and local staging as possible ways around that boundary.

## Rejected hypotheses

Every trial used `./build.sh`, with the original saved and restored between
variants. Each failed only getExtent: the other 18 MapUtil rows remained exact.

| Dimension linkage and body | Observed result |
| --- | --- |
| External C declarations, original body | 65 bytes; low-bound zero stores move before dimension reads. |
| External C declarations, write hi.x first, stage scaled DY in a Real, then write the low bounds and hi.y | 65 bytes; XMM allocation and scheduling differ. |
| External C definitions, original body | Same mismatch as external declarations; merely keeping definitions visible does not restore the static case. |
| External C declarations, original assignments into a local Region3D followed by aggregate assignment | 117 bytes; introduces a 24-byte stack temporary and scalar copies. |

The retail body takes the output pointer in EAX. Its instruction order is:
load scale into XMM1; convert DX into XMM2; zero XMM0; multiply and store hi.x;
convert/multiply DY in XMM2; store lo.x and lo.y from XMM0; store hi.y from XMM2;
store lo.z and hi.z from XMM0; return. Scale is at VA `0x00BC2428`.
The explicit-order trial instead uses XMM0 for the dimension conversions and
XMM1 for the later zero stores. Matching the arithmetic or length is insufficient.
These outcomes support an alias-analysis/code-scheduling explanation, not a
newly established retail type or donor layout.

## Restoration and current boundaries

After restoring the original source:

- `./build.sh Code/GameEngine/Source/GameClient/MapUtil.cpp Code/GameEngine/Source/GameClient/MapUtil_unk_YA_NAAVDataChunkInput_PAUDataChunkInfo_PAX_Z.cpp`:
  21/21 function rows and both data rows verified; string, float and import checks pass.
- `find_declared_unmatched.py` reports all defined functions already matched.
- Paired `link_check.py` against the fetched 2026-10-28 11:08 index
  `41c28839bf` retains MapUtil at 0 linked bytes and the provider at 164:
  1/2 units link. MapUtil has 14 unresolved names, five COMDAT disagreements
  and five selected-copy disagreements. This is an ordinary preview, not a
  census measurement or strict closure receipt.
- `name_lane.py consolidate --under Code/GameEngine/Source/GameClient/`
  reports mixed routing, private definitions and stale committed TU mapping.
  `tu_skeleton.py --plan Code/GameEngine/Source/GameClient/MapUtil.cpp`
  (which rebuilds stale mapping in memory) lists 123 approved rows, 15 donor
  files and 13 mixed files. Neither getExtent nor the dimensions provider is
  in that plan. No merge was attempted and no TU assignment was changed.

The next pass needs target-supported TU/ownership evidence for these two bodies
and a shared-dimension implementation that preserves getExtent's exact codegen.
The earlier suggestion to merge the provider into MapUtil is not current merge
authorization. The unresolved stream, map, string, Dict, file-system and parser
interfaces remain separate link prerequisites. No debt, source-file count or
linked-byte gain is claimed.

Local reproducibility logs (scratch, not durable evidence):
`build/codexb-maputil-{extern,order,def,bounds,restored,preview,plan}.log`.
