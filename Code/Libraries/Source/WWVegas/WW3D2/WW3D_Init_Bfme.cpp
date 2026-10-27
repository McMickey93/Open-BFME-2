// cl: /DNDEBUG /MD /EHsc
// platformsdk
// Retail 0x008FD640: BFME WW3D initialisation stores the static sort-list pair.

#include <windows.h>

class DX8Wrapper
{
public:
	static bool Init(void *hwnd, bool lite);
};

class StaticSortListClass
{
};

class DefaultStaticSortListClass : public StaticSortListClass
{
public:
	DefaultStaticSortListClass();

private:
	char m_body[0x324];
};

void *g_WW3D_Hwnd;
unsigned char g_WW3D_Lite;

class WW3D
{
public:
	static bool Init(void *hwnd, char *defaultpal, bool lite);

private:
	static bool IsInitted;	// 0x00DEC3D4, defined in ww3d.cpp
	static StaticSortListClass *DefaultStaticSortLists;	// 0x00DEC3F0, defined in ww3d.cpp
	static StaticSortListClass *CurrentStaticSortLists;	// 0x00DEC3F4, defined in ww3d.cpp
};

bool WW3D::Init(void *hwnd, char *, bool lite)
{
	g_WW3D_Hwnd = hwnd;
	g_WW3D_Lite = lite;
	if (!DX8Wrapper::Init(g_WW3D_Hwnd, lite))
		return false;
	timeBeginPeriod(1);
	DefaultStaticSortListClass *list = new DefaultStaticSortListClass;
	DefaultStaticSortLists = list;
	CurrentStaticSortLists = list;
	if (!lite)
		IsInitted = true;
	return true;
}
