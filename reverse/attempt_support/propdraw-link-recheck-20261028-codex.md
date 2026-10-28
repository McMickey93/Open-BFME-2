# W3DPropDraw current-input recheck

Inspected revision `e1b88db116ad`, 2026-10-28; ordinary preview index
`14dc3d2467` (2026-10-28 02:44 UTC). This rechecks LINK-120 without changing
source or claiming a repair.

`./build.sh Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/Draw/W3DPropDraw.cpp`
passes all five rows, including its verified funclet binding, and its literal
checks. Its 32-byte constructor at RVA 0x000CEEC0 is already rowed; the source
has 124 authored bytes in total.

The current-object `link_check.py` preview remains blocked, 0 -> 0 linked
authored bytes, by exactly these three definitions:

- `??1ModuleData@@UAE@XZ`: unproven, differs from the kept retail copy.
- `??_7DrawModule@@6B@`: differs from the first copy in link order.
- `??_GDrawModule@@MAEPAXI@Z`: differs from the first copy in link order.

The current include chain still supplies the ZH-shaped nine-slot ModuleData
and 32-slot DrawModule views described in LINK-120. The registered BFME 2
ModuleData view has 31 slots; the other DrawModule family copies currently
agree on a one-slot scaffold. These are different prerequisites: adopting a
short family scaffold alone would not establish the complete retail table.

The next useful repair remains replacement of the inherited Module.h include
chain with retail-proven BFME 2 interfaces, followed by verification of the
derived module-data constructor and affected family consumers. No new source
trial, donor-layout claim, census gain or clearance is recorded here. The body
and file claims were released after this recheck.
