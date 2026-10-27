// cl: /Oy-
// platformsdk

#include <windows.h>

int __stdcall EnumThreadWndProc(void *hwnd, long param);

class BfmeHostAAS
{
public:
	bool bfmeProbeAAS();

	unsigned char m_bfmeHeadAAS[0x9f55];
	char m_bfme9F55AAS;
};

bool BfmeHostAAS::bfmeProbeAAS()
{
	char state = m_bfme9F55AAS;

	if (state != 0)
		return state > 0;

	HWND found = 0;

	EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)EnumThreadWndProc, (long)&found);

	if (found == 0)
		return true;

	m_bfme9F55AAS = (char)0xff;

	if ((GetWindowLongA(found, -0x10) & 0xc00000) != 0)
		m_bfme9F55AAS = 1;

	RECT r;

	if (GetWindowRect(found, &r) != 0)
	{
		if (r.right - r.left < r.bottom - r.top)
			m_bfme9F55AAS = 1;
	}

	return m_bfme9F55AAS > 0;
}
