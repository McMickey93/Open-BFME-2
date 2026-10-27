// cl: /Ireference/shims/bfme2_ascii /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// Retail's 16-byte record owns an AsciiString and vector<AsciiString>;
// copy 0x002154F3 and destructor 0x002154BE establish that storage.
// The resize calls range erase 0x002157DB and fill insert 0x00215949.
// Use their rowed provider spellings rather than donor-only helper names.
#include "ascii_string.h"
#include <vector>

namespace _STL {
template <> vector<AsciiString, allocator<AsciiString> >::~vector();
template <> _Vector_base<AsciiString, allocator<AsciiString> >::~_Vector_base();
template <> void _STLP_alloc_proxy<AsciiString*, AsciiString, allocator<AsciiString> >::deallocate(AsciiString*, size_t);
template <> void allocator<AsciiString>::deallocate(AsciiString*, size_t) const;
}

struct BfmeItemERE
{
	AsciiString m_bfmeNameERE;
	_STL::vector<AsciiString> m_bfmeSubERE;
};

struct BfmeVectorRecord0002154F3;
namespace _STL {
template <> BfmeVectorRecord0002154F3 *vector<BfmeVectorRecord0002154F3, allocator<BfmeVectorRecord0002154F3> >::erase(BfmeVectorRecord0002154F3 *, BfmeVectorRecord0002154F3 *);
template <> void vector<BfmeVectorRecord0002154F3, allocator<BfmeVectorRecord0002154F3> >::_M_fill_insert(BfmeVectorRecord0002154F3 *, unsigned int, const BfmeVectorRecord0002154F3 &);
}

class BfmeVecERE
{
public:
	void bfmeResizeERE(unsigned int count, BfmeItemERE value);

	BfmeItemERE *m_bfmeFirstERE;
	BfmeItemERE *m_bfmeLastERE;
};

void BfmeVecERE::bfmeResizeERE(unsigned int count, BfmeItemERE value)
{
	if (count < (unsigned int)(m_bfmeLastERE - m_bfmeFirstERE))
		reinterpret_cast<_STL::vector<BfmeVectorRecord0002154F3> *>(this)->erase(
			reinterpret_cast<BfmeVectorRecord0002154F3 *>(m_bfmeFirstERE + count),
			reinterpret_cast<BfmeVectorRecord0002154F3 *>(m_bfmeLastERE));
	else
	{
		unsigned int extra =
			count - (unsigned int)(m_bfmeLastERE - m_bfmeFirstERE);

		reinterpret_cast<_STL::vector<BfmeVectorRecord0002154F3> *>(this)->_M_fill_insert(
			reinterpret_cast<BfmeVectorRecord0002154F3 *>(m_bfmeLastERE), extra,
			*reinterpret_cast<const BfmeVectorRecord0002154F3 *>(&value));
	}
}
