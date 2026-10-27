// cl: /DNDEBUG /MD /EHsc
// ??0Rva0043B196@@QAE@ABV0@@Z @0x0043B196 51B
// Evidence: calls rowed copy ctor ??0Rva00263895Member 0x28F68F; copies +0x7c +0x80 +0x84 then returns this ret4; callers 0x43B250 0x43B26D.
class Rva00263895Member
{
public:
	Rva00263895Member(const Rva00263895Member &other);
private:
	char m_data[0x7c];
};

class Rva0043B196
{
public:
	Rva0043B196(const Rva0043B196 &src);
private:
	Rva00263895Member m_00;
	unsigned int m_7c;
	unsigned int m_80;
	unsigned int m_84;
};

Rva0043B196::Rva0043B196(const Rva0043B196 &src)
	: m_00(src.m_00)
	, m_7c(src.m_7c)
	, m_80(src.m_80)
	, m_84(src.m_84)
{
}
