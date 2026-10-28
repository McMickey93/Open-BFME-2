// STLport 4.5.3 set/tree copy structure, bound to BFME 2's existing workers.
// Retail allocates 108-byte nodes with 92-byte values; application identity
// and unconstrained element fields remain unknown.
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
#define _STLP_BFME_RB_MINMAX_IMPORT  // inline _Rb_tree_node_base::_S_minimum/_S_maximum without a COMDAT copy (vendor/stlport/stl/_tree.h)
#include <set>

// _Rb_tree_iterator comparisons otherwise instantiate the base-class
// operator!= COMDAT (one byte shape per TU flags); exact-match free
// overloads take those calls instead so this TU emits no external copy.
namespace _STL {
template <class _RbVal, class _RbLeft, class _RbRight>
static inline bool operator!=(const _Rb_tree_iterator<_RbVal, _RbLeft> &a,
                              const _Rb_tree_iterator<_RbVal, _RbRight> &b)
{ return a._M_node != b._M_node; }
}
struct Rva00501B33Element {
 Rva00501B33Element(); Rva00501B33Element(const Rva00501B33Element&);
 ~Rva00501B33Element(); Rva00501B33Element&operator=(const Rva00501B33Element&);
 char bytes[92];
};
bool operator<(const Rva00501B33Element&,const Rva00501B33Element&);
// The native header constructor at 0x004FF55E allocates a 108-byte node.
// Its argument is ignored, but occupies the same one-word stack slot.
class Rva004FF55E {
public:
    Rva004FF55E(unsigned);
    typedef _STL::_Rb_tree_node<Rva00501B33Element> Node;
    _STL::_STLP_alloc_proxy<Node *, Node, _STL::allocator<Node> > _M_header;
};
struct Rva00500BF5Node;
class Rva00500BF5Tree {
public:
    Rva00500BF5Node *copy(Rva00500BF5Node *, Rva00500BF5Node *);
};
namespace _STL {
template <> struct _Rb_tree_base<Rva00501B33Element, allocator<Rva00501B33Element> >
    : Rva004FF55E {
    typedef allocator<Rva00501B33Element> allocator_type;
    __forceinline _Rb_tree_base(const allocator_type &value)
        : Rva004FF55E(reinterpret_cast<unsigned>(&value)) {}
    allocator_type get_allocator() const { return allocator_type(); }
    ~_Rb_tree_base() {
        allocator<_Rb_tree_node<Rva00501B33Element> >().deallocate(_M_header._M_data, 1);
    }
};
// STLport's copy-constructor structure, with the native copy worker at
// 0x0050146E. Its node links match this view; its values are never accessed here.
typedef _Rb_tree<Rva00501B33Element, Rva00501B33Element,
                 _Identity<Rva00501B33Element>, less<Rva00501B33Element>,
                 allocator<Rva00501B33Element> > Rva00501B33Tree;
// This unit owns only construction; do not instantiate an unrelated
// element-destruction family while instantiating the set copy constructor.
template <> Rva00501B33Tree::~_Rb_tree();
template <> Rva00501B33Tree::_Rb_tree(const Rva00501B33Tree &source)
    : _Rb_tree_base<Rva00501B33Element, allocator<Rva00501B33Element> >(
          source.get_allocator()),
      _M_node_count(0), _M_key_compare(source._M_key_compare)
{
    if (source._M_root() == 0)
        _M_empty_initialize();
    else {
        _S_color(this->_M_header._M_data) = _S_rb_tree_red;
        _M_root() = reinterpret_cast<_Link_type>(
            reinterpret_cast<Rva00500BF5Tree *>(this)->copy(
                reinterpret_cast<Rva00500BF5Node *>(source._M_root()),
                reinterpret_cast<Rva00500BF5Node *>(this->_M_header._M_data)));
        _M_leftmost() = _S_minimum(_M_root());
        _M_rightmost() = _S_maximum(_M_root());
    }
    _M_node_count = source._M_node_count;
}
}
template _STL::set<Rva00501B33Element>::set(const _STL::set<Rva00501B33Element> &);
