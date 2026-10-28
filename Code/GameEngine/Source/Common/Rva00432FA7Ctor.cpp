// cl: /MD
// ??0AnimationSoundModuleManager@@QAE@XZ, retail 0x00432FA7, 72 bytes.
// Ctor: SubsystemInterface base ctor 0x001B4E63, then the compiler's vtable
// store (0x0083CA30), five pointers/ints at +0xC..+0x1C zeroed, three FLT_MAX
// floats at +0x20/+0x24/+0x28 from pool 0x007BB8E0, then the singleton
// TheAnimationSoundModuleManager is set if zero.
#include <float.h>
#include "../../../Libraries/Include/Lib/Coord3D.h"
#include "../../../Libraries/Source/subsystem/SubsystemInterface.h"

class AnimationSoundModuleManager;
extern class AnimationSoundModuleManager *TheAnimationSoundModuleManager;

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

AnimationSoundModuleManager::AnimationSoundModuleManager()
{
	m_cleanHead = 0;
	m_cleanTail = 0;
	m_dirtyHead = 0;
	m_dirtyTail = 0;
	m_count = 0;
	m_listenerPosition.x = FLT_MAX;
	m_listenerPosition.y = FLT_MAX;
	m_listenerPosition.z = FLT_MAX;
	if (TheAnimationSoundModuleManager == 0)
		TheAnimationSoundModuleManager = this;
}

