// 14 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Sixteen B2-native flag-word clearers on 11 .data flag words
// (0x00E04900-0x00E049C8):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E045xx.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E04988;
// g_Va00E04988: matched references place it at VA 0xe04988 (zero-filled .bss).
unsigned int g_Va00E04988;

unsigned int Rva00796C60ClearFlag(void)
{
	return g_Va00E04988 &= 0xFFFFFFFEu;
}

unsigned int Rva00796C6DClearFlag(void)
{
	return g_Va00E04988 &= 0xFFFFFFFDu;
}

