// 14 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Fourteen B2-native flag-word clearers across fourteen .data flag words
// of one contiguous run (0x00781323-0x00781D66):
//
//     mov eax,[<address>] / and al,0xFE / mov [<address>],eax / ret
//
// All fourteen clear al bit 0. Same /G7 byte-register narrowing as
// GlobalFlagClearers_08.cpp (defaults emit `and eax,imm`). Each body
// carries a .rdata table slot (0x0092C168 and on). An image-wide raw
// branch scan flagged some of these addresses, but targeted decode proves
// every flag is a `jmp 0x629182` displacement byte, not a branch into the
// body. Identity is not recovered; names derive from addresses, following
// GlobalFlagClearers_08.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E0282C;
// g_Va00E0282C: matched references place it at VA 0xe0282c (zero-filled .bss).
unsigned int g_Va00E0282C;
extern unsigned int g_Va00E02844;
// g_Va00E02844: matched references place it at VA 0xe02844 (zero-filled .bss).
unsigned int g_Va00E02844;

unsigned int Rva007810A7ClearFlag(void)
{
	return g_Va00E0282C &= 0xFFFFFFFEu;
}

unsigned int Rva007810B4ClearFlag(void)
{
	return g_Va00E0282C &= 0xFFFFFFFDu;
}
