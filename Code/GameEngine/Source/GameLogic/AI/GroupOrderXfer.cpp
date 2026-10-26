// cl: /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_STLP_USE_MALLOC /D_CRTIMP=
// stlport
// ?xfer@GroupOrder@@UAEXPAVXfer@@@Z @0x00548AC2 70B evidence: vtable slot 3 offset 0xC of 0x0086A520 class of GroupOrder ctor; calls rowed Rva00398280Xfer 0x00398280 with this+4 vector; xferVersion 1-1 then xferUnsignedInt this+0x10 this+0x14; unblocks 0x00546FC9 etc.; callers 0x00546A48 etc.
// Proven method keeps real name xfer (slot 3 recipe).
#include <vector>

typedef unsigned char UnsignedByte;
typedef unsigned int UnsignedInt;
typedef bool Bool;

enum ScienceType
{
	SCIENCE_0 = 0
};


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


typedef _STL::vector<ScienceType> ScienceTypeVector;
extern Xfer *Rva00398280Xfer(Xfer *xfer, ScienceTypeVector *vec);

class GroupOrder
{
public:
	virtual ~GroupOrder();
	virtual void v01();
	virtual void v02();
	virtual void xfer(Xfer *xfer);
private:
	ScienceTypeVector m_list;
	UnsignedInt m_10;
	UnsignedInt m_14;
};

void GroupOrder::xfer(Xfer *xfer)
{
	Xfer::Version version;
	version.m_version = 1;
	version.m_currentVersion = 1;
	*xfer == version;
	Rva00398280Xfer(xfer, &m_list);
	*xfer == m_10;
	*xfer == m_14;
}
