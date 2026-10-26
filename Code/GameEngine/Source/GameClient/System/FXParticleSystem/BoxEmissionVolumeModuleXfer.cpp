// cl: /MD /ICode/Libraries/Include/Lib
// ?xfer@BoxEmissionVolumeModule@FXParticleSystem@@MAEXPAVXfer@@@Z
// retail 0x0055CFC3, 45 bytes: slot 3 (offset 0x0C) of the class's vtable
// 0x0081C784 (??_7BoxEmissionVolumeModule@FXParticleSystem@@6B
// DefaultModuleHeadBase@@@), whose slot 7 is the rowed box sample 0x0055D0D5
// over the same hollow flag (+0x20) and extents (+0x24). Version1, then the
// flag through xferBool (+0x90) and the extents through xferCoord3D (+0x60),
// the BFME 2 Xfer slots TerrainLogicXfer.cpp names. No base call.
#include "Coord3DBase.h"

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
#include "../../../../Include/Common/BfmeXfer.h"

namespace FXParticleSystem
{

class BoxEmissionVolumeModule
{
protected:
	virtual void xfer(Xfer *xfer);

private:
	char m_pad04[0x20 - 4];
	bool m_isHollow;		// +0x20
	Coord3D m_halfSize;		// +0x24
};

void BoxEmissionVolumeModule::xfer(Xfer *xfer)
{
	xfer->Version1();
	*xfer == m_isHollow;
	*xfer == asBase(m_halfSize);
}

}
