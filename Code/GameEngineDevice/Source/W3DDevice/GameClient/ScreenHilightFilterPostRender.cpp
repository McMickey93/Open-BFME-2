// cl: /O1 /G7 /arch:SSE /DNDEBUG /MD /EHsc
// dxsdk
// platformsdk
//
// ScreenHilightFilter::set, retail 0x000FB10B..0x000FB2C1 (438B), is slot 5
// of the same vftable. The clean BFME 1 donor at revision
// f98983a7d3bb405f1a4ba94bb6a2a168062a819d (game/GameEngineDevice/Source/
// W3DDevice/GameClient/ScreenHilightFilterSet.cpp) establishes the material,
// opaque shader, two empty textures and depth-state setup. BFME 2 uses the
// matched ScreenBWFilter helpers and texture-reference ABI; every body byte
// and relocation agrees. This partial class view retains the donor's spelling.
// Set_Hilight_Render_State keeps this inlined setup separate from postRender's
// existing out-of-line Set_DX8_Render_State calls.
//
// ScreenHilightFilter::postRender, slot 3 of its vftable (0x007CF31C, after
// the rowed preRender 0x000FAAC5). Zero Hour's postRender contract with
// BFME 2's hilight pass: a deferred frame (+0x14 set by preRender) only
// restores the default target and resets; otherwise, after set(mode), when
// GlobalData +0xD34 asks for it the stretched back buffer (+0x28 texture of
// the current pair) is redrawn into the +0x2C target through the filter's
// pixel/vertex shaders (+0x04/+0x08) with a colour constant from 0x000ABBEF,
// then the gaussian blur 0x00077392 runs over the pair and the result
// (+0x24) is blended additively over the viewport (drawViewport). Device
// calls use the D3D9 slot numbers; the sampler, texture and pixel-shader
// constant helpers are DX8Wrapper's inline forms (counters as the matched
// Rva000FBA57PostRender.cpp and W3DShaderManagerScreenBWFilterSet.cpp).
#include <string.h>

class Vector3
{
public:
	Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
	float X;
	float Y;
	float Z;
};

class Vector4
{
public:
	__declspec(dllimport) __forceinline Vector4(void) {}
	__declspec(dllimport) __forceinline Vector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}
	float X, Y, Z, W;
};

#include "../../../../Libraries/Include/Lib/Coord2D.h"
class Vector2;

#include <d3d9.h>

struct IDirect3DSurface8;
struct IDirect3DBaseTexture8 {};

// The device and textures keep their D3D8 type names (DX8Wrapper's static
// decorations) but are Direct3D 9 objects: SetRenderState 57, SetTexture 65, SetSamplerState 69,
// SetVertexDeclaration 87, SetVertexShader 92, SetPixelShader 107,
// SetPixelShaderConstantF 109; texture AddRef / Release 1 / 2.
struct IDirect3DDevice8;

extern unsigned number_of_DX8_calls;
extern unsigned g_fvfShader;

class StringClass
{
public:
	StringClass(int initial_len = 0, bool hint_temporary = false);
	__forceinline ~StringClass() { Free_String(); }
private:
	void Free_String();
	char *m_Buffer;
};

class VertexMaterialClass
{
public:
	enum PresetType
	{
		PRELIT_DIFFUSE = 0
	};
	virtual void Delete_This();
	static VertexMaterialClass *Get_Preset(PresetType type);
	void Add_Ref() { NumRefs++; }
	void Release_Ref()
	{
		NumRefs--;
		if (NumRefs == 0)
			Delete_This();
	}
	int NumRefs;
};
extern VertexMaterialClass *ScreenMaterial;

class ShaderClass
{
public:
	static ShaderClass _PresetOpaqueShader;
	unsigned int ShaderBits;
protected:
	friend class DX8Wrapper;
	static bool ShaderDirty;
private:
	unsigned int m_bits[2];
};

class TextureBaseClass
{
public:
	void Release_Ref();
};

struct BFME2TextureResource;
struct BFME2TextureRef
{
	BFME2TextureRef(BFME2TextureResource *texture) : Ptr(texture) {}
	~BFME2TextureRef()
	{
		if (Ptr)
			((TextureBaseClass *)Ptr)->Release_Ref();
	}
	BFME2TextureResource *Ptr;
};
void BFME2Set_Texture(unsigned stage, const BFME2TextureRef &texture);

class WW3D
{
public:
	static bool Is_Snapshot_Activated() { return SnapshotActivated; }
private:
	static bool SnapshotActivated;
};

struct RenderStateStruct
{
	ShaderClass shader;
};
class DX8Wrapper
{
public:
	static IDirect3DDevice8 *_Get_D3D_Device8() { return D3DDevice; }
	static void Set_Render_Target(IDirect3DSurface8 *render_target, bool use_default_depth_buffer);
	static void Clear(bool clear_color, bool clear_z_stencil, bool clear_stencil, const Vector3 &color, float dest_alpha, float z, unsigned int stencil);
	static void Set_DX8_Render_State(unsigned long state, unsigned value);
	static void Set_DX8_Texture_Stage_State(unsigned stage, unsigned long state, unsigned value);
	static void Apply_Render_State_Changes();

	static void Get_DX8_Render_State_Value_Name(StringClass &name, unsigned long state, unsigned int value);
	static __forceinline void Set_Material(VertexMaterialClass *material)
	{
		if (material)
			material->Add_Ref();
		if (ScreenMaterial)
			ScreenMaterial->Release_Ref();
		ScreenMaterial = material;
		render_state_changed |= 0x4000;
	}

	static __forceinline void Set_Shader(const ShaderClass &shader)
	{
		if (!ShaderClass::ShaderDirty && shader.ShaderBits == render_state.shader.ShaderBits)
			return;
		render_state.shader.ShaderBits = shader.ShaderBits;
		render_state_changed |= 0x8000;
		StringClass str;
	}

	static __forceinline void Set_Hilight_Render_State(unsigned long state, unsigned value)
	{
		if (RenderStates[state] == value)
			return;
		if (WW3D::Is_Snapshot_Activated())
		{
			StringClass value_name(0, true);
			Get_DX8_Render_State_Value_Name(value_name, state, value);
		}
		RenderStates[state] = value;
		reinterpret_cast<IDirect3DDevice9 *>(_Get_D3D_Device8())->SetRenderState((D3DRENDERSTATETYPE)state, value);
		number_of_DX8_calls++;
		render_state_changes++;
	}

	static __forceinline void Set_DX8_Sampler_State(unsigned stage, unsigned type, unsigned value)
	{
		reinterpret_cast<IDirect3DDevice9 *>(_Get_D3D_Device8())->SetSamplerState(stage, (D3DSAMPLERSTATETYPE)type, value);
		number_of_DX8_calls++;
		texture_stage_state_changes++;
	}
	static __forceinline void Set_DX8_Texture(unsigned stage, IDirect3DBaseTexture8 *texture)
	{
		if (stage >= 16) {
			reinterpret_cast<IDirect3DDevice9 *>(_Get_D3D_Device8())->SetTexture(stage, reinterpret_cast<IDirect3DBaseTexture9 *>(texture));
			number_of_DX8_calls++;
			return;
		}
		if (Textures[stage] == texture)
			return;
		if (Textures[stage])
			reinterpret_cast<IDirect3DBaseTexture9 *>(Textures[stage])->Release();
		Textures[stage] = texture;
		if (Textures[stage])
			reinterpret_cast<IDirect3DBaseTexture9 *>(Textures[stage])->AddRef();
		reinterpret_cast<IDirect3DDevice9 *>(_Get_D3D_Device8())->SetTexture(stage, reinterpret_cast<IDirect3DBaseTexture9 *>(texture));
		number_of_DX8_calls++;
		texture_changes++;
	}
	static __forceinline void Set_Pixel_Shader_Constant(int reg, const void *data, int count)
	{
		int memsize = sizeof(Vector4) * count;
		if (memcmp(data, &Pixel_Shader_Constants[reg], memsize) == 0)
			return;
		memcpy(&Pixel_Shader_Constants[reg], data, memsize);
		reinterpret_cast<IDirect3DDevice9 *>(_Get_D3D_Device8())->SetPixelShaderConstantF(reg, (const float *)data, count);
		number_of_DX8_calls++;
	}

protected:
	static IDirect3DDevice8 *D3DDevice;
	static IDirect3DBaseTexture8 *Textures[16];
	static unsigned texture_changes;
	static unsigned texture_stage_state_changes;
	static Vector4 Pixel_Shader_Constants[8];
	static unsigned RenderStates[256];
	static unsigned render_state_changed;
	static unsigned render_state_changes;
	static RenderStateStruct render_state;
};

struct GlowSampleVector;
struct IDirect3DTexture8;

class W3DShaderManager
{
public:
	static void drawViewport(int color, bool shaded, const Vector2 *viewportSize);
	static void performGlow(float weightScale, const GlowSampleVector *samples, int textureSize, IDirect3DTexture8 *sourceTexture,
		IDirect3DSurface8 *tempSurface, IDirect3DTexture8 *tempTexture, IDirect3DSurface8 *destSurface);
};

// The settings block behind Rva00309E4BGet (+0x08 is the blur strength).
struct BfmeHilightSettings
{
	char m_pad00[8];
	float m_08;
};
int Rva00309E4BGet();

// Helpers called from here: the colour read (0x000ABBEF) and the square
// quad draw (rowed 0x00075A23). The blur pass is the rowed
// W3DShaderManager::performGlow (0x00077392).
void rva000ABBEF(float *r, float *g, float *b, int index);
void Rva00075A23Draw(int width, int height);

extern bool bfmeOnlyEmissiveDraws;
class GlobalData;
extern GlobalData *TheWritableGlobalData;
struct BfmeHilightGlobalDataView
{
	char m_pad[0xD34];
	bool m_D34;
};

enum FilterModes { FM_NULL_MODE = 0 };

class ScreenHilightFilter
{
public:
	virtual int slot00();
	virtual int slot04();
	virtual bool preRender(bool &skipRender, int &scenePassMode);
	virtual bool postRender(int mode, Coord2D &scrollDelta, bool &doExtraRender, Coord2D *viewportSize);
	virtual void slot10();
protected:
	virtual int set(FilterModes mode);
public:
	virtual void reset();
private:
	unsigned m_pixelShader;	// +0x04
	unsigned m_vertexShader;	// +0x08
	int m_size;	// +0x0C
	int m_current;	// +0x10
	bool m_14;	// +0x14
	int m_kernel[3];	// +0x18
	IDirect3DBaseTexture8 *m_result;	// +0x24
	IDirect3DBaseTexture8 *m_textures[1];	// +0x28, indexed by m_current
	IDirect3DSurface8 *m_renderTarget;	// +0x2C
	void *m_surfaces[2];	// +0x30
};

// ?postRender@ScreenHilightFilter@@UAE_NHAAVCoord2D@@AA_NPAV2@@Z @0x000FAC37
bool ScreenHilightFilter::postRender(int mode, Coord2D &scrollDelta, bool &doExtraRender, Coord2D *viewportSize)
{
	bfmeOnlyEmissiveDraws = false;
	if (m_14) {
		DX8Wrapper::Set_Render_Target(0, true);
		reset();
		doExtraRender = true;
		m_14 = false;
		return true;
	}
	if (!set((FilterModes)mode))
		return false;
	if (TheWritableGlobalData && ((BfmeHilightGlobalDataView *)TheWritableGlobalData)->m_D34) {
		DX8Wrapper::Set_Render_Target(m_renderTarget, false);
		{
			Vector3 color(0.0f, 0.0f, 0.0f);
			DX8Wrapper::Clear(true, false, false, color, 0.0f, 1.0f, 0);
		}
		DX8Wrapper::Set_DX8_Sampler_State(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
		DX8Wrapper::Set_DX8_Sampler_State(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
		DX8Wrapper::Set_DX8_Sampler_State(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
		DX8Wrapper::Set_DX8_Sampler_State(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		DX8Wrapper::Set_DX8_Sampler_State(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
		DX8Wrapper::Set_DX8_Render_State(D3DRS_CULLMODE, D3DCULL_NONE);
		DX8Wrapper::Set_DX8_Render_State(D3DRS_ZWRITEENABLE, FALSE);
		DX8Wrapper::Set_DX8_Render_State(D3DRS_ZENABLE, D3DZB_FALSE);
		DX8Wrapper::Set_DX8_Texture_Stage_State(0, 0x18, 0);
		DX8Wrapper::Set_DX8_Texture_Stage_State(1, 0x18, 0);
		DX8Wrapper::Set_DX8_Texture(0, m_textures[m_current]);
		reinterpret_cast<IDirect3DDevice9 *>(DX8Wrapper::_Get_D3D_Device8())->SetPixelShader(
			reinterpret_cast<IDirect3DPixelShader9 *>(m_pixelShader));
		number_of_DX8_calls++;
		reinterpret_cast<IDirect3DDevice9 *>(DX8Wrapper::_Get_D3D_Device8())->SetVertexDeclaration(
			reinterpret_cast<IDirect3DVertexDeclaration9 *>(g_fvfShader));
		number_of_DX8_calls++;
		reinterpret_cast<IDirect3DDevice9 *>(DX8Wrapper::_Get_D3D_Device8())->SetVertexShader(
			reinterpret_cast<IDirect3DVertexShader9 *>(m_vertexShader));
		number_of_DX8_calls++;
		{
			float r, g, b;
			rva000ABBEF(&r, &g, &b, -1);
			Vector4 constant(r - 1.0f, g - 1.0f, b - 1.0f, 0.0f);
			DX8Wrapper::Set_Pixel_Shader_Constant(0, &constant, 1);
		}
		DX8Wrapper::Set_DX8_Render_State(D3DRS_ALPHABLENDENABLE, FALSE);
		DX8Wrapper::Set_DX8_Render_State(D3DRS_SRCBLEND, D3DBLEND_ONE);
		DX8Wrapper::Set_DX8_Render_State(D3DRS_DESTBLEND, D3DBLEND_ZERO);
		Rva00075A23Draw(m_size, m_size);
		DX8Wrapper::Set_Render_Target(0, true);
	}
	W3DShaderManager::performGlow(((BfmeHilightSettings *)Rva00309E4BGet())->m_08,
		(const GlowSampleVector *)m_kernel, m_size, (IDirect3DTexture8 *)m_result,
		(IDirect3DSurface8 *)m_surfaces[m_current], (IDirect3DTexture8 *)m_textures[m_current], m_renderTarget);
	DX8Wrapper::Set_DX8_Texture(0, m_result);
	DX8Wrapper::Set_DX8_Render_State(D3DRS_SRCBLEND, D3DBLEND_ONE);
	DX8Wrapper::Set_DX8_Render_State(D3DRS_DESTBLEND, D3DBLEND_INVSRCCOLOR);
	DX8Wrapper::Set_DX8_Render_State(D3DRS_ALPHABLENDENABLE, TRUE);
	DX8Wrapper::Apply_Render_State_Changes();
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, 5, 1);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, 6, 2);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, 4, 2);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, 0x18, 0);
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, 0x18, 0);
	reinterpret_cast<IDirect3DDevice9 *>(DX8Wrapper::_Get_D3D_Device8())->SetVertexShader(0);
	number_of_DX8_calls++;
	W3DShaderManager::drawViewport(-1, true, (const Vector2 *)viewportSize);
	reset();
	return true;
}

// ?set@ScreenHilightFilter@@MAEHW4FilterModes@@@Z @0x000FB10B
int ScreenHilightFilter::set(FilterModes mode)
{
	if (mode > FM_NULL_MODE)
	{
		VertexMaterialClass *vmat = VertexMaterialClass::Get_Preset(VertexMaterialClass::PRELIT_DIFFUSE);
		DX8Wrapper::Set_Material(vmat);
		if (vmat) vmat->Release_Ref();
		DX8Wrapper::Set_Shader(ShaderClass::_PresetOpaqueShader);
		BFME2Set_Texture(0, 0);
		BFME2Set_Texture(1, 0);
		DX8Wrapper::Apply_Render_State_Changes();
		DX8Wrapper::Set_Hilight_Render_State(23, 8);
		DX8Wrapper::Set_Hilight_Render_State(14, 0);
		DX8Wrapper::Apply_Render_State_Changes();
	}
	return true;
}
