// cl: /DNDEBUG /MD /Ireference/shims/bfme2_ascii
//
// Small vtable-slot bodies with no ledger owner and no Ghidra entry (sized
// from their bytes), batch K. As in VslotSmallBodiesA-J, each class and method
// is address-derived unless the ledger already names it, and models only what
// its body touches; the comment above each gives the .rdata slot address(es)
// that reference it. Meanings are not recovered.

#include "ascii_string.h"

// slot at VA 0x00C548F4: returns a copy of the global value at VA
// 0x00E030D0 (rowed copy constructor 0x002CF0F0).
template <int N> class BitFlags { public: unsigned int m_words[(N + 31) / 32]; };
extern BitFlags<11> DISABLEDMASK_ALL;
class BfmeFixedStorage002CF0F0
{
public:
	BfmeFixedStorage002CF0F0(const BfmeFixedStorage002CF0F0 &other);
private:
	int m_00;
};
class Rva004AB9D5
{
public:
	BfmeFixedStorage002CF0F0 getDisabledTypesToProcess();
};
BfmeFixedStorage002CF0F0 Rva004AB9D5::getDisabledTypesToProcess()
{
	return *(const BfmeFixedStorage002CF0F0 *)&DISABLEDMASK_ALL;
}
