// cl: /EHsc /MD
//
// ??0OldSchoolHelpBoxContentSource@@QAE@ABV0@@Z @0x00405B60 (45B): table 0x00838970
// is OldSchoolHelpBoxContentSource's (slot 3 is its WorldBuilder-named createContent).
// Derived copy ctor: calls base 0x00405A45 with (int)&o, installs vtable
// 0x00838970, copies 12 bytes at +4/+8/+0xC. Evidence: chain lane calls
// 0x00405A45, vtable store plus 3-dword copy, caller 0x00405D9D thunk.
extern "C" const void *const __identifier("??_7OldSchoolHelpBoxContentSource@@6B@")[];

class Rva00405A45
{
public:
	Rva00405A45(int dummy);
protected:
	const void *m_vtable;
};

class OldSchoolHelpBoxContentSource : public Rva00405A45
{
public:
	OldSchoolHelpBoxContentSource(const OldSchoolHelpBoxContentSource &other);
private:
	int m_4;
	int m_8;
	int m_c;
};

OldSchoolHelpBoxContentSource::OldSchoolHelpBoxContentSource(const OldSchoolHelpBoxContentSource &other) : Rva00405A45((int)&other)
{
	m_vtable = __identifier("??_7OldSchoolHelpBoxContentSource@@6B@");
	m_4 = other.m_4;
	m_8 = other.m_8;
	m_c = other.m_c;
}
