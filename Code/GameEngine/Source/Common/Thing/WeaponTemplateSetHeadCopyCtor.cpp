// cl: /DNDEBUG /MD
//
// WeaponTemplateSetHead copy ctor, retail 0x00045455, 24 bytes.
// Dedicated TU so WeaponTemplateSetCopyCtor.cpp cannot inline this memcpy.

#include <string.h>

class WeaponTemplateSetHead
{
	char _m[0x4C];

public:
	WeaponTemplateSetHead(const WeaponTemplateSetHead &that);
};

WeaponTemplateSetHead::WeaponTemplateSetHead(const WeaponTemplateSetHead &that)
{
	memcpy(this, &that, 0x4C);
}
