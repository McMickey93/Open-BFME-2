// cl: /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib -Ireference/open-bfme-1/inputs/reference/shims/iniexception -Ireference/open-bfme-1/inputs/reference/shims/sweep -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main -Ireference/open-bfme-1/game/GameEngine/Source/GameClient /Ireference/shims/bfme2_ascii_zh
// MetaMap::findGameMessageMetaType() -- name lookup for meta events.
//
// Evidence: retail 0x001DB3FE (52 bytes) is a linear scan of the {name,value}
// table at RVA 0x007DA640 calling the msvcr71 _strcmpi import and returning the
// matched value or 0 (MSG_INVALID). The table's "SAVE_VIEW2" entry appears in
// Zero Hour's MetaEvent.cpp GameMessageMetaTypeNames[]; the BFME1 conversion of
// that file carries a byte-matched copy of this function.
//
// The table below is retail's, read from game.dat: 125 names and the null
// terminator (1008 bytes, ending where CategoryListName starts at 0x007DAA30).
// BFME 2 drops and adds entries against Zero Hour (VIEW_HOME_BASE, AUTO_SAVE,
// CHAT_BUDDIES, STANCE_*, ORDERMODE_*, ...) and renumbers GameMessage::Type,
// so the values are retail's integers rather than Zero Hour enumerators.
//
// The class views below are MetaEvent.cpp's (the approved TU this body belongs
// to), so this file composes into it.
#include <string.h>

class GameMessage
{
public:
	enum Type { MSG_INVALID = 0 };
};

class MetaMapRec;

class MetaMap
{
protected:
	GameMessage::Type findGameMessageMetaType(const char *name);
};

struct LookupListRec { const char *name; int value; };

// PRIVATE DATA ///////////////////////////////////////////////////////////////

static const LookupListRec GameMessageMetaTypeNames[] =
{
	{ "SAVE_VIEW1", 36 },
	{ "SAVE_VIEW2", 37 },
	{ "SAVE_VIEW3", 38 },
	{ "SAVE_VIEW4", 39 },
	{ "SAVE_VIEW5", 40 },
	{ "SAVE_VIEW6", 41 },
	{ "SAVE_VIEW7", 42 },
	{ "SAVE_VIEW8", 43 },
	{ "VIEW_VIEW1", 44 },
	{ "VIEW_VIEW2", 45 },
	{ "VIEW_VIEW3", 46 },
	{ "VIEW_VIEW4", 47 },
	{ "VIEW_VIEW5", 48 },
	{ "VIEW_VIEW6", 49 },
	{ "VIEW_VIEW7", 50 },
	{ "VIEW_VIEW8", 51 },
	{ "CREATE_TEAM0", 52 },
	{ "CREATE_TEAM1", 53 },
	{ "CREATE_TEAM2", 54 },
	{ "CREATE_TEAM3", 55 },
	{ "CREATE_TEAM4", 56 },
	{ "CREATE_TEAM5", 57 },
	{ "CREATE_TEAM6", 58 },
	{ "CREATE_TEAM7", 59 },
	{ "CREATE_TEAM8", 60 },
	{ "CREATE_TEAM9", 61 },
	{ "SELECT_TEAM0", 62 },
	{ "SELECT_TEAM1", 63 },
	{ "SELECT_TEAM2", 64 },
	{ "SELECT_TEAM3", 65 },
	{ "SELECT_TEAM4", 66 },
	{ "SELECT_TEAM5", 67 },
	{ "SELECT_TEAM6", 68 },
	{ "SELECT_TEAM7", 69 },
	{ "SELECT_TEAM8", 70 },
	{ "SELECT_TEAM9", 71 },
	{ "ADD_TEAM0", 72 },
	{ "ADD_TEAM1", 73 },
	{ "ADD_TEAM2", 74 },
	{ "ADD_TEAM3", 75 },
	{ "ADD_TEAM4", 76 },
	{ "ADD_TEAM5", 77 },
	{ "ADD_TEAM6", 78 },
	{ "ADD_TEAM7", 79 },
	{ "ADD_TEAM8", 80 },
	{ "ADD_TEAM9", 81 },
	{ "VIEW_TEAM0", 82 },
	{ "VIEW_TEAM1", 83 },
	{ "VIEW_TEAM2", 84 },
	{ "VIEW_TEAM3", 85 },
	{ "VIEW_TEAM4", 86 },
	{ "VIEW_TEAM5", 87 },
	{ "VIEW_TEAM6", 88 },
	{ "VIEW_TEAM7", 89 },
	{ "VIEW_TEAM8", 90 },
	{ "VIEW_TEAM9", 91 },
	{ "SELECT_MATCHING_UNITS", 92 },
	{ "SELECT_NEXT_UNIT", 93 },
	{ "SELECT_PREV_UNIT", 94 },
	{ "SELECT_NEXT_WORKER", 95 },
	{ "SELECT_PREV_WORKER", 96 },
	{ "VIEW_HOME_BASE", 97 },
	{ "VIEW_LAST_RADAR_EVENT", 98 },
	{ "SELECT_HERO", 99 },
	{ "SELECT_ALL", 100 },
	{ "SCATTER", 101 },
	{ "STOP", 102 },
	{ "DEPLOY", 103 },
	{ "CREATE_FORMATION", 104 },
	{ "AUTO_SAVE", 105 },
	{ "FOLLOW", 106 },
	{ "CHAT_PLAYERS", 107 },
	{ "CHAT_BUDDIES", 108 },
	{ "CHAT_ALLIES", 109 },
	{ "CHAT_EVERYONE", 110 },
	{ "DIPLOMACY", 111 },
	{ "OPTIONS", 112 },
	{ "TOGGLE_CONTROL_BAR", 113 },
	{ "BEGIN_PATH_BUILD", 114 },
	{ "END_PATH_BUILD", 115 },
	{ "BEGIN_FORCEATTACK", 116 },
	{ "END_FORCEATTACK", 117 },
	{ "BEGIN_FORCEMOVE", 118 },
	{ "END_FORCEMOVE", 119 },
	{ "BEGIN_WAYPOINTS", 120 },
	{ "END_WAYPOINTS", 121 },
	{ "BEGIN_PREFER_SELECTION", 122 },
	{ "END_PREFER_SELECTION", 123 },
	{ "TAKE_SCREENSHOT", 124 },
	{ "ALL_CHEER", 125 },
	{ "TOGGLE_ATTACKMOVE", 126 },
	{ "BEGIN_CAMERA_ROTATE_LEFT", 127 },
	{ "END_CAMERA_ROTATE_LEFT", 128 },
	{ "BEGIN_CAMERA_ROTATE_RIGHT", 129 },
	{ "END_CAMERA_ROTATE_RIGHT", 130 },
	{ "BEGIN_CAMERA_ZOOM_IN", 131 },
	{ "END_CAMERA_ZOOM_IN", 132 },
	{ "BEGIN_CAMERA_ZOOM_OUT", 133 },
	{ "END_CAMERA_ZOOM_OUT", 134 },
	{ "CAMERA_RESET", 135 },
	{ "BEGIN_CAMERA_SCROLL_LEFT", 136 },
	{ "END_CAMERA_SCROLL_LEFT", 137 },
	{ "BEGIN_CAMERA_SCROLL_RIGHT", 138 },
	{ "END_CAMERA_SCROLL_RIGHT", 139 },
	{ "BEGIN_CAMERA_SCROLL_UP", 140 },
	{ "END_CAMERA_SCROLL_UP", 141 },
	{ "BEGIN_CAMERA_SCROLL_DOWN", 142 },
	{ "END_CAMERA_SCROLL_DOWN", 143 },
	{ "PLACE_BEACON", 144 },
	{ "DELETE_BEACON", 145 },
	{ "SPELL_STORE", 146 },
	{ "STANCE_AGGRESSIVE", 147 },
	{ "STANCE_HOLDGROUND", 148 },
	{ "STANCE_BATTLE", 149 },
	{ "ORDERMODE_IMMEDIATE", 150 },
	{ "ORDERMODE_WAYPOINT", 151 },
	{ "ORDER_SYNCHRONIZE", 152 },
	{ "TOGGLE_PLANNING_MODE", 153 },
	{ "SELL", 154 },
	{ "DEMO_PERFORM_STATISTICAL_DUMP", 155 },
	{ "TOGGLE_FAST_FORWARD_MODE", 156 },
	{ "RELOAD_RAPID_ITERATION_FEATURE", 157 },
	{ "REFRESH_RAPID_ITERATION_FEATURE", 158 },
	{ "DEBUG_TOGGLE_SHOWVISIONEGGS", 159 },
	{ "DEBUG_TOGGLE_STRINGTAGS", 160 },
	{ 0, 0 }	// keep this last!
};

//-------------------------------------------------------------------------------------------------
GameMessage::Type MetaMap::findGameMessageMetaType(const char* name)
{
	// Retail imports msvcr71.dll!_strcmpi at this call site (not _stricmp,
	// though the two CRT entry points are behaviorally identical) -- kept as
	// _strcmpi to byte-match the import thunk the linker actually picked.
	for (const LookupListRec* metaNames = GameMessageMetaTypeNames; metaNames->name; metaNames++)
		if (_strcmpi(metaNames->name, name) == 0)
			return (GameMessage::Type)metaNames->value;

	return GameMessage::MSG_INVALID;
}
