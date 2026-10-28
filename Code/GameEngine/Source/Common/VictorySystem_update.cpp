// cl: /DNDEBUG /MD /GX /D_STLP_USE_STATIC_LIB /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfme2_ascii /Ireference/shims/moduledata /Ireference/shims/bfmealloc /ICode/Libraries/Include
// stlport
//
// ?update@VictorySystem@@UAEXXZ @0x00405315 34B.
// VictorySystem::update: SubsystemInterface slot 10 of VictorySystem's table
// 0x008388D4 (installed by the rowed VictorySystem ctor 0x004054E1).
// Flag-gated chain: if the +0x134 byte is set run the no-arg members at
// 0x00405094 and 0x00405258 then tail to 0x00404A29, else return.
// VictorySystem is the view of its approved TU, VictorySystem.cpp.
typedef bool Bool;
#include "subsystem_interface.h"
#include <vector>
#define BFME_SNAPSHOT_NAME_SLOT
#define BFME_SNAPSHOT_CAPITALIZED_SLOTS
#include "Common/Snapshot.h"
#include "ascii_string.h"

class Xfer;

class Rva00404781 {public:__declspec(dllimport) __forceinline Rva00404781(){rva0040475C();}__declspec(nothrow) void rva0040475C();void AddDeath(float,int,int);int rva00404CF5(bool);float first[20],second[20];unsigned flags0,flags1;};

struct Rva0040538FElement
{
public:
	char bytes[24]; // +0x00
};

typedef _STL::_Vector_base<Rva0040538FElement,_STL::allocator<Rva0040538FElement> > VictoryParameterBase;

struct Rva00405350:public VictoryParameterBase {__forceinline Rva00405350():VictoryParameterBase(_STL::allocator<Rva0040538FElement>()){}~Rva00405350();Rva0040538FElement*first(){return _M_start;}Rva0040538FElement*last(){return _M_finish;}};

class CellGrid;

class VictorySystem:public SubsystemInterface,public Snapshot {
public:VictorySystem();void rva00404B03();virtual ~VictorySystem();virtual void init();virtual void reset();virtual void update();virtual void LoadPostProcess(){}virtual const char*GetSnapshotName()const{return "VictorySystem";}virtual void DoXfer(Xfer*);virtual void newMap();
 float cellSize10;unsigned field14;float firstScale18,secondScale1c,field20,field24;
 int playerParameterIndex28[20];Rva00404781 root78;Rva00405350 parameters120;
 CellGrid*grids12c[2];bool initialized134;unsigned activeGrid138,currentPlayer13c;
};

class VictorySystemGridUpdateView
{
public:
	void rva00405094();
	void rva00405258();
};

class Rva004053C2
{
public:
	void rva00404A29();
};

void VictorySystem::update()
{
	if (initialized134)
	{
		((VictorySystemGridUpdateView *)this)->rva00405094();
		((VictorySystemGridUpdateView *)this)->rva00405258();
		((Rva004053C2 *)this)->rva00404A29();
	}
}
