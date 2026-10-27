// cl: /DNDEBUG /MD /EHsc
// ?getModuleNameKey@RandomSoundSelectorClientBehavior@@UBE?AW4NameKeyType@@XZ @0x4CBCAD
// (69B): cached pool-name key for RandomSoundSelectorClientBehavior. The class
// identity comes from the pool-name string the body pushes
// ("RandomSoundSelectorClientBehavior"); the body guards a function-local static
// key fetched once through TheNameKeyGenerator. It is NOT getClassMemoryPool:
// retail stores nameToKey's return (a key, not a pool pointer) and returns it,
// and the address carries no getClassMemoryPool row anywhere. /EHsc for the
// static-guard EH prologue; globals are TU-local externs (DIR32 slots patch
// from retail, no pins; nameToKey resolves via its matched row).

#include "../../../GameClient/Drawable/Behavior/RandomSoundSelectorClientBehaviorView.h"

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

// ?getModuleNameKey@RandomSoundSelectorClientBehavior@@UBE?AW4NameKeyType@@XZ
NameKeyType RandomSoundSelectorClientBehavior::getModuleNameKey() const
{
	static NameKeyType TheRandomSoundSelectorClientBehaviorPoolKey =
		TheNameKeyGenerator->nameToKey("RandomSoundSelectorClientBehavior");
	return TheRandomSoundSelectorClientBehaviorPoolKey;
}
