// cl: /O1 /G7 /EHsc /MD
//
// ??_GRva005CE7CERecord@@QAEPAXI@Z at 0x005CE7CE (28B): a non-virtual scalar
// deleting destructor. Retail saves this, calls the destructor at 0x005E8F6A,
// tests bit 0 of the flags, conditionally frees through operator delete
// (0x0002FD60), returns this and pops one argument. The STLport stable_sort
// instantiation this unit once used to emit it also referenced the record's
// copy constructor, assignment and comparison, none of which retail shows; a
// delete expression emits the same wrapper on its own (as
// StlSweepR3Rva0046AA69.cpp does). Record identity and layout remain
// unresolved (address-derived).

struct Rva005CE7CERecord
{
	~Rva005CE7CERecord();
	char bytes[1];
};

// Emitter only: no retail body.
void Rva005CE7CERecord_Delete(Rva005CE7CERecord *p)
{
	delete p;
}

// This caller's native REL32 already names the kept provider at 0x005E8F6A.
// Compatible calling convention and argument/return ABI; binding is address-proven.
#pragma comment(linker, "/alternatename:??1Rva005CE7CERecord@@QAE@XZ=?rva005E8F6A@Rva005E8F50@@QAEXXZ")
