// cl: /O1 /arch:SSE /G7 /MD /EHsc
// Identity: newRoad/newBridge allocate this type at 0x002DB1CA; their
// native field accesses and ZH TerrainRoadType agree on name +4, bridge +8,
// id +0xC, next +0x10, widths +0x14/+0x18 and texture +0x38. Existing
// constructor/destructor ownership and all member cleanup bytes are retained.
// Built from the banked attempt reverse/attempts/0x002db1ca.cpp; fix: the float
// read through g_Va00BBB8D8 is a compiler literals holding the retail
// values, not extern globals, which is what gives retail's operand order.
// ??1TerrainRoadType@@UAE@XZ @0x002DB311 318B
// Evidence: unlock lane; vtable g_00C03E24; callees clear 0x0048BA39 releaseBuffer 0x00036410 TailRecord dtor 0x0010F149 and ??_M CRT; 11 singles + 7 arrays to 0x144.
// ??0TerrainRoadType@@QAE@XZ @0x002DB1CA 327B
// Evidence: unlock lane ctor of same class; vtable 0x00803E24; callees UnicodeString ctor 0x00326BE6 clear TailRecord dtor and ??_L CRT; POD floats/ints incl 1.0f.
extern const void *const g_00C03E24[];

// Native scalar strings own one pointer and release it directly. Keep the
// array element's native cleanup ABI by using the same genuine ownership.
#include "../../../../reference/shims/bfme2_ascii/ascii_string.h"

typedef bool Bool;
typedef int Int;

enum BodyDamageType
{
	BODY_PRISTINE,
	BODY_DAMAGED,
	BODY_REALLYDAMAGED,
	BODY_RUBBLE,

	BODYDAMAGETYPE_COUNT
};

enum { MAX_BRIDGE_BODY_FX = 3 };

// The +0x64/+0xD4 sound slots: 4-byte reference records whose default
// constructor is the folded null initializer 0x00326BE6 and whose destructor
// is the null-checked release 0x0010F149.
struct OpaqueRefElement4
{
	struct OpaqueRefCounted *referent;
	OpaqueRefElement4() : referent(0) {}
	~OpaqueRefElement4();
	OpaqueRefElement4 &operator=(const OpaqueRefElement4 &other);
};

// TerrainRoads.cpp's TerrainRoadType members (ZH TerrainRoads.h order).
class TerrainRoadType
{
public:
	TerrainRoadType();
	virtual ~TerrainRoadType();

protected:
	AsciiString m_name;                         ///< 0x04
	Bool m_isBridge;                            ///< 0x08
	unsigned int m_id;                          ///< 0x0C
	TerrainRoadType *m_next;                     ///< 0x10
	float m_roadWidth;                           ///< 0x14
	float m_roadWidthInTexture;                  ///< 0x18
	float m_bridgeScale;                        ///< 0x1C
	AsciiString m_scaffoldObjectName;           ///< 0x20
	AsciiString m_scaffoldSupportObjectName;    ///< 0x24
	float m_radarColor[3];                      ///< 0x28
	AsciiString m_bridgeModelName;              ///< 0x34
	AsciiString m_texture;                      ///< 0x38
	AsciiString m_bridgeModelNameDamaged;       ///< 0x3C
	AsciiString m_textureDamaged;               ///< 0x40
	AsciiString m_bridgeModelNameReallyDamaged; ///< 0x44
	AsciiString m_textureReallyDamaged;         ///< 0x48
	AsciiString m_bridgeModelNameBroken;        ///< 0x4C
	AsciiString m_textureBroken;                ///< 0x50
	AsciiString m_towerObjectName[4];           ///< 0x54
	OpaqueRefElement4 m_damageToSoundString[ BODYDAMAGETYPE_COUNT ];								///< 0x64
	AsciiString m_damageToOCLString[ BODYDAMAGETYPE_COUNT ][ MAX_BRIDGE_BODY_FX ];		///< 0x74
	AsciiString m_damageToFXString[ BODYDAMAGETYPE_COUNT ][ MAX_BRIDGE_BODY_FX ];		///< 0xA4
	OpaqueRefElement4 m_repairedToSoundString[ BODYDAMAGETYPE_COUNT ];							///< 0xD4
	AsciiString m_repairedToOCLString[ BODYDAMAGETYPE_COUNT ][ MAX_BRIDGE_BODY_FX ];	///< 0xE4
	AsciiString m_repairedToFXString[ BODYDAMAGETYPE_COUNT ][ MAX_BRIDGE_BODY_FX ];	///< 0x114
	float m_transitionEffectsHeight;            ///< 0x144
	Int m_numFXPerType;                         ///< 0x148
};
// TerrainRoadType::~TerrainRoadType: defined in GameClient/Terrain/TerrainRoads.cpp (its row's unit).
TerrainRoadType::TerrainRoadType()
{
	float v0 = 0.0f;
	float v1C = 1.0f;
	m_isBridge = false;
	m_id = 0;
	m_next = 0;
	m_numFXPerType = 0;
	m_roadWidth = v0;
	m_roadWidthInTexture = v0;
	m_bridgeScale = v1C;
	m_radarColor[0] = v0;
	m_radarColor[1] = v0;
	m_radarColor[2] = v0;
	m_transitionEffectsHeight = v0;
}
