// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHs
// ??1Rva0022300F@@QAE@XZ @0x0022300F 59B
// Dtor releasing wide string at +0xC via rowed releaseBuffer 0x00036E70 then
// freeing pointer at +0 via free 0x00030830 with null guard.
// Evidence: lea ecx [esi+0xC] call ?releaseBuffer@?$StringBase@G@@AAEXXZ then
// mov esi [esi] null-guarded free; __EH_prolog frame with and [ebp-4] 0 and
// or [ebp-4] -1. Same EH clear-plus-free shape as rowed 57B dtors.
// Callers at 0x00223062 0x00224C5F and jmp at 0x0076F5C5; unblocks 0x0022304A
// and 0x00224BDB.

// Retail calls free directly (the game allocator), not through the CRT
// import: read <stdlib.h> without dllimport. /EHs lets free throw,
// preserving retail's unwind states.
#define _CRTIMP
#include <stdlib.h>
#undef _CRTIMP

#include "unicode_string.h"

struct Rva0022300FPtrHandle
{
	~Rva0022300FPtrHandle()
	{
		if (m_ptr)
			free(m_ptr);
	}
	void *m_ptr;
};

class Rva0022300F
{
public:
	~Rva0022300F();
private:
	Rva0022300FPtrHandle m_handle;
	char m_pad04[8];
	UnicodeString m_str;
};

Rva0022300F::~Rva0022300F()
{
}
