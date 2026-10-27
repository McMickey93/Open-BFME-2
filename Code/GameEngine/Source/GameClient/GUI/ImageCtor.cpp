// cl: /Ireference/shims/bfme2_ascii /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
// platformsdk
//
// ??0Image@@QAE@XZ, retail 0x002D8FE4, 122 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameClient/System/ImageCtorThunk.cpp,
// Image::Image): null the texture holder, clear both filename strings, zero
// the sizes and status, and reset the UVs to the full-texture range. The
// retail body follows the reference source statement for statement,
// including the string clears through the 0x36410 pin; the BFME2 deltas are
// the vtable at 0xC037B8 and the member offsets below.

typedef int Int;

#include <windows.h>
#include "ascii_string.h"

#include "../../../../Libraries/Include/Lib/ICoord2D.h"

#include "../../../../Libraries/Include/Lib/Coord2D.h"

#include "../../../../Libraries/Include/Lib/Region2D.h"

class INI;

// The Image view is spelled as Image.cpp, the retail TU, spells it.
class TextureBaseClass
{
public:
	void Release_Ref();
};

// The 4-byte texture holder Image::bfmeSetTexture allocates at +0x2C; its
// first word is the TextureBaseClass ~Image releases.
class BfmeMapPictureTexture
{
public:
	__declspec(dllimport) __forceinline BfmeMapPictureTexture() : m_texture(0) {}
	BfmeMapPictureTexture &operator=(const BfmeMapPictureTexture &that);

	TextureBaseClass *m_texture;
};

class Image
{
public:
	Image();
	virtual ~Image();
	unsigned int setStatus(unsigned int bit);
	unsigned int clearStatus(unsigned int bit);
	void bfmeSetTexture(const BfmeMapPictureTexture &texture);
	void setImageSize(ICoord2D *size);
	void setUV(Region2D *uv) { if (uv) m_UVCoords = *uv; }
	const ICoord2D *getTextureSize(void) const { return &m_textureSize; }

	int getImageWidth(void) const { return m_imageSize.x; }
	int getImageHeight(void) const { return m_imageSize.y; }

	static void parseImageCoords(INI *ini, void *instance, void *store, const void *userData);
	static void parseImageStatus(INI *ini, void *instance, void *store, const void *userData);

private:
	AsciiString m_name; // +0x04
	AsciiString m_filename; // +0x08
	ICoord2D m_textureSize; // +0x0C
	Region2D m_UVCoords; // +0x14
	ICoord2D m_imageSize; // +0x24
	BfmeMapPictureTexture *m_texture; // +0x2C
	unsigned int m_status; // +0x30
};

// ??0Image@@QAE@XZ
Image::Image()
{
	m_texture = NULL;
	m_name.clear();
	m_filename.clear();
	m_textureSize.x = 0;
	m_textureSize.y = 0;
	m_UVCoords.lo.x = 0.0f;
	m_UVCoords.lo.y = 0.0f;
	m_UVCoords.hi.x = 1.0f;
	m_UVCoords.hi.y = 1.0f;
	m_imageSize.x = 0;
	m_imageSize.y = 0;
	m_status = 0;
}
