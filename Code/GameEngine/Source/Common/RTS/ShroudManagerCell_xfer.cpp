// cl: /MD
//
// ?xfer@ShroudManagerCell@@QAEXPAVXfer@@@Z, retail 0x0073EBB0
// (134 B).  ShroudManagerCell::xfer: write version 1.2 through
// the Xfer vtable slot +0x28, then for each of the 20 player states transfer
// its status short (slot +0x80) and its three counter shorts.  On load of a
// pre-1.2 save (isLoading slot +4 and the stored current version below 2) only
// the two legacy counters are read, through the N=2 helper 0x0073EA90, and the
// third counter is zeroed; otherwise the N=3 helper 0x0073EB00 fills all three.
// The element layout (cellNodes at +0, 8-byte PlayerState array at +4) and the
// helper twins match Rva0073EB00Xfer.cpp below; the N=2 helper is pinned.

typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;
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

struct XferVersion
{
	unsigned char m_version;
	unsigned char m_currentVersion;
};

struct ShroudManagerImpl008FBA40PlayerState
{
	UnsignedShort status;
	UnsignedShort counters[3];
};

class ShroudManagerCell
{
public:
	void xfer(Xfer *xfer);

private:
	void *cellNodes;
	ShroudManagerImpl008FBA40PlayerState playerStates[20];
};

extern Xfer *Rva0073EB00Xfer(Xfer *xfer, UnsignedShort *values);
extern Xfer *rva0073ea90(Xfer *xfer, UnsignedShort *values);

void ShroudManagerCell::xfer(Xfer *xfer)
{
	XferVersion version;
	version.m_version = 1;
	version.m_currentVersion = 2;
	(*xfer == reinterpret_cast<Xfer::Version &>(version));

	for (int i = 0; i < 20; ++i)
	{
		(*xfer == playerStates[i].status);
		if (xfer->IsLoading() && version.m_currentVersion < 2)
		{
			UnsignedShort values[2];
			rva0073ea90(xfer, values);
			playerStates[i].counters[0] = values[0];
			playerStates[i].counters[1] = values[1];
			playerStates[i].counters[2] = 0;
		}
		else
		{
			Rva0073EB00Xfer(xfer, playerStates[i].counters);
		}
	}
}
