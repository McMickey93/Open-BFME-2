// cl: /DNDEBUG /MD
// ?getAudioLODLevelName@GameLODManager@@QAEPBDH@Z @0x00202678 40B. WorldBuilder
// GameLOD.cpp:995 names it; the caller 0x002E53FA loads TheGameLODManager into
// ecx (the body never reads it). Indexed string getter: 0<=i<2
// returns table bfmeTabEYC[i] (0x00DB96B0), -1 returns "Unknown", else g_00BBE8E8.
// Evidence: caller 0x002E53FA passes int and uses result for StringBase::set,
// string literal 0x007D0FA4 "Unknown", table at 0x00DB96B0, default at 0x00BBE8E8.
extern const char *bfmeTabEYC[];

class GameLODManager
{
public:
	const char *getAudioLODLevelName(int i);
};

const char *GameLODManager::getAudioLODLevelName(int i)
{
	if (i >= 0 && i < 2)
		return bfmeTabEYC[i];
	if (i == -1)
		return "Unknown";
	return "?";
}
