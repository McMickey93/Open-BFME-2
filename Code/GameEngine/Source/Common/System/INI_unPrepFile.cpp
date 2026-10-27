// cl: /Ireference/shims/bfme2_ascii /EHsc
// ?unPrepFile@INI@@IAEXXZ @0x0002BF4A 66B: thiscall clear with None plus empty.
// Evidence: ret no args; lea ecx [esi+0x838] to Rva00601BBCHelper::rva00601A8D pin; AsciiString+0x4 set None row; BfmeINICurrentFilename set TheEmptyString row; ints +0x8 +0xc +0x10 zeroed; byte +0x430 false; g_00DDF57C zeroed; callers are Catch funclets.
// Identity: the INI load variants 0x0002DA4B/0x0002DC75/0x0002DD38 call it on
// their normal and catch(...) exits after prepFile 0x0002D2C1, where BFME 1's
// ini.cpp calls unPrepFile; its stores (line list clear, filename "None",
// zeroed counters and end-of-file flag, null file-level global) follow that
// donor body. The member names are INI.cpp's view of the same offsets.
#include "ascii_string.h"
class Rva00601BBCHelper
{
public:
	void rva00601A8D();
};
extern AsciiString BfmeINICurrentFilename;
extern void *g_00DDF57C;
class INI
{
protected:
	void unPrepFile();
public:
	void *m_file;
	AsciiString m_filename;
	unsigned int m_readBufferNext;
	unsigned int m_readBufferUsed;
	unsigned int m_lineNum;
	char m_buffer[0x418 - 0x14];
	char m_pad418[0x430 - 0x418];
	unsigned char m_endOfFile;
	char m_curBlockStart[0x838 - 0x431];
	Rva00601BBCHelper m_helper;
};

void INI::unPrepFile()
{
	m_helper.rva00601A8D();
	((StringBase<char> *)&m_filename)->set("None");
	((StringBase<char> *)&BfmeINICurrentFilename)->set(*(const StringBase<char> *)&AsciiString::TheEmptyString);
	m_readBufferNext = 0;
	m_readBufferUsed = 0;
	m_lineNum = 0;
	m_endOfFile = false;
	g_00DDF57C = 0;
}
