// cl: /Oy /DNDEBUG /MD
//
// DX8Wrapper::_Create_DX8_Surface, retail 0x0011DC60, 62 bytes.
// Dedicated TU so SurfaceClass's constructor cannot inline this body.

class IDirect3DSurface9;

struct IDirect3DDevice8;
struct IDirect3DDevice9;

struct IDirect3DDevice9Vtbl
{
	void *reserved[36];
	long (__stdcall *CreateOffscreenPlainSurface)(
		IDirect3DDevice9 *self,
		unsigned width,
		unsigned height,
		unsigned format,
		unsigned pool,
		IDirect3DSurface9 **surface,
		void *sharedHandle);
};

struct IDirect3DDevice9
{
	IDirect3DDevice9Vtbl *lpVtbl;
};

enum WW3DFormat
{
	WW3D_FORMAT_UNKNOWN
};

enum _D3DPOOL
{
	D3DPOOL_DEFAULT
};

class DX8Wrapper
{
public:
	static IDirect3DSurface9 *_Create_DX8_Surface(
		unsigned width, unsigned height, WW3DFormat format, _D3DPOOL pool);

protected:
	// The ledger's ?D3DDevice@DX8Wrapper@@1PAUIDirect3DDevice8@@A (0x9EDA34);
	// BFME 2 calls through it with the Direct3D 9 vtable.
	static IDirect3DDevice8 *D3DDevice;
};

// The DX8 call counter at 0x9EDA98 (the ledger's ?number_of_DX8_calls@@3IA).
extern unsigned number_of_DX8_calls;

IDirect3DSurface9 *DX8Wrapper::_Create_DX8_Surface(
	unsigned width, unsigned height, WW3DFormat format, _D3DPOOL pool)
{
	IDirect3DSurface9 *surface = 0;
	IDirect3DDevice9 *device = (IDirect3DDevice9 *)D3DDevice;
	device->lpVtbl->CreateOffscreenPlainSurface(
		device, width, height, (unsigned)format, (unsigned)pool, &surface, 0);
	++number_of_DX8_calls;
	return surface;
}

