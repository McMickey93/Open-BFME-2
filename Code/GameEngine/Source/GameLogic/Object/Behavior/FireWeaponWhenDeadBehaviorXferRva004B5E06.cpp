// cl: /MD
// ?rva004B5E06@Rva004B5E06@@QAEXPAVXfer@@@Z retail 0x004B5E06 64B
// Slot 3 of vtables 0x008581CC 0x008583B0; Version(1 2) via Xfer slot 0x28 gating bool at +0x20 via slot 0x90 then base UpgradeModule xfer.
// Evidence: vtable slot 3 plus Xfer slot order Version 0x28 bool 0x90 from Rva005C45D2 plus rowed UpgradeModule xfer 0x004CE3F9.
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
		unsigned char m_current;
		unsigned char m_minimum;
	};

class UpgradeModule
{
protected:
	virtual void xfer(Xfer *xfer);
};

class Rva004B5E06 : public UpgradeModule
{
public:
	void rva004B5E06(Xfer *xfer);
};

void Rva004B5E06::rva004B5E06(Xfer *xfer)
{
	Xfer::Version version;
	version.m_current = 1;
	version.m_minimum = 2;
	*xfer == version;
	if (version.m_minimum >= 2)
		*xfer == *(bool *)((char *)this + 0x20);
	UpgradeModule::xfer(xfer);
}
