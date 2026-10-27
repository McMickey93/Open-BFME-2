// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// shlwapi.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK shlwapi.h, included with _SHLWAPI_
// defined (the header's own switch) so LWSTDAPI is STDAPI and these
// definitions are not dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define _SHLWAPI_
#include <windows.h>
#include <shlwapi.h>
extern "C" {
// _PathCanonicalizeA@8
typedef BOOL (STDAPICALLTYPE *PFN_PathCanonicalizeA)(LPSTR, LPCSTR);
extern PFN_PathCanonicalizeA __identifier("_imp__PathCanonicalizeA@8");
BOOL STDAPICALLTYPE PathCanonicalizeA(LPSTR pszBuf, LPCSTR pszPath) {
 return __identifier("_imp__PathCanonicalizeA@8")(pszBuf, pszPath);
}

// _PathAppendA@8
typedef BOOL (STDAPICALLTYPE *PFN_PathAppendA)(LPSTR, LPCSTR);
extern PFN_PathAppendA __identifier("_imp__PathAppendA@8");
BOOL STDAPICALLTYPE PathAppendA(LPSTR pszPath, LPCSTR pMore) {
 return __identifier("_imp__PathAppendA@8")(pszPath, pMore);
}

// _PathRemoveFileSpecA@4
typedef BOOL (STDAPICALLTYPE *PFN_PathRemoveFileSpecA)(LPSTR);
extern PFN_PathRemoveFileSpecA __identifier("_imp__PathRemoveFileSpecA@4");
BOOL STDAPICALLTYPE PathRemoveFileSpecA(LPSTR pszPath) {
 return __identifier("_imp__PathRemoveFileSpecA@4")(pszPath);
}
}
