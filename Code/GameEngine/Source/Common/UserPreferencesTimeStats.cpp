// cl: /Ireference/shims/bfme2_ascii /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /DWIN32 /D_WINDOWS
// stlport
// ?rva00537A9B@UserPreferences@@QAEXVAsciiString@@M@Z @0x00537A9B 397B
// UserPreferences record-game-time path: TimePlayed add, Longest max, Shortest min-nonzero, Average recompute via total-games.
// Evidence: TimePlayed 0x00868E2C slot 0x28, Longest 0x00868E38 getter setter, Shortest 0x00868E48 getter setter,
// total-games 0x0053734E Average 0x00868E5C getter setter, TheGame float 1.0 0x007BB8D8, chain same class.
// Call sites 0x005BFA94 and 0x005BFE18. Structural inference: the average is
// recomputed in place in the getter's result (one float slot reused for the
// argument), as the turn-count sibling 0x005378E9 does with its own locals.
// Native callers preserve the one-pointer string ABI. Use the shared
// view and its independently verified workers instead of private wrappers.
#include "ascii_string.h"

#include <map>
#include "unicode_string.h"
typedef bool Bool;
typedef int Int;
typedef float Real;

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

void UserPreferences::rva00537A9B(AsciiString arg, float gameTime)
{
	AsciiString key(arg);
	((StringBase<char> *)&key)->concat("TimePlayed");
	float total = rva0053590D(arg) + gameTime;
	setReal(key, total);
	float longest = rva005359A9(arg);
	if (gameTime > longest)
		rva0053595E(arg, gameTime);
	float shortest = rva00535A45(arg);
	if (shortest == 0.0f || gameTime < shortest)
		rva005359FA(arg, gameTime);
	int games = rva0053734E(arg);
	float fGames = (float)(games - 1);
	float avg = rva00535AE1(arg);
	avg = (fGames * avg + gameTime) / (fGames + 1.0f);
	rva00535A96(arg, avg);
}
