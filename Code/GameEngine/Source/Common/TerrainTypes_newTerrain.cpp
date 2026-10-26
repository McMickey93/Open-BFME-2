// cl: /O1 /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /Ireference/shims/subsystem_bfme2
// TerrainTypeCollection::newTerrain @0x0031816C (149B): Zero Hour
// TerrainTypes.cpp's body. A new 0x30-byte TerrainType (its ctor 0x00317F6F,
// vtable 0x0080C66C) is filled from the "DefaultTerrain" entry through the
// rowed findTerrain 0x00317D18 and the type's operator= 0x0031804D, named
// through 0x00317C34 (the +0x04 AsciiString findTerrain compares) and pushed
// on the list head at this+0x0C through the +0x20 link findTerrain walks.
// BFME allocates with plain operator new where ZH used newInstance(). The
// only caller is INI::parseTerrainDefinition 0x00200A65, after findTerrain
// misses, as in ZH INITerrain.cpp.
typedef bool Bool;
#include "ascii_string.h"
#include "subsystem_interface.h"

class TerrainType
{
	friend class TerrainTypeCollection;
public:
	TerrainType();
	TerrainType &operator=(const TerrainType &that);
	void friend_setName(AsciiString name);
private:
	char m_pad00[4];
	AsciiString m_str04;
	AsciiString m_str08;
	char m_pad0C[0x14];
	TerrainType *m_next;
	char m_pad24[0x0C];
};

class TerrainTypeCollection : public SubsystemInterface
{
public:
	TerrainTypeCollection();
	virtual ~TerrainTypeCollection();
	virtual void init() {}
	virtual void reset() {}
	virtual void update() {}
	TerrainType *findTerrain(AsciiString name);
	TerrainType *newTerrain(AsciiString name);
private:
	TerrainType *m_head;
};

TerrainType *TerrainTypeCollection::newTerrain(AsciiString name)
{
	TerrainType *terrain = 0;

	terrain = new TerrainType;

	TerrainType *defaultTerrain = findTerrain(AsciiString("DefaultTerrain"));
	if (defaultTerrain)
		*terrain = *defaultTerrain;

	terrain->friend_setName(name);

	terrain->m_next = m_head;
	m_head = terrain;

	return terrain;
}
