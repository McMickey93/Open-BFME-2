// Two .data flag words (0x00DFEC4C, 0x00DFEC80) that reverse/data_rows.csv
// owns here. Their standalone clearers were retired: each word is the
// local-static guard of a matched parent (Drawable::onComingOutOfShroud,
// Rva002862C9), whose own unwind funclet is rowed under it. A data row cannot
// yet own a function-local static guard, so the ownership stays here until
// it can move to the parent's guard.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00DFEC4C;
// g_Va00DFEC4C: matched references place it at VA 0xdfec4c (zero-filled .bss).
unsigned int g_Va00DFEC4C;
extern unsigned int g_Va00DFEC80;
// g_Va00DFEC80: matched references place it at VA 0xdfec80 (zero-filled .bss).
unsigned int g_Va00DFEC80;
