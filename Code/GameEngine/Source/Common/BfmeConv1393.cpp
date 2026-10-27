#include <new>

extern "C" int __identifier("??_7AABTreeClass@@6B@")[];
extern "C" int __identifier("??_7RefCountClass@@6B@")[];

class BfmeThingVJS
{
public:
	void bfmeClearVJS(void);
	void *m_bfmeVfptr;
	int m_bfme04;
	int m_bfme08;
	void *m_bfme0c;
	int m_bfme10;
	void *m_bfme14;
	void *m_bfme18;
};

// ?bfmeClearVJS@BfmeThingVJS@@QAEXXZ
void BfmeThingVJS::bfmeClearVJS()
{
	m_bfmeVfptr = __identifier("??_7AABTreeClass@@6B@");
	m_bfme08 = 0;
	if (m_bfme0c)
	{
		::operator delete[](m_bfme0c);
		m_bfme0c = 0;
	}
	m_bfme10 = 0;
	if (m_bfme14)
	{
		::operator delete[](m_bfme14);
		m_bfme14 = 0;
	}
	m_bfmeVfptr = __identifier("??_7RefCountClass@@6B@");
	if (m_bfme18)
		m_bfme18 = 0;
}

// Both tables are already emitted in the tree: RVA 0x007D5F00 as
// ??_7AABTreeClass@@6B@ (2 slots) and RVA 0x007C650C as ??_7RefCountClass@@6B@
// (12 slots, eight of them the debug purecall). This unit only stores them.
