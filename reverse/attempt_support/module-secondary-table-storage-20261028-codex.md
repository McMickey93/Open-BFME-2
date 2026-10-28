# Module secondary-table storage

Inspected at `7c98b18b59`, 2026-10-28, seat codex.

The default data-debt picker served `_s_10` in Rva004DF418Finish.cpp. Its
registered owner, Rva004DF324Dtor.cpp, and the constructor each defined a
file-static integer. The previous deferral assumed the owner could not change.
This pass claims both files and retains the inventory's symbol and owner.

Retail facts: the constructor at RVA 0x004DF418 and destructor at 0x004DF324
install the same secondary-table address, RVA 0x0086157C, at object offset
0x10. Its three words are VA 0x008A6563, 0x008DF396 and 0x0084DF8D. The
primary table starts immediately afterward at RVA 0x00861588. Each slot has
an existing matched code owner:

| Slot | Code RVA | Existing symbol |
| --- | --- | --- |
| 0 | 0x004A6563 | `?Rva004A6563Get@@YAHXZ` |
| 1 | 0x004DF396 | `?getDisabledTypesToProcess@Rva004DF396@@UBE?AV?$BitFlags@$0L@@@XZ` |
| 2 | 0x0044DF8D | `?rva0044DF8D@UpdateModule@@UAEXW4UpdateSleepTime@@@Z` |

The owner now defines the complete constant table, using C linkage to retain
`_s_10`. The constructor declares that table externally. COFF inspection finds
one external definition in the owner (storage 2, section 3) and one undefined
external in the constructor (storage 2, section 0). There is no new pin,
alternate name or address-named global. Erased function declarations are used
only to store the existing entry addresses, never to make calls.

This proves storage and slot targets, not a recovered class name, donor layout
or original TU. The private class views and separate stand-ins for the folded
table at RVA 0x007EFF90 remain outstanding work.

Verification:

- Normal `./build.sh` passes all six affected function rows and the new
  12-byte data row, including each slot relocation. A further normal build
  of the owner and both unchanged slot-provider units passes 49/49 rows.
- Frozen-file checks pass; the constructor's EH graph is EXACT.
- Both data-check modes pass for the two changed sources: zero findings,
  zero second names at protected addresses, zero unjudged rows.
- `repair_queue.py retire data` removes the consumer's sole registered key.
  No key is deleted by hand.
- `data_ledger.py --out build/secondary-table-data-ledger.csv` produces one
  owned `_s_10` row with one definition and two references. Only that row is
  copied into the committed inventory. Three unrelated missing objects prevent
  a tree-wide freshness claim.
- Paired ordinary link previews preserve LINKS for both changed units and
  189 authored bytes against index `14dc3d2467` (2026-10-28 02:44).
- The staged-tree batch audit is INCONCLUSIVE: the index predates this base
  and lacks per-object consumer names. Carry this storage/provider scope into
  the next normal census; full external-consumer selection is unverified.

No new census-linked bytes, image ownership or runtime result is claimed.
