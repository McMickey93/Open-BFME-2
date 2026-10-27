# StructureCollapseUpdate TU approval

Selected by `next_work.py --claim` on 2026-10-27. The current-input
`tu_skeleton.py --plan Code/GameEngine/Source/GameLogic/Object/Update/StructureCollapseUpdate.cpp`
reports **0 approved rows, 1 donor file, 0 mixed files, 0 refused files**.
No merge or TU-map edit was attempted.

## Target facts

- `StructureCollapseUpdate::doPhaseStuff`, 0x004A43E9 / 200 bytes, already has
  a matched row in `StructureCollapseUpdate.cpp`. Its old `present-unmatched`
  marker and the corresponding hatch-register entry are removed in this change.
  `./build.sh` verifies all six rows in the file, including its EH rows.
- The ledger gives 0x004A4DBE / 96 bytes to
  `StructureCollapseUpdate::doCollapseDoneStuff` in the same source. Its EH
  handler is 0x0078DDE3 / 10 bytes and its rollback funclet is
  `$L68557`, 0x0078DDD6 / 13 bytes, with a `parent=` token naming that method.
- `RubbleRiseUpdate.cpp` already documents the 0x004A4DBE ownership problem.
  Its matched update at 0x004A4F72 calls that body through an explicit
  StructureCollapseUpdate cast. Conversely, the matched StructureCollapse
  update at 0x004A46BF uses 0x004A44B1 / 122 bytes, currently owned by
  `Rva004A44B1::doCollapseDoneStuff`. That body also conditionally destroys
  the object; the 96-byte body only stops BoneFX.
- The consolidation catalogue records retail paths for both TUs:
  StructureCollapseUpdate.cpp at string RVA 0x00852680, RubbleRiseUpdate.cpp
  at 0x008528A0. These paths prove TU names, not the helper's method name.

## Donor facts and remaining inference

`reference/open-bfme-1/game/GameEngine/Source/GameLogic/Object/Update/RubbleRiseUpdateDoRubbleDoneStuff.cpp`
defines `RubbleRiseUpdate::doRubbleDoneStuff`. Its comment reports BFME 1
ILT-oracle evidence at 0x002A38A0 and distinguishes it from BFME 1's real
StructureCollapse helper. This is a naming lead for BFME 2; the donor's
oracle was not rerun here and its name alone is not independent BFME 2 proof.

The existing callers, distinct helper behavior and retail TU anchors support
reconciling the 96-byte helper's owner with RubbleRiseUpdate before attempting
the TU merge. Contiguity alone must not be used to make that edit.

## Tool boundary and next step

The read-only probe

```
python3 tools/rename.py function --rva 0x004A4DBE \
  --new '?doRubbleDoneStuff@RubbleRiseUpdate@@IAEXXZ' \
  --basis canonical:bfme1 \
  --evidence 'reference/open-bfme-1/game/GameEngine/Source/GameLogic/Object/Update/RubbleRiseUpdateDoRubbleDoneStuff.cpp:58' \
  --dry-run
```

refuses the class-owner change as beyond an identifier-only rewrite, before
grading canonical evidence. This is an unsupported operation, not a false
reject. No name or row was changed, and no canonical name claim was admitted.

A supported owner-reconciliation operation must account for the body, handler,
funclet parent, callers, old-row tombstones, pins and path-keyed debt. Establish
the BFME 2 method-name evidence separately, then rebuild the current TU plan.
Keep 0x004A44B1's distinct ownership in view; renaming the entire
StructureCollapseUpdate class would corrupt its real methods. No linked-byte
gain or completed consolidation is claimed by this handoff.
