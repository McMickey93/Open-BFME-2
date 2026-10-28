// cl: /DNDEBUG /MD /GX
//
// ??0AimWeaponBehavior@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x0045B226,
// 85 bytes. Behavior-side ctor completing the AimWeaponBehavior file-unit
// (poolkey rowed at 0x45B198, proc rowed at 0x45B215, ModuleData factory
// rowed at 0x24B0F7, ModuleData ctor rowed at 0x45B1DD, behavior factory
// rowed at 0x24B0BF news 0x24 with this pinned 2-arg ctor).
//
// StealthDetector-mirror recipe (StealthDetectorUpdateCtor.cpp): UpdateModule
// is 0x20 (BehaviorModule pair plus UpdateModuleInterface plus three ints,
// per UpdateModuleCtor.cpp); the derived re-installs its three vtables at
// +0/+0xC/+0x10, clears its flag byte at +0x20, then wakes next frame with
// setWakeFrame(getObject(), 1) via the rowed UpdateModule base and the
// pinned 0x44DF71. Zero new pins (all callees rowed/pinned).

class Thing;
class ModuleData;
class Object;
class Xfer;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3FFFFFFF
};

class ObjectModule
{
public:
	ObjectModule(Thing *, const ModuleData *);
	virtual ~ObjectModule();
protected:
	const ModuleData *m_moduleData;
	Object *m_object;
};

class BehaviorModuleInterface { public: virtual void behaviorSlot(); };

class UpdateModuleInterface { public: virtual UpdateSleepTime update(); };

class UpdateModule : public ObjectModule,
	public BehaviorModuleInterface, public UpdateModuleInterface
{
public:
	UpdateModule(Thing *thing, const ModuleData *data);
	virtual ~UpdateModule();
	void xfer(Xfer *xfer);

protected:
	void setWakeFrame(Object *obj, UpdateSleepTime frame);

private:
	unsigned int m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_updateState;
};

class AimWeaponBehaviorModuleData
{
public:
	AimWeaponBehaviorModuleData();

private:
	const void *m_vtable; // +0
	unsigned int m_unused04; // +4 (retail never stores it)

public:
	float m_aimLowThreshold; // +8
	float m_aimHighThreshold; // +0xC
	float m_aimNearDistance; // +0x10
	float m_aimFarDistance; // +0x14
};

class AimWeaponBehavior : public UpdateModule
{
public:
	AimWeaponBehavior(Thing *thing, const ModuleData *moduleData);
	virtual ~AimWeaponBehavior();
	virtual NameKeyType getModuleNameKey() const;
	virtual UpdateSleepTime update();

private:
	const Object *getObject() const { return m_object; }
	const AimWeaponBehaviorModuleData *getAimWeaponBehaviorModuleData() const
	{
		return (const AimWeaponBehaviorModuleData *)m_moduleData;
	}

	bool m_isAiming; // +0x20
};

// ??0AimWeaponBehavior@@QAE@PAVThing@@PBVModuleData@@@Z @0x0045B226
AimWeaponBehavior::AimWeaponBehavior(Thing *thing, const ModuleData *moduleData) :
	UpdateModule(thing, moduleData)
{
	m_isAiming = false;
	setWakeFrame(const_cast<Object*>(getObject()), UPDATE_SLEEP_NONE);
}

// ??1AimWeaponBehavior@@UAE@XZ @0x0045B134 (formerly the placeholder
// Rva0045B134 in Rva0024A797Derived.cpp: vftable 0x00C418CC slot 0 is its
// deleting dtor 0x0045B27B, which calls 0x0045B134).
AimWeaponBehavior::~AimWeaponBehavior()
{
}
