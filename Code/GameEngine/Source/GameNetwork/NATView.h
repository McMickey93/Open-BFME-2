#ifndef BFME2_NAT_VIEW_H
#define BFME2_NAT_VIEW_H

// Private NAT view shared by the NAT.cpp TU and its not-yet-merged donors.
// Unknown fields keep padding; each named field cites the body that proves it.

#include "unicode_string.h"
class AsciiString;

class PortNegotiationSchema
{
public:
	void handleNegotiationResult(unsigned short first, unsigned short second, int cookie, int result);
	unsigned char m_bytes[0x8E4 - 0x28];
};

// A slot's address (+0x38 in each slot of the list at NAT +0x08; also the
// pointee of NAT's +0x90C table).
struct Rva005A6A4CAddress
{
	unsigned int ip;
	unsigned int port;
};

// A slot of the list at NAT +0x08: the player name at +0x30 (translated and
// compared by processGlobalMessage) and the address at +0x38.
struct NATSlotView
{
	unsigned char m_pad00[0x30];
	UnicodeString m_name;			// +0x30
	unsigned char m_pad34[0x38 - 0x34];
	Rva005A6A4CAddress m_address;		// +0x38
};

class GameInfo;

// flags: region default (reverse/retail_inventory/flag_regions.csv)
// ?rva005A6732@NAT@@QBE_NXZ @0x005A6732 92B. Unlock lane: range plus
// table-null checks on m_14/m_18 via m_8, then m_94C/m_950 must be 0/4/5.
// Evidence: callers 0x005A8ABF/0x005A8F57, neighbours Rva005A6709Predicate and
// Disp8CmpBoolGetters (0x94C field), no callees. Class renamed from the
// address-derived Rva005A6732 to the ledger's NAT: the two views are the same
// retail class (this body's m_8 at +0x08, the two slot ints at +0x14/+0x18
// and the state bytes at +0x94C/+0x950 are NAT's m_slotList, m_localSlot,
// m_targetSlot and m_state94c, as the NAT views in NATProcessGlobalMessage.cpp
// and NATUpdateBfme.cpp spell them), and 27 ledger rows already name the class
// NAT, so the rowed name is this spelling's owner.
// NAT is spelled struct: the data ledger binds TheNAT as ?TheNAT@@3PAUNAT@@A.
struct NAT
{
public:
	bool rva005A6732() const;
	void setConnectionState(int a, int b, int expected, int val);
	void rva005A6C90(int val);
	void rva005A6A4C();
	void probeMangler();
	AsciiString rva005A6E7A(int state);
	void processGlobalMessage(int slotNum, const char *options);
	void attachSlotList(GameInfo *game, int localSlot, unsigned int localIP, unsigned int arg, bool isHost);
	void targetNotifyMeIWasProbed(int slot);
	void gotTargetMangledPort(int slot, unsigned short port, int addr);
	void notifyHostMyNATCreated(int cookie);
	void StartNegotiationAction(int slot, int value);
private:
	int m_0;
	void *m_04;
	NATSlotView **m_slotList;		// +0x08
	int m_hostSlot;				// +0x0C
	int m_mode;				// +0x10
	int m_localSlot;			// +0x14
	int m_targetSlot;			// +0x18
	int m_1C;
	int m_cookie;				// +0x20
	int m_24;
	PortNegotiationSchema m_schema;		// +0x28
	unsigned char m_hostKnown[8];		// +0x8E4
	int m_slotCookie[8];			// +0x8EC
	Rva005A6A4CAddress *m_addresses[8];	// +0x90C
	char m_pad92C[0x934 - 0x92C];
	unsigned short m_port934;		// +0x934 (probeMangler)
	unsigned short m_port936;		// +0x936
	unsigned long m_time938;		// +0x938
	char m_pad93C[0x944 - 0x93C];
	unsigned long m_addr944;		// +0x944
	char m_pad948[0x94C - 0x948];
	int m_state94c;				// +0x94C
	int m_950;				// +0x950
};

#endif
