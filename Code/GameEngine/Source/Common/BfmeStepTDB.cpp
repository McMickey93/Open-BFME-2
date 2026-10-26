// cl: /DNDEBUG /MD
// Open-BFME5 conversions.
//
// ?bfmeStepTDB@@YAXXZ, retail 0x0011DC20 (58B). Called once by the rowed
// bfmeGoTDB in BfmeConv1309.cpp. The bfme1 sweep maps that call to BFME1
// 0x904720 where bfmeApplyBQ and bfmeStepTDB are ICF twins, so this
// transcribes reference/open-bfme-1/Code/GameEngine/Source/Common/
// BfmeConv1753.cpp bfmeApplyBQ with BQ names swapped for TDB ones.
//
// The dispatch table type mirrors BfmeConv1309.cpp BfmeCallsTDB: slot 89
// is the set operation (slot 92 is the run operation rowed through
// GoTDB). The /G7 P4 tuning is load-bearing: it emits the retail
// cmp-byte-imm and add-mem-imm forms where /O1-/O2/G6 use test and inc.

struct BfmeObjTDB;

struct BfmeCallsTDB
{
	void *m_bfmeSlot89[89];
	void (__stdcall *m_bfmeSetTDB)(BfmeObjTDB *owner, void *item);
};

struct BfmeObjTDB
{
	BfmeCallsTDB *m_bfmeCalls;
};

struct BfmeStateTDB
{
	unsigned char m_bfmeHeadTDB[0x14];
	void **m_bfmeSourceTDB;
	char m_bfmeBusyTDB;
};

extern BfmeStateTDB *g_bfmeStateTDB;
// g_bfmeStateTDB: matched references place it at VA 0xdee858 (zero-filled .bss).
BfmeStateTDB * g_bfmeStateTDB;
extern int g_bfmeModeTDB;
// g_bfmeModeTDB: matched references place it at VA 0xdee844 (zero-filled .bss).
int g_bfmeModeTDB;
// The ledger's DX8Wrapper device (0x9EDA34, a protected static read through a
// derived view) and DX8 call counter (0x9EDA98).
struct IDirect3DDevice8;
class DX8Wrapper
{
protected:
	static IDirect3DDevice8 *D3DDevice;
};
extern unsigned number_of_DX8_calls;

struct BfmeDeviceTDB : DX8Wrapper
{
	static BfmeObjTDB *get() { return (BfmeObjTDB *)D3DDevice; }
};

// ?bfmeStepTDB@@YAXXZ
void bfmeStepTDB(void)
{
	if (g_bfmeStateTDB == 0)
		return;

	if (g_bfmeModeTDB != 0 && g_bfmeModeTDB != 2)
		return;

	if (g_bfmeStateTDB->m_bfmeBusyTDB)
		return;

	BfmeDeviceTDB::get()->m_bfmeCalls->m_bfmeSetTDB(BfmeDeviceTDB::get(),
		*g_bfmeStateTDB->m_bfmeSourceTDB);

	++number_of_DX8_calls;
}
