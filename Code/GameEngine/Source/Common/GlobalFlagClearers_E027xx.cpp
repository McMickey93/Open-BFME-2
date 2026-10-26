// 8 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Nine B2-native flag-word clearers on nine .data flag words
// (0x00E027A8-0x00E027FC):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses,
// following GlobalFlagClearers_DFEExx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E027EC;
// g_Va00E027EC: matched references place it at VA 0xe027ec (zero-filled .bss).
unsigned int g_Va00E027EC;
extern unsigned int g_Va00E027F4;
// g_Va00E027F4: matched references place it at VA 0xe027f4 (zero-filled .bss).
unsigned int g_Va00E027F4;

unsigned int Rva00780E59ClearFlag(void)
{
	return g_Va00E027EC &= 0xFFFFFFFEu;
}

