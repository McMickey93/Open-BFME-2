// cl: /DNDEBUG /MD /EHsc
// ?winSetLoneWindow@GameWindowManager@@UAEXPAVGameWindow@@@Z @0x002C12DC 51B
// GameWindowManager::winSetLoneWindow; BFME1 donor GameWindowManager.cpp winSetLoneWindow verbatim shape; m_loneWindow at +0x2C; GGM_CLOSE 0x4005 via TheWindowManager slot 58 0xE8; vtable 0x7C7C90 slot 52.

class GameWindow;

class GameWindowManager
{
public:
#define V(n) virtual void pad##n() = 0;
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
	V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
	V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
	V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
	V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
	V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
	V(48) V(49) V(50) V(51)
#undef V
	virtual void winSetLoneWindow(GameWindow *window);

private:
	unsigned char m_pad04[0x28];
	GameWindow *m_loneWindow;
};

extern GameWindowManager *TheWindowManager;

// Match the seed TU's BFME message ABI independently of its Zero Hour header.
typedef unsigned int UnsignedInt;
typedef unsigned int WindowMsgData;
enum WindowMsgHandledType { MSG_IGNORED, MSG_HANDLED };

class BfmeWindowManagerSendView
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
	virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
	virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
	virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
	virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
	virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35();
	virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
	virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43();
	virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47();
	virtual void slot48(); virtual void slot49(); virtual void slot50(); virtual void slot51();
	virtual void slot52(); virtual void slot53(); virtual void slot54(); virtual void slot55();
	virtual void slot56(); virtual void slot57();
	virtual WindowMsgHandledType winSendSystemMsg( GameWindow *window, UnsignedInt msg, WindowMsgData mData1, WindowMsgData mData2 );
};

void GameWindowManager::winSetLoneWindow(GameWindow *window)
{
	enum { GGM_CLOSE = 0x4005 };
	if (m_loneWindow == window)
		return;
	if (m_loneWindow)
		((BfmeWindowManagerSendView *)TheWindowManager)->winSendSystemMsg(m_loneWindow, GGM_CLOSE, 0, 0);
	m_loneWindow = window;
}
