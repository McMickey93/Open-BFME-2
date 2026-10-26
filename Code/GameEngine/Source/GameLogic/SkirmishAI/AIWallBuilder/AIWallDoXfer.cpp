// cl: /O1 /arch:SSE /G7 /DNDEBUG /MD /EHsc
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
class Rva005970ED {
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
    unsigned char unknown04[0x40];
};
struct WallOrderRange {
    Rva00596CDF **start, **finish, **capacity;
    unsigned int size() const { return finish-start; }
    Rva00596CDF *operator[](unsigned int i) const { return start[i]; }
    Rva00596CDF **begin() const {return start;}
    Rva00596CDF **end() const {return finish;}
};
enum NameKeyType { NAMEKEY_INVALID=0 };
Xfer &__cdecl Rva00149101XferNameKey(Xfer &,NameKeyType &);
void *operator new(unsigned int);
// Reuse the owned serial-counter provider in Rva004EB583Ctor.cpp.
extern int g_00E044A0;
// WB 0x0137E7C0 names AIWall::DoXfer in AIWall.cpp (assert lines 611..633).
// Retail 0x004EB092..0x004EB2CA proves the owner index, order range,
// selected key, upgrade allocation and version-2 name-key transfer.
// This view agrees with buildGate's existing owner +18 and plan +14 fields.
// The +08/+1C/+28 ranges are the three-pointer storage also seen in the owned ctor.
class AIWall {
public:
    virtual ~AIWall();
    void DoXfer(Xfer *, bool detachOwner);
private:
    Rva00596CDF *selected04;
    WallOrderRange orders08;
    Rva005970ED *upgrade14;
    Player *owner18;
    WallOrderRange orders1c, orders28;
    int value34, value38, value3c, value40;
    unsigned int id44;
    NameKeyType key48;
};
void AIWall::DoXfer(Xfer *xfer,bool detachOwner) {
    WallVersion version(1,2);
    xfer->operator==(reinterpret_cast<Xfer::Version &>(version));
    int ownerIndex=owner18?reinterpret_cast<const WallPlayerIndexView *>(owner18)->getIndex():-1;
    xfer->operator==(ownerIndex);
    if(xfer->IsLoading() && ownerIndex!=-1)
        owner18=detachOwner?0:ThePlayerList->getNthPlayer(ownerIndex);
    {
    unsigned int count=orders08.size();
    xfer->operator==(count);
    for(unsigned int i=0;i<count;++i) {
        if(i<orders08.size())
            orders08[i]->Rva00596CEA(xfer,owner18);
        else {
            Rva00596CDF unused(0);
            unused.Rva00596CDF::Rva00596CEA(xfer,0);
        }
    }
    }
    unsigned int selectedID=selected04?selected04->getKey():-1;
    xfer->operator==(selectedID);
    if(xfer->IsLoading() && selectedID!=-1) {
        Rva00596CDF **end=orders08.end();
        for(Rva00596CDF **it=orders08.begin();it!=end && selected04==0;++it)
            if((*it)->getKey()==selectedID) selected04=*it;
    }
    bool hasUpgrade=upgrade14!=0;
    xfer->operator==(hasUpgrade);
    if(xfer->IsStoring() && hasUpgrade)
        upgrade14->xfer(xfer,owner18);
    else if(xfer->IsLoading() && hasUpgrade) {
        upgrade14=new Rva005970ED;
        upgrade14->xfer(xfer,owner18);
    }
    unsigned int count2=orders1c.size();
    xfer->operator==(count2);
    int value=value34;
    xfer->operator==(value);
    value34=value;
    xfer->operator==(value38);
    value=value3c;
    xfer->operator==(value);
    value3c=value;
    xfer->operator==(value40);
    xfer->operator==(id44);
    xfer->operator==(*(reinterpret_cast<unsigned int *>(&g_00E044A0)));
    if(version.current>=2) Rva00149101XferNameKey(*xfer,key48);
}
