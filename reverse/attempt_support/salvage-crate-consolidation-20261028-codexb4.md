# SalvageCrateCollide composition, 2026-10-28

Seat: yasinschroeder-codexb4. Inspected base: `6083bb742d`.
Destination: `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/SalvageCrateCollide.cpp`.

## Routing and prerequisite

The default picker claimed the destination, constructor, key getter and
HealCrateCollideXfer.cpp. The scoped `name_lane.py consolidate` report was
reviewed, including original-path evidence, alternatives, private-view and
compiler-setting blockers. The committed TU map is stale; the supported
`tu_skeleton.py` plan rebuilds current assignments in memory. It approves the
Salvage key getter and its two EH rows, and the kept xfer body at 0x004BD2F9,
for this destination. The xfer source's Heal spelling is an existing fold,
not a second retail body. Two mixed sources stay outside composition.

The first supported dry run rejects all three donors: the seed lacks the
constructor, getModuleNameKey and xfer declarations. `tu_views.py --dry-run`
reports conflicting base clauses for CrateCollide and SalvageCrateCollide.
The constructor's explicit vptr stores and the transfer source's multiple
inheritance view need separate reconciliation; they are not evidence for
replacing the behavior unit's working layout.

The prerequisite adds only the existing key-getter and xfer declarations to
the behavior view, plus the key donor's enum spelling and an Xfer forward
declaration. The signatures and access come from the existing matched rows;
no new identity, provider or vtable body is introduced. The constructor is
left unchanged.

Before the change, all four original sources pass strict receipt preparation:
19/19 function rows and five string references. Original objects are saved
under build/salvage-before. After the prerequisite, the behavior unit passes
13/13 rows, four string references and both EXACT EH graphs. Its 31 external
COMDAT byte-and-symbolic-relocation fingerprints, all 31 external definitions
and all 39 external references equal the original object. The frozen-file
check passes.

Ordinary previews before and after the prerequisite preserve LINKS for all
three candidate inputs: behavior 876, transfer 27 and key getter 79 authored
bytes, 982 total. The index is `41c28839bf` (2026-10-28 11:08), older than the
inspected base. These are bounded previews, not new census-linked bytes.

The second supported dry run accepts the behavior unit, key getter and
transfer source, with its census-linked-input guard passing. It still rejects
the constructor for the missing constructor declaration. It reports 17
approved rows in the composed unit; its input files also carry the existing
Heal transfer fold alias. Data identity reports no findings, and converged
data enforcement checks 11 addresses with no second names or unjudged rows.

## Applied composition and verification

The declaration prerequisite is committed separately as `ca11d97fcb`. After
the runner's publication rebase onto `dc5bd70524`, the refreshed scoped
planner was reviewed again. The supported merge accepts the behavior unit,
key getter and transfer source, removing two net source files. It rejects the
constructor and leaves both mixed sources untouched. The five function-ledger
cells (including the existing Heal fold), four TU-map source cells and two
data-ledger ownership cells are repointed by the tool. The map's assignments
are not regenerated in the commit. One whitespace-only line emitted by the
composer is cleaned up before final verification.

The composed unit passes `./build.sh`: 18/18 rows, five string references,
and all three EH graphs EXACT. Its strict `link_check.py --prepare-current`
receipt passes. Frozen-file, CSV, TU ownership, Microsoft-header staged check,
code identity (18 rows, zero new findings in shadow) and data identity checks
pass. Converged data enforcement checks 11 addresses with no second names or
unjudged rows.

Original versus composed COFF comparison preserves all 35 distinct external
COMDAT byte-and-symbolic-relocation fingerprints, all 35 external definitions
and all 40 unresolved external names. No conflicting original COMDAT copies.
The initial scratch comparison accidentally counted three undefined entries
also defined in the composed object as unresolved; those duplicate entries
are referenced only by .debug$F records. Subtracting the object's definitions
from both dependency sets gives the equal unresolved-name sets above.

The merge engine's census-linked-input guard passes. The final ordinary
preview LINKS for 982 authored bytes, equal to the sum of the original three
inputs. The destination's apparent preview increase from 876 to 982 is moved
ownership, not new census coverage. The preview index remains `41c28839bf`.

## Registers and tooling compatibility audit

Audit range: `dc5bd70524..ca11d97fcb` plus this composition, covering the queued
W3DShaderManager resource donor and these two Salvage donors together. The
combined old-path/basename search of tracked tools, hooks, workflows, source
includes, build/configuration files, registers and documentation finds no
active consumer requiring an update. Remaining mentions are origin banners,
BFME 1 provenance and reference ledgers, historical attempts/evidence,
deleted-row explanation and the published link-status snapshot. These are
preserved. No directories move; dynamic source discovery is unchanged.

No data-check or code-identity baseline keys, header-adoption rows or hatch
ownership belong to the two absorbed Salvage donors. The merge transfers
the two data-ledger owners without changing identities or totals, and
refreshes header-adoption and Microsoft-header reports through their owning
tools (no queue delta for these donors). Active function/map/data paths
resolve to the destination. The constructor's private-vtable keys remain
with the untouched constructor source. W3D's previously recorded register
audit remains applicable; its 21 rows and five data rows pass again after
resolving the publication rebase, which preserves both sides' header-queue
entries.

The outgoing batch audit of staged tree
`2bd87b02db6e8fe956d921e3a38b39724e86604f` against `dc5bd70524` is
INCONCLUSIVE: the index predates the base, and affected consumer
Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp lacks a current
receipt. Consumer selection remains unverified. This is the same outstanding
census prerequisite recorded for the queued W3D merge, now covering the full
batch; preserved object facts do not replace that verification.

## Remaining work

Keep the constructor separate until its layout and explicit vtable stores
can be reconciled without changing verified code or bindings. Carry the
merged units and affected consumers into the next scheduled census. No
census or smoke runner is started by this work, and no new linked-byte or
image-ownership result is claimed.
