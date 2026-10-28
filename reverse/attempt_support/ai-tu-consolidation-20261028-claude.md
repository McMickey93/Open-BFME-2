# ai.cpp consolidation triage (2026-10-28, claude-opus-5-5)

TU: `Code/GameEngine/Source/GameLogic/AI/ai.cpp` (156 approved rows). Served by
`tools/next_work.py --claim` (TU consolidation, 26 donors / 94 rows). Base
`85ca0e5558`; census index `41c28839bf`.

## Result

`tu_skeleton.py --merge --dry-run` rejects all 26 donors. One donor is
reconciled and landed: `AIGetAdjustedVisionRange.cpp` now builds on the TU's
flags and Zero Hour headers, with retail-offset views for Object
+0xB8/+0x258, AI +0x18 and TAiData +0x4C/+0x50 (1/1 exact, LINKS 138 B
unchanged). It omits the TU's `#pragma optimize` `_STL::max` block, which
the hatch register does not grant to a donor.

## Systemic blocker: the seed's header universe

The seed compiles against the vendored Zero Hour headers (`PreRTS.h`,
`GameLogic/AI.h`, `ScriptEngine.h`, `PlayerList.h`, `Common/AsciiString.h`)
plus views. Most donors need BFME 2 signatures or the bfme2_ascii shim's
AsciiString inlining, which those headers cannot spell and must not be edited:

- AsciiString redefinition (14 donors: AIParseSideInfo, AIConstructor(_Unresolved),
  TAiData, Rva0014AE40OwnerDestructor, Rva002FE620Ctor, AI_xfer,
  stlport_list_nocase4_*, Rva002FED8DCtor/Dtor, AIRva002FEE2CParse,
  StlSweepR3Rva002FFC74, AI_parseAttackPriority). Trial on
  AIRva002FEE2CParse.cpp with Zero Hour's AsciiString: 2/2 rows byte-exact,
  but link_check drops it from LINKS to blocked (138 -> 0 B): unresolved
  `?freeBytes@AsciiString@@AAEXXZ`, non-retail `?set@AsciiString@@QAEXABV1@@Z`
  and list `insert` copies. Reverted; do not move these donors onto Zero
  Hour's AsciiString.
- BFME 2 signatures absent from vendored classes: `AttackPriorityInfo::getPriority(const Object *, const Object *, bool) const`
  (AIBestAttackPriorityCallback), `PlayerList::getPlayersWithRelationship(int, unsigned, bool)`
  (Rva002FE13DHandler), `AI::rva002FE193` (AIObjectTargetPredicate,
  Rva002FE371Forward), `AI::GetSnapshotName` (SubsystemNameGetters3), BFME
  `Xfer` (TAiDataXfer), `TAiData::addFactionBuildList` parameter type
  (Rva0014C090ParseNamedDefinition_Rva002FE9FC). A view class cannot bind
  these, since the call must name the real mangled symbol.
- AI_createGroup.cpp composes but its bytes change; StlSweepR3Rva002FED07/FED53
  would lose their census-linked list `insert` selection.

Next step (maintainer or header lane): move the seed off the vendored Zero
Hour universe onto BFME 2 headers/shims (bfme2_ascii, BfmeXfer.h and BFME 2
class headers), or approve TU-scoped BFME 2 class headers for AI, PlayerList
and AttackPriorityInfo. The donors can then merge without
per-donor rewrites. Twelve mixed files also hold this TU's rows (split lane).
