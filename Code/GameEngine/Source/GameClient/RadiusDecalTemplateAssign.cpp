// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
//
// ?rva00330CDD@RadiusDecalTemplate@@QAEXABV1@@Z @0x00330CDD 97B
// RadiusDecalTemplate copy-assign shaped method: copies scalars +8..+1C,
// then both AsciiStrings via pinned ??4AsciiString@@QAEAAV0@ABV0@@Z,
// then fields +20..+30 with +24 before +20 per retail order.
// Layout verbatim from RadiusDecalTemplateRva00330D3E.cpp (next row 0x00330D3E).
// Callers 0x000B3287 0x000B50A4 0x00289951 0x00289983 0x002A4607.
#include "ascii_string.h"
#include "../../../Libraries/Include/Lib/Coord3D.h"
// RadiusDecal TU class views, kept verbatim in each of this TU's sources until
// they merge: offsets from the rowed bodies, member names from the seed.
class INI;
class Xfer;
class Player;
class RadiusDecal;

class RadiusDecalTemplate
{
public:
	RadiusDecalTemplate();
	float rva00330D3E(unsigned int index);
	static void parseRadiusDecalTemplate(INI *ini, void *instance, void *store, const void *userData);
	void rva00330CDD(const RadiusDecalTemplate &other);
	bool rva00331578(const RadiusDecalTemplate &other) const;
	void xferRadiusDecalTemplate(Xfer *xfer);
	void createSelectionRadiusDecal(Coord3D pos, unsigned selected, int color, RadiusDecal *out, float scale);
	void createDeathDecal(const Coord3D *pos, float angle, const unsigned *color, RadiusDecal *out);
	void createRadiusDecal(const Coord3D &pos, float radius, const Player *player, RadiusDecal &out) const;

	AsciiString m_name; // +0x00
	AsciiString m_secondName; // +0x04
	int m_shadowType; // +0x08
	float m_minOpacity; // +0x0C
	float m_maxOpacity; // +0x10
	float m_opacityThrobTime; // +0x14
	int m_color; // +0x18
	bool m_onlyVisibleToOwningPlayer; // +0x1C
	float m_unmodelled20; // +0x20
	float m_unmodelled24; // +0x24
	unsigned int m_unmodelled28; // +0x28
	float m_unmodelled2C; // +0x2C
	float m_unmodelled30; // +0x30
};

class Shadow
{
public:
	// The descriptor the creators fill for the shadow manager's create slot.
	struct ShadowTypeInfo
	{
		ShadowTypeInfo();
		~ShadowTypeInfo();
		AsciiString first, second;
		int style;
		float sizeX, sizeY, offsetX, offsetY, at1C, scale;
		unsigned char at24, allowUpdates, worldAlign;
	};
	void setOpacity(int value);
	void setColor(int color);
	__forceinline void setPosition(const Coord3D &p) { position = p; }
	__forceinline float getAngle() const { return angle; }
	__forceinline void setAngle(float a) { angle = a; }
	__forceinline void setRadius(float r) { radius58 = r; radius5C = r; }
	char pad00[8];
	Coord3D position; // +0x08
	char pad14[0xC];
	float angle; // +0x20
	char pad24[0x10];
	volatile unsigned type; // +0x34
	char pad38[0x20];
	float radius58, radius5C; // +0x58
	char pad60[4];
	bool at64; // +0x64
};

class RadiusDecal
{
public:
	RadiusDecal();
	~RadiusDecal();
	void clear();
	void setOpacity(float o);
	void setPosition(const Coord3D &pos);
	void Rva00330E15(const Coord3D &pos);
	void rva00330F7D(Xfer *xfer);
	void update();
	const RadiusDecalTemplate *m_decalTemplate; // +0x00
	Shadow *m_shadow; // +0x04
	bool m_empty; // +0x08
	float m_extra; // +0x0C
};
void RadiusDecalTemplate::rva00330CDD(const RadiusDecalTemplate &other)
{
	m_shadowType = other.m_shadowType;
	m_minOpacity = other.m_minOpacity;
	m_maxOpacity = other.m_maxOpacity;
	m_opacityThrobTime = other.m_opacityThrobTime;
	m_color = other.m_color;
	m_onlyVisibleToOwningPlayer = other.m_onlyVisibleToOwningPlayer;
	m_name = other.m_name;
	m_secondName = other.m_secondName;
	m_unmodelled24 = other.m_unmodelled24;
	m_unmodelled20 = other.m_unmodelled20;
	m_unmodelled28 = other.m_unmodelled28;
	m_unmodelled2C = other.m_unmodelled2C;
	m_unmodelled30 = other.m_unmodelled30;
}

// ?rva00331578@RadiusDecalTemplate@@QBE_NABV1@@Z
// Native Ghidra extent 0x00331578..0x0033162B; RET 4. The two string
// compares call the verified worker at 0x000069D6. Its consumed layout
// and field order agree with the rowed assignment and constructor views.
// Retail leaves the +0x1c byte out of this comparison.
bool RadiusDecalTemplate::rva00331578(const RadiusDecalTemplate &other) const
{
	if (m_shadowType == other.m_shadowType
		&& m_minOpacity == other.m_minOpacity
		&& m_maxOpacity == other.m_maxOpacity
		&& m_opacityThrobTime == other.m_opacityThrobTime
		&& m_color == other.m_color
		&& m_name.compare(other.m_name) == 0
		&& m_secondName.compare(other.m_secondName) == 0
		&& m_unmodelled24 == other.m_unmodelled24
		&& m_unmodelled20 == other.m_unmodelled20
		&& m_unmodelled28 == other.m_unmodelled28
		&& m_unmodelled2C == other.m_unmodelled2C
		&& m_unmodelled30 == other.m_unmodelled30)
		return true;
	return false;
}
