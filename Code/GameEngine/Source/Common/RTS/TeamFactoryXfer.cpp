// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/moduledata /O1 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?xfer@TeamFactory@@MAEXPAVXfer@@@Z, retail 0x003A308A (527 bytes).
// Identity (target): WorldBuilder's debug Team.cpp TeamFactory::DoXfer
// (callgraph lead) and Zero Hour's TeamFactory::xfer share retail's order:
// the unique team id, the prototype count checked against the map size
// (XferException(5, 0) on mismatch), then on save each prototype's id and
// snapshot over the map (rowed _M_increment 0x00024250), on load
// findTeamPrototypeByID (0x0039F72C) with the same throw when missing.
// Layout (target): the method runs on the Snapshot base at TeamFactory+0x0C,
// so the prototype map (+0xB0) and its count (+0xB4) read at +0xA4/+0xA8 and
// m_uniqueTeamID (+0xC0) at +0xB4; prototypes carry their id at +0x0C.
// BFME 2 deltas (target): a light-CRC early out and Version(1, 3); from
// version 2 a flag (whether the first of 40 prototype slots at +0x10 is
// set) and, when set, each slot's name (+0x14), owner player index (+0x08,
// -1 for none) and singleton bit (+0x18 bit 0); a slot with an owner is
// re-set up on load through 0x003A2C0D (owner, name, singleton, no Dict)
// and, from version 3, moved as a snapshot. Zero Hour's unused
// prototypeName local survives as the constructed-and-released string.
#include <map>
#include "ascii_string.h"
#include "Common/Snapshot.h"
#include "../../../../Libraries/Source/subsystem/SubsystemInterface.h"

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

#include "../../../Include/Common/BfmeXfer.h"

class Xfer::Version
{
public:
	Version(unsigned char current, unsigned char minimum)
		: m_current(current), m_minimum(minimum) {}

	unsigned char m_current;
	unsigned char m_minimum;
};



class XferException
{
public:
	XferException(int tag, const char *format, ...);
	XferException(const XferException &that);
	~XferException(void);

	char *text;
	int tagValue;
};

class Player
{
public:
	int getPlayerIndex() const { return m_playerIndex; }

private:
	unsigned char m_pad00[0x54];
	int m_playerIndex; // +0x54
};

class PlayerList
{
public:
	Player *getNthPlayer(int index);
};

extern PlayerList *ThePlayerList;

class Dict;

class TeamPrototype : public Snapshot
{
public:
	unsigned int getID() const { return m_id; }
	Player *getControllingPlayer() const { return m_owningPlayer; }
	const AsciiString &getName() const { return m_name; }
	bool getIsSingleton() const { return (m_flags & 1) != 0; }
	void rva003A2C0D(Player *owner, const AsciiString &name, bool isSingleton, Dict *d);

protected:
	virtual void crc(Xfer *xfer);
	virtual void xfer(Xfer *xfer);
	virtual void loadPostProcess();

private:
	unsigned char m_pad04[0x08 - 0x04];
	Player *m_owningPlayer; // +0x08
	unsigned int m_id; // +0x0C
	unsigned char m_pad10[0x14 - 0x10];
	AsciiString m_name; // +0x14
	int m_flags; // +0x18
};

// The prototype map as the Team.cpp seed spells it: lower_bound's header and
// node (Rva0039EA4E, 0x0039EA4E) with the TeamPrototype value at +0x18.
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
	unsigned int size() const { return m_nodeCount04; }
	Rva0039EA4ENode *m_header00;
	unsigned int m_nodeCount04;
};


enum { TEAM_FACTORY_PROTOTYPE_SLOTS = 40 };

class TeamFactory : public SubsystemInterface, public Snapshot
{
protected:
	virtual void crc(Xfer *xfer);
	virtual void xfer(Xfer *xfer);
	virtual void loadPostProcess();

public:
	TeamPrototype *findTeamPrototypeByID(unsigned int id);

private:
	TeamPrototype *m_dummyTeams[TEAM_FACTORY_PROTOTYPE_SLOTS]; // +0x10
	Rva0039EA4E m_prototypes; // +0xB0, map header and node count
	unsigned char m_padB8[0xBC - 0xB8];
	unsigned int m_uniqueTeamPrototypeID; // +0xBC
	unsigned int m_uniqueTeamID; // +0xC0
};

void TeamFactory::xfer(Xfer *xfer)
{
	if (xfer->IsLightCRC())
		return;

	Xfer::Version version(1, 3);
	*xfer == version;

	*xfer == m_uniqueTeamID;

	unsigned short prototypeCount = (unsigned short)m_prototypes.size();
	*xfer == prototypeCount;
	if (prototypeCount != m_prototypes.size())
		throw XferException(5, 0);

	unsigned int teamPrototypeID;
	TeamPrototype *teamPrototype;
	AsciiString prototypeName;
	if (xfer->IsStoring())
	{
		for (Rva0039EA4ENode *it = m_prototypes.m_header00->m_left08; it != m_prototypes.m_header00;
			it = (Rva0039EA4ENode *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)it))
		{
			teamPrototype = it->m_value18;
			teamPrototypeID = teamPrototype->getID();
			*xfer == teamPrototypeID;
			*xfer == *teamPrototype;
		}
	}
	else
	{
		for (unsigned short i = 0; i < prototypeCount; ++i)
		{
			*xfer == teamPrototypeID;
			teamPrototype = findTeamPrototypeByID(teamPrototypeID);
			if (teamPrototype == 0)
				throw XferException(5, 0);
			*xfer == *teamPrototype;
		}
	}

	if (version.m_minimum >= 2)
	{
		bool hasSlots = m_dummyTeams[0] != 0;
		*xfer == hasSlots;
		if (hasSlots)
		{
			for (int i = 0; i < TEAM_FACTORY_PROTOTYPE_SLOTS; ++i)
			{
				TeamPrototype *slot = m_dummyTeams[i];
				AsciiString name(slot->getName());
				*xfer == name;
				int playerIndex = slot->getControllingPlayer() ? slot->getControllingPlayer()->getPlayerIndex() : -1;
				*xfer == playerIndex;
				bool isSingleton = slot->getIsSingleton();
				*xfer == isSingleton;
				if (playerIndex != -1)
				{
					if (xfer->IsLoading())
					{
						Player *owner = ThePlayerList->getNthPlayer(playerIndex);
						slot->rva003A2C0D(owner, name, isSingleton, 0);
					}
					if (version.m_minimum >= 3)
						*xfer == *slot;
				}
			}
		}
	}
}
