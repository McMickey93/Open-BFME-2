// cl: /GX- /MD
// ???0Rva000F0F2B@@QAE@XZ @0x000F0F2B 48B: native boundary from Ghidra.
// Address-derived constructor; the original class name remains unknown.
// Body is byte-exact against retail and reuses the rowed void initializer
// 0x000EFA4E, whose own prefix view lives in BfmeShadowPrefix.h. The three
// consecutive words observed at 0x00BCEFA0 (EFAD2, B3FD0, __purecall) are
// read as this class's three-slot dispatch table; the extent is not
// independently proven, adjacent tables remain possible.
#include "BfmeShadowPrefix.h"

// The three consecutive words read at 0x00BCEFA0 are the table this
// constructor installs. The data ledger lists ??_7W3DProjectedShadow@@6B@ and
// ??_7Rva007B1380@@6B@ for that address (0x007CEFA0, 3 slots); the only object
// that defines it is Rva007B1380Ctor.cpp, whose rowed constructor 0x00109D8C
// stores the same 0x00BCEFA0, so bind that defined name.
extern "C" const void *const __identifier("??_7Rva007B1380@@6B@")[];

class Rva000F0F2B : public Rva000EFA4E
{
public:
	Rva000F0F2B();
	float m_value58;
	float m_value5c;
	float m_value60;
	bool m_flag64;
};

Rva000F0F2B::Rva000F0F2B()
{
	initialize();
	m_value58 = 0.0f;
	m_value5c = 0.0f;
	*(const void *const **)this = __identifier("??_7Rva007B1380@@6B@");
	m_value60 = 20.0f;
	m_flag64 = false;
}

class Rva000F0F19 : public Rva000EFA4E
{
public:
	Rva000F0F19();
};

Rva000F0F19::Rva000F0F19()
{
	*(const void *const **)this = __identifier("??_7Rva007B1380@@6B@");
	initialize();
}
