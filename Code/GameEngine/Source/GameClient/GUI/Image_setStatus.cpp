// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD
//
// Image::setStatus, retail 0x002D8E63, 15 bytes.
// OR bits into m_status at +0x30 and return the previous value.
// Kept out of AptMapPreviewPictureImage.cpp so that TU's caller
// cannot see this body (matching.md callee-visibility trap).

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

unsigned int Image::setStatus(unsigned int bit)
{
	unsigned int old = m_status;
	m_status |= bit;
	return old;
}
