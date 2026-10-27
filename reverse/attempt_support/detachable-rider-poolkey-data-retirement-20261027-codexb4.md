# DetachableRiderBody local-static data index repair

Inspected `408c38abc0` on 2026-10-27. The default picker claimed
`file:Code/GameEngine/Source/GameLogic/Object/Body/DetachableRiderBodyPoolKey.cpp`
for its registered data-identity finding.

## Existing owners and stale index

The source already owns three matched rows: `getModuleNameKey` at RVA
`0x004C1BE4` (69 bytes), compiler rollback label `$L310` at `0x0078FC70`
(13 bytes), and the parent's EH handler at `0x0078FC7D` (10 bytes).
`7599ea6a32` renamed the old static `rva0004C1BE4` method to this const
virtual method. `1b8654efaa` retired the standalone guard clearer and
recovered its compiler rollback under this parent; the old clearer's
retirement is recorded in `reverse/deleted_rows.csv`.

The data index still named the cached key using the old method spelling and
assigned the guard to deleted `Common/GlobalFlagClearers_E041xx.cpp` under
`?g_Va00E0416C@@3IA`. The data register retained a guard finding under the old
method spelling. A first retirement attempt correctly refused the two current
local-static names as new findings against this stale index; nothing was
retired until the index was repaired.

## Tool-derived replacement

After normal byte verification, ran:

```sh
python3 tools/data_ledger.py --out build/detachable-rider-data-ledger.csv
```

Copied only its complete generated rows for RVAs `0x00A04168` and `0x00A0416C`
into `reverse/data_ledger.csv`, preserving all other lines. These correspond
to VAs `0x00E04168` and `0x00E0416C`. Both generated rows are four-byte
`.data` globals, status `owned`, with one definition in this PoolKey source.
Their compiler symbols are:

| RVA | Current compiler symbol | Matched relocation sites |
| --- | --- | ---: |
| `0x00A04168` | `?TheDetachableRiderBodyPoolKey@?1??getModuleNameKey@DetachableRiderBody@@UBE?AW4NameKeyType@@XZ@4W43@A` | 2 |
| `0x00A0416C` | `?$S1@?1??getModuleNameKey@DetachableRiderBody@@UBE?AW4NameKeyType@@XZ@4IA` | 4 |

The generator's cached collect facts show this source as the only definition
and matched referrer of each symbol. Both are TU-local static COMDATs in the
object's `.bss`, and its dependency receipt is current. The retired
address-named clearer no longer participates. This establishes current object
identity, not original retail source identifiers or independent byte-verified
data ownership. Neither address is in `data_rows.csv` or `data_converged.csv`.

The generator reports 22 other matched sources without objects. Its entire
output is therefore not a whole-tree completeness receipt and is not committed.
Only the two scoped generated rows are adopted.

## Verification and retirement

- `./build.sh .../DetachableRiderBodyPoolKey.cpp`: all three rows exact;
  one literal verified, no float or import failures; current object reused.
- `tools/eh_verify.py`: one EXACT parent EH graph, including its rollback.
- `tools/find_declared_unmatched.py`: all defined functions already matched.
- `tools/data_check.py`: zero findings after the scoped index repair.
- `tools/repair_queue.py retire data .../DetachableRiderBodyPoolKey.cpp`:
  PASS, one stale key retired, zero still found.
- `tools/check_csv.py`: passes (98,276 function rows, 15,313 symbols,
  2,227 data rows, unchanged).
- Ordinary `tools/link_check.py` using the fetched `bf3dd31211` index:
  LINKS, 79 -> 79 authored nonpadding bytes. The source and object are unchanged;
  this bounded preview establishes no new linked-byte gain.

No game source, function row, pin, independently verified data row or byte
coverage changes. This retires one registered data-debt key. No new census
linked-byte gain or image-ownership result is claimed.
