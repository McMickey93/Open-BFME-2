// cl: /EHs /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP=
// stlport
// _Rb_tree<unsigned, pair<const unsigned, WeaponTemplateSetHead> >::_M_insert 0x004637B7 136B
// _Rb_tree::_M_insert for the Rva0046267A (0x50B) red-black tree: create the
// node through the member create_node 0x4634BA, link it left/right of pos,
// fix up the header root/leftmost/rightmost, then rebalance with rowed 0x25490
// and bump the node count at this+4. Key is the unsigned int at value +0
// (node +0x10); retail branches with jb, so the comparator is less<unsigned>.
// Evidence: 136B shape identical to the landed map<int,int> _M_insert 0x38341E
// except the 0x4637DA jl->jb; callees 0x4634BA and 0x25490 both rowed; caller
// 0x4638A1. Native create ignores ECX and pops its value argument (RET 4).
// A four-byte member-call view retains the native receiver reload while naming
// the existing __stdcall provider, without introducing another function name.
// Its callers 0x0046383F and 0x00463E4D are that tree's insert_unique pair
// (map<unsigned, WeaponTemplateSetHead>, 0x00464431); the create call stays on
// the rowed Rva004634BACreate provider.
#include <map>

class WeaponTemplateSetHead
{
public:
	__declspec(nothrow) WeaponTemplateSetHead(const WeaponTemplateSetHead &other);
private:
	unsigned int m_bits[19];
};

class Rva0046267A;
struct Rva004634BANode;

class Rva00463782
{
public:
	_STL::_Rb_tree_node_base *m_header;
	unsigned int m_count;
};

typedef _STL::pair<const unsigned int, WeaponTemplateSetHead> WeaponTemplateSetHeadPair;
typedef _STL::_Rb_tree<unsigned int, WeaponTemplateSetHeadPair,
	_STL::_Select1st<WeaponTemplateSetHeadPair>, _STL::less<unsigned int>,
	_STL::allocator<WeaponTemplateSetHeadPair> > WeaponTemplateSetHeadTree;

Rva004634BANode *__stdcall Rva004634BACreate(const Rva0046267A &);
union Rva004637B7CreateCall
{
 Rva004634BANode *(__stdcall *target)(const Rva0046267A &);
 Rva004634BANode *(Rva00463782::*member)(const Rva0046267A &);
};
typedef char Rva004637B7CreateCallWidth[sizeof(Rva004637B7CreateCall)==4 ? 1 : -1];

namespace _STL {
// ?_M_insert@?$_Rb_tree@IU?$pair@$$CBIVWeaponTemplateSetHead@@@_STL@@U?$_Select1st@U?$pair@$$CBIVWeaponTemplateSetHead@@@_STL@@@2@U?$less@I@2@V?$allocator@U?$pair@$$CBIVWeaponTemplateSetHead@@@_STL@@@2@@_STL@@AAE?AU?$_Rb_tree_iterator@U?$pair@$$CBIVWeaponTemplateSetHead@@@_STL@@U?$_Nonconst_traits@U?$pair@$$CBIVWeaponTemplateSetHead@@@_STL@@@2@@2@PAU_Rb_tree_node_base@2@0ABU?$pair@$$CBIVWeaponTemplateSetHead@@@2@0@Z
template <>
WeaponTemplateSetHeadTree::iterator WeaponTemplateSetHeadTree::_M_insert(
	_Rb_tree_node_base *x, _Rb_tree_node_base *pos,
	const WeaponTemplateSetHeadPair &v, _Rb_tree_node_base *w)
{
	Rva00463782 *self = (Rva00463782 *)this;
	const Rva0046267A *val = (const Rva0046267A *)&v;
	Rva004637B7CreateCall create;
	create.target = Rva004634BACreate;
	_STL::_Rb_tree_node_base *node;
	if (pos == self->m_header || (w == 0 && (x != 0 || *(const unsigned *)val < *(const unsigned *)((const char *)pos + 0x10))))
	{
		node = (_STL::_Rb_tree_node_base *)(self->*create.member)(*val);
		pos->_M_left = node;
		if (pos == self->m_header)
		{
			self->m_header->_M_parent = node;
			self->m_header->_M_right = node;
		}
		else if (pos == self->m_header->_M_left)
			self->m_header->_M_left = node;
	}
	else
	{
		node = (_STL::_Rb_tree_node_base *)(self->*create.member)(*val);
		pos->_M_right = node;
		if (pos == self->m_header->_M_right)
			self->m_header->_M_right = node;
	}
	node->_M_left = 0;
	node->_M_right = 0;
	node->_M_parent = pos;
	_STL::_Rb_global<bool>::_Rebalance(node, self->m_header->_M_parent);
	++self->m_count;
	return iterator((_Link_type)node);
}
}
