// cl: /Ireference/shims/bfmelist /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /Ireference/shims/bfme2_ascii
// platformsdk
// stlport
//
// GameWindowTransitionsHandler::findGroup (0x001DC01C, 98B), getNewGroup
// (0x001DC4D2, 170B), setGroup (0x001DC252, 243B) and reverse (0x001DC345,
// 231B), ported from Zero Hour's GameClient/GUI/GameWindowTransitions.cpp;
// reverse/symbols.csv pins findGroup, getNewGroup and setGroup at these
// addresses. The total-frames query between them (0x001DC1FD) is
// bfmeGetGroupTotalFrames, rowed in GameWindowTransitions.cpp.
// Target evidence: by-value AsciiString params with EH_prolog and the
// releaseBuffer row 0x00036410; isEmpty early-outs (null plus length
// check); the STLport group list at +0x20; compareNoCase (row 0x00006A00)
// against the group's name at +0xC; getNewGroup news 0x14 bytes, builds
// them with the rowed ctor 0x001DC0C7, names them through the folded
// AsciiString setter rowed as BuildListInfo::setTemplateName (0x001DBC2D)
// and appends through the folded list<int>::push_back.
// ZH's iterator loop gives retail's register assignment; compareNoCase is
// declared non-throwing (it allocates nothing), as retail's missing EH
// state store in findGroup shows; ~StringBase stays out of line (retail
// folds it onto releaseBuffer), so this unit emits no copy of it.
// BFME 2 additions in setGroup and reverse (target evidence): the whole call
// holds the critical section at +0x38 (EnterCriticalSection and
// LeaveCriticalSection imports, EH state 1); +0x54 and +0x58 are cleared and
// +0x5C and +0x60 take TheDisplay's vslots 0x40 and 0x44; a group that is
// dropped gets the rowed rva001DBE17 after (or instead of) its skip; reverse
// returns early on an unknown group and only clears the pending group when
// one was set. /EHsc: retail stores no EH state around the C imports.
// INI::parseWindowTransitions (0x001DC66F, 112B) is the "WindowTransition"
// block parser (retail table entry at 0x009B8CF0); the handler singleton is
// read from 0x00DFDC14 and the field table is the static at 0x00BDBBCC.
#include <windows.h>
#include <list>

// vector<int> fill/insert otherwise instantiates the _Construct<int,int>
// COMDAT (one byte shape per TU flags); a file-static overload takes those
// calls instead so this TU emits no external copy.
#include <new>
namespace _STL {
static inline void _Construct(int *__p, const int &__val)
{ new (__p) int(__val); }
}

// Compare nodes locally so this TU does not emit a conflicting iterator-base wrapper.
namespace _STL {
template <class T, class Traits>
static inline bool operator!=(const _List_iterator<T, Traits>& a,
                              const _List_iterator<T, Traits>& b)
{ return a._M_node != b._M_node; }
}

#include "ascii_string.h"

class Xfer;

enum INILoadType {INI_LOAD_INVALID, INI_LOAD_OVERWRITE};

class INI;
typedef void (*INIFieldParseProc)(INI *ini, void *instance, void *store, const void *userData);
struct FieldParse
{
	const char *token;
	INIFieldParseProc parse;
	const void *userData;
	int offset;
};

class INI
{
public:
	INI();
	~INI();
	unsigned char loadFile(AsciiString, INILoadType, Xfer *);
	const char *getNextToken(const char *seps = 0);
	void initFromINI(void *what, const FieldParse *parseTable);
	static void parseWindowTransitions( INI* ini );
	static void parseAsciiString(INI *ini, void *instance, void *store, const void *userData);
	static void parseInt(INI *ini, void *instance, void *store, const void *userData);
	static void parseBool(INI *ini, void *instance, void *store, const void *userData);	// rowed 0x002E850
	static void Rva001DCAED_ParseTransition(INI *ini, void *instance, void *store, const void *userData);
private:
	char storage[0x87C];
};

enum NameKeyType {NAMEKEY_INVALID=0,NAMEKEY_MAX=1<<23,FORCE_NAMEKEYTYPE_LONG=0x7fffffff};

class NameKeyGenerator;

extern NameKeyGenerator* TheNameKeyGenerator;

class Object;

struct KeyBucketNode { KeyBucketNode *next; int key; Object *value; };

struct KeyBucketTable
{
	KeyBucketNode **start;
	KeyBucketNode **finish;
	KeyBucketNode **storageEnd;
	unsigned size() const { return (unsigned)(finish - start); }
	KeyBucketNode *&at( unsigned n ) { return *( start + n ); }
};

struct KeyHashInt { unsigned operator()( int x ) const { return (unsigned)x; } };

struct KeyEqualInt { bool operator()( int a, int b ) const { return a == b; } };

class NameKeyGenerator
{
public:
	NameKeyType nameToKey( const char * );
	class KeyToBucketMap
	{
		friend class ObjectLookupMap;
	public:
		struct Slot { void *node; KeyToBucketMap *map; };
		__declspec(noinline) Slot *find( Slot &out, const int *key )
		{
			out.node = _M_find( *key );
			out.map = this;
			return &out;
		}
	private:
		struct value_type { int first; void *second; };
		int *insertNode( const value_type &value );
		unsigned tableSize() const { return m_table.size(); }
		KeyBucketNode *&tableAt( unsigned n ) { return m_table.at( n ); }
		unsigned bkt_num_key( int key ) const { return m_hash( key ) % tableSize(); }
		__declspec(noinline) void *_M_find( const int &key ) const
		{
			unsigned n = bkt_num_key( key );
			KeyBucketNode *first;
			for ( first = ( (KeyToBucketMap *)this )->tableAt( n ); first && !m_equals( first->key, key ); first = first->next )
			{
			}
			return first;
		}
		KeyHashInt m_hash;
		KeyEqualInt m_equals;
		char m_pad2[2];
		KeyBucketTable m_table;
		unsigned m_count;
	};
};

class ObjectLookupMap : public NameKeyGenerator::KeyToBucketMap
{
public:
	__declspec(noinline) Object **findSlot( int *key )
	{
		KeyToBucketMap::Slot out;
		find( out, key );
		KeyBucketNode *node = (KeyBucketNode *)out.node;
		if ( node == 0 )
		{
			out.node = (void *)*key;
			out.map = 0;
			return (Object **)( insertNode( (const KeyToBucketMap::value_type &)out ) + 1 );
		}
		return &node->value;
	}
	Object **slot( const NameKeyType &key ) { return findSlot( reinterpret_cast<int *>( const_cast<NameKeyType *>( &key ) ) ); }
};

// TransitionGroup's rowed bodies, on the address-named view.
class Rva001DBDA4
{
public:
	bool rva001DBD83() const; // isFinished
	void rva001DBD5D();      // update
	void rva001DBDC6();      // reverse
	void rva001DBE17();      // BFME 2's step after skip
	void rva001DBE34();      // skip
	void rva001DBE51();      // draw
	void rva001DC164();      // init
};

typedef bool Bool;

class TransitionWindow;

// The 0x14-byte group (genuine Rva001DC0EC home): the window list at +0, the
// direction at +0x04, the current frame at +0x08, the name at +0x0C and
// fireOnce at +0x10 (retail field table 0x007DBBCC).
class TransitionGroup
{
public:
	void addWindow(TransitionWindow *window);
	void init() { ((Rva001DBDA4 *)this)->rva001DC164(); }
	void update() { ((Rva001DBDA4 *)this)->rva001DBD5D(); }
	void reverse() { ((Rva001DBDA4 *)this)->rva001DBDC6(); }
	void skip() { ((Rva001DBDA4 *)this)->rva001DBE34(); }
	void draw() { ((Rva001DBDA4 *)this)->rva001DBE51(); }
	void bfmeAfterSkip() { ((Rva001DBDA4 *)this)->rva001DBE17(); }
	Bool isFinished() const { return ((const Rva001DBDA4 *)this)->rva001DBD83(); }
	Bool isReversed() { return m_directionMultiplier < 0; }
	Bool isFireOnce() { return m_fireOnce; }
	_STL::list<int, _STL::allocator<int> > m_list; // +0x00
	int m_directionMultiplier; // +0x04
	int m_currentFrame;        // +0x08
	AsciiString m_name;        // +0x0C
	Bool m_fireOnce;           // +0x10
};
typedef _STL::list<TransitionGroup *> TransitionGroupList;

class Display
{
public:
	virtual void v00();
	virtual void v01();
	virtual void v02();
	virtual void v03();
	virtual void v04();
	virtual void v05();
	virtual void v06();
	virtual void v07();
	virtual void v08();
	virtual void v09();
	virtual void v10();
	virtual void v11();
	virtual void unk30();
	virtual void v13();
	virtual void v14();
	virtual void v15();
	virtual int unk40();
	virtual int unk44();
};

class GameWindowTransitionsHandler;

// TheTransitionHandler is the singleton at 0x00DFDC14 (defined in WinMain.cpp).
extern GameWindowTransitionsHandler *TheTransitionHandler;

extern Display *TheDisplay;

class Rva001DC0EC
{
public:
	Rva001DC0EC();
private:
	_STL::list<int, _STL::allocator<int> > m_list;
private:
	int m_04;
private:
	int m_08;
private:
	int m_0C;
private:
	bool m_10;
public:
	void rva001DC1B3(_STL::list<int, _STL::allocator<int> > *dest);
};

class BuildListInfo
{
public:
	void setTemplateName(AsciiString name); // folded AsciiString setter
};

// BFME 2 guards the handler's group pointers with a critical section at
// +0x38, held for the whole call (EH state 1 while it is held).
class BfmeTransitionsLock
{
public:
	BfmeTransitionsLock(void *cs) : m_cs((CRITICAL_SECTION *)cs) { EnterCriticalSection((CRITICAL_SECTION *)cs); }
	~BfmeTransitionsLock() { LeaveCriticalSection(m_cs); }
private:
	CRITICAL_SECTION *m_cs;
};

// The handler as its ctor 0x001DCBC3 lays it out: vftable 0x007DBC30 at +0,
// the name-key parser map at +0x0C, the group list at +0x20, the current,
// pending, draw and secondary groups at +0x24..+0x30, the critical section at
// +0x38, the idle-notify flag at +0x51, the wait-loop sleep at +0x64, the
// wait reentrancy flag at +0x68 and the hold flag at +0x69.
class GameWindowTransitionsHandler
{
public:
	void load();
	bool isFinished();
	virtual void reset();
	virtual void draw();
	virtual void update();
	void rva001DC07E();
	void rva001DC57C(_STL::list<int, _STL::allocator<int> > *dest);
	void rva001DC5EC();
	const FieldParse *getFieldParse() const { return m_gameWindowTransitionsFieldParseTable; }
	void setGroup( AsciiString groupName, Bool immidiate );
	void reverse( AsciiString groupName );
	void remove( AsciiString groupName, Bool skipPending = false );
	static void parseWindow(INI *ini, void *instance, void *store, const void *userData);	// rowed 0x001DCB2F
	TransitionGroup *getNewGroup( AsciiString name );
private:
	static const FieldParse m_gameWindowTransitionsFieldParseTable[];
	TransitionGroup *findGroup( AsciiString groupName );
	char m_pad04[0x8];
	ObjectLookupMap m_table;
	TransitionGroupList m_transitionGroupList; // +0x20
	TransitionGroup *m_currentGroup;       // +0x24
	TransitionGroup *m_pendingGroup;       // +0x28
	TransitionGroup *m_drawGroup;          // +0x2C
	TransitionGroup *m_secondaryDrawGroup; // +0x30
	char m_pad34[0x4];
	CRITICAL_SECTION m_lock;
	char m_pad50;
	bool m_unk51;
	char m_pad52[0x2];
	int m_54;
	int m_58;
	int m_5C;
	int m_60;
	unsigned long m_64;
	unsigned char m_68;
	bool m_69;
};

// Retail's field table at RVA 0x007DBBCC (.rdata): "Window" -> parseWindow and "FireOnce" -> parseBool at
// +0x10 (TransitionGroup::m_fireOnce), then the zero sentinel; transcribed from retail's own bytes.
const FieldParse GameWindowTransitionsHandler::m_gameWindowTransitionsFieldParseTable[] =
{
	{ "Window", GameWindowTransitionsHandler::parseWindow, 0, 0 },
	{ "FireOnce", INI::parseBool, 0, 0x10 },
	{ 0, 0, 0, 0 }
};

TransitionGroup *GameWindowTransitionsHandler::getNewGroup( AsciiString name )
{
	if(name.isEmpty())
		return NULL;

	// test to see if we're trying to add an already exisitng group.
	if(findGroup(name))
	{
		return NULL;
	}
	TransitionGroup *transitionGroup = (TransitionGroup *)new Rva001DC0EC;
	((BuildListInfo *)transitionGroup)->setTemplateName(name);
	((_STL::list<int> *)&m_transitionGroupList)->push_back(*(int *)&transitionGroup);
	return transitionGroup;
}

TransitionGroup *GameWindowTransitionsHandler::findGroup( AsciiString groupName )
{
	if(groupName.isEmpty())
		return NULL;

	TransitionGroupList::iterator it = m_transitionGroupList.begin();
	while (it != m_transitionGroupList.end())
	{
		TransitionGroup *transitionGroup = *it;
		if(groupName.compareNoCase(transitionGroup->m_name) == 0)
			return transitionGroup;
		it++;
	}
	return NULL;
}

void GameWindowTransitionsHandler::setGroup(AsciiString groupName, Bool immidiate )
{
	BfmeTransitionsLock lock(&m_lock);
	m_54 = 0;
	m_58 = 0;
	m_5C = TheDisplay->unk40();
	m_60 = TheDisplay->unk44();
	if(groupName.isEmpty() && immidiate)
	{
		if(m_currentGroup)
		{
			m_currentGroup->bfmeAfterSkip();
			m_currentGroup = NULL;
		}
	}
	if(immidiate && m_currentGroup)
	{
		m_currentGroup->skip();
		m_currentGroup = findGroup(groupName);
		if(m_currentGroup)
			m_currentGroup->init();
		return;
	}

	if(m_currentGroup)
	{
		if(!m_currentGroup->isFireOnce() && !m_currentGroup->isReversed())
			m_currentGroup->reverse();
		m_pendingGroup = findGroup(groupName);
		if(m_pendingGroup)
			m_pendingGroup->init();
		return;
	}

	m_currentGroup = findGroup(groupName);
	if(m_currentGroup)
		m_currentGroup->init();
}

// GameWindowTransitionsHandler::remove (0x001DC42C, 166B): drops a group under
// the critical section; the nested equal-arm on the lookup keeps retail's
// EH-slot placement for the by-value name.
void GameWindowTransitionsHandler::remove( AsciiString groupName,  Bool skipPending )
{
	BfmeTransitionsLock lock(&m_lock);
	TransitionGroup *transitionGroup = (skipPending ? (findGroup(groupName)) : ((&m_lock ? (findGroup(groupName)) : (findGroup(groupName)))));
	if(!transitionGroup)
		return; // BFME 2 (target evidence): an unknown group changes nothing
	if(m_pendingGroup == transitionGroup)
	{
		if(skipPending)
			m_pendingGroup->skip();
		m_pendingGroup->bfmeAfterSkip();

		m_pendingGroup = NULL;
	}
	if(m_currentGroup == transitionGroup)
	{
		m_currentGroup->skip();
		m_currentGroup->bfmeAfterSkip();
		m_currentGroup = NULL;
		if(m_pendingGroup)
			m_currentGroup = m_pendingGroup;
	}
}

void GameWindowTransitionsHandler::reverse( AsciiString groupName )
{
	BfmeTransitionsLock lock(&m_lock);
	m_54 = 0;
	m_58 = 0;
	m_5C = TheDisplay->unk40();
	m_60 = TheDisplay->unk44();
	TransitionGroup *transitionGroup = findGroup(groupName);
	if(!transitionGroup)
		return;
	if( m_currentGroup == transitionGroup )
	{
		m_currentGroup->reverse();
		return;
	}
	if( m_pendingGroup == transitionGroup)
	{
		m_pendingGroup->bfmeAfterSkip();
		m_pendingGroup = NULL;
		return;
	}
	if(m_currentGroup)
	{
		m_currentGroup->skip();
		m_currentGroup->bfmeAfterSkip();
	}
	if(m_pendingGroup)
	{
		m_pendingGroup->skip();
		m_pendingGroup->bfmeAfterSkip();
		m_pendingGroup = NULL;
	}

	m_currentGroup = transitionGroup;
	m_currentGroup->init();
	m_currentGroup->skip();
	m_currentGroup->reverse();
}

void INI::parseWindowTransitions( INI* ini )
{
	AsciiString name;
	TransitionGroup *transitionGroup;

	// read the name
	const char* c = ini->getNextToken();
	name.set( c );

	if( !TheTransitionHandler )
		return;
	transitionGroup = TheTransitionHandler->getNewGroup( name );

	ini->initFromINI(transitionGroup, TheTransitionHandler->getFieldParse() );
}
