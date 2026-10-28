// cl: -DNDEBUG -DWIN32 -D_WINDOWS -MD -EHsc
//
// The AnimationSoundClientBehaviorGlobalSetting block -- BFME-only, one global
// tuning value for the AnimationSoundClientBehavior module, and a block that
// refuses to be overridden from a map.ini.
//
// The refusal is the message-carrying throw BFME uses in place of Zero Hour's
// bare INI_INVALID_DATA, and its text is verbatim from the image.

class INI;

typedef void (*INIFieldParseProc)( INI *ini, void *instance, void *store, const void *userData );

struct FieldParse
{
	const char *token;
	INIFieldParseProc parse;
	const void *userData;
	int offset;
};

enum INILoadType
{
	INI_LOAD_INVALID,
	INI_LOAD_OVERWRITE,
	INI_LOAD_CREATE_OVERRIDES,
	INI_LOAD_MULTIFILE
};

// BFME keeps m_loadType at INI+0x08; Zero Hour's header puts it at +0x2010
// because of the 8KB read buffer BFME does not have (docs/ini_loading.md).
class INI
{
public:
	void initFromINI( void *what, const FieldParse *parseTable );
	static void parseReal( INI *ini, void *instance, void *store, const void *userData );
	INILoadType getLoadType() const { return m_loadType; }

private:
	char m_pad[ 0x08 ];
	INILoadType m_loadType;	// +0x08
};

class INIException
{
public:
	char *mFailureMessage;
	int m_argCount;
	INIException(int argCount, const char *errorMessage, ...);
	INIException(const INIException &that);
	~INIException();
};

struct AnimationSoundClientBehaviorGlobalSetting
{
	float m_minMicrophoneDistanceToDirty;	// 0x00  MinMicrophoneDistanceToDirty

	static const FieldParse m_fieldParseTable[];
};

// The retail table at 0x0083CA88: 1 entry and the null terminator.
const FieldParse AnimationSoundClientBehaviorGlobalSetting::m_fieldParseTable[2] = {
	{ "MinMicrophoneDistanceToDirty", &INI::parseReal, 0, 0x0 },
	{ 0, 0, 0, 0 }
};

// The single instance the block parses into, at 0x012B4D44. Nothing in the image
// names it; the class name is the block keyword.
extern AnimationSoundClientBehaviorGlobalSetting TheAnimationSoundClientBehaviorGlobalSetting;

void parseAnimationSoundClientBehaviorGlobalSetting( INI *ini )
{
	if( ini->getLoadType() == INI_LOAD_CREATE_OVERRIDES )
		throw INIException( 3, "Cannot override AnimationSoundClientBehaviorGlobalSetting in map.ini" );

	ini->initFromINI( &TheAnimationSoundClientBehaviorGlobalSetting,
										AnimationSoundClientBehaviorGlobalSetting::m_fieldParseTable );
}
