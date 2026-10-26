// cl: -DNDEBUG -DWIN32 -D_WINDOWS -MD -EHsc -Ireference/shims/bfme2_ascii -Ireference/open-bfme-1/game/GameEngine/Source/Common/Audio
// stlport
// Audio slot lookup over the native AsciiString-keyed tree.
#include "ascii_string.h"
#include <map>

union Rva006AD590Slot
{
    int m_asInt;
    float m_asFloat;
};

typedef _STL::pair<const AsciiString, int> AudioPriorityValue;
typedef _STL::_Rb_tree<AsciiString, AudioPriorityValue,
    _STL::_Select1st<AudioPriorityValue>, _STL::less<AsciiString>,
    _STL::allocator<AudioPriorityValue> > AudioPriorityTree;

class Rva006AD590Entry
{
public:
    Rva006AD590Slot *find(int key);
    char m_pad[0x1b8];
    AudioPriorityTree m_map;
    char m_tail[0x1c4 - 0x1b8 - sizeof(AudioPriorityTree)];
};

Rva006AD590Slot *Rva006AD590Entry::find(int key)
{
    AudioPriorityTree::iterator node = m_map.find(*reinterpret_cast<const AsciiString *>(key));
    if (node._M_node == m_map.end()._M_node)
        return 0;
    return reinterpret_cast<Rva006AD590Slot *>(&node->second);
}

class Rva000588DA
{
public:
	~Rva000588DA();
};

class Rva00059259
{
public:
	void rva00059259();
};

void Rva00059259::rva00059259()
{
	((Rva000588DA *)this)->~Rva000588DA();
}

struct Rva00058A86Record;
namespace _STL {
	template <class A, class B, class C, class D, class E, class F> class hashtable {
	public:
		~hashtable();
	};
	template <class> struct hash;
	template <class> struct _Identity;
	template <class> struct equal_to;
	template <class> class allocator;

	typedef hashtable<Rva00058A86Record, Rva00058A86Record, hash<Rva00058A86Record>, _Identity<Rva00058A86Record>, equal_to<Rva00058A86Record>, allocator<Rva00058A86Record> > Rva00058A86Table;
}

class Rva000592B3
{
public:
	void rva000592B3();
};

void Rva000592B3::rva000592B3()
{
	((_STL::Rva00058A86Table *)this)->~hashtable();
}