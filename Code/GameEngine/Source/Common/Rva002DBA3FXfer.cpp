// cl: /MD
//
// ?xfer@Rva002DBA3F@@QAEXPAVXfer@@@Z, retail 0x002DBA3F, 43 bytes.
// __thiscall xfer-style method taking Xfer*: Version1 via rowed 0x000053EE
// then LivingWorldRegionID into +4 via rowed Rva003EFE82Get 0x003EFE82 then
// int at +8 via Xfer slot 0x3C, which BfmeXfer.h's reverse-ordered
// operator== run assigns to the RGBColor overload (the int overload is
// 0x7C), so the call casts. Chain lane: calls the just-landed 0x003EFE82.
// Caller 0x002DE072. Prev 0x002DBA19 lea getter / next SaveDate::isNewerThan.
// Honest address name; owner class unproven.
class Snapshot;
class AsciiString;
class UnicodeString;
class PooledString;
struct Coord3DBase;
struct ICoord3D;
struct Region3D;
struct IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
struct RealRange;
struct RGBColor;
struct RGBAColorReal;
struct RGBAColorInt;
#include "../../Include/Common/BfmeXfer.h"

struct Rva003EFE82Obj;
int __cdecl Rva003EFE82Get(struct Rva003EFE82Obj *obj, void *out);

struct Rva002DBA3F
{
	char m_pad[4];
	int m_regionID;
	int m_val;
	void xfer(class Xfer *xfer);
};

void Rva002DBA3F::xfer(class Xfer *xfer)
{
	xfer->Version1();
	Rva003EFE82Get((struct Rva003EFE82Obj *)xfer, &m_regionID);
	// Retail transfers the int through slot 15 (+0x3C), the RGBColor overload.
	*xfer == (RGBColor &)m_val;
}
