// cl: /O1 /MD /DNDEBUG
// Identity: ModuleFactory registers this module as "BeaconClientUpdate" (addModule pairs
// the name with its factories); formerly misnamed PointDefenseLaserUpdate.
// Trial: ??0BeaconClientUpdate@@QAE@PAVThing@@PBVModuleData@@@Z.
// Base 0x00362EC7 (pinned opaque); and-zeroed slot, hand-placed vtable
// (novtable), then a global-pointer member load. Factory stub order.
#include "../../../GameClient/Drawable/Update/BeaconClientUpdateView.h"

// PointDefenseLaserUpdate_vftable: matched references place it at VA 0xc5eb30 (retail .rdata value -26).
extern "C" char PointDefenseLaserUpdate_vftable = -26;

BeaconClientUpdate::BeaconClientUpdate(Thing *thing, const ModuleData *moduleData)
	: Rva00362EC7(thing, moduleData)
{
	id = INVALID_PARTICLE_SYSTEM_ID;
	*reinterpret_cast<char **>(this) = &PointDefenseLaserUpdate_vftable;
	lastRadarPulse = ((ClockView *)TheGameLogic)->frame;
}

// ??1BeaconClientUpdate@@ present-unmatched
BeaconClientUpdate::~BeaconClientUpdate()
{
}
