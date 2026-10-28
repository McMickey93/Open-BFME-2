// cl: /DNDEBUG /MD /EHsc
// platformsdk
// ?_M_rva00625476@BfmeDfe6e4@@QAEXXZ
// retail 0x00225476, 28 bytes. Guarded counter increment under the class
// critical section. The volatile counter gives retail's add-mem under the
// region's /O1 /G7, as in the _M_rva00625699 decrement sibling.

#include <windows.h>

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
	void _M_rva00625476();

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

// ?_M_rva00625476@BfmeDfe6e4@@QAEXXZ
void BfmeDfe6e4::_M_rva00625476()
{
	ScopedWatchdogLock lock(m_cs);
	m_refCount += 1;
}
