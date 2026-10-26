# ResourceGatheringManager GameLogic header prerequisite

Recovered inherited work on 2026-10-26, codex, family A shard 0/2.
Destination: Code/GameEngine/Source/Common/RTS/ResourceGatheringManager.cpp.
No source path or function owner changes.

The findBestSupplyWarehouse donor repeated the ObjectID enum and a private
GameLogic declaration. It now includes the registered
Common/GameLogicObjectLookupView.h and uses its ObjectID and GameLogic types.
`python3 tools/header_adopt_lane.py accept --class GameLogic
Code/GameEngine/Source/Common/RTS/ResourceGatheringManager_findBestSupplyWarehouse.cpp`
passes and retires one header-queue row through its acceptance path.

Verification: `./build.sh` on that donor preserves all six matched rows;
`find_declared_unmatched.py` passes. Saved pre-edit verified objects compared
using allowed_symbols, link_check and link_census COFF helpers retain all 18
external code definitions, 35 non-debug sections (bytes, named relocations and
COMDAT policies), external data definitions, undefined names and aliases.
All 24 reference identity facts and every data reference/definition fact are
unchanged. Thus this prerequisite changes no selected provider or consumer
binding. Scoped class, converged-data and two EXACT EH checks also passed in
the inherited session. Local receipts: build/codex-resource-{object-proof,
reference-delta,data-delta}.json and build/codex-recovery-build.txt.

The upstream before/after `tu_skeleton.py --merge TU --dry-run` verdict is
unchanged: seed and ResourceGatheringManagerXfer.cpp accepted (five rows),
destructor rejected C2600 (undeclared constructor) and deleter C2511
(EmitVtableTag constructor absent). The edited donor remains mixed: the cost
helper has no approved destination. This is a header prerequisite retired,
not a demonstrated increase in merge acceptance. The earlier STL receiver
handoff remains applicable. No identity/data key is retired or transferred.

The inherited `link_check.py --prepare-current --paths-from
build/codex-resource-sources.txt` reported preparation inputs moved while
compiling and accepted no strict witnesses. No census improvement follows
from that attempt. Object equivalence above supplies the bounded unchanged
binding evidence; the next normal census retains responsibility for totals.

Compatibility audit: origin/master..HEAD plus this staged adoption contains
no pending source move, rename or deletion. The existing header resolves at
the explicit relative include; no active tool, hook, workflow, build input or
registry needs a path repoint. Original EA evidence remains unchanged.
Claims on the destination, donor, queue and this handoff remain until publish
is confirmed. Recovered bytes, file reduction and identity retirements: zero.
