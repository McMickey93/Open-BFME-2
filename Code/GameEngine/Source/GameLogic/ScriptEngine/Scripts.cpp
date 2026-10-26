// cl: /DsetScriptList=setScriptList_Scripts_RV /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/open-bfme-1/reference/shims/scriptenginevtable /Ireference/open-bfme-1/reference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad
// stlport
#define Matrix4x4 Matrix4  // BFME renamed it
/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// FILE: Scripts.cpp /////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------
//                                                                          
//                       Westwood Studios Pacific.                          
//                                                                          
//                       Confidential Information                           
//                Copyright (C) 2001 - All Rights Reserved                  
//                                                                          
//-----------------------------------------------------------------------------
//
// Project:   Generals
//
// File name: Scripts.cpp
//
// Created:   John Ahlquist, Nov 2001
//
// Desc:      Contains the information describing scripts.
//
//-----------------------------------------------------------------------------
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

// BFME de-pooled this glue: retail's per-class `operator delete(void*, MagicEnum)`
// is one 12-byte body (0x007EFFF0) that calls the CRT free IMPORT THUNK -- a
// `call rel32` into `jmp [__imp__free]` -- where ::operator delete (0x00881EB0)
// is a different function. <stdlib.h> declares free __declspec(dllimport) under
// /MD, which compiles to the `ff 15` indirect form instead, so the C-linkage
// redeclaration below is what names `_free` for the linker's thunk; it is
// namespaced so every other free() call in this TU keeps the indirect form
// retail also uses. Same TU-scoped override Team.cpp already carries.
namespace BfmePoolGlue { extern "C" void __cdecl free(void *); }
#undef MEMORY_POOL_GLUE_WITHOUT_GCMP
#define MEMORY_POOL_GLUE_WITHOUT_GCMP(ARGCLASS) \
protected: \
	virtual ~ARGCLASS(); \
public: \
	enum ARGCLASS##MagicEnum { ARGCLASS##_GLUE_NOT_IMPLEMENTED = 0 }; \
public: \
	inline void *operator new(size_t s, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) \
	{ return MP_GLUE_ALLOCATE(ARGCLASS); } \
public: \
	inline void operator delete(void *p, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) \
	{ BfmePoolGlue::free(p); } \
protected: \
	inline void *operator new(size_t s) { return ::operator new(s); } \
	inline void operator delete(void *p) { ::operator delete(p); } \
private: \
	virtual MemoryPool *getObjectMemoryPool() { return ARGCLASS::getClassMemoryPool(); } \
public:

#include "Lib/BaseType.h"

#define DEFINE_BUILDABLE_STATUS_NAMES
#define DEFINE_OBJECT_STATUS_NAMES
#define DEFINE_SCIENCE_AVAILABILITY_NAMES

#include "Common/BorderColors.h"
#include "Common/DataChunk.h"
#include "Common/GameState.h"
#include "Common/KindOf.h"
#include "Common/Radar.h"
#include "Common/ThingTemplate.h"
#include "Common/Player.h"
#include "Common/Xfer.h"

#include "GameClient/ShellHooks.h"

#include "GameLogic/Ai.h"
#include "GameLogic/Object.h"
#include "GameLogic/ScriptEngine.h"
#include "GameLogic/SidesList.h"
#include "GameLogic/Module/ContainModule.h"


#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")
#endif


static Script *s_mtScript = NULL;
static ScriptGroup *s_mtGroup = NULL;

// The carved body at 0x001FC3D0 is a second copy of Script::getAction.
// Script::setAction stores at +0x28, setFalseAction stores at +0x2C, and
// setNextScript stores at +0x30, which proves the member layout.
class Rva001FC3D0ScriptAction
{
public:
	ScriptAction *getAction(void) const;

private:
	char m_prefix[0x28];
	ScriptAction *m_action;
};

// ?getAction@Rva001FC3D0ScriptAction@@QBEPAVScriptAction@@XZ

//
// These strings must be in the same order as they are in their definitions 
// (See SHELL_SCRIPT_HOOK_* )
//
char *TheShellHookNames[]=
{
	"ShellMainMenuCampaignPushed", //SHELL_SCRIPT_HOOK_MAIN_MENU_CAMPAIGN_SELECTED,
	"ShellMainMenuCampaignHighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_CAMPAIGN_HIGHLIGHTED,
	"ShellMainMenuCampaignUnhighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_CAMPAIGN_UNHIGHLIGHTED,

	"ShellMainMenuSkirmishPushed", //SHELL_SCRIPT_HOOK_MAIN_MENU_SKIRMISH_SELECTED,
	"ShellMainMenuSkirmishHighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_SKIRMISH_HIGHLIGHTED,
	"ShellMainMenuSkirmishUnhighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_SKIRMISH_UNHIGHLIGHTED,

	"ShellMainMenuOptionsPushed", //SHELL_SCRIPT_HOOK_MAIN_MENU_OPTIONS_SELECTED,
	"ShellMainMenuOptionsHighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_OPTIONS_HIGHLIGHTED,
	"ShellMainMenuOptionsUnhighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_OPTIONS_UNHIGHLIGHTED,

	"ShellMainMenuOnlinePushed", //SHELL_SCRIPT_HOOK_MAIN_MENU_ONLINE_SELECTED,
	"ShellMainMenuOnlineHighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_ONLINE_HIGHLIGHTED,
	"ShellMainMenuOnlineUnhighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_ONLINE_UNHIGHLIGHTED,

	"ShellMainMenuNetworkPushed", //SHELL_SCRIPT_HOOK_MAIN_MENU_NETWORK_SELECTED,
	"ShellMainMenuNetworkHighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_NETWORK_HIGHLIGHTED,
	"ShellMainMenuNetworkUnhighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_NETWORK_UNHIGHLIGHTED,

	"ShellMainMenuExitPushed", //SHELL_SCRIPT_HOOK_MAIN_MENU_EXIT_SELECTED,
	"ShellMainMenuExitHighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_EXIT_HIGHLIGHTED,
	"ShellMainMenuExitUnhighlighted", //SHELL_SCRIPT_HOOK_MAIN_MENU_EXIT_UNHIGHLIGHTED,

	"ShellGeneralsOnlineLogin", //SHELL_SCRIPT_HOOK_GENERALS_ONLINE_LOGIN,
	"ShellGeneralsOnlineLogout", //SHELL_SCRIPT_HOOK_GENERALS_ONLINE_LOGOUT,
	"ShellGeneralsOnlineEnteredFromGame", //SHELL_SCRIPT_HOOK_GENERALS_ONLINE_ENTERED_FROM_GAME,

	"ShellOptionsOpened", //SHELL_SCRIPT_HOOK_OPTIONS_OPENED,
	"ShellOptionsClosed", //SHELL_SCRIPT_HOOK_OPTIONS_CLOSED,

	"ShellSkirmishOpened", //SHELL_SCRIPT_HOOK_SKIRMISH_OPENED,
	"ShellSkirmishClosed", //SHELL_SCRIPT_HOOK_SKIRMISH_CLOSED,
	"ShellSkirmishEnteredFromGame", //SHELL_SCRIPT_HOOK_SKIRMISH_ENTERED_FROM_GAME,

	"ShellLANOpened", //SHELL_SCRIPT_HOOK_LAN_OPENED,
	"ShellLANClosed", //SHELL_SCRIPT_HOOK_LAN_CLOSED,
	"ShellLANEnteredFromGame", //SHELL_SCRIPT_HOOK_LAN_ENTERED_FROM_GAME,
};
void SignalUIInteraction(Int interaction)
{
	if (TheScriptEngine)
		TheScriptEngine->signalUIInteract(TheShellHookNames[interaction]);
}


// Changing the order or meaning of either of these will require you to update the maps
// in a meaningful way. If there are new entries, add them to the end, rather than the middle.
const char *Surfaces[] = { "Ground", "Air", "Ground or Air", };
const char *ShakeIntensities[] = { "Subtle", "Normal", "Strong", "Severe", "Cine_Extreme", "Cine_Insane" };

enum { K_SCRIPT_LIST_DATA_VERSION_1 = 1,
			K_SCRIPT_GROUP_DATA_VERSION_1 = 1,
			K_SCRIPT_GROUP_DATA_VERSION_2 = 2,
			K_SCRIPT_DATA_VERSION_1 = 1,
			K_SCRIPT_DATA_VERSION_2 = 2,
			K_SCRIPT_OR_CONDITION_DATA_VERSION_1=1, 
			K_SCRIPT_ACTION_VERSION_1 = 1,
			K_SCRIPT_ACTION_VERSION_2 = 2,
			K_SCRIPT_CONDITION_VERSION_1 = 1,
			K_SCRIPT_CONDITION_VERSION_2 = 2,
			K_SCRIPT_CONDITION_VERSION_3 = 3,
			K_SCRIPT_CONDITION_VERSION_4 = 4,
			K_SCRIPTS_DATA_VERSION_1,
			end_of_the_enumeration
};

static Condition::ConditionType ParameterChangesVer2[] = 
{ 
	// Seven Changed from version 1.
	Condition::TEAM_INSIDE_AREA_PARTIALLY, 
	Condition::TEAM_INSIDE_AREA_ENTIRELY, 
	Condition::TEAM_OUTSIDE_AREA_ENTIRELY, 
	Condition::TEAM_ENTERED_AREA_PARTIALLY, 
	Condition::TEAM_ENTERED_AREA_ENTIRELY, 
	Condition::TEAM_EXITED_AREA_ENTIRELY, 
	Condition::TEAM_EXITED_AREA_PARTIALLY, 
	(Condition::ConditionType) -1,
};

enum { AT_END = 0x00FFFFFF };

//-------------------------------------------------------------------------------------------------
// ******************************** class  ScriptList *********************************************
//-------------------------------------------------------------------------------------------------
// Statics ///////////////////////////////////////////////////////////////////////////////////////
ScriptList *ScriptList::s_readLists[MAX_PLAYER_COUNT] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
Int					ScriptList::s_numInReadList = 0;

Int ScriptList::m_curId = 0;

/**
 ScriptList::updateDefaults -  checks for empty script lists, and adds some default stuff
 so you don't get a totally blank screen in the editor.
 Matched via MASM exact dump @ 0x0035C8A0 (183B); BFME inlines a 0x4c ScriptList ctor.
*/

/**
  Deletes any script lists attached to sides.  Used for editor cleanup.
*/



/**
  Ctor.
*/
// ScriptList::ScriptList: defined in ScriptListCtor.cpp (its row's unit).

/**
  Dtor.  Deletes any script lists or group lists.  Note that dtors for groups and script lists
	delete the whole list, so don't need to traverse here.
*/

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version */
// ------------------------------------------------------------------------------------------------
// byte-exact reconstruction: Code/GameEngine/Source/Common/ScriptList_xferMethodThunk.cpp

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
// ScriptList::loadPostProcess is owned by ScriptListDestructor.cpp; native
// C1FAAC slot1 points to the shared empty RET. Keep a single definition.

/**
  ScriptList::duplicate - Creates a full, "deep" copy of scriptlist. 
*/
// ScriptList::duplicate: defined in ScriptListDuplicate.cpp (its row's unit).

/**
  ScriptList::duplicateAndQualify - Creates a full, "deep" copy of scriptlist,
	adding the qualifier to names. 
*/

/**
  ScriptList::discard - Deletes a script list, but not any children. 
*/

/**
  Add a script group to the current list of groups.  Offset to position ndx.
*/

/**
  Add a script to the current list of scripts.  Offset to position ndx.
*/

/**
  Delete a script from the current list of scripts.
*/

/**
  Delete a group from the current list of groups.
*/

/**
* ScriptList::ParseScriptsDataChunk - read a Scripts chunk.
* Format is the newer CHUNKY format.
*	See ScriptList::ScriptList for the writer.
*	Input: DataChunkInput 
*		
*/
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptList_ParseScriptsDataChunk_Thunk.cpp

/**
* ScriptList::getReadScripts - Gets the scripts read in from a file by .
* ScriptList::ParseScriptsDataChunk.
*		
*/

/**
* ScriptList::WriteScriptsDataChunk - Writes a Scripts chunk.
* Format is the newer CHUNKY format.
*	See ScriptEngine::ParseScriptsDataChunk for the reader.
*	Input: DataChunkInput 
*		
*/
// BFME's two writers are FREE functions taking the list itself as a second
// argument, not the static members the reference calls with two -- and it writes
// the GROUP chunk first. The reference copy writes the script chunk first, so
// the two produce different chunk orders in the saved map.
void WriteGroupDataChunk( DataChunkOutput &chunkWriter, ScriptList *scriptList, ScriptGroup *scriptGroup );
void WriteScriptDataChunk( DataChunkOutput &chunkWriter, ScriptList *scriptList, Script *script );

struct BfmeScriptListHeads
{
	UnsignedByte m_unreconstructed_00[4];
	Script *m_firstScript;						///< retail this+0x04
	ScriptGroup *m_firstGroup;					///< retail this+0x08
};

//
// Blocked on the row's own object-symbol note, which is a variant worth knowing.
// The row is NAMED ...QAPAV1@H@Z but carries
// object-symbol=?WriteScriptsDataChunk@ScriptList@@SAXAAVDataChunkOutput@@PBQAV1@H@Z,
// so the gate reads that second spelling out of the object. PBQAV1@ is what a
// parameter declared `ScriptList *const []' mangles to -- the donor's own
// declaration -- while this file's header declares `ScriptList *[]' and emits
// QAPAV1@. The two are different parameter TYPES, not a top-level const, so the
// destination cannot emit the donor's spelling without changing Scripts.h, and
// that is a wide header change for one body. It fails as "symbol not found in
// object", the same way an access-specifier mismatch does.
//
// The body itself is authored and the finding stands: BFME inlines the per-list
// writes here rather than calling WriteScriptListDataChunk, and writes the group
// chunk before the script chunk where the reference does the reverse.
// ScriptList::WriteScriptsDataChunk: defined in ScriptList_WriteScriptsDataChunk.cpp (its row's unit).



/**
* ScriptList::WriteScriptListDataChunk - Writes a Scripts chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/

// ?WriteScriptListDataChunk@ScriptList@@QAEXAAVDataChunkOutput@@@Z
// ScriptList::WriteScriptListDataChunk: defined in ScriptList_WriteScriptsDataChunk.cpp (its row's unit).


/**
* ScriptList::ParseScriptListDataChunk - read a Scripts chunk.
* Format is the newer CHUNKY format.
*	See ScriptList::WriteScriptListDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/
// byte-exact reconstruction: Code/GameEngine/Source/Common/ScriptList_ParseScriptListDataChunkThunk.cpp


//-------------------------------------------------------------------------------------------------
// ******************************** class  ScriptGroup *********************************************
//-------------------------------------------------------------------------------------------------

/**
  Ctor - gives it a default name.
*/

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version 
	* 2: m_isGroupActive, since it is twiddled by other scripts.  Only its initial state is determined by the map.
*/
// ------------------------------------------------------------------------------------------------
// Matched body: ScriptGroupXfer.cpp @ 0x350E90 (not this ZH list-walk; queue 0xAF9B24 was jmp-table).
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptGroupXfer.cpp

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------

/**
  ScriptGroup::duplicate - Creates a full, "deep" copy of ScriptGroup.
	m_nextGroup is NULL on the copy.
*/

/**
  ScriptGroup::duplicateAndQualify - Creates a full, "deep" copy of ScriptGroup, 
	adding qualifier to names.
	m_nextGroup is NULL on the copy.
*/

/**
  Delete a script from the current list of scripts.
*/

/**
  Add a script to the current list of scripts.  Offset to position ndx.
*/
// byte-exact reconstruction: Code/GameEngine/Source/Common/ScriptGroup_addScript_Thunk.cpp

/**
* ScriptGroup::WriteGroupDataChunk - Writes a Scripts chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/

/**
* ScriptGroup::ParseGroupDataChunk - read a Group chunk.
* Format is the newer CHUNKY format.
*	See ScriptList::WriteScriptListDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/

//-------------------------------------------------------------------------------------------------
// ******************************** class  Script *********************************************
//-------------------------------------------------------------------------------------------------
/**
  Ctor - initializes members.
*/
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptCtor.cpp
// Script::Script (?) is rowed in ScriptWriteDataChunk.cpp; a second definition here would not link.

/**
  Dtor - The condition and action deletes the rest of the list, but we have to loop & delete
	all the scripts in out list.
*/

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version */
// ------------------------------------------------------------------------------------------------
// Matched BFME 2 Script::xfer is defined in ScriptXfer.cpp (0x003B2540).

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
// ?loadPostProcess@Script@@MAEXXZ present-unmatched
void Script::loadPostProcess( void )
{

}  // end loadPostProcess

/**
  Script::duplicate - Creates a full, "deep" copy of script. Condition list and action
  list is duplicated as well.  Note - just the script, doesn't
	duplicate a list of scripts.  m_nextScript is NULL on the copy.
*/
// ?duplicate@Script@@QBEPAV1@XZ is a row of ScriptDuplicate.cpp; this unit's copy was
// a second, non-retail definition of it.

/**
  Script::duplicate - Creates a full, "deep" copy of script, with qualifier 
  added to names. Condition list and action
  list is duplicated as well.  Note - just the script, doesn't
	duplicate a list of scripts.  m_nextScript is NULL on the copy.
*/

/**
  Script::updateFrom - Copies all the data from pSrc into this.  Any data in this 
	is deleted (conditions, actions).  Note that this guts pSrc, and removes it's conditions
	and actions.  Intended for use in an edit dialog, where pSrc is a copy edited, and if cancelled
	discarded, and if not cancelled, updated into the real script, then discarded.
*/
// Script::updateFrom: byte-exact reconstruction on BFME 2's Script layout in
// Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptDeleteClauses.cpp.

/**
  Script::deleteOrCondition - delete pCond from the or condition list.
*/
// Script::deleteOrCondition: byte-exact reconstruction on BFME 2's Script layout in
// Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptDeleteClauses.cpp.


/**
  Script::deleteAction - delete pAct from the action list.
*/


/**
  Script::deleteFalseAction - delete pAct from the false action list.
*/


/**
  Script::getUiText - Creates the string to display in the scripts dialog box.
*/
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/Script_getUiText_Thunk.cpp
// Byte-exact BFME2 UI formatter lives in ScriptGetUiText.cpp.

/**
* Script::WriteScriptDataChunk - Writes a Scripts chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/
/**
* Script::ParseScript - read a script chunk.
* Format is the newer CHUNKY format.
*	See ScriptList::WriteScriptDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/Script_ParseScript_Thunk.cpp

/**
* Script::ParseScriptFromListDataChunk - read a script chunk in a script list.
* Format is the newer CHUNKY format.
*	See ScriptList::WriteScriptListDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/

/**
* Script::ParseScriptFromGroupDataChunk - read a script chunk in a script group.
* Format is the newer CHUNKY format.
*	See ScriptList::WriteScriptListDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/


/**
* Script::findPreviousOrCondition - find the OrCondition that immediately proceeds curOr.
*	Input: OrCondition 
*		
*/

//-------------------------------------------------------------------------------------------------
// ******************************** class  OrCondition *********************************************
//-------------------------------------------------------------------------------------------------

OrCondition *OrCondition::duplicate(void) const 
{
	OrCondition *pNew = newInstance(OrCondition);	
	if (m_firstAnd) {
		pNew->m_firstAnd = m_firstAnd->duplicate();
	}
	OrCondition *pLink = m_nextOr;
	OrCondition *pCur = pNew;
	while (pLink) {
		pCur->m_nextOr = newInstance(OrCondition);
		pCur = pCur->m_nextOr;
		if (pLink->m_firstAnd) {
			pCur->m_firstAnd = pLink->m_firstAnd->duplicate();
		}
		pLink = pLink->m_nextOr;
	}
	return pNew;
}


Condition *OrCondition::removeCondition(Condition *pCond)
{
	Condition *pPrev = NULL;
	Condition *pCur = m_firstAnd;
	while (pCond != pCur) {
		pPrev = pCur;
		pCur = pCur->getNext();
	}

	DEBUG_ASSERTCRASH(pCur, ("Couldn't find condition."));
	if (pCur==NULL) 
		return NULL;
	if (pPrev) {
		pPrev->setNextCondition(pCur->getNext());
	} else {
		m_firstAnd = pCur->getNext();
	}

	pCur->setNextCondition(NULL);
	return pCur;
}

void OrCondition::deleteCondition(Condition *pCond)
{
	// Retail 0x003B26A1: removeCondition, then a global-scope delete: the
	// virtual destructor through vtable[0] with flags 0, whose returned
	// complete-object pointer goes to ::operator delete. Condition's
	// destructor is protected; the PublicDtor cast reaches the same call.
	Condition *pCur = removeCondition(pCond);
	if (pCur == NULL)
		return;
	struct PublicDtor { virtual ~PublicDtor() {} };
	::delete (PublicDtor *)pCur;
}


/**
* OrCondition::WriteOrConditionDataChunk - Writes a Or condition chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/
// OrCondition::WriteOrConditionDataChunk: defined in OrConditionWriteOrConditionDataChunk.cpp (its row's unit).

/**
* OrCondition::ParseOrConditionDataChunk - read a Or condition chunk.
* Format is the newer CHUNKY format.
*	See OrCondition::WriteOrConditionDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/

/**
* OrCondition::findPreviousCondition - find the condition that immediately proceeds curCond.
* Format is the newer CHUNKY format.
*	See OrCondition::WriteOrConditionDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/
Condition *OrCondition::findPreviousCondition( Condition *curCond )
{
	Condition *myConditions = getFirstAndCondition();
	if (myConditions == curCond) {
		return NULL;
	}

	while (myConditions) {
		if (myConditions->getNext() == curCond) {
			return myConditions;
		}
		myConditions = myConditions->getNext();
	}

	DEBUG_CRASH(("Searched for non-existent And Condition. (jkmcd)"));
	return NULL;
}


//-------------------------------------------------------------------------------------------------
// ******************************** class  Condition *********************************************
//-------------------------------------------------------------------------------------------------
// Owned by ConditionCtor.cpp.

// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/Condition_setConditionType_Thunk.cpp
// Condition::setConditionType: defined in Rva003b6d92Finish.cpp (its row's unit).

// Owned by ConditionDuplicate.cpp.


// Condition::~Condition (0x003B4230) is defined in ScriptConditionActionDtors.cpp.



// Condition::getUiStrings: defined in ConditionGetUiStrings.cpp (its row's unit).

// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/Condition_getUiText_Thunk.cpp
AsciiString Condition::getUiText(void)
{
	AsciiString uiText;
	AsciiString strings[MAX_PARMS];
	Int numStrings = getUiStrings(strings);
	Int i;

	if (m_hasWarnings) {
		uiText = "[???]";
	}

	for (i=0; i<MAX_PARMS; i++) {
		if (i<numStrings) {
			((StringBase<char> *)&uiText)->concat(*(const StringBase<char> *)&strings[i]);
		}
		if (i<m_numParms) {
			uiText.concat(m_parms[i]->getUiText());
		}
	}

	return uiText;
}


/**
* Condition::WriteConditionDataChunk - Writes a condition chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/
// Condition::WriteConditionDataChunk: defined in ConditionWriteDataChunk.cpp (its row's unit).
// Condition::ParseConditionDataChunk: defined in Rva003b6d92Finish.cpp (its row's unit).


// The exact retail constructor is emitted by Template.cpp.

//-------------------------------------------------------------------------------------------------
// ******************************** class Parameter ***********************************************
//-------------------------------------------------------------------------------------------------
// Template::getParameterType: defined in Rva003b6d92Finish.cpp (its row's unit).

// Parameter::getCoord3D: defined in ParameterGetCoord3D.cpp (its row's unit).

// Parameter::setCoord3D: defined in ParameterSetCoord3D.cpp (its row's unit).


// Parameter::getUiText: defined in ParameterGetUiTextBody.cpp (its row's unit).

/**
* Parameter::WriteParameter - Writes an Parameter.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/
// Parameter::WriteParameter: defined in Parameter_WriteParameter.cpp (its row's unit).

/**
* Parameter::ReadParameter - read a parameter.
* Format is the newer CHUNKY format.
*	See Parameter::WriteParameter for the writer.
*	Input: DataChunkInput 
*		
*/
// ?ReadParameter@Parameter@@SAPAV1@AAVDataChunkInput@@@Z
// Body in Code/masm_dumps/_sa3__ReadParameter_Parameter__SAPAV1_AAVDataChunkInput_357FC0.asm (exact 748B retail @ 0x00357FC0).
//-------------------------------------------------------------------------------------------------
// ******************************** class ScriptAction ***********************************************
//-------------------------------------------------------------------------------------------------
// Owned by ScriptActionCtor.cpp.

// ScriptAction::setActionType: defined in Rva003b6d92Finish.cpp (its row's unit).

// Owned by ScriptActionDuplicate.cpp.


// ScriptAction::~ScriptAction is owned by ScriptConditionActionDtors.cpp.

// ScriptAction::getUiStrings: defined in ScriptActionGetUiStrings.cpp (its row's unit).

// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptAction_getUiText_Thunk.cpp
// ScriptAction::getUiText: defined in ScriptActionGetUiText.cpp (its row's unit).

/**
* ScriptAction::WriteActionDataChunk - Writes an Action chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/

// ScriptAction::ParseAction: BFME's reader is reconstructed in ScriptActionParseAction.cpp; ZH's
// version here was not retail's and emitted Parameter's constructor ahead of its retail copy.

/**
* ScriptAction::ParseActionDataChunk - read an action chunk in a script list.
* Format is the newer CHUNKY format.
*	See ScriptAction::WriteActionDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptsParseActionDataChunkThunk.cpp


/**
* ScriptAction::WriteActionFalseDataChunk - Writes a false Action chunk.
* Format is the newer CHUNKY format.
*	Input: DataChunkInput 
*		
*/

/**
* ScriptAction::ParseActionFalseDataChunk - read a false action chunk in a script list.
* Format is the newer CHUNKY format.
*	See ScriptAction::WriteActionDataChunk for the writer.
*	Input: DataChunkInput 
*		
*/
// byte-exact reconstruction: Code/GameEngine/Source/GameLogic/ScriptEngine/ScriptAction_ParseActionFalseDataChunk_Thunk.cpp

// NOTE: Changing these or adding ot TheOBjectFlagNames requires changes to 
// ScriptActions::changeObjectPanelFlagForSingleObject
// THEY SHOULD STAY IN SYNC.
const char* TheObjectFlagsNames[] = 
{ 
	"Enabled",
	"Powered",
	"Indestructible",
	"Unsellable",
	"Selectable",
	"AI Recruitable",
	"Player Targetable",
	NULL,
};
