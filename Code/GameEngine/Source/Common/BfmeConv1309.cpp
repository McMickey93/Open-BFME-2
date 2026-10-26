// Open-BFME5 conversions.

extern void *g_bfmeVftTDA[];

class BfmeSinkTDA
{
public:
	virtual void bfmeV0TDA() = 0;
	virtual void bfmeV1TDA() = 0;
	virtual void bfmeV2TDA() = 0;
	virtual void bfmeDropTDA(void *p, int f) = 0;
};

class GenAlloc; GenAlloc *Gen007EFFC0();

class BfmeThingTDA
{
public:
	void bfmeGoTDA();
	void *m_vtable;
	char m_bfmePad[8];
	void *m_bfmeItem;
};

void BfmeThingTDA::bfmeGoTDA()
{
	m_vtable = g_bfmeVftTDA;
	((BfmeSinkTDA *)Gen007EFFC0())->bfmeDropTDA(m_bfmeItem, 0);
}

struct BfmeCallsTDB;

struct BfmeObjTDB
{
	BfmeCallsTDB *m_bfmeCalls;
};

struct BfmeCallsTDB
{
	void *m_bfmeSlot0;
	void *m_bfmeSlot1;
	void *m_bfmeSlot2;
	void *m_bfmeSlot3;
	void *m_bfmeSlot4;
	void *m_bfmeSlot5;
	void *m_bfmeSlot6;
	void *m_bfmeSlot7;
	void *m_bfmeSlot8;
	void *m_bfmeSlot9;
	void *m_bfmeSlot10;
	void *m_bfmeSlot11;
	void *m_bfmeSlot12;
	void *m_bfmeSlot13;
	void *m_bfmeSlot14;
	void *m_bfmeSlot15;
	void *m_bfmeSlot16;
	void *m_bfmeSlot17;
	void *m_bfmeSlot18;
	void *m_bfmeSlot19;
	void *m_bfmeSlot20;
	void *m_bfmeSlot21;
	void *m_bfmeSlot22;
	void *m_bfmeSlot23;
	void *m_bfmeSlot24;
	void *m_bfmeSlot25;
	void *m_bfmeSlot26;
	void *m_bfmeSlot27;
	void *m_bfmeSlot28;
	void *m_bfmeSlot29;
	void *m_bfmeSlot30;
	void *m_bfmeSlot31;
	void *m_bfmeSlot32;
	void *m_bfmeSlot33;
	void *m_bfmeSlot34;
	void *m_bfmeSlot35;
	void *m_bfmeSlot36;
	void *m_bfmeSlot37;
	void *m_bfmeSlot38;
	void *m_bfmeSlot39;
	void *m_bfmeSlot40;
	void *m_bfmeSlot41;
	void *m_bfmeSlot42;
	void *m_bfmeSlot43;
	void *m_bfmeSlot44;
	void *m_bfmeSlot45;
	void *m_bfmeSlot46;
	void *m_bfmeSlot47;
	void *m_bfmeSlot48;
	void *m_bfmeSlot49;
	void *m_bfmeSlot50;
	void *m_bfmeSlot51;
	void *m_bfmeSlot52;
	void *m_bfmeSlot53;
	void *m_bfmeSlot54;
	void *m_bfmeSlot55;
	void *m_bfmeSlot56;
	void *m_bfmeSlot57;
	void *m_bfmeSlot58;
	void *m_bfmeSlot59;
	void *m_bfmeSlot60;
	void *m_bfmeSlot61;
	void *m_bfmeSlot62;
	void *m_bfmeSlot63;
	void *m_bfmeSlot64;
	void *m_bfmeSlot65;
	void *m_bfmeSlot66;
	void *m_bfmeSlot67;
	void *m_bfmeSlot68;
	void *m_bfmeSlot69;
	void *m_bfmeSlot70;
	void *m_bfmeSlot71;
	void *m_bfmeSlot72;
	void *m_bfmeSlot73;
	void *m_bfmeSlot74;
	void *m_bfmeSlot75;
	void *m_bfmeSlot76;
	void *m_bfmeSlot77;
	void *m_bfmeSlot78;
	void *m_bfmeSlot79;
	void *m_bfmeSlot80;
	void *m_bfmeSlot81;
	void *m_bfmeSlot82;
	void *m_bfmeSlot83;
	void *m_bfmeSlot84;
	void *m_bfmeSlot85;
	void *m_bfmeSlot86;
	void *m_bfmeSlot87;
	void *m_bfmeSlot88;
	void *m_bfmeSlot89;
	void *m_bfmeSlot90;
	void *m_bfmeSlot91;
	void (__stdcall *m_bfmeRunTDB)(BfmeObjTDB *o, int f);
};

// The ledger's globals this body reaches: DX8Wrapper's device (0x9EDA34),
// the DX8 call counter (0x9EDA98) and ShaderClass's dirty flag (0x9B621C).
// The two class statics are protected, so derived views read them.
struct IDirect3DDevice8;
class DX8Wrapper
{
protected:
	static IDirect3DDevice8 *D3DDevice;
};
class ShaderClass
{
protected:
	static bool ShaderDirty;
};
extern unsigned number_of_DX8_calls;

struct BfmeDeviceTDB : DX8Wrapper
{
	static BfmeObjTDB *get() { return (BfmeObjTDB *)D3DDevice; }
};
struct BfmeShaderTDB : ShaderClass
{
	static void setDirty() { ShaderDirty = true; }
};

void bfmeStepTDB(void);

void bfmeGoTDB(void)
{
	BfmeDeviceTDB::get()->m_bfmeCalls->m_bfmeRunTDB(BfmeDeviceTDB::get(), 0);
	++number_of_DX8_calls;
	bfmeStepTDB();
	BfmeShaderTDB::setDirty();
}
// ?g_bfmeVftTDA@@3PAPAXA: the global at VA 0xce157c is ?vftable_01129D30@@3HA.
#pragma comment(linker, "/alternatename:?g_bfmeVftTDA@@3PAPAXA=?vftable_01129D30@@3HA")
