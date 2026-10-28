// cl: /DNDEBUG /MD /EHsc
// platformsdk
// ?rva00225492@BfmeDfe6e4@@QAEXXZ
// Refresh the timestamp on its owning thread under the class critical section.
// The thread ID uses WWLib's wrapper; time() binds its IAT slot directly. The
// scoped lock's destructor keeps retail's EBP frame under the region's /O1.

#include <windows.h>
#include <time.h>

class ThreadClass
{
public:
	static unsigned int _Get_Current_Thread_ID();
};

class WatchdogCriticalSection
{
public:
	void enter()
	{
		EnterCriticalSection(&m_storage);
	}

	void leave()
	{
		LeaveCriticalSection(&m_storage);
	}

private:
	CRITICAL_SECTION m_storage;
};

class ScopedWatchdogLock
{
public:
	ScopedWatchdogLock(WatchdogCriticalSection &section) : m_section(section)
	{
		m_section.enter();
	}

	~ScopedWatchdogLock()
	{
		m_section.leave();
	}

private:
	WatchdogCriticalSection &m_section;
};

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
	volatile int m_refCount; // +0x6C
	WatchdogCriticalSection m_cs; // +0x70
};

// ?rva00225492@BfmeDfe6e4@@QAEXXZ
void BfmeDfe6e4::rva00225492()
{
	if (ThreadClass::_Get_Current_Thread_ID() != m_threadId) {
		return;
	}
	time_t now;
	time(&now);
	ScopedWatchdogLock lock(m_cs);
	m_timestamp = now;
}

// ?rva00225460@BfmeDfe6e4@@QAEXXZ / ?rva0022546B@BfmeDfe6e4@@QAEXXZ, retail
// 0x00225460 and 0x0022546B (11B each), directly before 0x00225476: enter and
// leave the class critical section at +0x70 through the IAT.
void BfmeDfe6e4::rva00225460()
{
	m_cs.enter();
}

void BfmeDfe6e4::rva0022546B()
{
	m_cs.leave();
}
