// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /arch:SSE /DNDEBUG /MD
// Rva0052BFE1::rva0052C7A2, retail 0x0052C7A2 (129 B): the campaign's record
// lookup by name, called by LivingWorldCampaignManager 0x003B8D4D. It walks
// the 184-byte records at +0x0C (the vector LivingWorldCampaign.cpp's
// 0x0052C0C8 also scans) and returns the first whose name (the shared name
// getter 0x00564DF2, by value) equals the key, else null. Names are
// structural.
#include "ascii_string.h"

class Rva00564DF2NameView
{
public:
	AsciiString rva00564DF2() const;	// 0x00564DF2
private:
	char m_bytes[0xB8];
};

// The receiver view LivingWorldCampaign.cpp declares: 184-byte records at +0x0C.
template<class T> class StringBase;

struct Rva005657FEElement;

struct Rva005657FEHolder;

struct CampaignEntry184 {unsigned char opaque[184];};

class Rva00564DF2NameView;

// The 184-byte records at +0x0C, read as name views by rva0052C7A2.
struct Rva0052BFE1Records
{
	Rva00564DF2NameView *m_start;
	Rva00564DF2NameView *m_finish;
	Rva00564DF2NameView *m_endOfStorage;

	unsigned int size() const { return m_finish - m_start; }
	Rva00564DF2NameView &operator[](unsigned int i) { return m_start[i]; }
};

class Rva0052BFE1 {
public: Rva005657FEElement *rva0052BFE1(const StringBase<char>&,const Rva005657FEHolder*);
public: Rva00564DF2NameView *rva0052C7A2(const AsciiString &name);
private: unsigned char prefix[12];union { struct { CampaignEntry184 *m_begin,*m_end; }; Rva0052BFE1Records m_records; };
};

Rva00564DF2NameView *Rva0052BFE1::rva0052C7A2(const AsciiString &name)
{
	for (unsigned int i = 0; i < m_records.size(); ++i)
	{
		if (m_records[i].rva00564DF2() == name)
			return &m_records[i];
	}
	return 0;
}
