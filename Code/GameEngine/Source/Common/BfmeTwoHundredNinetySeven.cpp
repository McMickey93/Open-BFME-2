// cl: /Oy-
// platformsdk
// A text written to the standard output, its length measured in place. Nothing
// is written for one particular kind, nor when there is no text. The count
// written lands back in the first argument's own slot.

#include <windows.h>
#include <string.h>
#pragma intrinsic(strlen)

void __stdcall bfmeWriteQN(int kind, void *spare, char *text)
{
	if (kind == 5)
		return;

	if (text == 0)
		return;

	WriteFile(GetStdHandle((DWORD)-11), text, strlen(text), (DWORD *)&kind, 0);
}
