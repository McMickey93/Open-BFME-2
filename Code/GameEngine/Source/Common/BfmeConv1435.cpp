// cl: /Ob0 /Ireference/shims/bfme2_ascii
// platformsdk
// Near-miss donor from Open-BFME-1 BfmeConv1435.cpp
// (?bfmeTickVM0@Display@@QAEXXZ @0x0040FE40):
// retail predicate virtual is at slot +0x114 (not +0xF0).
// ?StartRenderThread@Display@@QAEXH@Z @0x0025D904 (199B):
// BFME2-only watchdog arming. A 64-bit timing base is divided by
// (timer - 2) through __alldiv and a frequency ratio is scaled on the x87
// unit; then two mutexes plus a worker thread are created and the first
// mutex is polled at 1ms until the wait times out.

#include <windows.h>

// Watcher thread armed by StartRenderThread. Retail's body returns with a plain
// ret: it is cdecl, cast to CreateThread's stdcall start type.
unsigned long __cdecl bfmeVM0WorkerThread(void *param);

__int64 g_bfmeVM0Total;
__int64 g_bfmeVM0Quotient;
extern double g_bfmeVM0Scale;
// g_bfmeVM0Scale: matched references place it at VA 0xdfea10 (zero-filled .bss).
double g_bfmeVM0Scale;
// g_bfmeVM0Factor: matched references place it at VA 0xbf5d50 (retail .rdata value 0.03333333333333333).

#include "../GameClient/DisplayStaticDebugView.h"

// ?bfmeVM0WorkerThread@@YAKPAX@Z retail 0x0025D128 (118B), the CreateThread
// start StartRenderThread pushes. It holds the first mutex while it runs and
// polls the second, which the arming thread owns, at the mode's period:
// mode 5 drives rva0025C4A4(1) every 33ms; any other mode probes through
// slot +0x118 until it succeeds (kicking slot +0x124 and retrying after 1ms)
// and then idles at 100ms.
unsigned long __cdecl bfmeVM0WorkerThread(void *param)
{
	Display *self = (Display *)param;
	bool probing = true;
	WaitForSingleObject(self->m_firstMutex, (unsigned long)-1);
	do {
		if (self->m_mode == 5) {
			self->rva0025C4A4(1);
			Sleep(33);
		} else if (probing) {
			if (!self->bfmeProbeVM0()) {
				self->bfmeKickVM0(1);
				Sleep(1);
			} else {
				probing = false;
				Sleep(100);
			}
		} else {
			Sleep(100);
		}
	} while (WaitForSingleObject(self->m_secondMutex, 0) == 0x102);
	ReleaseMutex(self->m_firstMutex);
	return 0;
}

void Display::bfmeTickVM0()
{
	if (bfmePredVM0())
		StartRenderThread(3);
}

// ?StartRenderThread@Display@@QAEXH@Z
void Display::StartRenderThread(int mode)
{
	if (m_firstMutex == 0 && m_secondMutex == 0) {
		if (mode != 5) {
			int span = m_timer->readTickCounter();
			--span;
			--span;
			g_bfmeVM0Quotient = g_bfmeVM0Total / span;
			g_bfmeVM0Scale = 1000.0 / (double)g_bfmeVM0Total * 0.03333333333333333;
		}
		m_firstMutex = CreateMutexA(0, 0, 0);
		m_secondMutex = CreateMutexA(0, 1, 0);
		m_armed = 0;
		if (m_secondMutex != 0 && m_firstMutex != 0) {
			m_mode = mode;
			CreateThread(0, 0, (unsigned long (__stdcall *)(void *))bfmeVM0WorkerThread, this, 0, 0);
			unsigned long status;
			do {
				status = WaitForSingleObject(m_firstMutex, 1);
				if (status == 0)
					ReleaseMutex(m_firstMutex);
			} while (status != 0x102);
		}
	}
}

//
// ?rva0025C46E@Display@@QAEXXZ retail 0x0025C46E 54B.
// Mutex release via m_firstMutex +0x40 and m_secondMutex +0x44 tail of Display.
// Evidence: retail cmp [esi+0x44] 0 je then ReleaseMutex WaitForSingleObject ReleaseMutex and zero both; callers 0x0025D9DB 0x0025D121 with no stack pushes and same this.
void Display::rva0025C46E()
{
	if (m_secondMutex != 0) {
		ReleaseMutex(m_secondMutex);
		WaitForSingleObject(m_firstMutex, (unsigned long)-1);
		ReleaseMutex(m_firstMutex);
		m_secondMutex = 0;
		m_firstMutex = 0;
	}
}

// ?rva0025D9CB@Display@@QAEX_N@Z retail 0x0025D9CB 24B.
// Flag selects watchdog arm (StartRenderThread mode 5) versus mutex release
// (rva0025C46E), forwarding this. Callers at 0x0043A30B/0x0043A326 push 0/1.
void Display::rva0025D9CB(bool flag)
{
	if (flag)
		StartRenderThread(5);
	else
		rva0025C46E();
}

// ?rva0025D10F@Display@@QAEXXZ retail 0x0025D10F 25B.
// Predicate-guarded mutex release: tail-jumps to rva0025C46E when the slot
// 0x114 predicate (bfmePredVM0) is true. Caller at 0x0025D1B3, same class.
void Display::rva0025D10F()
{
	if (bfmePredVM0())
		rva0025C46E();
}
