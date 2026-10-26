// 20 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-one B2-native flag-word clearers on 21 .data flag words
// (0x00E04304-0x00E043E0):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// following GlobalFlagClearers_E03Fxx.cpp.
// 0x00790AE8 and guard VA 0x00E043D8 are now owned by the exact
// UnleashSpecialPower::rva004CE0D9 static-initialization EH graph.
// 0x00790AFF and guard VA 0x00E043E0 belong to triggerAbilityEffect.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E04338;
// g_Va00E04338: matched references place it at VA 0xe04338 (zero-filled .bss).
unsigned int g_Va00E04338;

unsigned int Rva007904F3ClearFlag(void)
{
	return g_Va00E04338 &= 0xFFFFFFFEu;
}

