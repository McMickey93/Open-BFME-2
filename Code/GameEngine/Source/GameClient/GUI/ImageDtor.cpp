// cl: /Ireference/shims/bfme2_ascii /EHsc /DNDEBUG /MD
//
// Image::~Image, retail 0x002D91CC (94B) plus its scalar deleting
// destructor 0x002D9262 (28B).
//
// Member layout follows the proven ImageCtor TU in this directory
// (vptr 0xC037B8; m_name +0x04; m_filename +0x08; texture size +0x0C;
// UV coords +0x14; image size +0x24; texture holder +0x2C;
// m_status +0x30). The +0x2C holder is the 4-byte BfmeMapPictureTexture
// allocation from Image::bfmeSetTexture in this directory: its first
// word is the TextureBaseClass whose Release_Ref is the rowed release
// body at 0x61ED10, then the holder itself is freed.
//
// Shape notes, all read off retail:
// - A named holder local keeps the holder in edi across the Release
//   call; a bare member re-read uses eax plus a reload and misses.
// - The filename (+0x08) and name (+0x04) destructions are the implicit
//   member teardown in reverse declaration order through the rowed
//   AsciiString pin at 0x36410; the holder block runs under EH state 1.

#include <new>
#include <string.h>

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

// ??1Image@@UAE@XZ, retail 0x002D91CC (94B).
Image::~Image()
{
	BfmeMapPictureTexture *holder = m_texture;
	if (holder) {
		if (holder->m_texture)
			holder->m_texture->Release_Ref();
		delete holder;
	}
}
