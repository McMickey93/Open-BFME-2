// ??0Made002CC774@@QAE@XZ
// cl: /Ireference/shims/bfme2_ascii /MD /EHsc /DNDEBUG
// ??0Made002CC774@@QAE@XZ, retail 0x00509522 38B.
// Base Rva00507823 plus vtable 0x00864520 plus three members at
// +0x128/+0x12c/+0x130 zeroed. AsciiString at +0x130 is the non-trivial
// member, so the derived vptr store lands first. Made002CCBCA precedent.
#include "ascii_string.h"

class Rva00507823
{
public:
	Rva00507823();
	virtual ~Rva00507823();
	char m_pad04[0x124];
};
struct Input005093C6;
struct Coord3D;
class WeaponTemplate;
class Made002CC774 : public Rva00507823
{
public:
	void rva005093C6(Input005093C6 *input, const Coord3D *position);
	Made002CC774();
private:
	WeaponTemplate *m_weapon; // +0x128
	unsigned int m_lifetime; // +0x12C
	AsciiString m_130; // +0x130
};
Made002CC774::Made002CC774()
{
    m_weapon = 0;
    m_lifetime = 0;
}
