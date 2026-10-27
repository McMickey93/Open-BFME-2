// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// ws2_32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK WinSock2.h, included with
// WINSOCK_API_LINKAGE empty (the header's own guard) so these definitions are
// not dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define WINSOCK_API_LINKAGE
#include <winsock2.h>
extern "C" {
// _listen@8
typedef int (WSAAPI *PFN_listen)(SOCKET, int);
extern PFN_listen __identifier("_imp__listen@8");
int WSAAPI listen(SOCKET s, int backlog) {
 return __identifier("_imp__listen@8")(s, backlog);
}

// _accept@12
typedef SOCKET (WSAAPI *PFN_accept)(SOCKET, struct sockaddr FAR *, int FAR *);
extern PFN_accept __identifier("_imp__accept@12");
SOCKET WSAAPI accept(SOCKET s, struct sockaddr FAR * addr, int FAR * addrlen) {
 return __identifier("_imp__accept@12")(s, addr, addrlen);
}

// _getpeername@12
typedef int (WSAAPI *PFN_getpeername)(SOCKET, struct sockaddr FAR *, int FAR *);
extern PFN_getpeername __identifier("_imp__getpeername@12");
int WSAAPI getpeername(SOCKET s, struct sockaddr FAR * name, int FAR * namelen) {
 return __identifier("_imp__getpeername@12")(s, name, namelen);
}

// _WSAIoctl@36
typedef int (WSAAPI *PFN_WSAIoctl)(SOCKET, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern PFN_WSAIoctl __identifier("_imp__WSAIoctl@36");
int WSAAPI WSAIoctl(SOCKET s, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
 return __identifier("_imp__WSAIoctl@36")(s, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped, lpCompletionRoutine);
}
}
