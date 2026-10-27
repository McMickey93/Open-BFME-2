# RiderChangeContain local-static data index repair

Inspected `67587e56fd` on 2026-10-27. The default picker claimed the
RiderChangeContain consolidation family. Its earlier composition failures
remain prerequisites; this pass repairs the family's stale data index instead.

## Existing owners and history

`Code/GameEngine/Source/GameLogic/Object/Contain/RiderChangeContainPoolKey.cpp`
already owns three matched rows: `getModuleNameKey` at RVA `0x0047E2E0`
(69 bytes), compiler rollback label `$L310` at `0x0078B7C0` (13 bytes), and
the parent's EH handler at `0x0078B7CD` (10 bytes). No function, source name,
pin or data definition is added or renamed by this repair.

`b3f118ca65` renamed the old static `rva00047E2E0` body to the current const
virtual method. `590c2708dd` retired the standalone guard clearer and rowed
the compiler rollback under this parent, as `reverse/deleted_rows.csv` records.
The index still named the old function's cached key, and assigned its guard to
the deleted `Common/GlobalFlagClearers_E037xx.cpp` source. Consequently the
current object had two wrong-name findings against the stale index; the data
register held one finding under the old function spelling.

## Tool-derived replacement

After `./build.sh` verified the source, generated a separate index with:

```sh
python3 tools/data_ledger.py --out build/rider-data-ledger.csv
```

Copied only its complete, unmodified CSV rows for RVAs `0x00A03734` and
`0x00A03738` into `reverse/data_ledger.csv`, preserving every other line.
These are VAs `0x00E03734` and `0x00E03738`, respectively. Both generated
rows have size 4, section `.data`, status `owned`, one definition, and this
PoolKey source as owner. Their current compiler-local names are:

| RVA | Compiler symbol | Matched relocation sites |
| --- | --- | ---: |
| `0x00A03734` | `?TheRiderChangeContainPoolKey@?1??getModuleNameKey@RiderChangeContain@@UBE?AW4NameKeyType@@XZ@4W43@A` | 2 |
| `0x00A03738` | `?$S1@?1??getModuleNameKey@RiderChangeContain@@UBE?AW4NameKeyType@@XZ@4IA` | 4 |

Inspection of `data_ledger.collect()` shows only this source among the cached
definitions and matched referrers of either symbol. Both definitions are
TU-local compiler COMDATs; the object's dependency receipt is current. The
removed address-named guard is no longer a participating definition. These
are current object identities, not claims about retail source identifier names
or independently byte-verified data ownership in `data_rows.csv`.

The generator reported 18 other matched sources without objects. Its whole
output is therefore not a whole-tree completeness receipt and is not committed.
The scoped repair keeps unrelated entries, verified ownership overlays and
register findings unchanged.

## Verification and retirement

- `./build.sh .../RiderChangeContainPoolKey.cpp`: 3/3 matched rows, one
  literal, no float or import failures; current object reused.
- `tools/eh_verify.py`: one EXACT parent EH graph, including the rollback
  funclet at `0x0078B7C0`.
- `tools/find_declared_unmatched.py`: all defined functions already matched.
- `tools/data_check.py`: zero findings after the index repair.
- `tools/repair_queue.py retire data .../RiderChangeContainPoolKey.cpp`:
  PASS, one key retired from `reverse/data_check_baseline.txt`, zero still found.
- `tools/check_csv.py`: passes, with 98,276 function rows, 15,313 symbols and
  2,226 data rows unchanged.
- Ordinary `link_check.py` against the fetched `bf3dd31211` provider index
  preserves LINKS (78 authored nonpadding bytes). This is a bounded preview;
  no new census-linked bytes or image-ownership improvement is claimed.

## Consolidation handoff

Read the current `name_lane.py consolidate --under
Code/GameEngine/Source/GameLogic/Object/Contain/` packet and the earlier
`consolidation-audio-data-prerequisite-20261026-codex4.md` handoff. The seed
imports Zero Hour interfaces while donors define conflicting private
`RiderChangeContain`, `AsciiString` and `Xfer` views. The native donor's
contain-count and contained-list contracts differ from the seed's header
interfaces. The seed also emits a compiler helper and four data definitions,
so deleting its broad include stack requires a provider/consumer inventory.
No unchanged broad composition trial was repeated. Reconcile those native
interfaces in a separately verified prerequisite before the next merge.

Result: one data-debt key retired; no source files merged or code coverage
changed. All unused family claims were released.
