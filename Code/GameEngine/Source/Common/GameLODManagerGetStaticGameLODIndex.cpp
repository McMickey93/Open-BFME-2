// cl: /EHsc /DNDEBUG /MD
//
// ?getStaticGameLODIndex@GameLODManager@@QAEHVAsciiString@@@Z, retail
// 0x00202C30, 70 bytes. Dedicated TU (abuts the audio sibling at 0x202C76).
//
// Static-LOD twin of getAudioLODIndex (GameLODManagerGetAudioLODIndex.cpp):
// five-entry name table walked with compareNoCase returning the index, -1 on
// miss. No debug-reporting tail; the by-value parameter is destroyed here at
// the end (MSVC callee-destroys rule), which is the trailing releaseBuffer
// call. Retail facts:
// - compareNoCase: the canonical AsciiString forwards to the declared-only
//   StringBase<char> 1-arg body (retail calls 0x00037980), declared throw()
//   below.
// - The parameter destruction is the canonical ~AsciiString's single
//   releaseBuffer call (rowed 0x36410).
// - The table base (retail 0xDB969C) is DIR32-masked, so any extern spelling
//   verifies; the entry values never enter .text. Retail strings:
//   VeryLow/Low/Medium/High/VeryHigh.
// - /EHsc (not the sibling's /GX-): the by-value parameter forces the EH
//   prolog/teardown pair retail shows. No unwind states: parameters carry
//   none, only stack temps would (winSetText precedent).

typedef int Int;
typedef bool Bool;

#include "../../../../reference/shims/bfme2_ascii/ascii_string.h"

// throw(): a throwing leaf callee forces an `and [ebp-4],0` state init
// retail lacks; the leaf compare (0x00037980) cannot throw.
template <> int StringBase<char>::compareNoCase(const char *other) const throw();

class GameLODManager
{
public:
	Int getStaticGameLODIndex(AsciiString name);
};

// Retail table at 0xDB969C: VeryLow, Low, Medium, High, VeryHigh.
const char *bfmeStaticLODNames[5] = { "VeryLow", "Low", "Medium", "High", "VeryHigh" };

// ?getStaticGameLODIndex@GameLODManager@@QAEHVAsciiString@@@Z
Int GameLODManager::getStaticGameLODIndex(AsciiString name)
{
	for (Int i = 0; i < 5; ++i)
	{
		if (name.compareNoCase(bfmeStaticLODNames[i]) == 0)
			return i;
	}

	return -1;
}
