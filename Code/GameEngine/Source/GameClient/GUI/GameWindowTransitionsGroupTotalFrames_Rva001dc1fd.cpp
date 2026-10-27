// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmelist /Ireference/shims/bfmealloc -Ireference/open-bfme-1/game/GameEngine/Source/GameClient/GUI /Ireference/shims/bfme2_ascii

// The inline forwarders over StringBase are what put retail's EH saved-esp
// store ahead of the in-place ctor `this` (EH transposition).
#include "ascii_string.h"

class TransitionGroup;

// TransitionGroup's rowed bodies, on the address-named view.
class Rva001DBDA4
{
public:
	int rva001DBDA4() const; // getTotalFrames
};

// upstream layout: inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameClient/GameWindowTransitions.h
class GameWindowTransitionsHandler
{
public:
	int bfmeGetGroupTotalFrames( AsciiString groupName );
private:
	TransitionGroup *findGroup( AsciiString groupName );
};

// Return the duration of a named transition group, or zero when absent.
// ?bfmeGetGroupTotalFrames@GameWindowTransitionsHandler@@QAEHVAsciiString@@@Z
int GameWindowTransitionsHandler::bfmeGetGroupTotalFrames( AsciiString groupName )
{
	int totalFrames = 0;
	TransitionGroup *group = findGroup( groupName );
	if (group)
		totalFrames = ((Rva001DBDA4 *)group)->rva001DBDA4();
	return totalFrames;
}
