// cl: /O1 /G7 /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// platformsdk
// Clean BFME 1 donor NAT_attachSlotList_BFME.cpp at 9cbfb551 supplies
// transport allocation, local-IP setup and starting-port calculation.
// WB 0x014DBB90 names attachSlotList and its five arguments;
// retail 0x005A6B14..0x005A6C90 includes the missing 20-byte prologue.
#include "unicode_string.h"
#include "../../Include/GameNetwork/Transport.h"
#include <windows.h>
struct TransportAddress
{
    unsigned int ip;
    unsigned short port;
};
#include "NATView.h"

class GlobalData
{
public:
    unsigned char m_prefix[0xA54];
    unsigned int m_forcedPort;
};
extern GlobalData *TheWritableGlobalData;
void NAT::attachSlotList(GameInfo *gameInfo, int localSlot, unsigned int localIP,
    unsigned int timeout, bool isHost)
{
    if (!gameInfo)
        return;
    m_slotList = gameInfo->m_slots;
    m_localIP = localIP;
    m_localSlot = localSlot;
    if (m_localSlot < 0 || m_localSlot >= 8)
        return;
    if (isHost)
        m_hostSlot = localSlot;
    else
        m_hostSlot = 8;
    m_04 = new Transport;
    if (TheWritableGlobalData->m_forcedPort > 0)
        m_startingPortNumber = (unsigned short)TheWritableGlobalData->m_forcedPort;
    else
        m_startingPortNumber = (unsigned short)(8088 + ((timeGetTime() / 1000) % 20000));
    generatePortNumbers(m_slotList, localSlot);
    if (TheWritableGlobalData->m_forcedPort != 0) {
        unsigned short port = (unsigned short)TheWritableGlobalData->m_forcedPort;
        unsigned int ip = m_localIP;
        TransportAddress address = {ip, port};
        m_04->init(&address);
    } else {
        m_04->rva004D53B5((void *)m_localIP);
    }
    m_schema.attachSlotList(m_slotList, (unsigned short)localSlot);
    if (m_slotList) {
        for (int i = 0; i < 8; ++i) {
            if (m_slotList[i] && m_slotList[i]->isHuman() && m_slotList[i]->m_name.getLength())
                processPlayerJoin(i);
            m_hostKnown[i] = false;
            m_slotCookie[0] = 0;
        }
    }
    m_hostKnown[localSlot] = true;
    m_timeoutTime = timeGetTime() + timeout;
}

// BFME 1 NAT_generatePortNumbers.cpp at 9cbfb551 supplies port assignment;
// complete WB 0x014DB9D0 and native 0x005A678E add the two-word address cache.
void NAT::generatePortNumbers(GameSlot **slotList, int localSlot)
{
    for (int i = 0; i < 8; ++i) {
        if (slotList[i]) {
            if (i == localSlot && TheWritableGlobalData->m_forcedPort != 0) {
                NetPacketAddress address = slotList[i]->m_address;
                address.port = (unsigned short)TheWritableGlobalData->m_forcedPort;
                slotList[i]->m_address = address;
                if (!m_addresses[i])
                    m_addresses[i] = new NetPacketAddress(address);
                else
                    *m_addresses[i] = address;
            } else {
                NetPacketAddress address = slotList[i]->m_address;
                address.port = (unsigned short)(m_startingPortNumber + i);
                slotList[i]->m_address = address;
                if (!m_addresses[i])
                    m_addresses[i] = new NetPacketAddress(address);
                else
                    *m_addresses[i] = address;
            }
        }
    }
}
