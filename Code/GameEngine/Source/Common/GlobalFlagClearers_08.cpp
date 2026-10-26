// Three .data flag words formerly cleared by this unit's 31 B2-native
// clearers. Each clearer is now rowed as its matched parent's /G7
// local-static guard rollback ($L funclet) under the parent's EXACT EH graph
// (GameWindowManager::assignDefaultGadgetLook, ControlBarSystem,
// ActiveBodyInterface::updateBodyParticleSystems); see reverse/deleted_rows.csv.
// The words stay defined here: g_Va00DFEFA0 is still cleared by
// GlobalFlagClearers_04.cpp, g_Va00E02F24 by GlobalFlagClearers_E0102xx.cpp,
// and g_Va00E040B0 is a reverse/data_rows.csv-owned datum of this unit.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00DFEFA0;
// g_Va00DFEFA0: VA 0xdfefa0 (zero-filled .bss).
unsigned int g_Va00DFEFA0;
extern unsigned int g_Va00E02F24;
// g_Va00E02F24: matched references place it at VA 0xe02f24 (zero-filled .bss).
unsigned int g_Va00E02F24;
extern unsigned int g_Va00E040B0;
// g_Va00E040B0: matched references place it at VA 0xe040b0 (zero-filled .bss).
unsigned int g_Va00E040B0;

