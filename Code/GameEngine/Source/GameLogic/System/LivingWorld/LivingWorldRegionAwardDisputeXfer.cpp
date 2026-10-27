// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?xfer@RegionAwardDispute@@MAEXPAVXfer@@@Z, retail 0x004FBDF7..0x004FBE7A
// (131B, RET 4): the dispute's Xfer (vftable 0x00BFE280 slot 3). Version {1,2}; region id at +4 through
// the rowed 0x003EFE82; the dispute type at +0x14 is read through the
// rowed enum helper 0x004FBDDF for the old version (1 keeps 0x20, anything
// else becomes 0x22) and through the rowed 0x002B24F0 otherwise; a 4-byte
// member at +0x1C through Xfer slot 0x90; then the disputant vector at +8
// through the rowed LivingWorld 0x002B8DFC. Layout beyond these fields is
// opaque. Evidence: retail frame and callees read at the REL32s; field
// roles other than the vector (+8, the pointer vector of
// LivingWorldRegionAwardDispute.cpp) are unnamed.
#include <vector>

typedef unsigned char UnsignedByte;

struct XferVersion
{
	UnsignedByte m_version;
	UnsignedByte m_currentVersion;
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
#include "../../../../Include/Common/BfmeXfer.h"

struct Rva003EFE82Obj;
struct Rva002B24F0Obj;
class ModuleData;
int Rva003EFE82Get(Rva003EFE82Obj *xfer, void *value);
int Rva002B24F0Get(Rva002B24F0Obj *xfer, void *value);
void XferRegionAwardDisputeDisputeType(Xfer *xfer, void *value);

class Rva002BA8F1Logic
{
public:
	void rva002B8DFC(Xfer *xfer, _STL::vector<const ModuleData *> *vec);
};
class LivingWorldLogic;
extern LivingWorldLogic *TheLivingWorldLogic;

#define BFME_SNAPSHOT_NAME_SLOT
#include "../../../../../../reference/shims/moduledata/Common/Snapshot.h"

// Retail vftable 0x00BFE280 slot 3 (the Snapshot xfer).
class RegionAwardDispute : public Snapshot
{
public:
	virtual ~RegionAwardDispute();
protected:
	virtual void loadPostProcess();
	virtual const char *GetSnapshotName() const;
	virtual void xfer(Xfer *xfer);

private:
	int m_regionID;				// +0x04
	_STL::vector<const ModuleData *> m_disputants;	// +0x08
	int m_disputeType;			// +0x14
	int m_18;
	int m_1C;				// +0x1C
};

void RegionAwardDispute::xfer(Xfer *xfer)
{
	XferVersion version;
	version.m_version = 1;
	version.m_currentVersion = 2;
	(*xfer == reinterpret_cast<Xfer::Version &>(version));

	Rva003EFE82Get((Rva003EFE82Obj *)xfer, &m_regionID);
	if (version.m_currentVersion < 2) {
		int old = 1;
		XferRegionAwardDisputeDisputeType(xfer, &old);
		m_disputeType = old != 1 ? 0x22 : 0x20;
	} else {
		Rva002B24F0Get((Rva002B24F0Obj *)xfer, &m_disputeType);
	}
	(*xfer == *reinterpret_cast<bool *>(&m_1C));
	((Rva002BA8F1Logic *)TheLivingWorldLogic)->rva002B8DFC(xfer, &m_disputants);
}
