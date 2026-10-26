// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element identity and unconstrained fields remain address-derived structural inference.
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#include <vector>

struct Rva005FE24CElement {Rva005FE24CElement();Rva005FE24CElement(const Rva005FE24CElement&);Rva005FE24CElement&operator=(const Rva005FE24CElement&);~Rva005FE24CElement(){}char bytes[12]; bool operator==(const Rva005FE24CElement&)const;};

// Retail's loop calls the rowed placement-copy owner
// Rva005FE0F5Construct 0x005FE0F5 (stlport_construct_game_structs2.cpp), declared over its opaque BfmeStringRecord005F93E3.
struct BfmeStringRecord005F93E3;
void Rva005FE0F5Construct(BfmeStringRecord005F93E3 *, const BfmeStringRecord005F93E3 &);
namespace _STL {
template <> __declspec(dllimport) __declspec(nothrow) __forceinline void _Construct<Rva005FE24CElement, Rva005FE24CElement>(Rva005FE24CElement *__p, const Rva005FE24CElement &__val)
{ Rva005FE0F5Construct((BfmeStringRecord005F93E3 *)__p, *(const BfmeStringRecord005F93E3 *)&__val); }
}

// Instantiate the recovered operation and its required template dependencies.
template Rva005FE24CElement * _STL::__uninitialized_fill_n<Rva005FE24CElement *, unsigned int, Rva005FE24CElement>(Rva005FE24CElement *, unsigned int, Rva005FE24CElement const &, _STL::__false_type const &);
