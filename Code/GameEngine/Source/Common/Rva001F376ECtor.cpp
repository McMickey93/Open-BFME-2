// cl: /MD
// ??0Rva001F376E@@QAE@XZ, RVA 0x001F376E, 80B.
// Unlock lane: no callees. Callers at 0x001F4B76/0x001F9BDD.
// Ctor storing vtable 0x007E15B4 and zeroing twelve floats at
// +0x04/+0x08/+0x0C/+0x28/+0x2C/+0x30/+0x1C/+0x20/+0x24/+0x10/+0x14/
// +0x18, int at +0x34 and byte at +0x38.
//
// A Snapshot-derived FX info record (target facts): its table 0x007E15B4 is
// the Snapshot four-slot shape of the exported FX infos beside it
// (EmissionVolumeInfo 0x007E1548, EmissionVelocityInfo 0x007E1584): slot 0
// the shared deleting dtor 0x004A10FD, slot 1 the empty LoadPostProcess fold
// 0x000B3FD0, slot 2 a getter returning "FXParticleInfo" (0x001F37BE), slot 3
// the xfer 0x001F37C4. Its destructor is the Snapshot-family fold 0x0049B47C
// (mov [ecx],0x00BBB554 / ret): with the base's empty inline destructor
// expanded, the store of the own table is dead and only Snapshot's remains;
// here likewise the base table store ahead of 0x007E15B4 is dead.
#define BFME_SNAPSHOT_CAPITALIZED_SLOTS
#define BFME_SNAPSHOT_NAME_SLOT
#define BFME_SNAPSHOT_NONCONST_NAME_SLOT
#define BFME_SNAPSHOT_REFERENCE_XFER
#include "../../../../reference/shims/moduledata/Common/Snapshot.h"

class Rva001F376E : public Snapshot
{
public:
	Rva001F376E();
	// Empty inline, as the generation loop 0x001F9BA4 destroys its local
	// record (Rva001F9BA4Generate.cpp): both units emit one destructor.
	virtual ~Rva001F376E() {}
	// Slots 1-3 stay undeclared here: their bodies are rowed under
	// placeholder names (?name@Rva001F37BENamed, ?rva001F37C4@Rva001F37C4,
	// and the 0x000B3FD0 fold), and this unit's table would reference
	// overrider names nothing defines yet.
private:
	float m_04;
	float m_08;
	float m_0c;
	float m_10;
	float m_14;
	float m_18;
	float m_1c;
	float m_20;
	float m_24;
	float m_28;
	float m_2c;
	float m_30;
	int m_34;
	unsigned char m_38;
};
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
Rva001F376E::Rva001F376E()
{
	m_04 = 0.0f;
	m_08 = 0.0f;
	m_0c = 0.0f;
	m_28 = 0.0f;
	m_2c = 0.0f;
	m_30 = 0.0f;
	m_1c = 0.0f;
	m_20 = 0.0f;
	m_24 = 0.0f;
	m_10 = 0.0f;
	m_14 = 0.0f;
	m_18 = 0.0f;
	_ReadWriteBarrier();
	m_34 = 0;
	m_38 = 0;
}
