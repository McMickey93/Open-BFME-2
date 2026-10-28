// ?init@AIWall@@QAE_NXZ
// ?init@AIWall@@QAE_NXZ
// Named WB137B990/405 and complete native4EBEB7..4EBF4B establish AIWall::init.
// Actual STLport vector operations eliminate the old bank's invented volatile
// field qualifiers. This complete trial emits146B against native148B: frame,
// sort argument construction and loop/state logic agree, but post-sort median
// load order/register allocation still differ. Four source shapes were tested;
// retaining an explicit median gives143B and incorrectly elides the reload.
// Helper4EBB58's full673B native body was read and proves ECX/RET0. Its original
// name is unknown (WB's Coord2D::Set label is an inline-source attribution).
// No helper pin was added while the caller remains a byte mismatch.
// cl: /O1 /arch:SSE /G7 /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// W7-MP5 r3: T1 search (199 trials/14 generators) improved nd24->20, 146->147B
// with gen_barrier at offset 64 (a _ReadWriteBarrier before the post-sort median
// read). Residue: validation-loop iterator/end register roles are swapped
// (retail iterator ECX/end EDI vs ours EDI/EDX) and the median load base
// register; end-in-for-init, valid-first condition order and named-key shapes
// were inert or worse.
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
#include <vector>
struct Rva004EBE74Item 
{
 unsigned char unknown00[0x50];
 unsigned m_50;
 unsigned getKey() const 
 {
  return m_50;
  
 }
 
};
struct Rva004EBE74Cmp 
{
 bool operator()(const Rva004EBE74Item *a, const Rva004EBE74Item *b) const 
 {
  return a->m_50 < b->m_50;
  
 }
 
};
namespace _STL 
{
 template<class Iterator, class Predicate>
 void sort(Iterator first, Iterator last, Predicate predicate);
 
}
// AIWall is the AIWall.cpp unit's view. Its order elements are the
// Rva004EBE74Item records the rowed sort family is instantiated over; the
// casts below cross from the unit's element view to that one.
class Coord2D;
struct WallPositionValue;
class Object;
class Xfer;
class WallPositionOrderView;
class Rva004EB902Plan;
class Player;
class PolygonTrigger;
struct BfmeE8;
enum NameKeyType { NAMEKEY_INVALID=0 };
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
bool AIWall::init()

{
 if (orders08.size() > 1) 
 {
  _STL::sort(reinterpret_cast<Rva004EBE74Item **>(orders08.begin()), reinterpret_cast<Rva004EBE74Item **>(orders08.end()), Rva004EBE74Cmp());
  unsigned count = orders08.size();
  Rva004EBE74Item **beginp = reinterpret_cast<Rva004EBE74Item **>(&orders08[0]);
  Rva004EBE74Item **endp = reinterpret_cast<Rva004EBE74Item **>(orders08.end());
  *(volatile Rva004EBE74Item **)(beginp + (count >> 1)) = *(beginp + (count >> 1));
  Rva004EBE74Item ** volatile *medianSlot = (Rva004EBE74Item ** volatile *)&orders08;
  Rva004EBE74Item **medianBegin = *medianSlot;
  selected04 = reinterpret_cast<WallPositionOrderView *>(*(medianBegin + (count >> 1)));
  beginp = reinterpret_cast<Rva004EBE74Item **>(&orders08[0]);
  count = orders08.size();
  bool valid = true;
  unsigned index = (unsigned)-1;
  for (Rva004EBE74Item **p = beginp; p != endp && valid; ++p) 
  {
   if ((*p)->getKey() != ++index)
   valid = false;
   
  }
  if (valid) 
  {
   index38 = reinterpret_cast<Rva004EBE74Item *>(selected04)->getKey();
   index40 = reinterpret_cast<Rva004EBE74Item *>(selected04)->getKey();
   rva004EBB58();
   return true;
   
  }
  
 }
 return false;
 
}
