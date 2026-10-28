// cl: /MD
// ?rva003FDE8C@LivingWorldArmyIcon@@QAEXE@Z @0x003FDE8C 33B: __thiscall void method iterating
// pointer range [+0x2C,+0x30) calling rowed Rva0056B929::rva0056B929(arg). Evidence:
// retail loads begin/end from ecx+0x2C/0x30 steps 4 derefs each and forwards stack arg;
// callers at 0x003193E6/0x003FE3A1/0x00538D51/0x00538D7E; callee row Rva0056B929.cpp;
// sibling 0x003FDE50 same shape with hoisted range loop. 0x003FE3A1 is in
// LivingWorldArmyIcon::rva003FE342 on its own this; 0x003193E6 passes an army's
// +0x88 icon pointer.
class Rva0056B929
{
public:
	void rva0056B929(unsigned char arg);
};

struct Rva003FDEADRefBlock;
struct Rva003FDEADParam38;
class LivingWorldArmyIcon
{
public:
	void rva003FDEAD();
	void rva003FDD41(int unused0,int unused1,int enabled);
	void rva003FDDAC();
	void rva003FDF1B();
	void rva003FDF8B();
	void rva003FDFFB();
	void rva003FDE8C(unsigned char arg);
	float rva003FE13E();
	char m_pad00[0x14];
private:
	Rva003FDEADRefBlock *m_p14; // +0x14
	float m_18; // +0x18
	float m_1C; // +0x1C
	char m_pad20[0xC];
	Rva0056B929 **m_begin; // +0x2C +0x2C
	Rva0056B929 **m_end; // +0x30 +0x30
	char m_pad34[0x4];
	Rva003FDEADParam38 *m_p38; // +0x38
	char m_pad3C[0x14];
	float m_50; // +0x50
	float m_54; // +0x54
	float m_58; // +0x58
};

void LivingWorldArmyIcon::rva003FDE8C(unsigned char arg)
{
	Rva0056B929 **first = m_begin;
	Rva0056B929 **last = m_end;
	for (; first != last; ++first)
		(*first)->rva0056B929(arg);
}
