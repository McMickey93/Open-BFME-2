// cl: /MD /EHs
// ??1Rva0041580E@@QAE@XZ @0x004159AA 56B chain via rowed 0x00415886.
// Destructor: cleanup via 0x00415886 then free head if non-null. Evidence:
// ECX passthrough to rowed 0x00415886 at 0x004159BF, lea ecx [esi+8] member
// call at 0x00415AF8, callers at 0x00415AF8 0x00415ADB.

// Retail calls free directly (the game allocator), not through the CRT
// import: read <stdlib.h> without dllimport. /EHs lets free throw,
// preserving retail's unwind states.
#define _CRTIMP
#include <stdlib.h>
#undef _CRTIMP

struct Rva0041580EHeadPtr
{
	~Rva0041580EHeadPtr()
	{
		if (m_ptr != 0)
			free(m_ptr);
	}
	void *m_ptr;
};

struct Rva0041580E
{
	Rva0041580EHeadPtr m_head00;
	int m_flag04;
	void rva00415886();
	~Rva0041580E();
};

Rva0041580E::~Rva0041580E()
{
	rva00415886();
}
