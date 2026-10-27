// cl: /MD /DNDEBUG
//
// ??0SlaveWatcherBehaviorModuleData@@QAE@XZ, retail 0x004846C7,
// 22 bytes. Frameless store-only ctor over table 0xC4A208
// (GrantUpgrade@8, RemoveUpgrade@C, ShareUpgrades@10, LetSlaveLive@11).
// Identity is the table (BFME1 SlaveWatcherBehaviorModuleDataConstructor
// donor carries GrantUpgrade@8/RemoveUpgrade@C at identical offsets;
// BFME2 extends with ShareUpgrades/LetSlaveLive bytes) plus the rowed
// poolkey 0x48462E (SlaveWatcherBehavior) in the same cluster plus
// factory 0x24C660 news 0x14 sole caller plus proc 0x4845BA rowed.
// Shape follows ReflectDamage trivial-ctor precedent: flat TU-local class
// with explicit void*m_vtable (no virtuals, no vtable emission) plus
// plain-data members; body assignments in retail order. Strings are 4B
// zeroed slots, modeled as const char* (BattlePlan precedent). Vtable
// 0x00C4A298 is unique image-wide (single installing site).

// Retail VA 0x00C4A298 (.rdata): a 31-slot vftable no unit emits. Defined here as
// data with retail's slot pointers, each bound to the ledger name at its
// target (tools/vftable_map.py); its installers store this table.
extern "C" void __identifier("?GetSnapshotName@ModuleData@@UBEPBDXZ")();
extern "C" void __identifier("??1Coord2D@@QAE@XZ")();
extern "C" void __identifier("?rva000B69A1@Rva000B69A1@@QAE?AVAsciiString@@H@Z")();
extern "C" void __identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z")();
extern "C" void __identifier("?IsCRC@Xfer@@UBE_NXZ")();
extern "C" void __identifier("?DoXfer@EmissionVelocityInfo@FXParticleSystem@@UAEXAAVXfer@@@Z")();
extern "C" void __identifier("??_GSlaveWatcherBehaviorModuleData@@UAEPAXI@Z")();
extern "C" void __identifier("?rva0050B5C6@Rva0050B5C6@@QAE_NXZ")();
extern "C" const void *const vtbl_00C4A298[] = {
	(const void *)&__identifier("??_GSlaveWatcherBehaviorModuleData@@UAEPAXI@Z"),
	(const void *)&__identifier("??1Coord2D@@QAE@XZ"),
	(const void *)&__identifier("?GetSnapshotName@ModuleData@@UBEPBDXZ"),
	(const void *)&__identifier("?DoXfer@EmissionVelocityInfo@FXParticleSystem@@UAEXAAVXfer@@@Z"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?rva000B69A1@Rva000B69A1@@QAE?AVAsciiString@@H@Z"),
	(const void *)&__identifier("?IsCRC@Xfer@@UBE_NXZ"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?ControlBarInput@@YA?AW4WindowMsgHandledType@@PAVGameWindow@@III@Z"),
	(const void *)&__identifier("?rva0050B5C6@Rva0050B5C6@@QAE_NXZ")
};

class SlaveWatcherBehaviorModuleData
{
public:
	SlaveWatcherBehaviorModuleData();

private:
	const void *m_vtable; // +0
	unsigned int m_unused04; // +4
	const char *m_grantUpgrade; // +8
	const char *m_removeUpgrade; // +0xC
	bool m_shareUpgrades; // +0x10
	bool m_letSlaveLive; // +0x11
};

// ??0SlaveWatcherBehaviorModuleData@@QAE@XZ @0x4846C7
SlaveWatcherBehaviorModuleData::SlaveWatcherBehaviorModuleData()
{
	m_vtable = reinterpret_cast<const void *>(((unsigned int)vtbl_00C4A298));
	m_grantUpgrade = 0;
	m_removeUpgrade = 0;
	m_shareUpgrades = false;
	m_letSlaveLive = false;
}
