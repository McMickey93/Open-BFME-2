// cl: /O1 /arch:SSE /G7 /DNDEBUG /MD /EHsc
// stlport
class AsciiString;
// Retail Version stores minimum/current bytes and has an inline constructor;
// that constructor form also reproduces the independent stack homes in DoXfer.
struct WallVersion
{
    WallVersion(unsigned char min, unsigned char cur) : minimum(min), current(cur) {}
    unsigned char minimum, current;
};
class Snapshot;
class AsciiString;
class UnicodeString;
class PooledString;
struct Coord3DBase;
struct ICoord3D;
struct Region3D;
class IRegion3D;
class Coord2D;
struct ICoord2D;
struct Region2D;
struct IRegion2D;
class RealRange;
struct RGBColor;
class RGBAColorReal;
class RGBAColorInt;
struct XferUnknown11;
#include "../../../../Include/Common/BfmeXfer.h"

class Player;
struct WallPlayerIndexView { unsigned char unknown[0x54]; int index; int getIndex() const {return index;} };
class PlayerList { public: Player *getNthPlayer(int); };
extern PlayerList *ThePlayerList;
class Rva00596CDF {
public:
    Rva00596CDF(unsigned int);
    virtual ~Rva00596CDF();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();

    virtual void Rva00596CEA(Xfer *, void *);
    unsigned char unknown04[0x4c];
    unsigned int key50;
    int value54;
    bool value58;
    unsigned int getKey() const {return key50;}
};
class Rva005970ED
{
public:
	Rva005970ED();
	virtual ~Rva005970ED();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual void slot10();
	virtual void slot11();
	virtual void xfer(Xfer *, Player *);
	float delay04; // +0x04
	char m_pad08[0x3C];
};
enum NameKeyType { NAMEKEY_INVALID=0 };
Xfer &__cdecl Rva00149101XferNameKey(Xfer &,NameKeyType &);
#include <new>
#include <vector>
// Reuse the owned serial-counter provider in Rva004EB583Ctor.cpp.
extern int g_00E044A0;
// WB 0x0137E7C0 names AIWall::DoXfer in AIWall.cpp (assert lines 611..633).
// Retail 0x004EB092..0x004EB2CA proves the owner index, order range,
// selected key, upgrade allocation and version-2 name-key transfer.
// AIWall is the AIWall.cpp unit's view (owner +18, plan +14, order vectors
// +08/+1C/+28, the three-pointer storage also seen in the owned ctor). Its
// order elements are the Rva00596CDF objects this transfer walks, and its
// plan is the Rva005970ED object it allocates; the casts below cross views.
struct WallPositionValue;
class WallPositionOrderView;
class Rva004EB902Plan;
class PolygonTrigger;
struct BfmeE8;
class Object;
class AIWall
{
public:
	virtual ~AIWall();
	float rva004EADBA(const Coord2D *pt);	// 0x004EADBA: smallest squared distance to the wall polyline
	WallPositionValue calcGatePosition();	// 0x004EAFBD: WB names calcGatePosition; hidden value result
	void buildGate();
	void updateState(bool left);
	void update();
	void activate(void *owner, float delay, const void *orderName);
	bool rva004EB7CC(void *owner);
    void rva004EBB58();
    static void __cdecl informInstanceOnTriggerEntered(Object *, void *, bool);
	bool init();
	void DoXfer(Xfer *, bool detachOwner);
private:
	WallPositionOrderView *selected04;
	_STL::vector<WallPositionOrderView *> orders08;
	Rva004EB902Plan *m_14;	// +0x14
	Player *m_18;		// +0x18
    _STL::vector<PolygonTrigger *> triggers1c;
    _STL::vector<BfmeE8> triggerCounts28;
	int state34, index38, state3c, index40;
	unsigned int id44;
	NameKeyType key48;
};
void AIWall::DoXfer(Xfer *xfer,bool detachOwner) {
    WallVersion version(1,2);
    xfer->operator==(reinterpret_cast<Xfer::Version &>(version));
    int ownerIndex=m_18?reinterpret_cast<const WallPlayerIndexView *>(m_18)->getIndex():-1;
    xfer->operator==(ownerIndex);
    if(xfer->IsLoading() && ownerIndex!=-1)
        m_18=detachOwner?0:ThePlayerList->getNthPlayer(ownerIndex);
    {
    unsigned int count=orders08.size();
    xfer->operator==(count);
    for(unsigned int i=0;i<count;++i) {
        if(i<orders08.size())
            reinterpret_cast<Rva00596CDF *>(orders08[i])->Rva00596CEA(xfer,m_18);
        else {
            Rva00596CDF unused(0);
            unused.Rva00596CDF::Rva00596CEA(xfer,0);
        }
    }
    }
    unsigned int selectedID=selected04?reinterpret_cast<Rva00596CDF *>(selected04)->getKey():-1;
    xfer->operator==(selectedID);
    if(xfer->IsLoading() && selectedID!=-1) {
        Rva00596CDF **end=reinterpret_cast<Rva00596CDF **>(orders08.end());
        for(Rva00596CDF **it=reinterpret_cast<Rva00596CDF **>(orders08.begin());it!=end && selected04==0;++it)
            if((*it)->getKey()==selectedID) selected04=reinterpret_cast<WallPositionOrderView *>(*it);
    }
    bool hasUpgrade=m_14!=0;
    xfer->operator==(hasUpgrade);
    if(xfer->IsStoring() && hasUpgrade)
        reinterpret_cast<Rva005970ED *>(m_14)->xfer(xfer,m_18);
    else if(xfer->IsLoading() && hasUpgrade) {
        m_14=reinterpret_cast<Rva004EB902Plan *>(new Rva005970ED);
        reinterpret_cast<Rva005970ED *>(m_14)->xfer(xfer,m_18);
    }
    unsigned int count2=triggers1c.size();
    xfer->operator==(count2);
    int value=state34;
    xfer->operator==(value);
    state34=value;
    xfer->operator==(index38);
    value=state3c;
    xfer->operator==(value);
    state3c=value;
    xfer->operator==(index40);
    xfer->operator==(id44);
    xfer->operator==(*(reinterpret_cast<unsigned int *>(&g_00E044A0)));
    if(version.current>=2) Rva00149101XferNameKey(*xfer,key48);
}
