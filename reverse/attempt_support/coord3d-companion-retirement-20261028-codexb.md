# Coord3D companion header debt retirement

Inspected `9d2ee4a0f425e2a5302cc23c6dc6999ec3f56aca` on 2026-10-28;
claimed `class:Coord3D`. This is retirement of already-completed source
adoptions, not a new class layout or source reconstruction.

The false rejection recorded at 0x0027EDBC is resolved by the existing
`e46cd47132` tooling change: `header_adopt_lane.py` recognizes the exact
Coord3DDerivedView.h and Coord3DInline.h companion paths. The following units
already include those shared views and contain no private Coord3D body.

| Source (under Code/GameEngine/Source/GameLogic/) | Shared view | Matched rows | Ordinary preview |
| --- | --- | ---: | --- |
| Map/BridgeObjectCtor.cpp | Coord3DDerivedView.h | 7 | LINKS, 1,683 -> 1,683 bytes |
| Object/Behavior/BridgeBehaviorHandleObjectsOnBridgeOnDie.cpp | Coord3DDerivedView.h | 4 | LINKS, 448 -> 448 bytes |
| SkirmishAI/AITacticalAI/AITacticsGenerator/TargetlessTactics/AIStructureCreepTactic.cpp | Coord3DDerivedView.h | 52 | blocked, 0 -> 0 bytes |
| Object/Update/OneRingPenaltyUpdate.cpp | Coord3DInline.h | 5 | LINKS, 482 -> 482 bytes |

`header_adopt_lane.py accept --class Coord3D` on these four paths reports
four PASS verdicts and removes their four queue entries itself. The normal
combined `./build.sh` passes 68/68 function rows, five nonempty string literals,
one empty-string reference and thirteen compiler float literals. The build
also verifies the existing funclet placements despite renumbered compiler
labels. `find_declared_unmatched.py` accepts all four sources.

The combined ordinary `link_check.py` uses the latest available fetched index,
`41c28839bf` (2026-10-28 11:08). It preserves 2,613 linked bytes in the three
previously linked units. AIStructureCreepTactic remains blocked by selected
`vector<Object *>` destructor, `_M_insert_overflow` and `push_back` copies.
These are the existing LINK-132/LINK-133 provider-selection prerequisites;
the preview exits 1 for that blocked unit. Header acceptance allows unchanged
zero coverage and does not declare the unit linked. This preview is not a
new census measurement, and no linking gain is claimed.

No source, shared header, row identity, pin or TU placement changes. Remaining
Coord3D queue entries retain their class-key, member or codegen prerequisites.
In particular, matrix4d.cpp still requires the identity reconciliation recorded
in the existing Matrix4D handoff; this pass does not repeat that failed trial.

Reproducibility logs (local scratch):
`build/codexb-coord3d-retire-build.log` and
`build/codexb-coord3d-retire-link.log`.
