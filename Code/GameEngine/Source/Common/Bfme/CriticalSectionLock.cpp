// cl: /DNDEBUG /MD /EHsc
// platformsdk
// ??0CriticalSectionLock@@QAE@PAUBfmeCriticalSection@@@Z @0x0061FC40, 22 bytes.
// BFME1 Bfme sweep exact placement; verbatim source import. The unmatched
// Glo00EF3330::h00489410 draft that lived here called the unpinned
// ?j_00043c57@@YAXXZ, which nothing defines, so the file could not link;
// the draft is removed (no row ever claimed it) and only the matched lock
// helper remains.

#include <windows.h>

struct BfmeCriticalSection;

class CriticalSectionLock
{
public:
	explicit CriticalSectionLock(BfmeCriticalSection *section);

	~CriticalSectionLock()
	{
		LeaveCriticalSection(m_section);
	}

private:
	LPCRITICAL_SECTION m_section;
};

CriticalSectionLock::CriticalSectionLock(BfmeCriticalSection *section) : m_section((LPCRITICAL_SECTION)section)
{
	EnterCriticalSection(m_section);
}
