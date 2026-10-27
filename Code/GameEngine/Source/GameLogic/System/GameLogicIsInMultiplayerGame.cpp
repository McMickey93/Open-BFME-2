// cl: /DNDEBUG /MD /EHsc

// ?isInMultiplayerGame@GameLogic@@QAE_NXZ @0x42235 (23B):
// GameLogic::isInMultiplayerGame, ZH GameLogic.h:404 verbatim shape
// (m_gameMode at +0x110 is GAME_LAN(1) or GAME_INTERNET(5)). B2 carries it
// out-of-line (ZH inlines it); 43 image-wide callers including
// ScienceStore::getSciencePurchaseCost. Leaf, no pins.

#include "../../Common/GameLogicObjectLookupView.h"

// ?isInMultiplayerGame@GameLogic@@QAE_NXZ
inline __declspec(noinline) bool GameLogic::isInMultiplayerGame()
{
	return m_110 == 1 || m_110 == 5;
}
static bool (GameLogic::*s_anchor_isInMultiplayerGame)() = &GameLogic::isInMultiplayerGame;
