// cl: /O1 /G7 /arch:SSE /DNDEBUG /MD /EHsc /Ireference/shims/bfme2_ascii
// platformsdk
// ?rva0025DA8D@Display@@UAE_NVAsciiString@@H@Z, retail 0x0025DA8D (160 bytes, EH, RET 8),
// display vtable slot 72 (W3DDisplay table 0x007C3C80). Refuses on Windows 9x
// (GetVersionExA platform 1); otherwise hands a copy of the movie name, the flags without
// bit 3 and two -1 limits to slot 66 (+0x108) and, when that starts, runs the rowed
// bfmeTickVM0 step and reports success. The slot's own name is not recovered.
#include <windows.h>
#include <string.h>

#include "DisplayStaticDebugView.h"

bool Display::rva0025DA8D(AsciiString movieName, int flags)
{
	OSVERSIONINFOA info;
	memset(&info, 0, sizeof(info));
	info.dwOSVersionInfoSize = sizeof(info);
	GetVersionExA(&info);
	if (info.dwPlatformId != VER_PLATFORM_WIN32_WINDOWS && playMovieFlags(movieName, flags & ~8, -1, -1)) {
		bfmeTickVM0();
		return true;
	}
	return false;
}
