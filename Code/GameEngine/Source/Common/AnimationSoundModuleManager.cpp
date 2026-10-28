// cl: /MD
// ??1AnimationSoundModuleManager@@UAE@XZ @0x00432FEF 54B: virtual dtor with two-list cleanup.
// Evidence: vtable 0x0083CA30 slot0 ??_G 0x0043312E; ctor 0x00432FA7 same vtable; tail-jmp to rowed ??1SubsystemInterface@@UAE@XZ 0x001B4E74; callers 0x00433131.

// Retail base vtable BD77A0 and destructor 1B4E74 prove the canonical 12-byte subsystem base.
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

AnimationSoundModuleManager::~AnimationSoundModuleManager()
{
	for (int i = 0; i < 2; i++) {
		Rva00432F23Node *head;
		if (i != 0)
			head = m_cleanHead;
		else
			head = m_dirtyHead;
		while (head) {
			Rva00432F23Node *next = head->m_next;
			head->m_next = 0;
			head->m_prev = 0;
			head = next;
		}
	}
}
