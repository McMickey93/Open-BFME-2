// 21 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-three B2-native flag-word clearers on 23 .data flag words
// (0x00E03E00-0x00E03EF4):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E03Dxx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03E28;
// g_Va00E03E28: matched references place it at VA 0xe03e28 (zero-filled .bss).
unsigned int g_Va00E03E28;
extern unsigned int g_Va00E03E74;
// g_Va00E03E74: matched references place it at VA 0xe03e74 (zero-filled .bss).
unsigned int g_Va00E03E74;

unsigned int Rva0078EC05ClearFlag(void)
{
	return g_Va00E03E28 &= 0xFFFFFFFEu;
}

unsigned int Rva0078ED14ClearFlag(void)
{
	return g_Va00E03E74 &= 0xFFFFFFFEu;
}

