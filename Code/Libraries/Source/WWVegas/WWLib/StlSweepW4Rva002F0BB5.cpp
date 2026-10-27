// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element identity and unconstrained fields remain address-derived structural inference.
// cl: /O1 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#include <map>

struct Rva002F0BB5Element { char bytes[1]; bool operator<(const Rva002F0BB5Element&)const; bool operator==(const Rva002F0BB5Element&)const; };

typedef _STL::pair<const int, Rva002F0BB5Element> _Rva002F0BB5Pair;
typedef _STL::allocator<_Rva002F0BB5Pair> _Rva002F0BB5Alloc;
typedef _STL::_Rb_tree<int, _Rva002F0BB5Pair, _STL::_Select1st<_Rva002F0BB5Pair>, _STL::less<int>, _Rva002F0BB5Alloc > _Rva002F0BB5Tree;
typedef _STL::_Rb_tree_base<_Rva002F0BB5Pair, _Rva002F0BB5Alloc > _Rva002F0BB5Base;

// Retail's clear() 0x002EEA1D and ~_Rb_tree_base() 0x002EEA46 are defined in
// Rva002EEA1DReset.cpp; declare them so this unit emits no copies of its own.
namespace _STL {
template <> void _Rva002F0BB5Tree::clear();
template <> _Rva002F0BB5Base::~_Rb_tree_base() throw();
}

template _Rva002F0BB5Tree::~_Rb_tree();
