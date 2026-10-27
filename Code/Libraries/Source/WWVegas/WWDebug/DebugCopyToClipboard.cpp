// cl: /DNDEBUG /MD /EHs-c- /Oy-
// platformsdk
//
// Clipboard helper at retail 0x0003C730 (112 bytes): puts a copy of a text
// on the clipboard as CF_TEXT in a moveable/DDE-share/zeroed GlobalAlloc
// block. The assert/crash dialog's copy button (0x0003D3A0) calls it with
// the report text. The name is descriptive; no symbol survives for it.

#include <windows.h>
#include <string.h>

// ?DebugCopyToClipboard@@YAXPBD@Z
void DebugCopyToClipboard(const char *text)
{
	if (!text || !OpenClipboard(0))
		return;

	HGLOBAL memory = GlobalAlloc(0x2042, strlen(text) + 1);
	if (memory)
	{
		strcpy((char *)GlobalLock(memory), text);
		GlobalUnlock(memory);
		EmptyClipboard();
		SetClipboardData(1, memory);
	}
	CloseClipboard();
}
