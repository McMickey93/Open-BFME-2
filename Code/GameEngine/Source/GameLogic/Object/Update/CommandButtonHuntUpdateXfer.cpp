// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /GX
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

// CommandButtonHuntUpdate::xfer, ported from Zero Hour's GameEngine/Source/
// GameLogic/Object/Update/CommandButtonHuntUpdate.cpp (GeneralsMD tree vendored
// under reference/open-bfme-1/inputs/reference). Slot 3 of
// ??_7CommandButtonHuntUpdate. BFME 2 Xfer spelling: UpdateModule::xfer first,
// the light-CRC early-out, Version1, then the button name (+0x20) through
// operator==(AsciiString&). On load the button pointer (+0x24) is
// re-resolved from the object's command set; a BFME 2 command set holds 32
// buttons. Callees are ZH's: Object::getCommandSetString (0x00290E67),
// ControlBar::findCommandSet (0x0031D5F8) and CommandSet::getCommandButton
// (0x00409EE8). CommandButton keeps its name at +0x10.
//
// The classes spell CommandButtonHuntUpdate.cpp's views (the TU this xfer
// joins): UpdateModule's vftable slots as read off retail, the command
// button with both fields that unit reads.

#include "ascii_string.h"

class UnicodeString;
class PooledString;
struct XferUnknown11;
class Coord3DBase;
class ICoord3D;
class Region3D;
class IRegion3D;
class Coord2D;
class ICoord2D;
class Region2D;
class IRegion2D;
class RealRange;
class RGBColor;
class RGBAColorReal;
class RGBAColorInt;
class Snapshot;

#include "../../../../Include/Common/BfmeXfer.h"

typedef bool Bool;
typedef int Int;

class Thing;
class ModuleData;
class SpecialPowerTemplate;
struct CommandButtonHuntUpdateModuleData;

class CommandButton
{
public:
	const AsciiString &getName() const { return m_name; }
	const SpecialPowerTemplate *getSpecialPowerTemplate() const { return m_specialPower; }
private:
	unsigned char m_pad00[0x10];
	AsciiString m_name;				// +0x10
	unsigned char m_pad14[0x44 - 0x14];
	const SpecialPowerTemplate *m_specialPower;	// +0x44
};

enum { MAX_COMMANDS_PER_SET = 32 };

class CommandSet
{
public:
	const CommandButton *getCommandButton( Int i ) const;
};

// ControlBar::findCommandSet (0x0031D5F8) is rowed as Rva0031D5F8::rva0031D5F8.
class Rva0031D5F8
{
public:
	void *rva0031D5F8( const AsciiString *name );
};
class ControlBar;
extern ControlBar *TheControlBar;

class Object
{
public:
	const AsciiString *rva00290E67( void ) const;	// getCommandSetString, rowed by address
};

class Xfer;

enum NameKeyType
{
	NK_UNKNOWN = 0
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_FOREVER = 0x3fffffff
};

// UpdateModule's three vptrs (+0x00, +0x0C, +0x10) are the ones the matched
// ctor (0x004952CF) and dtor (0x00495389) store. The primary vftable's slots
// read off retail: UpdateModule's own (0x00BF004C) holds its scalar deleting
// dtor, loadPostProcess (0x0058B03E), GetSnapshotName (0x002533CD), xfer
// (0x0044DF9F) and __purecall in slot 4; CommandButtonHuntUpdate's (0x00C4ECFC)
// holds its xfer (0x004953EE) in slot 3 and getModuleNameKey (0x00495344) in
// slot 4.
class PB_DeepBase
{
public:
	PB_DeepBase(Thing *, const ModuleData *);
	virtual ~PB_DeepBase();

protected:
	const ModuleData *m_moduleData;		// +0x04
	Object *m_object;			// +0x08
};

class PB_Iface1 { public: virtual void slot(); };
class PB_Iface2 { public: virtual void slot(); };

class UpdateModule : public PB_DeepBase, public PB_Iface1, public PB_Iface2
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual ~UpdateModule();

protected:
	virtual void loadPostProcess();				// slot 1
	virtual const char *GetSnapshotName() const;		// slot 2

public:
	virtual void xfer(Xfer *xfer);				// slot 3
	virtual NameKeyType getModuleNameKey() const = 0;	// slot 4

protected:
	void setWakeFrame(Object *, UpdateSleepTime);
	Object *getObject() const { return m_object; }

private:
	unsigned int m_f14;
	int m_f18;
	int m_f1c;
};

class CommandButtonHuntUpdate : public UpdateModule
{
public:
	CommandButtonHuntUpdate(Thing *, const ModuleData *);
	virtual NameKeyType getModuleNameKey() const;

protected:
	virtual ~CommandButtonHuntUpdate();
	virtual void xfer(Xfer *xfer);
	Object *scanClosestTarget();

private:
	const CommandButtonHuntUpdateModuleData *getCommandButtonHuntUpdateModuleData() const
	{
		return (const CommandButtonHuntUpdateModuleData *)m_moduleData;
	}

	AsciiString m_commandButtonName;		// +0x20
	const CommandButton *m_commandButton;		// +0x24
};

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version */
// ------------------------------------------------------------------------------------------------
void CommandButtonHuntUpdate::xfer( Xfer *xfer )
{

	// extend base class
	UpdateModule::xfer( xfer );

	if( xfer->IsLightCRC() )
		return;

	// version
	xfer->Version1();

	// command button name
	*xfer == m_commandButtonName;

	// command button
	if( xfer->IsLoading() )
	{

		m_commandButton = 0;
		// BFME 2 keeps the out-of-line StringBase<char>::isEmpty call here
		if( ((const StringBase<char> *)&m_commandButtonName)->isEmpty() == false )
		{
			const CommandSet *commandSet = (const CommandSet *)((Rva0031D5F8 *)TheControlBar)->rva0031D5F8( getObject()->rva00290E67() );
			if( commandSet )
			{
				for( Int i = 0; i < MAX_COMMANDS_PER_SET; i++ )
				{
					const CommandButton *commandButton = commandSet->getCommandButton(i);
					if( commandButton && commandButton->getName() == m_commandButtonName )
					{
						m_commandButton = commandButton;
						break;
					}
				}
			}
		}

	}  // end if

}  // end xfer
