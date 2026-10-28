// cl: /DNDEBUG /MD
//
// ??0RainOfFireUpdateModuleData@@QAE@XZ, retail 0x004AC03D, 89 bytes.
// Frameless SSE ctor: two global floats into +0x10/+0x14, vtable literal,
// ints 150/120 at +8/+0xC, zeros plus two 1.0f stores across +0x18/+0x2C.
// Explicit m_vtable plus /arch:SSE per the DemoTrap precedent.

// Retail default floats arrive via absolute loads (DIR32-masked externs,
// free per the DieMuxData precedent): emitter height at 0x00BC292C, darkness
// level at 0x00BBB8D4. The 1.0f defaults stay literals: the compiler folds
// them onto the shared literal at 0x00BBB8D8 per the Prone precedent.

extern "C" const void *const __identifier("??_7ObjectHelperModuleData@@6B@")[];  // folded nine-class vftable 0x00C4ED70, by its data-ledger name

#include "RainOfFireUpdateView.h"

// ??0RainOfFireUpdateModuleData@@QAE@XZ
RainOfFireUpdateModuleData::RainOfFireUpdateModuleData()
{
	height = 100.0f;
	darkness = 0.25f;
	vtable = reinterpret_cast<void *>(((unsigned int)__identifier("??_7ObjectHelperModuleData@@6B@")));
	startRainTime = 150;
	darknessFadeTime = 120;
	jitter = 0.0f;
	dpsMin = 1.0f;
	dpsMax = 1.0f;
	rampup = 0.0f;
	offset.x = 0.0f;
	offset.y = 0.0f;
}
