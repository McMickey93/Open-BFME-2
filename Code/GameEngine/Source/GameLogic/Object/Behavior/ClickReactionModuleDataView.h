#ifndef BFME2_CLICK_REACTION_MODULE_DATA_VIEW_H
#define BFME2_CLICK_REACTION_MODULE_DATA_VIEW_H

// Shared constructor/reaction prefix. Retail constructor 0x004595F0 writes
// the vptr at +0, leaves +4 untouched, sets +8 and clears five ints at +0x0C.
// The reaction consumer reads the same +8 scalar and +0x0C array.
struct ClickReactionBehaviorModuleData
{
	ClickReactionBehaviorModuleData();
	const void *m_vtable; // +0
	unsigned int m_unused04; // +4
	int m_weight; // +8; existing reaction-view spelling
	int m_cooldown[5]; // +0x0C; existing reaction-view spelling
};

#endif
