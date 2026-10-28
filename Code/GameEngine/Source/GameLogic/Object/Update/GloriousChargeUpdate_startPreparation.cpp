// cl: /DNDEBUG /MD
// Retail 0x004AD554 (56 bytes): ?startPreparation@GloriousChargeUpdate@@UAEXXZ.
// Identity: slot 15 of the primary vtable 0x00C55118 that the matched
// GloriousChargeUpdate dtor 0x004AD58C installs (slot 0 is the matched
// ??_GGloriousChargeUpdate, slot 4 its pool key). Its base is
// SpecialAbilityUpdate: the base vtable 0x00C3FBA8 has the matched
// ??_GSpecialAbilityUpdate, xfer and pool key in slots 0/3/4 and holds
// 0x00450D9A in slot 15, which this override calls first as the base
// implementation (pinned here as ?startPreparation@SpecialAbilityUpdate@@UAEXXZ).
// Names by address: the slot name is not established.
// Body: base call, set condition bit 6*32+15 on the Object, then OR 0x10 into
// the +0x118 word of its Drawable (pinned getDrawable 0x005508E2).
//
// Model-condition bits: the word array of the Object starts at +0x10C (the
// variable-index set/test in 0x00293A05 addresses [obj + word*4 + 0x10C]); a
// bit index is word*32 + bit. The accessors return the masked word rather
// than a bool and the update is a free __forceinline helper that calls the
// pinned condition-changed notifier 0x0028AE6D (?rva0028AE6D@Object@@QAEXXZ)
// only when the bit changed; this is the BFME1 HordeGarrisonContainCtor.cpp
// recipe (mask in a register and test/or on the member for a set, byte-narrowed
// test/and for a clear). With the array based at +0x110 instead, a word-0 access
// keeps the array address in a register (lea), which retail never does.
// The class views are GloriousChargeUpdateUpdate.cpp's.

#include "../../../../../../reference/shims/bfme2_ascii/ascii_string.h"

class Drawable;
class Rva0010CConditionBits
{
public:
	unsigned int test(int bit) const
	{
		return m_words[bit >> 5] & (1U << (bit & 0x1f));
	}
	void set(int bit)
	{
		m_words[bit >> 5] |= 1U << (bit & 0x1f);
	}
	void clear(int bit)
	{
		m_words[bit >> 5] &= ~(1U << (bit & 0x1f));
	}
private:
	unsigned int m_words[20];
};
#include "../../../Common/GameLogicObjectLookupView.h"
enum KindOfType
{
	KINDOF_FIRST = 0
};
#include "../../../../../Libraries/Include/Lib/Coord3D.h"
class Object
{
public:
	void rva0028AE6D();
	bool addAttributeModifierToPool(const AsciiString &name, int n);
	Drawable *getDrawable() const;
	bool isKindOf(KindOfType t) const;
	const Coord3D *getPosition() const { return &m_pos; }
	ObjectID getID() const { return m_id; }
	unsigned char m_pad000[0x38];
	Coord3D m_pos; // +0x38
	unsigned char m_pad044[0x74 - 0x44];
	ObjectID m_id; // +0x74
	unsigned char m_pad078[0x10C - 0x78];
	Rva0010CConditionBits m_conditionBits; // +0x10C
	unsigned char m_pad15C[0x44C - 0x15C];
	int m_44C; // +0x44C
};
static __forceinline void clearModelConditionBit(Object *object, int bit)
{
	if (object->m_conditionBits.test(bit) != 0)
	{
		object->m_conditionBits.clear(bit);
		object->rva0028AE6D();
	}
}
static __forceinline void setModelConditionBit(Object *object, int bit)
{
	if (object->m_conditionBits.test(bit) == 0)
	{
		object->m_conditionBits.set(bit);
		object->rva0028AE6D();
	}
}
// The Drawable word 0x004AD8E3 sets bit 3 of.
struct Rva004AD8E3Drawable
{
	unsigned char m_pad[0x118];
	unsigned int m_118; // +0x118
};
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
void GloriousChargeUpdate::startPreparation()
{
	SpecialAbilityUpdate::startPreparation();
	setModelConditionBit(m_object, 6 * 32 + 15);
	Drawable *draw = m_object->getDrawable();
	if (draw)
		((Rva004AD8E3Drawable *)draw)->m_118 |= 0x10;
}
