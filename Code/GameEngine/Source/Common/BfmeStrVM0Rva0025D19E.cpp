// cl: /Ireference/shims/bfme2_ascii /MD
// ?rva0025D19E@Display@@QAEXXZ, retail 0x0025D19E, 103 bytes.
// Field reset of Display: clears flags at +0x64/+0x10C, and when a timer is
// present runs the predicate-guarded release (rowed rva0025D10F), polls the
// timer slot-7 virtual and drops it; zeroes the +0xC8/+0xCC floats, resets a
// non-empty name at +0xD0 to the exported AsciiString::TheEmptyString
// (0x009E0878, via the pinned operator=), and stamps -1 at +0xE0/+0xE4.
// Evidence: sole caller at 0x0025D6A4 (unclaimed dtor, same this); rowed
// StringBase<char>::isEmpty (AsciiString.cpp) and slot-7 BfmeVM0Timer virtual.
#include "../GameClient/DisplayStaticDebugView.h"

void Display::rva0025D19E()
{
	m_b10C = false;
	m_b64 = false;
	if (m_timer != 0)
	{
		rva0025D10F();
		m_timer->v7();
		m_timer = 0;
	}
	m_fC8 = 0.0f;
	m_fCC = 0.0f;
	if (!m_name.isEmpty())
		m_name = AsciiString::TheEmptyString;
	m_iE4 = -1;
	m_iE0 = -1;
}
