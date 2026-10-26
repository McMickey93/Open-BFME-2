// cl: /DNDEBUG /MD /EHsc
// stlport
// ?removeFromContain@TunnelTracker@@QAEXW4ObjectID@@H@Z, retail 0x004F54BF, 75 bytes.
// Removes an ObjectID from list at +0x10 via rowed find 0x0029B694 and rowed ObjectID erase (pin at 0x00438539 folded onto int erase), then dec count at +0x18.
// Layout: pad 0x10, list at +0x10, count at +0x18 (list size 8). Evidence: leaf packet with 2 unclaimed callers; TunnelContain caller 0x0047DC88 passes through ObjectID plus second int arg; ret 8 is thiscall 2 args with second unused.
// Precedent Rva002A1111.cpp for find plus Rva0029BA28.cpp for list erase.
#include <list>
#include "../GameLogicObjectLookupView.h"
#include "../RTS/TunnelTrackerNemesisView.h"

// Compare nodes locally so this TU does not emit a conflicting iterator-base wrapper.
namespace _STL {
template <class T, class Traits>
static inline bool operator!=(const _List_iterator<T, Traits>& a,
                              const _List_iterator<T, Traits>& b)
{ return a._M_node != b._M_node; }
}


namespace _STL
{
template <class _InputIter, class _Tp>
_InputIter find(_InputIter __first, _InputIter __last, const _Tp &__val);
}

// bfme link decl-only begin
namespace _STL { template <> void _STLP_alloc_proxy<_STL::_List_node<ObjectID> *,_STL::_List_node<ObjectID>,_STL::allocator<_STL::_List_node<ObjectID> > >::deallocate(_STL::_List_node<ObjectID> *,unsigned int); }
namespace _STL { template <> void allocator<_STL::_List_node<ObjectID> >::deallocate(_STL::_List_node<ObjectID> *,unsigned int) const; }
namespace _STL { template <> _STL::_List_iterator<ObjectID,_STL::_Nonconst_traits<ObjectID> > list<ObjectID,_STL::allocator<ObjectID> >::erase(_STL::_List_iterator<ObjectID,_STL::_Nonconst_traits<ObjectID> >); }
// bfme link decl-only end
void TunnelTracker::removeFromContain(ObjectID val, int dummy)
{
	_STL::list<ObjectID>::iterator it = _STL::find(
		reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->begin(),
		reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->end(), val);
	if (it == reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->end())
		return;
	reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->erase(it);
	--m_containListSize;
}

bool TunnelTracker::isInContainer(ObjectID val)
{
	return _STL::find(
		reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->begin(),
		reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->end(), val)
		!= reinterpret_cast<_STL::list<ObjectID> *>(&m_containHead)->end();
}
