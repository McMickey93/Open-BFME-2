# Split pinger global ownership

Inspected BFME 2 revision: `67098f8d8b` on 2026-10-27.
Ordinary preview index: `bf3dd31211`, 2026-10-27 00:39, `retail-truth-4`.

## Retained repair

`Code/GameEngine/Source/GameNetwork/GameSpy/peer/peerPing.c` and
`Code/GameEngine/Source/GameNetwork/GameSpy/pinger/pingerMain.c` previously
defined private copies of the same native state. Their existing data-ledger
owners and names are retained. No new global spelling, pin, row or storage
extent is introduced.

| Native RVA | Existing name | Definition retained in |
| --- | --- | --- |
| 0x009DBDEC | piSocket | peerPing.c |
| 0x00A0C0E0 | piPingerPinged | pingerMain.c |
| 0x00A0C0E8 | piPingerPingedParam | peerPing.c |
| 0x00A0C0F0 | piPingerSetDataParam | pingerMain.c |
| 0x00A0C0F8 | piActivePingList | peerPing.c |
| 0x00A0C0FC | piPingerSetData | pingerMain.c |
| 0x00A0C100 | piLastThinkTime | peerPing.c |
| 0x00A0C108 | piInitialized | peerPing.c |

The consumer declares each variable `extern`; the owner defines it with external
C linkage. Both units now use the existing callback types and unsigned timestamp
type from pingerMain.c. pingerInit's C symbol and machine body are preserved.
A search of `Code/` and `reference/shims/` finds these names only in these two
units. The existing provisional ledger interval for piSocket is not independent
proof of its storage extent; this repair only retains its existing SOCKET
definition and INVALID_SOCKET initializer.

Checks:

- `./build.sh` over both sources: 19/19 rows exact, including two named imports.
- `find_declared_unmatched.py` over each source: all defined functions matched,
  both before and after the edits.
- Paired `link_check.py` over the two current objects: both LINKS before and
  after, retaining 1,604 and 1,166 authored bytes respectively.
- `data_check.py` over both sources: 13 findings before, five after; zero outside
  the baseline in either case.
- `repair_queue.py retire data` retires three keys from peerPing.c and five
  from pingerMain.c. The remaining five keys are preserved.

This is eight data-debt retirements. No census linked-byte or image-ownership
gain is claimed.

## Remaining prerequisites and reversed trials

The remaining piSettingData duplicate at RVA 0x00A0C104 needs a shared-storage
declaration that preserves piProcessTrip2 (0x006B27C0, 230 bytes). Making the
existing peerPing.c definition external and pingerMain.c's declaration extern
preserves the other 18 rows but moves the `piSettingData = 1` store ahead of the
socket-address loads. Retail loads the callback arguments before that store.
Capturing the address and port in two locals before the store also fails: the
frame grows from 24 to 28 bytes and register allocation changes throughout the
body. Both piSettingData edits and the local-variable trial are reversed. The
observed scheduling change is target/compiler evidence; alias conservatism from
the external variable is an explanation to investigate, not proven identity.

Four counter keys remain across the two units at RVA 0x00A0C0EC. Its data-ledger
owner is the existing `g_00E0C0EC` union in RvaSmallLeafTransfers.cpp; these C
units use piNextID. Resolve that existing owner and its mixed word/dword accesses
before changing the counter spelling or definition. No alias is added.

## Separate default-queue verification

The default picker first served W3DDisplayRva00045213.cpp's historical selected
BFME_DX8_Thread_Lock blocker. Its own preview still selects the indexed wrong
copy. Supplying the current BfmeDX8ThreadLock.cpp object makes both units LINKS,
with 383 and 247 authored bytes. The screenshot unit passes all three rows;
its renumbered cleanup label is verified through the parent's EH data. No source
change was needed. This extends LINK-106's existing caller evidence; census
confirmation remains pending.
