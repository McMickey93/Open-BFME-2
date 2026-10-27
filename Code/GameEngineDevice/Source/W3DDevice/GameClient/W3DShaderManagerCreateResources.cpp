// cl: /O1 /DNDEBUG /MD /EHsc
// dxsdk
// platformsdk
// W3DShaderManager dependent-resource creation, retail 0x000754DE..0x00075649
// (363 bytes, plain RET) and its EH handler 0x0075EF58. Original name unknown:
// W3DShaderManager::init (0x00077F80) calls it with no arguments at +0x0E; WB
// 0x7CEA80 is the same body with RefCountClass::Release_Ref's refcount.h:164
// assertion and the "Creating POOL_DEFAULT surface: W3DShaderManager::
// m_oldRenderSurface / m_renderTexture / m_newRenderSurface / m_oldDepthSurface"
// logs. Semantic donor: Open-BFME-1 W3DShaderManagerCreateResources.cpp
// (BfmeShaderShutdown::rva00716770), the counterpart of the rowed
// releaseDependentResources at 0x00076790.
// The quad vertex buffer is released through the global itself (REF_PTR_RELEASE
// with Release_Ref inlined), which keeps the object in EAX and gives retail's
// mov ecx,eax / add eax,4 counter address.

#include <d3d9.h>
#include <new>

// Native dynamic vertex buffer, constructor rowed at 0x0013AC00 (0x20 bytes).
class BfmeDynamicNativeVB
{
public:
	BfmeDynamicNativeVB(unsigned type, unsigned short vertexCount, unsigned usage, unsigned vertexSize);
	virtual void Delete_This();
	void Release_Ref()
	{
		NumRefs--;
		if (NumRefs == 0)
			Delete_This();
	}

	int NumRefs;
	unsigned type;
	unsigned short vertexCount;
	int engineReferences;
	void *format;
	bool usesDeclaration;
	void *buffer;
};

// The device, surfaces and render texture keep the ledger's Direct3D 8 spellings
// (W3DShaderManager's statics decorate with them) but are Direct3D 9 objects:
// device CreateTexture (23, with the shared-handle argument), GetRenderTarget (38)
// and GetDepthStencilSurface (40); surface GetDesc (12); texture GetSurfaceLevel
// (18); Release (2) on both.
struct IDirect3DDevice8;
struct IDirect3DSurface8;
struct IDirect3DTexture8;

class DX8Wrapper
{
public:
	static IDirect3DDevice8 *_Get_D3D_Device8() { return D3DDevice; }
protected:
	static IDirect3DDevice8 *D3DDevice;
};

// Shader-manager render-to-texture globals at VA 0x009E1F64..0x009E1F70 and
// the quad vertex buffer / index at 0x009E1F7C / 0x009E1F80, spelled as the
// data ledger names them.
class W3DShaderManager
{
public:
	static IDirect3DSurface8 *m_oldRenderSurface;
	static IDirect3DTexture8 *m_renderTexture;
};
extern unsigned int g_Va009E1F6C;	// m_newRenderSurface
struct ShaderComResourceRef;
extern ShaderComResourceRef *rva012F9D10;	// m_oldDepthSurface
class VertexBufferClass;
extern VertexBufferClass *g_vb;
extern int g_quadIndex;

#define m_newRenderSurface (*(IDirect3DSurface8 **)&g_Va009E1F6C)
#define m_oldDepthSurface (*(IDirect3DSurface8 **)&rva012F9D10)
#define ShaderQuadBuffer (*(BfmeDynamicNativeVB **)&g_vb)

#define DEVICE9 (reinterpret_cast<IDirect3DDevice9 *>(DX8Wrapper::_Get_D3D_Device8()))
#define SURFACE9(x) (reinterpret_cast<IDirect3DSurface9 *>(x))
#define SURFACE9_OUT(x) (reinterpret_cast<IDirect3DSurface9 **>(x))
#define TEXTURE9(x) (reinterpret_cast<IDirect3DTexture9 *>(x))

void __cdecl Rva000754DEInit()
{
	if (ShaderQuadBuffer) {
		ShaderQuadBuffer->Release_Ref();
		ShaderQuadBuffer = 0;
	}
	ShaderQuadBuffer = new BfmeDynamicNativeVB(0, 200, 1, 0x1C);
	g_quadIndex = 0;

	if (W3DShaderManager::m_oldRenderSurface || W3DShaderManager::m_renderTexture ||
		m_newRenderSurface || m_oldDepthSurface)
		return;

	DEVICE9->GetRenderTarget(0, SURFACE9_OUT(&W3DShaderManager::m_oldRenderSurface));
	D3DSURFACE_DESC desc;
	SURFACE9(W3DShaderManager::m_oldRenderSurface)->GetDesc(&desc);
	HRESULT hr = DEVICE9->CreateTexture(desc.Width, desc.Height, 1, D3DUSAGE_RENDERTARGET,
		desc.Format, D3DPOOL_DEFAULT, reinterpret_cast<IDirect3DTexture9 **>(&W3DShaderManager::m_renderTexture), 0);
	if (hr != D3D_OK) {
		if (W3DShaderManager::m_oldRenderSurface)
			SURFACE9(W3DShaderManager::m_oldRenderSurface)->Release();
		W3DShaderManager::m_oldRenderSurface = 0;
		W3DShaderManager::m_renderTexture = 0;
		return;
	}
	hr = TEXTURE9(W3DShaderManager::m_renderTexture)->GetSurfaceLevel(0, SURFACE9_OUT(&m_newRenderSurface));
	if (hr != D3D_OK) {
		if (W3DShaderManager::m_renderTexture)
			TEXTURE9(W3DShaderManager::m_renderTexture)->Release();
		m_newRenderSurface = 0;
		W3DShaderManager::m_renderTexture = 0;
		return;
	}
	hr = DEVICE9->GetDepthStencilSurface(SURFACE9_OUT(&m_oldDepthSurface));
	if (hr != D3D_OK) {
		if (m_newRenderSurface)
			SURFACE9(m_newRenderSurface)->Release();
		if (W3DShaderManager::m_renderTexture)
			TEXTURE9(W3DShaderManager::m_renderTexture)->Release();
		m_oldDepthSurface = 0;
		m_newRenderSurface = 0;
		W3DShaderManager::m_renderTexture = 0;
	}
}
