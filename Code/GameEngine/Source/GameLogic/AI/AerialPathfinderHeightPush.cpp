// cl: /O1 /arch:SSE /G7 /MD /EHs
// Native 00375ED7..0037609C/453B RET12. WB F2BE60 corroborates five
// height probes: center, then four corners, and final separation push.
// The original method name is unknown. Target proves AI+258, motion+1F0,
// clearance+48 and Object bounding radius+BC. Probe vector reuse and the
// initial comparison against zero follow the debug body and native SSE.
// Keep the separation provider external: visible body knowledge changes
// MSVC's receiver allocation. The final object read preserves its native
// parameter home; local volatile qualification asserts no original type.
#include "../../../../Libraries/Include/Lib/Coord3D.h"
struct AerialMotionInfo { char prefix[0x48]; float height; };
class ThingTemplate {public: char prefix[0x108];unsigned kinds[7];};
class AerialPartner {public:char prefix[0x4C0];unsigned id;};
class AerialAI {public:
#define V(n) virtual void slot##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92) V(93) V(94) V(95) V(96)
#undef V
 virtual AerialPartner* getPartner();
 char pad04[0x1F0-4];AerialMotionInfo* motion;
};
class GeometryInfo
{
public:
	char prefix[0x14]; // +0x00
	float radius; // +0x14
};
class Object {public:
 void* vtable;ThingTemplate* thing;char pad8[0x38-8];Coord3D position;float angle;
 char pad48[0x74-0x48];unsigned id;char pad78[0xA8-0x78];GeometryInfo geometry;
 char padC0[0x258-0xC0];AerialAI* ai;
};
class Rva00375A73Context;
struct Rva00375A73Coord;
class Rva00312C95;
class AerialPathfinder
{
public:
	bool rva00375C28(Object*,const Coord3D*,float*,Coord3D*);
	bool rva00375A73(Rva00375A73Context*,float,Rva00375A73Coord*);
	bool rva00375DFF(Object*,Rva00375A73Context*,float,float);
	float rva00375B7A(float,float);
	int rva00375ED7(Object*,const Coord3D*,Coord3D*);
	bool computeAerialPath(void *, const Coord3D *, Rva00312C95 *, const unsigned char *, const unsigned char *, bool);
	char m_pad00[0x258];
private:
	void *m_258; // +0x258 +0x258
};
int AerialPathfinder::rva00375ED7(Object*obj,const Coord3D*pos,Coord3D*push)
{
 AerialAI*ai=obj->ai;
 if(!ai)return 2;
 push->x=0;push->y=0;push->z=0;
 float height=ai->motion->height;
 float radius=obj->geometry.radius;
 Coord3D sample={0,0,0};
 float worst=0;
 sample.z=pos->z-height*0.5f;
 sample.x=pos->x;sample.y=pos->y;
 float ground=rva00375B7A(sample.x,sample.y);
 if(ground-sample.z>0.0f)worst=ground-sample.z;
 sample.z=pos->z-height*0.5f*0.777f;
 sample.x=pos->x-radius;sample.y=pos->y-radius;
 ground=rva00375B7A(sample.x,sample.y);
 if(ground-sample.z>worst)worst=ground-sample.z;
 sample.y=pos->y+radius;
 ground=rva00375B7A(sample.x,sample.y);
 if(ground-sample.z>worst)worst=ground-sample.z;
 sample.x=pos->x+radius;
 ground=rva00375B7A(sample.x,sample.y);
 if(ground-sample.z>worst)worst=ground-sample.z;
 sample.y=pos->y-radius;
 ground=rva00375B7A(sample.x,sample.y);
 if(ground-sample.z>worst)worst=ground-sample.z;
 push->z+=worst;
 rva00375C28(*(Object*volatile*)&obj,pos,&worst,push);
 return worst>0.0f ? 1:0;
}
