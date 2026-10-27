// cl: /MD
// platformsdk
// ?Rva0004300DGet@@YA_JXZ, retail 0x0004300D, 23 bytes.
// Free-function QueryPerformanceCounter wrapper returning the 64-bit tick.
// Evidence: IAT kernel32 QueryPerformanceCounter; edx:eax return; callers
// 0x000437B6 0x00043E5B 0x00043EB8 0x000483C0.
#include <windows.h>

__int64 __cdecl Rva0004300DGet()
{
	LARGE_INTEGER ts;
	QueryPerformanceCounter(&ts);
	return ts.QuadPart;
}

// ?Rva00043024Get@@YA_JXZ, retail 0x00043024, 23 bytes.
// Free-function QueryPerformanceFrequency wrapper returning the 64-bit rate.
// Evidence: IAT kernel32 QueryPerformanceFrequency; edx:eax return; callers
// 0x000437AB 0x00043DD6 0x000483B5.
__int64 __cdecl Rva00043024Get()
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return freq.QuadPart;
}
