# GarrisonContain condition-index composition blocker

Inherited trial recovered on 2026-10-26, codex, family A shard 0/2.
Destination: Code/GameEngine/Source/GameLogic/Object/Contain/GarrisonContain.cpp.
Donor: GarrisonContainFindConditionIndex.cpp, findConditionIndex at
0x00477E50, 50 bytes. The existing re_attempts.log entry records the blocked
verdict. No trial source remains in Code and its claims were released.

Adding an OpenContain getObject accessor clears the private-member C2248
diagnostic in a bounded upstream Verifier composition trial, but not the byte
or provider requirements. Standalone/retail accesses receiver+0x08 and body
virtual slot+0x20. Composition with the imported class accesses receiver+0x0C,
adjusts the body by +0x14, and dispatches slot+0x2C. The accessor also emits
an additional unrowed COMDAT. This requires an evidenced BFME 2 receiver/body
contract; changing visibility alone does not repair the prerequisite.

The upstream scoped composition result rejected this donor for bytes and
reported no verified merge of two or more donors. Trial object:
build/tu_skeleton/7d5479a1b68fa1b1.obj. Supporting local receipts:
build/codex-garrison-condition-{scoped-trial,object-proof}.json and the saved
accessor trial .cpp under build. No register, name, pin or layout was guessed.
Skip this unchanged blocker until the shared layout is reconciled.

Shared obstacle-register update was deferred: claiming
file:docs/linking_obstacles.md reported another worker's live claim.
LINK-004 should retain this receiver/body-layout blocker, plus PlayerList's
composition C1001 and ResourceGatheringManager's mixed cost helper and
missing lifecycle declarations. Their separate canonical-header adoptions
retire two queue rows with unchanged full-object and binding facts; neither
claims a demonstrated merge unblock.
