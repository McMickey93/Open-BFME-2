// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?findTeamByID@TeamFactory@@QAEPAVTeam@@I@Z @0x0039F761 68B
// Zero Hour TeamFactory::findTeamByID: a null id returns null; otherwise walk
// the prototype map at +0xB0 (header->left begin, rowed _M_increment
// 0x00024250, 8-byte key at +0x10, TeamPrototype at +0x18 as in the sibling
// TeamFactoryFindById.cpp) and return the first non-null
// TeamPrototype::findTeamByID (0x0039D92A). Callers: getTeamNamed 0x003584E9,
// the CaveContain/GarrisonContain/TurretAI xfers and
// AIGuardAttackAggressorState::update with ecx = TheTeamFactory.
// The prototype map as the Team.cpp seed spells it: lower_bound's header and
// node (Rva0039EA4E, 0x0039EA4E) with the TeamPrototype value at +0x18.
#include <map>
class Team;
struct Rva0039D8FBKey
{
	int m_first;
	int m_second;
};
class TeamPrototype
{
public:
	Team *findTeamByID(unsigned int id);
};
struct Rva0039EA4ENode
{
	int m_color00;
	Rva0039EA4ENode *m_parent04;
	Rva0039EA4ENode *m_left08;
	Rva0039EA4ENode *m_right0C;
	Rva0039D8FBKey m_key10;
	TeamPrototype *m_value18;
};
class Rva0039EA4E
{
public:
	Rva0039EA4ENode *rva0039EA4E(const Rva0039D8FBKey &key);
	Rva0039EA4ENode *m_header00;
};
class TeamFactory
{
public:
	Team *findTeamByID(unsigned int id);
private:
	unsigned char m_pad00[0xB0];
	Rva0039EA4E m_prototypes; // +0xB0
};
Team *TeamFactory::findTeamByID(unsigned int id)
{
	if (id == 0)
		return 0;
	Rva0039EA4ENode *node = m_prototypes.m_header00->m_left08;
	if (node != m_prototypes.m_header00) {
		do {
			Team *team = node->m_value18->findTeamByID(id);
			if (team)
				return team;
			node = (Rva0039EA4ENode *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)node);
		} while (node != m_prototypes.m_header00);
	}
	return 0;
}
