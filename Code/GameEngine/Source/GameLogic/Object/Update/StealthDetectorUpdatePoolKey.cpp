// cl: /DNDEBUG /MD /EHsc
// ?getModuleNameKey@StealthDetectorUpdate@@UBE?AW4NameKeyType@@XZ @0x4a2c74
// (69B): cached pool-name key for StealthDetectorUpdate. The class
// identity comes from the pool-name string the body pushes
// ("StealthDetectorUpdate"); the body guards a function-local static
// key fetched once through TheNameKeyGenerator. It is NOT getClassMemoryPool:
// retail stores nameToKey's return (a key, not a pool pointer) and returns it,
// and the address carries no getClassMemoryPool row anywhere. /EHsc for the
// static-guard EH prologue; globals are TU-local externs (DIR32 slots patch
// from retail, no pins; nameToKey resolves via its matched row).

// The module's class views spell the StealthDetectorUpdate TU's union
// (StealthDetectorUpdateView.h's layout, UpdateModule's slots named by
// their ledger rows).
class Object;
class Xfer;
struct StealthDetectorUpdateModuleData;

enum UpdateSleepTime { UPDATE_SLEEP_NONE = 1, UPDATE_SLEEP_FOREVER = 0x3fffffff };
enum NameKeyType { NAMEKEY_INVALID = 0 };

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};
extern NameKeyGenerator *TheNameKeyGenerator;

// The module data and object pointers sit at +0x04/+0x08 under the primary
// vptr, the other interface at +0x0C and the update interface at +0x10. The
// primary slots are UpdateModule's as its retail vftable (0x00BF004C) holds
// them: dtor, loadPostProcess (0x0058B03E), GetSnapshotName (0x002533CD),
// xfer (0x0044DF9F), __purecall for getModuleNameKey; the module's own xfer
// (0x004A2C30) sits in slot 3 and getModuleNameKey (0x004A2C74) in slot 4.
// No constructor or vftable is defined from this view.
class DetectorPrimary
{
public:
	virtual ~DetectorPrimary();
	const StealthDetectorUpdateModuleData *m_data;	// +0x04
	Object *m_object;				// +0x08
};
class DetectorOther { public: virtual void other(); };
class UpdateModuleInterface { public: virtual UpdateSleepTime update() = 0; };
class UpdateModule : public DetectorPrimary, public DetectorOther, public UpdateModuleInterface
{
protected:
	virtual void loadPostProcess();				// slot 1
	virtual const char *GetSnapshotName() const;		// slot 2
public:
	virtual void xfer(Xfer *xfer);				// slot 3
	virtual NameKeyType getModuleNameKey() const = 0;	// slot 4
protected:
	void setWakeFrame(Object *object, UpdateSleepTime wakeTime);	// rowed 0x0044DF71
};
class StealthDetectorUpdate : public UpdateModule
{
public:
	virtual UpdateSleepTime update();
	virtual NameKeyType getModuleNameKey() const;
	Object *getObject() const { return m_object; }
	const char *name() const;
protected:
	virtual void xfer(Xfer *xfer);
};

// ?getModuleNameKey@StealthDetectorUpdate@@UBE?AW4NameKeyType@@XZ
NameKeyType StealthDetectorUpdate::getModuleNameKey() const
{
	static NameKeyType TheStealthDetectorUpdatePoolKey =
		TheNameKeyGenerator->nameToKey("StealthDetectorUpdate");
	return TheStealthDetectorUpdatePoolKey;
}

