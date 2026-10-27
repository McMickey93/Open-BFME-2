// stlport
// cl: /Ireference/shims/bfme2_ascii /ICode/GameEngine/Include /DNDEBUG /MD
#include "GameLogic/ScriptActionsBFME2.h"
// flags: region default (reverse/retail_inventory/flag_regions.csv)
// ?Rva003BB700@ScriptActions@@QAEX_N@Z @0x003BB700 19B: ScriptActions member setter of
// TheGameLogic's byte at +0x98 (the flag Rva0039B683 gates on).
// Target evidence: TheGameLogic is the global at 0x00DFE78C; with the real
// extern the compiler loads the argument first as retail does (the banked
// attempt read the global through a literal-address macro).
#include "GameLogicObjectLookupView.h"

extern GameLogic *TheGameLogic;

void ScriptActions::Rva003BB700(bool v)
{
	TheGameLogic->enableScoring(v);
}

// Member ABI proved at each native executeAction3CA4BE call site: ECX=this.
// Canonical ScriptActions owner; address-derived verbs remain uncertain.
