// cl: /DNDEBUG /MD /EHsc
//
// Rva0026EDC4Xfer at retail 0x0026EDC4, 24 bytes (mangled Rva0026EDC4Xfer free cdecl
// taking Xfer and void). Free helper called by Upgrade xfer at 0x0026EE11:
// forwards Xfer and status field to Xfer vtable slot +0x94 with UpgradeStatusType
// context and size 4. String xref unique to this body. Vtable layout follows the
// XferVersionTransfer TU where BFME2 transfer sits at +0x98 so +0x94 is slot37.

#include "XferVectorTypes.h"
#include "../../../Include/Common/BfmeXfer.h"

void __cdecl Rva0026EDC4Xfer(Xfer *xfer, void *data)
{
	xfer->XferEnum("UpgradeStatusType", data, 4);
}

class Rva0026EE11
{
public:
	void rva0026EE11(Xfer *xfer);
private:
	unsigned char m_pad[8];
	int m_status;
};

// Rva0026EE11 chain at retail 0x0026EE11 31 bytes: Version1 via rowed Xfer
// then the helper above with status field at +8. Callees both rowed.
void Rva0026EE11::rva0026EE11(Xfer *xfer)
{
	xfer->Version1();
	Rva0026EDC4Xfer(xfer, &m_status);
}
