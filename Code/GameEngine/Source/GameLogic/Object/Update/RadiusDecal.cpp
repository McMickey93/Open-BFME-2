// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /Ireference/shims/bfme2_ascii
// BFME1 RadiusDecal_update.cpp at9cbfb551 supplies opacity, visibility,
// frame and continuous rotation semantics; retail BFME2 adds the bounded
// radius/fade branch. Same owner proven by RadiusDecal::clear330DBA and
// rva330F7D receiver/callers. Native layout fields below are measured.
// The two-instruction FISTP fragment is the donor's rounded float-to-int
// machinery, proven by native731009..73100F; ordinary unsigned casts emit
// truncation/conversion helpers instead and change the rounding contract.
#include "../../../Common/GameLogicObjectLookupView.h"
#include "ascii_string.h"
#include "../../../../../Libraries/Include/Lib/Coord3D.h"
#include <math.h>
float Sin(float);float normalizeAngle(float);
extern float BfmeClientFramesPerMillisecond;
// Retail's one-frame-in-seconds at 30 fps, VA 0x00DBA508 (RVA 0x009BA508): the
// rowed update reads it with `flds 0xdba508` (retail 0x00331FDF) before
// multiplying the decal's rotationSpeed by the degrees-to-radians constant at
// RVA 0x0080DB6C. That address is already owned -- the ledger binds 0x009BA508
// to ?opacityLogicStepSeconds@@3MA and Drawable_rva00275598.cpp:105 defines it
// as 0.03333333507180214f, which is exactly 1/30 -- so the donor spelling
// ?g_bfmeSecondCF@@3MA was this unit's private name for an existing object and
// a second definition of it here would be a duplicate. This unit therefore
// reads the same object under the ledger's name, which is the spelling
// Bfme5TinyFifteenO1.cpp, Rva002BEDCAMovementDuration.cpp and
// Rva002BF09EPlacePoint.cpp already use.
extern float opacityLogicStepSeconds;
class GameClient { public:
 virtual void slot0()=0;
 virtual void slot1()=0;
 virtual void slot2()=0;
 virtual void slot3()=0;
 virtual void slot4()=0;
 virtual void slot5()=0;
 virtual void slot6()=0;
 virtual void slot7()=0;
 virtual void slot8()=0;
 virtual void slot9()=0;
 virtual void slot10()=0;
 virtual void slot11()=0;
 virtual void slot12()=0;
 virtual void slot13()=0;
 virtual void slot14()=0;
 virtual void slot15()=0;
 virtual void slot16()=0;
 virtual void slot17()=0;
 virtual void slot18()=0;
 virtual void slot19()=0;
 virtual void slot20()=0;
 virtual void slot21()=0;
 virtual void slot22()=0;
 virtual void slot23()=0;
 virtual void slot24()=0;
 virtual void slot25()=0;
 virtual void slot26()=0;
 virtual void slot27()=0;
 virtual void slot28()=0;
 virtual void slot29()=0;
 virtual void slot30()=0;
 virtual unsigned getFrame()=0;
};
extern GameClient *TheGameClient;extern GameLogic *TheGameLogic;
class GlobalData { public: char pad00[0x5C];volatile bool at5C; };
extern GlobalData *TheWritableGlobalData;
class BfmeOwnVVD { public:virtual void slot0()=0;virtual void slot1()=0;virtual int slot2()=0; };
class LookAtTranslator; extern LookAtTranslator *TheLookAtTranslator;
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
void RadiusDecal::update() {
 if(m_extra==0.0f) m_extra=(float)TheGameLogic->getFrame();
 if(!m_shadow) goto update_extra;
 if(!m_decalTemplate) goto update_extra;
 {
 unsigned frame=TheGameClient->getFrame();
 float throbTime=(float)ceil(m_decalTemplate->m_opacityThrobTime*BfmeClientFramesPerMillisecond);
 unsigned cycle;
 __asm fld throbTime
 __asm fistp cycle
 unsigned divisorValue=cycle;
 const unsigned minimum=1;
 const unsigned *divisor=divisorValue>1?&divisorValue:&minimum;
 unsigned phase=frame%*divisor;
 float percent=0.5f*(Sin((float)phase*6.28318548f/(float)*divisor)+1.0f);
 int opacity;
 if(TheGameLogic->getDrawIconUI()) opacity=(int)(((m_decalTemplate->m_maxOpacity-m_decalTemplate->m_minOpacity)*percent+m_decalTemplate->m_minOpacity)*255.0f);
 else opacity=0;
 {
  bool special=m_shadow->type==0x1000;
  unsigned value=*(const volatile unsigned *)&m_decalTemplate->m_unmodelled28;
  if(value>0) special=true;
  if(!special && TheWritableGlobalData->at5C && ((BfmeOwnVVD *)TheLookAtTranslator)->slot2()) opacity=0;
 }
 set_opacity:
 m_shadow->setOpacity(opacity);
 float speed=m_decalTemplate->m_unmodelled2C;
 float step=m_decalTemplate->m_unmodelled30;
 float limit=2.0f*m_decalTemplate->m_unmodelled24;
 if(speed>0.0f && step>0.0f && limit>0.0f) {
  float radius=m_shadow->radius5C-step;
  if(radius<0.0f) radius+=limit;
  else if(radius>limit) radius=limit;
  m_shadow->setRadius(radius);
  float fade=1.0f-radius/limit;
  fade*=fade;
  m_shadow->setAngle(normalizeAngle(m_shadow->getAngle()+fade*speed));
  opacity=(int)(fade*255.0f);
  m_shadow->setOpacity(opacity);
  m_shadow->setColor(opacity*0x10101-0x1000000);
 } else if(m_decalTemplate->m_unmodelled2C!=0.0f) {
  float scale=opacityLogicStepSeconds;
  scale*=0.0174532924f;
  scale*=m_decalTemplate->m_unmodelled2C;
  scale*=60.0f;
  unsigned clientFrame=TheGameClient->getFrame();
  m_shadow->angle=(float)clientFrame*scale;
 }
 }
 update_extra:
 m_extra=(float)TheGameClient->getFrame();
}
