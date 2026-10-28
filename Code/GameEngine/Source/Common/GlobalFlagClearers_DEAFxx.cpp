// All 23 clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// What remains is the data_rows.csv-owned flag word below. The family was
// twenty-three B2-native flag-word clearers across twenty-one .data flag words of
// one contiguous run (0x007618F7-0x00762A01):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Twenty-two clear al bit 0, one clears al bit 1. Same /G7 byte-register
// narrowing as GlobalFlagClearers_08.cpp (defaults emit `and eax,imm`).
// Each body carries a .rdata table slot (0x00904E88 and on). Identity is
// not recovered; names derive from addresses, following
// GlobalFlagClearers_08.cpp.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00DEBBAC;
// g_Va00DEBBAC: matched references place it at VA 0xdebbac (zero-filled .bss).
unsigned int g_Va00DEBBAC;

