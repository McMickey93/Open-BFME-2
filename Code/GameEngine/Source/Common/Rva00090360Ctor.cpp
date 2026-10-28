// cl: /MD
// ??0W3DDisplayStringManager@@QAE@XZ 33B @0x00090360: ctor calling rowed base 0x00262002 then storing vtable 0x007C7E20 then zeroing +0x14 (10 dwords) and +0x3C. Size 0x40 per caller alloc at 0x0004C55E. Evidence: rowed base callee plus vtable plus caller.
class Rva0026201C
{
public:
	Rva0026201C();
	virtual ~Rva0026201C();
protected:
	char m_pad04[12];
	struct Rva90381Node *m_head10;
};

class W3DDisplayStringManager : public Rva0026201C
{
public:
	W3DDisplayStringManager();
	virtual ~W3DDisplayStringManager();
	void freeDisplayString(struct Rva90381Node *string);
private:
	int m_14[10];
	int m_3C;
};

struct Rva90381Node
{
	virtual void *rva(int x);
	char m_pad04[8];
	Rva90381Node *m_next;
	Rva90381Node *m_prev;
};

struct Node00262045;
class Rva00262045
{
public:
	void unLink(struct Node00262045 *n);
};

#include <new>

// ?freeDisplayString@W3DDisplayStringManager@@QAEXPAURva90381Node@@@Z @0x00090381 47B
// Slot 15 offset 0x3C of vtable 0x007C7E20. Unlinks n via rowed 0x00262045,
// clears head at +0x10 if it equals n, releases via slot0 plus rowed delete 0x0002FD60.
// Callers in dtor 0x0009045E.
void W3DDisplayStringManager::freeDisplayString(struct Rva90381Node *string)
{
	if (string != 0) {
		((Rva00262045 *)this)->unLink((struct Node00262045 *)string);
		if (m_head10 == string)
			m_head10 = 0;
		operator delete(string->rva(0));
	}
}

W3DDisplayStringManager::W3DDisplayStringManager()
{
	for (int i = 0; i < 10; ++i)
		m_14[i] = 0;
	m_3C = 0;
}
