// cl: /Ireference/shims/bfme2_ascii /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
// ?DoXfer@LivingWorldRegionConnection@@UAEXAAVXfer@@@Z @0x003F3054 70B
// Snapshot slot 3 DoXfer: Version(1,1) + regionName + numberAllowed via helper
// + detourPoints via vector helper.
// Evidence: 70B ebp frame ret 4; vslot 3 of 0x836E48 (LivingWorldRegionConnection
// copy ctor TU); calls Xfer 0x28 (Version) + 0x6C (Ascii) + rowed Get 0x3EFE82
// + rowed Xfer 0x3F2C0C; callees all rowed/pinned.
#include <vector>
#include "ascii_string.h"

class AsciiString;
class UnicodeString;
class PooledString;
struct XferUnknown11;
class Coord3DBase;
class ICoord3D;
class Region3D;
class IRegion3D;
class Coord2D;
class ICoord2D;
class Region2D;
class IRegion2D;
class RealRange;
class RGBColor;
class RGBAColorReal;
class RGBAColorInt;
class Snapshot;
class Thing;
class ModuleData;
class Object;
class DamageInfo;

#include "../../../Include/Common/BfmeXfer.h"
class Xfer::Version
    {
    public:
        unsigned char data[2];
    };

struct Rva003EFE82Obj;
int __cdecl Rva003EFE82Get(Rva003EFE82Obj *a, void *b);
struct BfmeE8
{
    float x;
    float y;
};
Xfer *Rva003F2C0CXfer(Xfer *xfer, _STL::vector<BfmeE8> *vec);

#include "../../../../../reference/shims/moduledata/Common/Snapshot.h"

class LivingWorldRegionConnection : public Snapshot
{
public:
    LivingWorldRegionConnection(const LivingWorldRegionConnection &that);
    virtual ~LivingWorldRegionConnection();
    virtual void LoadPostProcess();
    virtual const char *GetSnapshotName();
    virtual void DoXfer(Xfer &xfer);

private:
    AsciiString m_regionName;
    int m_numberAllowed;
    _STL::vector<BfmeE8> m_detourPoints;
};

void LivingWorldRegionConnection::DoXfer(Xfer &xfer)
{
    Xfer::Version v;
    v.data[0] = 1;
    v.data[1] = 1;
    xfer == v;
    xfer == m_regionName;
    Rva003EFE82Get((Rva003EFE82Obj *)&xfer, &m_numberAllowed);
    Rva003F2C0CXfer(&xfer, &m_detourPoints);
}
