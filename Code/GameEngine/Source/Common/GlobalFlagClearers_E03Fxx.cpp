// 23 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-five B2-native flag-word clearers on 25 .data flag words
// (0x00E03F00-0x00E03FF4):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E03Exx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03F74;
// g_Va00E03F74: matched references place it at VA 0xe03f74 (zero-filled .bss).
unsigned int g_Va00E03F74;
extern unsigned int g_Va00E03F94;
// g_Va00E03F94: matched references place it at VA 0xe03f94 (zero-filled .bss).
unsigned int g_Va00E03F94;
extern unsigned int g_Va00E03FC8;
// g_Va00E03FC8: matched references place it at VA 0xe03fc8 (zero-filled .bss).
unsigned int g_Va00E03FC8;

unsigned int Rva0078F1EFClearFlag(void)
{
	return g_Va00E03F74 &= 0xFFFFFFFEu;
}

unsigned int Rva0078F27AClearFlag(void)
{
	return g_Va00E03F94 &= 0xFFFFFFFEu;
}

