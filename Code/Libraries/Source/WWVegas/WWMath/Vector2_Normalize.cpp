// cl: /O1 /Oy- /arch:SSE2 /EHsc /DNDEBUG /MD
//
// ?Normalize@Vector2@@QAEXXZ, retail 0x0007E60B, 72 bytes.
// Dedicated TU: the only other in-tree emission (the since-removed Zero
// Hour ParticleUplinkCannonUpdate.cpp port, /Oy-implied) came out
// frameless, but retail keeps an ebp frame for the len2 spill (movss
// [ebp-0x4] + fld round-trip into the Inv_Sqrt call), so this body lives in
// its own /Oy- unit. BFME1 vector2.h shape verbatim;
// Inv_Sqrt resolves to the matched ?Inv_Sqrt@WWMath@@SIMM@Z row.

#include "../../../../../reference/shims/wwmath/Vector2.h"


// Header inlines that the units including the header emit as select-any
// copies, which plain definitions here collided with. The anchor keeps this
// unit's copies for the rows; it is not retail code.
#pragma inline_depth(0)
// ?_bfmeVector2InlineAnchor@@YAXPAVVector2@@@Z absent-from-retail
void _bfmeVector2InlineAnchor(Vector2 *p)
{
    p->Normalize();
}
#pragma inline_depth()
