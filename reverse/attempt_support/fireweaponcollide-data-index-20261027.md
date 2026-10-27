# FireWeaponCollide local storage index repair

Inspected at `0c436f24b57698ad49c5f014f5d4a99ddb771cfb`, 2026-10-27,
seat codex5.

The default picker claimed `file:Code/GameEngine/Source/GameLogic/Object/Collide/FireWeaponCollide.cpp`
for one proposed TU row. The current `tu_skeleton.py --plan` instead rebuilds
the stale map in memory and approves all 14 rows. No TU map is committed.
The consolidation planner reports the three remaining clean satellites;
`tu_skeleton.py --merge ... --dry-run` accepts none. The constructor's base
views differ, and the onCollide/shouldFireWeapon views cannot compose with
the seed. Commit `bf3ce2314b` already records these interface prerequisites,
including primary slot 12 behind unnamed slots 5-11. No source trial or merge
is retained. Reconcile these views in separately verified changes before
retrying composition; a plausible getter rename does not repair the contract.

The seed's registered data debt still spells `rva00004BB755`. Its getter was
renamed in `4385c1a0c7`, and `bad0141bb5` removed the separate guard definition
and rowed its rollback under the parent's exact EH graph. Source search finds
no remaining `g_Va00E04008` or `rva00004BB755` in Code. The current function row
and compiler-owned local storage are already in the consolidated owner.

`python3 tools/data_ledger.py --out build/codex5-fireweaponcollide-data-ledger.csv`
generates 34,378 addresses and reports three matched sources without objects.
Only its exact generated rows for `0x00A04004` and `0x00A04008` are copied into
the committed index. Each is a four-byte owned global in FireWeaponCollide.cpp,
with one definition and two matched relocation references. The key and guard
now use the getter's existing spelling; the removed external guard no longer
competes with its compiler-owned local. Other generated index changes are
excluded. No source, function row, pin, data ownership row or converged name
changes.

Validation:

- `./build.sh Code/GameEngine/Source/GameLogic/Object/Collide/FireWeaponCollide.cpp`:
  all nine rows and two literals pass, including the guard rollback verified
  through its parent's EH data after label renumbering.
- `eh_verify.py`: three EXACT graphs, none baselined or missing.
- `find_declared_unmatched.py`: all defined functions already matched.
- `data_check.py`: zero findings after the index refresh;
  `data_check.py --converged`: ten addresses, zero second names or unjudged rows.
- `repair_queue.py retire data .../FireWeaponCollide.cpp`: PASS, one key
  retired, zero remaining findings. Only this owning-tool verdict removes
  the baseline line.
- `check_csv.py` and `git diff --check` pass.

Ordinary preview uses index `bf3dd31211` (2026-10-27 00:39,
`retail-truth-4`), unchanged by `--fetch-index`. Before and after the data
refresh, it reports duplicate getModuleNameKey/xfer and a selected-copy
finding for getModuleNameKey. Inspection of the index identifies its strong
providers as the deleted FireWeaponCollidePoolKey.obj and
FireWeaponCollideXfer.obj. Their source definitions moved to the seed in
`bf3ce2314b`; Code contains exactly one definition of each. The historical
objects are still counted by this ordinary preview. The other three current
satellites preview LINKS (49, 94 and 58 authored bytes). No whole-current-ledger
preview, current link clearance, census gain or image-ownership measurement
is claimed. The next normal census must measure the consolidated provider
universe; the data-index correction alone is not that verification.
