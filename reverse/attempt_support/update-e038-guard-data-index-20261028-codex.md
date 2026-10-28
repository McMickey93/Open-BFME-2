# E038 update cached-key data-index retirement

Inspected at `bd82c0156d2e357964f367c334e122bafe8c24dc`, 2026-10-28,
seat `yasinschroeder-codex`.

The data picker claimed DelayedWeaponSetUpgradeUpdatePoolKey.cpp's guard at
RVA 0x00A038E0. Its index still chose the external address-named definition
formerly in GlobalFlagClearers_E038xx.cpp. Commit `e44def7a6f` replaced that
file's standalone clearers with the owning parents' generated rollback
funclets and removed those external definitions. Three of these six accessors
also have already-landed getter renames missing from the index.

All six claimed sources are under
`Code/GameEngine/Source/GameLogic/Object/Update/`:

| Source | Key RVA | Guard RVA |
| --- | --- | --- |
| AssistedTargetingUpdatePoolKey.cpp | 0x00A038AC | 0x00A038B0 |
| BoneFXUpdatePoolKey.cpp | 0x00A038C8 | 0x00A038CC |
| DefaultProductionExitUpdatePoolKey.cpp | 0x00A038D4 | 0x00A038D8 |
| DelayedWeaponSetUpgradeUpdatePoolKey.cpp | 0x00A038DC | 0x00A038E0 |
| DeletionUpdatePoolKey.cpp | 0x00A038E4 | 0x00A038E8 |
| DynamicShroudClearingRangeUpdatePoolKey.cpp | 0x00A038F8 | 0x00A038FC |

`python3 tools/data_ledger.py --out build/codex-e038-update/data-ledger.csv`
generated 34,332 addresses and reported five matched sources without objects.
This change adopts only the complete, unmodified generated rows for the twelve
addresses above; nine committed rows change. Every selected row has size four,
status owned and one definition, with two key relocation sites or four guard
sites. None has an explicit data_rows.csv or data_converged.csv owner. Generated
bounds are index bounds, not independently verified data extents. This is a
scoped refresh and does not establish whole-index freshness.

Verification:

- Frozen-file checks pass for all six sources. The normal build passes all
  18 function rows and six string literals, plus float and import checks.
- EH verification reports six EXACT parent graphs, no nonexact rows and no
  missing objects. All six source SHA-256 hashes remain unchanged.
- Enforced data_check reports six sources, zero findings and zero findings
  outside the baseline. Converged mode checks eleven protected addresses with
  zero second names and zero unjudged rows.
- `repair_queue.py retire data SOURCE` independently passes for each source
  and removes its single registered key, with zero remaining findings.
- Ordinary previews against index `73061d9452` (2026-10-27 14:34 UTC) retain
  LINKS for all six units: 78, 76, 78, 78, 78 and 78 authored bytes, respectively,
  totaling 466. No source or function-ledger input changes in this repair.
- check_csv and git diff --check pass.

The initial default link pick was Rva00415704Ctor.cpp. Its normal build passes
all four rows, and the joint ordinary preview with Rva00415CABDtor.cpp and
OpaqueScalarDeletingDtorsB10.cpp reports 3/3 LINKS (90, 272 and 544 authored
bytes). That confirms LINK-112's existing repair; the claim was released
without a source edit. LINK-121's older constructor lead is superseded in this
bounded scope.

This retires six stale data-debt keys under LINK-007. Broader E038 ownership
work and census confirmation remain open; no new census-linked bytes or image
ownership gain is claimed.
