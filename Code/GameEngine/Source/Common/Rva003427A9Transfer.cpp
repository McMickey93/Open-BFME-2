// cl: /DNDEBUG /MD
//
// ?xfer@Rva003427A9@@QAEXPAVXfer@@@Z @0x003427A9 42B.
//
// Xfer-driven member transfer: Version1 (rowed 0x000053EE) on the stream,
// then the stream's virtual slots 30 and 24 over the +0x4C/+0x50 members
// in that order (the second call reuses edi via add, the vptr reloads).
// No direct caller exists, so this is a virtual (xfer-family) body;
// the member types are unestablished, hence plain ints carried only for
// their addresses. Slot contents are deliberately unnamed pure virtuals:
// indirect calls encode only the slot, and the two slot identities are
// not yet proven (the BFME2 Xfer operator== view would put Region3D and
// RealRange here, but those overlap, so the count is not trusted).

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
#include "../../Include/Common/BfmeXfer.h"

class Rva003427A9
{
public:
	void xfer(Xfer *x);
private:
	char m_pad00[0x4c];
	int m_4c; // +0x4C
	int m_50; // +0x50
};

void Rva003427A9::xfer(Xfer *xfer)
{
	xfer->Version1();
	(*xfer == reinterpret_cast<unsigned int &>(m_4c));
	(*xfer == reinterpret_cast<Coord3DBase &>(m_50));
}
