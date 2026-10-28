// cl: /MD
// ?rva00586BAB@Rva00586BAB@@QAEXXZ @0x00586BAB 30B.
// Chain from 0x00586B92: destroy range m_0..m_4 via rowed Destroy then free m_0 via 0x30830. Caller 0x00586CEF. Unlocks 0x00586C56.
class Rva00585B16;
void __cdecl Rva00586B92Destroy(Rva00585B16 *first, Rva00585B16 *last);

// Retail calls free directly (the game allocator), not through the CRT
// import: read <stdlib.h> without dllimport.
#define _CRTIMP
#include <stdlib.h>
#undef _CRTIMP

class Rva00586BAB {
public:
	void rva00586BAB();
private:
	Rva00585B16 *m_0;
	Rva00585B16 *m_4;
};
void Rva00586BAB::rva00586BAB()
{
	Rva00586B92Destroy(m_0, m_4);
	Rva00585B16 *p = m_0;
	if (p != 0)
		free(p);
}
