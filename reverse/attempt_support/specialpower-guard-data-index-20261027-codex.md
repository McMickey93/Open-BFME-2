# Special-power cached-key data-index retirement

Inspected at `afd6ba6febe2`, 2026-10-27, seat codex.

The data picker served CashHackSpecialPowerPoolKey.cpp's guard at RVA
0x00A041A4. The index still preferred the external guard in the deleted
GlobalFlagClearers_E041xx.cpp. Commit `1b8654efaa8f` already replaced that
unit's standalone clearers with rowed parent-generated rollback funclets and
verified their EH graphs. The same stale index ownership affects seven other
cached-key units below. Commit `09a977f618` also renamed five of these getters
to getModuleNameKey; their cached-key index spellings remained stale.

Current sources contain their compiler-owned local statics and no longer name
the eight former external guard globals. None of the eight guard addresses has
a data_rows or data_converged owner. This repairs stale data-identity debt after
existing source recovery.

`python3 tools/data_ledger.py --out build/codex-e041-special-guard/data-ledger.csv`
generated 34,386 addresses and reported one unrelated missing matched object.
Only the exact sixteen key/guard rows for these eight independently verified
current objects were adopted. Three key rows were already current, leaving
thirteen changed index rows. Every selected row has one definition; keys have
two references and guards four. Generated sizes remain unchanged: four bytes
except the WeaponChange guard's eight-byte index bound. These bounds do not
establish independently verified storage extents, and this narrow repair does
not claim whole-index freshness.

The first seven sources are under
`Code/GameEngine/Source/GameLogic/Object/SpecialPower/`; WeaponChange is under
`Code/GameEngine/Source/GameLogic/Module/`.

| Source | Key RVA | Guard RVA |
| --- | --- | --- |
| CashHackSpecialPowerPoolKey.cpp | 0x00A041A0 | 0x00A041A4 |
| DefectorSpecialPowerPoolKey.cpp | 0x00A041A8 | 0x00A041AC |
| ElvenWoodSpecialPowerPoolKey.cpp | 0x00A041C8 | 0x00A041CC |
| InvisibilitySpecialPowerPoolKey.cpp | 0x00A04198 | 0x00A0419C |
| LevelGrantSpecialPowerPoolKey.cpp | 0x00A041B0 | 0x00A041B4 |
| OCLSpecialPowerPoolKey.cpp | 0x00A041C0 | 0x00A041C4 |
| ProductionSpeedBonusPoolKey.cpp | 0x00A041B8 | 0x00A041BC |
| WeaponChangePowerPoolKey.cpp | 0x00A041D4 | 0x00A041D8 |

Validation:

- find_declared_unmatched passes all eight sources. The normal build verifies
  all 24 function rows and eight string literals using current dependency
  receipts. Imports and float checks pass.
- eh_verify reports eight EXACT parent EH graphs, including their rollbacks.
- Enforced data_check reports zero findings and zero findings outside the
  baseline. Converged checks cover ten protected addresses with zero second
  names or unjudged rows.
- `repair_queue.py retire data SOURCE` passes for each source and removes one
  registered key each, with zero remaining findings. The owning retirement
  tool performs all eight baseline removals.
- Ordinary link_check against index `73061d9452`, 2026-10-27 14:34, reports
  all eight sources LINKS and preserves 629 authored bytes: ElvenWood 77,
  WeaponChange 78, and the other six 79 each. No code, object or function-ledger
  input changed after that preview.
- check_csv and git diff --check pass.

This change edits no C++ source, function row, pin, converged owner or source
path. No new census-linked bytes or image-ownership gain is claimed. Wider
data storage closure and census confirmation under LINK-007 remain open.
