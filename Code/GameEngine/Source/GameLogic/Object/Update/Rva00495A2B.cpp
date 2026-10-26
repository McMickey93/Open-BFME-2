// cl: /DNDEBUG /MD
//
// ?rva00495A2B@Rva00495A2B@@QAEXXZ, retail 0x00495A2B (73 bytes).
// Identity: unlock predicate firing a temp weapon then killing the object;
// testStatus 2 and 0x13 gate the fire, kill is Damage 8 Death 0, flag +0x24
// set. Callers in DemoTrap area; TheWeaponStore via rowed name.
#include "DemoTrapObjectView.h"
class WeaponTemplate;
class WeaponStore
{
public:
	void createAndFireTempWeapon(const WeaponTemplate *wt, const Object *obj, const Coord3D *pos);
};
extern WeaponStore *TheWeaponStore;
struct Rva00495A2B_H04
{
	unsigned char m_pad[8];
	const WeaponTemplate *m_wt08;
};
void Rva00495A2B::rva00495A2B()
{
	Object *obj = m_obj08;
	if (obj->testStatus(STATUS_UNDER_CONSTRUCTION))
		goto doKill;
	if (obj->testStatus(STATUS_SOLD))
		goto doKill;
	TheWeaponStore->createAndFireTempWeapon(m_p04->m_wt08, obj, &obj->m_pos38);
doKill:
	obj->kill(DAMAGE_8, DEATH_0);
	m_b24 = 1;
}
