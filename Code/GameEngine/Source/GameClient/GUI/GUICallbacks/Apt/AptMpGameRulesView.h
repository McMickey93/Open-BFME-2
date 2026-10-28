#ifndef BFME2_APT_MP_GAME_RULES_VIEW_H
#define BFME2_APT_MP_GAME_RULES_VIEW_H

// Private views shared by the AptMpGameRules.cpp TU and its not-yet-merged
// donors. Unknown fields keep padding.

class GameWindow
{
public:
	unsigned int winGetStyle();
	int winHide(bool);
	int winEnable(bool);			// 0x00313BEC
};

class Rva0043DA65
{
public:
	int rva0043DA65();			// 0x0043DA65
};

// rva0043DA65's result viewed as the object whose slot 12 (+0x30) the
// window toggle tests.
class Rva0057E97AValidator
{
public:
	virtual void pad0() = 0;
	virtual void pad1() = 0;
	virtual void pad2() = 0;
	virtual void pad3() = 0;
	virtual void pad4() = 0;
	virtual void pad5() = 0;
	virtual void pad6() = 0;
	virtual void pad7() = 0;
	virtual void pad8() = 0;
	virtual void pad9() = 0;
	virtual void pad10() = 0;
	virtual void pad11() = 0;
	virtual bool checkValid() = 0;
};

// The rules screen's window-list holder (the TU's bodies reach it by casting
// this): +0x58 holder, +0x7C/+0x80 window list, +0x88 updating flag, +0xB4
// per-window enable flags.
class Rva0057E97A
{
public:
	void rva0057E59B(int index, bool enable);
	void rva0057E97A();
private:
	char m_pad0[0x58];
	Rva0043DA65 *m_holder;			// +0x58
	char m_pad5C[0x20];
	GameWindow **m_begin;			// +0x7C
	GameWindow **m_end;			// +0x80
	char m_pad84[4];
	bool m_updating;			// +0x88
	char m_pad89[0x2B];
	int *m_enableFlags;			// +0xB4
};

#endif
