// cl: /MD /EHsc
// BFME1 6583b3c1 game/Libraries/Source/EA/Apt/Rva008921B0Atof.cpp
// supplies the adapter structure and empty scoped guard. The guard under
// /EHsc preserves a call rather than a tail jump; no exception handler emits.
// Native 6CD070..6CD07E forwards one cdecl char pointer, returning x87 double.
// Its call resolves to the rowed atof import thunk at 629970 (IAT BBA550):
// <stdlib.h>'s atof, with _CRTIMP empty (the header's own guard) so the call
// is a direct call to the thunk rather than through __imp__atof.
// No original EA adapter name is established.
#define _CRTIMP
#include <stdlib.h>
class EmptyGuard { public: ~EmptyGuard() {} };
extern "C" double Rva006CD070Atof(const char *text)
{
    EmptyGuard guard;
    return atof(text);
}
