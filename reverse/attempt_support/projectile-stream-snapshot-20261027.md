# Projectile-stream module-data composition, 2026-10-27

Seat codexb5; starting revision ca91099184. Destination:
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
