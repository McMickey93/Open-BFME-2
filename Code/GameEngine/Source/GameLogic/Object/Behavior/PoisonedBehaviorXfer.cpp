// cl: /MD
//
// ?xfer@PoisonedBehavior@@MAEXPAVXfer@@@Z, retail 0x004830A9, 82 bytes.
// Slot 3 (offset 0x0C) of vtable 0x008498BC (class of ??1PoisonedBehavior
// rowed at 0x00482ED9 in PoisonedBehaviorDtor.cpp).
//
// Donor: BFME1 PoisonedBehavior.cpp xfer plus ZH PoisonedBehavior.cpp xfer
// (version 2 with xferUnsignedInt/xferReal/xferUser). BFME2 repairs: base
// UpdateModule xfer via rowed 0x0044DF9F, IsLightCRC early-out via Xfer slot
// 0x10, Version1 via rowed 0x000053EE, then uint at +0x24 plus uint at +0x28
// via Xfer slot 0x78, float at +0x2C via Xfer slot 0x70, DeathType at +0x30
// via rowed XferDeathType 0x00305F02. Layout is the rowed PoisonedBehavior
// class from PoisonedBehaviorCtor.cpp (UpdateModule base 0x20 plus
// DamageModuleInterface at +0x20 giving +0x24 start). Recipe is the
// SlowDeathBehaviorXfer/OneRingPenaltyUpdateXfer slot-3 pattern.

class AsciiString;
class UnicodeString;
class PooledString;
struct XferUnknown11;
class Coord3DBase;
class ICoord3D;
class Region3D;
class IRegion3D;
class Coord2D;
class ICoord2D;
class Region2D;
class IRegion2D;
class RealRange;
class RGBColor;
class RGBAColorReal;
class RGBAColorInt;
class Snapshot;
class Thing;
class ModuleData;
class Object;
class DamageInfo;

#include "../../../../Include/Common/BfmeXfer.h"

void XferDeathType(Xfer *xfer, int *value);

// The module classes spell the PoisonedBehavior.cpp TU's union view.
class Xfer;
class PoisonedBehaviorModuleData;
enum BodyDamageType;

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

enum NameKeyType
{
	NK_UNKNOWN = 0
};

// Vptrs at +0x00, +0x0C, +0x10 and +0x20 (the dtor's four stores). The
// primary vftable (0x00C498BC) holds the scalar deleting dtor, the shared
// loadPostProcess, the name getter, xfer (0x004830A9) and getModuleNameKey
// (0x00482F27) in slots 0-4, the slots UpdateModule's own (0x00BF004C) fills
// with loadPostProcess (0x0058B03E), GetSnapshotName (0x002533CD), xfer
// (0x0044DF9F) and __purecall; the +0x10 one (0x00C497F4) starts with update
// (0x00483133), the +0x20 one (0x00C497E8) with onDamage and onHealing.
class BehaviorModuleBase
{
public:
	virtual ~BehaviorModuleBase();
	const ModuleData *m_moduleData;
	Object *m_object;
};

class BehaviorModuleOther
{
public:
	virtual void behaviorModuleOtherAnchor();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};

class UpdateModuleInterface
{
public:
	virtual UpdateSleepTime update() = 0;
};

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
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
	UpdateSleepTime frameToSleepTime(unsigned int frame1, unsigned int frame2 = UPDATE_SLEEP_FOREVER, unsigned int frame3 = UPDATE_SLEEP_FOREVER, unsigned int frame4 = UPDATE_SLEEP_FOREVER);
	void setWakeFrame(Object *obj, UpdateSleepTime wakeDelay);
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;
};

class DamageModuleInterface
{
public:
	DamageModuleInterface() {}
	virtual void onDamage(DamageInfo *damageInfo) = 0;
	virtual void onHealing(DamageInfo *damageInfo) = 0;
	virtual void onBodyDamageStateChange(
		const DamageInfo *damageInfo, BodyDamageType oldState, BodyDamageType newState) = 0;
};

class PoisonedBehavior : public UpdateModule, public DamageModuleInterface
{
public:
	PoisonedBehavior(Thing *thing, const ModuleData *moduleData);
	virtual NameKeyType getModuleNameKey() const;
	virtual UpdateSleepTime update();
	virtual void onDamage(DamageInfo *damageInfo);
	virtual void onHealing(DamageInfo *damageInfo);
	virtual void onBodyDamageStateChange(
		const DamageInfo *damageInfo, BodyDamageType oldState, BodyDamageType newState) {}
	void rva00483083(); // stopPoisonedEffects
protected:
	virtual ~PoisonedBehavior();
	virtual void xfer(Xfer *xfer);
	void startPoisonedEffects(const DamageInfo *damageInfo);
	UpdateSleepTime calcSleepTime();
	const PoisonedBehaviorModuleData *getPoisonedBehaviorModuleData() const { return (const PoisonedBehaviorModuleData *)m_moduleData; }
	Object *getObject() const { return m_object; }
private:
	unsigned int m_poisonDamageFrame;	// +0x24
	unsigned int m_poisonOverallStopFrame;	// +0x28
	float m_poisonDamageAmount;		// +0x2C
	int m_deathType;			// +0x30
};

void PoisonedBehavior::xfer(Xfer *xfer)
{
	UpdateModule::xfer(xfer);
	if (xfer->IsLightCRC())
		return;
	xfer->Version1();
	*xfer == m_poisonDamageFrame;
	*xfer == m_poisonOverallStopFrame;
	*xfer == m_poisonDamageAmount;
	XferDeathType(xfer, &m_deathType);
}
