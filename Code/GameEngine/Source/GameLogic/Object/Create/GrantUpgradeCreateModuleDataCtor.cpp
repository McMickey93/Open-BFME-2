// cl: /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS /Ireference/shims/moduledata
// stlport

// ??0GrantUpgradeCreateModuleData@@QAE@XZ, retail 0x004B90E1 (78 bytes).
// The module-data half of GrantUpgradeCreate: vtable immediate 0x00C594E0
// modelled as an explicit first member (ToppleUpdateModuleDataCtor
// precedent, so no vtable is emitted and no dtor row is owed), an
// uninitialised word at +0x04 retail never stores, the upgrade-name string
// at +0x08 assigned empty via StringBase::set (rowed at 0x55F5, literal ""),
// the exempt-status mask at +0x0C reset through the ledger-known
// bitset<128>::reset body (rowed at 0x24CA24, HealContain precedent) and the
// BFME2 GiveOnBuildComplete flag at +0x1C defaulting to false. Field identity
// is retail's own INI table at 0x00C594A0 (landed buildFieldParse row) joined
// to the BFME1 GrantUpgradeCreate donor (UpgradeToGrant plus ExemptStatus;
// BFME2 extends it with GiveOnBuildComplete). The empty CreateModuleData base
// (inline-empty ctor plus Snapshot-reset dtor) is load-bearing for the EH
// state machine (Topple precedent): it advances the state to 0 with no
// emitted code, so the member init is bracketed by state 0/1 exactly as
// retail. Body order follows retail.

#include <bitset>

namespace _STL {
template<> bitset<128> &bitset<128>::reset();
}

extern "C" const void *const vtbl_00C594E0[];

template <typename T> class StringBase
{
public:
	StringBase() : m_data(0) {}
	~StringBase();
	void set(const char *str);

private:
	void *m_data;
};

typedef StringBase<char> AsciiString;

// Retail's state-0 unwind funclet 0x0078F234 jumps to 0x0049B47C, the
// ModuleData-family destructor fold that restores the Snapshot vptr
// 0x00BBB554: the base destructor is that reset (ToppleUpdateModuleDataCtor
// and CivilianSpawnCollideModuleData precedent). The unit defines the
// funclet's callee itself; no other object provides the nonvirtual spelling.
#include "Common/Snapshot.h"

class CreateModuleData
{
public:
	CreateModuleData() {}
	~CreateModuleData() { reinterpret_cast<Snapshot *>(this)->Snapshot::~Snapshot(); }

private:
};

class GrantUpgradeCreateModuleData : public CreateModuleData
{
public:
	GrantUpgradeCreateModuleData();

private:
	const void *m_vtable;
	unsigned int m_unused04;
	AsciiString m_upgradeName;			// +0x08
	unsigned long m_exemptStatus[4];		// +0x0C
	bool m_giveOnBuildComplete;			// +0x1C
};

GrantUpgradeCreateModuleData::GrantUpgradeCreateModuleData()
	: m_vtable(reinterpret_cast<const void *>(((unsigned int)vtbl_00C594E0)))
	, m_upgradeName()
{
	((_STL::bitset<128> *)m_exemptStatus)->reset();
	m_upgradeName.set("");
	m_giveOnBuildComplete = false;
}
