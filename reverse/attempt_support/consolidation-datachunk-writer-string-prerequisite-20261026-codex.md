# DataChunk ASCII writer header prerequisite, 2026-10-26

Allocated codex family A shard 0/2 DataChunk.cpp destination, authorized by
runner --check-tu. Its current upstream plan routes this ScriptEngine donor
to that destination. Normal donor/header-register/handoff claims held; no
overlapping worker claim taken. Common/System planner regenerated at
build/consolidation/datachunk-writer-session6 and its currency check passes.

The queued canonical AsciiString adoption failed because the private view
called getStringData. Used header_adopt_lane.py swap to remove AsciiString
and AsciiStringHeader, include the canonical header, and call its existing
str() API. No flags, receiver fields, ledger identities or layout changed.

Verification:

- Before/after ./build.sh DataChunkOutput_writeAsciiString.cpp: 1/1 row,
  91 retail bytes exact, one empty-string reference and one import verified.
  Frozen and class checks pass; EH verifier has zero rows/failures/missing.
- header_adopt_lane.py accept --class AsciiString SOURCE passes and retires
  exactly its one header_queue.tsv entry. Three header entries retired across
  the complete pending batch; zero code-identity debt keys retired here.
- Scoped reference/data facts unchanged (zero code-call facts in this body).
  Undefined externals unchanged. The body and surviving getLength helper
  retain their bytes and normalized relocations. One empty-string datum has
  identical content/relocations despite changed COFF section numbering.
- Replaced private getStringData with canonical str: both 16 bytes, digest
  624f6b429ab0. Removed private helper has no other provider or undefined
  referrer. Canonical str's existing selected WinMain provider stays selected
  among 617 other copies. Added StringBase<char>::getLength (14 bytes,
  fbd63de13562) and validate (one byte, 8bf7b464aaa2) are identical to their
  existing selected WWLib/string_base and Common/System/Xfer providers
  (79 and 121 other copies). validate's LivingWorldObjectParser consumer keeps
  the same selected provider. No changed consumer binding. New unused aliases
  already exist in the pending batch; complete alias union unchanged.
  Scratch receipt: build/codex-session6-datachunk-writer-provider-proof.json.
- link_check.py --prepare-current --paths-from
  build/codex-session6-datachunk-writer-sources.txt accepts one strict current
  provider receipt. check_csv passes; converged data check reports ten
  addresses, zero second names/unjudged. No census or closure claim.

This retires a demonstrated canonical-header prerequisite. No merge applied
and no new accepted composition claimed for this donor. Remaining receiver
APIs and tempFile/file spelling differ in the seed; the earlier ordinary
DataChunk trial records these separately. Do not guess a field identity or
bypass the Mapping identity refusal. Leave the already compatible counted
readers to Luna; renew evidence and claims before any future composition.

Publication compatibility audit covers outgoing commits 022d9b9a58 through
be158fe4f7 plus this change, using outgoing log and merge-base diff to exclude
incoming origin commits. No outgoing game-source moves/deletions/renames or
ledger repoints. Active tools/hooks/workflows/includes/build inputs and path
registers need no updates. New FunctionLexicon private-header consumers remain
exactly the two previously verified sources. Historical EA paths preserved.
Protected data/identity/gate/hatch registers unchanged; header retirement uses
its acceptance path. Source files removed zero; recovered C++ bytes zero.
Keep claims until publication is confirmed.

## Final publication and shared audit handoff

All six source/prerequisite commits were confirmed on origin/master after the
runner's rebase and successful push (new SHAs): ef4bc446bc (FunctionLexicon),
8d28d71268 (KeepObjectDie), deb97f75b4 (counted-reader header), bb320ed81b
(counted-reader cleanup binding), 9036ebf7f0 (seed reader APIs), 78413ee546
(this writer). The final pre-push gate verified 66/66 rows across seven
sources, including dependent Eva.cpp, seven EXACT EH graphs, eleven literals,
seven empty-string references, five float literals and four named imports.
Converged data still has zero second names/unjudged; CSV/pin/baseline gates pass.

The pre-push link batch audit returned INCONCLUSIVE before selected-provider
or lost-byte comparison: index 763dc8759f predates outgoing base 978d1d04ae,
and Eva.cpp lacks a strict current receipt. A single supported follow-up,
link_check.py --prepare-current --paths-from
build/codex-session6-eva-sources.txt, refuses that receipt because its include
inventory has a macro or parent-traversing include with unknown search roots.
This is the existing LINK-008 inventory boundary, not failed byte verification.
No workaround, gate edit, repeated batch audit, link cycle or smoke run used.
The individually recorded object/composition proofs remain bounded evidence;
carry census confirmation and Eva receipt repair to their normal lanes.
docs/linking_obstacles.md is held by yasinschroeder-codexb, so its LINK-001/008
freshness update is handed off here without racing the shared file claim.

Demonstrated ordinary dry-run compatibility: FunctionLexicon seed + constructor
seven existing rows / 401 bytes; DataChunk's two counted-string donors add six
existing rows / 381 bytes. No later Luna merge is confirmed. KeepObjectDie's
canonical header is accepted but its receiver/vtable APIs remain incompatible.
Other allocated trials: AssaultTransportAIUpdate still accepts no donors due
to receiver/helper and Xfer/GameLogic view conflicts; Preorder/CrushDie/HotKey
retain previously evidenced receiver/vtable/STL/flag blockers. No source trial
left behind for those targets, and no unchanged failed build repeated.

Final progress.py origin/master: BYTE-MATCHED 7,978,500 (100%); authored C++
7,249,397 (+0); LINKED 7,567,229 (98.14%); LINKING 7,322,361 (97.47%), both
from the 2026-10-26 13:18 d1f046749a census. No new ownership receipt.
Session totals: three accepted header retirements, one code-reference identity
finding corrected, zero registered code-identity keys retired, zero source
files removed, one private header added, zero recovered C++ bytes.

Publication audit now covers ef4bc446bc..78413ee546 and this documentation-only
follow-up; no pending source path changes or new consumers. All thirteen
published source/register/other-handoff claims are released after confirmation;
only this handoff's file claim remains if the runner defers its final commit.
Release that claim after this follow-up lands. No RVA claims were acquired.
