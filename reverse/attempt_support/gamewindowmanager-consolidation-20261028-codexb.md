# GameWindowManager consolidation prerequisite, 2026-10-28

Inspected f5979062a5 with census index 2026-10-28 02:44 at 14dc3d2467.
Scope: the 21 clean donors selected for GameWindowManager.cpp by the current
in-memory TU map (70 rows, 7,912 bytes). The committed TU map was not regenerated.
The naming packet was regenerated under build/consolidation/gamewindowmanager-codexb.
Its exact original GameWindowManager.cpp path comes from WorldBuilder, not the game
image; BFME1/Zero Hour paths are donor leads, not direct target path evidence.

## Reconciliation

The initial supported merge dry run accepted no combination: duplicate enums,
UnicodeString/STL definitions, incompatible GameWindow/manager member declarations,
and byte differences remain. The tu_views dry run reported conflicting virtual
slots and a field under a vfptr; no broad class rewrite was applied.

The lone-window donor at 0x002C12DC duplicated GGM_CLOSE at namespace scope.
Move that constant into the function, and call through the seed's identical
BfmeWindowManagerSendView instead of relying on the donor's manager declaration.
This preserves target slot 58 (+0xE8) when the merge retains the shared Zero Hour
manager header (which places winSendSystemMsg earlier). The native manager's
winSetLoneWindow slot 52 and m_loneWindow offset +0x2C remain intact.
The now-unused private winSendSystemMsg declaration and padding slots are removed.
No new function body, global identity, pin or escape hatch is introduced.

## Verification

Before reconciliation, ./build.sh verified all 70 rows across the 21 donors.
After reconciliation, the seed and lone-window donor pass 7/7 rows together,
and both find_declared_unmatched checks are clean. The donor's entire COMDAT
bytes and relocation identities, defined externals and undefined externals
are unchanged against the saved pre-edit object. Ordinary link_check previews
both sources LINKS (319 and 51 own bytes); these are predictions, not a census.
The initial scope data_check found no findings; code identity remains shadow,
with the pre-existing divergent list-base funclet in Rva002C5398Dtor.cpp untouched.
The lone-window donor owns no debt-register, header-queue or hatch entries.

## Remaining work

Retry tools/tu_skeleton.py --merge after this prerequisite commit. Other donor
layout, duplicate-definition and byte blockers remain; do not combine their
repairs or claim that the initial full merge succeeded. LINK-075's previous
repair remains awaiting census confirmation. No runtime, image-ownership or
new linked-byte measurement is claimed.
