#pragma once

#include "../../../../Common/GameLogicObjectLookupView.h"
#include "ScienceBuilderVectorView.h"

// Native 0x005977D3 prunes ObjectIDs at +0x18/+0x1C and calls the primary
// interface's slot zero. The builder calls this body on its primary receiver
// (0x00597FC5), without constructing or sizing this accessed-prefix view.
class Rva005977D3
{
public:
	virtual void slot0(Object *obj, int x);
	void rva005977D3();
private:
	char m_pad04[0x18 - 4];
	_STL::vector<ObjectID, _STL::allocator<ObjectID> > m_ids;
};

// Native 0x0059781D uses the same primary receiver: owner at +0x14,
// pointer-vector ranges at +0x24/+0x28 and +0x30/+0x34. The first vector
// reserves the measured +0x18..+0x23 prefix; this body never accesses it.
class Rva0059781D
{
public:
	void rva0059781D();
private:
	char m_pad00[0x14];
	void *m_14;
	_STL::vector<void *, _STL::allocator<void *> > m_vec18;
	_STL::vector<void *, _STL::allocator<void *> > m_vec24;
	_STL::vector<void *, _STL::allocator<void *> > m_vec30;
};
