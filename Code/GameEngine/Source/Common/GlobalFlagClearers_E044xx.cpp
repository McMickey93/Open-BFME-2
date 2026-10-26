// 6 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Remaining B2-native flag-word clearers on separate .data flag words
// (0x00E04410-0x00E044EC):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E043xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E044C0;
// g_Va00E044C0: matched references place it at VA 0xe044c0 (zero-filled .bss).
unsigned int g_Va00E044C0;
extern unsigned int g_Va00E044C8;
// g_Va00E044C8: matched references place it at VA 0xe044c8 (zero-filled .bss).
unsigned int g_Va00E044C8;

unsigned int Rva00792CD9ClearFlag(void)
{
	return g_Va00E044C0 &= 0xFFFFFFFEu;
}

unsigned int Rva00792D4DClearFlag(void)
{
	return g_Va00E044C8 &= 0xFFFFFFFEu;
}

