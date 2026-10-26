// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element identity and unconstrained fields remain address-derived structural inference.
// cl: /O1 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#include <map>

struct Rva002F0B8AElement { char bytes[1]; bool operator<(const Rva002F0B8AElement&)const; bool operator==(const Rva002F0B8AElement&)const; };

typedef _STL::pair<const int, Rva002F0B8AElement> _Rva002F0B8APair;
typedef _STL::allocator<_Rva002F0B8APair> _Rva002F0B8AAlloc;
typedef _STL::_Rb_tree<int, _Rva002F0B8APair, _STL::_Select1st<_Rva002F0B8APair>, _STL::less<int>, _Rva002F0B8AAlloc > _Rva002F0B8ATree;
typedef _STL::_Rb_tree_base<_Rva002F0B8APair, _Rva002F0B8AAlloc > _Rva002F0B8ABase;

namespace _STL {
template <> void _Rva002F0B8ATree::clear();
template <> _Rva002F0B8ABase::~_Rb_tree_base() throw();
}

template _Rva002F0B8ATree::~_Rb_tree();
