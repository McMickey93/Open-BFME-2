// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// winmm.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK MMSystem.h, included through windows.h
// with _WINMM_ defined (the header's own switch) so WINMMAPI is empty and
// these definitions are not dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define _WINMM_
#include <windows.h>
extern "C" {
// _timeGetTime@0
typedef DWORD (WINAPI *PFN_timeGetTime)(void);
extern PFN_timeGetTime __identifier("_imp__timeGetTime@0");
DWORD WINAPI timeGetTime(void) {
 return __identifier("_imp__timeGetTime@0")();
}

// _timeBeginPeriod@4
typedef MMRESULT (WINAPI *PFN_timeBeginPeriod)(UINT);
extern PFN_timeBeginPeriod __identifier("_imp__timeBeginPeriod@4");
MMRESULT WINAPI timeBeginPeriod(UINT uPeriod) {
 return __identifier("_imp__timeBeginPeriod@4")(uPeriod);
}

// _timeEndPeriod@4
typedef MMRESULT (WINAPI *PFN_timeEndPeriod)(UINT);
extern PFN_timeEndPeriod __identifier("_imp__timeEndPeriod@4");
MMRESULT WINAPI timeEndPeriod(UINT uPeriod) {
 return __identifier("_imp__timeEndPeriod@4")(uPeriod);
}
}
