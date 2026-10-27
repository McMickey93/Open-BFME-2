// cl: /DNDEBUG /MD
// ?rva0039F0D2@Team@@QAE_NXZ @0x0039F0D2 17B
// Team bool getter through +0x118: returns (m_map->m_14 != 0).
// Evidence: prev/next Team rows; Team+0x118 is the team-override map per
// TeamGetControllingPlayer.cpp; caller at 0x0028E82B tests al.
class TeamRelationMap;
class PlayerRelationMap;

// Both relation maps are read through this one view.
struct TeamMapInner
{
	unsigned char m_pad00[0x14];
	int m_14;
};

class Team
{
public:
	bool rva0039F0D2();
	bool rva0039F824();
private:
	unsigned char m_pad00[0x118];
	TeamRelationMap *m_teamRelations;
	PlayerRelationMap *m_playerRelations;
};

bool Team::rva0039F0D2()
{
	return ((TeamMapInner *)m_teamRelations)->m_14 != 0;
}

bool Team::rva0039F824()
{
	return ((TeamMapInner *)m_playerRelations)->m_14 != 0;
}
