# Squad GameLogic adoption blocker

2026-10-26, codex, allocated family A shard 0/2 target Squad.cpp. Current
--plan routes seven primary rows; SquadGetAllObjectsAndRemoveDead.cpp is
mixed because its vector<Object*>::size row at 0x00597612 is unplaced.
The scoped AI planner and currency check pass. Original-path alternatives
and cross-game shape twins are hints, not complete class identity evidence.

The donor still has an open GameLogic header-adoption row. Replacing its
private ObjectID/GameLogic declarations with the registered
GameLogicObjectLookupView.h compiles and preserves two of three rows, but
the 75-byte rva004D6CAC body swaps ESI/EDI: retail keeps this in EDI and the
ObjectID cursor in ESI; this trial does the reverse. Callee placements and
the 75-byte boundary are unchanged. Moving the iterator declaration outside
the loop does not change that result. The other cache-pruning body (88B) and
vector::size (9B) remain exact. No flags or hatches changed.

This is also a provider prerequisite, not only declaration cleanup. The
before object emits 46 code definitions; the adoption emits 30. The sixteen
removed COMDATs include the private 43-byte GameLogic::findObjectByID and its
hash-map helpers. The canonical existing owner at 0x00049DC5 in
GameLogicFindObjectByID.cpp is 37 bytes. Their common name does not establish
equivalent provider bytes or selection. A future repair must preserve the
three target rows while verifying changed lookup/helper provider bindings;
the smaller trial object alone establishes no link improvement.

Restored the entire source from its verified before snapshot. Declaration
scan passes. No shared header, source path, ledger row, data/code identity
register or header queue row changes; header adoption was not accepted.
The adoption blocker is recorded with re_log.py; source claim released.
The commit gate correctly refused a partial stash for an already-matched RVA,
so that trial stash was removed and the verdict superseded with blocked. Evidence is under
build/codex-squad-lookup-{before-build,after-build,cursor-build,
first-object-proof}. The initial three-row build was exact.

Complete pending batch still has no source moves, renames or deletions.
Active tools, hooks, workflows, includes, build inputs and registries require
no path updates. The attempt is evidence only: no merge, recovered byte,
file reduction, debt retirement or downstream Luna acceptance is claimed.
