// cl: /DNDEBUG /MD /GX
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

// StealthDetectorUpdate::xfer, ported from Zero Hour's GameEngine/Source/
// GameLogic/Object/Update/StealthDetectorUpdate.cpp (GeneralsMD tree vendored
// under reference/open-bfme-1/inputs/reference): slot 3 of the vftable whose
// slot-2 name getter returns StealthDetectorUpdate. BFME 2 is at version 3
// and has dropped ZH's m_enabled: saves older than version 3 still carry
// the flag, so it is read into a local and discarded.

class AsciiString;
class UnicodeString;
class PooledString;
struct XferUnknown11;
struct Coord3DBase;
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

class Xfer::Version
{
public:
	Version(unsigned char current, unsigned char minimum)
		: m_current(current), m_minimum(minimum) {}

	unsigned char m_current;
	unsigned char m_minimum;
};

typedef bool Bool;
typedef int Int;
typedef unsigned int UnsignedInt;

// The module's class views spell the StealthDetectorUpdate TU's union
// (StealthDetectorUpdateView.h's layout, UpdateModule's slots named by
// their ledger rows).
class Object;
class Xfer;
struct StealthDetectorUpdateModuleData;

enum UpdateSleepTime { UPDATE_SLEEP_NONE = 1, UPDATE_SLEEP_FOREVER = 0x3fffffff };
enum NameKeyType { NAMEKEY_INVALID = 0 };

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};
extern NameKeyGenerator *TheNameKeyGenerator;

// The module data and object pointers sit at +0x04/+0x08 under the primary
// vptr, the other interface at +0x0C and the update interface at +0x10. The
// primary slots are UpdateModule's as its retail vftable (0x00BF004C) holds
// them: dtor, loadPostProcess (0x0058B03E), GetSnapshotName (0x002533CD),
// xfer (0x0044DF9F), __purecall for getModuleNameKey; the module's own xfer
// (0x004A2C30) sits in slot 3 and getModuleNameKey (0x004A2C74) in slot 4.
// No constructor or vftable is defined from this view.
class DetectorPrimary
{
public:
	virtual ~DetectorPrimary();
	const StealthDetectorUpdateModuleData *m_data;	// +0x04
	Object *m_object;				// +0x08
};
class DetectorOther { public: virtual void other(); };
class UpdateModuleInterface { public: virtual UpdateSleepTime update() = 0; };
class UpdateModule : public DetectorPrimary, public DetectorOther, public UpdateModuleInterface
{
protected:
	virtual void loadPostProcess();				// slot 1
	virtual const char *GetSnapshotName() const;		// slot 2
public:
	virtual void xfer(Xfer *xfer);				// slot 3
	virtual NameKeyType getModuleNameKey() const = 0;	// slot 4
protected:
	void setWakeFrame(Object *object, UpdateSleepTime wakeTime);	// rowed 0x0044DF71
};
class StealthDetectorUpdate : public UpdateModule
{
public:
	virtual UpdateSleepTime update();
	virtual NameKeyType getModuleNameKey() const;
	Object *getObject() const { return m_object; }
	const char *name() const;
protected:
	virtual void xfer(Xfer *xfer);
};

// ------------------------------------------------------------------------------------------------
/** Xfer method
	* Version Info:
	* 1: Initial version
	* 3: BFME 2, enabled flag removed */
// ------------------------------------------------------------------------------------------------
void StealthDetectorUpdate::xfer( Xfer *xfer )
{

	// version
	Xfer::Version version( 1, 3 );
	*xfer == version;

	// extend base class
	UpdateModule::xfer( xfer );

	// enabled (obsolete)
	if( version.m_minimum < 3 )
	{
		Bool enabled = false;
		*xfer == enabled;
	}

}  // end xfer
