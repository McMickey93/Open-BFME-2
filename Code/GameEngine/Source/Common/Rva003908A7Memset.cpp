// cl: /DNDEBUG /MD /EHs
// ?rva003908A7@@YGPAXPAX@Z, retail 0x003908A7, 27 bytes.
// memset the first four bytes, set flag 0x10 on the dword there, return the
// input pointer. Evidence: memset import thunk 0x006291AE (three pushes:
// dest, 0, 4); orl $0x10,(%esi); stdcall ret 4 returning the pointer.
// memset is msvcr71's, called through its import thunk at 0x006291AE
// rather than expanded inline: <string.h>'s memset with
// #pragma function(memset).
#include <string.h>
#pragma function(memset)

void *__stdcall rva003908A7(void *p)
{
	memset(p, 0, 4);
	*reinterpret_cast<int *>(p) |= 0x10;
	return p;
}
