// cl: /DNDEBUG /MD
//
// ?xfer@GloriousChargeUpdate@@MAEXPAVXfer@@@Z, retail 0x004AD890, 83 bytes.
// Slot 3 of the vftable 0x00C55118 whose slot-2 name getter returns
// "GloriousChargeUpdate" (the rowed dtor 0x004AD58C installs it). The rowed
// SpecialAbilityUpdate::xfer 0x0044F996 first, the light-CRC out, Version1,
// the ObjectID list at +0x88 (pinned xferSTLObjectIDList 0x00331F2D), a
// bool at +0x90 and an unsigned int at +0x8C. Member names not recovered;
// the class views are GloriousChargeUpdateUpdate.cpp's.

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

#include "../../../../Include/Common/BfmeXfer.h"

class Xfer::Version
{
public:
	Version(unsigned char current, unsigned char minimum)
		: m_current(current), m_minimum(minimum) {}

	unsigned char m_current;
	unsigned char m_minimum;
};

#include "../../../Common/GameLogicObjectLookupView.h"

void XferObjectID(Xfer *xfer, ObjectID *id);

struct BridgeBehaviorObjectIDNode
{
	BridgeBehaviorObjectIDNode *m_next;
	BridgeBehaviorObjectIDNode *m_previous;
	ObjectID m_value;
};

class BridgeBehaviorObjectIDList
{
public:
	void push_back(const ObjectID &value);
	BridgeBehaviorObjectIDNode *m_node;
};

Xfer *xferSTLObjectIDList(Xfer *xfer, BridgeBehaviorObjectIDList *list);

struct Rva004AD613Node
{
	Rva004AD613Node *m_next;
	Rva004AD613Node *m_prev;
	ObjectID m_id;
};
struct Rva004AD613Iterator
{
	Rva004AD613Node *m_node;
	ObjectID &operator*() const { return m_node->m_id; }
	Rva004AD613Iterator &operator++() { m_node = m_node->m_next; return *this; }
	bool operator!=(const Rva004AD613Iterator &other) const { return m_node != other.m_node; }
};
// Native2A1B6F and its whole insertion helper copy one opaque four-byte
// element into a 12-byte list node; they never dereference the word as a
// pointer. Reuse that existing owner for these ObjectID payloads.
class Rva002A1B6FNativeList { public: void append(void *const &value); };

class Rva0029FB3BMember
{
public:
	bool empty() const { return m_head->m_next == m_head; }
	Rva004AD613Iterator begin() const { Rva004AD613Iterator it; it.m_node = m_head->m_next; return it; }
	Rva004AD613Iterator end() const { Rva004AD613Iterator it; it.m_node = m_head; return it; }
	void reset();
	Rva004AD613Node *m_head;
};
class Thing;
class ModuleData;
class Xfer;
enum NameKeyType
{
	NK_UNKNOWN = 0
};
class BehaviorModule
{
public:
	virtual ~BehaviorModule();
protected:
	const ModuleData *m_moduleData; // +0x04
	Object *m_object; // +0x08
};
class BehaviorModuleInterface
{
public:
	virtual void behaviorModuleInterfaceAnchor();
};
enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1,
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};
class UpdateModuleInterface
{
public:
	virtual UpdateSleepTime update() = 0;
};
class UpdateModule : public BehaviorModule, public BehaviorModuleInterface, public UpdateModuleInterface
{
protected:
	unsigned int m_14;
	int m_18;
	int m_1C;
};
class SpecialPowerUpdateInterface
{
public:
	virtual void specialPowerUpdateAnchor();
};
// Primary-vtable slots 1..17 of SpecialAbilityUpdate (vtable 0x00C3FBA8):
// xfer 0x0044F996 in slot 3 and the pool key in slot 4; only the positions
// of slots 15 and 17 matter to update().
class SpecialAbilityUpdate : public UpdateModule, public SpecialPowerUpdateInterface
{
public:
	virtual void slot01(); virtual void slot02();
protected:
	virtual void xfer(Xfer *xfer); // slot 3
public:
	virtual NameKeyType getModuleNameKey() const; // slot 4
	virtual void slot05(); virtual void slot06();
	virtual void slot07(); virtual void slot08(); virtual void slot09();
	virtual void slot10(); virtual void slot11(); virtual void slot12();
	virtual void slot13(); virtual void slot14();
	virtual void startPreparation(); // slot 15; 0x00450D9A, GloriousChargeUpdate 0x004AD554
	virtual void slot16();
	virtual void triggerAbilityEffect(); // slot 17; GloriousChargeUpdate 0x004AD8E3
private:
	unsigned char m_pad24[0x88 - 0x24];
};
class SpecialAbilityUpdateModuleData
{
public:
	SpecialAbilityUpdateModuleData();

private:
	unsigned char m_pad[0xC8];
};
class GloriousChargeUpdateModuleData : public SpecialAbilityUpdateModuleData
{
public:
	GloriousChargeUpdateModuleData();

	float m_bonusRadius; // +0xC8
	int m_speechDuration; // +0xCC
	int m_updateInterval; // +0xD0
};
class GloriousChargeUpdate : public SpecialAbilityUpdate
{
public:
	virtual NameKeyType getModuleNameKey() const;
	virtual void startPreparation();
	void rva004AD613();
	void rva004AD7B6();
	virtual void triggerAbilityEffect();
	virtual UpdateSleepTime update();
protected:
	virtual void xfer(Xfer *xfer);
private:
	const GloriousChargeUpdateModuleData *getGloriousChargeData() const
	{
		return (const GloriousChargeUpdateModuleData *)m_moduleData;
	}
	Rva0029FB3BMember m_88; // +0x88
	unsigned int m_8C; // +0x8C
	bool m_90; // +0x90
};

// ?xfer@GloriousChargeUpdate@@MAEXPAVXfer@@@Z @0x004AD890
void GloriousChargeUpdate::xfer(Xfer *xfer)
{
	SpecialAbilityUpdate::xfer(xfer);

	if (xfer->IsLightCRC())
		return;

	xfer->Version1();
	xferSTLObjectIDList(xfer, reinterpret_cast<BridgeBehaviorObjectIDList *>(&m_88));
	*xfer == m_90;
	*xfer == m_8C;
}
