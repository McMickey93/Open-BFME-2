// cl: /DNDEBUG /MD /EHsc
// stlport
//
// ?getNextTokenOrNull@INI@@QAEPBDPBD@Z, retail 0x002DEED, 170 bytes.
// Dedicated shard TU (same-TU visibility law: grafting into the sibling
// INI_getNextToken TU would recolor its getNextTokenOrNull call site).
//
// BFME2 keeps a token cursor over the line buffer: while the buffer holds
// text, strtok continues the current line; once exhausted, nextToken pulls
// the next line into a scratch token, banks it in m_tokens, and returns a
// pointer to the banked copy (or "" when the scratch is empty). On
// exhaustion the buffer is cleared and the shared strtok tail decides.
// ZH's donor is a plain static strtok wrapper (no buffer/vector), so only
// the separators default (m_seps at this+0x418, BFME1 +0x414) transfers.

#include <string.h>

#include "../../../../../reference/shims/bfme2_ascii/ascii_string.h"
#include <vector>

// The rowed out-of-line push_back (0x002DBE6): an explicit specialization
// declaration keeps the call instead of inlining STLport's in-class body.
namespace _STL
{
template <> void vector<AsciiString, allocator<AsciiString> >::push_back(const AsciiString &value);
}

// Member names follow INI.cpp's view of the same offsets.
class INI
{
public:
	const char *getNextTokenOrNull(const char *seps);

	char m_pad0[0x418];
	const char *m_seps;
	char m_pad1[0x86C - 0x41C];
	AsciiString m_str86C;
	_STL::vector<AsciiString> m_vec870;
};

// ?getNextTokenOrNull@INI@@QAEPBDPBD@Z
const char *INI::getNextTokenOrNull(const char *seps)
{
	if (seps == 0)
		seps = m_seps;
	if (!m_str86C.isEmpty()) {
		AsciiString token;
		if (m_str86C.nextToken(&token, seps)) {
			m_vec870.push_back(token);
			return m_vec870.back().str();
		}
		m_str86C.clear();
	}
	return strtok(0, seps);
}
