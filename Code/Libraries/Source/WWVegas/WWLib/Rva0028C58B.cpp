// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP=
// ?rva0028C58B@Rva0028C58B@@QAEPAV1@XZ @0x0028C58B 20B: memset this 0x14 to 0 and return this. Evidence: retail pushes 0x14 0 this to rowed memset thunk 0x006291AE then mov eax esi; caller at 0x0029915A; neighbours share same cl flags.
// memset is msvcr71's, called through its import thunk at 0x006291AE
// rather than expanded inline: <string.h>'s memset with
// #pragma function(memset).
#include <string.h>
#pragma function(memset)

class Rva0028C58B
{
public:
	Rva0028C58B *rva0028C58B();
private:
	char m_pad[0x14];
};

Rva0028C58B *Rva0028C58B::rva0028C58B()
{
	memset(this, 0, 0x14);
	return this;
}
