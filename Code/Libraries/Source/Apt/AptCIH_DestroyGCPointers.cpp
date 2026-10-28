// cl: /DNDEBUG /MD
//
// AptCIH::DestroyGCPointers at 0x006E0460, 50 bytes. Address-derived cleanup
// worker: it releases the object at +0x4C through vtable slot 2 (skipping the
// 0xBAADF00D uninitialised fill), releases the object at +0x48 through vtable
// slot 1, nulls +0x48, then tail-jumps the 5-byte flag setter at 0x006DBD80
// (or dword ptr [ecx+4],8; ret). No original identity is claimed.

class Rva006E0460Ref
{
public:
	virtual void vf0();
	virtual void vf1(); // slot 1  (vtable +4)
	virtual void vf2(); // slot 2  (vtable +8)
};

class AptCIH
{
public:
	void DestroyGCPointers();
	void rva006dbd80();

private:
	char m_pad48[0x48];
	AptCIH *m_parent; // +0x48
	void *m_4C; // +0x4C
};

void AptCIH::DestroyGCPointers()
{
	if (m_4C != 0 && m_4C != (Rva006E0460Ref *)0xBAADF00D)
		((Rva006E0460Ref *)m_4C)->vf2();
	if (m_parent != 0)
		((Rva006E0460Ref *)m_parent)->vf1();
	m_parent = 0;
	rva006dbd80();
}
