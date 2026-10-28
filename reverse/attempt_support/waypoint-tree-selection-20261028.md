# Waypoint tree selection recheck

Base `73a4520034`; refreshed index `41c28839bf`. The default picker served
`MapMetaDataCopyDeferred.cpp` at 0x0030200E. The ordinary `link_check` still
reports three non-retail COMDATs and the same three selected-copy failures;
0 of the unit's 856 authored bytes preview as linked.

The earlier waypoint-tree binding check in `docs/linking_obstacles.md` gives
the retail call targets and non-relocation byte comparison. Current ledger
inspection confirms the typed creation and base-constructor spellings already
own rows in `MapUtil.cpp` at 0x0016D760 and 0x0016D590, while the copy chain
calls 0x003012CE and 0x0030087C. The clone spelling remains pinned to
0x00413E55 instead of the chain's 0x00301BBF. Those distinct bodies and their
consumers need a coherent identity and ownership explanation before changing
the bindings. No source trial, pin change, or clearance is claimed.
