// cl: /O1 /G7 /EHsc /MD
//
// ??_GRva0044BE1DRecord@@QAEPAXI@Z at 0x0044BE1D (28B): a non-virtual scalar
// deleting destructor. Retail saves this, calls the destructor at 0x0044BE39,
// tests bit 0 of the flags, conditionally frees through operator delete,
// returns this and pops one argument. The STLport stable_sort instantiation
// this unit once used to emit it also referenced the record's copy
// constructor, assignment and comparison, none of which retail shows; a
// delete expression emits the same wrapper on its own (as
// StlSweepR3Rva0046AA69.cpp does). Record identity and layout remain
// unresolved (address-derived).

struct Rva0044BE1DRecord
{
	~Rva0044BE1DRecord();
	char bytes[1];
};

// Emitter only: no retail body.
void Rva0044BE1DRecord_Delete(Rva0044BE1DRecord *p)
{
	delete p;
}

// This caller's native REL32 already names the kept provider at 0x0044BE39.
// Compatible calling convention and argument/return ABI; binding is address-proven.
#pragma comment(linker, "/alternatename:??1Rva0044BE1DRecord@@QAE@XZ=??1Rva0044BE39@@UAE@XZ")
