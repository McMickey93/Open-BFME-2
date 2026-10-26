// cl: /MD
// Sibling of rowed _M_construct_null_aux at 0x00019950 (12B), matched on
// mnemonic shape only -- the identity differs. Retail 0x00038780 (13B)
// stores the byte 1 at +0x9F58 of the Debug singleton whose pointer lives at
// 0x00DE0880 (theDebug, defined by DebugPreStaticInit.cpp); read through a
// view of the real global.
class Debug;
extern Debug *theDebug;

struct Gen_00DE0880
{
	char m_pad[0x9f58];
	unsigned char m_flag;
};

void __cdecl rva0038780()
{
	((Gen_00DE0880 *)theDebug)->m_flag = 1;
}
