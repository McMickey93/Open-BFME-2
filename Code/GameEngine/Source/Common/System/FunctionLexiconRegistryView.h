#ifndef BFME_FUNCTION_LEXICON_REGISTRY_VIEW_H
#define BFME_FUNCTION_LEXICON_REGISTRY_VIEW_H

typedef bool Bool;
#include "subsystem_interface.h"

// Target receiver shared by the constructor at 0x002D22AC and validator at
// 0x002D22D5. Both access twelve table pointers following the 0x0C-byte
// SubsystemInterface base. Keep the existing structural name: this declaration
// does not identify it with FunctionLexicon or recover its remaining methods.
class Rva002D22CA : public SubsystemInterface
{
public:
	Rva002D22CA();
	virtual ~Rva002D22CA();
	bool rva002D22D5();

private:
	void *m_tables[12];
};

#endif
