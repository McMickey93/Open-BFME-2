// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <list>
// ?Run@Rva005B7DC3Box@@QAEXXZ @0x005B7DC3 54B: allocate-transform-consume.
// Raw-allocates 0x28 bytes through operator new at 0x2FDA0, then
// transforms non-null results through the pinned
// 0-arg method, stamps the block's first word with 4, and runs the +0x0C
// sub-object's pinned consumer on the block pointer. The null path leaves
// a null block (the store is unconditional). Targets from retail REL32.
// 0x005B72BE is the rowed Rva0040C1F0 constructor; the +0x0C consumer
// 0x0005548F is the rowed STLport list<int>::push_back.
class Rva0040C1F0
{
public:
	Rva0040C1F0() throw();
	int m_00;
	char m_pad[0x24];
};

namespace _STL
{
// Keep the established out-of-line list<int>::push_back provider.
template <> void list<int, allocator<int> >::push_back(const int &value);
}

struct Rva005B7DC3Box
{
	char pad[0xc];
	_STL::list<int, _STL::allocator<int> > m_0C;

	void Run();
};

void Rva005B7DC3Box::Run()
{
	Rva0040C1F0 *p = (Rva0040C1F0 *)::operator new(0x28);
	p = (p != 0) ? new (p) Rva0040C1F0 : 0;
	int out = (int)p;
	p->m_00 = 4;
	m_0C.push_back(out);
}

