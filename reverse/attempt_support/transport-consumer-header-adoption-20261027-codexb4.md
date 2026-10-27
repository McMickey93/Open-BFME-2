# Transport consumer header adoption, 2026-10-27

Inspected revision: `3626999202`. The default picker claimed `class:Transport`
and the five consumer files in its header queue. The BFME 1 freshness receipt
is dated 2026-10-26; no reference refresh was needed.

Replace the declaration-only Transport views in Rva0025DDD2Float.cpp,
LANAPIInit.cpp and LANAPISetLocalIP.cpp with the existing canonical
Code/GameEngine/Include/GameNetwork/Transport.h. The statistics declarations
were already supplied by the earlier statistics-header prerequisite; both LAN
consumers already use the address-struct init signature in that header.
There is no new member/layout/name recovery or shared-header change.

Verification:

- Before editing, find_declared_unmatched.py passes all five consumers.
- Normal build before: 17/17 matched rows across all five files, six string
  literals and six imports verified. After: all eight rows across the three
  changed consumers pass, with the same six literals and six imports.
- find_declared_unmatched.py --fail passes the three changed sources;
  eh_verify.py finds no EH-bearing rows in them.
- header_adopt_lane.py accept --class Transport passes each changed source
  and retires exactly three queue rows through the owning tool.
- Paired ordinary link_check.py calls use census index bf3dd31211
  (2026-10-27 00:39). Every one of the five consumers remains LINKS:
  Rva0025DDD2Float 276, ConnectionManager_doRelay 713, LANAPIInit 256,
  LANAPISetLocalIP 157 and Transport_init_AsciiString_Rva004d5534 104
  authored bytes, 1,506 -> 1,506 total. These are preview scopes, not new
  census measurements or a linked-byte gain.

The remaining two queue rows stay registered and their sources are unchanged.
ConnectionManager_doRelay directly accesses m_inBuffer; the canonical header
keeps that array and its nested Message type private, whereas NetPacket's
existing constructor takes TransportMessage*. A coherent receive-buffer
interface and message identity are prerequisites. The AsciiString initializer
defines init(AsciiString, unsigned short), absent from the canonical header;
its current outlined string lifetime must also be preserved when adopting it.
These are existing header-surface blockers, not evidence of missing retail
functions. No source trial, pin, alias or marker was added to work around them.

The prior Transport composition obstacles remain separately recorded in
sol-b5-transport-header-prerequisite-20261026.md; no merge was attempted here.
Local raw receipts: build/transport-header-{before,after,accept}.log and
build/transport-header-link-{before,after}.log. Header debt decreases by three;
no source paths move and no code/data identity retirement is claimed.
