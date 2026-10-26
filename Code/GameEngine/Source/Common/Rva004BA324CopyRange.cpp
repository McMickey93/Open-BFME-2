// cl: /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?Rva004BA324CopyRange@@YAPAVRva004BA1C8@@PAV1@00H@Z, retail 0x004BA324 29B: tag temp plus null distance forwarder.
// Evidence: same 29B shape as rowed ?Rva002915EBCopyRange at 0x002915EB; callee 0x004BA2E9 is 50B assign loop via rowed assign; caller 0x004BA399 is 51B erase-range like rowed EraseRange at 0x002983DA.
#include <stl/_iterator_base.h>

class Rva004BA1C8;

// The real STLport tag and the existing out-of-line __copy provider are shared
// with TransitionDamageFX.cpp. This forwarder needs no private record layout
// or second template body.
namespace _STL {
template <class _RandomAccessIter, class _OutputIter, class _Distance>
__declspec(noinline) inline _OutputIter
__copy(_RandomAccessIter __first, _RandomAccessIter __last,
       _OutputIter __result, const random_access_iterator_tag &, _Distance *);
}

Rva004BA1C8 *Rva004BA324CopyRange(Rva004BA1C8 *first, Rva004BA1C8 *last, Rva004BA1C8 *result, int dummy)
{
	_STL::random_access_iterator_tag tag;
	(void)dummy;
	return _STL::__copy(first, last, result, tag, (int *)0);
}
