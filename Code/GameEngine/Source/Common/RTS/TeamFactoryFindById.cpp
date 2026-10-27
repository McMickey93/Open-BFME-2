// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?findTeamPrototypeByID@TeamFactory@@QAEPAVTeamPrototype@@I@Z @0x0039F72C 53B
// Name (donor): Zero Hour TeamFactory::findTeamPrototypeByID, which
// TeamFactory::xfer calls on load exactly where retail calls this body.
// TeamFactory prototype map linear find by id. Walks the +0xB0 map from
// header->left via rowed _M_increment 0x00024250; each node carries the
// 8-byte key at +0x10 and the TeamPrototype at +0x18 whose +0x0C id is
// compared to the arg. Returns the prototype or null. Same owner/map/node
// as siblings 0x0039FE6C and 0x0039FE11; callers at 0x002B17B4 0x003A31C4
// 0x004EDB33 prove the single-arg thiscall shape.
// Evidence: ret 4 thiscall; [ecx+0xB0] header and [header+8] begin.
// The prototype map as the Team.cpp seed spells it: lower_bound's header and
// node (Rva0039EA4E, 0x0039EA4E) with the TeamPrototype value at +0x18.
#include <map>

struct Rva0039D8FBKey
{
	int m_first;
	int m_second;
};

class TeamPrototype
{
public:
	char m_pad00[0x0C];
	int m_id; // +0x0C
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
	TeamPrototype *findTeamPrototypeByID(unsigned int id);
private:
	unsigned char m_pad00[0xB0];
	Rva0039EA4E m_prototypes; // +0xB0
};

TeamPrototype *TeamFactory::findTeamPrototypeByID(unsigned int id)
{
	Rva0039EA4ENode *node = m_prototypes.m_header00->m_left08;
	if (node != m_prototypes.m_header00) {
		do {
			TeamPrototype *proto = node->m_value18;
			if (proto->m_id == id)
				return proto;
			node = (Rva0039EA4ENode *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)node);
		} while (node != m_prototypes.m_header00);
	}
	return 0;
}
