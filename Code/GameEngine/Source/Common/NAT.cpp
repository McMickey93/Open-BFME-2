// cl: -GR- -EHsc-
// NAT::processPlayerJoin @0x005A6903 92B (WorldBuilder name, its
// __FUNCTION__ string "NAT::processPlayerJoin"; WB calls
// PortNegotiationSchema::playerJoin where retail calls 0x005DC291): bounds-checked slot refresh.
// Index >= 8 returns early; else the +0x28 sub-object consumes the index,
// the +0x38 field of m_8[idx] stores through the m_90C[idx] pointer, the
// pinned predicate gates on, +0x10 stamps 1 with an early-out when the index
// is current, otherwise the byte/dword tables update with the pinned
// counter. All three callees pop nothing (callee cleanup), hence bare
// call sites; targets read from retail REL32.
#include "../GameNetwork/NATView.h"

typedef void (PortNegotiationSchema::*PortNegotiationIntShape)(int);

// Retail resets an eight-byte value with a dword and a ushort member;
// the last two bytes are padding, copied with the member representation.
struct Rva005A695FValue
{
	__forceinline Rva005A695FValue() : value00(0), value04(0) {}
	int value00;
	unsigned short value04;
};

// 0x005A671D ignores incoming ecx (loads its context from the 0xE063FC
// global first thing), so it is spelled as a free function: no ecx setup.
int Rva005A671DNext();

void NAT::processPlayerJoin(int idx)
{
	if ((unsigned short)idx >= 8)
		return;
	(m_schema.*reinterpret_cast<PortNegotiationIntShape>(&PortNegotiationSchema::playerJoin))(idx);
	idx = (unsigned short)idx;
	GameSlot *o = m_slotList[idx];
	Rva005A6A4CAddress *p = m_addresses[idx];
	p->ip = o->m_address.ip;
	if (!(((Rva005A6709 *)this)->*reinterpret_cast<Rva005A6709BoolShape>(&Rva005A6709::rva005A6709))())
		return;
	if (idx == m_localSlot) {
		m_mode = 1;
		return;
	}
	m_mode = 1;
	m_hostKnown[idx] = 0;
	m_slotCookie[idx] = Rva005A671DNext();
}

// Native 0x005A695F..0x005A69C0 RET4 shares the NAT tables and +0x28
// sub-object with the named join and reconnect siblings. This operation's
// original name remains unknown; it clears the selected slot and its value.
void NAT::processPlayerLeave(int idx)
{
	if ((unsigned short)idx >= 8)
		return;
	int slot = (unsigned short)idx;
	if (m_targetSlot == slot)
	{
		m_targetSlot = -1;
		m_state94c = 0;
		m_950 = 0;
	}
	(m_schema.*reinterpret_cast<PortNegotiationIntShape>(&PortNegotiationSchema::playerLeave))(idx);
	m_hostKnown[slot] = 0;
	m_slotCookie[slot] = 0;
	*(Rva005A695FValue *)m_addresses[slot] = Rva005A695FValue();
}
