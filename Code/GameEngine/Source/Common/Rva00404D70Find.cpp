// cl: /DNDEBUG /DBFME_SB_CLEAR_DECL /MD /GX /D_STLP_USE_STATIC_LIB /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfme2_ascii /Ireference/shims/moduledata /Ireference/shims/bfmealloc /ICode/Libraries/Include
// stlport
// ?rva00404D70@Rva00404D70@@QAEHABVAsciiString@@@Z @0x00404D70 117B
// Range find over 0x18-byte records with AsciiString at +0 via
// StringBase<char>::compareNoCase row 0x00006A00. Evidence: callers
// 0x00404FDB 0x0040502F 0x00405697 pass AsciiString and test 0x7fffffff;
// step 0x18 matches BfmeStringRecord00404BF3 neighbour TU.
#include <vector>
#include "ascii_string.h"

struct BfmeStringRecord00404BF3
{
	AsciiString text; // +0x00
	float f0; // +0x04
	float f1; // +0x08
	float f2; // +0x0C
	float f3; // +0x10
	float f4; // +0x14
	BfmeStringRecord00404BF3(const AsciiString &s);
};

class Rva00404D70
{
public:
	int rva00404D70(const AsciiString &s);
private:
	char m_pad[0x120];
	_STL::vector<BfmeStringRecord00404BF3> m_vec;
};

int Rva00404D70::rva00404D70(const AsciiString &asciiString)
{
	bool found = false;
	int result = 0x7fffffff;
	for (unsigned int i = 0; i < m_vec.size() && !found; ++i)
	{
		if (((const StringBase<char> *)&m_vec[i].text)->compareNoCase(*(const StringBase<char> *)&asciiString) == 0)
		{
			result = (int)i;
			found = true;
		}
	}
	return result;
}
