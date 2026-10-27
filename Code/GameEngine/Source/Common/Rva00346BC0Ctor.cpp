// cl: /MD
// ??0Rva00346BC0@@QAE@IIIII@Z retail 0x00346BC0 109B
// Unlock ctor memset 0x10 plus four bit sets; first arg ignored like sibling
// Rva00265254 family. Evidence: memset via rowed ji_006291ae 0x006291AE;
// m_bits[aN>>5] |= 1u << (aN&31) for a2-a5; ret 0x14 five args; no float.
// memset is msvcr71's, called through its import thunk at 0x006291AE
// rather than expanded inline: <string.h>'s memset with
// #pragma function(memset).
#include <string.h>
#pragma function(memset)

class Rva00346BC0
{
public:
	Rva00346BC0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);
private:
	unsigned int m_bits[4];
};

Rva00346BC0::Rva00346BC0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
	memset(this, 0, 0x10);
	m_bits[a2 >> 5] |= 1u << (a2 & 31);
	m_bits[a3 >> 5] |= 1u << (a3 & 31);
	m_bits[a4 >> 5] |= 1u << (a4 & 31);
	m_bits[a5 >> 5] |= 1u << (a5 & 31);
}
