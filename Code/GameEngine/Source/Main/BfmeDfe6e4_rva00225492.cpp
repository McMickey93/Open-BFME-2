// cl: /DNDEBUG /MD /EHsc /Oy- /Ireference/shims/bfme2_thread /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib
#include "thread.h"
// ?rva00225492@BfmeDfe6e4@@QAEXXZ
// Refresh the timestamp on its owning thread under the class critical section.
// The thread ID uses WWLib's wrapper; time() binds its IAT slot directly.

#ifndef NULL
#define NULL 0
#endif

typedef long time_t;

struct CRITICAL_SECTION
{
    unsigned char data[24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) long __cdecl time(time_t *tod);

class BfmeDfe6e4
{
public:
	void rva00225492();
    void rva00225460();
    void rva0022546B();

private:
	// Retail layout: owning thread id at +0x50, timestamp at +0x54,
	// guarded counter at +0x6C, critical section at +0x70.
	unsigned char m_unreconstructed_00[0x50];
	unsigned long m_threadId; // +0x50
	long m_timestamp; // +0x54
	unsigned char m_unreconstructed_58[0x6C - 0x58];
	int m_refCount; // +0x6C
	CRITICAL_SECTION m_cs; // +0x70
};

// ?rva00225492@BfmeDfe6e4@@QAEXXZ
void BfmeDfe6e4::rva00225492()
{
	if (ThreadClass::_Get_Current_Thread_ID() != m_threadId) {
		return;
	}
	time_t now;
	time(&now);
	EnterCriticalSection(&m_cs);
	m_timestamp = now;
	LeaveCriticalSection(&m_cs);
}

// ?rva00225460@BfmeDfe6e4@@QAEXXZ / ?rva0022546B@BfmeDfe6e4@@QAEXXZ, retail
// 0x00225460 and 0x0022546B (11B each), directly before 0x00225476: enter and
// leave the class critical section at +0x70 through the IAT.
void BfmeDfe6e4::rva00225460()
{
    EnterCriticalSection(&m_cs);
}

void BfmeDfe6e4::rva0022546B()
{
    LeaveCriticalSection(&m_cs);
}
