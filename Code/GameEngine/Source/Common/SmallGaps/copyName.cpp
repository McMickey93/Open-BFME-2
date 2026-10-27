// ?copyName@@YGXPAURva00808C20Entry@@PBU1@@Z
#include <string.h>
struct Rva00808C20Entry {
	char m_pad[0x10];
	char* m_name;
	unsigned int m_capacity;
	int m_18;
	int m_1c;
	unsigned int m_20;
};
void __stdcall copyName(Rva00808C20Entry* dst, const Rva00808C20Entry* src)
{
	dst->m_1c = src->m_1c;
	dst->m_20 = 0xc0000000;
	strncpy(dst->m_name, src->m_name, dst->m_capacity);
}
