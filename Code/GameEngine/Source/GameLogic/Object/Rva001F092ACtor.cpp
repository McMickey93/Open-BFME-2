// cl: /Ireference/shims/bfme2_ascii /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva001F092A@@QAE@XZ, retail 0x001F092A, 80 bytes.
// Default ctor: base is the canonical SubsystemInterface (rowed ctor
// 0x001B4E63; its dtor is the base vtable's 0x001B4E74), vptr 0x007E100C,
// map<int,void*> at +0x0C via rowed map ctor 0x0033C432, vector<BfmeE16> at
// +0x18 and +0x24 via rowed _Vector_base ctor 0x00211E58. Base layout (vptr
// + flag + AsciiString = 12B) from SubsystemInterfaceBaseConstruct.cpp; member
// pattern from Rva001FDB55Ctor.cpp (same base plus vector/set) and
// stlport_vector_e16_o1.cpp. Sole caller at 0x0022EBBD.
#include <vector>
#include <map>

#include "../../../../Libraries/Include/Lib/BfmeE16.h"
// bfme link decl-only BfmeE16
namespace _STL { template <> vector<BfmeE16, allocator<BfmeE16> >::~vector(); }

// 0x001B4E63 is the rowed SubsystemInterface ctor and 0x001B4E74 its dtor.
// The base has to be the canonical 12-byte class itself: a private 12-byte
// view emitted a second ??_7ObjectCreationListStore@@6B@ whose dtor slot was
// not retail's 0x001B4E74, so the dtor unit's copy lost by link order.
#include "../../../../Libraries/Source/subsystem/SubsystemInterface.h"

class ObjectCreationListStore : public SubsystemInterface
{
public:
	ObjectCreationListStore();
private:
	_STL::map<int, void *> m_map;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_vec0;
	_STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_vec1;
public:
	virtual ~ObjectCreationListStore();	// rowed elsewhere; declared so this unit binds to it
};

ObjectCreationListStore::ObjectCreationListStore()
{
}
