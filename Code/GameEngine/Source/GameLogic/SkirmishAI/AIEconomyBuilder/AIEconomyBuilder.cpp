// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// WB1383180 identifies AIEconomyBuilder::DoXfer; native4EA93F..4EAA4B
// proves version1/1, scalars18/1C/20 and pointer range24. Saving counts
// kind1 and other records, then transfers the kind1 IDs at70. Loading
// subtracts omitted records from count1C and appends lookup4EA124 results.
// EconomyFarmView describes only accesses proven in that body and lookup;
// it does not assign a recovered class identity to the farm pointees.
// Canonical49B4DFCB0 supplies pointer-vector growth through its verified
// three-word/four-byte-pointer ABI; no wall/farm-is-ModuleData claim.
#include <vector>
class AsciiString;
// Retail Version stores minimum/current bytes and has an inline constructor;
// that constructor form also reproduces the independent stack homes in DoXfer.
struct WallVersion
{
    WallVersion(unsigned char min, unsigned char cur) : minimum(min), current(cur) {}
    unsigned char minimum, current;
};
class Snapshot;
class AsciiString;
class UnicodeString;
class PooledString;
struct Coord3DBase;
struct ICoord3D;
struct Region3D;
class IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
class RealRange;
struct RGBColor;
class RGBAColorReal;
class RGBAColorInt;
struct XferUnknown11;
#include "../../../../Include/Common/BfmeXfer.h"


class ModuleData;
namespace _STL { template<> void vector<const ModuleData*>::push_back(const ModuleData *const&); }
void *Rva004EA124Find(void *);
struct EconomyFarmView { unsigned char unknown0[0x10]; unsigned int kind; unsigned char unknown14[0x5c]; unsigned int id; };
#include "AIEconomyBuilderFarmLibrary.h"
void AIEconomyBuilder::DoXfer(Xfer *xfer) {
 
 WallVersion version(1,1);
 xfer->operator==(reinterpret_cast<Xfer::Version &>(version));
 xfer->operator==(value18);
 xfer->operator==(count1c);
 xfer->operator==(value20);
 unsigned int farmCount=0;
 unsigned int otherCount=0;
 if(xfer->IsStoring()) {
  _STL::vector<EconomyFarmView*>::iterator end=reinterpret_cast<_STL::vector<EconomyFarmView*>&>(storage).end();
  for(_STL::vector<EconomyFarmView*>::iterator it=reinterpret_cast<_STL::vector<EconomyFarmView*>&>(storage).begin(); it!=end; ++it) {
   if((*it)->kind==1) ++farmCount;
   else ++otherCount;
  }
 }
 xfer->operator==(farmCount);
 xfer->operator==(otherCount);
 if(xfer->IsStoring()) {
  _STL::vector<EconomyFarmView*>::iterator end=reinterpret_cast<_STL::vector<EconomyFarmView*>&>(storage).end();
  for(_STL::vector<EconomyFarmView*>::iterator it=reinterpret_cast<_STL::vector<EconomyFarmView*>&>(storage).begin(); it!=end; ++it) {
   if((*it)->kind==1) { unsigned int id=(*it)->id; xfer->operator==(id); }
  }
 } else if(xfer->IsLoading()) {
  count1c-=otherCount;
  for(unsigned int i=0;i<farmCount;++i) {
   unsigned int id=0;
   xfer->operator==(id);
   void *farm=Rva004EA124Find(reinterpret_cast<void*>(id));
   reinterpret_cast<_STL::vector<const ModuleData*>&>(storage).push_back(reinterpret_cast<const ModuleData *const&>(farm));
  }
 }
}
