// cl: /DNDEBUG /MD /EHsc
// ?DoXfer@DefaultPhysicsModuleInfo@FXParticleSystem@@UAEXAAVXfer@@@Z 0x0055EECB
// 110B (the name Rva0055EF39Xfer.cpp calls it by). Version-gated xfer:
// a two-byte version record (1, 3) is transferred first, then the +0x10 and +0x4
// members, the RandomVariable at +0x14 through the matched xferRandomVariable,
// and the +0x20 and +0x21 members once the version reaches 2 and 3.
class GameClientRandomVariable;

#include "../Common/System/XferVectorTypes.h"
#include "../../Include/Common/BfmeXfer.h"

Xfer &xferRandomVariable(Xfer &xfer, GameClientRandomVariable &value);

struct Rva0055EECBVersion
{
	unsigned char current;
	unsigned char stored;
};

namespace FXParticleSystem
{
class DefaultPhysicsModuleInfo
{
public:
	virtual void DoXfer(Xfer &xfer);
private:
	unsigned char m4[0x0C]; // +0x04
	unsigned char m10[4]; // +0x10
	unsigned char m14[0x0C]; // +0x14
	unsigned char m20[2]; // +0x20
};
}

void FXParticleSystem::DefaultPhysicsModuleInfo::DoXfer(Xfer &xfer)
{
	Rva0055EECBVersion version;
	version.current = 1;
	version.stored = 3;
	xfer == reinterpret_cast<Xfer::Version &>(version);
	xfer == reinterpret_cast<float &>(m10);
	xfer == reinterpret_cast<Coord3DBase &>(m4);
	xferRandomVariable(xfer, *reinterpret_cast<GameClientRandomVariable *>(&m14));
	if (version.stored >= 2)
		xfer == reinterpret_cast<bool &>(m20[0]);
	if (version.stored >= 3)
		xfer == reinterpret_cast<bool &>(m20[1]);
}
