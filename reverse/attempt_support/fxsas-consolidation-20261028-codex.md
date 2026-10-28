# FX SAS approved-TU consolidation, 2026-10-28

Inspected source base: `3bfa975ff5`. Owner: `yasinschroeder-codex`.
Destination: `Code/Libraries/Source/WWVegas/WW3D2/FXShaderParameterSourceNamespaceSAS.cpp`.

## Placement and scope

`next_work.py --claim` selected this approved provisional TU and claimed its
destination and 29 clean donor scopes. The supported planner,
`name_lane.py consolidate --under Code/Libraries/Source/WWVegas/WW3D2/`,
was generated and its snapshot check passed before composition. The merger
rebuilt the stale map in memory. Only the 19 moved source-column cells change
in the committed map; assignments and approval evidence are unchanged.

The planner's WorldBuilder path lead is
`Code/Libraries/Source/WWVegas/WW3D2/fxshadernamespacesas.cpp` (string offset
`0x01A01160`). That lead does not prove the BFME 2 filename. The approved
destination remains provisional; its class-based spelling is not presented as
a recovered retail filename. The existing lower-case file is mixed and stays
in place. Skeleton comments for rows held elsewhere earn no progress.

The normal `tu_skeleton.py --merge` preview and application accept 15 donors:

- Common: `Rva0014F9FillN`, `Rva0014F995CopyBackward`,
  `Rva0014FA0DCopyBackward`, `Rva0014FA2AFill`, `Rva0014F674Loop`,
  `Rva0014FA62Copy`, `Rva0014FA90Copy`, `Rva00150248Copy`,
  `Rva00150265Copy`, `Rva00150558Dtor`,
  `FamilyDeletingDtors_Rva0015058E` (all `.cpp`).
- WWLib: `Rva00150A77VectorInsert.cpp`, `Rva00150A7CVectorInsert.cpp`,
  `Rva00150A81VectorInsert.cpp`, `Rva00150A86VectorInsert.cpp`.

They become one source file: **14 fewer source files**, with the same 19 rows
and 518 authored bytes. No name, extent, status or notes change. A narrow
ledger comparison confirms exactly one row per moved address.

## Verification and object bindings

- All candidate source files pass `find_declared_unmatched.py` before the
  merge. The destination passes afterward, retaining its existing exemptions.
- `./build.sh` verifies **19/19** rows, with no string, float or named-import
  references to judge. `eh_verify.py` verifies the one EH row **EXACT**.
- `check_csv.py` passes (98,941 function rows, 9,420 symbols, 2,201 data rows).
  Shadow data checking reports zero findings; enforced converged checking
  judges 11 addresses with no second names or unjudged rows.
- The merge-selected compiler settings preserve all **23 external COMDAT
  symbol/size/byte-and-relocation digests**, all **16 strong definitions**,
  the one weak alias, and the same **19 external dependencies**. There is no
  new or removed external definition or common definition. The comparison uses
  the merger's verified donor objects and the destination's ordinary build
  object; it performs no private compile into the shared match cache.
- The merge engine's census-linked guard accepts the composition. The
  destination passes `link_check.py --new-variants --staged`.
  Ordinary preview cannot judge this new source because it is not yet in the
  census; it is not reported as a link gain.
- `progress.py` reports BYTE-MATCHED 100%, unchanged matched bytes, and
  SOURCE FILES 22,296 (-14 versus the source base). Census figures remain
  unchanged; no image-ownership or runtime result is claimed.

The complete outgoing batch link audit is **INCONCLUSIVE**: its published index
at `14dc3d2467` differs from the outgoing base and lacks per-object consumer
names. The committed census history still names `73061d9452`. Full outgoing
consumer/selected-provider confirmation remains for the next normal census.
The local composition guard and unchanged object inventory are bounded
evidence, not a substitute for that census.

Scratch receipts: `build/fxsas-merge.log`, `fxsas-build.log`,
`fxsas-before-objects.json`, `fxsas-object-comparison.json`,
`fxsas-new-variants.log`, `fxsas-link-batch.log`, `fxsas-progress.log`.

## Registers, queues and full outgoing path audit

The absorbed donors own no code-identity or data-baseline keys, data-ledger
ownership, flag override, canonical-header queue key or fold proof. The merger
refreshes the header queues and transfers the placement-new Microsoft-header
entry from `Rva0014F9FillN.cpp` to the destination, preserving its unverified
status. Its `reaches_code` field changes from no to yes in the combined TU.
The existing inline-base-destructor `present_unmatched` hatch moves from
`Rva00150558Dtor.cpp` with its count kept. No debt is retired. The global hatch
updater also dropped 13 unrelated stale GameLOD register keys; those existing
keys were restored, leaving only the supported donor-to-TU transfer staged.
The staged hatch check passes. TU ownership reports only the diagnostic
two-int `Rva0014F718`/`ICoord2D` fingerprint similarity.

The audited outgoing range is `4b5c353408..3bfa975ff5` plus this staged merge.
It includes all 16 deleted donors: these 15 and the earlier NAT predicate
absorption. One combined full-path/basename search covers tracked tools,
hooks, workflows, source/header includes, root build/configuration files,
registries and documentation. No executable path consumer or include needs
an update. No directory moves, so directory-based scans and globs retain
their meaning. Active function/map/queue/hatch owners resolve to the new TU.

Remaining old-path mentions are intentional: 16 census-owned link-status rows;
donor provenance in NAT.cpp and the new TU; two explanatory source comments
about the existing base view; historical attempt packets and re_attempts.log.
Those records are not rewritten. This handoff adds historical references only.
Raw combined search: `build/fxsas-path-audit.txt`.

## Remaining composition prerequisites

Fourteen clean donors are left untouched. The overflow views at 0x0014F480,
0x0014F4A1 and 0x0014F4C2 disagree with the retained base declarations;
the first loses bytes and the latter two fail declaration ordering. The
0x0015068C finish and 0x00150558 deleting-dtor family lose bytes.
The three W5 fill-insert units and four indexed-vector units collide on
`_STL::__false_type` and other private declarations. The 0x00150959 insert
needs compatible visible types, and the 0x00150B8D family conflicts on the
0x0014F480 vftable's modifiers. `tu_views.py --dry-run` also identifies
base-clause, novtable and overlapping-vector-field differences. Reconcile a
bounded donor in its own verified prerequisite before another merge.

Eight mixed sources remain intact: GapBodiesGE45, Rva0014F3E7Destroy,
Rva0015058EDtor, Rva001505CDDtor, RvaVectorDtorFamily,
fxshadernamespacesas, StlportVectorEraseRangeDeferred and
VectorOverflowRva001504A1. No generated source is edited and no failed
reconstruction is left under Code/.
