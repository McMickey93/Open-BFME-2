// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element identity and unconstrained fields remain address-derived structural inference.
// cl: /O1 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport

#include <map>

struct Rva002F0BB5Element { char bytes[1]; bool operator<(const Rva002F0BB5Element&)const; bool operator==(const Rva002F0BB5Element&)const; };
// Instantiate the rowed destructor and its required template dependencies.
template _STL::_Rb_tree<int, _STL::pair<const int, Rva002F0BB5Element>, _STL::_Select1st<_STL::pair<const int, Rva002F0BB5Element> >, _STL::less<int>, _STL::allocator<_STL::pair<const int, Rva002F0BB5Element> > >::~_Rb_tree();
