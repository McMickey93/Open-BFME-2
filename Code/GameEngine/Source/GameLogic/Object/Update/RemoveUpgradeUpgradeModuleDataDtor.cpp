// cl: /DBFME_ASCII_DTOR_DECL /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// stlport
//
// ??1RemoveUpgradeUpgradeModuleData@@UAE@XZ, retail 0x004B8050, 69 bytes.
// ModuleData dtor: tears down two AsciiString vectors at +0x124 (state 1)
// then +0x118 (state 0) through the rowed 0x2CC70 body, then restores the
// Snapshot base vtable 0x00BBB554. Empty derived body with no base call since
// the base destruction is inline. Shape follows the landed
// ModelConditionSoundSelectorClientBehaviorModuleDataDtor/CivilianSpawnCollideModuleDataDtor (canonical
// Snapshot with inline BBB554-restoring dtor, novtable derived, empty body) plus the
// Rampage vector precedent. Layout from the rowed ctor 0x004B7FF1 (base
// 0x118 via OpenContain 0x253487, vectors at +0x118/+0x124, bytes at
// +0x130/+0x131, size 0x134 via factory 0x0025082A) and table 0xC58EA0.
// Caller is the slot-0 ??_G at 0x004B8034 (vtable 0x58EF0).

#include <vector>

#include "../../../../../../reference/shims/moduledata/Common/Snapshot.h"

#include "ascii_string.h"

// A declaration-only specialization stops this TU emitting its own
// vector<AsciiString> dtor COMDAT, so the call binds the kept copy.
namespace _STL {
template <> vector<AsciiString, allocator<AsciiString> >::~vector();
template <> _Vector_base<AsciiString, allocator<AsciiString> >::~_Vector_base();
template <> void _STLP_alloc_proxy<AsciiString*, AsciiString, allocator<AsciiString> >::deallocate(AsciiString*, size_t);
template <> void allocator<AsciiString>::deallocate(AsciiString*, size_t) const;
}

class __declspec(novtable) RemoveUpgradeUpgradeModuleData : public Snapshot
{
public:
	virtual ~RemoveUpgradeUpgradeModuleData();

private:
	// Opaque inherited storage between Snapshot's vptr and the two vectors.
	// The constructor's 0x118-byte base fixes this extent; its hierarchy is
	// not reconstructed by this destructor-only view.
	unsigned char m_unrecoveredBase04[0x118 - 4];
	_STL::vector<AsciiString> m_upgradeToRemove; // +0x118
	_STL::vector<AsciiString> m_upgradeGroupsToRemove; // +0x124
	unsigned char m_suppressEvaEventForRemoval; // +0x130
	unsigned char m_removeFromAllPlayerObjects; // +0x131
};

RemoveUpgradeUpgradeModuleData::~RemoveUpgradeUpgradeModuleData()
{
}
