// cl: /DNDEBUG /MD
// ?update@RadiusDecalUpdate@@UAE?AW4UpdateSleepTime@@XZ retail 0x0039157B, 51
// bytes: Zero Hour's RadiusDecalUpdate::update. It is the first slot of the
// three-slot UpdateModuleInterface vftable (rdata 0x0081A00C) that sits right
// before RadiusDecalUpdate's primary one (??_GRadiusDecalUpdate at 0x0081A018),
// so MSVC compiles it on the interface subobject at +0x10: the object pointer
// is read at -8 (+0x08 in the module), the delivery decal at +0x10 (+0x20) and
// the kill-when-no-longer-attacking flag at +0x20 (+0x30). Callees:
// Object::testStatus (rowed 0x0004E536, OBJECT_STATUS_IS_ATTACKING = 0x16),
// RadiusDecal::clear (rowed 0x00330DBA) and RadiusDecal::update (pinned
// 0x00330F98). It sits between killRadiusDecal (0x0039155F) and xfer
// (0x003915AE) as in the Zero Hour source.

// The classes come from RadiusDecalUpdateView.h, the view of the
// RadiusDecalUpdate.cpp TU this body joins.
#include "RadiusDecalUpdateView.h"

//-------------------------------------------------------------------------------------------------
UpdateSleepTime RadiusDecalUpdate::update()
{
	if (m_killWhenNoLongerAttacking && !getObject()->testStatus(OBJECT_STATUS_IS_ATTACKING))
	{
		m_deliveryDecal.clear();
		return UPDATE_SLEEP_FOREVER;
	}

	m_deliveryDecal.update();
	return UPDATE_SLEEP_NONE;
}
