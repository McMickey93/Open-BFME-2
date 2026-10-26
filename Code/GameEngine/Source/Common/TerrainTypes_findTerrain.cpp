// cl: /O1 /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfme2_ascii
// stlport

// BFME2 terrain-type collection lookup. Layout is retail-owned: the list
// head lives at this+0x0C, TerrainType carries its name at +0x04 and its
// next link at +0x20 (the +0x00..+0x03 and +0x0C..+0x1F ranges are still
// unproven; m_texture sits at +0x08 per the two by-value getters that copy
// it). The name comparison calls out to AsciiString::compare (rowed at
// 0x0069D6) instead of inlining it the way the BFME1 donor does.
//
// Codegen notes (all load-bearing, verified byte-exact at 0x000317D18):
// the key travels by value (caller constructs, callee destroys through the
// pinned ~AsciiString at 0x00036410) and compare is declared throw() -
// without it MSVC spends an EH state around the loop (and [ebp-4],0) that
// retail does not have.

typedef int Int;
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

TerrainType *TerrainTypeCollection::findTerrain(AsciiString name)
{
	TerrainType *terrain;

	for (terrain = m_head; terrain; terrain = terrain->m_next) {
		if (terrain->m_str04.compare(name) == 0)
			return terrain;
	}

	return 0;
}
