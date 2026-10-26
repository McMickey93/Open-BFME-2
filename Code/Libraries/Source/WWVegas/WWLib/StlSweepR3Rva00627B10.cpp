// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O2 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#include <algorithm>
#include <memory>



struct Rva00627B10Record { Rva00627B10Record(); Rva00627B10Record(const Rva00627B10Record&); ~Rva00627B10Record(); Rva00627B10Record&operator=(const Rva00627B10Record&); char bytes[1]; bool operator<(const Rva00627B10Record&)const; };
template void _STL::make_heap(Rva00627B10Record*,Rva00627B10Record*,_STL::less<Rva00627B10Record>);
