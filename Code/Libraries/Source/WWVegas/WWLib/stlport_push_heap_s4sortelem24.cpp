// cl: /DNDEBUG /MD /EHsc
//
// _STL::__push_heap_aux over S4SortElem24 / S4Cmp009F4BF0 (STLport 4.5.3
// _heap.c): a by-value copy of last[-1] and a call to the already-landed
// __push_heap at 0x00627330. Its one caller is push_heap at 0x00627B10
// (StlSweepR3Rva00627B10.cpp), which passes the two null distance/value type
// tags as the fourth and fifth arguments.

struct S4SortElem24
{
	int m_key;
	int m_values[5];
};

struct S4Cmp009F4BF0
{
	bool operator()(const S4SortElem24 &a, const S4SortElem24 &b) const;
};

namespace _STL
{

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __push_heap(RandomAccessIterator first, Distance holeIndex,
	Distance topIndex, Tp val, Compare comp);

template <class RandomAccessIterator, class Compare, class Distance, class Tp>
void __push_heap_aux(RandomAccessIterator first, RandomAccessIterator last,
	Compare comp, Distance *, Tp *)
{
	__push_heap(first, Distance((last - first) - 1), Distance(0), Tp(*(last - 1)), comp);
}

template void __push_heap_aux<S4SortElem24 *, S4Cmp009F4BF0, int, S4SortElem24>(
	S4SortElem24 *, S4SortElem24 *, S4Cmp009F4BF0, int *, S4SortElem24 *);

}
