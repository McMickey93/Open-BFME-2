// .data flag word(s) g_Va00E035EC kept defined here (still named by another unit or
// owned here by reverse/data_rows.csv). The unit's 8 former B2-native
// clearers are each rowed as a matched parent's /G7 local-static guard
// rollback ($L funclet) under the parent's EXACT EH graph; see
// reverse/deleted_rows.csv.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E035EC;
// g_Va00E035EC: matched references place it at VA 0xe035ec (zero-filled .bss).
unsigned int g_Va00E035EC;

