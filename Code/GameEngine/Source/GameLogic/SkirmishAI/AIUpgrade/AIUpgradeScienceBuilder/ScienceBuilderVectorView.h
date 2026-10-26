#pragma once

// Accessed vector prefix shared by this builder's registration and object
// pruning bodies. Keep the existing STLport template identities: declarations
// only, with no replacement template implementations or providers.
namespace _STL
{

template<class T> class allocator
{
};

template<class T, class A = allocator<T> > class vector
{
public:
	void push_back(const T &value);
	T *erase(T *pos);
	T *erase(T *first, T *last);
	T *m_begin, *m_end, *m_limit;
};

}
