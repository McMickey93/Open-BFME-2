// platformsdk
// ?rva00882140PatchAllModules@@YAPAXPBD0PAX@Z
// Try rva00882050PatchImport against every module loaded in this process,
// then resolve the target through LoadLibraryA/GetProcAddress regardless.

#include <windows.h>
#include <TlHelp32.h>

extern bool rva00882050PatchImport(const char *moduleName, const char *dllName,
                                    const char *functionName, void *replacement);

void *rva00882140PatchAllModules(const char *dllName, const char *functionName, void *replacement)
{
    HANDLE snapshot = CreateToolhelp32Snapshot(8, GetCurrentProcessId());

    MODULEENTRY32 entry;
    entry.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(snapshot, &entry))
    {
        do
        {
            rva00882050PatchImport(entry.szModule, dllName, functionName, replacement);
        } while (Module32Next(snapshot, &entry));
    }

    CloseHandle(snapshot);

    return (void *)GetProcAddress(LoadLibraryA(dllName), functionName);
}
