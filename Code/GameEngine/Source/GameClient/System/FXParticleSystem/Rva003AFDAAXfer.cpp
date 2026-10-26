// cl: /MD

// ?xfer@Rva003AFDAA@@UAEXPAVXfer@@@Z @0x003AFDAA 71B: slot 3 (offset 0xC) of
// 0x0081D950 (class of ??1Rva003B0152) and 0x0081DA10 (class of ??1Rva003B0401).
// Xfer declaration is the UpdateModuleXfer-proven spelling (GpuDrawModuleInfoDoXfer).
// Retail order: IsCRC early-out (slot 0xC), Version{1,1} via ==Version (slot 0x28),
// uint temp of member +0x10 via ==uint (slot 0x78), then IsStoring (slot 8).

class AsciiString;
class UnicodeString;
class PooledString;
struct XferUnknown11;
class Coord3DBase;
class ICoord3D;
class Region3D;
class IRegion3D;
class Coord2D;
class ICoord2D;
class Region2D;
class IRegion2D;
class RealRange;
class RGBColor;
class RGBAColorReal;
class RGBAColorInt;
class Snapshot;

#include "../../../../Include/Common/BfmeXfer.h"

class Xfer::Version
{
public:
	union
	{
		int i;
		unsigned char b[4];
	};
};

class Rva003AFDAA
{
public:
	virtual void xfer(Xfer *xfer);

private:
	char m_pad04[12]; // +0x04..0x0F (vptr at +0x0)
	int m_10; // +0x10: transferred as unsigned int
};

void Rva003AFDAA::xfer(Xfer *xfer)
{
	if (xfer->IsCRC())
		return;
	Xfer::Version ver;
	ver.b[0] = 1;
	ver.b[1] = 1;
	*xfer == ver;
	unsigned int tmp = m_10;
	*xfer == tmp;
	xfer->IsStoring();
}
