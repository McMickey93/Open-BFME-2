// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /ICode/Libraries/Source/WWVegas/WWLib
// stlport
// ?xferListInt@@YAPAVXfer@@PAV1@PAV?$list@HV?$allocator@H@_STL@@@_STL@@@Z @0x00206861 194B free list<int> Xfer helper version {1,1} via slot 0x28 size via slot 0x2C/0x78 IsStoring via slot 0x08 saving walks ints via slot 0x78 loading checks empty via FormatText 0x0060C36E plus Throw 0x00629094 then reloads via slot 0x78 plus rowed push_back 0x0005548F.
// Evidence: unlock lane every callee rowed or pinned; donor BFME1 ScriptEngine/XferListInt.cpp same skeleton; same shape as BFME2 XferListObjectID 0x0036ABAF 196B.
#define _STLP_NO_EXCEPTIONS 1
#include <list>

// Declaration-only: retail has one list<int>::insert (rowed in stlport_list_int_insert.cpp, node creation out of line);
// this unit calls it rather than emitting a copy with the node creation inlined.
namespace _STL {
template <> list<int, allocator<int> >::iterator list<int, allocator<int> >::insert(list<int, allocator<int> >::iterator, const int &);
}

// vector<int> fill/insert otherwise instantiates the _Construct<int,int>
// COMDAT (one byte shape per TU flags); a file-static overload takes those
// calls instead so this TU emits no external copy.
#include <new>
namespace _STL {
static inline void _Construct(int *__p, const int &__val)
{ new (__p) int(__val); }
}

// Compare nodes locally so this TU does not emit a conflicting iterator-base wrapper.
namespace _STL {
template <class T, class Traits>
static inline bool operator!=(const _List_iterator<T, Traits>& a,
                              const _List_iterator<T, Traits>& b)
{ return a._M_node != b._M_node; }
}


typedef unsigned char UnsignedByte;
typedef unsigned int UnsignedInt;
typedef bool Bool;

struct XferVersion
{
	UnsignedByte m_version;
	UnsignedByte m_currentVersion;
};

#include "../../Common/System/XferVectorTypes.h"
#include "../../../Include/Common/BfmeXfer.h"

class XferException
{
public:
	XferException(int tag, const char *format, ...);
	XferException(const XferException &that);
	~XferException();

	char *text;
	int tag;
};


typedef _STL::list<int> ListInt;

Xfer *xferListInt(Xfer *xfer, ListInt *list)
{
	XferVersion version;
	version.m_version = 1;
	version.m_currentVersion = 1;
	xfer->operator==(reinterpret_cast<Xfer::Version &>(version));

	UnsignedInt count = list->size();
	xfer->operator==("std::list").operator==(count);

	if (xfer->IsStoring())
	{
		ListInt::_Node *sentinel = list->_M_node._M_data;
		ListInt::_Node *node = (ListInt::_Node *)sentinel->_M_next;
		while (node != sentinel)
		{
			xfer->operator==(*((UnsignedInt *)&node->_M_data));
			node = (ListInt::_Node *)node->_M_next;
		}
	}
	else
	{
		if (!list->empty())
		{
			throw XferException(4, "List must be empty on load");
		}

		int value;
		while (count != 0)
		{
			--count;
			xfer->operator==(*((UnsignedInt *)&value));
			list->push_back(value);
		}
		--count;
	}
	return xfer;
}
