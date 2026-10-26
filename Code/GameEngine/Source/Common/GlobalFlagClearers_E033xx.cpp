// 17 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-one B2-native flag-word clearers on fourteen .data flag words
// (0x00E03304-0x00E033F0):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses,
// following GlobalFlagClearers_E031xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03350;
// g_Va00E03350: matched references place it at VA 0xe03350 (zero-filled .bss).
unsigned int g_Va00E03350;
extern unsigned int g_Va00E033A0;
// g_Va00E033A0: matched references place it at VA 0xe033a0 (zero-filled .bss).
unsigned int g_Va00E033A0;
extern unsigned int g_Va00E033A8;
// g_Va00E033A8: matched references place it at VA 0xe033a8 (zero-filled .bss).
unsigned int g_Va00E033A8;

unsigned int Rva00788A22ClearFlag(void)
{
	return g_Va00E03350 &= 0xFFFFFFFEu;
}

unsigned int Rva00788A37ClearFlag(void)
{
	return g_Va00E03350 &= 0xFFFFFFFDu;
}

unsigned int Rva00789B39ClearFlag(void)
{
	return g_Va00E033A0 &= 0xFFFFFFFEu;
}

unsigned int Rva00789B6DClearFlag(void)
{
	return g_Va00E033A8 &= 0xFFFFFFFEu;
}

