// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/subsystem_bfme2 /DNDEBUG /MD /EHsc
// ?load@ImageCollection@@QAEXH@Z @ 0x002D908D 249B
// Evidence: BFME1 donor ImageCollectionLoad.cpp trimmed (no userData block); same 5 strings TextureSize_%d HandCreated AptImages ParticleTextures TransitionImages in order; same loadDirectory TRUE OVERWRITE NULL 0; ret 4 single int arg; callers 0x0023A2F1; neighbours ImageBfmeSetTexture and stlport map.
#include <stdio.h>
#include "ascii_string.h"

// INI and ImageCollection are spelled as Image.cpp, the retail TU, spells them.
class Xfer;

enum INILoadType
{
	INI_LOAD_INVALID = 0,
	INI_LOAD_OVERWRITE = 1,
	INI_LOAD_CREATE_OVERRIDES = 2
};

class INI
{
public:
	INI();
	~INI();
	bool loadDirectory(AsciiString dirpath, bool recursive, INILoadType loadType, Xfer *xfer, int extra);
	const char *getNextSubToken(const char *expected);
	int scanInt(const char *token);
	static void parseBitString32(INI *ini, void *instance, void *store, const void *userData);

private:
	char m_unported[0x87C];
};

typedef bool Bool;
#include "subsystem_interface.h"

namespace _STL
{

template <class First, class Second> struct pair
{
	First first;
	Second second;
};

template <class Type> struct less
{
};

template <class Type> class allocator
{
};

template <class Key, class Value, class Compare, class Alloc> class map
{
public:
	map();
	unsigned char m_pad[0x18];
};

}

class ImageCollection : public SubsystemInterface
{
public:
	ImageCollection();
	void load(int textureSize);

public:
	virtual ~ImageCollection();
	// Retail vtable 0x00C03878 slots 1/9/10 (init/reset/update) are the folded
	// empty body at 0x000B3FD0, as in Zero Hour's ImageCollection.
	virtual void init() {}
	virtual void reset() {}
	virtual void update() {}

private:
	_STL::map<int, void *, _STL::less<int>, _STL::allocator<_STL::pair<const int, void *> > > m_imageMap;
};

void ImageCollection::load(int textureSize)
{
	char buffer[260];
	INI ini;
	sprintf(buffer, "Data\\INI\\MappedImages\\TextureSize_%d", textureSize);
	ini.loadDirectory(AsciiString(buffer), true, INI_LOAD_OVERWRITE, (Xfer *)0, 0);
	ini.loadDirectory("Data\\INI\\MappedImages\\HandCreated", true, INI_LOAD_OVERWRITE, (Xfer *)0, 0);
	ini.loadDirectory("Data\\INI\\MappedImages\\AptImages", true, INI_LOAD_OVERWRITE, (Xfer *)0, 0);
	ini.loadDirectory("Data\\INI\\MappedImages\\ParticleTextures", true, INI_LOAD_OVERWRITE, (Xfer *)0, 0);
	ini.loadDirectory("Data\\INI\\MappedImages\\TransitionImages", true, INI_LOAD_OVERWRITE, (Xfer *)0, 0);
}
