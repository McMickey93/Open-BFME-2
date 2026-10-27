# RGBColor owner adopts its canonical header

Inspected revision: `658c11de7b`, 2026-10-27. Scope: `color.cpp` under the
`class:RGBColor` claim. This follows the assignment prerequisite in the
[earlier handoff](rgbcolor-header-prerequisites-20261027-codexb4.md).

Target facts: `color.cpp` already owns the 18-byte assignment at 0x0000353A.
Its private declaration made that assignment user-declared. The canonical
header instead leaves the assignment implicit. Adding an out-of-line
declaration to that header would change how its other users copy colors,
as the earlier attempt found. No new row or donor identity is needed.

The repair includes the existing canonical header, removes the private class
and hand-written assignment, and takes the implicit assignment's member
pointer inside the existing `bfmeEmitcolor` helper. The helper's existing
inline-depth boundary emits the assignment COMDAT. This follows the
compiler-generated-assignment recipe in `docs/matching.md`; it adds no global,
pin, alias, marker or compiler flag. The two conversion definitions now spell
the canonical declarations' `throw()` specification. Their bytes stay exact.
This proves a compatible reconstruction, not retail's original source spelling.

Verification:

- Before the edit, `header_adopt_lane.py gate-cost` verifies all 177 dependent
  ledger sources against the unchanged canonical header, with zero red chunks.
- The final ordinary build verifies 20/20 rows across `color.cpp`, its separate
  constructor, `DrawableFlashAsSelected.cpp`, `GlobalDataSetTimeOfDay.cpp` and
  `W3DRopeDrawInitRopeParms.cpp`. String, float and import reference checks pass.
- `header_adopt_lane.py accept --class RGBColor .../color.cpp` passes and
  retires precisely its one queue row. The declaration checker passes.
- Shadow data checking finds zero findings; enforced converged checking finds
  no second name at any of the ten checked addresses.
- `link_check.py --prepare-current` prepares and byte-verifies the owned
  source's strict reusable receipt, without changing the census or its index.
- The five-unit ordinary preview against index `73061d9452` (2026-10-27
  14:34, retail-truth-4) preserves LINKS for all five: 656, 18, 391, 86 and
  131 authored bytes respectively, 1,282 total. This is preview evidence,
  not a new census measurement or proof of full strict closure.

The separate integer constructor remains in the header queue: its required
`RGBColor(int)` declaration is still absent, and adding constructors needs
aggregate-initializer and default-construction reconciliation across users.
The existing conversion-emission helper and its counted marker remain.
Retiring that helper still requires preserving compatible inline setter
ownership with `DrawableFlashAsSelected.cpp`. The shared header, contract,
functions ledger and pins are unchanged. Progress is one retired header row;
no new linked-byte or image-ownership gain is claimed.
