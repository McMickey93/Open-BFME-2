# Spline-effect TU anchor investigation, 2026-10-27

Inspected BFME 2 revision: `704c48ba56`. Reference freshness receipt:
`build/bfme1-last-check.txt`, verified 2026-10-26 at BFME 1
`de077dd5dd8339716a6abe453a1d81dfdf77e651`.

The default picker claimed the no-signal run `0x004E3A6E..0x004E3FFA`:
15 ordinary code rows in ten sources. No source, row, name or map change is
retained. This is missing placement evidence for existing matched C++, not a
matching regression.

## Target facts

`tu_evidence.py --source
Code/GameEngine/Source/Common/Rva004E3CD0Dtor.cpp` emits only its CSV header:
none of its promoted layout signals supplies a placement. The current map
leaves the selected code run without an approved TU. `find_declared_unmatched.py`
across all ten selected sources reports all definitions already matched.
`./build.sh Code/GameEngine/Source/Common/Rva004E3CD0Dtor.cpp` passes 6/6
rows, string/float/import references included; `eh_verify.py` reports its one
parent graph EXACT.

The emitted funclet labels have changed: the gate independently binds old
`$L5188` to current `$L5191` at `0x00791E37`, and `uw_00791e42`'s
`object-symbol=$L5191` to current `$L5192` at `0x00791E42`. Both are already
owned by their real C++ parent. The latter compiler-label alias is exempt from
the hatch register's rule 9; merely respelling it would retire no hatch debt.

## Reference facts and alternatives

The supported planner was run with
`name_lane.py consolidate --under Code/GameEngine/Source/Common/`.
Its packet for `Rva004E3CD0Dtor.cpp` marks all six rows unresolved except the
`0x004E3A6E` identity/file hint. The hint comes from `wb_name_leads.csv`:
`SplineEffect::InitGeometries`, score 1, callgraph pairing, file
`Code/GameEngine/Source/GameLogic/System/LivingWorld/LivingWorldCampaignObjects.cpp`.
The planner explicitly says this is not a verified target TU. The WorldBuilder
path exists in the path catalogue, with independent BFME 1 EA path-existence
citations; neither citation proves this BFME 2 body's placement or name.

Already named `SplineEffect::Execute` and `SetSubObjectColor` rows instead
provide naming hints for
`Code/GameEngine/Source/GameLogic/LivingWorld/SplineEffect.cpp`. The map
marks that proposed cluster noncontiguous. Their WB-derived naming cannot
independently corroborate the same WB pairing under `tu_map.wb_self`.

The upper edge includes a mixed singleton-constructor file:
`Rva0050E9D3SingletonCtors.cpp` owns both `0x004E3FFA` and `0x0043C705`.
It cannot be moved wholesale on a lead for the former, and a merge must not
split a mixed donor. No Zero Hour SplineEffect definition or retail source-path
xref was found for the assigned bodies.

## Remaining prerequisite

Obtain an independently checkable target source-path anchor or a unique,
nontrivial same-body donor/name proof that the current map accepts. Recheck the
WorldBuilder pairing against actual body evidence before proposing a permanent
name; score-1 callgraph vocabulary and matching layouts are not such proof.
Rebuild the map in memory and use `tu_skeleton.py` only after it approves the
selected addresses. Do not hand-approve either competing path, regenerate the
committed map from this lane, or rename the existing parent merely to force a
placement. Claims released after recording this handoff.
