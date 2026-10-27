// cl: /DNDEBUG /MD /EHs-c- /Oy-
// platformsdk
//
// Late-bound debugger probe, retail 0x0003E3E0 (108 bytes), between
// DebugFreeMemory and DebugAllocMemory in the debug library. The Debug
// constructor (0x00038440) calls it and turns the stack walk off
// (+0x9E79) when it reports a debugger.
//
// Ported from Open-BFME-1 Rva0088EAF0IsDebuggerPresent.cpp (b1 0x0088EAF0):
// kernel32 is loaded by name and IsDebuggerPresent resolved at run time.
// BFME2 additionally asks CheckRemoteDebuggerPresent for the current
// process and ORs both answers.

#include <windows.h>

typedef int(__stdcall *IsDebuggerPresentProc)(void);
typedef int(__stdcall *CheckRemoteDebuggerPresentProc)(void *process, int *present);

// ?DebugIsDebuggerAttached@@YA_NXZ
bool DebugIsDebuggerAttached()
{
	bool attached = false;
	HMODULE kernel = LoadLibraryA("kernel32");
	if (kernel)
	{
		IsDebuggerPresentProc isDebuggerPresent =
			(IsDebuggerPresentProc)GetProcAddress(kernel, "IsDebuggerPresent");
		if (isDebuggerPresent)
			attached = isDebuggerPresent() != 0;

		CheckRemoteDebuggerPresentProc checkRemote = (CheckRemoteDebuggerPresentProc)
			GetProcAddress(kernel, "CheckRemoteDebuggerPresent");
		int remote = 0;
		if (checkRemote && checkRemote(GetCurrentProcess(), &remote))
			attached |= remote != 0;
	}
	return attached;
}
