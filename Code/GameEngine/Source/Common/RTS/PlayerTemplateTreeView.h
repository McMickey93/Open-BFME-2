// TU-scoped tree view shared by the existing erase/clear, assignment and
// destructor owners. The matched bodies establish the pointer at +0 and count
// at +4. Keep the destructor donor's header handle: it supplies retail's EH
// cleanup when clear throws. This does not establish an original class name.
#ifndef BFME_PLAYER_TEMPLATE_TREE_VIEW_H
#define BFME_PLAYER_TEMPLATE_TREE_VIEW_H

extern "C" void __cdecl free(void *block) throw(...);

struct Rva001FD42BNode
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva001FD42BNode *m_parent;
	Rva001FD42BNode *m_left;
	Rva001FD42BNode *m_right;
	unsigned char m_value[8];
};

struct Rva001FD42BHeaderHandle
{
	~Rva001FD42BHeaderHandle()
	{
		if (m_header)
			free(m_header);
	}
	Rva001FD42BNode *m_header;
};

struct Rva001FD42B
{
	void rva001FD42B(Rva001FD42BNode *x);
	void rva001FD630();
	Rva001FD42B *rva001FD8DF(const Rva001FD42B &other);
	~Rva001FD42B();
	Rva001FD42BHeaderHandle m_handle;
	unsigned int m_count;
};

#endif
