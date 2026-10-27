// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc

// ??1CommandButtonHuntUpdate@@MAE@XZ, retail 0x00495389, 73 bytes.
// Dtor lane: restores three vptrs (+0 0x0084ECFC plus +0x0C 0x007EFF90 plus
// +0x10 0x0084ECF0) then destroys AsciiString at +0x20 via pinned 0x00036410
// then calls pinned UpdateModule base dtor 0x0024A797. Layout from the rowed
// ctor 0x004952CF (UpdateModule base 0x20 plus AsciiString plus raw pointer).
// ZH donor CommandButtonHuntUpdate.cpp:94 has empty dtor. Recipe is the
// InvisibilityUpdateDtor slot pattern with String member (ProductionModifier
// AsciiString pin spelling).

// The classes spell CommandButtonHuntUpdate.cpp's views (the TU this
// dtor joins).

#include "ascii_string.h"

class Thing;
class ModuleData;
class Object;
class CommandButton;
struct CommandButtonHuntUpdateModuleData;

class Xfer;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

// UpdateModule's three vptrs (+0x00, +0x0C, +0x10) are the ones the matched
// ctor (0x004952CF) and dtor (0x00495389) store. The primary vftable's slots
// read off retail: UpdateModule's own (0x00BF004C) holds its scalar deleting
// dtor, loadPostProcess (0x0058B03E), GetSnapshotName (0x002533CD), xfer
// (0x0044DF9F) and __purecall in slot 4; CommandButtonHuntUpdate's (0x00C4ECFC)
// holds its xfer (0x004953EE) in slot 3 and getModuleNameKey (0x00495344) in
// slot 4.
class PB_DeepBase
{
public:
	PB_DeepBase(Thing *, const ModuleData *);
	virtual ~PB_DeepBase();

protected:
	const ModuleData *m_moduleData;		// +0x04
	Object *m_object;			// +0x08
};

class PB_Iface1 { public: virtual void slot(); };
class PB_Iface2 { public: virtual void slot(); };

class UpdateModule : public PB_DeepBase, public PB_Iface1, public PB_Iface2
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();

protected:
	virtual void loadPostProcess();				// slot 1
	virtual const char *GetSnapshotName() const;		// slot 2

public:
	virtual void xfer(Xfer *xfer);				// slot 3
	virtual NameKeyType getModuleNameKey() const = 0;	// slot 4

protected:
	void setWakeFrame(Object *, UpdateSleepTime);
	Object *getObject() const { return m_object; }

private:
	unsigned int m_f14;
	int m_f18;
	int m_f1c;
};

class CommandButtonHuntUpdate : public UpdateModule
{
public:
	CommandButtonHuntUpdate(Thing *, const ModuleData *);
	virtual NameKeyType getModuleNameKey() const;

protected:
	virtual ~CommandButtonHuntUpdate();
	virtual void xfer(Xfer *xfer);
	Object *scanClosestTarget();

private:
	const CommandButtonHuntUpdateModuleData *getCommandButtonHuntUpdateModuleData() const
	{
		return (const CommandButtonHuntUpdateModuleData *)m_moduleData;
	}

	AsciiString m_commandButtonName;		// +0x20
	const CommandButton *m_commandButton;		// +0x24
};

CommandButtonHuntUpdate::~CommandButtonHuntUpdate()
{
}
