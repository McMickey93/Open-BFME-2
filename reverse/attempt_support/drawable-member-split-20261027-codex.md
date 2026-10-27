# Drawable member split and retained prerequisites, 2026-10-27

Inspected revision: `974dc48d85`; census/index `bf3dd31211` from
2026-10-27 00:39. This is cleanup of an existing matched 18-byte forwarder at
`0x00271BCC`, not recovery of a lost row. The split trial was fully reverted.
No source path, row ownership, TU-map assignment or Microsoft-header queue
change from the trial is retained.

## Retained prerequisite repairs

- `e43aa28492` removes two repeated linker directives from
  `Drawable/Rva00319831Copy.cpp`, reducing the hatch register by two. Its one
  matched row and 58-byte ordinary link preview are preserved.
- `74f835bf22` replaces the private GameLogic declaration in
  `Common/RvaMixedMemberForwarders.cpp` with the canonical header and a cast
  for the existing ArmySummarySystem view. All five rows/100 bytes match;
  six external code definitions, relocations and unresolved references are
  unchanged. `header_adopt_lane.py accept` retires its one header-queue row.
- `974dc48d85` gives Drawable.cpp the same canonical header and removes the
  unused AIUpdate header that transitively reinstated the donor GameLogic
  declaration. All four rows/369 bytes and its EH graph match. Its seven
  external code definitions, recursively resolved local EH data, icon-array
  payload/relocations and unresolved references are unchanged.

The pre-existing icon-array data-name finding remains: the source spells
`?TheDrawableIconNames@@3PAPBDA`, while the ledger at `0x009BB660` names
`?g_00DBB660@@3PBDB`. No data debt is retired or new global introduced.

## Split trial and stopping condition

The supported planner was refreshed with `name_lane.py consolidate --under
Code/GameEngine/Source/GameClient/ --out
build/consolidation/drawable-20261027-codex`; its freshness check passed before
applying `tu_skeleton.py --split
Code/GameEngine/Source/Common/RvaMixedMemberForwarders.cpp --for
Code/GameEngine/Source/GameClient/Drawable.cpp`. Placement was rebuilt in
memory: the selected row has an approved Drawable destination. No regenerated
whole TU map was retained. An earlier broad merge dry-run was interrupted
after about 13 minutes without a completed donor verdict; it is not evidence
that the whole donor set is ready.

The bounded split passed its combined residual/destination guard. Nine rows
remained exact: four/82 bytes in the residual and five/387 in Drawable, versus
five/100 and four/369 before. Both previews reported LINKS, with their combined
469 bytes unchanged. All 36 external code/data definitions and unresolved
references were unchanged, including local EH data after compiler label
renumbering. A comment-only path update in PinnedForwarders1830.cpp also passed
30/30 rows; that comment change was reverted with the split.

The final consumer audit found two append-only parameter-name records in
`reverse/name_basis.csv`: `agree:nl-2fb181b2bb24` (`immediate`) and
`agree:nl-5937838b0581` (`buffType`). Both record the old mixed source and
`0x00271BCC`. The original agreement/vote records are historical evidence and
must remain intact. `rename.py landing` and `check_renames` follow recorded
whole-file moves, but cannot route these records through this partial-file
move. The old mixed file survives, so an inverse parameter rename would still
select a source that no longer defines the method. `tu_skeleton` does not
carry this naming provenance. Per docs/naming.md, rename.py is the only writer
of the append-only basis register; no direct edit or fictitious whole-file
rename was used to conceal the problem.

Before retrying, provide a supported, tested way for naming checks and inverse
renames to follow row-scoped source moves while preserving those original
records. Then refresh the planner and repeat the supported split and combined
guard. No C++ code-generation blocker remains in this bounded composition.

## LINK-017 / LINK-042 batch handoff

The shared obstacle register was claimed by another worker, so this handoff
records the scoped result without editing that file. Neither obstacle is
cleared globally. The broad source batch's strict-receipt preparation passed
42/42 rows across four prepared objects. The eight-object trial overlay against
333 retired indexed objects reported an INCONCLUSIVE older-index baseline,
1,794 provisional provider disappearances and one wrong selected hashtable
provider, with no lost-byte or possible-loss lines. After reverting the split,
the two restored sources passed strict receipt preparation again (9/9 rows).
Repeating `link_batch_audit.py` over the seven retained sources at base
`587692cfb8bc9d7993f9b28f2435756511009ad8` produced the same findings and
333 retired objects, with no missing current-object receipts. No source paths
move in the retained outgoing batch. `check_csv.py` and the staged hatch check
pass. The Microsoft-header queue and all split ownership edits were restored.

The hashtable finding matches the existing LINK-017 current-frame-counter
entry: the constructor at `0x003A37FA` is currently rowed in Team.cpp, while
the bounded overlay selects ArmorHashMapCtor003A393A.cpp after retiring the
indexed STLSweepW5 provider. Sample disappeared xfer methods remain rowed at
`0x004830A9` in PoisonedBehavior.cpp, `0x003915AE` in RadiusDecalUpdate.cpp,
`0x004F5F4A` in ResourceGatheringManager.cpp, and `0x004A2C30` in
StealthDetectorUpdate.cpp. These current rows are not proof of wider provider
closure. No hashtable/xfer definition was edited here. A fresh maintainer
census with the full current provider set remains necessary; no measured
LINKED, LINKING or image-ownership gain is claimed.
