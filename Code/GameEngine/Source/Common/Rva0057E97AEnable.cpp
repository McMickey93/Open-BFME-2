// cl: /DNDEBUG /MD
// ?rva0057E97A@Rva0057E97A@@QAEXXZ @0x0057E97A 115B
// Toggles a window list: reads holder at +0x58 via rowed 0x0043DA65 (row types
// int but retail uses the return as an object pointer for slot-0x30 bool check;
// cast is required to keep the row mangling), then enables each GameWindow in
// [0x7C,0x80) with (flag && intAtB4[i]==1) via rowed GameWindow::winEnable.
// Evidence: packet disasm with rowed callees 0x0043DA65 and 0x00313BEC;
// callers 0x0057EA0F/0x0057ED2B of the same class; neighbours in Common.
#include "../GameClient/GUI/GUICallbacks/Apt/AptMpGameRulesView.h"

void Rva0057E97A::rva0057E97A()
{
	int tmp = m_holder->rva0043DA65();
	bool use;
	if (tmp != 0 && ((Rva0057E97AValidator *)tmp)->checkValid())
		use = true;
	else
		use = false;
	GameWindow **begin = m_begin;
	m_updating = false;
	if (begin != m_end)
	{
		unsigned int off = 0;
		do
		{
			GameWindow *gameWindow = *begin;
			if (gameWindow != 0)
				gameWindow->winEnable(use && m_enableFlags[off] == 1);
			++begin;
			++off;
		} while (begin != m_end);
	}
	m_updating = true;
}
