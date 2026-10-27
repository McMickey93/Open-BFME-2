// cl: /DNDEBUG /MD
//
// ?xfer@SpecialDisguiseUpdate@@MAEXPAVXfer@@@Z, retail 0x004B01F4, 97 bytes:
// slot 3 of SpecialDisguiseUpdate's primary vtable 0x00C56398 (ctors
// 0x004B0164, 0x004B02B7), the xfer slot. The UpdateModule part first
// (0x0044DF9F, pinned), nothing more for a light CRC (Xfer slot 4); then the
// two-byte version block (1, 2) through Xfer slot 10, the +0x90 field through
// slot 36 and the +0x8C field through slot 28, and from version 2 on the
// SpecialAbilityUpdate part (matched 0x0044F996). The field types behind
// slots 28 and 36 are not established. The version block is a small class
// with a constructor: that is what lets cl 7.1 place it in the dead argument
// slot (+8) the way retail does.
typedef unsigned char UnsignedByte;


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

class Xfer::Version
{
public:
	Version(UnsignedByte first, UnsignedByte version) : m_first(first), m_version(version) {}
	UnsignedByte m_first;
	UnsignedByte m_version;
};

class UpdateModule
{
public:
	virtual ~UpdateModule();
	virtual void slot1(); virtual void slot2();
	void xfer(Xfer *xfer);
};

class SpecialAbilityUpdate : public UpdateModule
{
protected:
	virtual void xfer(Xfer *xfer);
};

class SpecialDisguiseUpdate : public SpecialAbilityUpdate
{
protected:
	virtual void xfer(Xfer *xfer);
private:
	unsigned char m_pad04[0x8C - 4];
	int m_8C; // +0x8C
	int m_90; // +0x90
};

void SpecialDisguiseUpdate::xfer(Xfer *xfer)
{
	UpdateModule::xfer(xfer);
	if (xfer->IsLightCRC())
		return;
	Xfer::Version version(1, 2);
	xfer->operator==(version);
	xfer->operator==(reinterpret_cast<bool &>(m_90));
	xfer->operator==(reinterpret_cast<float &>(m_8C));
	if (version.m_version >= 2)
		SpecialAbilityUpdate::xfer(xfer);
}
