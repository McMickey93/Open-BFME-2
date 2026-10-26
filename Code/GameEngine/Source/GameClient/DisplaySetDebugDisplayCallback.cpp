// cl: /O1 /G7 /arch:SSE /DNDEBUG /MD
// ?setDebugDisplayCallback@Display@@UAEXP6AXPAVDebugDisplayInterface@@PAXPAU_iobuf@@@Z1@Z,
// retail 0x0025C6BD (37 bytes), W3DDisplay vtable slot 74. Zero Hour's Display::
// setDebugDisplayCallback stores the callback and user data (+0x30/+0x34, the fields
// W3DDisplayInit.cpp reads); BFME 2 also records in the writable global data (+0xBBC)
// whether the network debug display (rowed 0x00043D96) is the one installed.
#include "DisplayStaticDebugView.h"

void NetworkDebugDisplay(DebugDisplayInterface *dd, void *userData, FILE *fp);

class GlobalData
{
public:
	unsigned char m_pad000[0xBBC];
	bool m_networkDebugDisplay;		// +0xBBC
};
extern GlobalData *TheWritableGlobalData;

void Display::setDebugDisplayCallback(DebugDisplayCallback *callback, void *userData)
{
	m_debugDisplayCallback = callback;
	m_debugDisplayUserData = userData;
	TheWritableGlobalData->m_networkDebugDisplay = (callback == NetworkDebugDisplay);
}
