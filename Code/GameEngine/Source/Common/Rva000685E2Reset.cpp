// dxsdk
// platformsdk
// flags: region default (reverse/retail_inventory/flag_regions.csv)
// ?rva000685E2@BaseHeightMapRenderObjClass@@QAEXXZ @0x000685E2 272B
// Bulk DX8 texture-stage + render-state reset. Retail is 4x
// Set_DX8_Texture_Stage_State, 2x direct IDirect3DDevice9::SetSamplerState
// (slot 69, +0x114: the D3D8 texture-stage ADDRESSU/ADDRESSV states are
// sampler states in D3D9) with counter bumps, 6x wrapper, 2x direct, 2x
// wrapper, 3x Set_DX8_Render_State. Evidence: unlock lane; callees rowed
// 0x000661DD 0x0006615F; data VAs 0x009EDA34 0x009EDA98 0x009EDA68
// with extern names in use; neighbours Disp32DwordClearers2.cpp and
// Rva000687B8.cpp share // cl: /O1; no args ret.
// A thiscall member, not a free function: its only caller, the terrain
// render coordinator 0x000E2FBD, loads ecx with its own this before each
// of its six calls (target fact); the body itself never reads this. It sits
// in the BaseHeightMap code (0x00066808..0x00069DB1). Semantic donor: the
// stage-0/1 reset matches ZH CloudMapTerrainTextureClass::restore, which
// BFME 1's FlatHeightMap Render calls at the same points.

#include <d3d9.h>

// The device keeps its D3D8 type name but is a Direct3D 9 device.
struct IDirect3DDevice8;
#define DEVICE9 (reinterpret_cast<IDirect3DDevice9 *>(DX8Wrapper::D3DDevice))
class BaseHeightMapRenderObjClass;
class DX8Wrapper
{
	friend class BaseHeightMapRenderObjClass;
public:
	static void Set_DX8_Texture_Stage_State(unsigned stage, unsigned long state, unsigned value);
	static void Set_DX8_Render_State(unsigned long state, unsigned value);
protected:
	static IDirect3DDevice8 *D3DDevice;
	static unsigned int texture_stage_state_changes;
};
extern unsigned int number_of_DX8_calls;
class BaseHeightMapRenderObjClass
{
public:
	void rva000685E2(void);
};

void BaseHeightMapRenderObjClass::rva000685E2(void)
{
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	DEVICE9->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	number_of_DX8_calls++;
	DX8Wrapper::texture_stage_state_changes++;
	DEVICE9->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	number_of_DX8_calls++;
	DX8Wrapper::texture_stage_state_changes++;
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, D3DTSS_TEXCOORDINDEX, 0);
	DX8Wrapper::Set_DX8_Texture_Stage_State(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	DEVICE9->SetSamplerState(1, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	number_of_DX8_calls++;
	DX8Wrapper::texture_stage_state_changes++;
	DEVICE9->SetSamplerState(1, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	number_of_DX8_calls++;
	DX8Wrapper::texture_stage_state_changes++;
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, D3DTSS_TEXCOORDINDEX, 1);
	DX8Wrapper::Set_DX8_Texture_Stage_State(1, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
	DX8Wrapper::Set_DX8_Render_State(D3DRS_ALPHABLENDENABLE, FALSE);
	DX8Wrapper::Set_DX8_Render_State(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DX8Wrapper::Set_DX8_Render_State(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}
