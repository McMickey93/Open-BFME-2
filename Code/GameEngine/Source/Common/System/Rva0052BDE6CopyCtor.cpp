// cl: /Ireference/shims/bfme2_ascii /MD /EHsc
// ??0Rva0052BDE6@@QAE@ABV0@@Z, retail 0x0052BDE6, 77 bytes.
// Copy ctor for an address-named value type holding strings at +4 and +8
// with vtable 0x00C61DB4. Evidence: StringBase<char> copies via pinned
// 0x000365F0 from param+4/+8 to this+4/+8 with EH state 0 then 1, sole
// caller 0x0052C369 placement construct, unlocks 0x0052C34D. Sibling of
// Rva0052BEF0 copy ctor (same empty-base EH plus manual vtable recipe).
#include "ascii_string.h"


extern "C" const void *const __identifier("??_7Rva004E1B00@@6B@")[];

class EmptyBase
{
public:
	EmptyBase() {}
	~EmptyBase();
};

class Rva0052BDE6 : public EmptyBase
{
public:
	Rva0052BDE6(const Rva0052BDE6 &other);

private:
	const void *m_vtable; // +0
	AsciiString m_str04; // +4
	AsciiString m_str08; // +8
};

Rva0052BDE6::Rva0052BDE6(const Rva0052BDE6 &other)
	: m_vtable(__identifier("??_7Rva004E1B00@@6B@"))
	, m_str04(other.m_str04)
	, m_str08(other.m_str08)
{
}

// This existing structural copy view names the same12B native MoveArmy record.
// Keep its ABI bridge explicit; EmptyBase/manual-vptr type reconciliation is
// deferred, not claimed solved by following the corrected real Snapshot table.
