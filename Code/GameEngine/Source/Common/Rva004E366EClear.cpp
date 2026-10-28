// cl: /MD
//
// ?rva004E366E@Rva004E366E@@QAEXXZ @ 0x004E366E (28B).
// Vector clear plus free: erases the BfmePod8 vector at +0 via rowed erase
// @0x003FA4DB then frees the start via rowed _free @0x00030830 when present.
// Frameless push esi shape. Callers at 0x004E3886 0x0052BBDA 0x0052CEFF.
// Honest-address name: owner unproven.

struct BfmePod8 { int a[2]; };

namespace _STL
{
template <class T> class allocator
{
};

template <class T, class A = allocator<T> > class vector
{
public:
	T *erase(T *first, T *last);

	T *m_start;
	T *m_finish;
	T *m_end;
};
}

// Retail calls free directly (the game allocator), not through the CRT
// import: read <stdlib.h> without dllimport.
#define _CRTIMP
#include <stdlib.h>
#undef _CRTIMP

class Rva004E366E
{
public:
	void rva004E366E();

private:
	_STL::vector<BfmePod8> m_vec;
};

void Rva004E366E::rva004E366E()
{
	m_vec.erase(m_vec.m_start, m_vec.m_finish);
	if (m_vec.m_start)
		free(m_vec.m_start);
}
