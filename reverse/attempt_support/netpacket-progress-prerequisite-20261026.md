# NetPacket progress-view prerequisite, 2026-10-26 (codexb)

Family B shard 0/2, separate from the inherited recovery batch. The runner's
`--check-tu Code/GameEngine/Source/GameNetwork/NetPacket.cpp` exits zero.
Claimed the destination and all three edited serializer files. Reviewed the
GameNetwork naming packet's original-path evidence, alternatives and blockers;
the ordinary merger rebuilds current routing in memory. No merge is applied.

## Demonstrated unblock

At starting revision d74c167392, the ordinary dry-run accepts thirteen sources
and 185 rows. Three flattened NetProgressCommandMsg definitions suppress the
seed's inheritance and hide getNetCommandType/getTimestamp and other existing
base methods. Declare the existing polymorphic NetCommandMsg base separately,
derive the progress view, and retain the seed's base-typed NetCommandRef pointer
with an explicit progress cast at each serializer's read.

The post-edit ordinary command accepts sixteen sources and 188 rows:

```
python3 tools/tu_skeleton.py --merge Code/GameEngine/Source/GameNetwork/NetPacket.cpp --dry-run
```

Newly compatible donors are Rva0058C96CWrite.cpp (175 bytes),
Rva0058CB27Write.cpp (178), and Rva0058CBD9Write.cpp (178): three existing rows
and 531 existing retail bytes. This is a declaration prerequisite for Luna,
not recovered coverage, an applied merge, or a confirmed later Luna landing.

## Acceptance and binding evidence

- Before/after `./build.sh NetPacket.cpp Rva0058C96CWrite.cpp
  Rva0058CB27Write.cpp Rva0058CBD9Write.cpp`: 184/184 rows exact.
- Complete eighteen-source provider/context build: 227/227 rows exact, seven
  empty-string references and the emitted STLport constructor verified.
  `link_check.py --prepare-current` accepts strict reusable receipts for all
  eighteen providers after the trial finishes; census/index/status are unchanged.
- Edited sources plus seed pass find_declared_unmatched.py, class_gate.py,
  data_check.py --converged (ten addresses, no second names/unjudged rows),
  and scoped link_check.py --new-variants. No protected register changes.
- Saved eighteen baseline objects with source/object SHA256 in
  build/codexb-netpacket-progress-before.json. Supported allowed_symbols.Obj,
  its body/relocation reader and the census COMDAT reader compare all external
  code/data providers, relocation referents, flags, selection rules and
  undefined references. Every standalone object is identical before/after.
- The accepted composition (build/tu_skeleton/eb9ec061ae941f80.obj) preserves
  the provider union with no new provider, changed body or new undefined
  reference. Removed undefined references resolve to equal admitted providers.
  Local switch references are checked by containing provider and byte offset;
  local EH handlers retain their identities. All 65 EH parents are EXACT in
  both the 185-row baseline and the 188-row post-edit composition.
- The sole suppressed unrowed getCommand duplicate remains the previously
  documented one: the unchanged ConnectionManager provider has identical
  bytes/relocations and ANY selection, precedes NetPacket_isAckRepeat in the
  current input order (4120 < 19356), differs only in section alignment, is
  not an index selection exception, and has no undefined composed reference.
  No other provider loss is accepted.

Scratch receipts/proofs are build/codexb-netpacket-progress-* and the existing
build/codexb-netpacket-composition-proof.py, using the saved manifest and the
ordinary before/after trial reports. Full-scope shadow identity analysis still
reports the existing seed list-copy binding at 0x00594689 and an existing
cross-unit _Rb_tree::_M_insert variant. All standalone providers are unchanged;
neither finding is repaired or retired here. No selected-provider or measured
linked-byte gain is claimed; the previously recorded full-index freshness gap
still awaits a normal census.

## Pending-batch audit and handoff

Fetched origin/master b57c128806: none of the eighteen provider/context sources,
AGENTS.md or docs/consolidation.md changed upstream. Inspected the complete
pending range and staged changes, separating incoming commits from this seat's
outgoing range. All three production sources are edited in place; no production
path is added, deleted, moved or absorbed. Tools, hooks, workflows, includes,
build inputs, registries, historical EA paths, routing and existing debt owners
need no path repointing. No TU map or baseline was regenerated.

Leave the now-compatible sixteen-source subset for Luna. Five ordinary donors
remain rejected: the two incompatible wrapper payload views, NetPacketO1's
BaseType coordinate duplication, the write helper's declaration boundary and
the read helper's empty compile diagnostic. Five mixed donors remain untouched.
The existing list-copy identity finding remains open. File reduction, debt
retirement, recovered C++ bytes and census-linked-byte gain are each zero.
Keep the four source scope claims and this evidence claim until publication is
confirmed; no new RVA claims were needed.
