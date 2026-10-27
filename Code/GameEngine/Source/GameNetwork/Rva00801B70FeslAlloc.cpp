// cl: /GX-
// Allocate counted 0x30-stride array: clear, Gen007EFFC0 acquire, placement-new
// Rva00802380Owner per slot. Sibling of clear@Rva00801570 and of 0x00801BD0.

#include <new.h>

class GenAlloc
{
public:
	virtual void v0();
	virtual void v1();
	virtual void *allocate( unsigned int size, int flags );
	virtual void release( void *block, int flags );
};

extern GenAlloc *Gen007EFFC0();

class Rva00802380Owner
{
public:
	Rva00802380Owner();
};

class Rva00801570
{
public:
	void clear();
	void allocate( int count );

	Rva00802380Owner *m_array;
	int m_count;
};

void Rva00801570::allocate( int count )
{
	clear();
	m_array = (Rva00802380Owner *)Gen007EFFC0()->allocate( count * 0x30, 0 );
	for( int i = 0; i < count; ++i )
		new ( (char *)m_array + i * 0x30 ) Rva00802380Owner;
	m_count = count;
}
