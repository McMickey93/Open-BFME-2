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

## Post-rebase checks and data-retirement boundary

Publication rebased the queued batch onto `00531d7c2f`. An older queued E038
retirement conflicted with upstream's broader retirement: all six original
deleted keys were already absent upstream. The resolution preserves that
absence and adds no baseline key or new retirement. CritterEmitter's seven
rows remain approved in the refreshed map. Its merge is `e34bb74f39` after
rebase; the normal paired build again passes 8/8 rows and `check_csv.py` passes.
The complete outgoing range has no other source-path move.

The merge's normal pre-commit hook passes with zero new code-identity findings,
two EXACT EH graphs, eight exact function rows and zero enforced converged-data
collisions. Its shadow data scan finds two wrong-name keys: the local guard
at `0x00A04318` and cached key at `0x00A04314` now use the already-recovered
`getModuleNameKey` mangling, while their data-index entries retain the older
`rva0004C8D41` identities (the guard also has an external clearer definition).
These are preserved input identities, not new definitions from composition.
After the merge, `repair_queue.py retire data` refuses because both current
findings fall outside the carried old-name key. It changes nothing. A separate
data-identity repair must reconcile the current owners and shared clearer
before the owning tool can retire the remaining baseline key; no key is added
or hand-deleted here.

## Publication reconciliation with the module pool-key refresh

A further publication rebase onto `22ec257aa5` encountered the upstream
module pool-key refresh. That refresh already corrected CritterEmitter's key
and guard identities and retired its old guard key. The conflict resolution
preserves those current `getModuleNameKey` names, owned status, one definition
and relocation counts; both generated data-index rows (`0x00A04314` and
`0x00A04318`) now name the merged TU. No baseline key is reintroduced or
retired again. The earlier data-retirement boundary above describes the
previous inspected control and is superseded in this scope.

At `b0238684f4`, enforced data checks pass for the merged TU and six E036
containment accessors (seven sources, zero findings). EH verification reports
eight EXACT graphs across this scope; the merged TU accounts for two.
`tu_ownership.py --commit dc5bb034e4 --shadow` passes without findings.

The complete source-path batch is unchanged: the two CritterEmitter donors
are the only deleted source paths from `22ec257aa5..b0238684f4`. A combined
full-path/basename audit across tools, hooks, workflows, Code, documentation
and registers finds no active executable, include or build-list consumer
requiring a change. The data index, function ledger and TU map name the merged
TU. Remaining donor mentions are the provenance comments, historical
attempt/deleted-row/census records, and the PartTheHeavens comparison comment
previously classified above. The new upstream module-pool-key handoff is also
historical evidence and retains its inspected source paths. This audit does
not clear the existing strict batch-audit or census prerequisites.

## Completed full-gate control after conflict resolution

`BUILD_POOL=12 ./build.sh` at `b0238684f4` completed with actual exit **1**.
It passed 98,941/98,941 function rows across 22,248 sources, 31,537 string
literals plus 2,253 empty-string references, 9,117 float literals, 6,423 named
imports, pin consistency, module registration, all 22,075 source claims,
2,201 byte-verified data rows and the no-op patch. The sole red check is
DIR32 consistency, with these two unresolved vtable identities:

| Symbol | Conflicting table VAs |
| --- | --- |
| `??_7Rva003F498ACallback@@6B@` | `0x00C1C780`, `0x00C37080` |
| `??_7Rva0056224F@@6B@` | `0x00BBB554`, `0x00C1D358` |

Both exact pairs already appear in upstream's
[2026-10-27 native control](particle-info-base-link-20261027/native-run-conflicts.txt).
The outgoing batch changes neither Rva003F6A91Dtor.cpp nor Rva0056224FCtor.cpp,
nor the callback's RvaSmallVtableCtors.cpp/VslotSmallBodiesL.cpp providers,
`tools/build.py` or the DIR32 whitelist relative to `22ec257aa5`. The reported
class symbols and their relevant lifetime rows/pins have no outgoing changes.
The full control therefore confirms the previously recorded boundary; it is
not a green full gate. The LivingWorld callback needs coherent two-slot
visitor/provider identities (see the 0x003F6A91 and 0x005FED52 handoffs in
re_attempts.log). The particle info family needs its complete Snapshot and
secondary-table contracts, as documented in the
[existing bounded attempt](particle-info-base-link-20261027/readme.md).
No production-source or verifier change is made for either obstacle here.
