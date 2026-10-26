// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common
struct BfmeBaseFAC
{
	virtual void bfmeV0();
	virtual void bfmeV1();
	virtual void bfmeV2();
	virtual void bfmeV3();
	virtual void bfmeV4();
	virtual void bfmeV5();
	virtual void bfmeV6();
	virtual void bfmeV7();
	virtual void bfmeV8();
	virtual void bfmeV9();
	virtual void bfmeV10();
	virtual void bfmeV11();
	virtual void bfmeV12();
	virtual void bfmeV13();
	virtual void bfmeVirt14FAC(void *a);
};

struct BfmeThingFAC
{
	void bfmeGoFAC(void *a);
	unsigned char m_bfmeHead[4];
	BfmeBaseFAC *m_bfmeP;
};

void BfmeThingFAC::bfmeGoFAC(void *a)
{
	(*(BfmeBaseFAC **)((char *)this - 8))->bfmeVirt14FAC(a);
	if (m_bfmeP)
		m_bfmeP->bfmeVirt14FAC(a);
}
