// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/bfmelist /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??1Rva001DC0EC@@QAE@XZ @0x001DC0EC 120B. Dtor: deletes Rva001DBC77 items
// out of list<int> at +0 via erase loop then AsciiString at +0xC then the
// list base. Evidence: deleting-dtor caller 0x001DC1E1 item dtor row
// 0x001DBC77 erase row 0x00438539 releaseBuffer row 0x00036410 and
// list-base dtor row 0x004EC395. Honest address name.
#include "ascii_string.h"
#include <list>

// Retain bfmealloc's native null-checked free and proxy forwarding inline.
// The matched bodies already inline these STLport ownership wrappers.
namespace _STL {
template<> __declspec(dllimport) __forceinline
void allocator<_List_node<int> >::deallocate(pointer p, size_type n) const
{ if (p != 0) ::free((void*)p); }
template<> __declspec(dllimport) __forceinline
void _STLP_alloc_proxy<_List_node<int>*, _List_node<int>, allocator<_List_node<int> > >::deallocate(_List_node<int>* p, size_t n)
{ __stl_alloc_rebind(static_cast<_Base&>(*this), (_List_node<int>*)0).deallocate(p, n); }
}

// Retail's ~_List_base<int> may throw under /EHsc: the Rva001DC0EC dtor resets
// its EH state (or [ebp-4],-1) before calling it at 0x004EC395. With clear()'s
// body visible cl proves the base dtor nothrow and drops that store, so clear
// stays declared only; it binds the rowed list<int> owner.
namespace _STL {
template<> void _List_base<int, allocator<int> >::clear();
}

class Rva001DBC77
{
public:
	~Rva001DBC77();
};

#include <new>

class Rva001DC0EC
{
public:
	Rva001DC0EC();
	~Rva001DC0EC();
private:
	_STL::list<int, _STL::allocator<int> > m_list;
private:
	int m_04;
private:
	int m_08;
private:
	AsciiString m_0C;
private:
	bool m_10;
public:
	void rva001DC1B3(_STL::list<int, _STL::allocator<int> > *dest);
};

Rva001DC0EC::~Rva001DC0EC()
{
	_STL::list<int, _STL::allocator<int> >::iterator it = m_list.begin();
	while (it._M_node != m_list.end()._M_node) {
		Rva001DBC77 *p = (Rva001DBC77 *)*it;
		if (p != 0)
			delete p;
		it = m_list.erase(it);
	}
}
