// cl: /DNDEBUG /MD /EHsc
// ?_M_rva00625476@BfmeDfe6e4@@QAEXXZ
// retail 0x00225476, 28 bytes. Guarded counter increment under the class
// critical section. The volatile counter gives retail's add-mem under the
// region's /O1 /G7, as in the _M_rva00625699 decrement sibling.

struct CRITICAL_SECTION
{
    unsigned char data[24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section);

class BfmeDfe6e4
{
public:
	void _M_rva00625476();

private:
	// Retail layout: guarded counter at +0x6C, critical section at +0x70
	// (the sibling _M_rva00625699 decrements the counter the same way).
	unsigned char m_unreconstructed_00[0x6C];
	volatile int m_refCount; // +0x6C
	CRITICAL_SECTION m_cs; // +0x70
};

// ?_M_rva00625476@BfmeDfe6e4@@QAEXXZ
void BfmeDfe6e4::_M_rva00625476()
{
	EnterCriticalSection(&m_cs);
	m_refCount += 1;
	LeaveCriticalSection(&m_cs);
}
