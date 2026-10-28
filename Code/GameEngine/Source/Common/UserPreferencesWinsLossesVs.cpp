// cl: /Ireference/shims/bfme2_ascii /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /DWIN32 /D_WINDOWS
// stlport
//
// UserPreferences WinsVs/LossesVs helpers (retail 0x0053740C/82, 0x0053745E/85,
// 0x005374B3/82, 0x00537505/85, plus max-finders 0x0053755A/188 and
// 0x00537616/188).
// Each builds "<outer>WinsVs<inner>" or "<outer>LossesVs<inner>" from a
// by-value outer AsciiString plus "WinsVs"/"LossesVs" plus an inner faction
// string, then forwards to the UserPreferences virtual at slot 6 (getInt,
// +0x18, default 0) or slot 11 (setInt, +0x2C). The max-finders loop the
// six-entry faction table at 0x009BE9B0 (Men/Elves/Dwarves/Isengard/Mordor/
// Wild) and return the faction with the largest WinsVs/LossesVs value.
// Vtable layout mirrors Common/UserPreferences.cpp (13 slots: dtor, 2 loads,
// write, 5 getters, 4 setters) so the indirect offsets match; the mirror
// omits the map base and m_filename since these bodies touch only the vtable.
// Evidence: "WinsVs" at 0x00869120, "LossesVs" at 0x00869128; faction table
// at 0x009BE9B0 (Men/Elves/Dwarves/Isengard/Mordor/Wild); callers 0x0053755A,
// 0x00537616 (outer = [ebp+0x0C]) and 0x005376D2/0x005377B6 (outer/inner loop
// factions), plus 0x005BF4BC (RealTimeStatsPreferences at [ebp-0x2C]) and
// 0x005BFD35 (StrategicStatsPreferences at [ebp-0x28]); no BFME1 donor
// (no WinsVs/LossesVs hits in open-bfme-1/game). Class proven by shared use
// from both RealTime and Strategic stats objects (common UserPreferences base).

typedef int Int;
typedef bool Bool;
typedef float Real;

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

#include "ascii_string.h"


class UnicodeString;

#include <map>
#include "unicode_string.h"

typedef _STL::map<AsciiString, AsciiString> PreferenceMap;

class UserPreferences : public PreferenceMap
{
public:
	UserPreferences();
	virtual ~UserPreferences();

	// MSVC lays overloaded virtuals out in reverse declaration order, so
	// load(UnicodeString) takes slot 1 and load(AsciiString) slot 2.
	virtual Bool load(const AsciiString &fname);
	virtual Bool load(const UnicodeString &fname);
	virtual Bool write(void);

	virtual Bool getBool(const AsciiString &key, Bool defaultValue) const;
	virtual Real getReal(const AsciiString &key, Real defaultValue) const;
	virtual Int getInt(const AsciiString &key, Int defaultValue) const;
	virtual Int getEnumIndex(const char *key, const char **names, Int count, Int defaultValue) const;
	virtual AsciiString getAsciiString(const AsciiString &key, const AsciiString &defaultValue) const;

	virtual void setBool(const AsciiString &key, Bool val);
	virtual void setReal(const AsciiString &key, Real val);
	virtual void setInt(const AsciiString &key, Int val);
	virtual void setAsciiString(const AsciiString &key, const AsciiString &val);

	// Conditionally indexed setter (retail 0x003B2322): formats the index
	// with "%d" and either assigns or erases the slot by flag.
	void rva003B2322(const AsciiString &val, Int num, Bool flag);


	// Per-faction and lifetime statistics accessors (BFME 2 additions; the
	// ledger still names them by address).
	int rva00535CE4(AsciiString factionPrefix);
	AsciiString rva00535820();
	void rva00536B3F(AsciiString factionPrefix, int amount);
	int rva00536B86(AsciiString factionPrefix);
	void rva00536BD0(AsciiString factionPrefix, int amount);
	int rva00536C17(AsciiString factionPrefix);
	int rva0053700F();
	int rva005370D2();
	AsciiString rva00537261();
	void rva00537058(int bits);
	void rva0053711B(AsciiString factionPrefix, int amount, int value);
	UnicodeString rva00535B32(float seconds);
	void rva0053587C(AsciiString factionPrefix, int amount);
	void rva00535BAF(AsciiString factionPrefix, int amount);
	void rva00535C9D(AsciiString factionPrefix, int amount);
	void rva00535D2E(AsciiString factionPrefix, int amount);
	void rva00535DBF(AsciiString factionPrefix, int amount);
	void rva00535E50(AsciiString factionPrefix, int amount);
	void rva00535EE1(AsciiString factionPrefix, int amount);
	void rva00535F72(int amount);
	void rva00536003(int amount);
	void rva00536094(int amount);
	void rva00536125(int amount);
	int rva0053604B();
	int rva005360DC();
	int rva0053616D();
	void rva005361B6(AsciiString factionPrefix);
	AsciiString rva0053620F();
	int rva00535FBA();
	int rva005358C3(AsciiString factionPrefix);
	int rva00535BF6(AsciiString factionPrefix);
	int rva00535C40();
	int rva005373AF();
	int rva0053734E(AsciiString factionPrefix);
	int rva00537C28();
	UnicodeString rva00537C3F();
	void rva00536C61(AsciiString factionPrefix, int amount);
	int rva00536CA8(AsciiString factionPrefix);
	void rva00536CF2(AsciiString factionPrefix, int amount);
	int rva00536D39(AsciiString factionPrefix);
	void rva00536D83(AsciiString factionPrefix, int amount);
	int rva00536DCA(AsciiString factionPrefix);
	void rva00536E14(AsciiString factionPrefix, int amount);
	int rva00536E5B(AsciiString factionPrefix);
	void rva00536EA5(AsciiString factionPrefix, int amount);
	int rva00536EEC(AsciiString factionPrefix);
	void rva00536F36(AsciiString factionPrefix, int amount);
	int rva00536F7D(AsciiString factionPrefix);
	void rva00536FC7(int amount);
	int rva00535D75(AsciiString factionPrefix);
	int rva00535E06(AsciiString factionPrefix);
	int rva00535E97(AsciiString factionPrefix);
	int rva00535F28(AsciiString factionPrefix);
	void rva0053595E(AsciiString factionPrefix, float amount);
	float rva0053590D(AsciiString factionPrefix);
	float rva005359A9(AsciiString factionPrefix);
	float rva00535A45(AsciiString factionPrefix);
	float rva00535AE1(AsciiString factionPrefix);
	void rva005359FA(AsciiString factionPrefix, float amount);
	void rva00535A96(AsciiString factionPrefix, float amount);
	void rva00535781();
	int rva00537190(AsciiString factionPrefix, int amount);
	void rva005372BD(int amount);
	int rva00537305();
	void rva00537208(AsciiString factionPrefix);
	void rva0053626B(AsciiString factionPrefix, int amount);
	int rva005362B2(AsciiString factionPrefix);
	void rva005362FC(AsciiString factionPrefix, int amount);
	int rva00536343(AsciiString factionPrefix);
	void rva0053638D(AsciiString factionPrefix, int amount);
	int rva005363D4(AsciiString factionPrefix);
	void rva0053641E(AsciiString factionPrefix, int amount);
	int rva00536465(AsciiString factionPrefix);
	void rva005364AF(AsciiString factionPrefix, int amount);
	int rva005364F6(AsciiString factionPrefix);
	void rva00536540(AsciiString factionPrefix, int amount);
	int rva00536587(AsciiString factionPrefix);
	void rva005365D1(AsciiString factionPrefix, int amount);
	int rva00536618(AsciiString factionPrefix);
	void rva00536662(AsciiString factionPrefix, int amount);
	int rva005366A9(AsciiString factionPrefix);
	void rva005366F3(AsciiString factionPrefix, int amount);
	int rva0053673A(AsciiString factionPrefix);
	void rva00536784(AsciiString factionPrefix, int amount);
	int rva005367CB(AsciiString factionPrefix);
	int rva00536815(AsciiString factionPrefix);
	void rva0053685F(AsciiString factionPrefix, int amount);
	int rva005368A6(AsciiString factionPrefix);
	void rva005368F0(AsciiString factionPrefix, int amount);
	int rva00536937(AsciiString factionPrefix);
	void rva00536981(AsciiString factionPrefix, float amount);
	float rva005369CC(AsciiString factionPrefix);
	void rva00536A1D(AsciiString factionPrefix, int amount);
	int rva00536A64(AsciiString factionPrefix);
	void rva00536AAE(AsciiString factionPrefix, int amount);
	int rva00536AF5(AsciiString factionPrefix);
	Int rva00537505(AsciiString a, const AsciiString &b);
	void rva005374B3(AsciiString a, const AsciiString &b, Int v);
	Int rva0053745E(AsciiString a, const AsciiString &b);
	void rva0053740C(AsciiString a, const AsciiString &b, Int v);
	AsciiString rva0053755A(AsciiString a);
	AsciiString rva00537616(AsciiString a);
	AsciiString rva005376D2();
	AsciiString rva005377B6();
	void rva00537A9B(AsciiString arg, float gameTime);
	void rva005378E9(AsciiString faction, int turns);

protected:
	UnicodeString m_filename;
};

Int UserPreferences::rva00537505(AsciiString a, const AsciiString &asciiString)
{
	((StringBase<char> *)&a)->concat("LossesVs");
	((StringBase<char> *)&a)->concat(*(const StringBase<char> *)&asciiString);
	return getInt(a, 0);
}

void UserPreferences::rva005374B3(AsciiString a, const AsciiString &asciiString, Int v)
{
	((StringBase<char> *)&a)->concat("LossesVs");
	((StringBase<char> *)&a)->concat(*(const StringBase<char> *)&asciiString);
	setInt(a, v);
}

Int UserPreferences::rva0053745E(AsciiString a, const AsciiString &asciiString)
{
	((StringBase<char> *)&a)->concat("WinsVs");
	((StringBase<char> *)&a)->concat(*(const StringBase<char> *)&asciiString);
	return getInt(a, 0);
}

void UserPreferences::rva0053740C(AsciiString a, const AsciiString &asciiString, Int v)
{
	((StringBase<char> *)&a)->concat("WinsVs");
	((StringBase<char> *)&a)->concat(*(const StringBase<char> *)&asciiString);
	setInt(a, v);
}

extern const char *g_rva0033A3F4Table[];

AsciiString UserPreferences::rva0053755A(AsciiString a)
{
	AsciiString best;
	AsciiString cur;
	Int max = 0;
	for (Int i = 0; i < 6; ++i) {
		((StringBase<char> *)&cur)->set(g_rva0033A3F4Table[i]);
		Int v = rva0053745E(a, cur);
		if (v > max) {
			best = cur;
			max = v;
		}
	}
	return best;
}

AsciiString UserPreferences::rva00537616(AsciiString a)
{
	AsciiString best;
	AsciiString cur;
	Int max = 0;
	for (Int i = 0; i < 6; ++i) {
		((StringBase<char> *)&cur)->set(g_rva0033A3F4Table[i]);
		Int v = rva00537505(a, cur);
		if (v > max) {
			best = cur;
			max = v;
		}
	}
	return best;
}

AsciiString UserPreferences::rva005376D2()
{
	AsciiString best;
	AsciiString outer;
	AsciiString inner;
	Int max = 0;
	const char ** volatile a = g_rva0033A3F4Table;
	do {
		((StringBase<char> *)&outer)->set(*a);
		const char **b = g_rva0033A3F4Table;
		do {
			((StringBase<char> *)&inner)->set(*b);
			Int v = rva0053745E(outer, inner);
			if (v > max) {
				best = inner;
				max = v;
			}
			++b;
		} while ((Int)b < (Int)(g_rva0033A3F4Table + 6));
		++a;
	} while ((Int)a < (Int)(g_rva0033A3F4Table + 6));
	return best;
}

AsciiString UserPreferences::rva005377B6()
{
	AsciiString best;
	AsciiString outer;
	AsciiString inner;
	Int max = 0;
	const char ** volatile a = g_rva0033A3F4Table;
	do {
		((StringBase<char> *)&outer)->set(*a);
		const char **b = g_rva0033A3F4Table;
		do {
			((StringBase<char> *)&inner)->set(*b);
			Int v = rva00537505(outer, inner);
			if (v > max) {
				best = inner;
				max = v;
			}
			++b;
		} while ((Int)b < (Int)(g_rva0033A3F4Table + 6));
		++a;
	} while ((Int)a < (Int)(g_rva0033A3F4Table + 6));
	return best;
}
