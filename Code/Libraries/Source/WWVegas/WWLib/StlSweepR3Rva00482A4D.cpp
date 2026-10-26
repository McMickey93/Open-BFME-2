// cl: /O1 /G7 /EHsc /MD
//
// ??_GRva00482A4DRecord@@QAEPAXI@Z at 0x00482A4D (28B): a non-virtual scalar
// deleting destructor. Retail saves this, calls the destructor at 0x00482551,
// tests bit 0 of the flags, conditionally frees through operator delete,
// returns this and pops one argument. The STLport stable_sort instantiation
// this unit once used to emit it also referenced the record's copy
// constructor, assignment and comparison, none of which retail shows; a
// delete expression emits the same wrapper on its own (as
// StlSweepR3Rva0046AA69.cpp does). Record identity and layout remain
// unresolved (address-derived).

struct Rva00482A4DRecord
{
	~Rva00482A4DRecord();
	char bytes[1];
};

// Emitter only: no retail body.
void Rva00482A4DRecord_Delete(Rva00482A4DRecord *p)
{
	delete p;
}

// This caller's native REL32 already names the kept provider at 0x00482551.
// Compatible calling convention and argument/return ABI; binding is address-proven.
#pragma comment(linker, "/alternatename:??1Rva00482A4DRecord@@QAE@XZ=??1FireWeaponWhenDamagedBehavior@@UAE@XZ")
