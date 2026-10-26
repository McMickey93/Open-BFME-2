// One .data flag word, g_Va00E038C4, kept defined here because it is a
// reverse/data_rows.csv-owned datum of this unit. The unit's 26 former
// B2-native clearers (0x00E03804-0x00E038FC flag words) are each rowed as a
// matched parent's /G7 local-static guard rollback ($L funclet) under the
// parent's EXACT EH graph; see reverse/deleted_rows.csv.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E038C4;
// g_Va00E038C4: matched references place it at VA 0xe038c4 (zero-filled .bss).
unsigned int g_Va00E038C4;

