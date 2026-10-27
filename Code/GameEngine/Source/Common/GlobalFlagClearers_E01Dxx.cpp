// Seven B2-native flag-word clearers across three .data flag words of one
// contiguous run (0x0077AC0A-0x0077AD65):
//
//     mov eax,[<address>] / and al,<mask8> / mov [<address>],eax / ret
//
// Same /G7 byte-register narrowing as GlobalFlagClearers_08.cpp (defaults
// emit `and eax,imm`). Each body carries a .rdata table slot (0x00923918
// and on). Identity is not recovered; names derive from addresses,
// following GlobalFlagClearers_08.cpp.
// Read before masking so both standalone and size-optimized TU builds keep
// retail's load / mask AL / store sequence. The qualified reads are a
// source adaptation, not evidence of the original globals' qualifiers.
// cl: /G7 /MD /EHsc /DNDEBUG

extern unsigned int g_Va00E01D24;
// g_Va00E01D24: matched references place it at VA 0xe01d24 (zero-filled .bss).
unsigned int g_Va00E01D24;
extern unsigned int g_Va00E01D34;
// g_Va00E01D34: matched references place it at VA 0xe01d34 (zero-filled .bss).
unsigned int g_Va00E01D34;
extern unsigned int g_Va00E01D3C;
// g_Va00E01D3C: matched references place it at VA 0xe01d3c (zero-filled .bss).
unsigned int g_Va00E01D3C;

unsigned int Rva0077AC0AClearFlag(void)
{
	unsigned int &flag = g_Va00E01D24;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFEu;
}

unsigned int Rva0077AC17ClearFlag(void)
{
	unsigned int &flag = g_Va00E01D24;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFDu;
}

unsigned int Rva0077AC24ClearFlag(void)
{
	unsigned int &flag = g_Va00E01D24;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFBu;
}

unsigned int Rva0077AC3BClearFlag(void)
{
	unsigned int &flag = g_Va00E01D34;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFEu;
}

unsigned int Rva0077AC48ClearFlag(void)
{
	unsigned int &flag = g_Va00E01D34;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFDu;
}

unsigned int Rva0077AC55ClearFlag(void)
{
	unsigned int &flag = g_Va00E01D34;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFBu;
}

unsigned int Rva0077AD65ClearFlag(void)
{
	unsigned int &flag = g_Va00E01D3C;
	const unsigned int flags = static_cast<const volatile unsigned int &>(flag);
	return flag = flags & 0xFFFFFFFEu;
}
