// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O1 /EHs /D_BFME_RETAIL_TREE_INSERT_LAYOUT /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#define _STLP_BFME_LOWER_BOUND_EXTERN  // call retail's one __lower_bound<const size_t*> (vendor/stlport/stl/_hashtable.c)
#include <hash_set>
#include <cstddef>
// bfme link decl-only begin
namespace _STL { template <> void swap<_STLP_alloc_proxy<void **, void *, allocator<void *> > >(_STLP_alloc_proxy<void **, void *, allocator<void *> > &, _STLP_alloc_proxy<void **, void *, allocator<void *> > &); }
namespace _STL { template <> _Vector_base<void *, allocator<void *> >::_Vector_base(allocator<void *> const &); }
namespace _STL { template <> _Vector_base<void *, allocator<void *> >::_Vector_base(unsigned int, allocator<void *> const &); }
namespace _STL { template <> vector<void *, allocator<void *> >::vector(allocator<void *> const &); }
namespace _STL { template <> vector<void *, allocator<void *> >::vector(unsigned int, void *const &, allocator<void *> const &); }
namespace _STL { template <> _STLP_alloc_proxy<void **, void *, allocator<void *> >::~_STLP_alloc_proxy(); }
namespace _STL { template <> void vector<void *, allocator<void *> >::_M_clear(); }
namespace _STL { template <> void vector<void *, allocator<void *> >::_M_fill_insert(void **, unsigned int, void *const &); }
namespace _STL { template <> void vector<void *, allocator<void *> >::_M_insert_overflow(void **, void *const &, __true_type const &, unsigned int, bool); }
namespace _STL { template <> void vector<void *, allocator<void *> >::_M_set(void **, void **, void **); }
namespace _STL { template <> void ** allocator<void *>::allocate(unsigned int, void const *) const; }
namespace _STL { template <> unsigned int vector<void *, allocator<void *> >::capacity() const; }
namespace _STL { template <> allocator<void *> vector<void *, allocator<void *> >::get_allocator() const; }
namespace _STL { template <> void vector<void *, allocator<void *> >::insert(void **, unsigned int, void *const &); }
namespace _STL { template <> void vector<void *, allocator<void *> >::reserve(unsigned int); }
namespace _STL { template <> void vector<void *, allocator<void *> >::swap(vector<void *, allocator<void *> > &); }
// bfme link decl-only end
// Suppress this TU's non-retail copy of ?clear@?$vector@PAXV?$allocator@PAX@_STL@@@_STL@@QAEXXZ:
// the kept copy serves the link. Plain declaration-only form (no __imp_).
namespace _STL { template <> void vector<void *, allocator<void *> >::clear(); }
// Suppress this TU's non-retail copy of ??A?$vector@PAXV?$allocator@PAX@_STL@@@_STL@@QBEABQAXI@Z:
// the kept copy serves the link. Plain declaration-only form (no __imp_).
namespace _STL { template <> void *const &vector<void *>::operator[](size_t) const; }
// Suppress this TU's non-retail vector<void*> operator[] copy (family2-LK3 row 25):
// the retail copy serves the link. Plain declaration-only form (no __imp_).
namespace _STL {
template <> void *&_STL::vector<void*>::operator[](size_t);
}
// Suppress this TU's non-retail const-begin copy (row 47 family2-LK3): the
// /Od retail copy in stlport_vector_voidptr.cpp serves the link instead.
namespace _STL {
template <> vector<void *>::const_iterator _STL::vector<void *>::begin() const;
}

// map/set<unsigned> internals otherwise instantiate the less<unsigned>::operator()
// COMDAT (one byte shape per TU flags); a declaration-only specialization
// stops this TU emitting its copy so callers bind the kept copy.
// Plain (non-dllimport) form: no __imp_ reference is emitted.
namespace _STL {
template <> bool less<unsigned>::operator()(const unsigned &a, const unsigned &b) const;
}
// Suppress this TU's non-retail vector<void*> size copy (family2-LK3 row 17):
// the retail copy serves the link. Plain declaration-only form (no __imp_).
namespace _STL {
template <> size_t vector<void*>::size() const;
template <> void **vector<void*>::begin();
template <> void **vector<void*>::end();
}



struct Rva00058A86Record {char bytes[1];bool operator<(const Rva00058A86Record&)const;bool operator==(const Rva00058A86Record&)const;};
namespace _STL {template<>struct hash<Rva00058A86Record> {unsigned int operator()(const Rva00058A86Record&)const;};}
// Retail 0x00058A86 calls 0x00057FC1, the rowed clear of the pair-keyed
// hashtable over Rva00057FC1Record (StlSweepR3Rva00057FC1.cpp). Instantiating
// the whole set over this unit's own record left its operator== and hash
// unresolved and emitted a non-retail clear, so only the destructor is defined
// here and it calls that rowed clear by its own type.
struct Rva00057FC1Record { Rva00057FC1Record(); Rva00057FC1Record(const Rva00057FC1Record&); ~Rva00057FC1Record(); Rva00057FC1Record&operator=(const Rva00057FC1Record&); char bytes[1]; bool operator==(const Rva00057FC1Record&) const; bool operator<(const Rva00057FC1Record&) const; };
namespace _STL {template<>struct hash<Rva00057FC1Record> { unsigned int operator()(const Rva00057FC1Record&) const; };}
typedef _STL::hashtable<_STL::pair<Rva00057FC1Record const, Rva00057FC1Record>, Rva00057FC1Record, _STL::hash<Rva00057FC1Record>, _STL::_Select1st<_STL::pair<Rva00057FC1Record const, Rva00057FC1Record> >, _STL::equal_to<Rva00057FC1Record>, _STL::allocator<_STL::pair<Rva00057FC1Record const, Rva00057FC1Record> > > Rva00057FC1Table;
namespace _STL {
template <> void Rva00057FC1Table::clear();
typedef hashtable<Rva00058A86Record,Rva00058A86Record,hash<Rva00058A86Record>,_Identity<Rva00058A86Record>,equal_to<Rva00058A86Record>,allocator<Rva00058A86Record> > Rva00058A86Table;
template <> Rva00058A86Table::~hashtable()
{
    reinterpret_cast<Rva00057FC1Table *>(this)->clear();
}
template Rva00058A86Table::~hashtable();
}
