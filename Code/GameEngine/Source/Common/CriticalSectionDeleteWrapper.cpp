// platformsdk
// Critical-section delete wrapper: twelve-byte __cdecl free function with one shape:
//
//     mov eax,[esp+4] / push eax / call [DeleteCriticalSection] / ret
//
// Forwards its argument to the kernel32 DeleteCriticalSection import.
// The import rides the IAT via dllimport; the wrapper itself is __cdecl
// (ends with ret, not ret 4).
// Identity is not recovered: the name is derived from its address.
// No // cl: line (defaults match the frameless twelve-byte shape).

#include <windows.h>

// ?Rva000317E0Delete@@YAXPAX@Z @ 0x000317E0 (12B): forwards to DeleteCriticalSection.
// CC-pad before, frameless push/call/ret, direct E8 caller at 0x00033E77
// (unclaimed). Opaque address-derived name.
void Rva000317E0Delete(void *cs)
{
	DeleteCriticalSection((CRITICAL_SECTION *)cs);
}
