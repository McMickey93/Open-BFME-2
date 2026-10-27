// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// avifil32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK Vfw.h, whose STDAPI declarations carry
// no dllimport.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#include <windows.h>
#include <vfw.h>
extern "C" {
// _AVIFileReadData@16
typedef HRESULT (STDAPICALLTYPE *PFN_AVIFileReadData)(PAVIFILE, DWORD, LPVOID, LONG FAR *);
extern PFN_AVIFileReadData __identifier("_imp__AVIFileReadData@16");
HRESULT STDAPICALLTYPE AVIFileReadData(PAVIFILE pfile, DWORD ckid, LPVOID lpData, LONG FAR * lpcbData) {
 return __identifier("_imp__AVIFileReadData@16")(pfile, ckid, lpData, lpcbData);
}

// _AVIMakeCompressedStream@16
typedef HRESULT (STDAPICALLTYPE *PFN_AVIMakeCompressedStream)(PAVISTREAM FAR *, PAVISTREAM, AVICOMPRESSOPTIONS FAR *, CLSID FAR *);
extern PFN_AVIMakeCompressedStream __identifier("_imp__AVIMakeCompressedStream@16");
HRESULT STDAPICALLTYPE AVIMakeCompressedStream(PAVISTREAM FAR * ppsCompressed, PAVISTREAM ppsSource, AVICOMPRESSOPTIONS FAR * lpOptions, CLSID FAR * pclsidHandler) {
 return __identifier("_imp__AVIMakeCompressedStream@16")(ppsCompressed, ppsSource, lpOptions, pclsidHandler);
}

// _AVIFileCreateStreamA@12
typedef HRESULT (STDAPICALLTYPE *PFN_AVIFileCreateStreamA)(PAVIFILE, PAVISTREAM FAR *, AVISTREAMINFOA FAR *);
extern PFN_AVIFileCreateStreamA __identifier("_imp__AVIFileCreateStreamA@12");
HRESULT STDAPICALLTYPE AVIFileCreateStreamA(PAVIFILE pfile, PAVISTREAM FAR * ppavi, AVISTREAMINFOA FAR * psi) {
 return __identifier("_imp__AVIFileCreateStreamA@12")(pfile, ppavi, psi);
}

// _AVIFileInit@0
typedef void (STDAPICALLTYPE *PFN_AVIFileInit)(void);
extern PFN_AVIFileInit __identifier("_imp__AVIFileInit@0");
void STDAPICALLTYPE AVIFileInit(void) {
 __identifier("_imp__AVIFileInit@0")();
}
}
