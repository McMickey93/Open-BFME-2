// cl: /O1 /Ireference/shims/zh_outofline /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib /Ireference/shims
// platformsdk
// dxsdk
// stlport
// Ported verbatim from the Generals Zero Hour reference
// (GameEngine/Source/GameClient/GUI/GameWindowManager.cpp); this unit had no counterpart under Code/.
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

// FILE: GameWindowManager.cpp ////////////////////////////////////////////////////////////////////
// Created:   Colin Day, June 2001
//						Dean Iverson, March 1998 (Original window code)
// Desc:      The game window manager is the singleton class that we interface
//						with to interact with the game windowing system.
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

// Retail's DisplayString vtable calls getText at slot 2 (0x8), proven by the
// rowed getTooltipText at 0x002C1FA0; the Zero Hour donor DisplayString.h
// derives from MemoryPoolObject, whose extra virtual puts getText at slot 3,
// so this unit emitted a deviant getTooltipText copy and lost the COMDAT.
// TU-local view with retail's slot order (same as WinInstanceDataDisplayStrings.cpp).
// The donor UnicodeString header is pulled explicitly since the blocked header
// was this unit's carrier for it.
#include "Common/UnicodeString.h"
#define __DISPLAYSTRING_H_
class GameFont;
class DisplayString
{
public:
	virtual ~DisplayString() {}
	virtual void setText(UnicodeString text);
	virtual UnicodeString getText();
	virtual Int getTextLength();
	virtual void notifyTextChanged();
	virtual void reset();
	virtual void setFont(GameFont *font);
	virtual GameFont *getFont();
	virtual void setWordWrap(Int wordWrap) = 0;
	virtual void setWordWrapCentered(Bool isCentered) = 0;
};

// The donor WinInstanceData.h inline bodies for the four text accessors expand
// here to deviant copies (DisplayString slot 3, ZH UnicodeString copy), and
// the link then keeps this unit's getTooltipText instead of the rowed body at
// 0x002C1FA0. TU-local class view, verbatim from the donor header except those
// four stay declared-only so uses reach the rowed out-of-line bodies
// (getTooltipText 0x002C1FA0, getTooltipTextLength 0x002C027B, getText
// 0x003148F1, getTextLength 0x000A3DCC). Members are untouched, so layout and
// the GameWindow.h member-access inlines compile to the same bytes.
#include "Lib/BaseType.h"
#include "Common/AsciiString.h"
#include "GameClient/Color.h"
class Image;
class GameWindow;
class VideoBuffer;
#define __WININSTANCEDATA_H_

#define WIN_STATE_HILITED 	0x00000002
#define WIN_STATE_SELECTED	0x00000004

enum
{
	MAX_WINDOW_NAME_LEN = 64,
	MAX_DRAW_DATA = 9,
	MAX_TEXT_LABEL = 128
};

struct WinDrawData
{
	const Image *image;
	Color color;
	Color borderColor;
};

struct TextDrawData
{
	Color color;
	Color borderColor;
};

class WinInstanceData
{
public:
	WinInstanceData( void );
	virtual ~WinInstanceData( void );
	void init( void );
	void setTooltipText( UnicodeString tip );
	void setText( UnicodeString text );
	UnicodeString getTooltipText( void );
	UnicodeString getText( void );
	Int getTextLength( void );
	Int getTooltipTextLength( void );
	UnsignedInt getStyle( void ) { return m_style; }
	UnsignedInt getStatus( void ) { return m_status; }
	UnsignedInt getState( void ) { return m_state; }
	GameWindow *getOwner( void ) { return m_owner; }
	GameFont *getFont( void ) { return m_font; }
	DisplayString *getTextDisplayString( void ) { return m_text; }
	DisplayString *getTooltipDisplayString( void ) { return m_tooltip; }
	void setVideoBuffer( VideoBuffer * videoBuffer );

	Int m_id;
	Int m_state;
	UnsignedInt m_style;
	UnsignedInt m_status;
	GameWindow *m_owner;
	WinDrawData m_enabledDrawData[ MAX_DRAW_DATA ];
	WinDrawData m_disabledDrawData[ MAX_DRAW_DATA ];
	WinDrawData m_hiliteDrawData[ MAX_DRAW_DATA ];
	TextDrawData m_enabledText;
	TextDrawData m_disabledText;
	TextDrawData m_hiliteText;
	TextDrawData m_imeCompositeText;
	ICoord2D m_imageOffset;
	GameFont *m_font;
	AsciiString m_textLabelString;
	AsciiString m_decoratedNameString;
	AsciiString m_tooltipString;
	AsciiString m_headerTemplateName;
	Int m_tooltipDelay;
	DisplayString *m_text;
	DisplayString *m_tooltip;
	VideoBuffer *m_videoBuffer;
};

#include "Common/Debug.h"
#include "Common/Language.h"
#include "GameClient/Display.h"
#include "GameClient/GameWindowManager.h"
#include "GameClient/GameWindow.h"
#include "GameClient/Mouse.h"
#include "GameClient/DisplayStringManager.h"
#include "Gameclient/WindowLayout.h"
#include "GameClient/Gadget.h"
#include "GameClient/GameWindowGlobal.h"
#include "GameClient/GadgetListBox.h"
#include "GameClient/GadgetComboBox.h"
#include "GameClient/GadgetTabControl.h"
#include "GameClient/GadgetProgressBar.h"
#include "GameClient/GadgetStaticText.h"
#include "GameClient/GadgetTextEntry.h"
#include "GameClient/GadgetSlider.h"
#include "GameClient/GadgetRadioButton.h"
#include "GameClient/GadgetCheckBox.h"
#include "GameClient/GlobalLanguage.h"
#include "GameClient/GameWindowTransitions.h"
#include "Common/NameKeyGenerator.h"

// PUBLIC DATA ////////////////////////////////////////////////////////////////////////////////////
GameWindowManager *TheWindowManager = NULL;
UnsignedInt WindowLayoutCurrentVersion = 2;

///////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS //////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")
#endif

//
// with this statis set to true, the window system will propogate mouse position
// messages to windows.  You may want to disable this if you feel the mouse position
// messages are "spamming" your window and making a particular debuggin situation
// difficult.  Make sure you do enable this before you check in again tho because
// it is necessary for any code that needs to look at objects or anything under
// the radar cursor
//
static Bool sendMousePosMessages = TRUE;

//-------------------------------------------------------------------------------------------------
/** Process windows waiting to be destroyed */
//-------------------------------------------------------------------------------------------------
// GameWindowManager::processDestroyList: defined in GameWindowManager_processDestroyList.cpp (its row's unit).
  // end processDestroyList

///////////////////////////////////////////////////////////////////////////////////////////////////
// PUBLIC FUNCTIONS ///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// BFME's window manager carries winSendSystemMsg at vtable slot 58 (+0xE8);
// the shared Zero Hour header places it earlier.
class BfmeWindowManagerSendView
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
	virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
	virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
	virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
	virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
	virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
	virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
	virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
	virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
	virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
	virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
	virtual void slot56(); virtual void slot57();
	virtual WindowMsgHandledType winSendSystemMsg( GameWindow *window, UnsignedInt msg, WindowMsgData mData1, WindowMsgData mData2 );
};

//-------------------------------------------------------------------------------------------------
/** Generic function to simply propagate only button press messages to parent and let it deal with it */
//-------------------------------------------------------------------------------------------------
WindowMsgHandledType PassSelectedButtonsToParentSystem( GameWindow *window, UnsignedInt msg,
																												WindowMsgData mData1, WindowMsgData mData2 )
{

	// sanity
	if( window == NULL )
		return MSG_IGNORED;

	// BFME renumbered the later gadget messages: retail tests 0x4031 where the
	// shared Zero Hour enum puts GEM_EDIT_DONE at 0x402F, and adds 0x400B.
	if( (msg == GBM_SELECTED)  ||  (msg == GBM_SELECTED_RIGHT) || (msg == GBM_MOUSE_ENTERING) || (msg == GBM_MOUSE_LEAVING) || (msg == 0x4031) || (msg == 0x400B))
	{
		GameWindow *parent = window->winGetParent();

		if( parent )
			return ((BfmeWindowManagerSendView *)TheWindowManager)->winSendSystemMsg( parent, msg, mData1, mData2 );

	}  // end if
	
	return MSG_IGNORED;

}  // end PassSelectedButtonsToParentSystem

//-------------------------------------------------------------------------------------------------
/** Generic function to simply propagate only button press messages to parent and let it deal with it */
//-------------------------------------------------------------------------------------------------
WindowMsgHandledType PassMessagesToParentSystem( GameWindow *window, UnsignedInt msg,
																												WindowMsgData mData1, WindowMsgData mData2 )
{

	// sanity
	if( window == NULL )
		return MSG_IGNORED;


	GameWindow *parent = window->winGetParent();

	if( parent )
		return ((BfmeWindowManagerSendView *)TheWindowManager)->winSendSystemMsg( parent, msg, mData1, mData2 );
	
	return MSG_IGNORED;

}  // end PassSelectedButtonsToParentSystem


// GameWindowManager::reset: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::update: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::linkWindow: defined in GameWindowManager_linkWindow.cpp (its row's unit).

// GameWindowManager::unlinkWindow: defined in GameWindowManager_linkWindow.cpp (its row's unit).

// GameWindowManager::unlinkChildWindow: defined in GameWindowManager_linkWindow.cpp (its row's unit).

// GameWindowManager::isEnabled is defined in GameWindowManagerParentLinks.cpp.

// GameWindowManager::isHidden is defined in GameWindowManagerParentLinks.cpp.

// GameWindowManager::addWindowToParent is defined in GameWindowManagerParentLinks.cpp.

// GameWindowManager::addWindowToParentAtEnd: defined in GameWindowManager_enableWindowsInRange.cpp (its row's unit).

// GameWindowManager::windowHiding: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::hideWindowsInRange: defined in GameWindowManager_enableWindowsInRange.cpp (its row's unit).

// GameWindowManager::enableWindowsInRange: defined in GameWindowManager_enableWindowsInRange.cpp (its row's unit).

// GameWindowManager::winCapture: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::winRelease: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::winGetWindowFromId: defined in GameWindowManager_enableWindowsInRange.cpp (its row's unit).

// GameWindowManager::winSetFocus: defined in GameWindowManager_winSetFocus.cpp (its row's unit).

// GameWindowManager::winProcessMouseEvent: defined in GameWindowManagerMouseEvent.cpp (its row's unit).

// GameWindowManager::drawWindow: defined in GameWindowManager_drawWindow_Thunk.cpp (its row's unit).

// GameWindowManager::dumpWindow: defined in GameWindowManager_dumpWindow.cpp (its row's unit).

// GameWindowManager::winCreate: defined in GameWindowManager_dumpWindow.cpp (its row's unit).

// GameWindowManager::winDestroy: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::winDestroyAll: defined in GameWindowManager_winDestroyAll.cpp (its row's unit).

// GameWindowManager::winSetModal: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::winUnsetModal: defined in GameWindowManagerModal.cpp (its row's unit).

// GameWindowManager::winSetLoneWindow: defined in GameWindowManager_winSetLoneWindow.cpp (its row's unit).

// GameWindowManager::gogoGadgetListBox: defined in GameWindowManager_gogoGadgetListBox.cpp (its row's unit).

// GameWindowManager::gogoGadgetComboBox: defined in GameWindowManager_gogoGadgetComboBox.cpp (its row's unit).

// GameWindowManager::gogoGadgetTextEntry: defined in GameWindowManager_gogoGadgetTextEntry.cpp (its row's unit).

// GameWindowManager::winTextLabelToText: defined in GameWindowManager_winTextLabelToText.cpp (its row's unit).

// GameWindowManager::winNextTab: defined in GameWindowManager_winPrevTab.cpp (its row's unit).

// GameWindowManager::winPrevTab: defined in GameWindowManager_winPrevTab.cpp (its row's unit).

// GameWindowManager::registerTabList: defined in GameWindowManager_registerTabList.cpp (its row's unit).
