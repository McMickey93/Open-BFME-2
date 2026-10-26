// cl: /Od /Gy

// The two locks at 0x009DF570/0x009DF574 are STLport's
// _STL::_Node_Alloc_Lock<false, 0>::_S_lock and <true, 0>::_S_lock; the
// called body is the matched _STLP_mutex_base::_M_acquire_lock. Reach it
// through a view cast of the real statics.
namespace _STL
{
class _STLP_mutex_base
{
public:
	void _M_acquire_lock();
};

class NodeAllocMutex;

template <bool __threads, int __inst>
class _Node_Alloc_Lock
{
public:
	static NodeAllocMutex _S_lock;
};
}

class BfmeThingVLY
{
public:
	BfmeThingVLY *bfmeCtorVLY();
};

BfmeThingVLY *BfmeThingVLY::bfmeCtorVLY()
{
	if (0)
		((_STL::_STLP_mutex_base *)&_STL::_Node_Alloc_Lock<false, 0>::_S_lock)->_M_acquire_lock();
	return this;
}


class BfmeThingVLZ
{
public:
	BfmeThingVLZ *bfmeCtorVLZ();
};

BfmeThingVLZ *BfmeThingVLZ::bfmeCtorVLZ()
{
	if (1)
		((_STL::_STLP_mutex_base *)&_STL::_Node_Alloc_Lock<true, 0>::_S_lock)->_M_acquire_lock();
	return this;
}
