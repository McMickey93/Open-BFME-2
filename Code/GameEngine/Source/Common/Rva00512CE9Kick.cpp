// cl: /DNDEBUG /MD /EHs /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// stlport
//
// ?rva00512CE9@AptDisconnectScreen@@QAEXH_N@Z, retail 0x00512CE9, 94 bytes.
// Kick-button UI: formats player index via sprintf %d then invokes Apt
// ShowKickButton/HideKickButton with 1 plus buffer plus 0s plus owner at
// +0x274 via TheAptPlayer at 0x9FE4CC (SubsystemInterface registers it)
// and stores bool to +0x286 indexed array. Callers at 0x4D45F6 etc.
// Flags /O1 /MD (EBP frame, sprintf IAT, no EH, no STL).
// Views and flags are those of the approved TU, DisconnectMenu.cpp; sprintf
// stays an IAT call (the TU's /D_CRTIMP= would make it a thunk call).
#include <vector>
#include "ascii_string.h"
#include "unicode_string.h"
#include <string.h>
#pragma pointers_to_members(full_generality, multiple_inheritance)

class GameWindow
{
protected:
	virtual ~GameWindow();

private:
	unsigned char m_pad004[0x218 - 4];
};

// The Apt window manager (VA 0x00DFE4CC) and its background switch.
class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &key, const UnicodeString &text, bool usePlaceholder);
};

extern BfmeAptWindowManager *g_bfmeAptWindowManager;

// The Apt callback functors (Rva0057BC63FunctorHolder.cpp, as in
// AptScoreScreenCallbacks.cpp).
class __multiple_inheritance FunctorTarget;

typedef void (FunctorTarget::*FunctorMethod)(void);

struct FunctorBinding
{
	FunctorBinding(FunctorMethod method, FunctorTarget *target) : m_target(target), m_method(method) {}

	FunctorTarget *m_target;
	unsigned int m_pad;
	FunctorMethod m_method;
};

class FunctorWrapperHead
{
public:
	void *m_vtbl;
	int m_refCount; // +0x04
};

class Rva0057BC63FunctorHolder
{
public:
	Rva0057BC63FunctorHolder(const FunctorBinding &binding);
	Rva0057BC63FunctorHolder(const Rva0057BC63FunctorHolder &other) : m_ptr(other.m_ptr)
	{
		if (m_ptr)
			++m_ptr->m_refCount;
	}

	FunctorWrapperHead *m_ptr;
};

struct TargetRef00217D4C;

void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *ref);

template <class T> class AptRef : public Rva0057BC63FunctorHolder
{
public:
	AptRef(const FunctorBinding &binding) : Rva0057BC63FunctorHolder(binding) {}
	~AptRef()
	{
		if (m_ptr)
			ReleaseTreeHintRef00217D4C((TargetRef00217D4C *)m_ptr);
	}
};

class AptCommandMap;

class AptExternHandler;

class AptCommandMapAdder
{
public:
	void AddCommandMap(const AsciiString &name, AptRef<AptCommandMap> map);

private:
	_STL::vector<AsciiString> m_names;
};

class AptExternHandlerAdder
{
public:
	void AddExternHandler(const AsciiString &name, int arg, AptRef<AptExternHandler> handler);

private:
	_STL::vector<AsciiString> m_names;
};

class AptScreenInitGadgets;

void _bfme_setAptScreenRef(const AsciiString &name, AptRef<AptScreenInitGadgets> ref);

void _bfme_closeAptScreen(const AsciiString &name);

// The Apt screen base (BfmeAptGameWindowDestructor.cpp): a 0x218-byte
// GameWindow and, at +0x218, the 0x58-byte callback registry.
class Rva005248D0
{
public:
	virtual ~Rva005248D0();

	AptCommandMapAdder m_commandMaps; // +0x04
	AptExternHandlerAdder m_externHandlers; // +0x10

private:
	unsigned char m_pad01C[0x58 - 0x1C];
};

class _bfme_AptGameWindow : public GameWindow, public Rva005248D0
{
public:
	_bfme_AptGameWindow(void *context);
	virtual ~_bfme_AptGameWindow();

private:
	AsciiString m_filename; // +0x270

protected:
	int m_274;

private:
	char m_278;
};

// The open disconnect menu (VA 0x00E048D0; BFME 1's TheDisconnectMenu).
class DisconnectMenu;

 extern DisconnectMenu *TheDisconnectMenu;

class AptDisconnectScreen : public _bfme_AptGameWindow
{
public:
	AptDisconnectScreen(void *context);
	// Shows or hides a slot's kick button and records it at +0x286
	// (rowed in Rva00512CE9Kick.cpp).
	void rva00512CE9(int player, bool show);
	// Whether a slot's kick button is shown (+0x286).
	bool rva00512D47(int player);
	virtual ~AptDisconnectScreen();

	// AptDisconnectScreenKick.cpp and AptLobbyScreenInitCallbacks.cpp.
	void InitGadgets(const char *name, void *argument, GameWindow *window);
	void OnInitialized(const char *unused);
	void Quit(const char *unused);
	void Kick(const char *slot);
	void OnBttnEnterText(const char *unused);
	void PlayerColor(int slot, char *result, bool skip);
	// Unrowed 0x00512EDD: empties a slot's name (BFME 1's
	// DisconnectMenu::removePlayer), pinned by address.
	void rva00512EDD(int slot, UnicodeString name);
	// Vslot 5: re-applies the kick buttons once they changed.
	int rva00512DB1();

private:
	GameWindow *m_chatBox; // +0x27C
	GameWindow *m_chatEntry; // +0x280
	bool m_kickButtonsDirty; // +0x284
	bool m_quit; // +0x285
	bool m_kickButtons[8]; // +0x286
};

class Rva00222A8BTarget
{
public:
	void rva00222F55(bool show);
public:
	void rva002233A6(int mode);
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern "C" __declspec(dllimport) int __cdecl sprintf(char *, const char *, ...);

void AptDisconnectScreen::rva00512CE9(int player, bool show)
{
	char buf[32];
	sprintf(buf, "%d", player);
	const char *which = show ? "ShowKickButton" : "HideKickButton";
	(*(Rva00222A8BTarget **)&g_bfmeAptWindowManager)->invoke((void *)m_274, which, 1, buf, 0, 0, 0, 0);
	m_kickButtons[player] = show;
}

// ?rva00512D47@AptDisconnectScreen@@QAE_NH@Z @0x00512D47 14B: getter for m_286[player] bool array at +0x286.
// Evidence: same +0x286 indexed store in rva00512CE9 setter in this TU; callers at 0x004D45CB 0x004D45E4.
bool AptDisconnectScreen::rva00512D47(int player)
{
	return m_kickButtons[player];
}
