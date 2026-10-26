// cl: /Os -Ireference/open-bfme-1/game/GameEngine/Source/Common

class BfmeThingCEE
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void vfn6(void *a, void *b);
	void doCall(void *a, char *b);
};

void BfmeThingCEE::doCall(void *a, char *b)
{
	if (b && a)
		vfn6(a, b + 0x38);
}
