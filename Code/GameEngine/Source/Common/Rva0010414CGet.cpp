// cl: /MD
// ?Rva0010414CGet@@YAMPAM@Z, retail 0x0010414C, 34 bytes.
// Evidence: chain lane, calls 0x0010410F Wrap and atan2(float, float) 0x000422CD, callers in 0x00104359.
#include <math.h>

float __cdecl Rva0010410FWrap(float a);

float __cdecl Rva0010414CGet(float *p)
{
	return Rva0010410FWrap(atan2(p[1], p[0]));
}
