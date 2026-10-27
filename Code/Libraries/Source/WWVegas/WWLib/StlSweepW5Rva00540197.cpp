// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// The element is the 40-byte camera-track key Rva0054000B: this forwarder's only
// call goes to the rowed __copy_backward<Rva0054000B *> at 0x005400FF
// (stlport_asciistring_record_bodies.cpp). Its caller is
// vector<Rva0054000B>::insert 0x00540731.
#include <vector>

class Rva0054000B
{
public:
	Rva0054000B &operator=(const Rva0054000B &other);

private:
	char m_pad[40];
};

// Declared only: the rowed copy serves the call.
namespace _STL { template <> Rva0054000B *__copy_backward<Rva0054000B *, Rva0054000B *, int>(Rva0054000B *, Rva0054000B *, Rva0054000B *, const random_access_iterator_tag &, int *); }

template Rva0054000B *_STL::__copy_backward_ptrs<Rva0054000B *, Rva0054000B *>(Rva0054000B *, Rva0054000B *, Rva0054000B *, const _STL::__false_type &);
