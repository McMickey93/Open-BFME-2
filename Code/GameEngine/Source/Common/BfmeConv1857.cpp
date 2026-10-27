extern "C" int __cdecl __identifier("?ji_00629892@@YAXXZ")(const char *text, const char *format, ...);

class BfmeOwnerYA
{
public:
	void bfmeParseYA(const char *text);

	unsigned char m_bfmeHeadYA[0x68];
	int m_bfmeValueYA;
};

void BfmeOwnerYA::bfmeParseYA(const char *text)
{
	switch (text[0])
	{
	case 'f':
		m_bfmeValueYA = -200;
		break;
	case 'r':
		m_bfmeValueYA = -201;
		break;
	case 'c':
		m_bfmeValueYA = -202;
		break;
	case 't':
		m_bfmeValueYA = -203;
		break;
	default:
		__identifier("?ji_00629892@@YAXXZ")(text, (char *)"%d", &m_bfmeValueYA);
		break;
	}
}

// Retail's call sites in this unit's matched rows land on bodies rowed under
// other spellings at the same addresses (same ABI). Bind the spellings used here.
