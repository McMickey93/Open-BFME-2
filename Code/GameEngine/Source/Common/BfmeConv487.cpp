struct BfmeSubBLF
{
	unsigned char m_bfmeHead[4];
};

// The copy is msvcr71's strncpy (import thunk 0x0062983E), from <string.h>
// with _CRTIMP empty (the header's own guard) so the call is direct.
#define _CRTIMP
#include <string.h>

class BfmeThingBLF
{
public:
	void bfmeGoBLF(void *what);
	unsigned char m_bfmeHead[0x174];
	BfmeSubBLF m_bfmeSub;
};

void BfmeThingBLF::bfmeGoBLF(void *what)
{
	strncpy(reinterpret_cast<char *>(&m_bfmeSub), static_cast<const char *>(what), 0x20);
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?bfmeNoteVJI@BfmeSubVJI@@QAEXPBD@Z=?bfmeGoBLF@BfmeThingBLF@@QAEXPAX@Z")
