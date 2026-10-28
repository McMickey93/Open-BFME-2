# LivingWorld composition, 2026-10-28

Inspected HEAD: `4c82b129ad`. Owner: `yasinschroeder-codex`.

## Placement and bounded composition

The consolidation picker selected
`Code/GameEngine/Source/GameClient/LivingWorld/LivingWorld.cpp` and claimed
the destination and its 20 whole-file donors. The supported naming planner
was run under the LivingWorld directory, refreshed after the dry run, and
passed its freshness check. The map approves 66 rows, with 20 whole-file
donors and 13 mixed sources. Its TU grouping is provisional: this pass does
not establish the original retail filename or recover new semantic names.

All 20 donor frozen-file checks pass. `tu_views.py --dry-run` identifies
incompatible LivingWorld bases, class/struct differences, overlapping fields,
a TreeHintRef member-name collision and different table types. None of its
proposals was applied. Both the full dry run and applying `tu_skeleton.py
--merge` run accept the same six donors:

- GameClient/LivingWorld/LivingWorldCtor.cpp
- Common/Rva002BFF5A.cpp
- WWVegas/WW3D2/Rva002BF61BGroundPlacement.cpp
- GameClient/Rva002BF735NewNode.cpp
- WWVegas/WWLib/Rva002BFB1AClear.cpp
- Common/RvaPairCopyCallFamily.cpp

The resulting destination contains 16 rows and replaces six source files,
reducing SOURCE FILES by five. The merge repoints the function and TU-map
source columns and one body-owner source. The committed TU map is not
regenerated; the other row fields remain unchanged. The tool's link guard
accepts the composition against the indexed linking donors. This establishes
only the guard's bounded scope, not a new census result.

Fourteen donors remain separate. Free and Dtor encounter incompatible private
views; Erase (0x002C004F), Insert, Picker and Reset encounter missing or
incompatible table declarations; Dispatch, StlSweepR3, Rva002BFBF7,
StlSweepW5 and StlSweepW4 encounter duplicate container declarations.
LivingWorldSetActive conflicts with the LivingWorld view and constructor
declaration. Rva002BF807Ctor has overlapping view members. Rva002BF6B7Erase
fails byte verification in the merged candidate. These require separate,
verified prerequisite changes. All 13 mixed sources remain intact; no donor
was split or private view reconciled in this pass.

## Written destination checks and linking limits

The normal `./build.sh` passes 16/16 rows. The six renamed unwind labels are
verified through their parent graphs; `eh_verify.py` reports two EXACT
graphs, zero missing and zero debt. Frozen-file, CSV, class and staged diff
checks pass. The scoped data check has zero findings in shadow mode.
Staged TU ownership reports only four layout-fingerprint diagnostics, with
no ownership violation. `progress.py` retains 7,978,500 BYTE-MATCHED bytes
(100%), reports SOURCE FILES 22,145 (five fewer), and retains 42,695
TU-APPROVED rows.

The published index metadata is dated 2026-10-28 02:44 at `14dc3d2467`, with
underlying census `73061d9452`. Ordinary `link_check.py` cannot preview the
new destination because that path is absent from the census. No LINKS or
new linked-byte claim is made for it.

The whole outgoing-range audit compares base
`746d72d6359135dc4bfc8221e32b0dd18aa3f9c9` with staged source tree
`8c418cf56c05a20cbd6a65f3159132d80d47bc25` and 13 live changed source paths.
It exits 2, INCONCLUSIVE: the index predates the outgoing base and lacks
per-object consumer names. The supported fetch had already confirmed that
the published index is the same version. Full external consumer selection
remains unverified. Carry both this moved scope and the earlier terrain
composition into the next normal census; do not treat the guard's acceptance
as full-batch clearance. No runtime or image-ownership result is claimed.

The normal commit hook also reports two unregistered shadow identity findings:
unwind row 0x00776B2F names `??1Rva002BF6D6@@QAE@XZ` for retail target
0x002BF776, and 0x00776B3D names `??1Rva002BF75A@@QAE@XZ` for 0x002BFB28.
Both classify `wrong`, detail `extent`: the retail targets have their own
five-byte forwarder rows, distinct from the named destructors. A read-only
comparison of the cached original donor's `$L561`/`$L562` against the new
object's EH-verified `$L5479`/`$L5480` finds identical complete 14-byte bodies
and identical relocation offsets, kinds and symbol names. Thus these
bindings were carried from the donor; byte/EH verification does not clear
them. Reconcile the member cleanup contracts and forwarder identities in a
separate verified repair. No register entry is added or retired here.

## Registers and whole-batch path audit

The absorbed donors and destination have no code-identity, data, header-queue
or Microsoft-header queue keys to transfer. The supported merge refreshes
the queues without changing them. One existing alternatename hatch moves
with its helper into the destination; the hatch count is unchanged. No pin,
name, extent, flag override or data identity is added.

After the final source moves, the whole outgoing batch was searched for all
nine deleted paths and their basenames: these six donors and the three
earlier terrain absorptions. No executable consumer in tools, hooks,
workflows, includes, build configuration or registries needs an update.
Current ledger, body-owner and hatch paths resolve to their destinations.
Existing directory globs retain their meaning.

Remaining references are donor-provenance comments, historical source
comments and verification documentation, attempt evidence, deleted-row
reasons, the attempt log, census-owned link status, and append-only naming
evidence. The naming basis reader keys those records by name and RVA and
treats their old source paths as history. These records are retained. This
handoff adds historical mentions only.
