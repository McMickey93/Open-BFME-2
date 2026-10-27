// The table this reset installs is 0x00816778 (retail stores 0x00C16778). The
// data ledger names it ??_7Rva00360243@@6B@ (bfmeVftSF is one of its aliases);
// Rva00360474Ctor.cpp, whose rowed ctor 0x00360243 installs it, defines it.
extern "C" const void *const __identifier("??_7Rva00360243@@6B@")[];

class BfmeThingSF
{
public:
	void bfmeTailSF();
	void bfmeResetSF();
	void *m_bfmeVft;
	unsigned char m_bfmeGap[8];
	void *m_bfmeOne;
	unsigned char m_bfmeGapTwo[0x20];
	void *m_bfmeTwo;
	void *m_bfmeThree;
};

void BfmeThingSF::bfmeResetSF()
{
	m_bfmeVft = (void *)__identifier("??_7Rva00360243@@6B@");
	m_bfmeOne = 0;
	m_bfmeTwo = 0;
	m_bfmeThree = 0;
	bfmeTailSF();
}
