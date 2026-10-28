// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/open-bfme-1/inputs/reference/shims/display /Ireference/open-bfme-1/inputs/reference/shims/mouselayout /Ireference/open-bfme-1/inputs/reference/shims/sweep /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main
// stlport
//
// ?setPosition@Win32Mouse@@UAEXHH@Z, retail 0x00041AD4 (60B).
// Target facts: 0x00041AD4 fills slot 17 (setPosition, between
// createStreamMessages and setCursor) of two vftables: ??_7Win32Mouse@@6B@
// 0x007C2478, whose other slots include Win32Mouse::update 0x00041A0B,
// initCursorResources 0x00041BA6 and setCursor 0x00041A83, and ??_7W3DMouse@@6B@
// 0x007C86D8, which inherits it beside W3DMouse::draw 0x000992B0 and setCursor
// 0x00099DCC. No other absolute pointer in the image references it, and
// the body sits in Win32Mouse.cpp's run between setCursor 0x00041A83 and
// getMouseEvent 0x00041B10. It calls Mouse::setPosition 0x001EDE4C, then
// ClientToScreen(ApplicationHWnd) and SetCursorPos.
// Donor facts: Zero Hour's Win32Mouse has no setPosition; its
// DirectInputMouse::setPosition (Win32DIMouse.cpp) is this body, and this file
// was first ported from Open-BFME-1's Win32DIMouse.cpp (donor revision
// 6d9434269164392c5ba62aaa7c15a86b5b020d76, donor flags plus /O1), placed by
// masked whole-.text search under the DirectInputMouse name.
// Inference: BFME 2 gave Win32Mouse that override; the retail body is
// Win32Mouse::setPosition. The file keeps the donor port's compile environment.
#define Matrix4x4 Matrix4  // BFME renamed it
#define __PLACEMENT_VEC_NEW_INLINE  // always.h/GameMemory.h define array placement-new themselves
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

// FILE: Win32DIMouse.cpp /////////////////////////////////////////////////////////////////////////
// Created:    Colin Day, June 2001
// Desc:       Win32 direct input implementation for the mouse
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <windows.h>
#include <assert.h>

#include "Common/Debug.h"
#include "Common/GameType.h"	// TimeOfDay, for the BFME Display shim
#include "GameClient/Display.h"
#define __WIN32DIMOUSE_H_
// This unit declares the one Win32Mouse override it defines (below), so the
// shim's Win32Mouse.h, which lacks setPosition, stays out (WinMain.h includes it).
#define __WIN32MOUSE_H_
#ifndef DIRECTINPUT_VERSION
#	define DIRECTINPUT_VERSION	0x800
#endif
// Retail reaches DirectInput8Create with a direct `call rel32` at 0x6BBAC0, so
// it links dinput8.lib's stub rather than going through the import table; the
// sweep shim declares it __declspec(dllimport), which costs a `call [import]`
// one byte longer. Renaming the shim's declaration out of the way and giving
// the real one ordinary external linkage restores the retail call shape without
// touching the shim (a shim edit forces the full gate, which is red).
#define DirectInput8Create _bfme_dinput8create_dllimport_unused
// USER32 imports use C linkage in retail (ClipCursor, LoadCursorA,
// ReleaseCapture and SetCapture); the local dinput shim omits that linkage.
extern "C" {
#include <dinput.h>
}
#undef DirectInput8Create
extern "C" HRESULT WINAPI DirectInput8Create( HINSTANCE, DWORD, REFIID, void **, IUnknown * );

#include "GameClient/Mouse.h"

// dinput.h's DIERR_NOTACQUIRED is HRESULT_FROM_WIN32(ERROR_INVALID_ACCESS==12),
// which is what getMouseEvent @0x6BBC59 compares against. The sweep shim has
// 0x8007001A; correcting it there is another shim edit, so it is corrected here.
#undef DIERR_NOTACQUIRED
#define DIERR_NOTACQUIRED            0x8007000CL

// Same story for DIDC_FORCEFEEDBACK: dinput.h has it at 0x100, and openMouse
// @0x6BBB91 shifts dwFlags right by 8 before masking bit 0. The shim has 1.
#undef DIDC_FORCEFEEDBACK
#define DIDC_FORCEFEEDBACK           0x00000100

// Only the override this unit defines; the rest of BFME 2's Win32Mouse lives in
// Win32Mouse.cpp.
class Win32Mouse : public Mouse
{

public:

	virtual void setPosition( Int x, Int y );  ///< set position for mouse

};  // end class Win32Mouse

#include "WinMain.h"

// DEFINES ////////////////////////////////////////////////////////////////////////////////////////
enum { MOUSE_BUFFER_SIZE = 256, };


  // end setMouseLimits

//-------------------------------------------------------------------------------------------------
/** set the cursor position for windows OS */
//-------------------------------------------------------------------------------------------------
void Win32Mouse::setPosition( Int x, Int y )
{
	POINT p;

	// extending functionality
	Mouse::setPosition( x, y );

	// set the windows cursor
	p.x = x;
	p.y = y;
	ClientToScreen( ApplicationHWnd, &p );

	// set the window mouse
	SetCursorPos( p.x, p.y );

}


  // end releaseCapture
