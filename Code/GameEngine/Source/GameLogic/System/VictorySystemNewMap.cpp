// cl: /DNDEBUG /DBFME_SB_CLEAR_DECL /MD /GX /D_STLP_USE_STATIC_LIB /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfme2_ascii /Ireference/shims/moduledata /Ireference/shims/bfmealloc /ICode/Libraries/Include
// stlport
// WB1075B20 names VictorySystem::newMap and the native boundary is404DE5..405094.
// Reference VictorySystem reset/CellGrid construction provide subsystem leads;
// this body is reconstructed from target WB/native evidence, not a byte lift.
// Named TheTerrainLogic and ThePlayerList providers replace the old global wall.
// The nonthrowing parameter finder404D70 walks records and calls the rowed
// read-only string comparator6A00. Native EH also excludes the Default temporary.
// The radius is sqrt(2) times half the cell span; retail evaluates the float
// sqrt overload (the C++ <math.h> spelling, (float)sqrt((double)x)) and
// schedules the second argument-cleanup POP after FMUL 0.5 only with it.
// Views and flags are those of the approved TU, VictorySystem.cpp:
// +0x14 player count, +0x20 radius, +0x24 bonus.
typedef bool Bool;
#include "subsystem_interface.h"
#include <vector>
#define BFME_SNAPSHOT_NAME_SLOT
#define BFME_SNAPSHOT_CAPITALIZED_SLOTS
#include "Common/Snapshot.h"
#include "ascii_string.h"
#include "Lib/Coord3D.h"
#include "Lib/Region3D.h"
extern "C" double __cdecl fabs(double);
extern "C" double __cdecl sqrt(double);
inline float __cdecl sqrt(float _X) {return ((float)sqrt((double)_X)); }
extern "C" __declspec(dllimport) double __cdecl ceil(double);

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

struct BfmeStringRecord00404BF3
{
	AsciiString text; // +0x00
	float f0; // +0x04
	float f1; // +0x08
	float f2; // +0x0C
	float f3; // +0x10
	float f4; // +0x14
	BfmeStringRecord00404BF3(const AsciiString &s);
};

class Rva00404D70
{
public:
	int rva00404D70(const AsciiString &s) throw();
private:
	char m_pad[0x120];
	_STL::vector<BfmeStringRecord00404BF3> m_vec;
};

class TerrainLogic;extern TerrainLogic *TheTerrainLogic;
class NewMapTerrainView {public:
 virtual void slot00();virtual void slot01();virtual void slot02();virtual void slot03();
 virtual void slot04();virtual void slot05();virtual void slot06();virtual void slot07();virtual void slot08();
 virtual void getExtent(Region3D *);
};
class Player {public:char unknown00[0x54];int index;AsciiString faction;};
class PlayerList {public:Player *getNthPlayer(int);char unknown00[0x14];unsigned count;};
extern PlayerList *ThePlayerList;
class Rva00404781;
class CellGrid
{
public:
	int rva0056C16D();
	CellGrid(int,int,float,float);
	unsigned width; // +0x00
	unsigned height; // +0x04
	unsigned count; // +0x08
	float size; // +0x0C
	float offset; // +0x10
	Rva00404781 *cells; // +0x14
	unsigned int *values; // +0x18
};
void VictorySystem::newMap()
{
 rva00404B03();
 if(cellSize10>0.0f){
  Region3D extent;
  cellSize10=100.0f>cellSize10?100.0f:cellSize10;
  reinterpret_cast<NewMapTerrainView *>(TheTerrainLogic)->getExtent(&extent);
  if(extent.width()>0.0f && extent.height()>0.0f){
   cellSize10=cellSize10>(extent.height()>extent.width()?extent.width():extent.height())?
    (extent.height()>extent.width()?extent.width():extent.height()):cellSize10;
   int width=(int)ceil(fabs(extent.width())/cellSize10);
   int height=(int)ceil(fabs(extent.height())/cellSize10);
   grids12c[0]=new CellGrid(width,height,cellSize10,0.0f);
   ++width;++height;
   grids12c[1]=new CellGrid(width,height,cellSize10,-(cellSize10/2.0f));
  }
  field24=field24>1.0f?field24:1.0f;
  field20=sqrt(2.0f)*(cellSize10*field24/2.0f);
  field14=ThePlayerList->count;
  for(unsigned i=0;i<field14;++i){
   bool neutral=false;
   Player *player=ThePlayerList->getNthPlayer(i);
   AsciiString faction=player->faction;
   int index=reinterpret_cast<Rva00404D70 *>(this)->rva00404D70(faction);
   if(faction.isEmpty() || faction.compareNoCase("Observer")==0 || faction.compareNoCase("Civilian")==0)
    neutral=true;
   if(index==0x7fffffff)
    index=reinterpret_cast<Rva00404D70 *>(this)->rva00404D70(AsciiString("Default"));
   if(index!=0x7fffffff)
    playerParameterIndex28[i]=index | (neutral?0x80000000:0);
   else playerParameterIndex28[i]=0;
  }
  initialized134=true;
 }
}
