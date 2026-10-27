// cl: /DNDEBUG /MD
//
// ??0ToggleMountedSpecialAbilityUpdate@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x004ADAB5, 74 bytes.
// ToggleMountedSpecialAbilityUpdate behavior ctor over the pinned Rva0044EF5E
// intermediate base (0x44EF5E, thing plus data): sets the +0x88 slot from its
// base form to its final form (DIR32-masked provisional table symbols;
// the barrier pins both stores so retail keeps the lea plus double through-
// eax shape), then re-stores the primary vtable slot and the +0x0C/+0x10/
// +0x20 secondary slots (provisional table addresses, DIR32-masked), then
// clears a flag at +0x8C. The rowed name getter at 0x4ADA70 and ModuleData
// factory 0x24F6C5 prove the class; the rowed instance factory 0x24F68A is
// the sole raw caller. Row supersedes the ctor pin.

class Thing;
class ModuleData;

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

static int s_slotBase;
static int s_vtable;
static int s_secondary10;

// The data ledger assigns these provisional table symbols to ModuleUpdateDtors.
// Share those definitions rather than allocating another datum for each table.
extern "C"
{
	extern int s_dummy5188;
	extern int s_dummy5198;
	extern const void *const s_dummy62D8[47];
}

// Opaque intermediate base; ctor resolves to its pin. The explicit m_vtable
// member stands in for the inherited vptr so body order is source order.
class Rva0044EF5E
{
public:
	Rva0044EF5E(Thing *thing, const ModuleData *moduleData);

protected:
	const void *m_vtable;
	Thing *m_owner;
	int m_pad08;
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_pad[0x20 - 0x14];
};

class ToggleMountedSpecialAbilityUpdate : public Rva0044EF5E
{
public:
	ToggleMountedSpecialAbilityUpdate(Thing *thing, const ModuleData *moduleData);

private:
	const void *m_p20;
	unsigned char m_pad24[0x88 - 0x24];
	union
	{
		const void *m_slotBase;
		const void *m_slotFinal;
	};
	bool m_flag;
};

// ??0ToggleMountedSpecialAbilityUpdate@@QAE@PAVThing@@PBVModuleData@@@Z @0x4ADAB5
ToggleMountedSpecialAbilityUpdate::ToggleMountedSpecialAbilityUpdate(Thing *thing, const ModuleData *moduleData)
	: Rva0044EF5E(thing, moduleData)
{
	m_slotBase = &s_slotBase;
	_ReadWriteBarrier();
	m_slotFinal = &s_dummy5188;
	m_vtable = &s_vtable;
	m_p0C = s_dummy62D8;
	m_p10 = &s_secondary10;
	m_p20 = &s_dummy5198;
	m_flag = false;
}
