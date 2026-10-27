// flags: region default (reverse/retail_inventory/flag_regions.csv)
// ??0Rva0057ACEB@@QAE@PBURva0057ACEBData@@@Z @0x0057ACEB 59B
// Refcounted holder ctor: news 0x10 impl with vtable 0x0086F090 and copies 8B arg.
// Evidence: stores vtable at new obj, callers pass 8B struct ptr with ecx=temp.
extern "C" const void *const __identifier("??_7Rva0057AA1F@@6B@")[];
#include <new>
struct Rva0057ACEBData
{
	int m_0;
	int m_4;
};
class Rva0057ACEBImpl
{
public:
	void *m_vtbl;
	int m_ref;
	int m_a;
	int m_b;
	Rva0057ACEBImpl(const Rva0057ACEBData *initialData)
	{
		m_ref = 0;
		*(const void * *)this = __identifier("??_7Rva0057AA1F@@6B@");
		m_a = initialData->m_0;
		m_b = initialData->m_4;
	}
};
class Rva0057ACEB
{
public:
	Rva0057ACEB(const Rva0057ACEBData *initialData);
private:
	Rva0057ACEBImpl *m_impl;
};
Rva0057ACEB::Rva0057ACEB(const Rva0057ACEBData *initialData)
{
	Rva0057ACEBImpl *impl = new Rva0057ACEBImpl(initialData);
	m_impl = impl;
	if (impl)
		++impl->m_ref;
}

