// cl: /DNDEBUG /MD /GX
// ?shouldFireWeapon@FireWeaponCollide@@MAE_NXZ @0x004BB8BA 94B. Virtual slot
// 12 offset 0x30 of vtable 0x0085A0FC class of ??1FireWeaponCollide@@UAE@XZ.
// Status-mask overlap via rowed ?test@Rva00331682Holder 0x00331682 plus copy
// 0x002CF108 plus inverted-required check plus everFired at +0x18 and
// fireOnce at module +0x2C. Donor BFME1 FireWeaponCollide.cpp
// shouldFireWeapon plus ZH FireWeaponCollide.h. Follow retail order
// forbidden then required.
class Thing;

class ModuleData;

class WeaponTemplate;

// The class views are FireWeaponCollide.cpp's, so this body merges into it.
class Weapon
{
public:
	virtual void *deleteInstance(int flags);

	unsigned char m_pad04[4];
	unsigned int m_status; // +0x08
};

class BfmeObject872Header
{
public:
	BfmeObject872Header(const BfmeObject872Header &other);
	int m_vals[4];
};

class Rva00331682Holder
{
public:
	bool test(const void *other) const;
	int m_vals[4];
};

class Object
{
public:
	unsigned char m_pad[0x74];
	int m_weaponStatus; // +0x74
	unsigned char m_pad78[0x1C];
	BfmeObject872Header m_status; // +0x94
};

class Xfer;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

class ObjectModule
{
public:
	virtual ~ObjectModule();

protected:
	const ModuleData *m_moduleData;
	Object *m_object;
};

class BehaviorModuleInterface
{
public:
	virtual void *behaviorSlot() { return 0; }
};

class BehaviorModule : public ObjectModule, public BehaviorModuleInterface
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
	virtual ~BehaviorModule() {}

protected:
	virtual void loadPostProcess();				// slot 1
	virtual const char *GetSnapshotName() const;		// slot 2
};

class CollideModuleInterface
{
public:
	virtual void *collideSlot() { return 0; }
};

class CollideModule : public BehaviorModule, public CollideModuleInterface
{
public:
	CollideModule(Thing *thing, const ModuleData *moduleData);
	virtual ~CollideModule();
};

class FireWeaponCollideModuleData
{
public:
	unsigned char m_pad[8];
	const WeaponTemplate *m_collideWeaponTemplate; // +0x08
	Rva00331682Holder m_required; // +0x0C
	Rva00331682Holder m_forbidden; // +0x1C
	bool m_fireOnce; // +0x2C
};

class FireWeaponCollide : public CollideModule
{
public:
	FireWeaponCollide(Thing *thing, const ModuleData *moduleData);
	virtual ~FireWeaponCollide();

protected:
	virtual void xfer(Xfer *xfer);				// slot 3

public:
	virtual NameKeyType getModuleNameKey() const;		// slot 4

protected:
	virtual bool shouldFireWeapon();			// retail slot 12

private:
	const FireWeaponCollideModuleData *getFireWeaponCollideModuleData() const
	{
		return reinterpret_cast<const FireWeaponCollideModuleData *>(m_moduleData);
	}

	Weapon *m_collideWeapon; // +0x14
	bool m_everFired; // +0x18
};

bool FireWeaponCollide::shouldFireWeapon()
{
	const FireWeaponCollideModuleData *data = getFireWeaponCollideModuleData();
	BfmeObject872Header tmp(m_object->m_status);
	if (data->m_forbidden.test(&tmp))
		return false;
	for (unsigned i = 0; i < 4; ++i)
		tmp.m_vals[i] = ~tmp.m_vals[i];
	if (data->m_required.test(&tmp))
		return false;
	if (m_everFired && data->m_fireOnce)
		return false;
	return true;
}
