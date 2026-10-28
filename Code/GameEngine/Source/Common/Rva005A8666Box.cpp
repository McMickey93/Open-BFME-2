// cl: -GR- -EHsc-
// NAT::targetNotifyMeIWasProbed @0x005A8666 90B (WorldBuilder name, its
// __FUNCTION__ string "NAT::targetNotifyMeIWasProbed"): guarded one-shot setter.
// Unless +0x94C already reads 5, resolve m_8[m_14]; a present object with
// its 0x40 flag set and a present m_8[m_18] plus both byte gates leads
// through the pinned 0x5A831E call to the pinned setter with 3, every other
// failing path uses 5. The int parameter is unused (callback shape). Targets
// read from retail REL32; the 0x5A6C90 callee is matched but spelled local.
#include "../../Include/GameNetwork/Transport.h"
#include "../GameNetwork/NATView.h"

void NAT::targetNotifyMeIWasProbed(int unused)
{
	if (m_state94c == 5)
		return;
	NATSlotView *localPlayer = m_slotList[m_localSlot];
	if (localPlayer == 0) {
		rva005A6C90(5);
		return;
	}
	if (m_942 != 0)
		return;
	m_942 = 1;
	if ((localPlayer->m_flags40 & 8) == 0)
		return;
	if (m_slotList[m_targetSlot] == 0) {
		rva005A6C90(5);
		return;
	}
	if (m_25 == 0)
		return;
	if (m_24 == 0)
		return;
	sendAProbeToTarget();
	rva005A6C90(3);
}

// NAT::gotTargetMangledPort @0x005A86C0 219B (WorldBuilder name, its
// __FUNCTION__ string "NAT::gotTargetMangledPort"): validated triple apply.
// Unless both +0x94C and +0x950 read 4, resolve both indexed slots; present
// pair plus matching first arg stamps +0x25 and, when +0x970 is set, links
// the pair's words (copying b into the peer's +4 and c over on full match).
// A present +0x24 leads through the +4 sub-object consumer and, unless
// +0x94C reads 2 with both flags against a cleared +0x942, through the gate
// to the setter with 3. Same class as targetNotifyMeIWasProbed (shared layout and pins).
void NAT::gotTargetMangledPort(int nodeNumber, unsigned short mangledPort, int mangledAddress)
{
	if (m_state94c == 4 && m_950 == 4)
		return;
	NATSlotView *targetPlayer = m_slotList[m_targetSlot];
	if (targetPlayer == 0) {
		rva005A6C90(5);
		return;
	}
	NATSlotView *localPlayer = m_slotList[m_localSlot];
	if (localPlayer == 0) {
		rva005A6C90(5);
		return;
	}
	if (nodeNumber != m_targetSlot)
		return;
	if (m_970 == 0) {
		m_25 = 1;
		goto check24;
	}
	m_25 = 1;
	m_addresses[m_targetSlot]->port = mangledPort;
	if (m_addresses[m_localSlot]->ip == m_addresses[m_targetSlot]->ip)
		m_addresses[m_targetSlot]->ip = mangledAddress;
check24:
	if (m_24 == 0)
		return;
	m_04->setDestAddrToSocket(m_targetSlot, m_addresses[m_targetSlot]);
	if (m_state94c != 2)
		return;
	if ((localPlayer->m_flags40 & 8) != 0) {
		if (m_942 != 1 && (targetPlayer->m_flags40 & 8) == 0)
			return;
	}
	sendAProbeToTarget();
	rva005A6C90(3);
}
