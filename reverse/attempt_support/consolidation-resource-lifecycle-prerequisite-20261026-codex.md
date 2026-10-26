# ResourceGatheringManager lifecycle declaration prerequisite

2026-10-26, codex, family A shard 0/2. The runner's --check-tu authorizes
Code/GameEngine/Source/Common/RTS/ResourceGatheringManager.cpp. The scoped
planner and final currency check are under
build/consolidation/codex-resource-lifecycle-final. Its BFME 1/ZH source
leads do not prove BFME 2 source provenance; current routing approves moves.
No move or merge is applied here.

The list/transfer view lacked the lifecycle declarations used by the existing
destructor donor, so ordinary composition rejected its constructor (C2600).
The shared header now carries that donor's existing empty polymorphic base,
constructor, virtual destructor and abstract four-slot table. The former
slot-three seed(void*) placeholder becomes the existing xfer(Xfer*) member;
it remains pure, preserving the donor's purecall table entry. The transfer
body's out-of-line definition is valid for that pure virtual method.
The measured prefix stays vptr +0, warehouse list +4 and center list +8.
This is a scoped union of existing target declarations, not a recovered
complete class or a donor-layout attribution. No compiler flag or hatch is
added. The destructor includes the view instead of repeating the classes.

Acceptance:

- ./build.sh on destination, destructor and Xfer: 12/12 exact, before and
  after; literals/floats/import checks pass. Declaration scan and class gate
  pass. Two EH graphs EXACT. Three compiler-local labels renumber, with their
  retail locations verified from the parent's EH data; pins are unchanged.
- Preserved verified before objects and upstream allowed_symbols/link_check/
  link_census COFF readers compare all 19 + 27 + 1 external code definitions
  and 21 + 36 + 2 non-debug sections. Bytes, named relocations, COMDAT policies,
  undefined names, aliases and external data definitions are identical.
  All 22 code reference facts and every data definition/reference fact remain
  equal. Thus this prerequisite changes no selected provider or consumer
  binding, including shared emitted helpers. All three direct consumers were
  verified together; no other source includes this header.
- link_check.py --prepare-current --paths-from
  build/codex-resource-lifecycle-sources.txt writes three strict reusable
  receipts. Scoped --new-variants passes. Converged-data check: ten addresses,
  no second names or unjudged rows. No debt key is removed or transferred.
- Ordinary tu_skeleton.py --merge TU --dry-run previously accepted seed/Xfer,
  five rows. It now accepts seed/destructor/Xfer, twelve rows: seven additional
  existing rows / 272 retail bytes are byte-compatible. The separate deleter
  still lacks its EmitVtableTag constructor declaration (C2511). Mixed name
  getters and the unplaced cost helper stay behind. No Luna landing is claimed.

Composition binding limit: scratch d2da346bee240529.obj retains all 35 surviving
code definitions and both external data definitions exactly, with unchanged
per-row data facts and aliases, but drops four standalone COMDAT providers:
list<int>::erase(iterator), _Destroy<int>, allocator<list-node<int>>::deallocate
and its allocation-proxy wrapper. It adds an external reference to the first
and removes _free. The native erase owner is rowed at 0x00438539 in the
Libraries stlport_list_int_o1.cpp; no current whole-batch selection proof is
asserted here. This differs from the unchanged standalone prerequisite and
prevents endorsing or publishing the composition. Preserve this exact provider
prerequisite for Luna/current census rather than treating twelve exact rows as
a complete merge approval. The trial itself was never applied.

Receipts: build/codex-resource-lifecycle-{before-build,after-build,after-trial,
object-proof,reference-proof,data-check,prepare,variants}.txt and the matching
object/reference/data/composition JSON proofs. The composition script's final
assertion deliberately fails on the four missing providers and changed
external references; this is recorded, not ignored.

Complete pending batch audit: the actual outgoing commits since the merge
base plus this staged prerequisite contain no source moves/renames/deletions.
The raw two-tip diff also shows independently incoming Lifetime/LargeGroup
changes; those are not outgoing deletions. Existing source/header includes
resolve directly. Active tools, hooks, workflows, build inputs and registries
need no path repoint; historical EA paths remain. Header/MS queues and
code/data identity registers are unchanged by this prerequisite. Shared
obstacle-register ownership was held by another worker when requested; this
handoff supplies the LINK-004 declaration repair and remaining binding blocker.

File reduction 0; identity/data/header debt retired 0; recovered C++ bytes 0.
Retain destination, destructor, Xfer, shared-header and handoff file claims until
confirmed publication. The inherited ResourceGathering/PlayerList claims also
remain pending. No maintainer-only link cycle, smoke or nightly runner was used.
