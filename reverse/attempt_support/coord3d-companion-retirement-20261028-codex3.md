# Coord3D companion-header debt retirement

Inspected base `523e91ba00` on 2026-10-28. The default picker claimed
`class:Coord3D`; the four source scopes were also claimed before acceptance.
The BFME 1 freshness receipt is current, and the initial CSV check passes.

The false rejection recorded at `0x0027EDBC` has already been fixed by
`e46cd47132`. Three queued units include the existing
`Lib/Coord3DDerivedView.h`; OneRingPenaltyUpdate includes `Lib/Coord3DInline.h`.
Those exact companion paths are now recognized by the header acceptance tool.
All four units contain no private Coord3D body. This pass changes only the
header queue and its evidence; the game sources, shared headers, compiler
flags, function rows, pins and hatches are unchanged.

| Existing source | Matched rows | Ordinary preview linked bytes |
| --- | ---: | ---: |
| Code/GameEngine/Source/GameLogic/Map/BridgeObjectCtor.cpp | 7 | 1,683 -> 1,683 |
| Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeBehaviorHandleObjectsOnBridgeOnDie.cpp | 4 | 448 -> 448 |
| Code/GameEngine/Source/GameLogic/Object/Update/OneRingPenaltyUpdate.cpp | 5 | 482 -> 482 |
| Code/GameEngine/Source/GameLogic/SkirmishAI/AITacticalAI/AITacticsGenerator/TargetlessTactics/AIStructureCreepTactic.cpp | 52 | 0 -> 0 |

Verification, with all four full paths as arguments:

- `find_declared_unmatched.py` passes on every source. The tactic also
  reports one unclaimed definition without refusing the source; it is unchanged.
- Normal `./build.sh` passes 68/68 function rows, five literals, one empty-string
  reference and thirteen compiler float literals. Existing renumbered funclets
  are verified through their parents' EH data.
- `eh_verify.py` reports 11 EXACT EH graphs, no differences, no baselined
  differences and no missing objects.
- `link_check.py` uses fetched index `41c28839bf` (2026-10-28 11:08).
  Three units preview LINKS and preserve 2,613 authored bytes. The tactic
  remains blocked by the selected `vector<Object*>` destructor, push_back
  and _M_insert_overflow copies. Its authored scope is 4,226 bytes; none
  becomes linked here. This is the existing fold-order/container-provider
  prerequisite recorded under LINK-132, not a header-adoption failure.
- `header_adopt_lane.py accept --class Coord3D` reports four PASS verdicts
  through its own normal byte and per-unit link guards, and retires exactly
  these four queue rows. No other class/source key is changed.

Source SHA-256 witnesses (in table order):

```text
7502e799b5e4aced0acfcef2f2fdee878ea5f67891d6383a06affcf930541b5c
9637922539a5d5c1498bb67dc8033ac9276138e120add126aa5368f4794d9fa8
d58ec3b765da7ed5066bee2c400de34017275a1cff6e9433a064c952bb8a9198
0845cdf73b07e46d94e5e17acbc6af8a161553aaac44d4ab47f0653b6f5225e6
```

Eleven Coord3D queue entries remain. Their class-key, lifetime, conversion
and additional member prerequisites remain separate work under LINK-018.
No census, selected-provider closure, runtime or image-ownership gain is claimed.
