// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// shell32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK shellapi.h and ShlObj.h, included with
// _SHELL32_ defined (the headers' own switch) so SHSTDAPI is STDAPI and these
// definitions are not dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define _SHELL32_
#include <windows.h>
#include <shlobj.h>
extern "C" {
// _ShellExecuteA@24
typedef HINSTANCE (STDAPICALLTYPE *PFN_ShellExecuteA)(HWND, LPCSTR, LPCSTR, LPCSTR, LPCSTR, INT);
extern PFN_ShellExecuteA __identifier("_imp__ShellExecuteA@24");
HINSTANCE STDAPICALLTYPE ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd) {
 return __identifier("_imp__ShellExecuteA@24")(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd);
}

// _SHGetSpecialFolderPathW@16
typedef BOOL (STDAPICALLTYPE *PFN_SHGetSpecialFolderPathW)(HWND, LPWSTR, int, BOOL);
extern PFN_SHGetSpecialFolderPathW __identifier("_imp__SHGetSpecialFolderPathW@16");
BOOL STDAPICALLTYPE SHGetSpecialFolderPathW(HWND hwnd, LPWSTR pszPath, int csidl, BOOL fCreate) {
 return __identifier("_imp__SHGetSpecialFolderPathW@16")(hwnd, pszPath, csidl, fCreate);
}

// _CommandLineToArgvW@8
typedef LPWSTR * (STDAPICALLTYPE *PFN_CommandLineToArgvW)(LPCWSTR, int *);
extern PFN_CommandLineToArgvW __identifier("_imp__CommandLineToArgvW@8");
LPWSTR * STDAPICALLTYPE CommandLineToArgvW(LPCWSTR lpCmdLine, int * pNumArgs) {
 return __identifier("_imp__CommandLineToArgvW@8")(lpCmdLine, pNumArgs);
}

// _ShellExecuteW@24
typedef HINSTANCE (STDAPICALLTYPE *PFN_ShellExecuteW)(HWND, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, INT);
extern PFN_ShellExecuteW __identifier("_imp__ShellExecuteW@24");
HINSTANCE STDAPICALLTYPE ShellExecuteW(HWND hwnd, LPCWSTR lpOperation, LPCWSTR lpFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd) {
 return __identifier("_imp__ShellExecuteW@24")(hwnd, lpOperation, lpFile, lpParameters, lpDirectory, nShowCmd);
}
}
