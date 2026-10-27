# Projectile-stream module-data composition, 2026-10-27

Seat codexb5; initial upstream revision 0f2cabf5a8. Destination:
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DProjectileStreamDraw.cpp`.

## Verified prerequisite

The supported Draw consolidation planner was regenerated and its original-path
packets, alternatives and blockers reviewed. The normal merge verifier rebuilds
routing in memory: 32 approved rows, five whole sources, three mixed sources.
Before this change it accepts no multi-source subset: the module-data destructor
fails bytes, and the draw constructor, destructor and module fail compilation.
This reproduces the 2026-10-26 handoff, not a newly discovered regression.

The seed modeled its module-data vptr as a field, with an empty UpdateModuleData
base and a cast-based Snapshot destructor. Use the destructor donor's existing
canonical Snapshot base view and virtual destructor declaration instead. Remove
the manual vptr field/initializer and raw vtable identifier declaration. This is
reconciliation of two TU views, not recovery of a complete native ModuleData
hierarchy. Target facts: constructor 0x000D11D2 installs VA 0x00BCDF18, texture is
at +8, and destructor 0x000D1226 ultimately installs Snapshot's VA 0x00BBB554.

The seed retains all 10 matched rows and its field-parse data row. The constructor
and its EH companions remain exact. The normal merge dry run now accepts the
seed and ModuleDataDtor donor, 14 rows, with its linked-unit guard satisfied.
An observer captures the normal verifier's composed object without altering
routing, flags, admission or compilation into the match cache. All 19 relocation
bindings and 13 external function definitions match the standalone pair; no
external definition is lost, no new undefined name appears, no preexisting
external variants disagree, and all 13 selected-provider facts are unchanged.
Data binding/definition sets are equal. EH verifies three parents EXACT.

The prerequisite changes compiler emission as expected: the artificial
nonvirtual UpdateModuleData destructor disappears; canonical Snapshot's
constructor and the existing module-data scalar deleting destructor are emitted.
Every previously retained function's digest and COMDAT flags are unchanged.
The scalar deleting destructor is the donor's already-rowed 28-byte body.
The new-variants check passes. The ordinary preview against bf3dd31211 still
reports the stale duplicate getModuleNameKey provider absorbed before this
session; it does not establish a new link loss or a census gain.

find_declared_unmatched and class_gate pass. Converged data verification checks
ten addresses with no second names or unjudged rows. Existing seed pool-key data
identity debt remains: retirement refuses the renamed static guard/key findings
at 0x009EBC1C/0x009EBC18, so no key is removed. No identity or header/MS-header
queue entries belong to the accepted pair; no hatch or compiler flag changes.
The module donor retains its separate data debt and two optimize hatches.

## Remaining prerequisites

The draw module and destructor still fail composition on missing declarations
before pointer types; the draw constructor sees an undefined DrawModule base.
The three mixed files (W3DDrawNameGetters, W3DDrawModuleDeletingDtors and
RenderObjO1Inlines) require their own supported splits. Preserve their rows and
private views until separately reconciled. No byte-coverage, census-linked or
image-ownership improvement is claimed by this prerequisite.

Scratch receipts: build/codexb5-projectile-prerequisite-facts.json and
build/sol-b5-projectile-composition.json, -composed-bindings.json and
-composed-selection.json. No source path changes occur in this prerequisite.

## Applied merge and path audit

The supported --merge operation absorbed ModuleDataDtor.cpp, repointing its four
function rows and two existing TU-map source cells. It did not regenerate the
committed map. The resulting TU passes all 14 rows, its data row, one literal,
one empty-string reference and all three exception graphs. find_declared_unmatched
passes. The donor has no protected-register keys, hatches, header-queue entries
or data globals to transfer; the seed's surviving data debt remains owned.

The entire outgoing batch has one absorbed path, ModuleDataDtor.cpp to the seed.
Searches of tools, hooks, workflows, Code, docs and reverse find no active path
consumer requiring repair. Remaining old-path mentions are historical source
provenance, functions.csv notes, the census-owned link_status.csv snapshot, a
GpuDrawModuleInfoDtor example comment and banked evidence. Keep those histories.
The planner was regenerated after the merge. Active ledger sources are tracked,
and queued blocked donors remain intact. The scope loses one source file and
claims no additional byte or census coverage.

Before the final commit, upstream was rebased through e7da23e761 and the revised
AGENTS.md read. The prerequisite is now de531e7601 (the starting handoff is
dc72bb7347); all 14 rows pass again after the rebase. The earlier shadow batch
audit was inconclusive against bf3dd31211 with 15 missing current receipts,
first DetachableRiderDataRva004AEB84.cpp. The updated audit requires a committed
tip; its result must be recorded separately. None of these input limitations is
a clean whole-batch link verdict or authority to re-run the census.

## Data-index follow-up and current batch limit

The earlier data retirement refusal was caused by stale index identities, not a
second current source definition. The official data-ledger generator, run to
scratch with no missing source objects, identifies one owned TU-static definition
and two references in this TU for each of 0x009EBC18 and 0x009EBC1C. Copy only
those two unmodified generated rows into the committed index: the current getter's
local pool key and initialization guard replace obsolete rva0000D140A spellings
and the retired GlobalFlagClearers guard provider. No current Code source retains
those old names. The old external guard clearer already has its deleted-row
receipt; the getter's compiler-owned rollback at 0x00762992 remains EH-exact.

Ordinary data checking now has zero findings, and repair_queue.py retire data
removes the seed's one data-debt key. Converged checking still covers ten
addresses with no second names or unjudged rows. This repairs the scoped index
and retires that register key; it adds no source, pin, data-row or independently
verified data-ownership claim. The rejected module donor's debt remains.

The merged seed has a strict current receipt and passes the new-variants check.
After refreshing the available link index, the revised link_batch_audit against
base e7da23e761 and the committed source tip still returns INCONCLUSIVE: index
bf3dd31211 predates the outgoing base and lacks per-object consumer names. The
refresh imported 19,526 compiled objects without changing that published index.
The bounded provider/binding and merge-guard evidence above remains valid for
its stated scope. Whole-batch link closure is unverified and needs the next
normal census with complete consumer inputs; no census or smoke run was started.
