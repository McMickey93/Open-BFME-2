// cl: /DNDEBUG /MD

typedef bool Bool;

class Thing;
class ModuleData;
class Object;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h
// Slot 0 of the primary vtable 0x00857E30 is the scalar deleting dtor.
class BehaviorModule
{
public:
	virtual ~BehaviorModule();

protected:
	Object *getObject() const { return m_object; }

private:
	const ModuleData *m_moduleData; // +0x04
	Object *m_object; // +0x08
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/BehaviorModule.h
class BehaviorModuleInterface
{
public:
	virtual void behaviorModuleInterfaceAnchor();
};

template <int N> class UpgradeMuxSlots : public UpgradeMuxSlots<N - 1>
{
public:
	virtual void gap(char (*)[N]) = 0;
};
template <> class UpgradeMuxSlots<0>
{
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpgradeModule.h
// The +0x10 interface (vtable 0x00857DE8): slot 8 upgradeRemovalImplementation,
// slot 9 setUpgradeExecuted (the rowed UpgradeMux::rva00452354), slot 10
// upgradeImplementation.
class UpgradeMux : public UpgradeMuxSlots<8>
{
protected:
	virtual void upgradeRemovalImplementation() = 0;
	virtual void setUpgradeExecuted(Bool executed) = 0;
	virtual void upgradeImplementation() = 0;

private:
	Bool m_upgradeExecuted; // +0x14
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
	UpgradeModule( Thing *thing, const ModuleData *moduleData );
protected:
	virtual ~UpgradeModule();
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/StealthUpgrade.h
// 0x1C bytes (friend_newModuleInstance news 0x1C).
class StealthUpgrade : public UpgradeModule
{
public:
	StealthUpgrade( Thing *thing, const ModuleData *moduleData );
	const char *name() const;
	virtual NameKeyType getModuleNameKey() const;
protected:
	virtual ~StealthUpgrade();
	virtual void upgradeRemovalImplementation();
	virtual void upgradeImplementation();
};
enum ObjectStatusTypes
{
	OBJECT_STATUS_CAN_STEALTH = 0x12
};
class Object
{
public:
	void setStatus(ObjectStatusTypes status, bool set);
};

// StealthUpgrade::upgradeImplementation, retail 0x004B53C5 (13 bytes), and
// StealthUpgrade::upgradeRemovalImplementation, retail 0x004B53D2 (13 bytes): slots 10 and
// 8 of the +0x10 UpgradeMux vtable 0x00C57DE8 installed by the matched StealthUpgrade
// ctor (slot 9 is setUpgradeExecuted, the rowed UpgradeMux::rva00452354).
// Bodies: set and clear object status 0x12 (the Zero Hour OBJECT_STATUS_CAN_STEALTH setStatus
// of StealthUpgrade.cpp, here through the rowed setStatus(ObjectStatusTypes, bool)).
void StealthUpgrade::upgradeImplementation()
{
	// The logic that does the stealthupdate will notice this and start stealthing
	Object *me = getObject();
	me->setStatus(OBJECT_STATUS_CAN_STEALTH, true);
}
void StealthUpgrade::upgradeRemovalImplementation()
{
	Object *me = getObject();
	me->setStatus(OBJECT_STATUS_CAN_STEALTH, false);
}
