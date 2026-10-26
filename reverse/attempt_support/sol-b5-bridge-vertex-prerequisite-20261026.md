# Bridge vertex declaration prerequisite, Sol B5, 2026-10-26

Target: Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DBridgeBuffer.cpp.
Vertex donor: W3DBridgeGetModelVertices.cpp, row 0x000DDE13, 1179 bytes.
Family B shard 1/2 allocation approves this TU; normal file claims cover both
sources and this evidence. The earlier texture repair remains a separate
commit. No source merge, routing edit or identity retirement is part of this
repair. Current parent-directory planner evidence and prerequisites reviewed.

## Target evidence and bounded repair

The seed and vertex donor used different Vector3 views. Composition emitted
that by-value type after the seed's fields. Give both the donor's vector
operations plus the seed's existing subtract/right-scalar operators. Preserve
the donor's explicit component assignment and out-of-class addition because
its 1179-byte body depends on those codegen choices. Keep the seed's two
endpoint copies as Coord3D assignments, matching the existing three-word copy
and the destination's actual declared type. Both views are twelve bytes.

The seed's MeshClass had the verified eight-byte reference-count prefix and
model pointer at +0xC4; the vertex donor used padding across that prefix and
read the same pointer through bridgeModel. Reconcile the donor to the seed's
reference-count base, retain the +0xC4 model pointer and existing bridgeModel
accessor, and cast that accessor to the seed's existing index-query view.
This derives the common pointer position from matched target bodies; it does
not assert that either partial model view is a recovered complete class.

Add forward declarations needed before the combined class/global declarations,
and the existing vertex method/anchor declarations to the seed. No globals,
virtual slots, flags, imported names or generated rows change.

The explicit-assignment trial initially changed the seed's endpoint copies;
implicit assignment instead changed the vertex body. Neither failed trial is
left in Code/. The final Coord3D copy preserves both. Forward declarations then
exposed the reference-count conflict, followed by the missing method declaration;
each was addressed within these same two claimed sources.

## Standalone verification

./build.sh seed vertex: 19/19 exact, four float literals. The unchanged
destructor donor supplies four additional rows; eh_verify on all three reports
5/5 EXACT. find_declared_unmatched, class gate and ms_header_audit check pass.
The vertex anchor remains its preexisting admitted unclaimed inline helper.
allowed_symbols on all three: 52 references, zero wrong bindings. Including
located EH-label aliases, the scoped comparison covers 56 references/23 rows.
data_check on all three: zero findings/outside baseline. --converged on changed
sources: ten addresses, zero second names or unjudged rows.

Before/after standalone bytes, relocations, undefined names, data facts and
COMDAT selection/flags agree, except that the seed now emits the already-used
seven-byte bridgeModel accessor. That added COMDAT is an exact byte/relocation
and selection/flag twin of the existing vertex provider. No other external
definition changes. Normalize only compiler-local EH label renumbering.

Scoped receipts and observer scripts are under build/sol-b5-bridge-vertex-*;
they use upstream allowed_symbols, link_census, data_check and tu_skeleton
verifier objects. No hand compile into build/match, link cycle, smoke or
nightly measurement is used.

## Demonstrated composition and remaining prerequisites

The full normal tu_skeleton --merge --dry-run now accepts seed, destructor
and vertex donor: 23 rows, versus seed/destructor's 22 before this repair.
It admits the existing 1179-byte vertex body; it does not recover new C++ bytes.
All 56 composed code references retain their original bindings. All 44 external
definitions retain original bytes/relocations, COMDAT selections and flags;
there are no dropped definitions, new undefineds or divergent provider copies.
Upstream Identity/link_order selects equivalent provider facts for all 44
names. Data binding and definition unions agree exactly. The composed object
also passes eh_verify --objdir: 5/5 EXACT. No source merge was applied and no
later Luna landing is claimed. Leave this accepted three-source subset to Luna.

Normal remaining rejects: GetModelVerticesFixed has WWMath/header redefinitions;
BridgeLoad has Matrix3D::Rotate_Vector view conflicts; refill lacks the matching
counter/state declarations; AddBridge requires W3DTerrainLogic declarations and
Region3D adoption. Three mixed donors remain intact. Do not infer any of these
are fixed by the accepted subset.

The parent-directory name_lane planner was regenerated after the repair and
consolidate --check build/consolidation passes. check_csv passes. The affected
sources have no code/data/header/hatch/flag register keys; no debt is retired.

## Complete pending batch audit and publication handoff

Audited merge base dcd3113876c6b85160a6d8e7dc366d47ddebc94a through HEAD
plus the staged repair: PropDraw key declaration, Bridge texture teardown,
this Bridge vector/mesh prerequisite and evidence. No source paths or ledger
rows move. Active tools, hooks, workflows, includes, build inputs, registries
and original EA path strings need no repoint. Protected registers are unchanged.
The scoped object proofs cover every changed provider and composed consumer.

If publication is deferred, retain the pending file claims until the runner
lands the batch: PropDraw.cpp, Drawable/W3DPropDrawPoolKey.cpp, the PropDraw key
handoff, W3DBridgeBuffer.cpp, W3DBridgeDestructor.cpp, W3DBridgeGetModelVertices.cpp,
and the two Bridge handoffs. The reverted PropDraw module-data constructor
trial claim was released; the unused Bridge blocked-evidence claim was released.
Release these remaining file claims after confirmed publication and run claims
release --landed. No new RVA claim is outstanding for this declaration repair.

Other allocated probes this session: htree retains its imported-stricmp/CRT
provider and pivot-layout prerequisites; UDP retains alias/naming overlap and
private member declarations; AptInput needs its full CIH/pool views; Supply's
key repair is already absorbed; Laser retains constructor/texture-view ABI
conflicts. NAT plan includes several Common donors reserved for family A;
no cross-family donor was claimed or edited. Ghost's known STL provider/C1001
blocker was not retried. Inherited Tree prerequisite f23698e816 was confirmed
upstream and its seven claims released before new work. BFME1 official fetch
was verified against the retained clean reference, but inherited full reference
update validation remains incomplete; no freshness success receipt was written.

File reduction 0; identity debt retired 0; recovered C++ bytes +0; measured
LINKED gain +0. Together these three commits demonstrate two destination TUs
accepting seven additional existing donor rows (1366 retail bytes); they are
prerequisite improvements, not seven new recoveries or confirmed Luna landings.
