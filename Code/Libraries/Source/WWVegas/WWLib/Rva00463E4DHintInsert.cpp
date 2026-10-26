// cl: /O1 /G7 /EHs /D_BFME_RETAIL_TREE_INSERT_LAYOUT /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// STLport 4.5.3 _Rb_tree::insert_unique(hint, v) of the map<unsigned, WeaponTemplateSetHead>
// tree, 0x00463E4D 294 bytes, from the template. Target facts: its only caller
// 0x00464431 is that map's insert (called so by 0x00464923); it calls _M_insert
// 0x004637B7, insert_unique(v) 0x0046383F and the rowed increment/decrement
// 0x24250/0x242C0; the jb/jae compares fix the key as unsigned. The value's
// 0x4C-byte layout stays opaque. Flags follow the same-shape int-key body at
// 0x0046444E (StlSweepR3Rva0046444E.cpp).
#include <map>

namespace _STL {
template <> __declspec(dllimport) __forceinline
bool less<unsigned int>::operator()(const unsigned int &left, const unsigned int &right) const
{ return left < right; }
}

class WeaponTemplateSetHead
{
public:
	__declspec(nothrow) WeaponTemplateSetHead(const WeaponTemplateSetHead &other);
private:
	unsigned int m_bits[19];
};

typedef _STL::pair<const unsigned int, WeaponTemplateSetHead> WeaponTemplateSetHeadPair;
typedef _STL::_Rb_tree<unsigned int, WeaponTemplateSetHeadPair,
	_STL::_Select1st<WeaponTemplateSetHeadPair>, _STL::less<unsigned int>,
	_STL::allocator<WeaponTemplateSetHeadPair> > WeaponTemplateSetHeadTree;

// bfme link decl-only begin
namespace _STL {
template <> WeaponTemplateSetHeadTree::iterator WeaponTemplateSetHeadTree::_M_insert(_Rb_tree_node_base *, _Rb_tree_node_base *, const WeaponTemplateSetHeadPair &, _Rb_tree_node_base *);
template <> _STL::pair<WeaponTemplateSetHeadTree::iterator, bool> WeaponTemplateSetHeadTree::insert_unique(const WeaponTemplateSetHeadPair &);
}
// bfme link decl-only end

template WeaponTemplateSetHeadTree::iterator WeaponTemplateSetHeadTree::insert_unique(WeaponTemplateSetHeadTree::iterator, const WeaponTemplateSetHeadPair &);
