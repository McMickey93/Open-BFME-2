// 16 further clearers formerly here are rowed as their matched parents'
// /G7 guard-rollback $L funclets (EXACT EH graphs); see reverse/deleted_rows.csv.
// Twenty-six B2-native flag-word clearers on 25 .data flag words
// (0x00E03B00-0x00E03BF4):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot. Identity is
// not recovered; names derive from addresses.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E03B00;
// g_Va00E03B00: matched references place it at VA 0xe03b00 (zero-filled .bss).
unsigned int g_Va00E03B00;
extern unsigned int g_Va00E03B14;
// g_Va00E03B14: matched references place it at VA 0xe03b14 (zero-filled .bss).
unsigned int g_Va00E03B14;
extern unsigned int g_Va00E03B2C;
// g_Va00E03B2C: matched references place it at VA 0xe03b2c (zero-filled .bss).
unsigned int g_Va00E03B2C;
extern unsigned int g_Va00E03B58;
// g_Va00E03B58: matched references place it at VA 0xe03b58 (zero-filled .bss).
unsigned int g_Va00E03B58;
extern unsigned int g_Va00E03B60;
// g_Va00E03B60: matched references place it at VA 0xe03b60 (zero-filled .bss).
unsigned int g_Va00E03B60;
extern unsigned int g_Va00E03B8C;
// g_Va00E03B8C: matched references place it at VA 0xe03b8c (zero-filled .bss).
unsigned int g_Va00E03B8C;
extern unsigned int g_Va00E03BC4;
// g_Va00E03BC4: matched references place it at VA 0xe03bc4 (zero-filled .bss).
unsigned int g_Va00E03BC4;
extern unsigned int g_Va00E03BCC;
// g_Va00E03BCC: matched references place it at VA 0xe03bcc (zero-filled .bss).
unsigned int g_Va00E03BCC;

unsigned int Rva0078D53AClearFlag(void)
{
	return g_Va00E03B00 &= 0xFFFFFFFEu;
}

unsigned int Rva0078D5E0ClearFlag(void)
{
	return g_Va00E03B14 &= 0xFFFFFFFEu;
}

unsigned int Rva0078D6A6ClearFlag(void)
{
	return g_Va00E03B2C &= 0xFFFFFFFEu;
}

unsigned int Rva0078D8F9ClearFlag(void)
{
	return g_Va00E03B58 &= 0xFFFFFFFEu;
}

unsigned int Rva0078D934ClearFlag(void)
{
	return g_Va00E03B60 &= 0xFFFFFFFEu;
}

unsigned int Rva0078DB02ClearFlag(void)
{
	return g_Va00E03B8C &= 0xFFFFFFFEu;
}

unsigned int Rva0078DBB6ClearFlag(void)
{
	return g_Va00E03BC4 &= 0xFFFFFFFEu;
}

unsigned int Rva0078DC0AClearFlag(void)
{
	return g_Va00E03BCC &= 0xFFFFFFFEu;
}

// 78D9C9 and78DA27 are the two static-name initialization unwind actions
// emitted by ProductionUpdate::update; its compiler-owned guard is E03B6C.
