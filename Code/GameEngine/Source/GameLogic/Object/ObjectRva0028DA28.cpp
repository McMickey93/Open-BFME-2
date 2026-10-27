// cl: /DNDEBUG /MD
// ?rva0028DA28@Object@@QAEXXZ @0x0028DA28 63B: __thiscall void clears +0x284 0x80 via memset then walks null-terminated ptr array at +0x244 calling virtual slot 0x28 and Rva004CE245 on non-zero returns. Evidence: rowed memset thunk ji_006291ae plus rowed Rva004CE245 0x004CE245 plus prev ObjectRva0028D9E5 plus +0x284 bits.
// memset is msvcr71's, called through its import thunk at 0x006291AE
// rather than expanded inline: <string.h>'s memset with
// #pragma function(memset).
#include <string.h>
#pragma function(memset)

void Rva004CE245(void *p);

class ElemProvider
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void *slot10();
};

class Object
{
public:
	void rva0028DA28();
private:
	char m_pad00[0x244];
	void **m_arr244;
	char m_pad248[0x284 - 0x248];
	unsigned char m_clr284[0x80];
};

void Object::rva0028DA28()
{
	memset(m_clr284, 0, 0x80);
	void **arr = m_arr244;
	while (*arr != 0)
	{
		void *e = *arr;
		ElemProvider *elemProvider = (ElemProvider *)((char *)e + 0xc);
		void *r = elemProvider->slot10();
		if (r != 0)
			Rva004CE245(r);
		++arr;
	}
}
