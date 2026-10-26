// cl: /DNDEBUG /MD /EHsc
// stlport
//
// Bodies ported from Open-BFME-1's
// Libraries/Source/WWVegas/WWLib/stlport_introsort_loop_s4sortelem20.cpp
// (donor revision 6d9434269164392c5ba62aaa7c15a86b5b020d76, donor flags plus
// /O1). Compiled that way each body below places uniquely on unclaimed
// game.dat .text by masked whole-.text search, and ./build.sh reproduces it
// byte for byte: ??$swap@US4SortElem20@@@_STL@@YAXAAUS4So 0x003373D9 (75B).
// Callee addresses are read off retail's call sites (reverse/symbols.csv).
// Only the placed bodies are carried; the donor's other definitions are
// omitted.

// Open-BFME: STLport 4.5.3 __introsort_loop over the twenty-byte S4 record
// used by the adjacent insertion, heap, partial-sort, and partition family.
// The record has a 12-byte vector tail. AsciiString copies use the private
// StringBase constructor; cleanup calls the existing AsciiString destructor.

#include <algorithm>

#include "../../../../../reference/shims/bfme2_ascii/ascii_string.h"


// Retail S4+0 is the AsciiString wrapper. Its four-byte StringBase subobject
// keeps the 20-byte record layout, while cleanup resolves the distinct QAE
// AsciiString destructor (RVA 0x005EE90 / ILT 0x0000D828), not the private
// StringBase<char> destructor.

// Retail's tail is the STLport vector whose assignment is rowed at 0x332217
// (StlSweepR3Rva00332217.cpp, Rva00332217Record elements). The assignment
// below calls that row; the tail's layout is the vector's three pointers.
struct Rva00332217Record;
namespace _STL
{
template <class T> class allocator;
template <class T, class A> class vector
{
public:
	vector &operator=(const vector &other);
};
}
typedef _STL::vector<Rva00332217Record, _STL::allocator<Rva00332217Record> >
	Rva00332217RecordVector;

class BfmeSortElem20Tail
{
private:
    Rva00332217Record *m_begin;
    Rva00332217Record *m_end;
    Rva00332217Record *m_capacity;
};

struct S4SortElem20
{
	AsciiString m_bfmeName;
	char m_bfmeFlag;
	BfmeSortElem20Tail m_bfmeTail;

	// Retail 0x3372EC is a 39-byte assignment body whose calls go to the
	// StringBase setter at 0x366F0 and tail setter at 0x332217. The call target
	// is pinned from the BFME1 donor's placed caller; the Ghidra boundary and
	// those callees are target evidence. Preserve the donor's field-wise copy:
	// compiler-generated whole-tail copying emits a different 38-byte body.
	// Copy construction and destruction stay out of line: retail's swap
	// calls 0x3371B1 and 0x3372B7, which this unit does not own.
	S4SortElem20(const S4SortElem20 &other);
	~S4SortElem20();

	S4SortElem20 &operator=(const S4SortElem20 &other)
	{
		m_bfmeName = other.m_bfmeName;
		m_bfmeFlag = other.m_bfmeFlag;
		*(Rva00332217RecordVector *)&m_bfmeTail =
			*(const Rva00332217RecordVector *)&other.m_bfmeTail;
		return *this;
	}
};

struct S4Cmp002EB8E0
{
	int m_bfmeSlot;

	bool operator()(const S4SortElem20 &left,
		const S4SortElem20 &right) const
	{
		return ((const StringBase<char> &)left.m_bfmeName).compare(
			(const StringBase<char> &)right.m_bfmeName) < 0;
	}
};

namespace _STL
{

// Partition emits the rowed swap, iterator swap and comparator without
// instantiating the unused introsort and partial-sort helper chain.
template S4SortElem20 *__unguarded_partition<S4SortElem20 *, S4SortElem20,
	S4Cmp002EB8E0>(S4SortElem20 *, S4SortElem20 *, S4SortElem20,
	S4Cmp002EB8E0);

// The insertion dispatch shares this record's out-of-line lifetime operations.
template void __insertion_sort<S4SortElem20 *, S4Cmp002EB8E0>(S4SortElem20 *, S4SortElem20 *, S4Cmp002EB8E0);

}
