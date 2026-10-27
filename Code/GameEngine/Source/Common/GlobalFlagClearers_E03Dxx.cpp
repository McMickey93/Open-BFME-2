// 23 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-four B2-native flag-word clearers on 24 .data flag words
// (0x00E03D00-0x00E03DF4):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E03Cxx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03D34;
// g_Va00E03D34: matched references place it at VA 0xe03d34 (zero-filled .bss).
unsigned int g_Va00E03D34;
extern unsigned int g_Va00E03D60;
// g_Va00E03D60: matched references place it at VA 0xe03d60 (zero-filled .bss).
unsigned int g_Va00E03D60;

unsigned int Rva0078E61FClearFlag(void)
{
	return g_Va00E03D60 &= 0xFFFFFFFEu;
}

