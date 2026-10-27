// cl: /DNDEBUG /MD /EHsc
// ?rva0056F495@Rva0056EA91@@QAE_NABVUnicodeString@@@Z @0x0056F495 110B
// Chain of just-landed Rva0056EA91 0x0056EA91: current text via 0x0056EA91,
// compare via StringBase<G> 0x00006A7A, null +0xA8 guard, SetText 0x00322D63.
// Evidence: EH_prolog 0x00629188, ret 4, callers none, sibling GadgetComboBoxRva0056EBA1.
typedef unsigned short wchar_t;
typedef int Int;

#ifndef NULL
#define NULL 0
#endif

#include "../../../../../../reference/shims/bfme2_ascii/unicode_string.h"


class GameWindow;

void GadgetComboBoxSetText(GameWindow *comboBox, UnicodeString text);
UnicodeString GadgetComboBoxGetText(GameWindow *comboBox);

class Rva0056EA91
{
public:
	UnicodeString rva0056EA91();
	bool rva0056F495(const UnicodeString &text);
private:
	unsigned char m_pad[0xA8];
	GameWindow *m_combo;
};

bool Rva0056EA91::rva0056F495(const UnicodeString &text)
{
	bool ok = false;
	UnicodeString cur = rva0056EA91();
	if (cur.compare(text) != 0)
	{
		if (m_combo != NULL)
		{
			GadgetComboBoxSetText(m_combo, text);
			ok = true;
		}
	}
	return ok;
}
