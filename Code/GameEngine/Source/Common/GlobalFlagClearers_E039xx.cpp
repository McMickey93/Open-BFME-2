// 23 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-seven B2-native flag-word clearers on 27 .data flag words
// (0x00E03904-0x00E039FC):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E038xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03930;
// g_Va00E03930: matched references place it at VA 0xe03930 (zero-filled .bss).
unsigned int g_Va00E03930;
extern unsigned int g_Va00E03938;
// g_Va00E03938: matched references place it at VA 0xe03938 (zero-filled .bss).
unsigned int g_Va00E03938;
extern unsigned int g_Va00E03940;
// g_Va00E03940: matched references place it at VA 0xe03940 (zero-filled .bss).
unsigned int g_Va00E03940;
extern unsigned int g_Va00E03948;
// g_Va00E03948: matched references place it at VA 0xe03948 (zero-filled .bss).
unsigned int g_Va00E03948;

unsigned int Rva0078C634ClearFlag(void)
{
	return g_Va00E03930 &= 0xFFFFFFFEu;
}

unsigned int Rva0078C68AClearFlag(void)
{
	return g_Va00E03938 &= 0xFFFFFFFEu;
}

unsigned int Rva0078C6A9ClearFlag(void)
{
	return g_Va00E03940 &= 0xFFFFFFFEu;
}

unsigned int Rva0078C714ClearFlag(void)
{
	return g_Va00E03948 &= 0xFFFFFFFEu;
}

