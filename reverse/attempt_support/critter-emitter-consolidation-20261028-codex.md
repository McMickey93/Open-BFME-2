# CritterEmitter consolidation, 2026-10-28

Inspected base: `248318c9e2`. Owner: `yasinschroeder-codex`.

## Scope and placement

`next_work.py --claim` selected the CritterEmitterUpdate TU. The supported
`name_lane.py consolidate --under Code/GameEngine/Source/GameLogic/Object/Update/`
planner was read before composition. `tu_skeleton.py` rebuilt the stale map in
memory and accepted two donors into the currently approved provisional TU:

- `Code/GameEngine/Source/GameLogic/AI/CritterEmitterUpdatePoolKey.cpp`
- `Code/GameEngine/Source/GameLogic/Object/Update/CritterEmitterUpdateModuleDataDtor.cpp`
- Destination: `Code/GameEngine/Source/GameLogic/Object/Update/CritterEmitterUpdate.cpp`

This reduces source files from 22,340 to 22,339 at this base. All seven rows
retain their identities, extents and matched status: `0x004C8D41`, `0x004C8F49`,
`0x00790491`, `0x0079049E`, `0x007904A8`, `0x007904B0`, `0x007904BB`.
The committed TU map changes only those seven source columns; no placement
decision or regenerated map is committed.

The retail image contains the original path ending in `Update/CritterEmitter.cpp`
(string RVA `0x0085E920`). That target fact does not prove the provisional
destination filename `CritterEmitterUpdate.cpp`. The merge follows current map
approval and makes no stronger source-name recovery claim.

## Verification and bindings

- Before composition, normal `./build.sh` verifies 7/7 rows across both donors.
  Ordinary previews against published index `73061d9452` (2026-10-27 14:34 UTC)
  report LINKS for 69 and 85 authored nonpadding bytes, respectively.
- After composition, normal `./build.sh` verifies the same 7/7 rows. The three
  renumbered unwind labels are resolved through their parents' EH data.
  `eh_verify.py` reports two EXACT parent graphs and no baselined exceptions.
  Frozen-file checks pass before and after; `check_csv.py` passes.
- Before/after COFF inspection with `link_census.comdat_bodies` finds the same
  17 external COMDAT symbols, sizes and byte/relocation digests. The union of
  external definitions and unresolved references is identical. This includes
  the Snapshot vtable/destructors and BfmeE16 vector helpers; composition adds
  no new provider body or external dependency.
- The merge engine's census-linked guard accepts the composition. Admission
  via `link_check.py --new-variants --staged-peers --shadow` reports no finding.
  The ordinary preview cannot judge the destination because its new path is
  absent from the historical census. A complete current-input batch audit and
  later census confirmation remain unclaimed; carry this scope to the next
  normal census. No linked-byte, image-ownership or runtime gain is claimed.
- The constructor donor's location comment is updated; its separate row also
  byte-verifies (1/1). No constructor body or declaration changes.

## Debt, queues and path-consumer audit

The merge tool transfers one data baseline key and two data-ledger path
references. Totals are preserved, with no retirement in this commit. Neither
accepted donor nor destination has a code-identity baseline, header-queue or
Microsoft-header queue entry. `tu_skeleton` runs the owning queue refreshes;
neither queue needs a change. No pin, hatch or fold-proof key is added.

Audited the complete path batch at `248318c9e2` plus this merge and constructor
comment: combined old full paths and basenames were searched across active
tools, hooks, workflows, source/includes, root configuration, registers and
documentation. No executable tooling, build-list or include consumer needs a
change. Active ledger/register paths resolve to the destination. The one live
constructor location comment is corrected. Remaining old-path references are
the merge's donor provenance comments, historical `re_attempts.log` and
`deleted_rows.csv` evidence, prior attempt handoffs, and the census-owned
`link_status.csv`; these are intentionally retained. The nearby
PartTheHeavens destructor's comparison comment names an earlier reconstruction,
not an active source dependency.

## Remaining composition prerequisites

The merge engine rejects the object destructor, constructor thunk, update,
xfer and onCollide donors because their competing private CritterEmitterUpdate
views omit `getModuleNameKey`. The module-data constructor in
`DynamicGeometryInfoUpdateCtor.cpp` fails the merged byte check.
`tu_views.py --dry-run` also identifies differing BehaviorModule bases,
UpdateModuleInterface slot counts, CritterEmitterUpdateIface declarations,
UpdateModule bases and ModuleData class/struct forms. Reconcile those donors
in separately verified prerequisite commits before retrying them.

The three mixed files (ModuleNameGetters3, ModuleDataBuildFieldParse and
UpdateModuleDataDeletingDtors) stay in place. No rejected reconstruction or
temporary trial is left in `Code/`.
