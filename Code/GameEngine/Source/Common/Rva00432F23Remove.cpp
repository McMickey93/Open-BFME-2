// flags: region default (reverse/retail_inventory/flag_regions.csv)
// ?remove@AnimationSoundModuleManager@@QAEXPAVRva00432F23Node@@@Z @0x00432F23 90B
// Doubly-linked removal across two head/tail pairs with shared count:
// refreshes any of +0x0C +0x10 +0x14 +0x18 that points at the node, splices
// neighbours, clears the node links and decrements +0x1C. Evidence: single
// caller at 0x004C9DF6, layout with next at +0x14 and prev at +0x18 read off
// retail offsets. The owner is AnimationSoundModuleManager: callers pass
// TheAnimationSoundModuleManager (0x00E032D0) as this, and its ctor 0x00432FA7
// zeroes exactly these +0x0C..+0x1C fields.

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

void AnimationSoundModuleManager::remove(Rva00432F23Node *node)
{
    if (m_cleanHead == node)
        m_cleanHead = node->m_next;
    if (m_cleanTail == node)
        m_cleanTail = node->m_prev;
    if (m_dirtyHead == node)
        m_dirtyHead = node->m_next;
    if (m_dirtyTail == node)
        m_dirtyTail = node->m_prev;
    if (node->m_next)
        node->m_next->m_prev = node->m_prev;
    if (node->m_prev)
        node->m_prev->m_next = node->m_next;
    node->m_next = 0;
    node->m_prev = 0;
    --m_count;
}

void AnimationSoundModuleManager::rva00432F7D(Rva00432F23Node *node)
{
    if (m_cleanHead)
        m_cleanHead->m_prev = node;
    Rva00432F23Node *head = m_cleanHead;
    node->m_prev = 0;
    node->m_next = head;
    m_cleanHead = node;
    if (!m_cleanTail)
        m_cleanTail = node;
    ++m_count;
}

void AnimationSoundModuleManager::rva00432EC0(Rva00432F23Node *node)
{
    if (m_dirtyHead == node)
        return;
    if (m_dirtyTail == node)
        return;
    if (m_cleanHead == node)
        m_cleanHead = node->m_next;
    if (m_cleanTail == node)
        m_cleanTail = node->m_prev;
    if (node->m_next)
        node->m_next->m_prev = node->m_prev;
    if (node->m_prev)
        node->m_prev->m_next = node->m_next;
    if (m_dirtyHead)
        m_dirtyHead->m_prev = node;
    node->m_next = m_dirtyHead;
    m_dirtyHead = node;
    node->m_prev = 0;
    if (!m_dirtyTail)
        m_dirtyTail = node;
}
void AnimationSoundModuleManager::rva00432E5D(Rva00432F23Node *node)
{
    if (m_cleanHead == node)
        return;
    if (m_cleanTail == node)
        return;
    if (m_dirtyHead == node)
        m_dirtyHead = node->m_next;
    if (m_dirtyTail == node)
        m_dirtyTail = node->m_prev;
    if (node->m_next)
        node->m_next->m_prev = node->m_prev;
    if (node->m_prev)
        node->m_prev->m_next = node->m_next;
    if (m_cleanHead)
        m_cleanHead->m_prev = node;
    node->m_next = m_cleanHead;
    m_cleanHead = node;
    node->m_prev = 0;
    if (!m_cleanTail)
        m_cleanTail = node;
}
