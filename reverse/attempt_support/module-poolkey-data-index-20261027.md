# Module pool-key data index cleanup

Inspected at `7ac2580723`, 2026-10-27, seat codexb5.

The default picker served WallUpgradeUpdatePoolKey.cpp's old guard spelling.
Commit `8ca40fecae` had already named its getter and twelve siblings
`getModuleNameKey`. The data index still retained their former method names
and separate external guard owners. The standalone clearers have since been
retired in favor of each parent's own compiler-generated rollback funclet;
`reverse/deleted_rows.csv` records each of the ten replacements below.
For WallUpgradeUpdate, that retirement is in `b6e684778e`; `f4c9c4be02`
subsequently removed the last definition and the obsolete E03C clearer file.

This change refreshes twenty data-index rows for ten getters from that rename
batch. Each pair is copied exactly from `tools/data_ledger.py` output, restricted
to these addresses. Every generated row has one definition, status `owned`,
and two key references or four guard references. The key and guard now name
their actual TU-local definitions under `getModuleNameKey`.

| Getter class | Key RVA | Guard RVA |
| --- | --- | --- |
| OathbreakersFadeAwayBehavior | 0x00A03F5C | 0x00A03F60 |
| HealCrateCollide | 0x00A0404C | 0x00A04050 |
| SalvageCrateCollide | 0x00A04078 | 0x00A0407C |
| CombineHordeSpecialPower | 0x00A04300 | 0x00A04304 |
| EvacuateGarrisonSpecialPower | 0x00A043BC | 0x00A043C0 |
| GrabPassengerSpecialPower | 0x00A04268 | 0x00A0426C |
| AllowBannerSpawnUpgrade | 0x00A03F38 | 0x00A03F3C |
| CostModifierUpgrade | 0x00A03E94 | 0x00A03E98 |
| W3DSailModelDraw | 0x009EBBF0 | 0x009EBBF4 |
| WallUpgradeUpdate | 0x00A03CCC | 0x00A03CD0 |

The other three getters from that rename commit have no remaining data-debt
entry under their old source paths and are outside this batch. No game source,
function row, pin, verified data row or converged data name changes.

Validation:

- `find_declared_unmatched.py`: all ten sources clean.
- `./build.sh`: 31/31 matched rows, ten string literals and all import/float
  checks pass; all ten objects proven current by their dependency receipts.
- `eh_verify.py`: ten EXACT parent graphs, zero missing objects.
- `data_ledger.py --out build/codexb5-wallupgrade-data-ledger.csv`: 34,357
  addresses generated. Seven unrelated sources have no object; only the twenty
  rows belonging to the ten independently verified objects are copied.
- `data_check.py --enforce`: ten sources, zero findings.
- `data_check.py --converged`: zero second names and zero unjudged rows.
- `repair_queue.py retire data SOURCE`: PASS separately for each source,
  ten registered keys retired by the owning tool, zero remaining in these files.
- Ordinary `link_check.py`: all ten sources LINKS, preserving 811 authored
  bytes against index `bf3dd31211` (2026-10-27 00:39, retail-truth-4).
  This validates existing links; no census or linking gain is claimed.
- `check_csv.py` and `git diff --check` pass.
