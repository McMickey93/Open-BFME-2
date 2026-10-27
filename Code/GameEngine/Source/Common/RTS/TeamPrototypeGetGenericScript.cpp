// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?getGenericScript@TeamPrototype@@QAEPAVScript@@HPAVAsciiString@@@Z, retail
// 0x0039EC1E (187 bytes).
// Identity (target): WorldBuilder's debug Team.cpp:1372 body
// TeamPrototype::getGenericScript ("We attempted to find a generic script,
// but couldn't.") has retail's loop and callee order: the ScriptEngine
// lookup 0x003573C4 (prototype owner name +0x10, script name, out string)
// then Script::duplicate (0x003B7550).
// Donor (Zero Hour TeamPrototype::getGenericScript): fill the 32 run copies
// once (flag +0x28), then return the requested one. BFME 2 deltas (target):
// the lookup also yields a string, kept per slot at +0xAC when a copy was
// made and handed back through the second argument; the names are at +0x244
// and the copies at +0x2C.
#include "ascii_string.h"

class Script
{
public:
	Script *duplicate() const;
	void *getAction() const { return m_action; }

private:
	unsigned char m_pad00[0x34];
	void *m_action; // +0x34
};

// The (scope; name) script lookup 0x003573C4, rowed under its placeholder owner.
class BfmeRoomZC;
class Rva003573C4Owner
{
public:
	void *rva003573C4(const AsciiString &owner, const BfmeRoomZC &name, void *outName);
};
class ScriptEngine;

extern ScriptEngine *TheScriptEngine;

enum { MAX_GENERIC_SCRIPTS = 32 };

// The generic script names of the prototype's team template (+0x12C), as
// the Team.cpp seed's TeamTemplateInfo names them.
struct TeamTemplateGenericScriptsView
{
	unsigned char m_pad000[0x118];
	AsciiString m_teamGenericScripts[MAX_GENERIC_SCRIPTS]; // +0x118, prototype +0x244
};

class TeamPrototype
{
public:
	Script *getGenericScript(int scriptToRetrieve, AsciiString *outName);

private:
	unsigned char m_pad00[0x10];
	AsciiString m_ownerName; // +0x10
	unsigned char m_pad14[0x28 - 0x14];
	bool m_retrievedGenericScripts; // +0x28
	Script *m_genericScriptsToRun[MAX_GENERIC_SCRIPTS]; // +0x2C
	AsciiString m_genericScriptNames[MAX_GENERIC_SCRIPTS]; // +0xAC
	TeamTemplateGenericScriptsView m_teamTemplate; // +0x12C
};

Script *TeamPrototype::getGenericScript(int scriptToRetrieve, AsciiString *outName)
{
	if (!m_retrievedGenericScripts)
	{
		m_retrievedGenericScripts = true;
		for (int i = 0; i < MAX_GENERIC_SCRIPTS; ++i)
		{
			Script *dup = 0;
			AsciiString foundName;
			if (!m_teamTemplate.m_teamGenericScripts[i].isEmpty())
			{
				Script *script = (Script *)((Rva003573C4Owner *)TheScriptEngine)->rva003573C4(m_ownerName, *(const BfmeRoomZC *)&m_teamTemplate.m_teamGenericScripts[i], &foundName);
				if (script)
					dup = script->duplicate();
			}
			m_genericScriptsToRun[i] = dup;
			if (dup)
				m_genericScriptNames[i] = foundName;
		}
	}
	Script *result = m_genericScriptsToRun[scriptToRetrieve];
	if (result && outName)
		*outName = m_genericScriptNames[scriptToRetrieve];
	return result;
}
