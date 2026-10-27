// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /Ireference/shims/bfme2_ascii
// BFME1 RadiusDecalTemplate creation donors9cbfb551 and ZH RadiusDecal.cpp
// guide creation/visibility semantics. Native calls use a measured40B two
// string descriptor, Shadow::ShadowTypeInfo, whose ctor/dtor are rowed at
// 79514/793FA.
// Native Shadow fields position8,angle20,color setter330995 established by
// creation callers plus exact RadiusDecal update330F98 and clear330DBA.
#include "ascii_string.h"
#include "../../../../../Libraries/Include/Lib/Coord3D.h"
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
class AudioManager0029E159 { public:virtual void slot0()=0;virtual void slot1()=0;virtual Shadow *create(Shadow::ShadowTypeInfo *)=0; };
extern AudioManager0029E159 *g_00DEC2D4;
class Player { public: __forceinline int getPlayerIndex() const {return index;}
 char pad00[0x54];int index;char pad58[0x280-0x58];unsigned color; };
class PlayerList { public: __forceinline Player *getLocalPlayer() const {return local;}
 char pad00[0x10];Player *local; };
extern PlayerList *ThePlayerList;
static __forceinline void setCoordinates(Coord3D *to,float x,float y,float z) {to->x=x;to->y=y;to->z=z;}
void RadiusDecalTemplate::createDeathDecal(const Coord3D *pos,float angle,const unsigned *color,RadiusDecal *out) {
 if(m_name.isEmpty()==true) return;
 if(!pos) return;
 if(m_unmodelled20==0.0f) return;
 if(m_unmodelled24==0.0f) return;
 out->clear();out->m_empty=false;
 Shadow::ShadowTypeInfo descriptor;
 descriptor.first.setCopyInline(m_name);descriptor.second.setCopyInline(m_secondName);
 descriptor.sizeX=m_unmodelled24;descriptor.sizeY=m_unmodelled24;
 descriptor.allowUpdates=1;descriptor.worldAlign=1;
 descriptor.style=m_shadowType;descriptor.offsetX=0.0f;descriptor.offsetY=0.0f;
 out->m_shadow=g_00DEC2D4->create(&descriptor);
 if(!out->m_shadow) return;
 out->m_shadow->setAngle(angle);
 out->m_shadow->setColor((int)*color);
 Coord3D adjusted;
 setCoordinates(&adjusted,pos->x+descriptor.offsetX,pos->y+descriptor.offsetY,pos->z);
 out->m_shadow->setPosition(adjusted);
 out->m_decalTemplate=this;
}

void RadiusDecalTemplate::createRadiusDecal(const Coord3D &pos,float radius,const Player *player,RadiusDecal &out) const {
 out.clear();
 if(!player || m_name.isEmpty() || radius<=0.0f) return;
 out.m_empty=false;
 if(m_onlyVisibleToOwningPlayer && player->getPlayerIndex()!=ThePlayerList->getLocalPlayer()->getPlayerIndex()) return;
 Shadow::ShadowTypeInfo descriptor;
 descriptor.allowUpdates=0;descriptor.worldAlign=1;
 descriptor.style=m_shadowType;
 descriptor.first.setCopyInline(m_name);descriptor.second.setCopyInline(m_secondName);
 descriptor.sizeX=radius*2.0f;descriptor.sizeY=radius*2.0f;
 out.m_shadow=g_00DEC2D4->create(&descriptor);
 if(out.m_shadow) {
  out.m_shadow->setAngle(0.0f);
  unsigned c=m_color?m_color:player->color;
  out.m_shadow->setColor((int)c);
  out.m_shadow->setPosition(pos);
  if(radius>110.0f) out.m_shadow->at64=true;
  out.m_decalTemplate=this;
 }
}

// WB names this createSelectionRadiusDecal; original float3 vs Coord3D
// by-value source prototype remains donor-carried. Native ABI is12B coords
// followed by selected count, packed color, output pointer and extra scalar.
void RadiusDecalTemplate::createSelectionRadiusDecal(Coord3D pos,unsigned selected,int color,RadiusDecal *out,float scale) {
 if(m_name.isEmpty()==true) return;
 if(selected==0) return;
 if(m_unmodelled20==0.0f) return;
 if(m_unmodelled24==0.0f) return;
 out->clear();out->m_empty=false;
 Shadow::ShadowTypeInfo descriptor;
 descriptor.first.setCopyInline(m_name);descriptor.second.setCopyInline(m_secondName);
 descriptor.allowUpdates=0;descriptor.worldAlign=1;descriptor.style=m_shadowType;
 float diameter=rva00330D3E(selected);
 descriptor.sizeX=diameter;descriptor.sizeY=diameter;
 descriptor.offsetX=0.0f;descriptor.offsetY=0.0f;descriptor.scale=scale;
 out->m_shadow=g_00DEC2D4->create(&descriptor);
 if(out->m_shadow) {
  out->m_shadow->setAngle(0.0f);
  out->m_shadow->setColor(color);
  out->m_shadow->setPosition(pos);
  out->m_decalTemplate=this;
 }
}
