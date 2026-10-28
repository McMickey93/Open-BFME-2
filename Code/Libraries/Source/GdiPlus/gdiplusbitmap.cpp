// cl: /O1 /GX-
// platformsdk
// Microsoft Platform SDK GDI+ 1.0 GdiPlusBitmap.h inlines, emitted out of line
// by the ATL 7.1 CImage translation unit that carries the Gdiplus::Image and
// Gdiplus::Bitmap vtables.
#include <windows.h>
#include <objidl.h>
#include <float.h>

struct IDirectDrawSurface7;
#include <pshpack8.h>
namespace Gdiplus
{
namespace DllExports
{
#include <GdiPlusMem.h>
}
#include <GdiPlusBase.h>
#include <GdiPlusEnums.h>
#include <GdiPlusTypes.h>
#include <GdiPlusPixelFormats.h>
#include <GdiPlusColor.h>
#include <GdiPlusMetaHeader.h>
#include <GdiPlusImaging.h>
#include <GdiPlusColorMatrix.h>
#include <GdiPlusGpStubs.h>
#include <GdiPlusHeaders.h>
namespace DllExports
{
#include <GdiPlusFlat.h>
}
// Keep the selected bitmap inlines below: the SDK's complete class declarations
// and flat API declarations above supply their types without local copies.

inline __declspec(noinline) Image::~Image()
{
    DllExports::GdipDisposeImage(nativeImage);
}

Image *Image::Clone()
{
    GpImage *cloneimage = 0;

    SetStatus(DllExports::GdipCloneImage(nativeImage, &cloneimage));

    return new Image(cloneimage, lastResult);
}

UINT Image::GetWidth()
{
    UINT width = 0;

    SetStatus(DllExports::GdipGetImageWidth(nativeImage, &width));

    return width;
}

UINT Image::GetHeight()
{
    UINT height = 0;

    SetStatus(DllExports::GdipGetImageHeight(nativeImage, &height));

    return height;
}

PixelFormat Image::GetPixelFormat()
{
    PixelFormat format;

    SetStatus(DllExports::GdipGetImagePixelFormat(nativeImage, &format));

    return format;
}

INT Image::GetPaletteSize()
{
    INT size = 0;

    SetStatus(DllExports::GdipGetImagePaletteSize(nativeImage, &size));

    return size;
}

Status Image::GetPalette(ColorPalette *palette, INT size)
{
    return SetStatus(DllExports::GdipGetImagePalette(nativeImage, palette, size));
}

Image::Image(GpImage *nativeImage, Status status)
{
    SetNativeImage(nativeImage);
    lastResult = status;
}

// ?Image::SetNativeImage present-unmatched
void Image::SetNativeImage(GpImage *nativeImage)
{
    this->nativeImage = nativeImage;
}

// Bitmap constructors and their deleting destructor live in gdiplusbitmap_dtor.cpp.

Status Bitmap::LockBits(const Rect *rect, UINT flags, PixelFormat format, BitmapData *lockedBitmapData)
{
    return SetStatus(DllExports::GdipBitmapLockBits(
        (GpBitmap *)nativeImage, rect, flags, format, lockedBitmapData));
}

Status Bitmap::UnlockBits(BitmapData *lockedBitmapData)
{
    return SetStatus(DllExports::GdipBitmapUnlockBits((GpBitmap *)nativeImage, lockedBitmapData));
}

}

#include <poppack.h>
