# WeaponModeSpecialPowerUpdate pool-key data index prerequisite

Inspected revision `49fd3676a3`, selected by the default debt picker.
Source: `Code/GameEngine/Source/GameLogic/Object/Update/WeaponModeSpecialPowerUpdatePoolKey.cpp`.
The source scope was claimed during investigation and released without edits.

The existing clean C++ parent at RVA `0x00494AF3` (69 bytes), rollback at
`0x0078CEB5` (13 bytes) and EH handler at `0x0078CEC2` (10 bytes) all pass
ordinary byte verification. The parent EH graph is EXACT, its pool-name literal
passes, and `find_declared_unmatched.py` finds no unrowed definition.

The data register retains the pre-rename guard spelling. The tracked data index
also retains the old static method name for the key and a deleted standalone
clearer as guard owner. History establishes two relevant changes:

- `788ce59b66` named the virtual const `getModuleNameKey` method.
- `9ec60b109f` rowed the parent-owned guard rollbacks and removed
  `Code/GameEngine/Source/Common/GlobalFlagClearers_E03Axx.cpp`.

`data_check.py` therefore reports two current wrong-name findings, and
`repair_queue.py retire data` correctly refuses retirement without changing
the register. The required repair is a scoped data-index refresh, followed by
normal data-debt retirement; no source or compiler guard rewrite is needed.

Generated evidence from
`python3 tools/data_ledger.py --out build/data-ledger-20261027-codexb4.csv`
(34,415 addresses, zero missing objects):

| RVA | Current compiler symbol | Definition / matched refs |
| --- | --- | --- |
| `0x00A03A14` | `?TheWeaponModeSpecialPowerUpdatePoolKey@?1??getModuleNameKey@WeaponModeSpecialPowerUpdate@@UBE?AW4NameKeyType@@XZ@4W43@A` | 1 / 2 |
| `0x00A03A18` | `?$S1@?1??getModuleNameKey@WeaponModeSpecialPowerUpdate@@UBE?AW4NameKeyType@@XZ@4IA` | 1 / 4 |

Both generated rows are four-byte globals, status `owned`, with this source as
their only definition and matched referrer. Cached object facts place both
TU-local static COMDAT definitions in `.bss`; the generator labels their index
section `.data`. These are current compiler identities, not recovered original
retail identifiers or independent data-byte ownership proofs.

The shared `file:reverse/data_ledger.csv` claim was held by
`yasinschroeder-codexb` for a separate local key/guard refresh. The attempted
scope claim was refused, so no generated rows were adopted and no debt was
retired. Once that file is available, regenerate current evidence, adopt only
these complete two rows while preserving unrelated entries, rerun
`data_check.py`, then use `repair_queue.py retire data` for this source. Keep
the three matched rows and exact EH graph verified.
