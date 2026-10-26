// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O1 /G7 /EHsc- /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#include <vector>

struct Rva00214B22Record { ~Rva00214B22Record(); char bytes[1]; };

// Retail's destructor calls the rowed 25-byte range destroy at 0x00214B09,
// ??$_Destroy@PAVRva00214ADC@@@_STL@@YAXPAVRva00214ADC@@0@Z
// (stlport_vector_rva00214adc_destroy.cpp), over 0x14-byte elements. Spell
// STLport's ~vector body against that owner instead of instantiating the whole
// vector<Rva00214B22Record> and a competing _Destroy<Rva00214B22Record *> copy.
class Rva00214ADC;
namespace _STL {
template <> void _Destroy<Rva00214ADC *>(Rva00214ADC *, Rva00214ADC *);
template <> vector<Rva00214B22Record>::~vector()
{ _Destroy(reinterpret_cast<Rva00214ADC *>(this->_M_start), reinterpret_cast<Rva00214ADC *>(this->_M_finish)); }
}

template _STL::vector<Rva00214B22Record>::~vector();
