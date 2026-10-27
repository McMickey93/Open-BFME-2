// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?Rva0040E269Xfer@@YAPAVXfer@@PAV1@PAV?$vector@PBVModuleData@@V?$allocator@PBVModuleData@@@_STL@@@_STL@@@Z @0x0040E269 (202B):
// Free Xfer vector<const ModuleData*> helper version {1,1} via slot 0x28,
// size via slot 0x2C/0x78, isSaving via slot 0x08, saving walks pointer
// elements via slot 0x7C, loading checks empty via FormatText 0x0060C36E plus
// Throw 0x00629094 then reserve 0x002B712E plus push_back 0x004DFCB0.
// Mirrors landed Rva003F2C0CXfer 0x003F2C0C (same 202B, same recipe, element
// via slot 0x50 there). Element method name follows that precedent
// (element-type-derived, virtual so the gate does not resolve it).
// Evidence: unlock lane, strings "std::vector" and
// "Vector must be empty on load", all callees rowed or pinned.
// vector::_M_insert_overflow inlines max(size(), n). A file-static unsigned
// overload takes the call instead, so this TU emits no external max COMDAT.
#include <stl/_algobase.h>
namespace _STL {
static inline const unsigned int &max(const unsigned int &a, const unsigned int &b)
{
    return a < b ? b : a;
}
}

#define _STLP_NO_EXCEPTIONS 1
#include <vector>

typedef unsigned char UnsignedByte;
typedef unsigned int UnsignedInt;
typedef bool Bool;

class ModuleData;

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
struct IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
struct RealRange;
struct RGBColor;
struct RGBAColorReal;
struct RGBAColorInt;
#include "../../../Include/Common/BfmeXfer.h"

class XferException
{
public:
	XferException(int tag, const char *format, ...);
	XferException(const XferException &that);
	~XferException();

	char *text;
	int tag;
};


typedef _STL::vector<const ModuleData *> ModuleDataPtrVector;

Xfer *Rva0040E269Xfer(Xfer *xfer, ModuleDataPtrVector *vec)
{
	XferVersion version;
	version.m_version = 1;
	version.m_currentVersion = 1;
	*xfer == (Xfer::Version &)version;

	UnsignedInt count = (UnsignedInt)vec->size();
	xfer->operator==("std::vector").operator==(count);

	if (xfer->IsStoring()) {
		const ModuleData **end = vec->end();
		const ModuleData **cur = vec->begin();
		while (cur != end) {
			*xfer == (int &)(*cur);
			++cur;
		}
	} else {
		if (!vec->empty()) {
			throw XferException(4, "Vector must be empty on load");
		}
		vec->reserve(count);
		const ModuleData *value;
		while (count != 0) {
			--count;
			vec->push_back(value);
			*xfer == (int &)vec->back();
		}
	}
	return xfer;
}
