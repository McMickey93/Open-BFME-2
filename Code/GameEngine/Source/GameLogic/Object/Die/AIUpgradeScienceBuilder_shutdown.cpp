// cl: /GX-
// ?shutdown@AIUpgradeScienceBuilder@@UAEXXZ @0x00597B32 162B: vslot2 of 0x00870C18 clearing two voidptr vectors with slot0+delete then hero remove via TheSkirmishAIManager and ScienceType clear; callers 0x00597BFE
#include "../../SkirmishAI/AIUpgrade/AIUpgradeScienceBuilder/ScienceBuilderView.h"

class Player;
class CreateAHeroData;

class Rva004DFB55
{
public:
	void rva004DFB55(CreateAHeroData *p);
};

extern Rva002A8F24 *TheSkirmishAIManager;

class Elem
{
public:
	virtual void *slot0(int x);
};

void __cdecl operator delete(void *p);

void AIUpgradeScienceBuilder::shutdown()
{
	void **it = reinterpret_cast<_STL::vector<void *> *>(&m_upgrades)->m_begin;
	void **finish = reinterpret_cast<_STL::vector<void *> *>(&m_upgrades)->m_end;
	while (it != finish)
	{
		void *p = *it;
		void *q = 0;
		if (p != 0)
			q = ((Elem *)p)->slot0(0);
		::operator delete(q);
		++it;
	}
	{
		_STL::vector<void *, _STL::allocator<void *> > &r1 =
			*reinterpret_cast<_STL::vector<void *> *>(&m_upgrades);
		r1.erase(r1.m_begin, r1.m_end);
	}

	it = reinterpret_cast<_STL::vector<void *> *>(&m_30)->m_begin;
	finish = reinterpret_cast<_STL::vector<void *> *>(&m_30)->m_end;
	while (it != finish)
	{
		void *p = *it;
		void *q = 0;
		if (p != 0)
			q = ((Elem *)p)->slot0(0);
		::operator delete(q);
		++it;
	}
	{
		_STL::vector<void *, _STL::allocator<void *> > &r2 =
			*reinterpret_cast<_STL::vector<void *> *>(&m_30);
		r2.erase(r2.m_begin, r2.m_end);
	}

	Player *pl = m_14;
	void *store = TheSkirmishAIManager->rva002A8F24(pl);
	((Rva004DFB55 *)store)->rva004DFB55((CreateAHeroData *)this);
	_STL::vector<ScienceType, _STL::allocator<ScienceType> > *vs = &m_objects;
	vs->erase(vs->m_begin, vs->m_end);
}
