# Sol family B prerequisite handoff, 2026-10-26 (codexb)

Seat codexb, family B shard 0/2. Read current AGENTS.md and consolidation
instructions, including the provider/consumer and tooling audits. Preserved
the interrupted NetPacket preparation and verified inherited edits first.
No helper agent, manual merge/split, maintainer-only runner or naming vote.

## Verified prerequisites

All changes target Code/GameEngine/Source/GameNetwork/NetPacket.cpp. The
runner --check-tu exits zero; each edited file has its normal scope claim.
Current GameNetwork planner packets were reviewed and checked before editing;
the ordinary merger rebuilds routing in memory. No committed TU-map refresh.

| Scope | Commit after rebase | Ordinary acceptance |
| --- | --- | --- |
| Inherited seed argument declarations | 994e8e4ebe (was c1e5a94e6e) | Preserves the inherited seed/add-helper subset, 174 rows. |
| Inherited six reference-lifetime declarations | 6bf420e39b (was c83a97acef) | Eight sources / 180 rows; six donors newly demonstrated compatible during recovery. |
| New repeat-dispatch helper types | 8f63b247bd (was 82423bab2a) | Nine sources / 181 rows; adds the existing 75-byte dispatcher. |
| New four wrapper pointer casts | d78405e368 (was 0554dee82a) | Thirteen sources / 185 rows; adds four existing serializers totaling 717 bytes. |

The two new prerequisites demonstrate five newly compatible donors / 792
existing retail bytes beyond inherited recovery. Leave the compatible donors
for Luna. No actual merge or later downstream Luna landing is claimed.

Detailed evidence is in the same-date netpacket-declarations, netpacket-ref,
netpacket-ack and netpacket-wrapper handoffs. Before/after ./build.sh passes
188/188 inherited rows, 182/182 seed/dispatcher rows and 4/4 wrapper rows.
Frozen-file, class, scoped data, shadow variants and Microsoft-header checks
pass or retain the documented existing seed debt. Strict-current receipts
were accepted for the eight-file recovery, seed/dispatcher and four wrappers.

Supported COFF/COMDAT readers compare fourteen saved standalone objects with
current providers: code/data bytes, relocation referents, section flags,
selection rules and undefined references remain identical. The composed
object preserves every other provider and introduces no undefined reference;
all 65 EH parents are EXACT. The sole suppressed unrowed getCommand duplicate
has identical code/relocations/ANY selection in the unchanged, earlier
ConnectionManager provider, verified with its 30/30-row build. Only section
alignment differs. Removed references bind equal admitted providers. The
bounded comparison explicitly accounts for this duplicate; matched function
bytes alone are not the binding evidence.

Rebased the four commits onto origin/master b06312df51. Upstream changed none
of the fifteen-source verified provider/context scope. AGENTS.md and
docs/consolidation.md hashes are unchanged. Refreshed the complete thirteen-
source build, frozen checks, standalone comparison and composition proof
after rebase: 193/193 rows and 65 EXACT composed EH parents. The retained
getter provider still precedes the donor (current ranks 4120 < 19362).
Receipts are in build/codexb-session-rebased-build.txt.

## Remaining and investigated work

NetPacket's remaining eight ordinary rejections are three flattened progress
views hiding inherited base methods; two wrapper views needing field agreement;
NetPacketO1's duplicate BaseType coordinates; and separate write/read helper
declaration/compile boundaries. Five mixed donors remain untouched. The
existing ConstructBigCommandPacketList list-copy identity finding at
0x00594689 remains open and unretired. Released the unused, blocked
Rva005910B4Write claim. No nonmatching reconstruction remains in Code.

The allocated queue has twenty destinations and no explicit repair entries.
Fresh ordinary trials: Connection loses two seed rows under its carried flags
and needs a GameLogic adoption; DisconnectManager retains its 31-row O1 and
two-row constructor flag boundaries and other no-baseline donors; AptString
accepts its existing 37-row subset but rejects the constructor's incompatible
Rva006D6D20 field names, a flag-bound slice and Common-owned class views.
Apt claims were released without edits. The W3D planner hit a disappearing
temporary DisconnectManager trial file; that tooling race proves no queue is
empty, and no Bib trial was started. Existing Smudge/Bib SDK, ownership and
ABI blockers, font/debug virtual slots, Network flags and Win32/Common
dependencies remain with their recorded owners. Compatible TileData, mesh,
debris, AptMovie, line3d and wwstring subsets are left for Luna. No unchanged
failed source reconstruction was repeated. MessageStream issue #116 remains
reserved for a maintainer decision.

## Batch audit, measurements and publication

Audited origin/master..HEAD and the staged handoff across the complete pending
batch, with earlier triple-dot checks separating incoming changes. Eleven
production sources are edited in place; none is moved, added, deleted or
absorbed. Active tools, hooks, workflows, includes, build inputs and registries
need no path repair. Historical EA paths, routing, flag contracts and surviving
debt ownership remain intact. No protected register changes. check_csv.py
passes 98,271 function rows; diff whitespace checks pass. Shared obstacle
LINK-044 records the bounded clearance and remaining prerequisites.

Final progress.py origin/master after rebase: BYTE-MATCHED 7,978,500 (100%);
LINKING 7,322,361 (97.47%); LINKED 7,567,229 (98.14%), census d1f046749a at
2026-10-26 13:18. All deltas are zero. An earlier pre-rebase comparison showed
positive link deltas only because the checkout lacked the newer upstream
census; those are not this batch's gains. Files reduced, recovered C++ bytes,
identity/data/header debt retired and measured linked-byte gains are each zero.

Publication has been deferred by the shared slot. Keep thirteen accepted
source-file claims, the four detailed evidence claims, this handoff and
docs/linking_obstacles.md until confirmed publication; no new RVA claims exist.
The audited range is origin/master b06312df51 through d78405e368 plus this
handoff/obstacle update. The runner publishes any remaining batch after the
session. After landing release those file claims and run claims.py release
--landed. Read the pre-push selected-provider, lost-byte and input-freshness
report then; carry inconclusive findings to the next census without rerunning
maintainer-only measurements.

The first final publication attempt rebased the source commits successfully
but stopped on concurrent appended obstacle entries. Resolved the documentation
conflict by preserving the incoming entries and adding NetPacket as LINK-044 (LINK-041 through LINK-043 are upstream entries).
The further upstream update changes none of the fifteen verified provider/
context sources or either instruction file. The source commits and audited
base above reflect that rebase; the final progress figures remain unchanged.

Preparation recovery: retained backup refs/runner/preparation/1793025387074327263,
with no saved stash in runner-prepare.json. Replayed all five preserved commits
onto df25e102ce; resolved the append conflict retaining upstream LINK-041/042
and assigning the separate NetPacket evidence LINK-044. All eleven source edits
remain in place; no production path or protected register changes.

Recovery dry-run `git push --dry-run origin HEAD:master` passed at d76d8d4b8a:
218/218 rows across 12 source files, 69/69 EH EXACT, converged data check
12 sources / 10 addresses / no second names or unjudged rows. Frozen checks
pass for all eleven edited sources. The pre-push batch audit is inconclusive:
index 763dc8759f predates outgoing base df25e102ce and affected Eva.cpp lacks a
current receipt. Preserve the bounded standalone/composition proof above and
carry this index/receipt gap to the next normal census; no link gain is claimed.
The first recovery publisher then replayed the sources over f4ec351d97 and
stopped on another appended obstacle. Retained that incoming LINK-043 and
renumbered NetPacket LINK-044. No source/instruction changes occurred upstream
in the verified GameNetwork scope. Backup ref and all build evidence remain.
