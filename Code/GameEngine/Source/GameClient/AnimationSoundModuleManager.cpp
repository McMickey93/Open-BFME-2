// cl: /O1 /G7 /arch:SSE /MD /EHsc
// Native433025..4330EE RET0; WB12BDFC0 names the source file, with
// no original method name. Keep the method address-derived.
// BF1@575ba2b game/GameEngine/Source/GameClient/Drawable/Behavior/
// AnimationSoundClientBehaviorGlobal_unregister.cpp supplies the intrusive
// two-list registry semantics; target offsets and dispatch come from retail.
// This receiver view has ends0C/10/14/18 and cached position20; it is not
// asserted to share the BF1 registry ABI. The node's next/previous14/18,
// audio virtual slot+0x120 and threshold setting are independently measured in native.
// Coord3D is canonical. Inline copy/subtract/length are ordinary vector
// algebra, with z/y/x evaluation order matching retail's scalar SSE.
#include "../../../Libraries/Include/Lib/Coord3D.h"
#include "../../../Libraries/Source/subsystem/SubsystemInterface.h"

// The list node is the AnimationSoundClientBehavior the manager registers; its
// next/previous links sit at +0x14/+0x18 and its callers cast to this view.
class Rva00432F23Node
{
public:
	char m_pad[0x14];
	Rva00432F23Node *m_next;	// +0x14
	Rva00432F23Node *m_prev;	// +0x18
};

// Retail vtable 0x0083CA30 (slot 0 ??_G 0x0043312E); ctor 0x00432FA7 zeroes
// +0x0C..+0x1C and sets the listener position to FLT_MAX.
class AnimationSoundModuleManager : public SubsystemInterface
{
public:
	AnimationSoundModuleManager();
	virtual ~AnimationSoundModuleManager();
	void update();
	void remove(Rva00432F23Node *node);
	void rva00432F7D(Rva00432F23Node *node);
	void rva00432EC0(Rva00432F23Node *node);
	void rva00432E5D(Rva00432F23Node *node);

private:
	Rva00432F23Node *m_cleanHead;	// +0x0C
	Rva00432F23Node *m_cleanTail;	// +0x10
	Rva00432F23Node *m_dirtyHead;	// +0x14
	Rva00432F23Node *m_dirtyTail;	// +0x18
	int m_count;			// +0x1C
	Coord3D m_listenerPosition;	// +0x20
};

class AnimationSoundClientBehavior {public:
 void updateAnimationSounds();
};
struct AnimationSoundClientBehaviorGlobalSetting {float m_minMicrophoneDistanceToDirty;};
// Native complete4B setting atDC898C starts at50.0f; the manager reads
// that one scalar for the squared-distance threshold.
AnimationSoundClientBehaviorGlobalSetting TheAnimationSoundClientBehaviorGlobalSetting = { 50.0f };
class AudioManager;extern AudioManager *TheAudio;
template<int N>class AnimationListenerSlots:public AnimationListenerSlots<N-1>{public:virtual void gap(char(*)[N]);};
template<>class AnimationListenerSlots<1>{public:virtual void gap(char(*)[1]);};
class AnimationListenerCalls:public AnimationListenerSlots<72>{public:virtual const Coord3D*listener();};
static __forceinline void animationSubtract(Coord3D &lhs,const Coord3D &rhs){lhs.x-=rhs.x;lhs.y-=rhs.y;lhs.z-=rhs.z;}
static __forceinline float animationSoundLengthSquared(const Coord3D&pos){return pos.z*pos.z+pos.y*pos.y+pos.x*pos.x;}
void AnimationSoundModuleManager::update(){
 const Coord3D *listener=((AnimationListenerCalls*)TheAudio)->listener();
 Coord3D delta;delta.x=listener->x;delta.y=listener->y;delta.z=listener->z;
 animationSubtract(delta,m_listenerPosition);
 if(animationSoundLengthSquared(delta)>TheAnimationSoundClientBehaviorGlobalSetting.m_minMicrophoneDistanceToDirty*TheAnimationSoundClientBehaviorGlobalSetting.m_minMicrophoneDistanceToDirty && m_dirtyTail){
  if(m_cleanHead){m_dirtyTail->m_next=m_cleanHead;m_cleanHead->m_prev=m_dirtyTail;}
  m_cleanHead=m_dirtyHead;
  if(!m_cleanTail)m_cleanTail=m_dirtyTail;
  m_dirtyHead=0;m_dirtyTail=0;
 }
 if(!m_dirtyHead)m_listenerPosition=*((AnimationListenerCalls*)TheAudio)->listener();
 for(Rva00432F23Node *node=m_cleanHead;node;){
  Rva00432F23Node *next=node->m_next;
  ((AnimationSoundClientBehavior*)node)->updateAnimationSounds();node=next;
 }
}
