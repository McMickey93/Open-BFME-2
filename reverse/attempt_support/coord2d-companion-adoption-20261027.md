# Coord2D constructor-companion queue retirement

Inspected revision `028575016a` on 2026-10-27, after the separate checker
repair reached origin/master. The default picker claimed `class:Coord2D`.
The [checker evidence](header-coordinate-companions-20261027.md) records the
false rejection and the existing retail-evidenced constructor companions.

These six queued sources already include Coord2DCtorView.h and contain no
private Coord2D definition. No source, header, function row, pin, compiler
flag or hatch changes are needed. In particular, this does not replace the
registered POD header in its other consumers or infer new class identities.
Source SHA-256 witnesses collected before publication are identical after
the rebase. The coordinate headers and AGENTS.md also remain unchanged.

| Existing source | Matched rows | Ordinary preview authored bytes |
| --- | ---: | ---: |
| Code/GameEngine/Source/Common/Rva000A953BCtor.cpp | 3 | 110 |
| Code/GameEngine/Source/Common/Rva005CEA1CHolderRva005CEA1C.cpp | 1 | 25 |
| Code/GameEngine/Source/GameClient/GUI/ControlBar/ControlBarScheme_drawLayers.cpp | 2 | 86 |
| Code/GameEngine/Source/GameLogic/Object/Contain/HordeTransportContainCtor.cpp | 2 | 159 |
| Code/GameEngineDevice/Source/W3DDevice/GameClient/Rva001041D8Dtor.cpp | 10 | 291 |
| Code/GameEngineDevice/Source/W3DDevice/GameClient/Rva0010461FCtor.cpp | 10 | 978 |

Validation and retirement:

- The normal `./build.sh` cohort passes 28/28 matched rows, all string,
  floating-point and import-reference checks. Four renumbered funclet labels
  in the last constructor are verified through the parent's EH data.
- `find_declared_unmatched.py` passes for every source. `eh_verify.py` reports
  three EXACT graphs, no differences, no baselined differences and no missing
  objects.
- The ordinary `link_check.py` cohort reports six LINKS against published
  index `73061d9452` (2026-10-27 14:34). The 1,649 preview bytes describe
  already existing source. The historical-index comparison for the destructor
  is 279 -> 291; this acceptance changes no code and earns no linking gain.
- After the checker published, `header_adopt_lane.py accept --class Coord2D`
  with all six full source paths, without a header override, reports six PASS
  verdicts through the normal byte gates and retires exactly six queue rows.
  No other class/source queue key is removed or added.
- The checker repair's header-adoption, debt-retirement and exploit tests pass
  297 tests with one existing skip. Its separate normal publication succeeds.

Six Coord2D queue rows remain: Rva00062B17Init, AnimateWindowGetVel,
ProcessAnimateWindowRightFastInitReverse, AIStatesSmallUpdates,
MilesAudioManager and coord2d.cpp. Their stale-use, class-key, conversion or
additional member-surface prerequisites remain as recorded in LINK-098.
They were not changed or retired in this pass. No census, ownership,
strict-closure or runtime improvement is claimed.

## Previous batch publication qualification

The checker published as `028575016a` with four already pending commits,
onto outgoing base `4346b5248b`. The normal push hook passes 47/47 function
rows, two data rows, eight EXACT EH graphs, all reference checks and
converged-data enforcement across its expanded eleven-source scope. The
mandatory link batch audit remains INCONCLUSIVE: index `73061d9452` predates
that base, and eleven objects lack current receipts, first
Code/GameEngine/Source/Common/Rva0033BD50Free.cpp. The hook explicitly reports
linking UNVERIFIED. There is no current-master selected-provider or lost-byte
verdict for that batch; carry its scope into the next scheduled census and
current-receipt audit (LINK-008). The six ordinary previews above do not clear
that separate publication prerequisite.
