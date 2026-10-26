// cl: /Oi /DNDEBUG /MD
//
// ??0ClickReactionBehaviorModuleData@@QAE@XZ, retail 0x004595F0, 27 bytes.
// ClickReactionBehaviorModuleData frameless store-only ctor over table
// 0xC412F8 (ClickReactionTimer@8 plus ReactionFrames1@C through 5@1C): the
// folded vtable 0x00C4ED70 plus the 600 (0x258) default timer plus a
// compiler stosd run over the five frame slots. Identity is the rowed proc
// 0x45960C (same table) plus the rowed pool key 0x4595AB
// (ClickReactionBehavior) in the same cluster plus factory 0x24AED3 news
// 0x20 sole caller. Shape follows the ReflectDamage trivial-ctor precedent:
// flat TU-local class with explicit void*m_vtable (no virtuals, no vtable
// emission) plus plain-data members. The five zero dwords fall out of an
// inlined fixed-size memset (xor-eax plus lea-edi plus unrolled stosd, no
// rep prefix); the timer and vtable stay body assignments in retail order.
// Row supersedes the sole-caller pin.

extern "C" const void *const vtbl_00C4ED70[];  // folded, 9 classes; via ??_7BeaconClientUpdateModuleData@@6B@
#pragma comment(linker, "/alternatename:_vtbl_00C4ED70=??_7BeaconClientUpdateModuleData@@6B@")

#include <cstring>

#include "ClickReactionModuleDataView.h"

// ??0ClickReactionBehaviorModuleData@@QAE@XZ @0x4595F0
ClickReactionBehaviorModuleData::ClickReactionBehaviorModuleData()
{
	m_vtable = reinterpret_cast<const void *>(((unsigned int)vtbl_00C4ED70));
	m_weight = 0x258;
	memset(m_cooldown, 0, sizeof(m_cooldown));
}
