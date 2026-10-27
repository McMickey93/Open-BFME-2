// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport

#include <memory>

// Retail's record destructor is the rowed ??1Rva005838B5@@UAE@XZ (0x005838F8,
// Rva00587F69Dtor.cpp); dllimport+forceinline calls it by that name and emits
// no ??1Rva005838DCRecord copy (FamilyDeletingDtors2.cpp precedent).
struct Rva005838B5 { virtual ~Rva005838B5(); };
struct Rva005838DCRecord { __declspec(dllimport) __forceinline ~Rva005838DCRecord() { ((Rva005838B5 *)this)->Rva005838B5::~Rva005838B5(); } char bytes[1]; };
// Scalar destruction also emits the compiler-generated deleting destructor.
template void _STL::_Destroy<Rva005838DCRecord>(Rva005838DCRecord *);
