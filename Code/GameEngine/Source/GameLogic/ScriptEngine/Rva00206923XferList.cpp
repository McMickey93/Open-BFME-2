// ?Rva00206923XferList@@YAPAVXfer@@PAV1@PAV?$list@UBfmeSpecialPowerTimer8@@V?$allocator@UBfmeSpecialPowerTimer8@@@_STL@@@_STL@@@Z @0x00206923 205B
// cl: /Ireference/shims/bfmelist /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /ICode/Libraries/Source/WWVegas/WWLib
// stlport
// Free list<BfmeSpecialPowerTimer8> Xfer helper version {1 1} via slot 0x28 size via slots 0x2C 0x78 IsSaving via slot 0x08 saving walks timers via rowed Chain 0x00203D86 loading rejects a nonempty list with XferException then reloads via Chain plus rowed push_back 0x004DE74D. Evidence: leaf lane 2 callers; prev 0x00206861 next 0x00206ABE; strings std::list List must be empty on load; same skeleton as rowed xferListInt 0x00206861 and Rva00207F91.
#define _STLP_NO_EXCEPTIONS 1
#include <list>

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

// Retail ThrowInfo names the 8-byte XferException class and its rowed
// copy constructor and destructor (see Common/System/XferException.cpp).
class XferException
{
public:
	XferException(int tag, const char *format, ...);
	XferException(const XferException &that);
	~XferException();

	char *text;
	int tag;
};

#include "../../Common/BfmeSpecialPowerTimer8.h"

// Declare the rowed push_back so this TU calls it instead of emitting a
// competing generic insert/_M_create_node copy (same as Rva002AC6B1 precedent).
namespace _STL {
template<> void list<BfmeSpecialPowerTimer8, allocator<BfmeSpecialPowerTimer8> >::push_back(const BfmeSpecialPowerTimer8 &);
}

typedef _STL::list<BfmeSpecialPowerTimer8> ListTimer;

class Rva00203D86A;
void Rva00203D86Chain(Rva00203D86A *a, void *b);

Xfer *Rva00206923XferList(Xfer *xfer, ListTimer *list)
{
	XferVersion version;
	version.m_version = 1;
	version.m_currentVersion = 1;
	xfer->operator==(reinterpret_cast<Xfer::Version &>(version));

	UnsignedInt count = (UnsignedInt)list->size();
	xfer->operator==(XferVectorTypeName("std::list")).operator==(count);

	if (xfer->IsStoring())
	{
		ListTimer::_Node *sentinel = (ListTimer::_Node *)list->_M_node._M_data;
		ListTimer::_Node *node = (ListTimer::_Node *)sentinel->_M_next;
		while (node != sentinel)
		{
			Rva00203D86Chain((Rva00203D86A *)xfer, &node->_M_data);
			node = (ListTimer::_Node *)node->_M_next;
		}
	}
	else
	{
		if (!list->empty())
		{
			throw XferException(4, "List must be empty on load");
		}

		BfmeSpecialPowerTimer8 value = {0, 0};
		while (count != 0)
		{
			--count;
			Rva00203D86Chain((Rva00203D86A *)xfer, &value);
			list->push_back(value);
		}
	}
	return xfer;
}
