# LinearCampaignManager TU approval prerequisite

Inspected revision: `4ebcd6f5b255175ac47d557f993c46dd580bec10`.

The default picker served 101 proposed rows in 54 files for
`Code/GameEngine/Source/GameLogic/System/LinearCampaignManager.cpp` (60
bracketed, 41 unanchored). This is structural approval work, not missing
byte coverage. No game source, ownership assignment or map was changed.

Checks:

- `tools/check_csv.py`: OK (98,272 function rows).
- `tools/find_declared_unmatched.py` on the selected source: all definitions
  already matched.
- `tools/name_lane.py consolidate --under Code/GameEngine/Source/GameLogic/System/`
  and its `--check build/consolidation`: snapshot inputs and outputs agree.
- `tools/tu_skeleton.py --plan` on the selected TU: **0 approved rows**.
  The tool rebuilds a stale committed map in memory; the committed map was
  not regenerated.

Target facts: the source owns DoXfer at 0x001EBB73, the block parser at
0x001ED580, and their existing EH rows. The packet grades both bodies' TU
routes as hints: their real class names supply N, and their WorldBuilder
pairings provide identity/file hints. The path catalogue has one entry for
LinearCampaignManager.cpp, sourced only from WorldBuilder at file offset
0x01A1CD30. It has no retail path occurrence or Zero Hour definition/site
anchor for this TU. The packet leaves the five EH rows unresolved.

Donor facts: the catalogue provides no Zero Hour or BFME 1 EA path evidence
for this path. WorldBuilder establishes a path in that build; it does not
establish the retail translation unit.

Structural inference: the proposed contiguous campaign cluster is a useful
investigation group, but naming the already real-named endpoints again
cannot add F/Z/S evidence. Under the current map rules, C rows cannot turn
unapproved brackets into approved ownership. No merge is authorized by
this result.

Resume when independent retail or donor evidence supplies a re-checkable
anchor accepted by the ownership rules, or after a separately validated
layout signal is promoted through the documented verifier workflow. Then
rebuild the plan before attempting a merge. Repeating the same N/WB-only
scan does not resolve the prerequisite.
