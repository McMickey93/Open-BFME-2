// ?isValidContainerFor@TunnelTracker@@QAE_NPAVObject@@_N@Z
// cl: /DNDEBUG /MD /EHsc
// stlport
// ?isValidContainerFor@TunnelTracker@@QAE_NPAVObject@@_N@Z, retail 0x004F5473, 76 bytes.
// Finish lane from stash 0x004f5473 (score 0.93): count-limit check with testStatus 0x26 and flag109 0x10 guards.
// Layout: TunnelTracker list at +0x10 count at +0x18 per neighbours Rva004F5436Count plus Rva004F54BFRemove; Object+4 inner flag109; GlobalData limit at +0xA98. Evidence: finish packet slot plus callers 0x004664FC 0x0047DDD0.
#include <list>
#include "../RTS/TunnelTrackerNemesisView.h"

struct Rva004F5473Inner
{
	char m_pad[0x109];
	unsigned char m_flag109;
};

extern GlobalData *TheWritableGlobalData;

bool TunnelTracker::isValidContainerFor(Object *obj, bool flag)
{
	if (obj != 0) {
		if ((((Rva004F5473Inner *)obj->m_template)->m_flag109 & 0x10) == 0) {
			if (!flag || obj->testStatus(OBJECT_STATUS_26))
				return true;
			int limit = TheWritableGlobalData->m_maxTunnelCapacity;
			int count = m_containListSize;
			_ReadWriteBarrier();
			return count < limit;
		}
	}
	return false;
}
