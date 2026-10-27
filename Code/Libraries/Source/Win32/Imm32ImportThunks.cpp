// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// imm32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK imm.h, whose declarations carry no
// dllimport. imm.h leaves most parameters unnamed; the documented Win32
// parameter names are used.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#include <windows.h>
#include <imm.h>
extern "C" {
// _ImmAssociateContext@8
typedef HIMC (WINAPI *PFN_ImmAssociateContext)(HWND, HIMC);
extern PFN_ImmAssociateContext __identifier("_imp__ImmAssociateContext@8");
HIMC WINAPI ImmAssociateContext(HWND hWnd, HIMC hIMC) {
 return __identifier("_imp__ImmAssociateContext@8")(hWnd, hIMC);
}

// _ImmSetOpenStatus@8
typedef BOOL (WINAPI *PFN_ImmSetOpenStatus)(HIMC, BOOL);
extern PFN_ImmSetOpenStatus __identifier("_imp__ImmSetOpenStatus@8");
BOOL WINAPI ImmSetOpenStatus(HIMC hIMC, BOOL fOpen) {
 return __identifier("_imp__ImmSetOpenStatus@8")(hIMC, fOpen);
}

// _ImmNotifyIME@16
typedef BOOL (WINAPI *PFN_ImmNotifyIME)(HIMC, DWORD, DWORD, DWORD);
extern PFN_ImmNotifyIME __identifier("_imp__ImmNotifyIME@16");
BOOL WINAPI ImmNotifyIME(HIMC hIMC, DWORD dwAction, DWORD dwIndex, DWORD dwValue) {
 return __identifier("_imp__ImmNotifyIME@16")(hIMC, dwAction, dwIndex, dwValue);
}

// _ImmGetCompositionStringW@16
typedef LONG (WINAPI *PFN_ImmGetCompositionStringW)(HIMC, DWORD, LPVOID, DWORD);
extern PFN_ImmGetCompositionStringW __identifier("_imp__ImmGetCompositionStringW@16");
LONG WINAPI ImmGetCompositionStringW(HIMC hIMC, DWORD dwIndex, LPVOID lpBuf, DWORD dwBufLen) {
 return __identifier("_imp__ImmGetCompositionStringW@16")(hIMC, dwIndex, lpBuf, dwBufLen);
}

// _ImmGetProperty@8
typedef DWORD (WINAPI *PFN_ImmGetProperty)(HKL, DWORD);
extern PFN_ImmGetProperty __identifier("_imp__ImmGetProperty@8");
DWORD WINAPI ImmGetProperty(HKL hKL, DWORD fdwIndex) {
 return __identifier("_imp__ImmGetProperty@8")(hKL, fdwIndex);
}

// _ImmGetCandidateListW@16
typedef DWORD (WINAPI *PFN_ImmGetCandidateListW)(HIMC, DWORD, LPCANDIDATELIST, DWORD);
extern PFN_ImmGetCandidateListW __identifier("_imp__ImmGetCandidateListW@16");
DWORD WINAPI ImmGetCandidateListW(HIMC hIMC, DWORD deIndex, LPCANDIDATELIST lpCandList, DWORD dwBufLen) {
 return __identifier("_imp__ImmGetCandidateListW@16")(hIMC, deIndex, lpCandList, dwBufLen);
}

// _ImmGetCandidateListCountW@8
typedef DWORD (WINAPI *PFN_ImmGetCandidateListCountW)(HIMC, LPDWORD);
extern PFN_ImmGetCandidateListCountW __identifier("_imp__ImmGetCandidateListCountW@8");
DWORD WINAPI ImmGetCandidateListCountW(HIMC hIMC, LPDWORD lpdwListCount) {
 return __identifier("_imp__ImmGetCandidateListCountW@8")(hIMC, lpdwListCount);
}

// _ImmDestroyContext@4
typedef BOOL (WINAPI *PFN_ImmDestroyContext)(HIMC);
extern PFN_ImmDestroyContext __identifier("_imp__ImmDestroyContext@4");
BOOL WINAPI ImmDestroyContext(HIMC hIMC) {
 return __identifier("_imp__ImmDestroyContext@4")(hIMC);
}

// _ImmReleaseContext@8
typedef BOOL (WINAPI *PFN_ImmReleaseContext)(HWND, HIMC);
extern PFN_ImmReleaseContext __identifier("_imp__ImmReleaseContext@8");
BOOL WINAPI ImmReleaseContext(HWND hWnd, HIMC hIMC) {
 return __identifier("_imp__ImmReleaseContext@8")(hWnd, hIMC);
}

// _ImmGetContext@4
typedef HIMC (WINAPI *PFN_ImmGetContext)(HWND);
extern PFN_ImmGetContext __identifier("_imp__ImmGetContext@4");
HIMC WINAPI ImmGetContext(HWND hWnd) {
 return __identifier("_imp__ImmGetContext@4")(hWnd);
}

// _ImmCreateContext@0
typedef HIMC (WINAPI *PFN_ImmCreateContext)(void);
extern PFN_ImmCreateContext __identifier("_imp__ImmCreateContext@0");
HIMC WINAPI ImmCreateContext(void) {
 return __identifier("_imp__ImmCreateContext@0")();
}

// _ImmGetIMEFileNameA@12
typedef UINT (WINAPI *PFN_ImmGetIMEFileNameA)(HKL, LPSTR, UINT);
extern PFN_ImmGetIMEFileNameA __identifier("_imp__ImmGetIMEFileNameA@12");
UINT WINAPI ImmGetIMEFileNameA(HKL hKL, LPSTR lpszFileName, UINT uBufLen) {
 return __identifier("_imp__ImmGetIMEFileNameA@12")(hKL, lpszFileName, uBufLen);
}
}
