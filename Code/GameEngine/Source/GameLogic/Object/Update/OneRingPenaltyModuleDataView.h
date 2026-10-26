#pragma once

// Accessed module-data layout shared by the constructor and spawn helper.
// Retail ctor 0x004999F1 and field table 0x00C503B0 establish the offsets.
// The explicit vtable word is retained; this view does not model the destructor.
#include "../../../../../../reference/shims/bfme2_ascii/ascii_string.h"

class OpaqueRefCounted;
class OneRingPenaltyUpdateModuleData
{
public:
    OneRingPenaltyUpdateModuleData();

    const void *m_vtable; // +0x00
    unsigned int m_unused04; // +0x04, not initialized by the constructor
    AsciiString m_specialObjectName; // +0x08
    unsigned int m_ringTimeBeforeSpawning; // +0x0C
    unsigned int m_timeSpentRoamingAround; // +0x10
    unsigned int m_timeRingPowerSuppressed; // +0x14
    float m_startingDistanceFromMe; // +0x18
    unsigned int m_timeFrozenFromPenalty; // +0x1C
    OpaqueRefCounted *m_discoveredSound; // +0x20, holder representation
};
