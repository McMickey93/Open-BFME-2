// 24 clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// What remains is the data_rows.csv-owned flag word below. The family was
// twenty-six B2-native flag-word clearers on 25 .data flag words
// (0x00E03B00-0x00E03BF4):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03BCC;
// g_Va00E03BCC: matched references place it at VA 0xe03bcc (zero-filled .bss).
unsigned int g_Va00E03BCC;

// 78D9C9 and78DA27 are the two static-name initialization unwind actions
// emitted by ProductionUpdate::update; its compiler-owned guard is E03B6C.
