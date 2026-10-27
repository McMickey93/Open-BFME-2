// Shared partial receiver for the matched pool-key, constructor and
// apply/remove bodies. The implementation donor proves the +0x10 secondary
// UpgradeMux receiver and ModuleData/Object operands; the constructor's four
// vptr stores prove the subobjects at +0x00, +0x0C, +0x10 and +0x18, named as
// the data ledger names StatusBitsUpgrade's vtables.
#ifndef BFME2_STATUS_BITS_UPGRADE_VIEW_H
#define BFME2_STATUS_BITS_UPGRADE_VIEW_H

enum NameKeyType { NK_UNKNOWN = 0 };

class Rva00346BC0
{
	public:
	unsigned int m_words[4];
};

class Object
{
public:
	void rva0028CDEB(const Rva00346BC0 &mask, bool set);
};

class Thing;
class ModuleData;
class BehaviorModule
{
public:
	virtual void behaviorModuleAnchor();

protected:
	const ModuleData *m_moduleData;
	Object *m_object;
	Object *getObject() const { return m_object; }
};

class BehaviorModuleInterface
{
public:
	virtual void behaviorModuleInterfaceAnchor();
};

template <int N> class StatusBitsUpgradeMuxSlots : public StatusBitsUpgradeMuxSlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};

template <> class StatusBitsUpgradeMuxSlots<0>
{
};

class UpgradeMux : public StatusBitsUpgradeMuxSlots<8>
{
protected:
	virtual void upgradeRemovalImplementation() = 0;
	virtual void setUpgradeExecuted(bool executed) = 0;
	virtual void upgradeImplementation() = 0;

private:
	bool m_upgradeExecuted; // +0x14 of the module
};

class ModuleInterface
{
public:
	virtual void moduleInterfaceAnchor();
};

class UpgradeModule : public BehaviorModule,
	public BehaviorModuleInterface,
	public UpgradeMux,
	public ModuleInterface
{
public:
	UpgradeModule(Thing *thing, const ModuleData *moduleData);
	void rva004CE4A0();
	void rva004CE4A8();
};

class StatusBitsUpgradeModuleData
{
public:
	unsigned char m_pad[0x118];
	Rva00346BC0 m_statusToSet;
	Rva00346BC0 m_statusToClear;
};

class StatusBitsUpgrade : public UpgradeModule
{
public:
	StatusBitsUpgrade(Thing *thing, const ModuleData *moduleData);
	virtual NameKeyType getModuleNameKey() const;

protected:
	virtual void upgradeRemovalImplementation();
	virtual void upgradeImplementation();
};

#endif
