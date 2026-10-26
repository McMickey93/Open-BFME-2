// 15 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Ten B2-native flag-word clearers on ten .data flag words
// (0x00E04000-0x00E04068):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_E033xx.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses,
// following GlobalFlagClearers_E033xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E04010;
// g_Va00E04010: matched references place it at VA 0xe04010 (zero-filled .bss).
unsigned int g_Va00E04010;
extern unsigned int g_Va00E04018;
// g_Va00E04018: matched references place it at VA 0xe04018 (zero-filled .bss).
unsigned int g_Va00E04018;
extern unsigned int g_Va00E04068;
// g_Va00E04068: matched references place it at VA 0xe04068 (zero-filled .bss).
unsigned int g_Va00E04068;
extern unsigned int g_Va00E04090;
// g_Va00E04090: matched references place it at VA 0xe04090 (zero-filled .bss).
unsigned int g_Va00E04090;
extern unsigned int g_Va00E04128;
// g_Va00E04128: matched references place it at VA 0xe04128 (zero-filled .bss).
unsigned int g_Va00E04128;

unsigned int Rva0078F693ClearFlag(void)
{
	return g_Va00E04010 &= 0xFFFFFFFEu;
}

unsigned int Rva0078F6AAClearFlag(void)
{
	return g_Va00E04018 &= 0xFFFFFFFEu;
}

unsigned int Rva0078F7A2ClearFlag(void)
{
	return g_Va00E04068 &= 0xFFFFFFFEu;
}

unsigned int Rva0078F893ClearFlag(void)
{
	return g_Va00E04090 &= 0xFFFFFFFEu;
}

unsigned int Rva0078FB22ClearFlag(void)
{
	return g_Va00E04128 &= 0xFFFFFFFEu;
}

