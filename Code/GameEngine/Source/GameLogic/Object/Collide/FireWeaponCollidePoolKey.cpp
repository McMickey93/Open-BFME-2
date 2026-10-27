// cl: /DNDEBUG /MD /EHsc
// ?getModuleNameKey@FireWeaponCollide@@UBE?AW4NameKeyType@@XZ @0x4BB755
// (69B): cached pool-name key for FireWeaponCollide. The class
// identity comes from the pool-name string the body pushes
// ("FireWeaponCollide"); the body guards a function-local static
// key fetched once through TheNameKeyGenerator. It is NOT getClassMemoryPool:
// retail stores nameToKey's return (a key, not a pool pointer) and returns it,
// and the address carries no getClassMemoryPool row anywhere. /EHsc for the
// static-guard EH prologue; globals are TU-local externs (DIR32 slots patch
// from retail, no pins; nameToKey resolves via its matched row).

// The module classes spell the FireWeaponCollide.cpp TU's view, in which
// getModuleNameKey overrides primary slot 4.
class Thing;

class ModuleData;

class WeaponTemplate;

enum WeaponSlotType
{
	PRIMARY_WEAPON = 0
};

class Weapon
{
public:
	virtual void *deleteInstance(int flags);

	unsigned char m_pad04[4];
	unsigned int m_status; // +0x08
};

class WeaponStore
{
public:
	Weapon *allocateNewWeapon(const WeaponTemplate *weaponTemplate, WeaponSlotType slot) const;
};

extern WeaponStore *TheWeaponStore;

class Object
{
public:
	unsigned char m_pad[0x74];
	int m_weaponStatus; // +0x74
};

class Xfer;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

// Multiple-inheritance layout shared with the split xfer unit, so all units
// name the three vtables alike (+0x00 ObjectModule, +0x0C
// BehaviorModuleInterface, +0x10 CollideModuleInterface). Retail's primary
// vftable (0x00C5A0FC) holds the scalar deleting dtor, the shared
// loadPostProcess (0x00497805), the name getter (0x004BB6FC), xfer
// (0x004BB85C) and getModuleNameKey (0x004BB755) in slots 0-4; slots 1-2 are
// declared on BehaviorModule as its ledger rows spell them.
class ObjectModule
{
public:
	virtual ~ObjectModule();

protected:
	const ModuleData *m_moduleData;
	Object *m_object;
};

// Slot 0 of both interface vftables is retail's shared `return 0` fold
// (33 C0 C3 at 0x000D43D0); the views define it inline with that body, so
// the compiled tables name a definition of their own.
class BehaviorModuleInterface
{
public:
	virtual void *behaviorSlot() { return 0; }
};

class BehaviorModule : public ObjectModule, public BehaviorModuleInterface
{
public:
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

private:
	const FireWeaponCollideModuleData *getFireWeaponCollideModuleData() const
	{
		return reinterpret_cast<const FireWeaponCollideModuleData *>(m_moduleData);
	}

	Weapon *m_collideWeapon; // +0x14
	bool m_everFired; // +0x18
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

// ?getModuleNameKey@FireWeaponCollide@@UBE?AW4NameKeyType@@XZ
NameKeyType FireWeaponCollide::getModuleNameKey() const
{
	static NameKeyType TheFireWeaponCollidePoolKey =
		TheNameKeyGenerator->nameToKey("FireWeaponCollide");
	return TheFireWeaponCollidePoolKey;
}
