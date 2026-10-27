class BfmeThingBZD
{
public:
	void bfmeGoBZD(const char *text, int value);
	unsigned char m_bfmeHead[0x50];
	char m_bfmeBuf[0x80];
	int m_bfmeVal;
};

// The copy is msvcr71's strncpy (import thunk 0x0062983E), from <string.h>
// with _CRTIMP empty (the header's own guard) so the call is direct.
#define _CRTIMP
#include <string.h>

void BfmeThingBZD::bfmeGoBZD(const char *text, int value)
{
	strncpy(m_bfmeBuf, text, 0x40);
	m_bfmeVal = value;
}
