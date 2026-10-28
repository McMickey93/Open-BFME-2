// cl: /EHsc /MD /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /Ireference/shims/sweep
// stlport
// ?onApproachReached@DockUpdate@@UAEXPAVObject@@@Z @0x00589AB1 78B.
// Zero Hour DockUpdate::onApproachReached: finds the docker's ID (Object
// +0x74) among the approach-position owners and sets that index's bit in the
// approach-reached vector<bool>. DockUpdateInterface slot 8 of the docks'
// +0x20 interface vtables 0x00C51AC0 0x00C51C30 0x00C53740 (0x00C51D18 holds
// MonsterDockUpdate's override 0x004A159E), so `this` is the +0x20 subobject: owners at DockUpdate +0x60 (interface +0x40),
// reached bits at +0x6C (interface +0x4C). MonsterDockUpdate::onApproachReached
// 0x004A159E calls it first, as Zero Hour's overrides call the base.
// Evidence: offsets +0x40 +0x44 size sar2 plus vector bool call rowed 0x0006BE1F in DockUpdateCtor plus caller 0x004A159E passing object plus neighbour DockUpdateRemove layout.
// Match the destination TU's existing secondary-interface view.
// The accessed owners and reached-bit vector stay at interface +0x40/+0x4C.
#include <stl/_bvector.h>
typedef _STL::vector<bool, _STL::allocator<bool> > BoolVector;

class Object
{
public:
	void rva0028CFB2(const int *clear, const int *set);
	int m_pad74[0x74 / 4];	// vptr at +0x0, id at +0x74
	int m_id;	// +0x74
};

class ObjectIDVector
{
public:
	int *m_start;
	int *m_finish;
	int *m_endOfStorage;

	unsigned int size() const
	{
		return (unsigned int)(m_finish - m_start);
	}

	int &operator[](unsigned int index)
	{
		return m_start[index];
	}

	const int &operator[](unsigned int index) const
	{
		return m_start[index];
	}
};

class DockUpdate
{
public:
	virtual bool isClearToApproach(const Object *docker) const;
	virtual void dockSlot01();
	virtual void dockSlot02();
	virtual bool isClearToEnter(const Object *docker) const;
	virtual void dockSlot04();
	virtual void dockSlot05();
	virtual void dockSlot06();
	virtual void dockSlot07();
	virtual void onApproachReached(Object *docker);
	virtual void onEnterReached(Object *docker);
	virtual void onDockReached(Object *docker);
	virtual void onExitReached(Object *docker);
	virtual void dockSlot12();
	virtual void cancelDock(Object *docker);
	virtual bool isDockOpen();
	virtual void dockSlot15();
	virtual void dockSlot16();
	virtual void setDockCrippled(bool setting);
	void rva00589AFF(int index);

private:
	unsigned char m_pre04[0x24];	// interface vptr at +0x0, count at +0x28
	int m_numberApproachPositions;	// +0x28
	unsigned char m_pre2C[0x14];	// +0x2C..+0x3F
	ObjectIDVector m_approachPositionOwners;	// +0x40
	BoolVector m_approachPositionReached;	// +0x4C..+0x5F
	int m_activeDocker;	// +0x60
	bool m_dockerInside;	// +0x64
	bool m_dockCrippled;	// +0x65
};

void DockUpdate::onApproachReached(Object *docker)
{
	int target = docker->m_id;
	for (unsigned int i = 0; i < m_approachPositionOwners.size(); ++i)
	{
		if (m_approachPositionOwners[i] == target)
		{
			m_approachPositionReached[i] = true;
			break;
		}
	}
}
