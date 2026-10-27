// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport

#include <memory>

// Retail's record destructor is the rowed ??1Rva005AFE3F@@UAE@XZ (0x005AFE3F,
// Rva005AFE3FDtor.cpp); dllimport+forceinline calls it by that name and emits
// no ??1Rva005AFEDBRecord copy (FamilyDeletingDtors2.cpp precedent).
struct Rva005AFE3F { virtual ~Rva005AFE3F(); };
struct Rva005AFEDBRecord { __declspec(dllimport) __forceinline ~Rva005AFEDBRecord() { ((Rva005AFE3F *)this)->Rva005AFE3F::~Rva005AFE3F(); } char bytes[1]; };
// Scalar destruction also emits the compiler-generated deleting destructor.
template void _STL::_Destroy<Rva005AFEDBRecord>(Rva005AFEDBRecord *);
