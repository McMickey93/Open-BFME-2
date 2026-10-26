# Camera-shake TU consolidation

2026-10-26; input revision `6db4bffb3e`, outgoing base `3389824a5a`.
Claim owner: `yasinschroeder-codexb4`.

`next_work.py --claim` selected the approved camera-shake TU and
`Code/GameEngine/Source/Common/Rva00065E21Method.cpp`. The planner ran under
`Code/GameEngineDevice/Source/W3DDevice/GameClient/`; its snapshot passed
`name_lane.py consolidate --check build/consolidation` before application.
The planner correctly treats the stale committed map and donor names as hints.
`tu_skeleton.py` rebuilt placement in memory: the 27-byte row at 0x00065E21
is approved by the 0x00065DAD..0x00065E3C bracket for
`Code/GameEngineDevice/Source/W3DDevice/GameClient/camerashakesystem.cpp`.
No new name or layout identity is asserted by this move.

The dry run and application accept the seed and this donor, with no rejected
file and 13 byte-exact rows. The two mixed files, camerashakesystem_shaker.cpp
and Rva00065E3CMethod.cpp, remain in place. Only the donor's source column is
repointed in functions.csv and tu_map.csv; no regenerated map is committed.

## Verification and binding comparison

- `./build.sh` on the destination and both mixed peers: **27/27** rows exact,
  six float references verified. Destination alone: **13/13** exact.
- EH verification of those three sources: **5 EXACT**, zero failures or missing
  objects. Existing renumbered funclets resolve through the verified parents.
- Destination's declared-body, staged TU ownership, case, CSV and pin checks
  pass. Shadow data: zero findings; converged data: zero second names or
  unjudged rows. No header or Microsoft-header queue entry names either merged
  input; the merge refreshes the destination's Microsoft-header result.
- Neither merged input has a protected data, identity or hatch key to transfer.
  Before and after code identity each checks 18 references: 14 owners, two EH
  references and two aliases, with **zero wrong bindings**.
- `link_check.py --prepare-current` byte-verifies the destination and prepares
  its strict reusable receipt without changing census/index/status.
- Published index: `5ce093a71a`, 2026-10-26 19:02. Before composition, the four
  files preview LINKS for 255 + 27 + 879 + 171 = **1,332 bytes**. The ordinary
  post-merge CLI still includes the deleted donor's historical definition and
  reports its 27-byte symbol as a duplicate; that is not a second current body.
- Rechecking the final compiled object through `tu_skeleton.LinkGuard` returns
  no findings. A bounded in-memory comparison uses `link_check.forget` for only
  the deleted donor and refreshes the three current objects. All three LINKS,
  for 282 + 879 + 171 = **1,332 bytes**; unresolved, duplicate, COMDAT, address
  and selected-provider blocker lists are empty. The shaker peer retains its
  pre-existing unreferenced FastCriticalSectionClass diagnostic.

Raw logs and the read-only composition script are under ignored
`build/camera-consolidation-codexb4/`. The ordinary CLI limitation is retained
in `after-link.log`; the bounded result is in `composition-link.log`. Neither
comparison writes an index or runs a census.

## Outgoing path-consumer audit

The two previously pending commits change no source path. The complete outgoing
path-change scope therefore absorbs only Rva00065E21Method.cpp into the existing
camera-shake TU. A tracked-tree search for the old full path and basename finds
only the destination's provenance comment and reverse/link_status.csv's
historical census row. Keep both. No active tool, hook, workflow, include,
configuration, source registry, fold proof or protected register needs repair.
The method's existing W3DView_update.cpp caller keeps the same symbol spelling.

This removes one source file and preserves matched and bounded link coverage.
It retires no debt and claims no new linked bytes or ownership receipt. Carry
the composition to the next scheduled census; the available index predates the
outgoing base, so the automatic batch audit cannot establish exact-base closure.
