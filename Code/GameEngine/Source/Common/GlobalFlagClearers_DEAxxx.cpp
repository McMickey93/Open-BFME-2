// 8 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Ten B2-native flag-word clearers on nine scattered .data flag words
// (0x0076144C-0x00767CD3):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot (0x00904734
// and on). Identity is not recovered; names derive from addresses,
// following GlobalFlagClearers_08.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00DF3678;
// g_Va00DF3678: matched references place it at VA 0xdf3678 (zero-filled .bss).
unsigned int g_Va00DF3678;
extern unsigned int g_Va00DF6FC8;
// g_Va00DF6FC8: matched references place it at VA 0xdf6fc8 (zero-filled .bss).
unsigned int g_Va00DF6FC8;

unsigned int Rva007665ADClearFlag(void)
{
	return g_Va00DF3678 &= 0xFFFFFFFDu;
}

unsigned int Rva00767CD3ClearFlag(void)
{
	return g_Va00DF6FC8 &= 0xFFFFFFFDu;
}
