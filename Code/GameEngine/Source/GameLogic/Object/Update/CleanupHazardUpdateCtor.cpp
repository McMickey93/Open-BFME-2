// cl: /O1 /MD /DNDEBUG
// Identity: ModuleFactory registers this data class under "BeaconClientUpdateModuleData" (addModule
// pairs the name with this factory); formerly misnamed CleanupHazardUpdate/CleanupHazardUpdateModuleData.
// ??0BeaconClientUpdateModuleData@@QAE@XZ at retail 0x004C964C.
// Root-class default ctor: vtable plus two int members. No base, no calls.
// Factory stub order names it; stub size 0x10 confirms the layout.
#include "../../../GameClient/Drawable/Update/BeaconClientUpdateView.h"

BeaconClientUpdateModuleData::BeaconClientUpdateModuleData()
	: framesBetweenRadarPulses(0x1E), radarPulseDuration(0x0F)
{
}

// ??1BeaconClientUpdateModuleData@@ present-unmatched
BeaconClientUpdateModuleData::~BeaconClientUpdateModuleData()
{
}
