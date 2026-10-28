// cl: /O1 /DNDEBUG /MD /EHsc
//
// Vector deleting destructors (??_E), batch V07: the two 74-byte bodies of
// classes whose destructor is a header inline that only restores the vptr.
// For an array delete (flag bit 1) they run the eh vector destructor
// iterator (0x00629110) with the out-of-line copy of that destructor and the
// element size 4, then free through operator delete[] (0x0002FD80); for a
// single object the destructor is inlined (one vptr store) before operator
// delete (0x0002FD60).
//
//   ??_E        dtor        size  vtable#slot
//   0x000011EC  0x000011BD  0x4   0x00BBB52C#0  FXParticleSystem::ModuleTemplate
//   0x00001750  0x0049B47C  0x4   0x00BBB554#0  Snapshot
//
// Identity: each vtable is the one its matched constructors and destructor
// install (ModuleTemplate's in FXParticleSystem.cpp, ??_7Snapshot@@6B@
// pinned at 0x00BBB554), and the array path hands that class's destructor
// to the iterator. Retail inlines both destructors here, so they are header
// inlines. The anchor (no retail counterpart) only makes this TU emit the
// vector deleting destructors. Snapshot stays abstract: naming its compiler
// deleting destructor directly emits the array-capable body without constructing
// an instance, as XferVectorDeletingDtor.cpp does. Xfer's (0x00005422) lives in
// XferVectorDeletingDtor.cpp: this TU's one-slot Xfer view emitted a stub
// ??_7Xfer@@6B@ that link.exe kept ahead of Xfer.cpp's 39-slot table.

// Declared so the array path frees through operator delete[] (0x0002FD80)
// as retail does; left undeclared, cl falls back to scalar operator delete.
#include <new>

namespace FXParticleSystem
{

// upstream layout: FXParticleSystem.cpp's ModuleTemplate (vtable only).
class ModuleTemplate
{
public:
	virtual ~ModuleTemplate() {}
};

}

#include "../../../../reference/shims/moduledata/Common/Snapshot.h"

// ?<bfmeVectorDeleteAnchorV07> absent-from-retail
void bfmeVectorDeleteAnchorV07(Snapshot *snapshot)
{
	new FXParticleSystem::ModuleTemplate[2];
	snapshot->Snapshot::__vecDelDtor(3);
}

void Rva002253C2Init();

void Rva0000179A()
{
	Rva002253C2Init();
}
