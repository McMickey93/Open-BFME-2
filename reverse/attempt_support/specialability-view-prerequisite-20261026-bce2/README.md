# SpecialAbilityUpdate consolidation prerequisite

Base inspected: `c41b1ad5660`. Published preview index: `5ce093a71a`,
2026-10-26 19:02. Selected scope: SpecialAbilityUpdate.cpp and twelve donors
under `Code/GameEngine/Source/GameLogic/Object/Update/`.

The normal planner and `tu_skeleton.py --plan` retain 72 approved rows, thirteen
whole-file candidates including the seed, and seven mixed files which stay put.
The committed TU map is stale; the merge tool rebuilds its assignments in memory.
The planner's stale-map routing hints are not treated as approval.

The first supported non-applying merge rejects every donor. Its diagnostics
include incompatible private views, missing members and declaration ordering;
the destructor donor also fails byte verification. That first trial applied no merge.

## Verified field-view repair

The 98-byte predicate at 0x0044EECA reads `Overridable` fields at +0x1C and +0x20.
The seed already uses +0x1C and +0x44, but represented +0x20 through +0x43 as
padding. Give both existing private views the same declaration: `m_val20` at
+0x20, padding starting +0x24, and the existing `m_evaEvent44` at +0x44. The seed's
size and existing offsets are unchanged; the donor never constructs this view.
No canonical class copy, name, pin, flag or function-body change is introduced.

Before and after normal builds verify all 27 rows in the two files, four string
literals, one empty-string reference and thirteen float literals. After the edit,
all five parent EH graphs are EXACT. Five compiler-local funclets renumber;
the normal parent-EH proof resolves them without a ledger or pin edit.
Paired ordinary link previews preserve both clean files and 6,057 authored bytes
(5,959 in the seed, 98 in the donor). No linking gain is claimed.

## Existing shadow findings

The identity scanner reports `uw_00789b5b` calling `??1DrawableList@@QAE@XZ`
at retail 0x00239BAB, while that symbol owns 0x00239AF4. The native 0x00239BAB
five-byte forwarding destructor has a distinct existing owner. A control build
with only our seed declaration edit reversed reproduces the finding. Both scans
classify 189 references identically, and all fourteen detailed non-owner,
non-EH report rows are identical to the edited build. This is inherited
identity work, not classified here as a verifier false reject or silently retired.

The seed also retains two shadow data-name findings at 0x00A033A0 and 0x00A033A8.
A read-only check of the claimed PoolKey donor reports two current data-name
findings; its old baseline key must not be counted as fixed merely because the
function was renamed. No data or identity key is removed.

Detailed before/after builds, EH and link results, identity control and dry-run
diagnostics accompany this handoff. The refreshed planner stays in
`build/consolidation/turn78-special/`; no regenerated TU map is committed.

## Composition follow-up

The second supported dry run accepts the seed and the predicate donor after
the field-view prerequisite. Its census-linked guard accepts that composition.
The other eleven whole-file donors remain rejected: ModuleData needs its
custom-animation field; Slot8 and PoolKey need their member declarations; the
range methods need the AIUpdateInterface view; Xfer, the object-return helper,
InitiateIntent and TriggerAbilityEffect have declaration-order conflicts;
Rva00451EACMethod needs KIND_81 and the facing method; Rva0044EF5EFinish still
fails compilation; and the destructor still fails bytes. Mixed files stay put.
The complete second-trial diagnostics are in `dry-run-after.txt`.

The applying merge accepts the same pair and deletes one source file. It
repoints only the predicate's source in functions.csv and tu_map.csv (no map
regeneration), and refreshes the seed's unchanged Microsoft-header queue row.
The merge tool reports 26 approved addresses; the normal build checks all 27
ledger rows in the resulting source. All five EH graphs remain EXACT.

`link_check.py --prepare-current` verifies those rows and produces a strict
reusable receipt. The ordinary one-source preview still includes the historical
donor object and therefore reports a duplicate predicate. The read-only
`check_composition.py` uses the batch-audit overlay with the current seed object
and the now-unrowed, deleted donor retired. Every blocker list is empty, including
duplicates, selected copies, unresolved references and addresses. The predicate's
two calls still bind to the existing Overridable owner at 0x00288609. This is
bounded preview evidence against the 19:02 index, not a new census measurement.

The merged identity scan classifies 191 references: 172 owner, 11 alias, five EH,
two fold and the one inherited wrong binding. Its fourteen detailed report rows
are unchanged; the extra two owner bindings are the moved predicate's calls.
The same two static-guard data-name findings remain. No protected debt key,
fold-proof token, hatch or data identity moves or retires in this composition;
neither absorbed donor nor destination has a registered header-adoption row.

## Outgoing path-consumer audit

Scope: base c41b1ad5660 through the prerequisite and this one-donor merge.
Searching the tracked tree by the old path and basename finds only the source's
provenance comment, two historical attempt reports and the historical census
row in link_status.csv. These stay historical. No active tool, hook, workflow,
include, build configuration or fold proof consumes the removed file; no
directory is moved. The ledger and TU-map source cells now name the destination.
Header and Microsoft-header queues were processed by the merge tool; the latter
keeps the same classification. The complete normal pre-push batch audit remains
the final publication check, with any since-index uncertainty carried forward.

## Publication resume, 2026-10-27

The first push passed its normal gate (65 rows across four sources, nine exact
EH graphs), but master advanced before Git accepted it. The dependent scope
included Eva.cpp, ThreadClassLifecycle.cpp and thread.cpp. Their normal byte
checks passed; `link_check.py --prepare-current` cannot produce strict reusable
receipts because their include inventories contain macro or parent-traversing
includes with unknown search roots. The batch provider audit was inconclusive
for those three inputs. This is an input-evidence limitation, not a demonstrated
linking regression; no cache receipt or verifier exception was fabricated.

The resumed rebase onto 2b9fe3b6840 retains upstream's `<string.h>` adoption in
SpecialAbilityUpdate.cpp. Its queue conflict is resolved using the owning
scanner: refreshing the destination and removing the absorbed donor exactly
reproduces upstream's queue, with every unrelated row preserved.

The local BFME 1 freshness receipt had expired. An official-master fetch found
a0940f921b5b8d9029fc922b8032abcf4e60d240; BFME 2 currently pins the separately
verified 4fa9d591641a743b86f2320343b7a276585b814b. The update claim is held by
yasinschroeder-codex, so this publication keeps the verified pin and leaves the
local success stamp unchanged. The failed claim and official revision check
are the update blocker; the check must be repeated on a later work session.

The rebased source passes all 27 normal byte rows, five exact EH graphs, four
string literals plus one empty-string reference and thirteen float literals.
Its strict receipt is refreshed. Against the newly fetched 2026-10-27 00:39
index at bf3dd31211, the current-object composition with the deleted donor
retired again has no blockers in any reported category; both moved calls still
bind to the same existing owner. The current in-memory TU plan still approves
0x0044EECA in SpecialAbilityUpdate.cpp. A repeated old-basename search finds
only provenance, this handoff and historical census/attempt evidence. No active
path consumer requires a repair. The attached resume logs record these checks.
