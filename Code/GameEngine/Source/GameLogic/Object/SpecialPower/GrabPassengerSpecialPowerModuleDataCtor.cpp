// cl: /MD /DNDEBUG /DWIN32 /D_WINDOWS
//
// ??0GrabPassengerSpecialPowerModuleData@@QAE@XZ, retail 0x004C5421, 33 bytes.
// Frameless small ctor: runs the pinned opaque intermediate base ctor at
// 0x4930A0, installs vtable 0x00C5E7A8, zeroes GrabRadius at +0x7C and sets
// AllowTree at +0x80 (see the pinned buildFieldParse proc holding GrabRadius
// plus AllowTree). The TU-local base keeps an explicit vtable slot plus pad
// to 0x7C (ReflectDamage precedent, so no vtable is emitted) and the derived
// class adds plain-data members, so the body statements reproduce retail
// order: vtable literal, then the float zero (/arch:SSE keeps it as xorps
// plus movss, hoisted above the stores), then the byte. Size 0x84 matches the
// rowed 0x252088 factory news. Row supersedes the ctor pin.

extern "C" const void *const __identifier("??_7CombineHordeSpecialPowerModuleData@@6B@")[];  // folded vftable 0x00C5E7A8 (2 classes), by its data-ledger name

class SpecialPowerModuleData
{
public:
	SpecialPowerModuleData();

	void *m_vtable; // +0
	unsigned char m_pad[0x7C - 4]; // +4..0x7B
};

class GrabPassengerSpecialPowerModuleData : public SpecialPowerModuleData
{
public:
	GrabPassengerSpecialPowerModuleData();

private:
	float m_grabRadius; // +0x7C
	bool m_allowTree; // +0x80
};

// ??0GrabPassengerSpecialPowerModuleData@@QAE@XZ @0x4C5421
GrabPassengerSpecialPowerModuleData::GrabPassengerSpecialPowerModuleData()
	: SpecialPowerModuleData()
{
	m_vtable = reinterpret_cast<void *>(((unsigned int)__identifier("??_7CombineHordeSpecialPowerModuleData@@6B@")));
	m_grabRadius = 0.0f;
	m_allowTree = true;
}
