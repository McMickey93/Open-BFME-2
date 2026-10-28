// cl: /O1 /DNDEBUG /MD
//
// ?rva0049C51A@Rva0049C51A@@QAEXHHHHH@Z @0x0049C51A 57B.
// Look up the id at +0x20 through GameLogic::findObjectByID. Forward the
// five arguments to 0x004500A3 when that object is missing or the byte
// at +0x69 is clear.


class Object;

#include "GameLogicObjectLookupView.h"

extern GameLogic *TheGameLogic;

// 0x004500A3 is rowed as SpecialAbilityUpdate::initiateIntentToDoSpecialPower.
class SpecialPowerTemplate;
struct Coord3D;
class Waypoint;
class SpecialAbilityUpdate
{
public:
	virtual void initiateIntentToDoSpecialPower(const SpecialPowerTemplate *specialPowerTemplate, const Object *targetObj, const Coord3D *targetPos, unsigned int commandOptions, const Waypoint *way);
};

class Rva0049C51A
{
public:
	void rva0049C51A(int specialPowerTemplate, int targetObj, int targetPos, int commandOptions, int way);

private:
	char m_pad[0x20];
	ObjectID m_id;
	char m_pad24[0x69 - 0x24];
	unsigned char m_flag69;
};

void Rva0049C51A::rva0049C51A(int specialPowerTemplate, int targetObj, int targetPos, int commandOptions, int way)
{
	Object *found = TheGameLogic->findObjectByID(m_id);
	if (found == 0 || m_flag69 == 0)
		((SpecialAbilityUpdate *)this)->SpecialAbilityUpdate::initiateIntentToDoSpecialPower((const SpecialPowerTemplate *)specialPowerTemplate, (const Object *)targetObj, (const Coord3D *)targetPos, (unsigned int)commandOptions, (const Waypoint *)way);
}
