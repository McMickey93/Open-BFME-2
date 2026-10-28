// Reference: pristine STLport4.5.3. vector<BfmeVectorRecord0002154F3>::reserve.
// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// The emitted unsigned max copy must match retail RVA 0x00013740.
// Define it for speed, then restore this unit's flags for its own bodies.
#include <stl/_algobase.h>
#pragma optimize("s", off)
#pragma optimize("t", on)
namespace _STL {
static inline const unsigned int &max(const unsigned int &a, const unsigned int &b)
{
    return a < b ? b : a;
}
}
#pragma optimize("", on)

#include <vector>



// Retail's reserve (0x0021582C) sits among the AsciiString plus vector<AsciiString>
// record's vector bodies and reaches its rowed providers: allocate-and-copy 0x00215614
// -> uninitialized_copy 0x002155C9 -> placement copy 0x0021559C; clear 0x0021580E
// -> destroy range 0x00215783. Both loops step 0x10.
struct BfmeVectorRecord0002154F3 { BfmeVectorRecord0002154F3(); BfmeVectorRecord0002154F3(const BfmeVectorRecord0002154F3&); ~BfmeVectorRecord0002154F3(); BfmeVectorRecord0002154F3&operator=(const BfmeVectorRecord0002154F3&); private: char bytes[16]; };
namespace _STL {template<> void _Construct<BfmeVectorRecord0002154F3,BfmeVectorRecord0002154F3>(BfmeVectorRecord0002154F3*,const BfmeVectorRecord0002154F3&);}
namespace _STL {template<> void _Destroy<BfmeVectorRecord0002154F3*>(BfmeVectorRecord0002154F3*,BfmeVectorRecord0002154F3*);}
template void _STL::vector<BfmeVectorRecord0002154F3>::reserve(unsigned int);
