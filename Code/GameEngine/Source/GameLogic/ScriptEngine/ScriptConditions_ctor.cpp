// flags: region default (reverse/retail_inventory/flag_regions.csv)
//
// ScriptConditions constructor, retail 0x003E5513 (18 bytes). ScriptEngine::init
// creates it with operator new(0xC) and stores it in TheScriptConditions. The
// global's slot-15 call evaluates conditions at 0x0020CB4C.
//
// Donor: ZH ScriptConditions::ScriptConditions, an empty body. Only the
// SubsystemInterface base call (0x001B4E63) and the vtable store (0xC35B38)
// remain.
//
// ScriptConditions destructor, retail 0x003E5525 (62 bytes), and its scalar
// deleting destructor 0x003E5DCD (28 bytes). The constructor above stores
// vftable 0x00C35B38; that vftable's slot 0 is 0x003E5DCD, which calls
// 0x003E5525, and its slot 9 is ScriptConditions::reset (0x003E3C66). The
// destructor stores 0x00C35B38, calls reset 0x003E3C66 directly, then stores
// the ScriptConditionsInterface vftable 0x00C35AE0 and calls
// ~SubsystemInterface 0x001B4E74: Zero Hour's
// ScriptConditions::~ScriptConditions() { reset(); } over the inline empty
// ~ScriptConditionsInterface. Its unwind funclet 0x00783364 calls the
// out-of-line copy of that base destructor at 0x003E3BD4. (These rows were
// previously claimed as CDManager's; retail's CDManager uses vftable
// 0x00C3C5DC.)

#include "../../../../Libraries/Source/subsystem/SubsystemInterface.h"

class ScriptConditionsInterface : public SubsystemInterface
{
public:
	virtual ~ScriptConditionsInterface() { }
};

class ScriptConditions : public ScriptConditionsInterface
{
public:
	ScriptConditions();
	virtual ~ScriptConditions();
	virtual void init();
	virtual void reset();
};

ScriptConditions::ScriptConditions()
{
}

ScriptConditions::~ScriptConditions()
{
	reset(); // just in case...
}

// Placeholder virtuals in this unit's vftables: in retail, every vftable that holds
// each one has the same function in that slot (vftable addresses from matched vptr
// stores). Bind them to the rows at those functions.
#pragma comment(linker, "/alternatename:?init@ScriptConditions@@UAEXXZ=?rva000D20D6@Rva000D20D6@@UAEXXZ")
