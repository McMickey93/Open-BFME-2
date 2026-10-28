// cl: /Ob0
// ?rva0025C776@Display@@QAEXHMMMMHH@Z @0x0025C776 131B
// Third Display block setter, sibling of SetMovieImage/SetStaticImage in
// Rva0025C6E2.cpp: same object model, the +0x110/+0x124/+0x138 scalar block.
// Seven stack args (ret 0x1c); the reciprocal stores
// 1.0f / (float)a20 at +0x11c and the same literal at +0x120, both read from
// the compiler literal pool at 0x00BBB8D8 (modelled as a private extern float).
// The stores are written through volatile lvalues so MSVC 2003's /O1 list
// scheduler keeps the retail store order (m_124, m_130, m_134, m_138, m_110)
// instead of sinking the +0x138 immediate past the divss into its latency slot;
// the volatile qualifier emits the identical mov/movss encodings and the
// function has no externally visible behaviour change.

#include "../GameClient/DisplayStaticDebugView.h"

extern float g_Va00BBB8D8;

// ?rva0025C776@Display@@QAEXHMMMMHH@Z @0x0025C776
void Display::rva0025C776(int a8, float fc, float f10, float f14, float f18, int a1c, int a20)
{
	m_128 = fc;
	m_12c = f10;
	*(volatile int *)&m_124 = a8;
	int t_a1c = a1c;
	*(volatile float *)&m_130 = f14;
	*(volatile float *)&m_134 = f18;
	float one = g_Va00BBB8D8;
	*(volatile int *)&m_138 = 1;
	*(volatile int *)&m_110 = t_a1c;
	float fdiv = one / (float)a20;
	m_118 = a20;
	m_11c = fdiv;
	m_120 = one;
}
