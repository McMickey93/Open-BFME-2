// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHa /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// stlport
#define Matrix4x4 Matrix4  // BFME renamed it
#define __PLACEMENT_VEC_NEW_INLINE  // always.h/GameMemory.h define array placement-new themselves
// stlport
//
// ??0DebugIOOds@@QAE@XZ, retail 0x0003F380 (70 bytes), plus the
// ??_GDebugIOOds@@UAEPAXI@Z scalar deleting destructor at 0x0003F430
// (33 bytes). The implicit ??1DebugIOOds@@UAE@XZ at 0x0003F460
// and its unwind action are rowed from this unit too.
//
// Ported from Open-BFME-1
// Code/Libraries/Source/WWVegas/WWDebug/Rva0088FAA0DebugIOOdsDestructor.cpp.
// The class is upstream's (debug/internal_io.h through _pch.h); retail owns
// it as DebugIOOds (Create/Write rows). The in-class inline constructor is
// emitted out of line through the anchor below; Create (DebugIOOds_Create.cpp)
// inlines it.
#include "_pch.h"

// ?Delete@DebugIOOds@@UAEXXZ absent-from-retail
void DebugIOOds::Delete(void)
{
    this->~DebugIOOds();
}

// Preserve the inline constructor emitted by its factory consumers.
#pragma inline_depth(0)
// ?_bfmeDebugIOOdsInlineAnchor absent-from-retail
void _bfmeDebugIOOdsInlineAnchor(DebugIOOds *io)
{
    io->DebugIOOds::DebugIOOds();
}
#pragma inline_depth()
