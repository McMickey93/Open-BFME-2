// cl: /O2 /G6 /DNDEBUG /MD
// Clean room: reverse/vp6_cleanroom/specs/001bb670.md plus retail only.
// No decoder source was consulted.
//
// Diagnostic frame dump (retail 0x001BB670): appends the last reconstructed
// frame (Y plane plus two UV planes) to test.raw.

#include <stdio.h>

struct PB_INSTANCE
{
	unsigned char pad000[0x208];
	unsigned int yPlaneSize;      // 0x208
	unsigned int uvPlaneSize;     // 0x20C
	unsigned char pad210[0x44];
	void *lastReconFrame;         // 0x254
};

// RVA 0x001BB670
extern "C" void __cdecl vp6_appendframe(PB_INSTANCE *pbi)
{
	FILE *file = fopen("test.raw", "ab");
	fwrite(pbi->lastReconFrame, pbi->yPlaneSize + pbi->uvPlaneSize * 2, 1, file);
	fclose(file);
}
