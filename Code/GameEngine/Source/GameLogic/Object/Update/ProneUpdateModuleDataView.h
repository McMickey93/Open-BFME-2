#pragma once

// Accessed prefix shared by the byte-verified constructor and update bodies.
// Retail stores the folded vtable at +0 and the damage/frame ratio at +8;
// the intervening word is not initialized by this constructor.
class ProneUpdateModuleData
{
public:
	ProneUpdateModuleData();

	const void *m_vtable; // +0x00
	unsigned int m_unused04; // +0x04
	float m_damageToFramesRatio; // +0x08
};
