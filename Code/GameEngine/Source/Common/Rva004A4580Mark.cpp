// cl: /DNDEBUG /MD
//
// ?rva004A4580@Rva004A4580@@QAEPAXPAX@Z @0x004A4580 27B.
// Ignores this. Zeroes the first dword of the argument through the rowed
// memset thunk, then sets bit 1 and returns the same pointer.

// memset is msvcr71's, called through its import thunk at 0x006291AE
// rather than expanded inline: <string.h>'s memset with
// #pragma function(memset).
#include <string.h>
#pragma function(memset)

class Rva004A4580
{
public:
	void *rva004A4580(void *p);
};

void *Rva004A4580::rva004A4580(void *p)
{
	memset(p, 0, 4);
	*(unsigned int *)p |= 2;
	return p;
}
