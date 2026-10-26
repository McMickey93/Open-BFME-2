// cl: /O1 /MD /EHs /arch:SSE /G7 /ICode/Libraries/Include /ICode/GameEngine/Source/Common
// Codegen shard: WB 01532F70 names UnRegister and asserts its object argument.
// Native 0059771B..005977D3 RET4 removes upgrade records by live Object lookup
// and building records by stored ID. A produced-object hit clears that child ID.
// The record is an accessed prefix for slot0 and flags 2C/34; its original
// type and full extent remain unresolved. Existing vector<void*> erase is
// the established generic pointer-vector provider, not an application type claim.
#include "GameLogicObjectLookupView.h"
#include "ScienceBuilderView.h"
extern GameLogic *TheGameLogic;
class Player;
struct ScienceUnregisterObjectView { char pad00[0x74]; ObjectID id; };
class Rva00506FE9Hit { public: void unRegisterWithBuilder(void *); };
struct ScienceUnregisterRecord { virtual void *destroy(unsigned); char pad04[4]; ObjectID id; char pad0C[0x24-0x0c]; ObjectID producedId; char pad28[4]; bool used; char pad2D[0x34-0x2d]; bool upgrading; };
void AIUpgradeScienceBuilder::UnRegister(Object *object)
{
 void **i=reinterpret_cast<_STL::vector<void *> *>(&m_upgrades)->m_begin;
 while (i!=reinterpret_cast<_STL::vector<void *> *>(&m_upgrades)->m_end) {
  ScienceUnregisterRecord *item=(ScienceUnregisterRecord *)*i;
  if (TheGameLogic->findObjectByID(item->id)==object) {
   if (item->upgrading) ((Rva00506FE9Hit *)item)->unRegisterWithBuilder(m_14);
   ::operator delete(item->destroy(0));
   i=reinterpret_cast<_STL::vector<void *> *>(&m_upgrades)->erase(i);
  } else ++i;
 }
 i=reinterpret_cast<_STL::vector<void *> *>(&m_30)->m_begin;
 while (i!=reinterpret_cast<_STL::vector<void *> *>(&m_30)->m_end) {
  ScienceUnregisterRecord *item=(ScienceUnregisterRecord *)*i;
  if (item->id==((ScienceUnregisterObjectView *)object)->id) {
   if (item->used) ((Rva00506FE9Hit *)item)->unRegisterWithBuilder(m_14);
   ::operator delete(item->destroy(0));
   i=reinterpret_cast<_STL::vector<void *> *>(&m_30)->erase(i);
  } else {
   if (item->producedId==((ScienceUnregisterObjectView *)object)->id) {
    ((Rva00506FE9Hit *)item)->unRegisterWithBuilder(m_14);
    item->producedId=INVALID_OBJECT_ID; item->used=false;
   }
   ++i;
  }
 }
}
