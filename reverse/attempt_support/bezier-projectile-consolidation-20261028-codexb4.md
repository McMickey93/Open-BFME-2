# BezierProjectileBehavior consolidation handoff

2026-10-28, codexb4. Initial checkout: `6ed441010c`. Published prerequisite:
`f37de6bb3b` (parent `f7755f211c`). This is a composition attempt, not a
byte-match regression or a newly recovered body.

## Scope and evidence

The default claimed picker selected
`Code/GameEngine/Source/GameLogic/Object/Behavior/BezierProjectileBehavior.cpp`.
The supported planner and the merge tool's current in-memory TU approvals
identify 47 approved rows, ten whole-file donors and five mixed sources.
The committed map was stale; no regenerated map is committed. The planner
was regenerated after publication and its currency check passes. Original-path
placement and structural similarities support investigation, not additional
recovered names or layouts.

All inspected definitions are already matched. Initial supported merge dry-run
accepts no donor. The destination lacks declarations needed by its satellites;
their private views also disagree about inheritance, field names and compiler
settings. `tu_views.py --dry-run` reports those conflicts; no bulk view rewrite
was applied.

## Verified prerequisite

The existing `Bfme5FortyThree.cpp` cost accessor uses twelve-byte elements and
start/finish pointers at +0x44/+0x48. The published change makes that existing
contract available in the destination: its declaration, the element type,
pointers and size helper. No new retail name or donor provenance is inferred.

- Normal paired build: 9/9 function rows exact; the destination EH graph is
  EXACT. Frozen-file and class checks pass.
- All 21 destination external COMDAT digests are unchanged against the saved
  pre-edit object. External definitions and dependencies are unchanged.
- Both sources have strict current verification receipts from
  `link_check.py --prepare-current`.
- No source path, ledger row, pin, hatch or debt register changes.

## Blocking evidence

After the prerequisite, the supported dry-run gets past compilation and byte
verification for the cost donor, then refuses it at the link guard:

> a file without a census object would place the merged unit earlier in link order than the guard can judge

The donor is census-linked (29 authored bytes in its ordinary preview). The
destination is absent from the index, so its relative link position is
unverified. The initial index was `14dc3d2467` (underlying census `73061d9452`).
After a newer census became available, a fresh fetch obtained `54b83e4f69`;
ordinary destination preview still explicitly refuses it as absent from that
census. This is a missing evidence prerequisite, not a demonstrated false
reject. No applying merge was attempted and no guard was bypassed.

The other nine donors remain compile-rejected: Fire, Dtor, PoolKey, Update,
Rva0045C812, Rva0045C975, Xfer, Xfer_Rva0045CC72 and Collide. They need
separate verified declaration/view reconciliation. The mixed ModuleNameGetters,
Rva0055A246Ctor, BezierProjectileBehaviorCtor, BezierProjectileBehaviorSlots
and ModuleDataBuildFieldParse sources remain untouched.

## Next step and limits

Wait for the normal census and published index to contain the destination,
then rerun the supported planner/currency check and merge dry-run. Do not
infer permission to run a census directly. Reconcile additional private views
in their own verified commits before retrying their donors.

The outgoing batch audit against parent `f7755f211c` exits 2, INCONCLUSIVE.
Index `54b83e4f69` predates that base. After refreshing both edited/provider
receipts through the normal verifier (9/9 exact), it also reports an affected
consumer without a current receipt:
`Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp`.
Selected-provider coverage is unverified; carry that consumer and this scope
into the next normal census. The unchanged destination COMDATs do not replace
that missing consumer evidence. There are no source-path moves requiring a
path-consumer migration audit.

No source-file reduction, debt retirement, new linked bytes, runtime result or
image ownership gain is claimed. The cost-view prerequisite is complete; the
composition remains blocked. Carry this scope into the next normal census.
