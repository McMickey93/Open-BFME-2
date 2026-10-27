// cl: /MD
// Sibling of rowed Animatable3DObjClass::Get_Bone_Name at 0x001A4B90 (21B),
// matched on mnemonic shape only -- the identity differs. Retail 0x0061F090
// (21B) forwards through the singleton pointer at 0x00E09C0C and otherwise
// returns 100. The tail jump targets the incremental-link thunk at
// 0x00620DA0, rowed as the 5-byte tail jump Rva00620DA0::forward
// (TailJumpWrappers5B.cpp); retail truth never follows a padded jmp, so the
// call names that row rather than its target bfmeForward (0x006208B0).
class Rva00620DA0
{
public:
	int forward();
};

// The singleton at 0x00E09C0C: the data ledger's TheQ1Receiver
// (q1_registry_forwards.cpp), read through this unit's forwarding view.
class Q1Receiver0134FAAC;
extern Q1Receiver0134FAAC *TheQ1Receiver;

int __cdecl rva0061F090()
{
	if (TheQ1Receiver)
		return ((Rva00620DA0 *)TheQ1Receiver)->forward();
	return 100;
}
