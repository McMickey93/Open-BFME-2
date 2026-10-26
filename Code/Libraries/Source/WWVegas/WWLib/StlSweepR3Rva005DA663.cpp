// cl: /O1 /G7 /EHsc /MD
//
// ??_GRva005DA663Record@@QAEPAXI@Z at 0x005DA663 (28B): a non-virtual scalar
// deleting destructor. Retail saves this, calls the destructor at 0x005970E6,
// tests bit 0 of the flags, conditionally frees through operator delete,
// returns this and pops one argument. The STLport stable_sort instantiation
// this unit once used to emit it also referenced the record's copy
// constructor, assignment and comparison, none of which retail shows; a
// delete expression emits the same wrapper on its own (as
// StlSweepR3Rva0046AA69.cpp does). Record identity and layout remain
// unresolved (address-derived).

struct Rva005DA663Record
{
	~Rva005DA663Record();
	char bytes[1];
};

// Emitter only: no retail body.
void Rva005DA663Record_Delete(Rva005DA663Record *p)
{
	delete p;
}

// This caller's native REL32 already names the kept provider at 0x005970E6.
// Compatible calling convention and argument/return ABI; binding is address-proven.
#pragma comment(linker, "/alternatename:??1Rva005DA663Record@@QAE@XZ=?apply@Rva0005970E6DwordImmSetter@@QAEXXZ")
