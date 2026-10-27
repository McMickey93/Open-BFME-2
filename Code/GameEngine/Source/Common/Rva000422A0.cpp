// cl: /O1 /MD

// ?Rva000422A0Atan2@@YANMM@Z @0x000422A0 27B
// Unlock: float to double adapter for atan2 import thunk 0x0062992E.
// Caller 0x000422CD is math.h's float atan2 overload. Prev/next are disp trivials.

#include <math.h>

double __cdecl Rva000422A0Atan2(float y, float x)
{
	return atan2((double)(y), (double)(x));
}

double __cdecl Rva000422BBCeil(float x)
{
	return ceil((double)(x));
}

// W3DMouseCursorDirection.cpp already emits the complete retail float overload
// through setCursorDirection's real atan2 call; its row lives with that caller.
