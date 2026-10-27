// cl: /MD /D_CRTIMP=
// ?rva002CF32F@Rva002CF32F@@QAEXPAURva002CF32FNode@@@Z @0x002CF32F 45B.
// Tree erase: recurse right via +0xC, free the node via rowed _free 0x00030830,
// walk left via +0x8, ret 4. Same 45B shape as the rowed 0x002CF302 erase.
// Caller at 0x002CF815 unblocks 0x002CF807.
// Retail calls the game's _free at RVA 0x00030830 directly. Keep the CRT
// header's declaration without dllimport so /MD does not select __imp__free.
#include <stdlib.h>

struct Rva002CF32FNode
{
	unsigned char m_pad00[8];
	Rva002CF32FNode *m_left;
	Rva002CF32FNode *m_right;
};

struct Rva002CF32F
{
	void rva002CF32F(Rva002CF32FNode *x);
};

void Rva002CF32F::rva002CF32F(Rva002CF32FNode *x)
{
	while (x != 0) {
		rva002CF32F(x->m_right);
		Rva002CF32FNode *y = x->m_left;
		free(x);
		x = y;
	}
}
