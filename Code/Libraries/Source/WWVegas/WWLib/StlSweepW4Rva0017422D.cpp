// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// Element: the 32-byte BfmeAssignRecord32 whose copy (0x00173731), dtor (0x0017330A) and fill (0x001737A3) retail calls.
// cl: /O1 /G7 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// vector::_M_insert_overflow inlines max(size(), n). A file-static unsigned
// overload takes the call instead, so this TU emits no external max COMDAT.
namespace _STL {
static inline const unsigned int &max(const unsigned int &a, const unsigned int &b)
{
    return a < b ? b : a;
}
}
#include <vector>

struct BfmeAssignRecord32 { BfmeAssignRecord32(); BfmeAssignRecord32(const BfmeAssignRecord32 &); ~BfmeAssignRecord32(); BfmeAssignRecord32 &operator=(const BfmeAssignRecord32 &); char bytes[32]; };
typedef BfmeAssignRecord32 Record;

// The record's allocator and destroy helpers have their own owners; declaring
// the specializations keeps this unit from emitting a second, /Ob0 copy.
namespace _STL {
template <> Record *_STLP_alloc_proxy<Record *, Record, allocator<Record> >::allocate(size_t);
template <> void _STLP_alloc_proxy<Record *, Record, allocator<Record> >::deallocate(Record *, size_t);
template <> void __destroy_aux(Record *, Record *, const __false_type &);
template <> void __destroy<Record *, Record>(Record *, Record *, Record *);
}

// Instantiate the recovered operation and its required template dependencies.
template void _STL::vector<BfmeAssignRecord32, _STL::allocator<BfmeAssignRecord32> >::_M_fill_insert(BfmeAssignRecord32 *, unsigned int, BfmeAssignRecord32 const &);

// Native 0x001746BE: STLport4.5.3 vector count-insertion forwarding to its owned provider.
template void _STL::vector<BfmeAssignRecord32, _STL::allocator<BfmeAssignRecord32> >::insert(BfmeAssignRecord32 *, unsigned int, BfmeAssignRecord32 const &);
