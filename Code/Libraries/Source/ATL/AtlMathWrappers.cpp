// cl: /MD /O1 /arch:SSE /G7
// Address-named float-to-double wrappers at 0x000032B8 and 0x000032C9.
// Their call sites are inside unclaimed FUN_00526433; the target calls the
// double fabs and sqrt, so the argument is widened before <math.h>'s float
// overloads can take it.
#include <math.h>

double __cdecl Rva000032B8(float value)
{
	return fabs((double)value);
}

double __cdecl Rva000032C9(float value)
{
	return sqrt((double)value);
}
