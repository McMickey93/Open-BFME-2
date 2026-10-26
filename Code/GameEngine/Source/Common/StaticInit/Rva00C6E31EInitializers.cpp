// cl: /Oi /MD
// ATL's four-entry device-context cache initializer.
#include <string.h>

extern "C" int __cdecl atexit(void (__cdecl *callback)());
void rva007B9B0A();
void Rva00C6E31EInitialize();
struct HDC__;

namespace ATL
{
class CImage
{
    class CDCCache
    {
        HDC__ *m_ahDCs[4];
    };
    static CDCCache s_cache;
    friend void ::Rva00C6E31EInitialize();
};
}

void Rva00C6E31EInitialize()
{
    memset(&ATL::CImage::s_cache, 0, sizeof(ATL::CImage::s_cache));
    atexit(rva007B9B0A);
}
