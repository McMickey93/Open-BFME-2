// cl: /O1 /arch:SSE /G7 /Ireference/shims/bfme2_ascii /Ireference/shims/bfmelist /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /ICode/Libraries/Source/WWVegas/WWLib
//
// ?Rva00208081Xfer@@YAPAVXfer@@PAV1@PAX@Z, retail 0x00208081, 89 bytes.
// Fixed 20-element array of 12-byte vectors via rowed Rva001ECA2DXfer.
// Count via slot 0x78 checked against 0x14 with XferException on mismatch.
// Evidence: leaf lane caller 0x0020B803 and rowed callees plus prev next Xfer list units.
typedef unsigned int UnsignedInt;
typedef bool Bool;

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

extern Xfer *Rva001ECA2DXfer(Xfer *xfer, void *storage);

Xfer *Rva00208081Xfer(Xfer *xfer, void *storage)
{
	UnsignedInt count = 20;
	xfer->operator==(count);
	if (count != 20)
	{
		throw XferException(0, 0);
	}
	char *p = (char *)storage;
	UnsignedInt left = 20;
	do
	{
		Rva001ECA2DXfer(xfer, p);
		p += 12;
		--left;
	} while (left != 0);
	return xfer;
}
