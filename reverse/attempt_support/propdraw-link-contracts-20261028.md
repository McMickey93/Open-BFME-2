# PropDraw linking and consolidation boundary, 2026-10-28

Inspected c64f680554 after the default picker claimed RVA 0x000CEEC0 and
W3DPropDraw.cpp. Read LINK-120 and the earlier cached-key handoff before
investigation. No source, ledger, TU map or provider declaration was changed.

The five seed rows still match. Its ordinary link preview against census
index 14dc3d2467 (2026-10-28 02:44) reports the same three conflicts:
ModuleData's destructor differs from the kept retail copy, while DrawModule's
vftable and deleting destructor differ from the first selected copies.
No linked-byte gain is predicted for this unit.

A fresh name_lane consolidate report for the Draw directory was read before
the ordinary tu_skeleton merge dry-run. The current in-memory TU assignment
plans 15 approved rows, four clean sources and two mixed sources; no stale
committed TU assignment was used as approval. The dry-run accepts no donor:

- PoolKey compiles but LinkGuard refuses loss of its census-linked status
  through the seed's three existing provider conflicts.
- ModuleDataCtor fails because the seed view has no m_distanceFog member.
- React fails on Coord3D redefinition between the imported POD and ctor view.

The three clean donors independently build 8/8 exact, including their data,
string and float checks. Together with the seed this is 13/13 byte-matched
rows, not an accepted composition. The tool removed its temporary trial
sources; no source-path move or source recovery is claimed.

Next work remains a coherent BFME 2 ModuleData/Snapshot/DrawModule contract
with retail slot owners, shared with the ctor unit. Do not copy the short
family table or suppress emission merely to make the unit link. The earlier
cached-key and fog-field evidence remains applicable; no new fog-field or
Coord3D source trial was made. The mixed-source donors were not edited.

LINK-120 retains its history and remains open. No maintainer-only census,
smoke, nightly or shadow publisher was started. This handoff records current
verification and avoids treating an existing view mismatch as a regression.
