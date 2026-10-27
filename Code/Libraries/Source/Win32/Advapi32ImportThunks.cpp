// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// advapi32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK headers (WinReg.h, WinBase.h), included
// with _ADVAPI32_ defined (the headers' own switch) so WINADVAPI is empty and
// these definitions are not dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define _ADVAPI32_
#include <windows.h>
extern "C" {
// _AdjustTokenPrivileges@24
typedef BOOL (WINAPI *PFN_AdjustTokenPrivileges)(HANDLE, BOOL, PTOKEN_PRIVILEGES, DWORD, PTOKEN_PRIVILEGES, PDWORD);
extern PFN_AdjustTokenPrivileges __identifier("_imp__AdjustTokenPrivileges@24");
BOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle, BOOL DisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORD BufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength) {
 return __identifier("_imp__AdjustTokenPrivileges@24")(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength);
}

// _LookupPrivilegeValueA@12
typedef BOOL (WINAPI *PFN_LookupPrivilegeValueA)(LPCSTR, LPCSTR, PLUID);
extern PFN_LookupPrivilegeValueA __identifier("_imp__LookupPrivilegeValueA@12");
BOOL WINAPI LookupPrivilegeValueA(LPCSTR lpSystemName, LPCSTR lpName, PLUID lpLuid) {
 return __identifier("_imp__LookupPrivilegeValueA@12")(lpSystemName, lpName, lpLuid);
}

// _OpenProcessToken@12
typedef BOOL (WINAPI *PFN_OpenProcessToken)(HANDLE, DWORD, PHANDLE);
extern PFN_OpenProcessToken __identifier("_imp__OpenProcessToken@12");
BOOL WINAPI OpenProcessToken(HANDLE ProcessHandle, DWORD DesiredAccess, PHANDLE TokenHandle) {
 return __identifier("_imp__OpenProcessToken@12")(ProcessHandle, DesiredAccess, TokenHandle);
}

// _OpenThreadToken@16
typedef BOOL (WINAPI *PFN_OpenThreadToken)(HANDLE, DWORD, BOOL, PHANDLE);
extern PFN_OpenThreadToken __identifier("_imp__OpenThreadToken@16");
BOOL WINAPI OpenThreadToken(HANDLE ThreadHandle, DWORD DesiredAccess, BOOL OpenAsSelf, PHANDLE TokenHandle) {
 return __identifier("_imp__OpenThreadToken@16")(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle);
}

// _GetUserNameA@8
typedef BOOL (WINAPI *PFN_GetUserNameA)(LPSTR, LPDWORD);
extern PFN_GetUserNameA __identifier("_imp__GetUserNameA@8");
BOOL WINAPI GetUserNameA(LPSTR lpBuffer, LPDWORD nSize) {
 return __identifier("_imp__GetUserNameA@8")(lpBuffer, nSize);
}

// _RegCloseKey@4
typedef LONG (APIENTRY *PFN_RegCloseKey)(HKEY);
extern PFN_RegCloseKey __identifier("_imp__RegCloseKey@4");
LONG APIENTRY RegCloseKey(HKEY hKey) {
 return __identifier("_imp__RegCloseKey@4")(hKey);
}

// _RegQueryValueExW@24
typedef LONG (APIENTRY *PFN_RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
extern PFN_RegQueryValueExW __identifier("_imp__RegQueryValueExW@24");
LONG APIENTRY RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
 return __identifier("_imp__RegQueryValueExW@24")(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}

// _RegOpenKeyExW@20
typedef LONG (APIENTRY *PFN_RegOpenKeyExW)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
extern PFN_RegOpenKeyExW __identifier("_imp__RegOpenKeyExW@20");
LONG APIENTRY RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
 return __identifier("_imp__RegOpenKeyExW@20")(hKey, lpSubKey, ulOptions, samDesired, phkResult);
}

// _RegQueryValueExA@24
typedef LONG (APIENTRY *PFN_RegQueryValueExA)(HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
extern PFN_RegQueryValueExA __identifier("_imp__RegQueryValueExA@24");
LONG APIENTRY RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
 return __identifier("_imp__RegQueryValueExA@24")(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}

// _RegOpenKeyExA@20
typedef LONG (APIENTRY *PFN_RegOpenKeyExA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY);
extern PFN_RegOpenKeyExA __identifier("_imp__RegOpenKeyExA@20");
LONG APIENTRY RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
 return __identifier("_imp__RegOpenKeyExA@20")(hKey, lpSubKey, ulOptions, samDesired, phkResult);
}

// _RegSetValueExA@24
typedef LONG (APIENTRY *PFN_RegSetValueExA)(HKEY, LPCSTR, DWORD, DWORD, CONST BYTE *, DWORD);
extern PFN_RegSetValueExA __identifier("_imp__RegSetValueExA@24");
LONG APIENTRY RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE * lpData, DWORD cbData) {
 return __identifier("_imp__RegSetValueExA@24")(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}

// _RegCreateKeyExA@36
typedef LONG (APIENTRY *PFN_RegCreateKeyExA)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD);
extern PFN_RegCreateKeyExA __identifier("_imp__RegCreateKeyExA@36");
LONG APIENTRY RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition) {
 return __identifier("_imp__RegCreateKeyExA@36")(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition);
}

// _RegDeleteValueA@8
typedef LONG (APIENTRY *PFN_RegDeleteValueA)(HKEY, LPCSTR);
extern PFN_RegDeleteValueA __identifier("_imp__RegDeleteValueA@8");
LONG APIENTRY RegDeleteValueA(HKEY hKey, LPCSTR lpValueName) {
 return __identifier("_imp__RegDeleteValueA@8")(hKey, lpValueName);
}

// _RegSetValueExW@24
typedef LONG (APIENTRY *PFN_RegSetValueExW)(HKEY, LPCWSTR, DWORD, DWORD, CONST BYTE *, DWORD);
extern PFN_RegSetValueExW __identifier("_imp__RegSetValueExW@24");
LONG APIENTRY RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE * lpData, DWORD cbData) {
 return __identifier("_imp__RegSetValueExW@24")(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}

// _RegEnumValueA@32
typedef LONG (APIENTRY *PFN_RegEnumValueA)(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
extern PFN_RegEnumValueA __identifier("_imp__RegEnumValueA@32");
LONG APIENTRY RegEnumValueA(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcbValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
 return __identifier("_imp__RegEnumValueA@32")(hKey, dwIndex, lpValueName, lpcbValueName, lpReserved, lpType, lpData, lpcbData);
}

// _RegQueryInfoKeyA@48
typedef LONG (APIENTRY *PFN_RegQueryInfoKeyA)(HKEY, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, PFILETIME);
extern PFN_RegQueryInfoKeyA __identifier("_imp__RegQueryInfoKeyA@48");
LONG APIENTRY RegQueryInfoKeyA(HKEY hKey, LPSTR lpClass, LPDWORD lpcbClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime) {
 return __identifier("_imp__RegQueryInfoKeyA@48")(hKey, lpClass, lpcbClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime);
}

// _RegEnumKeyExA@32
typedef LONG (APIENTRY *PFN_RegEnumKeyExA)(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPSTR, LPDWORD, PFILETIME);
extern PFN_RegEnumKeyExA __identifier("_imp__RegEnumKeyExA@32");
LONG APIENTRY RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcbName, LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcbClass, PFILETIME lpftLastWriteTime) {
 return __identifier("_imp__RegEnumKeyExA@32")(hKey, dwIndex, lpName, lpcbName, lpReserved, lpClass, lpcbClass, lpftLastWriteTime);
}

// _RegDeleteKeyA@8
typedef LONG (APIENTRY *PFN_RegDeleteKeyA)(HKEY, LPCSTR);
extern PFN_RegDeleteKeyA __identifier("_imp__RegDeleteKeyA@8");
LONG APIENTRY RegDeleteKeyA(HKEY hKey, LPCSTR lpSubKey) {
 return __identifier("_imp__RegDeleteKeyA@8")(hKey, lpSubKey);
}
}
