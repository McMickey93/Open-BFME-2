// cl: /DNDEBUG /MD /GX
//
// ??0HordeWorkerAIUpdate@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x0049AD15,
// 134 bytes. Behavior-side ctor (rowed instance factory 0x24E560 news
// 0x3F8 with this pinned 2-arg ctor as its sole raw caller at 0x24E58A).
//
// Shape mirrors the rowed HordeAIUpdate base TU over the pinned opaque
// Transport base 0x26E9BD: the base call resolves via the rowed
// HordeAIUpdate ctor 0x49A7F3, the setWakeFrame spelling resolves via the
// Rva0026E9BDBase alias pin at 0x44DF71, and the wake frame comes from the
// int global at 0x00DBA4E4 (BfmeLogicFramesPerSecond, shared with the cold getters).
// An eax-homed int zero covers +0x3E8/+0x3EC/+0x3F0 plus the +0x3F4 byte;
// the +0x3E4 slot is re-stored. /GX for the EH prologue plus the single
// mid-body state store; the base dtor stays declared-only (no link clash
// with the base TU). Row supersedes the ctor pin.

extern "C" const void *const __identifier("??_7HordeWorkerAIUpdate@@6BDBaseM1@@@")[];  // folded vftable 0x00C50538 (2 classes), by its data-ledger name
extern "C" const void *const __identifier("??_7DozerAIUpdate@@6BAIUpdateInterface24@@@")[];  // folded vftable 0x00C52F88 (12 classes), by its data-ledger name

extern "C" const void *const __identifier("??_7HordeWorkerAIUpdate@@6BDBaseM3@@@")[];  // vftable 0x00C508B8
extern "C" const void *const __identifier("??_7HordeWorkerAIUpdate@@6BDBaseB2@@@")[];  // vftable 0x00C508BC
extern "C" const void *const __identifier("??_7HordeWorkerAIUpdate@@6BDBaseRoot@@@")[];  // vftable 0x00C508C8
extern const void *const g_00C50868[];

class Thing;
class ModuleData;
class Object;

extern int BfmeLogicFramesPerSecond;

class Rva0026E9BDBase
{
public:
	Rva0026E9BDBase(Thing *thing, const ModuleData *moduleData);
	~Rva0026E9BDBase();

protected:
	void setWakeFrame(Object *object, unsigned int frame);

	const void *m_vtable;
	const ModuleData *m_moduleData;
	Object *m_object;
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_pad14[0x20 - 0x14];
	const void *m_p20;
	const void *m_p24;
	unsigned char m_pad28[0x3E4 - 0x28];
	const void *m_p3E4;
};

class HordeAIUpdate : public Rva0026E9BDBase
{
public:
	HordeAIUpdate(Thing *thing, const ModuleData *moduleData);
};

class HordeWorkerAIUpdate : public HordeAIUpdate
{
public:
	HordeWorkerAIUpdate(Thing *thing, const ModuleData *moduleData);

private:
	unsigned int m_3E8;
	unsigned int m_3EC;
	unsigned int m_3F0;
	unsigned char m_3F4;
};

// ??0HordeWorkerAIUpdate@@QAE@PAVThing@@PBVModuleData@@@Z @0x0049AD15
HordeWorkerAIUpdate::HordeWorkerAIUpdate(Thing *thing, const ModuleData *moduleData)
	: HordeAIUpdate(thing, moduleData)
{
	int zero = 0;
	m_vtable = (const void *)((unsigned int)__identifier("??_7HordeWorkerAIUpdate@@6BDBaseRoot@@@"));
	m_p0C = (const void *)((unsigned int)__identifier("??_7HordeWorkerAIUpdate@@6BDBaseM1@@@"));
	m_p10 = (const void *)((unsigned int)__identifier("??_7HordeWorkerAIUpdate@@6BDBaseB2@@@"));
	m_p20 = (const void *)((unsigned int)__identifier("??_7HordeWorkerAIUpdate@@6BDBaseM3@@@"));
	m_p24 = (const void *)((unsigned int)__identifier("??_7DozerAIUpdate@@6BAIUpdateInterface24@@@"));
	m_p3E4 = (const void *)g_00C50868;
	m_3E8 = zero;
	m_3EC = zero;
	m_3F0 = zero;
	m_3F4 = zero;
	setWakeFrame(m_object, BfmeLogicFramesPerSecond);
}
