// cl: /MD
// ?rva001FD8DF@Rva001FD42B@@QAEPAU1@ABU1@@Z @0x001FD8DF 115B.
// Tree assign for the Rva001FD42B node family: self-check, clear via rowed
// rva001FD630, reset count, copy non-empty trees via rowed rva001FD751,
// fix leftmost via +8 and rightmost via +0xC, copy count, return this.
// Callers at 0x001FDBF2 0x001FE84C 0x002AFAB4; unblocks 0x001FE78E.
struct Rva001FD751Node
{
	unsigned char m_color;
	unsigned char m_pad01[3];
	Rva001FD751Node *m_parent;
	Rva001FD751Node *m_left;
	Rva001FD751Node *m_right;
	unsigned char m_value[8];
};

struct Rva001FD751
{
	Rva001FD751Node *rva001FD751(Rva001FD751Node *x, Rva001FD751Node *p);
};

#include "RTS/PlayerTemplateTreeView.h"

Rva001FD42B *Rva001FD42B::rva001FD8DF(const Rva001FD42B &other)
{
	if (this != &other) {
		rva001FD630();
		m_count = 0;
		Rva001FD42BNode *otherRoot = other.m_handle.m_header->m_parent;
		if (otherRoot == 0) {
			m_handle.m_header->m_parent = 0;
			m_handle.m_header->m_left = m_handle.m_header;
			m_handle.m_header->m_right = m_handle.m_header;
		} else {
			Rva001FD751 *self = (Rva001FD751 *)this;
			Rva001FD42BNode *hdr = m_handle.m_header;
			hdr->m_parent = (Rva001FD42BNode *)self->rva001FD751((Rva001FD751Node *)otherRoot, (Rva001FD751Node *)hdr);
			Rva001FD42BNode *x = m_handle.m_header->m_parent;
			while (x->m_left != 0)
				x = x->m_left;
			m_handle.m_header->m_left = x;
			x = m_handle.m_header->m_parent;
			while (x->m_right != 0)
				x = x->m_right;
			m_handle.m_header->m_right = x;
			m_count = other.m_count;
		}
	}
	return this;
}
