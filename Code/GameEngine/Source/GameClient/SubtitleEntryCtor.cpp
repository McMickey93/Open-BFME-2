// cl: /MD /EHsc
// Retail 0x00688550 (74B). SubtitleEntry constructor: vptr immediate,
// text member via the shared wide-string copy body, scalar stores, and a
// cleared display flag. Transferred from the BFME1 reconstruction
// (SubtitleEntryConstructorDestructor.cpp); only the ctor is claimed here.
// The text member constructs through the StringBase<wchar_t> copy body at
// 0x37050 (private AAE row, same pattern as the narrow StringBase pins),
// reached through the shared header's inline UnicodeString copy constructor.

extern "C" const void *const __identifier("??_7SubtitleEntry@@6B@")[];

#include "../../../../reference/shims/bfme2_ascii/unicode_string.h"

class SubtitleEntry
{
public:
	SubtitleEntry(const UnicodeString &text, unsigned int color, int style,
		int alignment, int line, int startFrame, int endFrame);

private:
	void *m_vft;
	UnicodeString m_text;
	unsigned int m_color;
	int m_style;
	int m_alignment;
	int m_line;
	int m_startFrame;
	int m_endFrame;
	bool m_displayed;
};

// ??0SubtitleEntry@@QAE@ABVUnicodeString@@IHHHHH@Z
SubtitleEntry::SubtitleEntry(const UnicodeString &text, unsigned int color,
	int style, int alignment, int line, int startFrame, int endFrame) :
	m_vft((void *)((unsigned int)__identifier("??_7SubtitleEntry@@6B@"))),
	m_text(text),
	m_color(color),
	m_style(style),
	m_alignment(alignment),
	m_line(line),
	m_startFrame(startFrame),
	m_endFrame(endFrame),
	m_displayed(false)
{
}
