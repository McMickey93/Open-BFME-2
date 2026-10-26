// 14 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// B2-native flag-word clearers on .data flag words
// (0x00E06220-0x00E06938):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses,
// following GlobalFlagClearers_E05x.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E063C8;
// g_Va00E063C8: matched references place it at VA 0xe063c8 (zero-filled .bss).
unsigned int g_Va00E063C8;
// Only the startup flag word lives here (VA E06558). MainMenuUtils owns its
// independent file-local state at E0655C..E06574; a 29-byte aggregate here
// incorrectly made those statics alias arbitrary objects during compilation.
unsigned int g_mainMenuStartupFlags;
// E065B0 is the compiler-owned static-initializer guard in
// ParasiticInGameCommandButton::Impl::Update. Its exact parent EH graph
// supplies the reset at7A08F0 in Rva005C33DDWindowNotification.cpp.

unsigned int Rva0079D3AAClearFlag(void)
{
	return g_Va00E063C8 &= 0xFFFFFFFDu;
}

