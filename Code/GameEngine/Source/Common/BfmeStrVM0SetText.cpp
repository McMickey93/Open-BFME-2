// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /arch:SSE /DNDEBUG /MD /EHsc
// ?rva0025D358@Display@@QAEXVUnicodeString@@MMHHH@Z, retail 0x0025D358, 112 bytes.
// Sets the +0xB0 display block: Unicode string via set plus ints at +0xB4/+0xB8/+0xBC
// and floats at +0xC0/+0xC4; the by-value string is released at the end.
// Evidence: same +0xB0/+0xD0/+0xF0 layout as the dtor 0x0025D686 (BfmeStrVM0Dtor.cpp)
// and ctor 0x0025D489; callees rowed StringBase<G>::set 0x00037150 and
// releaseBuffer 0x00036E70. The parameter is a UnicodeString: the only caller,
// 0x00356AC1 (Rva003560EDEngineRefresh.cpp), passes a UnicodeString copy of the
// fetched "GUI:Loading" text. Moved out of BfmeStrVM0Dtor.cpp, whose private
// StringBase view cannot spell UnicodeString (the canonical header owns it).
#include "../GameClient/DisplayStaticDebugView.h"

void Display::rva0025D358(UnicodeString s, float fC0, float fC4, int iB4, int iB8, int iBC)
{
	StringBase<unsigned short> &dst = m_sB0;
	dst.set(s);
	m_iB4 = iB4;
	m_iB8 = iB8;
	m_iBC = iBC;
	m_fC0 = fC0;
	m_fC4 = fC4;
}

// Retail 0x0025D3C8 (193B): NULL for an empty +0xB0 text; otherwise a new
// display string from TheDisplayStringManager given the +0xB4 font, the text
// and the +0xB8/+0xBC pair, after which +0xC8 holds half the unsigned width
// left over beside it (this slot 0x40 minus the string's width) and +0xCC the
// unsigned slot 0x44 value scaled by +0xC4. Returns the display string.
DisplayString *Display::rva0025D3C8()
{
	if (m_sB0.isEmpty())
		return 0;
	DisplayString *ds = TheDisplayStringManager->newDisplayString();
	if (ds) {
		ds->setFont((GameFont *)m_iB4);
		ds->setText(m_sB0);
		ds->setWordWrap(m_iB8, m_iBC);
		unsigned int width = ds->getWidth(-1);
		m_fC8 = (float)((getWidth() - width) >> 1);
		m_fCC = (float)getHeight() * m_fC4;
	}
	return ds;
}
