// cl: /DNDEBUG /MD
// ?setAll@Rva002535A5Mask@@SAXPAX@Z @0x002535A5 31B mask set-all.
// Retail memsets 0x1C bytes then NOTs 7 dwords. Evidence: leaf lane;
// pin plus caller AutoHealBehaviorModuleData ctor rowed; flags from prev
// ModuleDataBuildFieldParseChained TU and caller TU.
// memset is msvcr71's, called through its import thunk at 0x006291AE
// rather than expanded inline: <string.h>'s memset with
// #pragma function(memset).
#include <string.h>
#pragma function(memset)

class Rva002535A5Mask
{
public:
	static void setAll(void *mask);
};

void Rva002535A5Mask::setAll(void *mask)
{
	unsigned int *words = (unsigned int *)mask;
	memset(mask, 0, 0x1c);
	for (unsigned int i = 0; i < 7; i++)
		words[i] = ~words[i];
}
