// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /arch:SSE /DNDEBUG /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// Retail 0x003A0D0A 88B, WB twin EF2670 (identity remains address-derived).
// Target facts: owner +08, unit record array +130 with stride18, second name
// +10 in each record, count +1D8; existing TeamTemplateInfo ctor independently
// establishes seven records and that count. Empty object is the exported
// AsciiString::TheEmptyString at RVA9E0878. Registry and +38 append calls use
// their owned opaque providers; their higher-level purpose is not asserted.
#include <map>
#include "ascii_string.h"
class Player;
class Rva004EC05A { public: void rva004EC05A(void *); };
struct Rva002A8AB1Record;
class Rva002A8F24 { public: Rva002A8AB1Record *rva002A8AB1(void *); };
extern Rva002A8F24 *TheSkirmishAIManager;
// One unit record and the template's record array and count (+0x130 and
// +0x1D8 of the prototype), spelled as the Team.cpp seed's Rva0039EA9C and
// TeamTemplateInfo (+0x12C) name them.
struct UnitInfo { int m_00,m_04,m_08; AsciiString m_0c,m_10; int m_14; };
struct TeamTemplateUnitsView { char m_vptr[4]; UnitInfo m_unitsInfo[7]; int m_numUnitsInfo; };
class TeamPrototype { public: void __declspec(noinline) rva003A0D0A(); private:
 char m_pad00[8]; Player *m_owningPlayer; char m_pad0C[0x12C-0x0C]; TeamTemplateUnitsView m_teamTemplate;
};
void TeamPrototype::rva003A0D0A()
{
 if(m_owningPlayer) {
  Rva002A8AB1Record *record=TheSkirmishAIManager->rva002A8AB1(m_owningPlayer);
  if(record) {
   for(int i=0;i<m_teamTemplate.m_numUnitsInfo;++i) {
    if(m_teamTemplate.m_unitsInfo[i].m_10.compare(AsciiString::TheEmptyString)!=0)
     ((Rva004EC05A *)record)->rva004EC05A(&m_teamTemplate.m_unitsInfo[i].m_10);
   }
  }
 }
}

// The prototype map as the Team.cpp seed spells it.
struct Rva0039D8FBKey
{
    int m_first;
    int m_second;
};

int __cdecl Rva0039D8FBLess(const Rva0039D8FBKey &a, const Rva0039D8FBKey &b);

struct Rva0039EA4ENode
{
    int m_color00;
    Rva0039EA4ENode *m_parent04;
    Rva0039EA4ENode *m_left08;
    Rva0039EA4ENode *m_right0C;
    Rva0039D8FBKey m_key10;
    TeamPrototype *m_value18;
};

struct Rva0039F5C8Iterator
{
    Rva0039EA4ENode *m_node;
    Rva0039F5C8Iterator(Rva0039EA4ENode *node) : m_node(node) {}
};

class Rva0039EA4E
{
public:
    Rva0039EA4ENode *rva0039EA4E(const Rva0039D8FBKey &key);
    Rva0039F5C8Iterator rva0039F5C8(const Rva0039D8FBKey &key);
    Rva0039EA4ENode *rva0039F597(const Rva0039D8FBKey &key);
    Rva0039F5C8Iterator rva0039FB73(const Rva0039D8FBKey &key);
    unsigned int size() const { return m_nodeCount04; }

    Rva0039EA4ENode *m_header00;
    unsigned int m_nodeCount04; // TeamFactory::xfer checks it against the saved count
};

class TeamFactory {
public:
 void rva003A262C();
private:
 char m_pad[0xB0];
 Rva0039EA4E m_prototypes; // +0xB0
};
// ?rva003A262C@TeamFactory@@QAEXXZ @0x003A262C (45B)
void TeamFactory::rva003A262C()
{
 for (Rva0039EA4ENode *node = m_prototypes.m_header00->m_left08; node != m_prototypes.m_header00;
      node = (Rva0039EA4ENode *)_STL::_Rb_global<bool>::_M_increment((_STL::_Rb_tree_node_base *)node))
  node->m_value18->rva003A0D0A();
}
