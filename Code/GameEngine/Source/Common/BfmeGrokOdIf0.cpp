// cl: /Od

// The global at 0x009DF574 is STLport's node-allocator lock,
// _STL::_Node_Alloc_Lock<true, 0>::_S_lock, defined by
// node_alloc_M_deallocateThunk.cpp. The call at 0x00013260 is the matched
// _STLP_mutex_base::_M_initialize body (zeroes the first dword); reach it
// through a view cast of the real global.

namespace _STL
{
class _STLP_mutex_base
{
public:
	void _M_initialize();
};

class NodeAllocMutex;

template <bool __threads, int __inst>
class _Node_Alloc_Lock
{
public:
	static NodeAllocMutex _S_lock;
};
}

class BfmeIf1VMK
{
public:
	void grokIf1();
};

void BfmeIf1VMK::grokIf1()
{
	int n1;
	if (1)
		((_STL::_STLP_mutex_base *)&_STL::_Node_Alloc_Lock<true, 0>::_S_lock)->_M_initialize();
}
