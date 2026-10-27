// cl: /O1 /DNDEBUG /MD
//
// ??_GPlayerRelationMap@@MAEPAXI@Z, retail 0x002ADE55 (28 bytes): slot 0
// of vtable 0x00BFDD90, whose slot-2 name getter returns "PlayerRelationMap" (the only
// vtable using that getter). Scalar deleting destructor: calls the
// destructor at 0x002AD078 and then the global operator delete when bit 0 of
// the flags is set. That destructor re-stores vtable 0x00BFDD90, which
// identifies it as PlayerRelationMap::~PlayerRelationMap (pinned in reverse/symbols.csv).
// Class shape from Zero Hour's Common/Player.h (pooled).
// Zero Hour pools the class (MEMORY_POOL_GLUE: protected virtual
// destructor and an inline class operator delete); BFME 2's form frees
// through the global operator delete, so the class is modelled with none.
// The destructor is declared, not defined, so the call resolves to the pin;
// the dummy tag constructor (no retail counterpart) only makes this TU emit
// the vtable and with it the deleting destructor. Slots 1-3 are the Snapshot
// overrides loadPostProcess (shared empty ret 0x000B3FD0), GetSnapshotName
// (0x002AD0C0) and xfer (0x002ADEBE), declared alike in every unit that
// emits this vtable so the copies agree.

struct EmitVtableTag;
class Xfer;

class PlayerRelationMap
{
public:
	PlayerRelationMap(EmitVtableTag *);
protected:
	virtual ~PlayerRelationMap();
	virtual void loadPostProcess();
	virtual const char *GetSnapshotName() const;
	virtual void xfer(Xfer *xfer);
};

// ?<PlayerRelationMap::PlayerRelationMap> absent-from-retail
PlayerRelationMap::PlayerRelationMap(EmitVtableTag *)
{
}
