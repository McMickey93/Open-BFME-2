// cl: /O1 /DNDEBUG /MD
//
// ??_GWeaponSet@@UAEPAXI@Z, retail 0x002C75B5 (28 bytes): slot 0
// of vtable 0x00C0089C, whose slot-2 name getter returns "WeaponSet" (the only
// vtable using that getter). Scalar deleting destructor: calls the
// destructor at 0x002C7311 and then the global operator delete when bit 0 of
// the flags is set. That destructor re-stores vtable 0x00C0089C, which
// identifies it as WeaponSet::~WeaponSet (pinned in reverse/symbols.csv).
// Class shape from Zero Hour's GameLogic/WeaponSet.h (public ~WeaponSet).
// BFME 2's form frees through the global operator delete.
// The destructor is declared, not defined, so the call resolves to the pin;
// the dummy tag constructor (no retail counterpart) only makes this TU emit
// the vtable and with it the deleting destructor.

// The base is the canonical Snapshot (vtable 0x00BBB554), and WeaponSet's
// three Snapshot overrides are declared as in WeaponSetDtor.cpp and
// WeaponSetXfer.cpp, so every ??_7WeaponSet copy agrees.
#include "../../../../../reference/shims/moduledata/Common/Snapshot.h"

struct EmitVtableTag;

class WeaponSet : public Snapshot
{
public:
	WeaponSet(EmitVtableTag *);
	virtual ~WeaponSet();

protected:
	virtual void crc(Xfer *xfer);
	virtual void xfer(Xfer *xfer);
	virtual void loadPostProcess(void);
};

// ?<WeaponSet::WeaponSet> absent-from-retail
WeaponSet::WeaponSet(EmitVtableTag *)
{
}
