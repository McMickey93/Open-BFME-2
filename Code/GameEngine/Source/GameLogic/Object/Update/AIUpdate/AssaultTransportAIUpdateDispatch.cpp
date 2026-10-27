// cl: /DNDEBUG /MD
//
// ?aiDoCommand@AssaultTransportAIUpdate@@UAEXPBUAICommandParms@@@Z
// retail 0x0048F7A7 (129 bytes). Slot 0 of AssaultTransportAIUpdate's
// +0x20 AICommandInterface vftable 0x00C4CC8C, which the rowed dtor
// 0x0048F3E0 and ctor 0x0048F5A3 store. The override keeps that base's
// this, so the class members are reached 0x20 below their offsets and every
// helper call adjusts it back with its own lea. Commands from the AI
// (source 2) skip straight to the base; otherwise the command selects helper
// work before always delegating to AIUpdateInterface::aiDoCommand (0x002673F6,
// slot 0 of its +0x20 vftable). Command 5 zeroes the +0x430 word then runs
// both helpers; commands 0xB and 0x39 run the reset helper and raise the
// +0x441 flag; command 0xF runs the reset helper, copies the 12-byte position
// into the +0x424 triple and raises the +0x440 flag; any other command just
// runs the reset helper. The +0x424/+0x430/+0x440 tail is proven by the rowed
// Rva0048F365Helper TU. Case order in source is load-bearing for the
// compiler's block layout.

struct BfmeFloatTriple
{
	float m_x;
	float m_y;
	float m_z;
};

struct AICommandParms
{
	int m_cmd;
	int m_cmdSource;
	BfmeFloatTriple m_pos;
};

enum UpdateSleepTime
{
	UPDATE_SLEEP_NONE = 1
};

class Rva0026E836_Root
{
public:
	virtual ~Rva0026E836_Root();

private:
	char m_pad04[8];
};

class Rva0026E836_M1
{
public:
	virtual void f1();
};

class Rva0026E836_B2
{
public:
	virtual UpdateSleepTime update();

private:
	char m_pad08[12];
};

class Rva0026E836_M3
{
public:
	virtual void aiDoCommand(const AICommandParms *parms);
};

class AIUpdateInterface : public Rva0026E836_Root, public Rva0026E836_M1, public Rva0026E836_B2, public Rva0026E836_M3
{
public:
	virtual void aiDoCommand(const AICommandParms *parms);
};

class AssaultTransportAIUpdate : public AIUpdateInterface
{
public:
	virtual void aiDoCommand(const AICommandParms *parms);
	void Rva0048F690Helper();
	void Rva0048F365Helper();

private:
	unsigned char m_pad24[0x424 - 0x24];
	BfmeFloatTriple m_triple424;
	int m_int430;
	unsigned char m_pad434[0x440 - 0x434];
	unsigned char m_byte440;
	unsigned char m_byte441;
};

void AssaultTransportAIUpdate::aiDoCommand(const AICommandParms *parms)
{
	if (parms->m_cmdSource != 2)
	{
		switch (parms->m_cmd)
		{
		case 5:
			m_int430 = 0;
			Rva0048F690Helper();
			Rva0048F365Helper();
			break;
		case 0xB:
		case 0x39:
			Rva0048F365Helper();
			m_byte441 = 1;
			break;
		case 0xF:
			Rva0048F365Helper();
			m_triple424 = parms->m_pos;
			m_byte440 = 1;
			break;
		default:
			Rva0048F365Helper();
			break;
		}
	}
	AIUpdateInterface::aiDoCommand(parms);
}
