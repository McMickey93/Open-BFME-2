# Update-module cached-key data-index retirement

Inspected at `b76477cafdfe`, 2026-10-27, seat codex.

The data picker served PickupStuffUpdatePoolKey.cpp's compiler guard at RVA
0x00A039D0. The committed index still selected the external address-named guard
from GlobalFlagClearers_E039xx.cpp, deleted by 34fe46e9bf after 22ec6865e2
replaced standalone rollback bodies with their matched parents' generated
funclets. The key also retained the getter's old static placeholder spelling;
the current source declares virtual const getModuleNameKey.

The same cause affects the nineteen claimed cached-key units below. Their
sources contain the existing function-local statics. This repair changes no
C++ source or function row and introduces no new name. AssaultTransportAIUpdate
was held by another worker and is excluded; the mixed FireSpreadUpdate and
HeightDieUpdate units are also outside this batch.

`python3 tools/data_ledger.py --out build/codex-pickup-data-ledger.csv`
generated 34,386 addresses and reported one unrelated missing matched object.
This change adopts only its complete, unmodified rows for these 38 key/guard
addresses, changing 36 committed rows. All generated rows have size four,
status owned and one definition; keys have two collected relocation sites and
guards four. No address has an explicit data_rows or data_converged owner.
These generated bounds are not independently verified data extents, and this
scoped index refresh does not claim whole-index freshness.

All paths are under `Code/GameEngine/Source/GameLogic/Object/Update/`.

| Source | Key RVA | Guard RVA |
| --- | --- | --- |
| ArrowStormUpdatePoolKey.cpp | 0x00A039A0 | 0x00A039A4 |
| AttachUpdatePoolKey.cpp | 0x00A039C4 | 0x00A039C8 |
| DamageFieldUpdatePoolKey.cpp | 0x00A039B4 | 0x00A039B8 |
| DeployStyleAIUpdatePoolKey.cpp | 0x00A03968 | 0x00A0396C |
| FireSpreadUpdatePoolKey.cpp | 0x00A03900 | 0x00A03904 |
| FireWeaponUpdatePoolKey.cpp | 0x00A03918 | 0x00A0391C |
| FlammableUpdatePoolKey.cpp | 0x00A0392C | 0x00A03930 |
| FloatUpdatePoolKey.cpp | 0x00A03950 | 0x00A03954 |
| FloodUpdatePoolKey.cpp | 0x00A0395C | 0x00A03960 |
| HeroModeSpecialAbilityUpdatePoolKey.cpp | 0x00A039D4 | 0x00A039D8 |
| LargeGroupBonusUpdatePoolKey.cpp | 0x00A03988 | 0x00A0398C |
| ModelConditionSpecialAbilityUpdatePoolKey.cpp | 0x00A039AC | 0x00A039B0 |
| MonitorConditionUpdatePoolKey.cpp | 0x00A039BC | 0x00A039C0 |
| OilSpillUpdatePoolKey.cpp | 0x00A03920 | 0x00A03924 |
| PickupStuffUpdatePoolKey.cpp | 0x00A039CC | 0x00A039D0 |
| SiegeAIUpdatePoolKey.cpp | 0x00A03998 | 0x00A0399C |
| TeleportSpecialAbilityUpdatePoolKey.cpp | 0x00A039F0 | 0x00A039F4 |
| WeaponFireSpecialAbilityUpdatePoolKey.cpp | 0x00A039E4 | 0x00A039E8 |
| WeaponSetSpecialAbilityUpdatePoolKey.cpp | 0x00A039DC | 0x00A039E0 |

## Verification

- Frozen-file checks pass for every retained source.
- The normal build verifies all 57 retained function rows and nineteen literals
  against current dependency receipts. Float and import checks pass.
- EH verification reports nineteen EXACT parent graphs, no nonexact parents
  and no missing objects.
- Ordinary previews against index 73061d9452 (2026-10-27 14:34 UTC) preserve
  LINKS for all nineteen units, 1,493 authored bytes. No code, object or
  function-ledger input changes in this repair.

- Enforced data_check reports zero findings and zero findings outside the
  baseline. Converged checks cover ten protected addresses with zero second
  names or unjudged rows.
- `repair_queue.py retire data SOURCE` passes independently for all nineteen
  sources and removes exactly one registered key each, with zero remaining
  findings. These commands perform every baseline removal.
- check_csv and git diff --check pass. Source hashes remain unchanged.

This is data debt cleanup under LINK-007, with no new census-linked bytes or
image-ownership gain claimed.
