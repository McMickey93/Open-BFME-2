# E027 guard data index cleanup

Inspected at `46e6a22e9f`, 2026-10-27, seat codexb5.

The data picker served CastleBehaviorPoolKey2.cpp's historical external-guard
alias. Commit `d935aa0668` already replaced eight E027 standalone clearers
with their parents' verified compiler rollback funclets and removed seven
unused address globals. Six affected units still have registered data debt.
Their guard aliases are stale index entries, rather than remaining external
definitions. RadiusDecalUpdate and CastleMemberBehavior also now name their
getters `getModuleNameKey`; their cached-key index spellings need that rename.

| Unit (under GameLogic/Object) | Key RVA, refreshed if listed | Guard RVA |
| --- | --- | --- |
| Behavior/PhysicsBehaviorPoolKey.cpp | unchanged | 0x00A027A8 |
| Update/RadiusDecalUpdate.cpp | 0x00A027B0 | 0x00A027B4 |
| Behavior/CastleBehaviorPoolKey2.cpp | unchanged | 0x00A027CC |
| Behavior/CastleMemberBehaviorFind.cpp | unchanged | 0x00A027D4 |
| Behavior/CastleMemberBehaviorPoolKey.cpp | 0x00A027D8 | 0x00A027DC |
| Behavior/Rva00395C80Check.cpp | unchanged | 0x00A027E4 |

Eight rows are copied exactly from
`data_ledger.py --out build/codexb5-e027-data-ledger.csv`. All have one
definition and status `owned`. Every other committed index line is preserved.
The generator reports ten unrelated sources without objects; all six scoped
objects have independently passed the ordinary build and freshness checks.
The surviving E027EC clearer and explicit E027F4 data owner remain untouched,
as do the other two units without registered data debt. No game source,
function row, pin, explicit data row or converged name changes.

Validation:

- `find_declared_unmatched.py`: all six sources clean.
- `./build.sh`: 26/26 matched rows, six literals, all float/import checks pass.
- `eh_verify.py`: eight EXACT graphs, no missing objects.
- `data_check.py --enforce`: six sources, zero findings.
- `data_check.py --converged`: ten protected addresses, no second names or
  unjudged rows.
- `repair_queue.py retire data SOURCE`: PASS individually for all six units;
  six registered keys retired, zero remaining findings in those units.
- `check_csv.py` and `git diff --check` pass.

Ordinary previews before and after the index repair use `bf3dd31211`
(2026-10-27 00:39, retail-truth-4). The five behavior units all retain LINKS
and 400 authored bytes. RadiusDecalUpdate reports the same three duplicate
method providers (getModuleNameKey, update, xfer) and selected-wrong getter
before and after. Commit `a6669d8c26` absorbed and deleted those three donor
sources after the preview index was published. The current TU passes all
eleven rows, including the renamed getter and its parent-placed EH funclet;
its historical census contribution is 342 bytes and its current authored
scope is 532 bytes. Do not count the stale-provider preview as a new loss or
as proof of a cleared link. Confirm that consolidation against current
providers in the next normal maintainer census. No linking or image-ownership
gain is claimed for this data-debt batch.
