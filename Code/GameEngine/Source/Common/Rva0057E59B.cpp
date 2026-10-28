// cl: /DNDEBUG /MD
// ?rva0057E59B@Rva0057E97A@@QAEXH_N@Z @0x0057E59B 26B
// Window enable helper of the Rva0057E97A holder: w = m_begin[index] at +0x7C,
// if w is null skip, else w->winEnable(enable) via rowed 0x00313BEC.
// Same class and flags as the neighbour 0x0057E97A TU. Evidence: packet
// disasm, single caller 0x0043DBE0, prev/next rows.
#include "../GameClient/GUI/GUICallbacks/Apt/AptMpGameRulesView.h"

void Rva0057E97A::rva0057E59B(int index, bool enable)
{
	class GameWindow *gameWindow = m_begin[index];
	if (gameWindow != 0)
		gameWindow->winEnable(enable);
}
