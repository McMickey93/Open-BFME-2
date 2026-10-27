// cl: /Ireference/shims/bfmelist /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// platformsdk
//
// ?rva001DC57C@GameWindowTransitionsHandler@@QAEXPAV?$list@HV?$allocator@H@_STL@@@_STL@@@Z @0x001DC57C 112B.
// GameWindowTransitionsHandler group collector (BFME 2 addition; Open-BFME 1
// rows the same shape as rva0048B690@GameWindowTransitionsHandler): under the
// critical section at +0x38, the current/pending/draw/secondary groups at
// +0x24/+0x28/+0x2C/+0x30 (Rva001DC0EC = TransitionGroup) each append to
// dest via the rowed 0x001DC1B3. Evidence: caller 0x0035D20C passes
// TheTransitionHandler (0x00DFDC14); handler field offsets match the ctor
// 0x001DCBC3 and dtor 0x001DC6E4.
#include <windows.h>
#include <list>

// The unwind funclet keeps an out-of-line ~CriticalSectionLock COMDAT; retail's
// (0x0061FC60, mov eax,[ecx]; push eax) is the favor-speed shape.
#pragma optimize("t", on)
class CriticalSectionLock
{
public:
	CRITICAL_SECTION *m_cs;
	CriticalSectionLock(CRITICAL_SECTION *cs) : m_cs(cs) { EnterCriticalSection(m_cs); }
	~CriticalSectionLock() { LeaveCriticalSection(m_cs); }
};
#pragma optimize("", on)

class Rva001DC0EC
{
public:
	void rva001DC1B3(_STL::list<int, _STL::allocator<int> > *dest);
};

class Rva001DBDA4;

// The group slots are Rva001DBDA4 pointers (TransitionGroup, as the update
// and reset bodies spell them); the collector walks them as Rva001DC0EC.
class GameWindowTransitionsHandler
{
public:
	void rva001DC57C(_STL::list<int, _STL::allocator<int> > *dest);
private:
	unsigned char m_pad00[0x24];
	Rva001DBDA4 *m_24;
	Rva001DBDA4 *m_28;
	Rva001DBDA4 *m_2C;
	Rva001DBDA4 *m_30;
	unsigned char m_pad34[4];
	CRITICAL_SECTION m_lock;
};

void GameWindowTransitionsHandler::rva001DC57C(_STL::list<int, _STL::allocator<int> > *dest)
{
	CriticalSectionLock lock(&m_lock);
	if (m_24 != 0)
		((Rva001DC0EC *)m_24)->rva001DC1B3(dest);
	if (m_28 != 0)
		((Rva001DC0EC *)m_28)->rva001DC1B3(dest);
	if (m_2C != 0)
		((Rva001DC0EC *)m_2C)->rva001DC1B3(dest);
	if (m_30 != 0)
		((Rva001DC0EC *)m_30)->rva001DC1B3(dest);
}
