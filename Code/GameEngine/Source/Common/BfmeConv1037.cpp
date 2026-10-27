// platformsdk
// Wait on a handle and log on failure.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv1037.cpp); trimmed to the single T1
// body the sweep places.

// Matched connection-log bodies use the same getter for their second vtable slot.

#include <windows.h>

class BfmeLog1037
{
public:
	virtual void bfmeV01037();
	virtual void bfmeSay1037(char *m);
};

struct Rva007EB810Diag; Rva007EB810Diag *Rva007EB810Get();

class BfmeH1037
{
public:
	void bfmeGo1037H(void);

	char m_bfmePad[4];
	void *m_handle;
};

void BfmeH1037::bfmeGo1037H(void)
{
	if (WaitForSingleObject(m_handle, (unsigned long)-1) != 0)
		((BfmeLog1037 *)Rva007EB810Get())->bfmeSay1037((char *)"Error entering critical section\n");
}
