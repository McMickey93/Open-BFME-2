// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#include <algorithm>

// 0x00218FC2 sorts the 16-byte font-substitution records (MixFileCreator::FileInfoStruct's
// layout) for parseFontSubstitutionDefinition. Its two callees are rowed in GameFont.cpp:
// 0x00218E09 as __introsort_loop over Rva00218E09Record with less<>, and 0x0021889A as
// Rva0021889AFinalSort over Q3SortElem16. This unit emits only sort itself and calls
// those rowed definitions, so it instantiates none of the record's members.
struct Rva00218FC2Record { char bytes[16]; };
struct Rva00218FC2RecordCompare { void *m_state; };

struct Rva00218E09Record;
struct Q3SortElem16;
struct Q3SortCompare { void *m_state; };
void __cdecl Rva0021889AFinalSort(Q3SortElem16 *first, Q3SortElem16 *last, Q3SortCompare comp);

namespace _STL {
template <>
void __introsort_loop<Rva00218E09Record *, Rva00218E09Record, int, less<Rva00218E09Record> >(
	Rva00218E09Record *first, Rva00218E09Record *last, Rva00218E09Record *,
	int depth_limit, less<Rva00218E09Record> comp);

template <>
void sort<Rva00218FC2Record *, Rva00218FC2RecordCompare>(Rva00218FC2Record *first,
	Rva00218FC2Record *last, Rva00218FC2RecordCompare comp)
{
	if (first != last) {
		__introsort_loop((Rva00218E09Record *)first, (Rva00218E09Record *)last,
			(Rva00218E09Record *)0, __lg(last - first) * 2,
			*(less<Rva00218E09Record> *)&comp);
		Rva0021889AFinalSort((Q3SortElem16 *)first, (Q3SortElem16 *)last,
			*(Q3SortCompare *)&comp);
	}
}
}
