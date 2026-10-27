// cl: /MD
// platformsdk
// Donor: Open-BFME-1 10af19f44a89ab7ecc23195bb9a842ceafbc02c9,
// game/Libraries/Source/WWVegas/WWLib/Rva0084D790LocaleWrappers.cpp.

#include <windows.h>

// Target evidence: [0x00020A60,0x00020A8F), then INT3 padding.
// IAT 0x00BBA1B0 declares kernel32!GetStringTypeW. Retail builds a terminated
// WCHAR pair, requests CT_CTYPE1 (1), and masks the first output word.
// The donor's address label is not an original target function identity.
int __cdecl Rva00020A60(const void *unused, int character, int mask)
{
    WCHAR input[2] = {(WCHAR)character, 0};
    WORD result[2];
    GetStringTypeW(1, input, -1, result);
    return result[0] & mask;
}

// This is only the first-dword view read by this target body; the rest of the
// owner and its original type are unknown. LCMapStringW consumes that dword
// as an LCID. The donor carries the same access, not a proven target class name.
struct Rva00020A90Locale { LCID m_00; };

// Target evidence: [0x00020A90,0x00020AB7), then INT3 padding.
// IAT 0x00BBA1B4 declares kernel32!LCMapStringW; flag 0x100 maps one WCHAR
// to lowercase. BFME1 folds this donor with another address, so keep the
// target's address label rather than spending either donor function name.
WCHAR __cdecl Rva00020A90(Rva00020A90Locale *locale, int character)
{
    WCHAR result;
    LCMapStringW(locale->m_00, 0x100, (const WCHAR *)&character, 1, &result, 1);
    return result;
}
