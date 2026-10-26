// 23 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-four B2-native flag-word clearers on 24 .data flag words
// (0x00E03704-0x00E037FC):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E036xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E037D8;
// g_Va00E037D8: matched references place it at VA 0xe037d8 (zero-filled .bss).
unsigned int g_Va00E037D8;

unsigned int Rva0078BC95ClearFlag(void)
{
	return g_Va00E037D8 &= 0xFFFFFFFEu;
}

