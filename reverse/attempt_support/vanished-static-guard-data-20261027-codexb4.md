# Vanished-source static guard debt

## Target facts and history

The data queue served two baseline keys whose source files no longer exist:

- `Code/GameEngine/Source/GameLogic/Object/Upgrade/ObjectCreationUpgradeVslot8.cpp`,
  compiler guard at RVA `0x00A03E10`.
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/W3DRopeDrawPoolKey.cpp`,
  compiler guard at RVA `0x009EBB7C`.

Both files disappeared in `7a517b342b47dfaf5f8bf7693474ce8f2893fcb5`.
Its parent's ledger holds exactly one matched row in each old file:
`ObjectCreationUpgrade::rva004B463C`, RVA `0x004B463C`, 189 bytes; and
`W3DRopeDraw::rva000CA7F6`, RVA `0x000CA7F6`, 69 bytes. Both rows retain
their names, addresses, extents and matched status in the current owners:

- `Code/GameEngine/Source/GameLogic/Object/Upgrade/ObjectCreationUpgrade.cpp`
- `Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DRopeDraw.cpp`

Their compiler EH handlers and native guard rollback funclets are also rowed
in these current owners. The old standalone rollback reconstructions are
covered in `reverse/deleted_rows.csv`; the parents themselves were moved,
not deleted. No lost-row tombstone is claimed for either parent.

## Scoped generated index repair

The committed data index still selected the removed address-named clearer
symbols at RVAs `0x009EBB7C`, `0x00A03E00` and `0x00A03E10`. The current
clearer sources no longer define them. Before the repair, `data_check.py`
reported three wrong-name findings in the two current owners: the two served
guards and the adjacent ObjectCreationUpgrade pool-key guard.

`python3 tools/data_ledger.py --out build/codexb4-data-ledger-current.csv`
reports zero missing matched objects. This repair adopts only the generator's
three complete, unmodified rows for those addresses. The generated rows have
size four, status `owned`, one definition and two collected relocation sites
each. Cached generator facts identify only the current owner as the definition
and matched referrer of each compiler guard, with static COMDAT definitions
in `.bss`. None has an explicit `data_rows.csv` or `data_converged.csv` entry.
This is an index freshness repair, not independently byte-verified data
ownership, a whole-tree data verification or a linked-coverage claim.

## Retirement and verification

The two original keys were transferred unchanged, except for their source
column, to their current row owners. `repair_queue.py retire data SOURCE`
then passed separately for each owner: one key retired and zero still found.
The final register loses exactly the two original vanished-source keys.
Per-key `Debt-Retired` trailers account for the vanished paths over the whole
commit, as required by the disappeared-source exception; the data tool's
current-owner verdicts provide the retirement evidence.

- `find_declared_unmatched.py` passes for both current sources.
- `./build.sh` on both sources: 22/22 matched functions pass, including string,
  floating-point and import checks.
- `eh_verify.py` on both sources: five EH rows, all EXACT, none missing objects.
- `data_check.py` on both sources after the repair: zero findings.

No source, function row, pin, hatch or independently verified data owner changes.
