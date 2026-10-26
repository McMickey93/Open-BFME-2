#pragma once

class AsciiString;

// Lookup at 0x002000D7 tests the +4 override link, then uses the existing
// recursive worker. This is an accessed prefix, not the complete base class.
class Rva001E35DFView
{
public:
	const Rva001E35DFView *getFinalOverride() const;
	const Rva001E35DFView *finalOverride() const
	{
		if (m_next)
			return m_next->getFinalOverride();
		return this;
	}

private:
	void *m_vtbl;
	Rva001E35DFView *m_next;
};

// Skill selection at 0x00200157 reads fallback +0x14 and overrides +0x18..30.
// Neither lookup nor selection constructs or sizes this prefix view.
struct Rva002000D7Config : public Rva001E35DFView
{
	int rva00200157(const AsciiString &);
	char unknown08[0x14 - 8];
	int fallback, primary, men, elves, dwarves, isengard, mordor, wild;
};
