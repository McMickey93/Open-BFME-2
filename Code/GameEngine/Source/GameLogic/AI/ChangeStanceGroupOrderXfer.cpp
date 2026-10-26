// cl: /MD
// ?xfer@ChangeStanceGroupOrder@@UAEXPAVXfer@@@Z @0x00546B91 54B evidence: slot 3 of 0x0086A36C ChangeStanceGroupOrder; base GroupOrder xfer rowed 0x00548AC2 then xferVersion 1-1 then XferStancesEnum rowed 0x0045ED66 for this+0x18; member int at +0x18 (the stance).
// Proven method keeps real name xfer.
typedef unsigned char UnsignedByte;
typedef bool Bool;
typedef unsigned int UnsignedInt;


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

class Xfer::Version
{
public:
	UnsignedByte m_version;
	UnsignedByte m_currentVersion;
};


extern void __cdecl XferStancesEnum(Xfer *xfer, int *value);

class GroupOrder
{
public:
	virtual ~GroupOrder();
	virtual void v01();
	virtual void v02();
	virtual void xfer(Xfer *xfer);
protected:
	unsigned char m_pad04[0x14];
};

class ChangeStanceGroupOrder : public GroupOrder
{
public:
	virtual void xfer(Xfer *xfer);
private:
	int m_stance;
};

void ChangeStanceGroupOrder::xfer(Xfer *xfer)
{
	Xfer::Version version;
	version.m_version = 1;
	version.m_currentVersion = 1;
	GroupOrder::xfer(xfer);
	*xfer == version;
	XferStancesEnum(xfer, &m_stance);
}
