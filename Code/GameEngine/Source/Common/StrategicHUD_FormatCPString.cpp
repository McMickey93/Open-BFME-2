// cl: /MD /EHsc
// ?FormatCPString@StrategicHUD@@YA?AVUnicodeString@@HH@Z @0x005FD53E (150B): ArmyUnitSwapperCP fetch+format twin of 0x005D38C8.
// TheGameText fetch slot 0x3C with null exists; fmt via +8-or-empty at 0x007BB5C4; UnicodeString format
// 0x006CB5D0; releaseBuffer 0x00036E70; copy ctor 0x00037050; b>0 guard; caller 0x005FD916.
// Evidence: same label STRATEGICHUD:ArmyUnitSwapperCP; neighbours 0x005FD4FF/0x005FD788.
class UnicodeString;
namespace StrategicHUD
{
	UnicodeString __cdecl FormatCPString(int a, int b);
}
typedef unsigned short wchar_t;
typedef bool Bool;

template <typename T> class StringBase;
class UnicodeString;

#include "../../../../reference/shims/bfme2_ascii/unicode_string.h"


class GameTextInterface
{
public:
	virtual ~GameTextInterface() {}
	virtual void slot00() = 0;
	virtual void slot04() = 0;
	virtual void slot08() = 0;
	virtual void slot0c() = 0;
	virtual void slot10() = 0;
	virtual void slot14() = 0;
	virtual void slot18() = 0;
	virtual void slot1c() = 0;
	virtual void slot20() = 0;
	virtual void slot24() = 0;
	virtual void slot28() = 0;
	virtual void slot2c() = 0;
	virtual void slot30() = 0;
	virtual UnicodeString fetch(const char *label, Bool *exists = 0) = 0;
	virtual UnicodeString fetch(const class AsciiString &label, Bool *exists = 0) = 0;
};

extern GameTextInterface *TheGameText;

UnicodeString StrategicHUD::FormatCPString(int commandPoints, int maxCommandPoints)
{
	UnicodeString cpString;
	if (maxCommandPoints > 0) {
		UnicodeString fetched = TheGameText->fetch("STRATEGICHUD:ArmyUnitSwapperCP", 0);
		const wchar_t *fmt = fetched.str();
		cpString.format(fmt, commandPoints, maxCommandPoints);
	}
	return cpString;
}
