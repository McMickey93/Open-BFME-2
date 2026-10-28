// cl: /Ob0
// ?SetMovieImage@Display@@QAEXHHMMMM@Z @0x0025C6E2 74B evidence: same TU class Display as neighbours rva0025C46E rva0025D10F in BfmeConv1435.cpp; array at +0x68 element 24B bounds 3; 6 stack args ret 0x18; unblocks 0x00356724 0x00356889
// ?SetStaticImage@Display@@QAEXHHMMMM@Z @0x0025C72C 74B twin with const 2 at +0x14 via same array bounds and G7 imul; unblocks 0x0023958B 0x0035C566

#include "../GameClient/DisplayStaticDebugView.h"

void Display::SetMovieImage(int v0, int idx, float f0, float f1, float f2, float f3)
{
	if (idx >= 3)
		return;
	Rva0025C6E2Elem &e = m_staticImages[idx];
	e.m_04 = f0;
	e.m_08 = f1;
	e.m_0c = f2;
	e.m_00 = (Image *)v0;
	e.m_10 = f3;
	e.m_14 = 1;
}

void Display::SetStaticImage(int v0, int idx, float f0, float f1, float f2, float f3)
{
	if (idx >= 3)
		return;
	Rva0025C6E2Elem &e = m_staticImages[idx];
	e.m_04 = f0;
	e.m_08 = f1;
	e.m_0c = f2;
	e.m_00 = (Image *)v0;
	e.m_10 = f3;
	e.m_14 = 2;
}
