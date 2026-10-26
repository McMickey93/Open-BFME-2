// Target boundary 0x003A46FA/191 is STLport vector::_M_insert_overflow
// false_type. The matched push_back at 0x003A47B9 calls it with vector ECX
// and five overflow arguments; retail advances 0xA0-byte elements and clears
// old storage through the separately matched _M_clear at 0x003A46DC.
//
// BfmeStringHeadRecord160 is only an emitter view: the 160-byte size and an
// AsciiString-shaped first member are target-supported, but the full
// application record identity/layout is not claimed. The target Construct
// wrapper at 0x3A454E forwards to the observed record-copy body at 0x3A451B.
// cl: /Ireference/shims/bfme2_ascii /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// Retail keeps one unsigned max, RVA 0x00013740 (the vendored STLport row). This unit's
// flags (/G7) compile a different copy, and retail kept another unit's. This unit-local
// overload keeps the inlined code and offers the link no second copy.
#include <stl/_algobase.h>
namespace _STL {
static inline const unsigned int &max(const unsigned int &a, const unsigned int &b)
{
    return a < b ? b : a;
}
}

#include <vector>

#include "ascii_string.h"


struct BfmeStringHeadRecord160 { AsciiString s; int a[39]; };

// The wrapper retail calls at 0x3A454E is the copy-construct of the 160-byte
// record rowed in StringContainerRecordCopyBFME2.cpp; reach it through that
// record's own specialization so the call binds the owner's body.
struct BfmeContainerRecord003A451B;
namespace _STL {
template <> void _Construct<BfmeContainerRecord003A451B, BfmeContainerRecord003A451B>(
	BfmeContainerRecord003A451B *, const BfmeContainerRecord003A451B &);
template <> inline void _Construct<BfmeStringHeadRecord160, BfmeStringHeadRecord160>(
	BfmeStringHeadRecord160 *p, const BfmeStringHeadRecord160 &v)
{
	_Construct((BfmeContainerRecord003A451B *)p, (const BfmeContainerRecord003A451B &)v);
}
}

template void _STL::vector<BfmeStringHeadRecord160>::_M_insert_overflow(
	BfmeStringHeadRecord160 *, const BfmeStringHeadRecord160 &,
	const _STL::__false_type &, unsigned int, bool);
