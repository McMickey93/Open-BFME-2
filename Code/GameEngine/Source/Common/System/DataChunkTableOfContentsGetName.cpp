// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD
//
// DataChunkTableOfContents::getName, retail 0x003070F1, 53 bytes.
//
// Ported from the Zero Hour reference
// (GameEngine/Source/Common/System/DataChunk.cpp, getName).
// Retail walks the Mapping list (next at +4, name at +8, id at +0xC)
// returning the name or AsciiString::TheEmptyString via the pinned
// AsciiString copy at 0x000365F0.
// Evidence: callers at 0x003074C9 0x003074FE 0x003077FE 0x0030789A
// 0x00307B06 pass DataChunkInput table IDs; empty path is TheEmptyString.

typedef unsigned int UnsignedInt;

#include "ascii_string.h"

// Use the seed DataChunk.cpp view: getName only reads these three fields;
// it neither constructs a Mapping nor dispatches through its virtual slot.
class Mapping
{
public:
	virtual void *deleteInstance(int flags);
	Mapping *m_next; ///< retail +0x04
	AsciiString m_name; ///< retail +0x08
	unsigned int m_id; ///< retail +0x0C
};

class DataChunkTableOfContents
{
public:
	AsciiString getName(UnsignedInt id);

private:
	Mapping *m_list; ///< retail this+0x00
};

AsciiString DataChunkTableOfContents::getName(UnsignedInt id)
{
	for (Mapping *mapping = m_list; mapping; mapping = mapping->m_next)
	{
		if (mapping->m_id == id)
			return mapping->m_name;
	}
	return AsciiString::TheEmptyString;
}
