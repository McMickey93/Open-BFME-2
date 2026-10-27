class BfmeThingCEB
{
public:
	void bfmeGoCEB(const char *text, int value);
	unsigned char m_bfmeHead[0x90];
	char m_bfmeBuf[0x44];
	int m_bfmeVal;
};

// The copy is msvcr71's strncpy (import thunk 0x0062983E), from <string.h>
// with _CRTIMP empty (the header's own guard) so the call is direct.
#define _CRTIMP
#include <string.h>

void BfmeThingCEB::bfmeGoCEB(const char *text, int value)
{
	strncpy(m_bfmeBuf, text, 0x40);
	m_bfmeVal = value;
}
