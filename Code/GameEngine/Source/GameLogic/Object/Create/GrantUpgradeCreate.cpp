// cl: /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /DWIN32 /D_WINDOWS /DBFME_MODULE_NO_MPO /MD /EHsc /Ireference/open-bfme-1/reference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad
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

// FILE: GrantUpgradeCreate.cpp ////////////////////////////////////////////////////////////////////////
// Author: Kris Morness, April 2002
// Desc:   GrantUpgrade create module
///////////////////////////////////////////////////////////////////////////////////////////////////

// INCLUDES ///////////////////////////////////////////////////////////////////////////////////////
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#define DEFINE_OBJECT_STATUS_NAMES
#include "Common/Player.h"
#include "Common/Upgrade.h"
#include "Common/Xfer.h"
#include "GameLogic/Module/GrantUpgradeCreate.h"
#include "GameLogic/Object.h"

// LINK-DUP: ??0GrantUpgradeCreateModuleData and
// ?buildFieldParse@GrantUpgradeCreateModuleData are owned by
// GrantUpgradeCreateModuleDataCtor.cpp and CreateModuleDataBuildFieldParse.cpp;
// this file merely declares them via its headers (no definitions here).

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// The module hierarchy needs BFME_MODULE_NO_MPO on this file's own cl line:
// retail's Module has no MemoryPoolObject base, so BehaviorModule spans 0x0C
// and this constructor's second vtable store lands at +0x0C, where the wider
// layout puts a fourth vptr at +0x04 and +0x14 and shifts everything.
GrantUpgradeCreate::GrantUpgradeCreate( Thing *thing, const ModuleData* moduleData ) : CreateModule( thing, moduleData )
{
}  // end GrantUpgradeCreate

//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
// ??1GrantUpgradeCreate@@MAE@XZ
// ??1GrantUpgradeCreate@@MAE@XZ present-unmatched
GrantUpgradeCreate::~GrantUpgradeCreate( void )
{

}  // end ~GrantUpgradeCreate

//-------------------------------------------------------------------------------------------------
// GrantUpgradeCreate::onCreate (retail 0x004B901D) and ::onBuildComplete
// (0x004B9093) are matched in SupplyWarehouseCreateRva004B901D.cpp and
// SupplyWarehouseCreateRva004B9093.cpp: slots 0 and 1 of the CreateModuleInterface
// vftable 0x00859428 that the constructor above stores at +0x10. The unmatched
// Zero Hour bodies that stood here would define the same symbols a second time.
//-------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------
/** CRC */
// ------------------------------------------------------------------------------------------------
// ?crc@GrantUpgradeCreate@@MAEXPAVXfer@@@Z present-unmatched
void GrantUpgradeCreate::crc( Xfer *xfer )
{

	// extend base class
	CreateModule::crc( xfer );

}  // end crc

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version */
// ------------------------------------------------------------------------------------------------
// ?xfer@GrantUpgradeCreate@@MAEXPAVXfer@@@Z present-unmatched
void GrantUpgradeCreate::xfer( Xfer *xfer )
{

	// version
	XferVersion currentVersion = 1;
	XferVersion version = currentVersion;
	xfer->xferVersion( &version, currentVersion );

	// extend base class
	CreateModule::xfer( xfer );

}  // end xfer

// ------------------------------------------------------------------------------------------------
/** Load post process */
// ------------------------------------------------------------------------------------------------
// ?loadPostProcess@GrantUpgradeCreate@@MAEXXZ present-unmatched
void GrantUpgradeCreate::loadPostProcess( void )
{

	// extend base class
	CreateModule::loadPostProcess();

}  // end loadPostProcess
