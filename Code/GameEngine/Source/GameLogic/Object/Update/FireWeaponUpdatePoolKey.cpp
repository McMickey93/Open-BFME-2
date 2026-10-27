// cl: /DNDEBUG /MD /EHsc
// stlport
// ?getModuleNameKey@FireWeaponUpdate@@UBE?AW4NameKeyType@@XZ @0x48BDB3
// (69B): cached pool-name key for FireWeaponUpdate. The class
// identity comes from the pool-name string the body pushes
// ("FireWeaponUpdate"); the body guards a function-local static
// key fetched once through TheNameKeyGenerator. It is NOT getClassMemoryPool:
// retail stores nameToKey's return (a key, not a pool pointer) and returns it,
// and the address carries no getClassMemoryPool row anywhere. /EHsc for the
// static-guard EH prologue; globals are TU-local externs (DIR32 slots patch
// from retail, no pins; nameToKey resolves via its matched row).

#include <list>

enum NameKeyType
{
	NK_UNKNOWN = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class Thing;
class ModuleData;
class Object;
class Weapon;

typedef bool Bool;

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3FFFFFFF
};

template <int NUMBITS> class BitFlags;

// Zero Hour's UpdateModule shape, as FireWeaponUpdateCtor.cpp declares it: ObjectModule at +0, BehaviorModuleInterface
// at +0xC (retail's folded table) and UpdateModuleInterface at +0x10, whose
// table 0x00C4C18C is the rowed update 0x0048BEE8 then UpdateModule's rowed
// getDisabledTypesToProcess 0x00253376 and 0x0044DF8D. The compiler installs
// all three after the pinned UpdateModule ctor.
class ObjectModule
{
public:
	virtual void objectModuleAnchor();
protected:
	const ModuleData *m_moduleData;		// +4
	Object *m_object;					// +8
};

class BehaviorModuleInterface
{
public:
	virtual void behaviorModuleInterfaceAnchor();
};

class UpdateModuleInterface
{
public:
	virtual UpdateSleepTime update() = 0;
	virtual BitFlags<11> getDisabledTypesToProcess() const = 0;
	virtual void rva0044DF8D(UpdateSleepTime frame) = 0;
};

class UpdateModule : public ObjectModule, public BehaviorModuleInterface, public UpdateModuleInterface
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();
	virtual BitFlags<11> getDisabledTypesToProcess() const;
	virtual void rva0044DF8D(UpdateSleepTime frame);
protected:
	void setWakeFrame(Object *object, UpdateSleepTime frame);
	unsigned int m_nextCallFrameAndPhase;	// +0x14
	int m_indexInLogic;					// +0x18
	int m_reserved1C;					// +0x1C
};
class FireWeaponUpdate : public UpdateModule
{
public:
	FireWeaponUpdate(Thing *thing, const ModuleData *moduleData);
	virtual ~FireWeaponUpdate();
	virtual UpdateSleepTime update();
	virtual NameKeyType getModuleNameKey() const;
	void Rva0048BDF8Helper(void);
private:
	Weapon *m_weapon; // +0x20
	_STL::list<int> m_entries; // +0x24
	Bool m_entriesReady; // +0x28
};


// ?getModuleNameKey@FireWeaponUpdate@@UBE?AW4NameKeyType@@XZ
NameKeyType FireWeaponUpdate::getModuleNameKey() const
{
	static NameKeyType TheFireWeaponUpdatePoolKey =
		TheNameKeyGenerator->nameToKey("FireWeaponUpdate");
	return TheFireWeaponUpdatePoolKey;
}
