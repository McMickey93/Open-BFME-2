// cl: /DNDEBUG /MD /EHsc /Oy-
// platformsdk
// ?clipCursorToClient@@YAXXZ, retail 0x000430C8, 98 bytes.
// Ported from Open-BFME-1
// (Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DDisplayClipCursor.cpp,
// their matched 113B row). Retail-measured deltas: the application window
// handle lives at 0x00DDE024 (re-read per use, like TheDisplay); the frame is
// 0x18 with esi/edi saved. Identity proven by the three user32 imports
// (GetClientRect + ClientToScreen + ClipCursor) in BFME1's order.

#include <windows.h>

// Retail address 0x00DDE024; patched from retail like any extern (no pin).
extern void *ApplicationHWnd;

void clipCursorToClient(void)
{
	RECT rect;
	GetClientRect((HWND)ApplicationHWnd, &rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;
	POINT point;
	point.x = rect.left;
	point.y = rect.top;
	ClientToScreen((HWND)ApplicationHWnd, &point);
	rect.left = point.x;
	rect.top = point.y;
	rect.right = point.x + width;
	rect.bottom = point.y + height;
	ClipCursor(&rect);
}
