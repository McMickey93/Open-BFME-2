// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// ole32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK objbase.h and ole2.h, included with
// _OLE32_ defined (the headers' own switch) so WINOLEAPI is STDAPI and these
// definitions are not dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define _OLE32_
#include <windows.h>
extern "C" {
// _OleRun@4
typedef HRESULT (STDAPICALLTYPE *PFN_OleRun)(LPUNKNOWN);
extern PFN_OleRun __identifier("_imp__OleRun@4");
HRESULT STDAPICALLTYPE OleRun(LPUNKNOWN pUnknown) {
 return __identifier("_imp__OleRun@4")(pUnknown);
}

// _CoCreateInstance@20
typedef HRESULT (STDAPICALLTYPE *PFN_CoCreateInstance)(REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID FAR *);
extern PFN_CoCreateInstance __identifier("_imp__CoCreateInstance@20");
HRESULT STDAPICALLTYPE CoCreateInstance(REFCLSID rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID FAR * ppv) {
 return __identifier("_imp__CoCreateInstance@20")(rclsid, pUnkOuter, dwClsContext, riid, ppv);
}

// _CoUninitialize@0
typedef void (STDAPICALLTYPE *PFN_CoUninitialize)(void);
extern PFN_CoUninitialize __identifier("_imp__CoUninitialize@0");
void STDAPICALLTYPE CoUninitialize(void) {
 __identifier("_imp__CoUninitialize@0")();
}

// _CoInitialize@4
typedef HRESULT (STDAPICALLTYPE *PFN_CoInitialize)(LPVOID);
extern PFN_CoInitialize __identifier("_imp__CoInitialize@4");
HRESULT STDAPICALLTYPE CoInitialize(LPVOID pvReserved) {
 return __identifier("_imp__CoInitialize@4")(pvReserved);
}

// _CoCreateGuid@4
typedef HRESULT (STDAPICALLTYPE *PFN_CoCreateGuid)(GUID FAR *);
extern PFN_CoCreateGuid __identifier("_imp__CoCreateGuid@4");
HRESULT STDAPICALLTYPE CoCreateGuid(GUID FAR * pguid) {
 return __identifier("_imp__CoCreateGuid@4")(pguid);
}

// _CoInitializeEx@8
typedef HRESULT (STDAPICALLTYPE *PFN_CoInitializeEx)(LPVOID, DWORD);
extern PFN_CoInitializeEx __identifier("_imp__CoInitializeEx@8");
HRESULT STDAPICALLTYPE CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit) {
 return __identifier("_imp__CoInitializeEx@8")(pvReserved, dwCoInit);
}
}
