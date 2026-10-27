// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?teamAboutToBeDeleted@TeamFactory@@QAEXPAVTeam@@@Z, retail 0x003A3048,
// 65 bytes.
//
// Zero Hour Team.cpp TeamFactory::teamAboutToBeDeleted: every prototype in
// the factory's map hears about the team, then ThePlayerList does.
// Target evidence: TheTeamFactory (0x00E028BC) is the receiver at both
// teardown call sites (deleteTeamCallback 0x003A33A7 and
// TeamPrototype::updateState 0x003A34AC); the body walks the +0xB0
// prototype map from header->left through the rowed _M_increment
// 0x00024250 like the rowed TeamFactory finds (TeamFactoryFindById.cpp),
// calling 0x003A2CA5 on each node's +0x18 prototype with the team (pinned
// as TeamPrototype::teamAboutToBeDeleted: it walks the prototype's +0x334
// team list), and tail-calls ThePlayerList (0x00DFEEE8) member 0x002A7AFE
// when the list exists.
// The prototype map as the Team.cpp seed spells it: lower_bound's header and
// node (Rva0039EA4E, 0x0039EA4E) with the TeamPrototype value at +0x18.
#include <map>

class Team;

class TeamPrototype
{
public:
	void teamAboutToBeDeleted(Team *team);
};

struct Rva0039D8FBKey
{
	int m_first;
	int m_second;
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

class PlayerList
{
public:
	void rva002A7AFE(void *team);
};

extern PlayerList *ThePlayerList;

class TeamFactory
{
public:
	void teamAboutToBeDeleted(Team *team);

private:
	unsigned char m_pad00[0xB0];
	Rva0039EA4E m_prototypes; // +0xB0
};

void TeamFactory::teamAboutToBeDeleted(Team *team)
{
	for (Rva0039EA4ENode *it = m_prototypes.m_header00->m_left08; it != m_prototypes.m_header00;
		it = (Rva0039EA4ENode *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)it))
	{
		it->m_value18->teamAboutToBeDeleted(team);
	}
	if (ThePlayerList)
		ThePlayerList->rva002A7AFE(team);
}
