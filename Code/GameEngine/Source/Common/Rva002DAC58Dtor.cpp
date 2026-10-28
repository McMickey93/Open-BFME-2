// cl: /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfme2_ascii /MD /EHsc
// ??1TerrainRoadCollection@@UAE@XZ @0x002DAC58 128B: dtor with two node lists plus SubsystemInterface.
// Evidence: vptr 0x00C03D64 store, lists at +0xC/+0x10 with ::delete (virtual slot0 with flag 0, then global delete) row 0x2FD60, base dtor row 0x1B4E74, deleting dtor caller 0x002DACD8 28B, neighbour Rva002DB311Dtor /O1 /MD /EHsc.

// BFME2 SubsystemInterface (12-byte base, 14-slot vtable 0x00BD77A0; ctor
// 0x001B4E63 / dtor 0x001B4E74 rowed as ??0/??1SubsystemInterface) from the
// subsystem shim, so this unit emits the retail 14-slot vtable 0x00C03D64.
typedef bool Bool;
#include "subsystem_interface.h"

// TerrainRoads.cpp's road type: virtual dtor in slot 0, next link at +0x10.
// Retail destroys each node through slot 0 with flag 0 and frees it with the
// global operator delete, which is what ::delete does to a polymorphic object.
class TerrainRoadType
{
public:
	virtual ~TerrainRoadType();
	TerrainRoadType *friend_getNext() { return m_next; }
protected:
	char m_pad04[0xC];
	TerrainRoadType *m_next;	///< 0x10
};

class TerrainRoadCollection : public SubsystemInterface
{
public:
	virtual ~TerrainRoadCollection();
	// Retail vtable 0x00C03D64 slots 1/9/10 (init/reset/update) are the folded
	// empty body at 0x000B3FD0.
	virtual void init() {}
	virtual void reset() {}
	virtual void update() {}
private:
	TerrainRoadType *m_roadList;
	TerrainRoadType *m_bridgeList;
};

TerrainRoadCollection::~TerrainRoadCollection()
{
	TerrainRoadType *temp;

	while( m_roadList )
	{
		temp = m_roadList->friend_getNext();
		::delete m_roadList;
		m_roadList = temp;
	}
	while( m_bridgeList )
	{
		temp = m_bridgeList->friend_getNext();
		::delete m_bridgeList;
		m_bridgeList = temp;
	}
}
