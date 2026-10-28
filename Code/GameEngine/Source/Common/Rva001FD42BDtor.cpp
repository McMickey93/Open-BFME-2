// cl: /DNDEBUG /MD /EHs
// ??1Rva001FD42B@@QAE@XZ @0x001FD6BC 56B.
// Tree destructor for the Rva001FD42B node family: clears via the rowed
// rva001FD630, then the inline header-handle member dtor frees the sentinel
// via the rowed free 0x00030830 with a null guard. Same 56B clear-plus-free
// shape as the rowed ??1AnimationSoundTree@@QAE@XZ 0x004CA653; the inline
// member dtor needs unwind across the clear, giving the __EH_prolog frame.
// Callers at 0x001FE27D 0x002B13AE and jmp at 0x001FD85E; unblocks 0x002B11A7.

// Retail calls free directly (the game allocator), not through the CRT
// import: read <stdlib.h> without dllimport. /EHs lets free throw,
// preserving retail's unwind states.
#define _CRTIMP
#include <stdlib.h>
#undef _CRTIMP

#include "RTS/PlayerTemplateTreeView.h"

Rva001FD42B::~Rva001FD42B()
{
	rva001FD630();
}
