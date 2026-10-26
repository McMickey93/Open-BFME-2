// 5 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Six B2-native flag-word clearers on five scattered .data flag words
// (0x007785C9-0x0077979D):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot (0x00920670
// and on). Identity is not recovered; names derive from addresses,
// following GlobalFlagClearers_08.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00DFF0E4;
// g_Va00DFF0E4: matched references place it at VA 0xdff0e4 (zero-filled .bss).
unsigned int g_Va00DFF0E4;

unsigned int Rva00778EA4ClearFlag(void)
{
	return g_Va00DFF0E4 &= 0xFFFFFFFEu;
}

