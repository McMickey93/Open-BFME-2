// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// stlport
//
// ?readLine@INI@@IAEXXZ @0x0002D669, 143 bytes. INI line reader (r15: unsigned-count fix).
//
// TARGET (retail facts): no-arg thiscall void (push esi/edi, ret); Ghidra
// FUN_0042d669 143B chain-exact (0x2D2C1+936=0x2D669, 0x2D669+143=0x2D6F8);
// calls size-like /12 body at 0x5D5847 (rowed vector<BfmeE12>::size), INT
// accessor at 0x6018B6 (rowed INIFileTable::getFileId), strncpy import
// (IAT 0xBBA620), rowed vector<AsciiString>::erase at 0x2CCFC, string clear
// at 0x36410 (rowed releaseBuffer bytes via canonical AsciiString::clear
// alias), strlen thunk at 0x629170 plus Xfer virtual slot 0x24 (xferUser)
// behind global 0xDDF57C. True branch copies a line into m_buffer (+0x14,
// 0x403 chars, last byte at +0x417 cleared), resets token cursor (vector at
// +0x870, AsciiString at +0x86C); false branch latches endOfFile (+0x430)
// and empties the buffer; tail hashes every line through s_xfer.
// Consumers: loadFile 0x2DC75, initFromINIMulti 0x2D7A8 (blocked 5578/662).
// No symbols.csv pin at 0x2D669.
//
// DONOR (reference facts, guidance only): BFME1 ini.cpp INI::readLine (void,
// no args): if (m_lineNum < (UnsignedInt)(m_lines.m_end - m_lines.m_begin))
// { line = m_lines.getText(m_lineNum++); strncpy(m_buffer,line,MAX-1);
// m_buffer[MAX-1]=0; } else { m_endOfFile=TRUE; m_buffer[0]=0; }
// if (s_xfer) s_xfer->xferUser(m_buffer, strlen(m_buffer)).
// Unsigned compare is donor-explicit; r14 signed cast emitted jge, retail is
// jae. INFERENCE: outer method is INI::readLine (arity/ABI/shape/consumer
// need agree); line-text meaning of getFileId slot + 12B views is inference,
// bytes/providers are target facts.

#include "ascii_string.h"

#include <string.h>

struct BfmeE12
{
	float x, y, z;
};

#include <vector>

// The rowed out-of-line size (0x005D5847) and erase (0x0002CCFC): explicit
// specialization declarations keep the calls instead of inlining STLport's
// in-class bodies.
namespace _STL
{
template <> unsigned int vector<BfmeE12, allocator<BfmeE12> >::size() const;
template <> vector<AsciiString, allocator<AsciiString> >::iterator
vector<AsciiString, allocator<AsciiString> >::erase(iterator first, iterator last);
}

class INIFileTable
{
public:
	int getFileId(int fileIndex) const;

	int m_reserved;
	_STL::vector<BfmeE12> m_lineVec;
	char m_tail[0x86C - 0x848];
};

// Target proves a raw buffer/size call through slot 9, not its class or method name.
class BfmeIniTransferSlot09
{
public:
	virtual void _d0() = 0;
	virtual void _d1() = 0;
	virtual void _d2() = 0;
	virtual void _d3() = 0;
	virtual void _d4() = 0;
	virtual void _d5() = 0;
	virtual void _d6() = 0;
	virtual void _d7() = 0;
	virtual void _d8() = 0;
	virtual void slot09(void *data, int dataSize) = 0;
};

// Sole provider: retail VA 0x00DDF57C contains four initial zero bytes.
// The clear routine and reader share this pointer without naming its runtime class.
void *g_00DDF57C = 0;

// The 0x34-byte helper at INI +0x838 (INIHelperRva00601BBC_Rva00601BBCHelper.cpp);
// readLine reads it as the INIFileTable record view.
class Rva00601BBCHelper
{
public:
	Rva00601BBCHelper();
	virtual ~Rva00601BBCHelper();
	void rva00601A8D();

private:
	char m_body[0x30]; // after the vptr: 0x34 bytes in all
};

// Member names follow INI.cpp's view of the same offsets: m_readBufferUsed
// holds the current line index, m_str86C/m_vec870 the token cursor.
class INI
{
protected:
	void readLine();

public:
	void *m_file;
	AsciiString m_filename;
	unsigned int m_readBufferNext;
	unsigned int m_readBufferUsed;
	unsigned int m_lineNum;
	char m_buffer[0x418 - 0x14];
	const char *m_seps;
	const char *m_sepsPercent;
	const char *m_sepsColon;
	const char *m_sepsQuote;
	const char *m_blockEndToken;
	const char *m_endScriptToken;
	unsigned char m_endOfFile;
	char m_curBlockStart[0x838 - 0x431];
	Rva00601BBCHelper m_helper;
	AsciiString m_str86C;
	_STL::vector<AsciiString> m_vec870;
};

// ?readLine@INI@@IAEXXZ
void INI::readLine()
{
	if (m_lineNum < ((INIFileTable *)&m_helper)->m_lineVec.size()) {
		unsigned int cur = m_lineNum;
		m_readBufferUsed = cur;
		m_lineNum = cur + 1;
		const char *line = (const char *)((INIFileTable *)&m_helper)->getFileId(cur);
		strncpy(m_buffer, line, 0x403);
		m_buffer[0x403] = 0;
		_STL::vector<AsciiString> &toks = m_vec870;
		AsciiString *first = toks.begin();
		AsciiString *last = toks.end();
		toks.erase(first, last);
		m_str86C.clear();
	} else {
		m_endOfFile = 1;
		m_buffer[0] = 0;
	}
	if (g_00DDF57C != 0) {
		unsigned int len = strlen(m_buffer);
		((BfmeIniTransferSlot09 *)g_00DDF57C)->slot09(m_buffer, (int)len);
	}
}
