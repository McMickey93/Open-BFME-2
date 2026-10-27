# TunnelTracker Xfer append identity

2026-10-27, inspected revision `fb5c33cf4f`, seat codexb4.

The default picker claimed 0x004F579C and its source for the single divergent
code-identity key in `TunnelTrackerXfer.cpp`. The row already passes byte
verification and the current-object ordinary link preview before this change.
This is identity cleanup, not a new body or new linked-byte claim.

## Evidence and change

Target facts: the 192-byte Xfer row calls 0x0005548F in its load loop. That
address's sole ledger owner is the 26-byte `list<int>::push_back(const int &)`
in `stlport_list_int_o1.cpp`; its native insert provider is 0x005925E2.
The existing TunnelTracker constructor and destructor views both declare the
transfer list at +0x14 as `list<int>`. The main TunnelTracker source already
binds four-byte appends to this same owner. The previous Xfer view instead
instantiated `list<ObjectID>::push_back`, producing the divergent registered
binding. No new donor evidence or complete class-layout recovery is asserted.

Use the existing integer list view at +0x14, declare the rowed append out of
line, and pass the transferred ObjectID through a const integer reference.
Remove the three now-unused ObjectID list specialization declarations. No
source path, ledger row, pin, alias, shared header or data ownership changes.

## Verification

- Before and after: `./build.sh` verifies the Xfer row, 1/1, all 192 bytes;
  frozen-source checks find every defined function matched.
- `allowed_symbols.py --source`: six references, six owner bindings, zero wrong.
- Initial identity retirement correctly refused a missing TransportAIUpdate
  object and stale Team/ScriptEngineDoXfer providers. Refreshing those sources
  through `./build.sh` verifies 54/54 plus 79/79 rows, with verified parent EH
  data for renumbered labels and four complete STLport constructor folds.
- `repair_queue.py retire identity` then passes and removes exactly the one
  source key, with zero still found. The register is changed only by that tool.
- Shadow and converged data checks: zero findings.
- Paired ordinary `link_check.py` with `stlport_list_int_o1.cpp`: both keep
  LINKS, 192 + 667 = 859 authored bytes, before and after, index `bf3dd31211`
  (2026-10-27 00:39, retail-truth-4). Its unreferenced integer _Construct
  diagnostic remains outside the blocker set. No new census result claimed.

The earlier TunnelTracker consolidation handoff remains valid for its other
receiver and shared-interface prerequisites. This repair resolves only the
Xfer append identity key and preserves current matched/preview-linked coverage.

## Recovery reconciliation (2026-10-28)

Retain the source repair, but keep the upstream divergent identity key.
Rerunning `repair_queue.py retire identity` now refuses retirement because
74 ledger objects are missing and 12 referenced provider objects are not
proven current. Its examples are W3DLightDraw and MilesAudioManager.
The original successful retirement above used the earlier object's complete
provider set; it is historical evidence. Refresh current providers before
retrying retirement. No current debt reduction is claimed for this key.
