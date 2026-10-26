// cl: /Ireference/shims/zh_outofline /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib
// stlport
// Initially ported verbatim from the Generals Zero Hour reference;
// loadPostProcess is adapted below to independently verified BFME2 behavior.
// (GameEngine/Source/GameLogic/Object/Contain/OpenContain.cpp); this unit had no counterpart under Code/.
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

// FILE: OpenContain.cpp //////////////////////////////////////////////////////////////////////////
// Author: Colin Day, November 2001
// Desc:   The OpenContain ContainModule allows objects to be contained inside of other
//				 objects.  There is a set of functionality that will be common to 
//				 all container modules that provides the actual containment
//				 implementations, those implementations are found here
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine
// vector::_M_insert_overflow inlines max(size(), n). A file-static unsigned
// overload takes the call instead, so this TU emits no external max COMDAT.
namespace _STL {
static inline const unsigned int &max(const unsigned int &a, const unsigned int &b)
{
    return a < b ? b : a;
}
}
#include <map>

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
template <class T, class LeftTraits, class RightTraits>
static inline bool operator!=(const _Rb_tree_iterator<T, LeftTraits>& a,
                              const _Rb_tree_iterator<T, RightTraits>& b)
{ return a._M_node != b._M_node; }
}
#include <list>

// Compare nodes locally so this TU does not emit a conflicting iterator-base wrapper.
namespace _STL {
template <class T, class LeftTraits, class RightTraits>
static inline bool operator!=(const _List_iterator<T, LeftTraits>& a,
                              const _List_iterator<T, RightTraits>& b)
{ return a._M_node != b._M_node; }
}

#include <vector>
// Bind assignment to the complete rowed provider at 0x002CD098.
namespace _STL {
template <> vector<Coord3D, allocator<Coord3D> > &
vector<Coord3D, allocator<Coord3D> >::operator=(const vector<Coord3D, allocator<Coord3D> > &);
// Retain this unit's rowed capacity helper after assignment becomes external.
template unsigned int vector<Coord3D, allocator<Coord3D> >::capacity() const;
}

#include "Common/BitFlagsIO.h"
#include "Common/GameAudio.h"
#include "Common/GameState.h"
#include "Common/Module.h"
#include "Common/Player.h"
#include "Common/RandomValue.h"
#include "Common/ThingTemplate.h"
#include "Common/Xfer.h"

#include "GameClient/Drawable.h"
#include "GameClient/InGameUI.h"
#include "GameClient/ControlBar.h"

#include "GameLogic/AIPathfind.h"
#include "GameLogic/GameLogic.h"
#include "GameLogic/Module/OpenContain.h"
#include "GameLogic/Module/AIUpdate.h"
#include "GameLogic/Module/PhysicsUpdate.h"
#include "GameLogic/Module/StealthUpdate.h"
#include "GameLogic/Module/BodyModule.h"
#include "GameLogic/Object.h"
#include "GameLogic/PartitionManager.h"
#include "GameLogic/Weapon.h"
// Suppress this TU's non-retail copy of ?_M_is_equal@?$_Base_bitset@$03@_STL@@QBE_NABU12@@Z:
// the kept copy serves the link. Plain declaration-only form (no __imp_).
namespace _STL { template <> bool _Base_bitset<4>::_M_is_equal(_Base_bitset<4> const &) const; }

#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// ??0OpenContainModuleData@@QAE@XZ owned by OpenContainModuleDataCtor.cpp; declared here only.

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// ?buildFieldParse@OpenContainModuleData@@SAXAAVMultiIniFieldParse@@@Z owned by ModuleDataBuildFieldParseChained.cpp; declared here only.

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// ??0OpenContain@@QAE@PAVThing@@PBVModuleData@@@Z owned by OpenContainCtor.cpp; declared here only.

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// containReactToTransformChange: OpenContainReactToTransformChange.cpp (retail 0x004624E3).

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// ?OpenContain::update present-unmatched
UpdateSleepTime OpenContain::update( void )
{
	m_playerEnteredMask = 0;

	// we need to monitor changes in the art and position
	monitorConditionChanges();

	if( m_doorCloseCountdown )
	{
		/// @todo srj -- for now, OpenContain assumes at most one door
		--m_doorCloseCountdown;
		if( m_doorCloseCountdown == 0 )
			getObject()->clearAndSetModelConditionState( MODELCONDITION_DOOR_1_OPENING, MODELCONDITION_DOOR_1_CLOSING );
	}

	if (!m_objectEnterExitInfo.empty())
		pruneDeadWanters();

	return UPDATE_SLEEP_NONE;
}

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/** Add 'rider' to the m_containList of objects in this module.
	* This will trigger an onContaining event for the object that this module
	* is a part of and an onContainedBy event for the object being contained */
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/** Remove 'rider' from the m_containList of objects in this module.
	* This will trigger an onRemoving event for the object that this module
	* is a part of and an onRemovedFrom event for the object being removed */
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/** Remove all contained objects from the contained list */
//-------------------------------------------------------------------------------------------------
// OpenContain::removeAllContained is defined with its retail-matched body in Code/GameEngine/Source/GameLogic/Object/Contain/OpenContain_removeAllContained_Rva004635C0.cpp (0x004635C0).

//-------------------------------------------------------------------------------------------------
/** Kill all contained objects in the contained list */
//-------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------
/** Force all contained objects in the contained list to exit, and kick them in the pants on the way out*/
//--------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
/** Iterate the contained list and call the callback on each of the objects */
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// OpenContain::getClosestRider: retail's body is the row at 0x004632E0
// (OpenContainRva004638F1.cpp); this unit only declares it, so its vtable binds there.





//-------------------------------------------------------------------------------------------------
struct DropData
{
	Real minRadius;
	Real maxRadius;
	Object *container;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS //////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
/** Remove an object from the containment of this module given the item
	* to remove and trigger the proper callback events */
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// OpenContain::onContaining is defined with its independently verified BFME2
// body in Rva00463097Audio.cpp (0x00463097), which keys the enter sound
// by the owner's Drawable instead of the donor's template sound.

//-------------------------------------------------------------------------------------------------
// OpenContain::onRemoving is defined with its independently verified BFME2
// body in OpenContainOnRemoving.cpp (0x00464D02). It extends the donor's two
// audio scopes with keyed Drawable lookups, map cleanup and timed bonuses.

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/** The die callback: retail body lives in OpenContainOnDie.cpp (rowed at
0x004641B1); this TU keeps the class declaration only. */  

// ------------------------------------------------------------------------------------------------
/** Check to see if we are a valid container for 'obj' */
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
// OpenContain::exitObjectViaDoor (0x0046525F) and exitObjectInAHurry (0x004656DF) are BFME2 code
// with a different module layout; they live in OpenContainExitObjectInAHurry.cpp.


//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/** Check to see if our internal knowledge of the artwork matches the current state of
	* the model being displayed.  When changes occur (from changing the time of day or going
	* to a new damage state, we will want to redeploy all our occupants to be at new fire
	* points that are reflected in the new artwork */
//-------------------------------------------------------------------------------------------------
// OpenContain::monitorConditionChanges: retail's body is the row at 0x00462C72
// (OpenContainRva00462C72.cpp); this unit only declares it, so its vtable binds there.

// ------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------
// OpenContain::redeployOccupants: retail's body is the row at 0x00464286
// (OpenContainRva00464286.cpp); this unit only declares it, so its vtable binds there.
// Its Zero Hour loop was the only user of these reverse-iterator compares, which are
// rowed in this unit, so instantiate them explicitly.
template bool std::operator==(const ContainedItemsList::const_reverse_iterator &, const ContainedItemsList::const_reverse_iterator &);
template bool std::operator!=(const ContainedItemsList::const_reverse_iterator &, const ContainedItemsList::const_reverse_iterator &);

//-------------------------------------------------------------------------------------------------
/** Place the object at the 3D position of the next fire point to use */
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
/**
	this is used for containers that must do something to allow people to enter or exit...
	eg, land (for Chinook), open door (whatever)... it's called with wants=WANTS_TO_ENTER
	when something is in the enter state, and wants=WANTS_NOTHING when the unit has
	either entered, or given up...
*/

//-------------------------------------------------------------------------------------------------
// ?OpenContain::pruneDeadWanters present-unmatched
void OpenContain::pruneDeadWanters()
{
	for (ObjectEnterExitMap::iterator it = m_objectEnterExitInfo.begin(); it != m_objectEnterExitInfo.end(); /*++it*/)
	{
		ObjectID id = (*it).first;
		Object* obj = TheGameLogic->findObjectByID(id);
		if (obj == NULL || obj->isEffectivelyDead())
		{
			ObjectEnterExitMap::iterator tmp = it;
			++it;
			m_objectEnterExitInfo.erase(tmp);
		}
		else
		{
			++it;
		}
	}
}

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

 
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// OpenContain::getNaturalRallyPoint (0x0046363F) is rowed in SlaughterHordeContainIterate.cpp; a second definition here would not link.







//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------











// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version */
// ------------------------------------------------------------------------------------------------
// OpenContain::xfer is defined by the retail-matched BFME2 body at
// 0x00465EF1 in OpenContainXfer.cpp. The donor layout is different.
  // end xfer

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
// Native 0x00463C6E..0x00463D58 restoration: owner +8, secondary
// interface +0x20 / slot 44 returns a 16-byte mask, word 1 bit 29.
// Lists +0x54/+0x74 and Object +0x250/+0x274 are target evidence;
// the ZH/BFME1 loadPostProcess body supplies purpose and source provenance.
// The enclosing walk is computed once before the restored-rider loop.
// Slot 24's trailing zero arguments retain their unknown target meanings.
class XferException {
public:
    XferException(int, const char *, ...);
    XferException(const XferException &);
    ~XferException();
    char *text;
    int tag;
};
template <int N> class Rva00463C6ESlots : public Rva00463C6ESlots<N - 1> {
public: virtual void gap(char (*)[N]);
};
template <> class Rva00463C6ESlots<0> {};
struct Rva00463C6EMask { unsigned int words[4]; bool test(int i) const { return (words[i / 32] >> (i % 32)) & 1; } };
class Rva00463C6EStatus : public Rva00463C6ESlots<44> {
public: virtual Rva00463C6EMask status(int);
};
class Rva00463C6EView;
class Rva00463C6EModule : public Rva00463C6ESlots<1> {
public: virtual Rva00463C6EView *contain() = 0;
};
struct Rva00463C6EObject {
    char unknown00[0x250];
    Rva00463C6EModule *module250;
    char unknown254[0x274 - 0x254];
    Object *containedBy274;
};
class Rva00463C6EView : public Rva00463C6ESlots<24> {
public:
    virtual void slot24(Object *, int, int) = 0;
    void *moduleData;
    Object *owner;
    char unknown0C[0x20 - 0xC];
    Rva00463C6EStatus status20;
    char unknown24[0x54 - 0x24];
    _STL::list<int> riders54;
    char unknown58[0x74 - 0x58];
    _STL::list<int> restoreIDs74;
};
void OpenContain::loadPostProcess()
{
    Rva00463C6EView *self = reinterpret_cast<Rva00463C6EView *>(this);
    Object *owner = self->owner;
    UpdateModule::loadPostProcess();
    if (!self->riders54.empty())
        throw XferException(5, 0);
    bool enclosing = false;
    Rva00463C6EView *probe = self;
    do {
        if (probe->status20.status(0).test(61)) {
            enclosing = true;
            break;
        }
        Object *object = probe->owner;
        if (!object) break;
        Object *outer = reinterpret_cast<Rva00463C6EObject *>(object)->containedBy274;
        if (!outer) break;
        Rva00463C6EModule *module = reinterpret_cast<Rva00463C6EObject *>(outer)->module250;
        if (!module) break;
        probe = module->contain();
    } while (probe);
    for (_STL::list<int>::iterator it = self->restoreIDs74.begin(); it != self->restoreIDs74.end(); ++it) {
        Object *rider = TheGameLogic->findObjectByID((ObjectID)*it);
        if (!rider) throw XferException(5, 0);
        self->riders54.push_back(reinterpret_cast<const int &>(rider));
        if (enclosing) self->slot24(rider, 0, 0);
        reinterpret_cast<Rva00463C6EObject *>(rider)->containedBy274 = owner;
    }
    self->restoreIDs74.clear();
}

// Complete native entry 0x0046491E..0x00464923 forwards the unchanged
// receiver and key reference to the verified erase at 0x004643E8 and
// returns its unsigned count. The record/tree view is already established;
// keep an address-derived label for the unidentified containing wrapper.
struct Rva00463E09Record;
typedef _STL::_Rb_tree<int, _STL::pair<int const, Rva00463E09Record>,
	_STL::_Select1st<_STL::pair<int const, Rva00463E09Record> >,
	_STL::less<int>, _STL::allocator<_STL::pair<int const, Rva00463E09Record> > > Rva0046491ETree;
// Use the existing verified provider without emitting another template copy.
namespace _STL {
template <> unsigned int Rva0046491ETree::erase(const int &);
}
class Rva0046491E : public Rva0046491ETree
{
public:
	unsigned int rva0046491E(const int &key);
};

unsigned int Rva0046491E::rva0046491E(const int &key)
{
	return erase(key);
}
