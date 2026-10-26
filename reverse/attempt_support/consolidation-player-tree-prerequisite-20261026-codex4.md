# PlayerTemplate tree receiver prerequisite, 2026-10-26

Allocated family A shard 1/2 destination:
`Code/GameEngine/Source/Common/RTS/PlayerTemplate.cpp`.
The RTS-scoped planner and current `tu_skeleton.py --plan` identify 77
approved rows, 15 direct donor files and 16 mixed sources. Routing is rebuilt
in memory. No ledger path, row, compiler flag or TU map changes.

## Repair and standalone acceptance

The existing erase/clear owner and assignment donor used incompatible private
views of `Rva001FD42B`; the destructor donor requires a header-handle member
whose destructor supplies the retail unwind cleanup. Share the existing node,
handle and receiver declarations in TU-scoped `PlayerTemplateTreeView.h`.
Erase/clear and assignment access the same pointer through the handle. Keep
the separately rowed copy helper's existing node view, with explicit casts at
its call boundary, as the seed already does for the adjacent tree family.
No original class name or complete STL identity is inferred.

- Before and after official `./build.sh` over the seed, `Rva001FD42BDtor.cpp`
  and `Rva001FD42BAssign.cpp`: all 22 rows match; three string references and
  the float/import checks pass. Three existing funclet pins are verified by
  their parent EH data despite compiler label renumbering.
- Before and after frozen-file scans: all defined functions already matched.
- `allowed_symbols.py --source` reports the same 61 references: 45 owner,
  seven alias, four fold, four EH and one wrong/extent. The pre-existing
  extent finding belongs to the seed's hashtable copy at 0x001FDC0F, calling
  vector erase at 0x00027400. This repair neither changes nor retires it.
- `data_check.py` reports zero findings before and after. No code/data debt
  key for these tree receivers is retired; all protected registers remain.
- `build/codex4-player-tree-proof.py` inspects saved official before objects
  and official rebuilt objects. For all three sources, external code/data
  fingerprints, sizes, exclusivity, actual COMDAT selections, undefined
  references and every row's data-binding facts are identical. The shared
  declaration introduces no standalone provider or consumer change.
- `class_gate.py` over all three sources and the header passes.

Local receipts are `build/codex4-player-tree-{before,after}-{build,identity,data}.txt`,
`build/codex4-player-tree-before-{0,1,2}.{cpp,obj}`, the after-trial/planner
reports and the proof script/output.
The script only inspects objects; it never invokes a compiler.

## Consolidation trial

Before the repair the ordinary dry-run accepted no donors. The destructor
lost bytes in composition and the assignment collided with the seed's
receiver declaration (missing assignment member and incompatible node types).
After repair, the ordinary `--merge TU --dry-run` accepts the seed plus
`Rva001FD42BAssign.cpp`: 21 existing rows / 1,837 retail bytes. The declaration
and node-type conflict is cleared for this pair; no actual merge is applied.
The destructor still reports `bytes` despite its standalone 56-byte match.
The neighboring tree destructor, missing store/vector declarations, STL
redefinitions, mixed donors and census-linked guard remain independent
prerequisites. No destructor merge acceptance is claimed.

The accepted composed object `build/tu_skeleton/ce6e13b58afd08a6.obj` exactly
equals the seed-plus-assignment standalone union: 142 code definitions and
145 external code/data definitions. Fingerprints, sizes, exclusivity and
actual COMDAT policies match that union. Unresolved references equal the
standalone union minus defined symbols. All 21 row data-binding fact sets
are identical in standalone and composed objects. No changed provider,
COMDAT selection or unresolved binding needs additional consumer repair.
This demonstrates an assignment prerequisite unblock for Luna, not a later
confirmed landing.

## Publication audit and measurements

Audit `origin/master..HEAD` together with these staged paths. There are no
source moves or removed paths in the pending batch. The sole new header has
exactly these three direct consumers; all are officially rebuilt together.
Active tools, hooks, workflows, source registries and build inputs require no
path repointing. Original EA paths and the existing stdlib/free ABI queue note
are retained. Historical ledgers and debt keys stay at their existing owners.
No header/MS queue acceptance is claimed. Unrelated `reverse/zh_sweep/` is
preserved.

File reduction 0 (one private header added); recovered C++ bytes 0; debt
retired 0. No census, image-ownership gain or confirmed Luna landing claimed.
Keep the three source claims, header claim and this handoff claim until the
runner confirms publication, along with inherited unpublished file claims.

## Other allocated probes

RadiusDecalUpdate's ordinary dry-run accepts no donor: pool-key needs the
module-name virtual declaration, update needs its members, Xfer needs the
base/xfer contract. The previously accepted constructor/destructor work stays
intact. No virtual slot or ABI was guessed. GeometryParseType's private Xfer
slot layout differs from the canonical header. DockUpdate has a derived
Coord3D contract; ProcessAnimateWindow uses nontrivial Coord2D copy/destruction.
These are inspection-only boundaries, not failed byte conversions. No claims
or source edits remain for them. ModelCondition/Locomotor/ExperienceScalar/
Unpause getter blockers are unchanged from existing handoffs and were not
patched again.
