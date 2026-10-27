// cl: -DNDEBUG -MD -EHsc -Ireference/open-bfme-1/game/GameEngine/Source/GameLogic
//
// Retail 0x00194810: split name on the first '/'. Hit returns (prefix, suffix);
// miss returns (AsciiString::TheEmptyString, name). Pair construction is the
// landed bfmeMakePairEL factory (ILT 0x0001E7EF -> 0x00193520).
// Address-derived name: used as the map key for 0x0019B780.

#include "../../../../reference/shims/bfme2_ascii/ascii_string.h"

// Rva00194810 calls getCharAt out of line (0x00035720). Retail keeps the
// speed-built copy there (string_base_inline.cpp); this unit's /O1 copy would
// tail-merge the returns and be the copy the link keeps, so the body is built
// for speed. Keeping the definition visible also preserves the caller's cached
// buffer pointer; a declaration alone makes it reload after each accessor call.
#pragma optimize("t", on)
template<> inline char StringBase<char>::getCharAt(int index) const throw()
{
	return m_data ? m_data->data[index] : 0;
}
#pragma optimize("", on)

class BfmeWordEL : private AsciiString
{
public:
	BfmeWordEL(const BfmeWordEL &other) : AsciiString(other) {}
	BfmeWordEL(const BfmeWordEL &other, int start, int len)
		: AsciiString(other, start, len) {}
	~BfmeWordEL() {}

	int getLength() const { return ((const StringBase<char> *)this)->getLength(); }
	char getCharAt(int index) const { return ((const StringBase<char> *)this)->getCharAt(index); }
};

struct BfmePairEL
{
	// Callers destroy this pair through the established pair provider.
	// This producer does not own an independent cleanup implementation.
	~BfmePairEL();
	BfmeWordEL first;
	BfmeWordEL second;
};

BfmePairEL __cdecl bfmeMakePairEL(const BfmeWordEL &first, const BfmeWordEL &second);

// ?Rva00194810@@YA?AUBfmePairEL@@ABVBfmeWordEL@@@Z
BfmePairEL __cdecl Rva00194810(const BfmeWordEL &name)
{
	int i = 0;
	while (i < name.getLength())
	{
		if (name.getCharAt(i) == '/')
		{
			BfmeWordEL suffix(name, i + 1, name.getLength() - i - 1);
			BfmeWordEL prefix(name, 0, i);
			return bfmeMakePairEL(prefix, suffix);
		}
		++i;
	}
	return bfmeMakePairEL(
		*reinterpret_cast<const BfmeWordEL *>(&AsciiString::TheEmptyString),
		name);
}
