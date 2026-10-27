// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// tapi32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK Tapi.h with TAPI_CURRENT_VERSION
// 0x00010004 (the header's own version switch): the TAPI 1.4 interface whose
// unsuffixed lineGetDevCaps/lineGetID/lineMakeCall/lineOpen exports the
// retail IAT names. Its declarations carry no dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define TAPI_CURRENT_VERSION 0x00010004
#include <windows.h>
#include <tapi.h>
extern "C" {
// _lineInitialize@20
typedef LONG (WINAPI *PFN_lineInitialize)(LPHLINEAPP, HINSTANCE, LINECALLBACK, LPCSTR, LPDWORD);
extern PFN_lineInitialize __identifier("_imp__lineInitialize@20");
LONG WINAPI lineInitialize(LPHLINEAPP lphLineApp, HINSTANCE hInstance, LINECALLBACK lpfnCallback, LPCSTR lpszAppName, LPDWORD lpdwNumDevs) {
 return __identifier("_imp__lineInitialize@20")(lphLineApp, hInstance, lpfnCallback, lpszAppName, lpdwNumDevs);
}

// _lineAnswer@12
typedef LONG (WINAPI *PFN_lineAnswer)(HCALL, LPCSTR, DWORD);
extern PFN_lineAnswer __identifier("_imp__lineAnswer@12");
LONG WINAPI lineAnswer(HCALL hCall, LPCSTR lpsUserUserInfo, DWORD dwSize) {
 return __identifier("_imp__lineAnswer@12")(hCall, lpsUserUserInfo, dwSize);
}

// _lineClose@4
typedef LONG (WINAPI *PFN_lineClose)(HLINE);
extern PFN_lineClose __identifier("_imp__lineClose@4");
LONG WINAPI lineClose(HLINE hLine) {
 return __identifier("_imp__lineClose@4")(hLine);
}

// _lineOpen@36
typedef LONG (WINAPI *PFN_lineOpen)(HLINEAPP, DWORD, LPHLINE, DWORD, DWORD, DWORD_PTR, DWORD, DWORD, LPLINECALLPARAMS const);
extern PFN_lineOpen __identifier("_imp__lineOpen@36");
LONG WINAPI lineOpen(HLINEAPP hLineApp, DWORD dwDeviceID, LPHLINE lphLine, DWORD dwAPIVersion, DWORD dwExtVersion, DWORD_PTR dwCallbackInstance, DWORD dwPrivileges, DWORD dwMediaModes, LPLINECALLPARAMS const lpCallParams) {
 return __identifier("_imp__lineOpen@36")(hLineApp, dwDeviceID, lphLine, dwAPIVersion, dwExtVersion, dwCallbackInstance, dwPrivileges, dwMediaModes, lpCallParams);
}

// _lineNegotiateAPIVersion@24
typedef LONG (WINAPI *PFN_lineNegotiateAPIVersion)(HLINEAPP, DWORD, DWORD, DWORD, LPDWORD, LPLINEEXTENSIONID);
extern PFN_lineNegotiateAPIVersion __identifier("_imp__lineNegotiateAPIVersion@24");
LONG WINAPI lineNegotiateAPIVersion(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPILowVersion, DWORD dwAPIHighVersion, LPDWORD lpdwAPIVersion, LPLINEEXTENSIONID lpExtensionID) {
 return __identifier("_imp__lineNegotiateAPIVersion@24")(hLineApp, dwDeviceID, dwAPILowVersion, dwAPIHighVersion, lpdwAPIVersion, lpExtensionID);
}

// _lineGetID@24
typedef LONG (WINAPI *PFN_lineGetID)(HLINE, DWORD, HCALL, DWORD, LPVARSTRING, LPCSTR);
extern PFN_lineGetID __identifier("_imp__lineGetID@24");
LONG WINAPI lineGetID(HLINE hLine, DWORD dwAddressID, HCALL hCall, DWORD dwSelect, LPVARSTRING lpDeviceID, LPCSTR lpszDeviceClass) {
 return __identifier("_imp__lineGetID@24")(hLine, dwAddressID, hCall, dwSelect, lpDeviceID, lpszDeviceClass);
}

// _lineMakeCall@20
typedef LONG (WINAPI *PFN_lineMakeCall)(HLINE, LPHCALL, LPCSTR, DWORD, LPLINECALLPARAMS const);
extern PFN_lineMakeCall __identifier("_imp__lineMakeCall@20");
LONG WINAPI lineMakeCall(HLINE hLine, LPHCALL lphCall, LPCSTR lpszDestAddress, DWORD dwCountryCode, LPLINECALLPARAMS const lpCallParams) {
 return __identifier("_imp__lineMakeCall@20")(hLine, lphCall, lpszDestAddress, dwCountryCode, lpCallParams);
}

// _lineShutdown@4
typedef LONG (WINAPI *PFN_lineShutdown)(HLINEAPP);
extern PFN_lineShutdown __identifier("_imp__lineShutdown@4");
LONG WINAPI lineShutdown(HLINEAPP hLineApp) {
 return __identifier("_imp__lineShutdown@4")(hLineApp);
}

// _lineGetDevCaps@20
typedef LONG (WINAPI *PFN_lineGetDevCaps)(HLINEAPP, DWORD, DWORD, DWORD, LPLINEDEVCAPS);
extern PFN_lineGetDevCaps __identifier("_imp__lineGetDevCaps@20");
LONG WINAPI lineGetDevCaps(HLINEAPP hLineApp, DWORD dwDeviceID, DWORD dwAPIVersion, DWORD dwExtVersion, LPLINEDEVCAPS lpLineDevCaps) {
 return __identifier("_imp__lineGetDevCaps@20")(hLineApp, dwDeviceID, dwAPIVersion, dwExtVersion, lpLineDevCaps);
}
}
