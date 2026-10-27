// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// The element is the 40-byte camera-track key Rva0054000B: the loop's only call
// is its assignment, rowed at 0x00540053 (StlSweepW4Rva00540053.cpp).
#include <vector>

class Rva0054000B
{
public:
	Rva0054000B &operator=(const Rva0054000B &other);

private:
	char m_pad[40];
};

template Rva0054000B *_STL::__copy<Rva0054000B *, Rva0054000B *, int>(Rva0054000B *, Rva0054000B *, Rva0054000B *, const _STL::random_access_iterator_tag &, int *);
