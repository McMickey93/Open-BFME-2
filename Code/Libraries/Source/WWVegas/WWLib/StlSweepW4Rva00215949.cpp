// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// cl: /O1 /G7 /Ob0 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /Ireference/shims/bfme2_ascii
// stlport
// vector<BfmeVectorRecord0002154F3>::_M_fill_insert at 0x00215949. The resize
// at 0x00215A8D calls it on the AsciiString plus vector<AsciiString> record;
// its copy 0x002154F3, destructor 0x002154BE, helpers and _M_insert_overflow
// 0x00215895 are the record's rowed providers.
// vector::_M_insert_overflow inlines max(size(), n). A file-static unsigned
// overload takes the call instead, so this TU emits no external max COMDAT.
namespace _STL {
static inline const unsigned int &max(const unsigned int &a, const unsigned int &b)
{
    return a < b ? b : a;
}
}
#include "ascii_string.h"
#include <vector>

struct BfmeVectorRecord0002154F3 {
    AsciiString text;
    _STL::vector<AsciiString> names;
    BfmeVectorRecord0002154F3();
    BfmeVectorRecord0002154F3(const BfmeVectorRecord0002154F3 &);
    ~BfmeVectorRecord0002154F3();
    BfmeVectorRecord0002154F3 &operator=(const BfmeVectorRecord0002154F3 &);
};
typedef BfmeVectorRecord0002154F3 Record;
// The inline _M_insert_overflow copy (/Ob0) calls these out of line; bind them
// to the kept copies instead of emitting this unit's own.
namespace _STL {
template <> Record *_STLP_alloc_proxy<Record *, Record, allocator<Record> >::allocate(size_t);
template <> void _STLP_alloc_proxy<Record *, Record, allocator<Record> >::deallocate(Record *, size_t);
template <> void __destroy_aux(Record *, Record *, const __false_type &);
template <> void __destroy<Record *, Record>(Record *, Record *, Record *);
}

template void _STL::vector<BfmeVectorRecord0002154F3, _STL::allocator<BfmeVectorRecord0002154F3> >::_M_fill_insert(BfmeVectorRecord0002154F3 *, unsigned int, BfmeVectorRecord0002154F3 const &);
