// cl: /O2 /G7 /Oy /Ob1 /MD /I"reference/open-bfme-1/inputs/toolchains/vs2003/Program Files/Microsoft Visual Studio .NET 2003/Vc7/PlatformSDK/Include"
// oleaut32.dll import thunks: typed C++ forwarding through the genuine PE
// import-pointer symbols, as Kernel32ImportThunks.cpp and
// User32ImportThunks.cpp do. VS2003 __identifier names the actual decorated
// __imp__ symbol; no alias, address pin, inline assembly, emitted bytes or
// replacement datum is used.
// Signatures: the VS2003 Platform SDK oleauto.h, included with _OLEAUT32_
// defined (the header's own switch) so WINOLEAUTAPI is STDAPI and these
// definitions are not dllimport. oleauto.h leaves the Sys* string parameters
// unnamed; the documented names are used.
// Each retail six-byte thunk's IAT slot names the export (row notes).
#define _OLEAUT32_
#include <windows.h>
extern "C" {
// _SysFreeString@4
typedef void (STDAPICALLTYPE *PFN_SysFreeString)(BSTR);
extern PFN_SysFreeString __identifier("_imp__SysFreeString@4");
void STDAPICALLTYPE SysFreeString(BSTR bstrString) {
 __identifier("_imp__SysFreeString@4")(bstrString);
}

// _SysStringLen@4
typedef UINT (STDAPICALLTYPE *PFN_SysStringLen)(BSTR);
extern PFN_SysStringLen __identifier("_imp__SysStringLen@4");
UINT STDAPICALLTYPE SysStringLen(BSTR pbstr) {
 return __identifier("_imp__SysStringLen@4")(pbstr);
}

// _SysAllocString@4
typedef BSTR (STDAPICALLTYPE *PFN_SysAllocString)(const OLECHAR *);
extern PFN_SysAllocString __identifier("_imp__SysAllocString@4");
BSTR STDAPICALLTYPE SysAllocString(const OLECHAR * psz) {
 return __identifier("_imp__SysAllocString@4")(psz);
}

// _VariantClear@4
typedef HRESULT (STDAPICALLTYPE *PFN_VariantClear)(VARIANTARG *);
extern PFN_VariantClear __identifier("_imp__VariantClear@4");
HRESULT STDAPICALLTYPE VariantClear(VARIANTARG * pvarg) {
 return __identifier("_imp__VariantClear@4")(pvarg);
}

// _GetErrorInfo@8
typedef HRESULT (STDAPICALLTYPE *PFN_GetErrorInfo)(ULONG, IErrorInfo **);
extern PFN_GetErrorInfo __identifier("_imp__GetErrorInfo@8");
HRESULT STDAPICALLTYPE GetErrorInfo(ULONG dwReserved, IErrorInfo ** pperrinfo) {
 return __identifier("_imp__GetErrorInfo@8")(dwReserved, pperrinfo);
}

// _VariantChangeType@16
typedef HRESULT (STDAPICALLTYPE *PFN_VariantChangeType)(VARIANTARG *, VARIANTARG *, USHORT, VARTYPE);
extern PFN_VariantChangeType __identifier("_imp__VariantChangeType@16");
HRESULT STDAPICALLTYPE VariantChangeType(VARIANTARG * pvargDest, VARIANTARG * pvarSrc, USHORT wFlags, VARTYPE vt) {
 return __identifier("_imp__VariantChangeType@16")(pvargDest, pvarSrc, wFlags, vt);
}

// _VariantInit@4
typedef void (STDAPICALLTYPE *PFN_VariantInit)(VARIANTARG *);
extern PFN_VariantInit __identifier("_imp__VariantInit@4");
void STDAPICALLTYPE VariantInit(VARIANTARG * pvarg) {
 __identifier("_imp__VariantInit@4")(pvarg);
}

// _SetErrorInfo@8
typedef HRESULT (STDAPICALLTYPE *PFN_SetErrorInfo)(ULONG, IErrorInfo *);
extern PFN_SetErrorInfo __identifier("_imp__SetErrorInfo@8");
HRESULT STDAPICALLTYPE SetErrorInfo(ULONG dwReserved, IErrorInfo * perrinfo) {
 return __identifier("_imp__SetErrorInfo@8")(dwReserved, perrinfo);
}

// _CreateErrorInfo@4
typedef HRESULT (STDAPICALLTYPE *PFN_CreateErrorInfo)(ICreateErrorInfo **);
extern PFN_CreateErrorInfo __identifier("_imp__CreateErrorInfo@4");
HRESULT STDAPICALLTYPE CreateErrorInfo(ICreateErrorInfo ** pperrinfo) {
 return __identifier("_imp__CreateErrorInfo@4")(pperrinfo);
}
}
