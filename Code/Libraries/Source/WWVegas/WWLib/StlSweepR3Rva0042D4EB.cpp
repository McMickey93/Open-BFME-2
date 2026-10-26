// cl: /O1 /G7 /EHsc /MD
//
// ??_GRva0042D4EBRecord@@QAEPAXI@Z at 0x0042D4EB (28B): a non-virtual scalar
// deleting destructor. Retail saves this, calls the destructor at 0x005794ED,
// tests bit 0 of the flags, conditionally frees through operator delete,
// returns this and pops one argument. The STLport stable_sort instantiation
// this unit once used to emit it also referenced the record's copy
// constructor, assignment and comparison, none of which retail shows; a
// delete expression emits the same wrapper on its own (as
// StlSweepR3Rva0046AA69.cpp does). Record identity and layout remain
// unresolved (address-derived).

struct Rva0042D4EBRecord
{
	~Rva0042D4EBRecord();
	char bytes[1];
};

// Emitter only: no retail body.
void Rva0042D4EBRecord_Delete(Rva0042D4EBRecord *p)
{
	delete p;
}

// This caller's native REL32 already names the kept provider at 0x005794ED.
// Compatible calling convention and argument/return ABI; binding is address-proven.
#pragma comment(linker, "/alternatename:??1Rva0042D4EBRecord@@QAE@XZ=??1EndTurnButtonImpl@StrategicHUD@@QAE@XZ")
