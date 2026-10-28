#ifndef BFME2_NAT_VIEW_H
#define BFME2_NAT_VIEW_H

// Private NAT view shared by the NAT.cpp TU and its not-yet-merged donors.
// Unknown fields keep padding; each named field cites the body that proves it.

class AsciiString;

class PortNegotiationSchema
{
public:
	void handleNegotiationResult(unsigned short a, unsigned short b, int expected, int newVal);
};

// A slot's address (+0x38 in each slot of the list at NAT +0x08).
struct Rva005A6A4CAddress
{
	unsigned int ip;
	unsigned int port;
};

struct Rva005A6A4CSlot
{
	char m_pad00[0x38];
	Rva005A6A4CAddress m_address;
};

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
struct Rva005A6A4CSlot;

class NAT
{
public:
	bool rva005A6732() const;
public:
	void setConnectionState(int a, int b, int expected, int val);
public:
	void rva005A6C90(int val);
public:
	void rva005A6A4C();
public:
	void probeMangler();
private:
	char m_pad00[0x8];
private:
	Rva005A6A4CSlot **m_8;
private:
	char m_pad0C[0x14 - 0xC];
private:
	int m_14;
private:
	int m_18;
private:
	int m_1C;
private:
	int m_20;
private:
	int m_24;
private:
	PortNegotiationSchema m_28;
private:
	char m_pad2C[0x90C - 0x2C];
private:
	Rva005A6A4CAddress *m_90C[8];
private:
	char m_pad92C[0x934 - 0x92C];
private:
	unsigned short m_port934; // +0x934 (probeMangler)
private:
	unsigned short m_port936; // +0x936
private:
	unsigned long m_time938; // +0x938
private:
	char m_pad93C[0x944 - 0x93C];
private:
	unsigned long m_addr944; // +0x944
private:
	char m_pad948[0x94C - 0x948];
private:
	int m_94C;
private:
	int m_950;
public:
	AsciiString rva005A6E7A(int state);
};

#endif
