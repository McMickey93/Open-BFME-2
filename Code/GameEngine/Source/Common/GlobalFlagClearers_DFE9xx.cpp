// One B2-native flag-word clearer on .data flag word 0x00DFE944 (its nine
// siblings are rowed as their parents' guard-rollback funclets):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses,
// following GlobalFlagClearers_DFEExx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00DFE944;
// g_Va00DFE944: matched references place it at VA 0xdfe944 (zero-filled .bss).
unsigned int g_Va00DFE944;

unsigned int Rva0077118FClearFlag(void)
{
	return g_Va00DFE944 &= 0xFFFFFFFEu;
}

