// Shared, TU-scoped RadiusDecalUpdate view (the RadiusDecalUpdate.cpp TU and
// the donors that join it).
// Target constructor and destructor prove the base span 0x20, decal span 0x10
// and later flag at +0x30. The create body reads the decal byte at +0x28,
// distinct from that flag; RadiusDecal::clear/ctor establish its empty byte.
// The three vptrs sit at +0x00, +0x0C and +0x10 (the dtor's stores). The
// vftables read off retail: the primary one (0x00C1A018) holds the scalar
// deleting dtor, loadPostProcess, the name getter, xfer (0x003915AE) and
// getModuleNameKey (0x00391445) in slots 0-4, the slots UpdateModule's own
// (0x00BF004C) fills with loadPostProcess (0x0058B03E), GetSnapshotName
// (0x002533CD), xfer (0x0044DF9F) and __purecall; the +0x10 one (0x00C1A00C)
// starts with update (0x0039157B). These declarations do not establish
// original BFME 2 header names or a canonical class.
#ifndef BFME_RADIUS_DECAL_UPDATE_VIEW_H
#define BFME_RADIUS_DECAL_UPDATE_VIEW_H

class Thing;
class ModuleData;
class Object;
class Player;
class Xfer;
struct Coord3D;

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3FFFFFFF
};

enum NameKeyType
{
	NK_UNKNOWN = 0
};

enum ObjectStatusTypes
{
	OBJECT_STATUS_IS_ATTACKING = 0x16
};

class Object
{
public:
    Player *getControllingPlayer() const;
	bool testStatus( ObjectStatusTypes bit ) const;
};

class RadiusDecal;

class RadiusDecalTemplate
{
public:
    void createRadiusDecal(const Coord3D &, float, const Player *, RadiusDecal &) const;
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/Module.h
class ObjectModule
{
public:
	ObjectModule(Thing *, const ModuleData *);
	virtual ~ObjectModule();

protected:
	const ModuleData *m_moduleData;
	Object *m_object;
	Object *getObject() const { return m_object; }
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h
class UpdateModuleInterface
{
public:
	virtual void updateModuleInterfaceAnchor();
};

class ModuleInterface
{
public:
	virtual UpdateSleepTime update() = 0;	// slot 0 of the +0x10 vftable
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/UpdateModule.h
class UpdateModule : public ObjectModule, public UpdateModuleInterface, public ModuleInterface
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

private:
	unsigned int m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_updateState;
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameClient/RadiusDecal.h
class RadiusDecal
{
    friend class RadiusDecalUpdate;
public:
	RadiusDecal();
	~RadiusDecal();
	void clear();
	void update();
	void rva00330F7D(Xfer *xfer);

private:
	const void *m_template;
	void *m_decal;
	unsigned char m_empty;
	unsigned char m_pad[4];
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/RadiusDecalUpdate.h
class RadiusDecalUpdate : public UpdateModule
{
public:
	RadiusDecalUpdate(Thing *, const ModuleData *);
	virtual ~RadiusDecalUpdate();
	virtual NameKeyType getModuleNameKey() const;
	virtual UpdateSleepTime update();
    void createRadiusDecal(const RadiusDecalTemplate &, float, const Coord3D &);
    void killRadiusDecal();

protected:
	virtual void xfer(Xfer *xfer);

private:
	RadiusDecal m_deliveryDecal;		// +0x20
	bool m_killWhenNoLongerAttacking;	// +0x30
};


#endif
