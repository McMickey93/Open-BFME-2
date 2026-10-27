// cl: /DNDEBUG /MD /Ireference/shims/bfme2_ascii
// ??0Rva0039EA9C@@QAE@XZ @0x0039EA9C 27B, call sites 0x0059A388 0x0059A689
// 0x005A9FDF. Six-dword record: zeros, 1 at +0x08, -1 at +0x14.
// Structural inference: retail stores the -1 last (or dword [+0x14], -1
// after the zero and 1 stores) even though plain int initialisers schedule
// it first; a +0x14 member sub-object with its own inline -1 constructor
// gives exactly that order.
#include <new>
#include "ascii_string.h"

struct Rva0039EA9CHandle
{
	int m_value;
	Rva0039EA9CHandle() : m_value(-1) {}
};

// The record as the Team.cpp seed spells it: the +0x0C/+0x10 words are
// AsciiStrings (TeamPrototype::rva003A0D0A reads the +0x10 name; the rowed
// dtor 0x0039EAB7 releases both), whose inline default constructors store
// the same zeros.
class Rva0039EA9C
{
public:
	Rva0039EA9C();
	~Rva0039EA9C();
public:
	int m_00;
	int m_04;
	int m_08;
	AsciiString m_0c;
	AsciiString m_10;
	Rva0039EA9CHandle m_14;
};
// Select-any like every other TU's copy (a strong definition would duplicate theirs at link time);
// the anchor keeps the noinline body emitted.
__declspec(noinline) inline Rva0039EA9C::Rva0039EA9C() : m_00(0), m_04(0), m_08(1)
{
}

// ?bfmeAnchorRva0039EA9C absent-from-retail
void *bfmeAnchorRva0039EA9C(void *where)
{
	return new (where) Rva0039EA9C();
}

