// 19 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-three B2-native flag-word clearers on twenty-one .data flag words
// (0x00E03400-0x00E034E4):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses,
// following GlobalFlagClearers_E033xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E0340C;
// g_Va00E0340C: matched references place it at VA 0xe0340c (zero-filled .bss).
unsigned int g_Va00E0340C;
extern unsigned int g_Va00E0343C;
// g_Va00E0343C: matched references place it at VA 0xe0343c (zero-filled .bss).
unsigned int g_Va00E0343C;
extern unsigned int g_Va00E0346C;
// g_Va00E0346C: matched references place it at VA 0xe0346c (zero-filled .bss).
unsigned int g_Va00E0346C;

unsigned int Rva00789F03ClearFlag(void)
{
	return g_Va00E0340C &= 0xFFFFFFFEu;
}

unsigned int Rva00789F18ClearFlag(void)
{
	return g_Va00E0340C &= 0xFFFFFFFDu;
}

unsigned int Rva0078A1A6ClearFlag(void)
{
	return g_Va00E0343C &= 0xFFFFFFFEu;
}

unsigned int Rva0078A27EClearFlag(void)
{
	return g_Va00E0346C &= 0xFFFFFFFEu;
}

