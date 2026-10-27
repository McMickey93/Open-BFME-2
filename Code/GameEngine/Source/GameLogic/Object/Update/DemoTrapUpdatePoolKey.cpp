// cl: /DNDEBUG /MD /EHsc
// ?getModuleNameKey@DemoTrapUpdate@@UBE?AW4NameKeyType@@XZ @0x495935
// (69B): cached pool-name key for DemoTrapUpdate. The class
// identity comes from the pool-name string the body pushes
// ("DemoTrapUpdate"); the body guards a function-local static
// key fetched once through TheNameKeyGenerator. It is NOT getClassMemoryPool:
// retail stores nameToKey's return (a key, not a pool pointer) and returns it,
// and the address carries no getClassMemoryPool row anywhere. /EHsc for the
// static-guard EH prologue; globals are TU-local externs (DIR32 slots patch
// from retail, no pins; nameToKey resolves via its matched row).

// The module classes spell the DemoTrapUpdate.cpp TU's union view. Vptrs at
// +0x00, +0x0C and +0x10 (the constructor's three stores). Retail's primary
// vftable (0x00C4ED3C) holds the scalar deleting dtor (0x004959E3), the
// shared loadPostProcess (0x00497805), the name getter (0x0049592F), xfer
// (0x00495A74), getModuleNameKey (0x00495935) and onObjectCreated
// (0x004959FF) in slots 0-5; UpdateModule's own (0x00BF004C) fills slots 1-2
// with loadPostProcess (0x0058B03E) and GetSnapshotName (0x002533CD). The
// +0x10 one (0x00C4ED30) opens with update (0x00495ABA).
class Thing;
class ModuleData;
class Object;
class Xfer;
class DemoTrapUpdateModuleData;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

class ObjectModule
{
public:
	ObjectModule(Thing *, const ModuleData *);
	virtual void objectModuleAnchor();			// slot 0
protected:
	const ModuleData *m_moduleData;				// +0x04
	Object *m_object;					// +0x08
};

class BehaviorInterface
{
public:
	virtual void behaviorAnchor() = 0;			// vptr at +0x0C
};

class UpdateInterface
{
public:
	virtual UpdateSleepTime update() = 0;			// vptr at +0x10
};

class UpdateModule : public ObjectModule,
	public BehaviorInterface, public UpdateInterface
{
public:
	// Defined once, out of line, in UpdateModuleCtor.cpp (retail 0x00253390).
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual void behaviorAnchor();
	void xfer(Xfer *xfer);					// 0x0044DF9F, spelled as its row
protected:
	virtual void loadPostProcess();				// slot 1
	virtual const char *GetSnapshotName() const;		// slot 2
private:
	unsigned int m_nextCallFrameAndPhase;			// +0x14
	int m_indexInLogic;					// +0x18
	int m_updateState;					// +0x1C
};

class DemoTrapUpdate : public UpdateModule
{
public:
	DemoTrapUpdate(Thing *thing, const ModuleData *moduleData);
	virtual void objectModuleAnchor();
	virtual void behaviorAnchor();
protected:
	virtual void xfer(Xfer *xfer);				// slot 3
public:
	virtual NameKeyType getModuleNameKey() const;		// slot 4
	virtual void onObjectCreated();				// slot 5
	virtual UpdateSleepTime update();
	const DemoTrapUpdateModuleData *getDemoTrapUpdateModuleData() const
	{
		return (const DemoTrapUpdateModuleData *)m_moduleData;
	}
	Object *getObject() const { return m_object; }
private:
	int m_nextScanFrames;					// +0x20
	bool m_detonated;					// +0x24
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

// ?getModuleNameKey@DemoTrapUpdate@@UBE?AW4NameKeyType@@XZ
NameKeyType DemoTrapUpdate::getModuleNameKey() const
{
	static NameKeyType TheDemoTrapUpdatePoolKey =
		TheNameKeyGenerator->nameToKey("DemoTrapUpdate");
	return TheDemoTrapUpdatePoolKey;
}

