// cl: /Ireference/shims/bfmelist /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /ICode/Libraries/Source/WWVegas/WWLib /ICode/GameEngine/Source/Common
// stlport
// ?Rva002070F7Xfer@@YAPAVXfer@@PAV1@PAV?$list@UBfmeSpecialPowerTimer8@@V?$allocator@UBfmeSpecialPowerTimer8@@@_STL@@@_STL@@@Z @0x002070F7 89B free helper xferring array of 20 SpecialPowerTimer lists via rowed 0x00206B02 count 20 via slot 0x78.
// Evidence: chain lane callee 0x00206B02 rowed; callers 4x in FUN_0060a859; prev 0x00206FE6 next 0x00207150.
#define _STLP_NO_EXCEPTIONS 1
#include <list>
#include "BfmeSpecialPowerTimer8.h"

typedef unsigned char UnsignedByte;
typedef unsigned int UnsignedInt;
typedef bool Bool;

struct XferVersion
{
	UnsignedByte m_version;
	UnsignedByte m_currentVersion;
};

#include "../../Common/System/XferVectorTypes.h"
#include "../../../Include/Common/BfmeXfer.h"

// Retail ThrowInfo names the 8-byte XferException class and its rowed
// copy constructor and destructor (see Common/System/XferException.cpp).
class XferException
{
public:
	XferException(int tag, const char *format, ...);
	XferException(const XferException &that);
	~XferException();

	char *text;
	int tag;
};

typedef _STL::list<BfmeSpecialPowerTimer8> ListTimer;
Xfer *Rva00206B02Xfer(Xfer *xfer, ListTimer *list);

Xfer *Rva002070F7Xfer(Xfer *xfer, ListTimer *lists)
{
	UnsignedInt count = 20;
	xfer->operator==(count);
	if (count != 20) {
		throw XferException(0, 0);
	}
	for (int i = 0; i < 20; ++i)
		Rva00206B02Xfer(xfer, &lists[i]);
	return xfer;
}
