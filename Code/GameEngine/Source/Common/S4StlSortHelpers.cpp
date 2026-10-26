// cl: -GX- /Ireference/shims/bfme2_ascii
// stlport
// Final insertion-sort dispatcher for a string-keyed 20-byte record.
#include <algorithm>
#include "ascii_string.h"

struct S4SortElem20
{
    AsciiString m_name;
    char m_flag;
    void *m_tail[3];
    S4SortElem20(const S4SortElem20 &);
    ~S4SortElem20();
    S4SortElem20 &operator=(const S4SortElem20 &) throw();
};
struct S4Cmp002EB8E0
{
    void *m_state;
    bool operator()(const S4SortElem20 &left, const S4SortElem20 &right) const
    {
        return ((const StringBase<char> &)left.m_name).compare((const StringBase<char> &)right.m_name) < 0;
    }
};

namespace _STL
{
// Insertion helpers use the existing record lifetime and EH-enabled provider.
template <> void __insertion_sort<S4SortElem20 *, S4Cmp002EB8E0>(S4SortElem20 *, S4SortElem20 *, S4Cmp002EB8E0);

// The unguarded loop binds its existing rowed copy at 0x00337555.
template <> void __unguarded_insertion_sort_aux<S4SortElem20 *, S4SortElem20, S4Cmp002EB8E0>(S4SortElem20 *, S4SortElem20 *, S4SortElem20 *, S4Cmp002EB8E0);

template void __final_insertion_sort<S4SortElem20 *, S4Cmp002EB8E0>(S4SortElem20 *, S4SortElem20 *, S4Cmp002EB8E0);
}
