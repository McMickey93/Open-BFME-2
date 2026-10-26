# Bridge texture teardown prerequisite, Sol B5, 2026-10-26

Target: Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DBridgeBuffer.cpp.
Seat codexb5, family B shard 1/2. Runner allocation --check-tu exited 0;
normal upstream file claims cover the seed, destructor donor and this handoff.
Read current AGENTS.md and docs/consolidation.md. name_lane consolidate under
Code/GameEngineDevice/Source/W3DDevice/GameClient/ catalogued original-path
worldbuilder/Zero Hour/BFME1 evidence and alternative donors; its mixed-file,
private-view, compiler/include and protected-register warnings were reviewed.
The map is rebuilt in memory by tu_skeleton; no routing map is committed.

## Proven prerequisite and demonstrated unblock

The seed padded across the texture member at +0x34. The existing, byte-verified
W3DBridgeDestructor.cpp models TextureRef there and AsciiString at +0x108;
its automatic member teardown requires that declaration in the destination.
Replace only four bytes of padding with that same TextureRef view and copy the
existing texture declarations into the seed. W3DBridge remains 0x114 bytes;
left mesh stays at +0x38, template name at +0x108. No body, signature, flag,
virtual slot, global spelling or method name changes. This is target member
teardown evidence from the matched donor, not a claim that its stale BFME1
retail-address comment describes BFME2. BFME2's ledger parent is 0x000DDA6E,
73 bytes, with three associated EH rows (108 retail bytes total).

Before: normal --merge --dry-run accepted nothing, destructor rejected.
After: the same command accepts seed and full destructor donor, all 22 rows
(18 seed, four donor). No merge applied; no later Luna landing claimed.
Luna can merge this pair through the ordinary claims and acceptance checks.

## Verification and scoped composition evidence

- ./build.sh on seed and destructor: 22/22 rows exact before and after,
  three float literals. find_declared_unmatched passes for both files.
- eh_verify.py on both: EXACT 5, no exceptions or missing objects.
- allowed_symbols.py --source both: 47 references, zero wrong bindings.
  The scoped object comparison also resolves EH-label aliases: 51 references
  across 22 rows, no changed bindings. All 28 external definitions in the
  composed object have the same bytes/relocations, COMDAT selection and flags
  as their original providers. No new/dropped definitions or new undefineds.
  Upstream Identity/link_order selection agrees for all 28 provider names;
  there are no preexisting divergent provider copies in these two objects.
- data_check.py both: zero findings/outside baseline. --converged: ten
  addresses, zero second names or unjudged rows. Composition preserves the
  union of data bindings and definitions exactly.
- Before/after standalone provider, data and relocation facts agree exactly
  after resolving only compiler-local EH label renumbering. class_gate passes.
- Planner regenerated after edits; consolidate --check build/consolidation
  passes. Normal hook verifies ledger, source, identity and data acceptance.

Local receipts, all ignored under build/: sol-b5-bridge-session-before.log,
sol-b5-bridge-after-trial.log, sol-b5-bridge-before/proof.json,
sol-b5-bridge-after/proof.json, sol-b5-bridge-composition.json,
sol-b5-bridge-composed-bindings.json, sol-b5-bridge-composed-selection.json.
Scratch scripts use upstream allowed_symbols, link_census COMDAT selection,
data_check and the existing tu_skeleton verifier objects; no manual compile
through build.compile_source and no maintainer link cycle was run.

## Remaining prerequisites and batch audit

getModelVertices still fails Vector3 declaration order; getModelVerticesFixed
has Coord3D/header conflicts and a protected hatch key. W3DBridgeLoad has
MeshClass declaration conflicts; refill has missing counter/state spellings.
AddBridge needs W3DTerrainLogic declarations and Region3D header adoption.
Three mixed donor files remain intact; their Common/foreign rows stay put.
These are distinct blockers, not closure of the whole Bridge TU.

Before committing, audited the common-ancestor..HEAD outgoing batch plus this
staged repair. Pending PropDraw and Bridge edits move no source paths or rows;
no active tool, hook, workflow, include consumer, build input, registry or
Doxygen path needs repointing. Protected registers and historical EA paths are
unchanged. Existing code/data/header debt keys remain accounted for; none are
retired. Current includes and standalone providers remain stable; affected
composed consumers are covered by the scoped evidence above.

File reduction 0; identity debt retired 0; recovered C++ bytes +0; no measured
LINKED gain. Claims remain held until publication is confirmed; if deferred,
release seed/destructor/handoff file claims after the runner lands the batch.
