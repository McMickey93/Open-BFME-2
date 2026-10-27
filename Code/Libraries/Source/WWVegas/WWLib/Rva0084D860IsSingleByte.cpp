// cl: /MD /D_STLP_USE_STATIC_LIB
// platformsdk
// BFME1 donor: Rva0084DBStringAndCodePage.cpp. Retail stores GetCPInfo's
// MaxCharSize in the first dword of a 20-byte local and tests it against 1.
// Target disassembly reads owner+4 as the code-page value.

#include <windows.h>

struct Rva0084D860CodePage
{
	unsigned int unknown;
	unsigned int codePage;
};

bool Rva0084D860IsSingleByte(const Rva0084D860CodePage *owner)
{
	CPINFO info;
	GetCPInfo(owner->codePage, &info);
	return info.MaxCharSize == 1;
}
