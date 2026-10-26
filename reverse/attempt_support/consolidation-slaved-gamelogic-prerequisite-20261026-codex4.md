# SlavedUpdate GameLogic prerequisite, 2026-10-26

Allocated family A, shard 1/2 target:
`Code/GameEngine/Source/GameLogic/Object/Update/SlavedUpdate.cpp`.
Read the Update-scoped consolidation planner, original-path alternatives and
prerequisites; regenerated after the trial removed its temporary source.
The currency check passed before editing. Routing is rebuilt in memory:
28 approved destination rows, six donor files, six mixed files. The repair
source contains 18 rows, including 16 placed here, one Locomotor row and one
unplaced row. No routing override, move, split or merge is applied.

## Repair and checks

SlavedUpdateRepair.cpp now includes the registered
Common/GameLogicObjectLookupView.h, replacing its private GameLogic class and
ObjectID enum. Four zero-sentinel uses take the canonical INVALID_OBJECT_ID.
No method bodies, receiver layout, compiler flags or shared headers change.

- Before/after official `./build.sh SOURCE`: 18/18 function rows and the one
  BfmeSlavedUpdateIntervalFrames data row pass. Eight string references and
  eleven float literals pass; both renumbered EH funclets verify through their
  parent placement. Both frozen scans pass.
- `header_adopt_lane.py accept --class GameLogic SOURCE`: PASS and exactly
  one header-queue entry retired through its acceptance path. Its prior
  data-row failure no longer reproduces on the current tree.
- Before/after `allowed_symbols.py --source SOURCE`: 121 references,
  116 owner, two EH, two alias, one fold; zero wrong bindings.
- `data_check.py SOURCE`: zero findings before and after. Neither identity
  register has a key for this source; no code/data debt retired.
- `check_csv.py` and `git diff --check` pass.

Saved the original verified object as build/codex4-slaved-before.obj and
compared it with the official rebuilt object using upstream
allowed_symbols._object_defs and link_census._comdat_sections. All 62 external
code definitions, all 52 undefined external symbols and all 71 code/data
COMDATs have identical contents/digests, sizes and exclusivity. Nothing is
added or removed. The object path and ordering do not change, so selected
provider candidates and all provider/consumer bindings remain the same;
no affected consumer requires recompilation. This is scoped object evidence,
not a new whole-image census. No composed object is published.

## Remaining prerequisites

The normal merge trial accepts no donors: seed STL allocator explicit
specialization C2950, competing SlavedUpdate views missing rva0004A1875 or
model-condition members, and the Xfer donor's unresolved UpdateModule::xfer.
The supported split trial identifies 13 carveable bodies, with their owned
funclets, but refuses before composition: the residual loses matched
0x001E3459 and 0x0026C26D helper rows. No residual rewrite or flag workaround
was attempted. This is a canonical-header prerequisite cleared for sixteen
destination rows, not demonstrated new merge acceptance or a Luna landing.
The blocked split and merge evidence is recorded through re_log.py.

Receipts: build/codex4-slaved-{before-build,after-build,before-identity,
after-identity,header-accept,trial,split-trial}.txt. Existing data ownership,
identity debt and hatch registers are preserved. File reduction 0; recovered
C++ bytes 0; header debt retired 1; code/data identity retirement 0.

Audit before the commit-and-publish call covers origin/master..HEAD (the
inherited scanner/header batch plus recovery receipt) and this source change.
No game source paths are added, removed, renamed or moved. Active tooling,
hooks, workflows, includes, build inputs and registries need no path repoints;
the canonical include resolves from the donor's existing directory.
Historical EA strings remain. Keep the source, header queue and this handoff's
file claims, plus inherited retained scopes, until publication is confirmed.
No RVA claims were taken. Unrelated untracked reverse/zh_sweep is preserved.

Publication confirmed at bca2dcdf04, with the four inherited/recovery commits
b2962d2d87, bb720e6b3c, 56b70313df and f6e0a2986b. The push hook passed
60/60 rows across five sources. Its link audit was inconclusive: index
d1f046749a differed from outgoing base 0dd5e48e6a, and five source objects
lacked current strict receipts (first Eva.cpp). LINK-017 records that limit;
no linked-byte increase is claimed. All ten landed file claims were released;
release --landed found no outstanding RVA claims. The commit's identity shadow
report includes the divergent Object::getBodyModule definition: the complete
before/after object comparison above proves this adoption did not change that
definition, and no identity key was retired.

Read-only followup probes found no demonstrated new prerequisite in the
allocated ProjectileStreamUpdate, RiderChangeContain, PlayerTemplate,
ControlBarScheme or AITactic targets. Existing composition/ABI blockers were
not retried. In particular AITactic's private Xfer has incompatible virtual
slots; adding forward declarations alone cannot adopt BfmeXfer.h. The
SubsystemInterface naming decision remains reserved to issue #116. No new
merge acceptance or downstream Luna landing is claimed.
