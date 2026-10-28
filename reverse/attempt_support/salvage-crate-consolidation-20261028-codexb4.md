# SalvageCrateCollide composition, 2026-10-28

Seat: yasinschroeder-codexb4. Inspected base: `6083bb742d`.
Destination: `Code/GameEngine/Source/GameLogic/Object/Collide/CrateCollide/SalvageCrateCollide.cpp`.

## Routing and prerequisite

The default picker claimed the destination, constructor, key getter and
HealCrateCollideXfer.cpp. The scoped `name_lane.py consolidate` report was
reviewed, including original-path evidence, alternatives, private-view and
compiler-setting blockers. The committed TU map is stale; the supported
`tu_skeleton.py` plan rebuilds current assignments in memory. It approves the
Salvage key getter and its two EH rows, and the kept xfer body at 0x004BD2F9,
for this destination. The xfer source's Heal spelling is an existing fold,
not a second retail body. Two mixed sources stay outside composition.

The first supported dry run rejects all three donors: the seed lacks the
constructor, getModuleNameKey and xfer declarations. `tu_views.py --dry-run`
reports conflicting base clauses for CrateCollide and SalvageCrateCollide.
The constructor's explicit vptr stores and the transfer source's multiple
inheritance view need separate reconciliation; they are not evidence for
replacing the behavior unit's working layout.

The prerequisite adds only the existing key-getter and xfer declarations to
the behavior view, plus the key donor's enum spelling and an Xfer forward
declaration. The signatures and access come from the existing matched rows;
no new identity, provider or vtable body is introduced. The constructor is
left unchanged.

Before the change, all four original sources pass strict receipt preparation:
19/19 function rows and five string references. Original objects are saved
under build/salvage-before. After the prerequisite, the behavior unit passes
13/13 rows, four string references and both EXACT EH graphs. Its 31 external
COMDAT byte-and-symbolic-relocation fingerprints, all 31 external definitions
and all 39 external references equal the original object. The frozen-file
check passes.

Ordinary previews before and after the prerequisite preserve LINKS for all
three candidate inputs: behavior 876, transfer 27 and key getter 79 authored
bytes, 982 total. The index is `41c28839bf` (2026-10-28 11:08), older than the
inspected base. These are bounded previews, not new census-linked bytes.

The second supported dry run accepts the behavior unit, key getter and
transfer source, with its census-linked-input guard passing. It still rejects
the constructor for the missing constructor declaration. It reports 17
approved rows in the composed unit; its input files also carry the existing
Heal transfer fold alias. Data identity reports no findings, and converged
data enforcement checks 11 addresses with no second names or unjudged rows.

## Remaining work

Run the supported composition after the declaration prerequisite is committed.
Keep the constructor separate unless its layout and explicit vtable stores
can be reconciled without changing its verified code or bindings. Complete
the path/register/provider audit and current destination receipt before
publishing a merge; carry inconclusive consumer selection into the next
scheduled census. No census or smoke runner is started by this work.
