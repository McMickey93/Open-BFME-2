// flags: region default (reverse/retail_inventory/flag_regions.csv)
//
// ?decreaseAIPriorityForFailure@TeamPrototype@@QAEXXZ @0x0039D73A (13B).
// TeamPrototype priority decrement: subtracts the dword at +0x224 from the
// dword at +0x21C. Retail shape is mov eax plus disp32 sub plus ret.
// Caller at 0x003BFC5D passes the TeamPrototype at Team+0x30 and then logs
// Team priority decreased with the updated +0x21C value, proving the owner
// is TeamPrototype and the +0x21C field is its priority.

// The production-priority slots of the prototype's team template (+0x12C),
// spelled as the Team.cpp seed's TeamTemplateInfo names them (Zero Hour's
// m_productionPriority and its success increase and failure decrease).
struct TeamTemplatePriorityView
{
	char m_pad00[0xF0];
	int m_productionPriority; // +0xF0, prototype +0x21C
	int m_productionPrioritySuccessIncrease; // +0xF4, prototype +0x220
	int m_productionPriorityFailureDecrease; // +0xF8, prototype +0x224
};

class TeamPrototype
{
public:
	void increaseAIPriorityForSuccess();
	void decreaseAIPriorityForFailure();
	void rva0039D747(int delta);
	void rva0039D754(int delta);

private:
	char m_pad00[0x12C];
	TeamTemplatePriorityView m_teamTemplate; // +0x12C
};

// ?increaseAIPriorityForSuccess@TeamPrototype@@QAEXXZ @0x0039D72D (13B), the increment twin
// directly before it: adds the dword at +0x220 to the priority. Its caller at
// 0x003CB963 logs "Team '%s' priority increased to %d for success." after it.
void TeamPrototype::increaseAIPriorityForSuccess()
{
	m_teamTemplate.m_productionPriority += m_teamTemplate.m_productionPrioritySuccessIncrease;
}

void TeamPrototype::decreaseAIPriorityForFailure()
{
	m_teamTemplate.m_productionPriority -= m_teamTemplate.m_productionPriorityFailureDecrease;
}

void TeamPrototype::rva0039D747(int delta)
{
	m_teamTemplate.m_productionPriority += delta;
}

void TeamPrototype::rva0039D754(int delta)
{
	m_teamTemplate.m_productionPriority -= delta;
}
