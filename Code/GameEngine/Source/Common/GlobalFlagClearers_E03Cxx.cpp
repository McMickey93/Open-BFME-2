// 24 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-five B2-native flag-word clearers on 23 .data flag words
// (0x00E03C00-0x00E03CF8):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E03Bxx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03CDC;
// g_Va00E03CDC: matched references place it at VA 0xe03cdc (zero-filled .bss).
unsigned int g_Va00E03CDC;

unsigned int Rva0078E29DClearFlag(void)
{
	return g_Va00E03CDC &= 0xFFFFFFFEu;
}

