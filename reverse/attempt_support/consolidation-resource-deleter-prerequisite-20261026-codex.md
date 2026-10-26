# ResourceGatheringManager deleter declaration prerequisite

2026-10-26, codex, family A shard 0/2. Runner --check-tu authorizes
Code/GameEngine/Source/Common/RTS/ResourceGatheringManager.cpp. Scoped planner
build/consolidation/codex-resource-deleter-final is current. Its original-path
leads and alternative donor layouts remain investigation evidence; current
routing, rebuilt in memory by tu_skeleton, approves the destination. No map is
regenerated on disk and no merge or split is applied.

Following the lifecycle prerequisite, ordinary composition accepted twelve
rows but rejected ResourceGatheringManagerDeleter.cpp with C2511: its existing
EmitVtableTag constructor had no declaration in the surviving shared class.
The shared view now forward-declares that existing tag and declares the
existing overload. No body, compiler flag, layout field, virtual slot or hatch
is added. The deleter source and its honest absent-from-retail emitter marker
remain unchanged.

Acceptance:

- ./build.sh destination/destructor/Xfer/deleter: 13/13 exact before and after;
  literals/floats/import checks pass. find_declared_unmatched.py and class_gate
  pass; two EH graphs are EXACT. Three local funclet labels renumber, with the
  existing parent EH placement verified; pins are unchanged.
- Full standalone COFF comparison, using upstream allowed_symbols/link_check
  readers: 19 + 27 + 1 + 2 external code definitions, and 21 + 36 + 2 + 4
  non-debug sections, identical before/after. Named relocations, section bytes,
  COMDAT policies, undefined symbols, aliases and external data definitions are
  unchanged. All 24 row reference facts and all data facts are identical.
  The three direct header consumers and separate deleter were verified together;
  rg finds no other header consumers. Thus the declaration prerequisite changes
  no emitted standalone provider or consumer binding.
- link_check.py --prepare-current --paths-from
  build/codex-resource-deleter-sources.txt writes four strict receipts. An earlier
  concurrent attempt detected moving preparation inputs and accepted no witness;
  it was rerun after the composition trial completed. Scoped --new-variants
  passes. Converged data: ten addresses, zero second names/unjudged rows.
- tu_skeleton.py --merge TU --dry-run now accepts all four clean sources,
  thirteen existing rows / 536 retail bytes, with no rejected clean donor:
  one additional existing 28-byte deleting destructor at 0x004F5F2E compared
  with the previous twelve-row trial. This is a demonstrated byte-compatibility
  unblock, not a completed merge, recovered bytes or confirmed Luna landing.

Composition still requires provider evidence. Scratch 73e9f1bee7fcdb50.obj
retains both external data definitions and every row's data facts; it drops
four standalone COMDATs (list<int>::erase, _Destroy<int>, node deallocate and
its proxy), adds the external erase reference and removes _free, as in the
previous lifecycle trial. Its non-retail EmitVtableTag constructor also changes
from 11 to 73 bytes because the surviving shared class has two real list members. There are no new
external definitions or alias changes, and no conflicting standalone definitions.
The diagnostic comparison intentionally ends with a failing equality assertion;
its JSON records these deltas. No current selected-provider/consumer proof for
that composition is claimed. Leave composition unapplied until the native erase
provider and this emitter's changed dependencies are verified together.
Mixed ModuleNameGetters and the unplaced cost helper remain outside this merge.

Evidence: build/codex-resource-deleter-{before-build,after-build,after-trial,
object-proof,reference-proof,data-proof,prepare-final,variants-final}.txt,
EH and composition JSON, plus the scoped planner. No register or debt key is
removed. File reduction 0; identity/data/header debt retired 0; recovered C++
bytes 0. This adds one row / 28 existing bytes to the earlier lifecycle
prerequisite's seven rows / 272 existing bytes accepted by ordinary dry-run.

Complete pending path audit: merge-base-to-HEAD plus this staged prerequisite
has no source moves, renames or deletions. Active tooling, hooks, workflows,
includes, build inputs and registries require no repoint. Historical EA paths
are preserved; identity/data/MS/header registers keep their existing ownership.
No maintainer-only link cycle, smoke or nightly builder was used. Retain the
shared-header/deleter/handoff and previous pending file claims until publication
is confirmed, then release those scopes and settle landed RVAs.

The shared docs/linking_obstacles.md claim was refused (another worker holds
it). This scoped handoff supplies the LINK-004/017 update without editing
that worker's register.
