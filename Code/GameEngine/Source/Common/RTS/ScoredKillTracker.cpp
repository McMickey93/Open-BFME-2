// cl: /ICode/Libraries/Include /Ireference/shims/bfme2_ascii /O1 /G7 /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc /Ireference/shims/moduledata
// stlport
// WB14162D0 names ScoredKillTracker::DoXfer and the tracked-kills count.
// Native55AA68..55AB41/217 proves the scalar offsets and Xfer slots, the
// four-byte ObjectFilter index at+8, and list<int> at+18 followed by count1C.
// Existing friend_update proves list elements are frame values and +4 is
// their lifetime window; the purpose of the scalar at+C remains unknown.
// The version is1/1. CRC returns before transfer; load rebuilds the list,
// save walks to a captured end iterator. No reference source identity is
// claimed: WB and retail supply this reconstruction. ObjectFilter::DoXfer
// is the independently rowed362255 provider; list clear/push are23DAA5/5548F.
#include <list>

// Declaration-only: retail keeps one copy of this STLport member (rowed elsewhere); this unit calls it
// rather than emitting its own.
namespace _STL {
template <> _List_base<int, allocator<int> >::~_List_base();
}
#include "Lib/Coord3D.h"

// list<int> destruction otherwise instantiates per-TU deallocate
// COMDATs (one byte shape per TU flags); explicit dllimport+forceinline
// specializations take those calls inline so this TU emits no external copy.
namespace _STL {
template <> __declspec(dllimport) __forceinline
void allocator<_List_node<int> >::deallocate(_List_node<int>* __p, size_t __n) const {
  _STLP_ASSERT( (__p == 0) == (__n == 0) )
    if (__p != 0) __sgi_alloc::deallocate((void*)__p, __n * sizeof(value_type));
}
template <> __declspec(dllimport) __forceinline
void _STLP_alloc_proxy<_List_node<int> *, _List_node<int>, allocator<_List_node<int> > >::deallocate(_List_node<int> *__p, size_t __n) {
  allocator<_List_node<int> >().deallocate(__p, __n);
}
}
class AsciiString;
// Retail Version stores minimum/current bytes and has an inline constructor;
// that constructor form also reproduces the independent stack homes in DoXfer.
struct TrackerVersion
{
    TrackerVersion(unsigned char min, unsigned char cur) : minimum(min), current(cur) {}
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
#include "../../../Include/Common/BfmeXfer.h"

namespace _STL {
template<>void _List_base<int, allocator<int> >::clear();
template<>void list<int>::push_back(const int&);
}

class ObjectFilter { public: void DoXfer(Xfer *); int m_id; };
#include "../ScoredKillTrackerView.h"
void ScoredKillTracker::DoXfer(Xfer *xfer) {
    if (xfer->IsCRC()) return;
    TrackerVersion version(1,1);
    (*xfer == reinterpret_cast<Xfer::Version &>(version));
    (*xfer == m_lifetime);
    reinterpret_cast<ObjectFilter *>(&m_filter)->DoXfer(xfer);
    (*xfer == m_value0c);
    (*xfer == m_playerIndex);
    (*xfer == m_trackedKillsCount);
    if (xfer->IsLoading()) {
        m_trackedKills.clear();
        for (int i=0; i<m_trackedKillsCount; ++i) {
            int kill;
            (*xfer == reinterpret_cast<unsigned int &>(kill));
            m_trackedKills.push_back(kill);
        }
    } else {
        _STL::list<int>::iterator end=m_trackedKills.end();
        for (_STL::list<int>::iterator it=m_trackedKills.begin(); it._M_node != end._M_node; ++it) {
            unsigned int kill=*it;
            (*xfer == kill);
        }
    }
    (*xfer == reinterpret_cast<Coord3DBase &>(m_position.value));
}

// WB14159C0 and native55A998..55AA06 RET12 prove these three arguments.
ScoredKillTracker::ScoredKillTracker(unsigned frames,const Rva00360D26Member &filter,unsigned flags):
 m_lifetime(frames),m_filter(filter),m_value0c(flags),m_keeper(0),m_playerIndex(-1),m_trackedKillsCount(0) {}
ScoredKillTracker::~ScoredKillTracker() {rva0055A91A();}
const char *ScoredKillTracker::GetSnapshotName() const {return "ScoredKillTracker";}

// Native55A892..55A8E2 is independently bounded80B, RET4.
// The unknown scalar0C acts as a player-acceptance mask here. No-player
// objects require all20 bits. The filter receives the keeper player only
// when the existing signed index is nonnegative. All callees already owned.
class Player {public:char opaque[0x54];int index;};
class PlayerList {public:Player*getNthPlayer(int);};extern PlayerList*ThePlayerList;
class Object {public:Player*getControllingPlayer()const;};
class Rva2225E0Filter {public:bool accepts(Object*,Player*);};
bool ScoredKillTracker::rva0055A892(const Object*object){
 Player*player=object->getControllingPlayer();
 if(player){if(!(m_value0c&(1u<<player->index)))return false;}
 else if(m_value0c!=0xFFFFF)return false;
 Player*owner=0;if(m_playerIndex>=0)owner=ThePlayerList->getNthPlayer(m_playerIndex);
 return ((Rva2225E0Filter*)&m_filter)->accepts((Object*)object,owner);
}

// Native55A8E2/55A8F2/55A904 reject configuration changes while hooked.
// Scalar/filter assignments and each RET4 independently prove these ABIs.
void ScoredKillTracker::rva0055A8E2(unsigned value){if(!m_keeper)m_lifetime=value;}
void ScoredKillTracker::rva0055A8F2(const Rva00360D26Member &filter){if(!m_keeper)m_filter=filter;}
void ScoredKillTracker::rva0055A904(unsigned value){if(!m_keeper)m_value0c=value;}
