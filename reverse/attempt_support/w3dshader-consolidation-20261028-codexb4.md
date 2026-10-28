# W3DShaderManager resource-creation consolidation, 2026-10-28

Seat: yasinschroeder-codexb4. Inspected base: `2a972506ca`.
Destination: `Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DShaderManager.cpp`.
Absorbed source: `Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DShaderManagerCreateResources.cpp`.

## Routing and scope

`next_work.py --claim` selected this TU. The scoped `name_lane.py consolidate`
packet and `tu_views.py --dry-run` were reviewed before composition. The
committed TU map was stale; `tu_skeleton.py` rebuilt current assignments in
memory and approved the resource-creation parent (0x000754DE, 363 bytes),
unwind (0x0075EF4E, 10 bytes) and handler (0x0075EF58, 10 bytes). Only the three moved source cells are repointed in the committed map; no
regenerated assignments are committed. Retail/WB assertion strings and reconstructed BFME 1 paths
are retained as provenance in the source; the BFME 1 source is a semantic
donor, not evidence that a donor path is an original BFME 2 path.

The supported dry run accepted only the existing TU and resource-creation
donor. Remaining whole-file donors need declaration/codegen reconciliation:
setShader and notify lack access to m_currentShader; draw and benchmark need
additional DX8Wrapper declarations; startRenderToTexture and setShroudTex need
compatible DX8Wrapper members; performGlow has protected-member access;
requirements duplicates placement new[]/delete[] via always.h; Gaussian needs
its member declaration in the seed. Two mixed donors (shutdown and init)
remain outside this merge. No rejected donor was edited.

## Verification and registers

Before composition, both original objects passed `link_check.py
--prepare-current`: 21/21 function rows, five data rows, three string literals,
16 named imports, and strict reusable receipts. Original COFF objects were
saved under build/w3dshader-before for the binding comparison. The failed
first preparation ran while the dry run was changing temporary source
inventory; it accepted no receipts and was retried after the dry run ended.

The applied supported merge preserves 21/21 function rows and all five data
rows. `./build.sh` and the destination's `link_check.py --prepare-current`
pass: three string references, 16 named imports and all four EH graphs EXACT.
The frozen-file check and CSV integrity pass. Code identity (shadow) reports
21 rows and zero new findings. Data identity reports zero findings; converged
data enforcement checks 11 addresses with no second names or unjudged rows.
TU ownership and the Microsoft-header staged check pass.

Original versus merged COFF audit: 19 COMDAT copies become 18 distinct
COMDATs, with byte-and-symbolic-relocation digests preserved for every one;
no conflicting original copies. All 32 external definitions and the external
undefined dependency set are preserved. The former donor's identical
DX8Wrapper accessor copy is coalesced into the existing TU's copy.

No data-identity, code-identity, header-adoption or flag-override register keys
were attached to the absorbed donor. The supported tool transfers its hatch
ownership and coalesces the duplicated g_Va009E1F6C declaration, reducing total
address-global occurrences by one (four to three). The destination's existing
alternatename remains one. The tool refreshes the Microsoft-header queue:
four existing imports still have matching declarations; d3d9.h requires
include-resolution review in that queue. No unrelated queue rows are removed.
The current TU map's approved destination is retained, with only moved source
cells repointed; functions.csv repoints all three donor rows.

## Tooling compatibility audit

Audited `2a972506ca` plus this staged change (one absorbed path, one existing
destination); no other outgoing moves. Combined full-path/basename search
across tracked tools, hooks, workflows, Code includes, build/configuration
files, reverse registers and documentation finds no active consumer requiring
an update. Remaining mentions are the merged source's origin banner and BFME 1
provenance, historical re_attempts/link_status records and
reverse/attempt_evidence/crack-j-cleanup-audit.json's source_before evidence.
Those historical paths are retained. No directory is moved, so dynamic source
discovery continues in the same tree. Active functions/map/hatch ownership
points to the current TU; header queues were reviewed/refreshed by their owning
tools. The destination is tracked. `git diff --cached --check` passes.

## Remaining link verification

The preview index is `41c28839bf` (2026-10-28 11:08), older than the inspected
base. Ordinary preview: the destination LINKS, 1,772 authored bytes; its census
attribution was 1,399 bytes. The 373-byte difference is source composition and
is not a measured gain. The merge's LinkGuard accepts both census-linked
inputs and the final composition.

The outgoing audit was run on staged tree
`9c0e2df41263adb574766452c0ace3c790383bd1` against the inspected base. Its first
missing scope receipt was the unchanged init caller
Code/GameEngine/Source/Common/Rva00066A9ABody.cpp; explicit preparation now
verifies both of its rows and two string references with a strict receipt.
Rerunning after that new evidence remains INCONCLUSIVE: the index predates the
base, and affected consumer
Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp lacks a current
receipt. Full consumer selection is therefore unverified, not clean. Carry the
merged provider, init caller and affected consumer cohort into the next normal
census. The preserved symbol/dependency and COMDAT digests above bound what
this composition itself changes; they do not replace the census. No new census or smoke run is requested or started. This consolidation
claims one fewer source file and preservation of matched coverage; it claims
no measured linked-byte or image-ownership gain.


Publication rebase: the first runner publish stopped before handing off or
pushing this commit. Rebased onto `109916432b`, preserving upstream's
GlowMaterial handoff and PortNegotiationSchema Microsoft-header queue entry
alongside this change. No tools, hooks, flag tables or this TU's source changed upstream;
nearby unrelated W3D sources and Rva0007DF07.h changed. The latter is outside
the destination's include dependencies. The destination is
reverified after conflict resolution. The original inspected base and scoped
COFF comparison above remain the recorded before-state, not a census claim.
