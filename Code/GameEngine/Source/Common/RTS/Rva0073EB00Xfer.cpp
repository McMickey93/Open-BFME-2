// cl: /MD
// ?Rva0073EB00Xfer@@YAPAVXfer@@PAV1@PAG@Z @0x0073EB00 106B
// Shroud PlayerState counters[3] Xfer helper N=3 twin of N=2 at 0x0073EA90.
// Evidence: caller 0x0073EBB0 passes Xfer plus short ptr; slots 0x78 count and 0x80 per-short;
// throw via _bfmeFormatText 0x0060C36E plus _CxxThrowException 0x00629094 with g_guardTargetTypeThrowInfo.

typedef unsigned int UnsignedInt;
typedef bool Bool;

class Snapshot;
class AsciiString;
class UnicodeString;
class PooledString;
struct Coord3DBase;
struct ICoord3D;
struct Region3D;
class IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
class RealRange;
struct RGBColor;
class RGBAColorReal;
class RGBAColorInt;
struct XferUnknown11;
#include "../../../Include/Common/BfmeXfer.h"

struct XferException
{
	char *text;
	int tag;
};

extern "C" XferException *__cdecl bfmeFormatText(XferException *result, int tag, const char *format, ...);
extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);
extern int g_guardTargetTypeThrowInfo;

Xfer *Rva0073EB00Xfer(Xfer *xfer, unsigned short *vals)
{
	UnsignedInt count = 3;
	int n = 3;
	(*xfer == count);
	if (count != 3) {
		XferException error;
		bfmeFormatText(&error, 0, 0);
		_CxxThrowException(&error, (const _s__ThrowInfo *)&g_guardTargetTypeThrowInfo); __assume(0);
	}
	do {
		(*xfer == *vals++);
	} while (--n != 0);
	return xfer;
}

// Native 0x0073EA90..0x0073EAFA is the N=2 legacy counter helper.
// The matched ShroudManagerCell::xfer at 0x0073EBB0
// calls it for pre-1.2 loads, then zeros the third counter. Its Ghidra
// extent and the call target independently establish the 106-byte body;
// the previous rope/parseTurret drift votes are unrelated identities.
Xfer *rva0073ea90(Xfer *xfer, unsigned short *vals)
{
	UnsignedInt count = 2;
	int n = 2;
	(*xfer == count);
	if (count != 2) {
		XferException error;
		bfmeFormatText(&error, 0, 0);
		_CxxThrowException(&error, (const _s__ThrowInfo *)&g_guardTargetTypeThrowInfo); __assume(0);
	}
	do {
		(*xfer == *vals++);
	} while (--n != 0);
	return xfer;
}
