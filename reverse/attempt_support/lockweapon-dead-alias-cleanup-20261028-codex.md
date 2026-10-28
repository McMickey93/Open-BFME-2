# LockWeaponCreate unused alias cleanup, 2026-10-28

Inspected BFME 2 revision: `2f83fb883ac58c54bcffc6d3eb98aa1d3b4c0c98`.
Source: `Code/GameEngine/Source/GameLogic/Object/Create/LockWeaponCreate.cpp`.
Ordinary preview index: `14dc3d2467`, 2026-10-28 02:44 UTC.

## Retained change

Remove the unused linker directive mapping the nonvirtual destructor spelling
`??1CreateModuleData@@QAE@XZ` to `??1CreateModuleData@@UAE@XZ`, together with its
explanatory comment. Neither spelling is an external definition or reference in
this object. The three other aliases and the destructor exemption remain.
`tools/hatch_counters.py --update` retires this one alias key, lowering the
alternatename total from 2,929 to 2,928.

The normal `./build.sh` passes both rows (55 bytes), including string, float and
import reference checks. The frozen-file check passes before and after the edit;
the data-identity shadow check reports zero findings for this source. Read-only
COFF comparison through `link_census.comdat_bodies` proves all 83 external COMDAT
byte/relocation digests identical. All 110 external symbol records (83 defined,
27 undefined), including their values, section numbers and storage classes, are
identical. This is escape-hatch cleanup, with no recovered bytes or changed
provider/consumer bindings. Scratch evidence:
`build/lockweapon-link-20261028/object-comparison.json`.

## Reverted canonical Snapshot trial

Replacing this unit's BFME 1 moduledata include directory with the project's
`reference/shims/moduledata` keeps both constructor rows exact. The ordinary
preview removes the ModuleData destructor conflict but retains the
BehaviorModuleData conflict and both unresolved virtuals. However, the switch
changes multiple virtual tables and destructor COMDATs, and emits Snapshot's
virtual deleting destructor. The existing aliases were written against the old
interface spelling/order. Constructor byte matches alone do not establish a
correct complete native table. Restore the original include directory; no
header, table, pin or trial body change is retained.

## Remaining link prerequisites

The original and final ordinary previews both report two unresolved names,
`LockWeaponCreate::onBuildComplete` and `LockWeaponCreate::xfer`, and conflicting
copies of `ModuleData::~ModuleData` and `BehaviorModuleData::~BehaviorModuleData`.
Three differing base constructors are unreferenced diagnostics, not blockers.
Predicted linked contribution remains zero. Final scratch output:
`build/lockweapon-link-20261028/final-link-check.txt`.

LINK-004's existing interface prerequisite remains: the currently spelled xfer
slot reaches retail's load-post-process wrapper at RVA 0x00497805, while native
create-interface slot 1 reaches the existing 21-byte row at RVA 0x004B8CC9,
currently named `BfmeThing940G::bfmeGo940G`. Reconcile Snapshot/module/interface
declarations and prove provider identities together before changing these
bindings. Existing coverage means this is identity/interface cleanup rather
than a newly missing body. No obstacle clearance, census gain or runtime result
is claimed.
