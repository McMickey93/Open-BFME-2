// cl: /MD
// ?xfer@WeaponFireSpecialAbilityUpdate@@MAEXPAVXfer@@@Z @ 0x004925E5 160B: slot 3.
// BFME1 donor WeaponFireSpecialAbilityUpdate_xfer.cpp reuse: Version(1,2) via
// slot 0x28 then base SpecialAbilityUpdate xfer via rowed 0x0044F996 then IsCRC
// via slot 0x0C then version>=2 bool weaponPresent at +0x88 via slot 0x90 then
// IsStoring via slot 0x08 then WeaponFireSpecialWeapon block via slots
// 0x14/0x30/0x18 else skip via 0x1C. Evidence: donor plus vtable 0x0084E090
// slot 3 plus string plus rowed base.
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

class SpecialAbilityUpdate
{
public:
	virtual ~SpecialAbilityUpdate();

protected:
	virtual void xfer(Xfer *xfer);

private:
	char m_pad04[0x88 - 0x04];
};

class WeaponFireSpecialAbilityUpdate : public SpecialAbilityUpdate
{
protected:
	virtual void xfer(Xfer *xfer);

private:
	Snapshot *m_weapon88;
};

void WeaponFireSpecialAbilityUpdate::xfer(Xfer *xfer)
{
	Xfer::Version version(1, 2);
	*xfer == version;
	SpecialAbilityUpdate::xfer(xfer);
	if (xfer->IsCRC())
		return;
	if (version.m_minimum < 2)
		return;
	bool weaponPresent = m_weapon88 != 0;
	*xfer == weaponPresent;
	if (!weaponPresent)
		return;
	if (xfer->IsStoring() || m_weapon88 != 0) {
		xfer->BeginBlock("WeaponFireSpecialWeapon");
		*xfer == *m_weapon88;
		xfer->EndBlock();
	} else {
		xfer->SkipBlock("WeaponFireSpecialWeapon");
	}
}
