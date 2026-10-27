// cl: -DNDEBUG -DWIN32 -MD -D_STLP_USE_STATIC_LIB -Ireference/open-bfme-1/game/GameEngine/Source/GameLogic/ScriptEngine
// stlport

// The registration table at 0x002EC990 pushes ILT thunk 0x0003D4BF, which
// jumps here to 0x002E6420, and the next lua_setglobal names it
// ObjectEnterUncontrollableCowerState. The callback resolves two objects and
// sets special model condition 5 on the first, with the second as its value.
//
// Both object lookups use one logic instance. Cache its receiver across the calls.

struct lua_State;
extern "C" int lua_type(lua_State *state, int index);
// Rowed 0x00747190 (Rva00990030RecordLookup.cpp) over its view of the Lua
// state's stack range; called by that row's name.
struct Rva00990030Range;
unsigned Rva00990030Lookup(Rva00990030Range *state, int index);

// Lua 4.0.1 lua.h
const int LUA_TNIL = 1;

class Object
{
public:
	// Rowed 0x0028EC68 (ObjectRva0028EBDA.cpp); called by that row's name.
	void rva0028EC68(int condition, void *value, int enabled);
};



// ABI slice matching GameLogicFindObjectByID.cpp: the bucket vector sits at
// this+0xB4, the offset retail's findObjectByID reads.
#include "../../Common/GameLogicObjectLookupView.h"


extern GameLogic *TheGameLogic;

int ObjectEnterUncontrollableCowerState(lua_State *state)
{
	unsigned objectID = Rva00990030Lookup((Rva00990030Range *)state, 1);
	if (!objectID && lua_type(state, 1) != LUA_TNIL)
		return 0;
	// Retail checks argument 1 again here, not argument 2.
	unsigned otherID = Rva00990030Lookup((Rva00990030Range *)state, 2);
	if (!otherID && lua_type(state, 1) != LUA_TNIL)
		return 0;

	GameLogic *logic = TheGameLogic;
	Object *object = logic->findObjectByID((ObjectID)objectID);
	Object *other = logic->findObjectByID((ObjectID)otherID);
	if (object && other)
		object->rva0028EC68(5, other, 1);
	return 0;
}
