// cl: /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii
//
// ??1Rva00496A63@@QAE@XZ, retail 0x00496A63, 53 bytes.
// Target evidence: called per element of the +0x18 vector by
// BannerCarrierUpdateModuleData dtor 0x00497056 and by the scalar wrapper
// 0x00496B2C; donor BFME1 BannerCarrierUpdateModuleDataDestructors proves a
// two-string element. Destroys AsciiStrings at +0 and +0x54 through
// StringBase<char>::releaseBuffer at 0x00036410; no vptr restores so non-virtual.

#include "ascii_string.h"

class Rva00496A63
{
public:
	~Rva00496A63();

private:
	AsciiString m_first; // +0
	unsigned char m_pad04[0x54 - 4];
	AsciiString m_second; // +0x54
};

Rva00496A63::~Rva00496A63()
{
}
