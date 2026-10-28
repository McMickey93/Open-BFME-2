// cl: /DNDEBUG /MD /EHs /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// stlport
//
// BFME2's disconnect screen Apt callbacks "AptDisconnectScreen::Kick"
// (0x00512D55; votes to kick the player in the given slot),
// "DisconnectScreen::InitGadgets" (0x0051321A), "AptDisconnectScreen::Quit"
// (0x005132D2) and "AptDisconnectScreen::Chat::OnBttnEnterText"
// (0x00513382), bound by those names as member pointers by the screen's
// registration; that binding is their only reference.
// Views and flags are those of the approved TU, DisconnectMenu.cpp.
#include <vector>
#include "ascii_string.h"
#include "unicode_string.h"
#include <string.h>
#pragma pointers_to_members(full_generality, multiple_inheritance)
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
	// Shows or hides a slot's kick button and records it at +0x286.
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
	// Zero Hour's DisconnectMenu::sendChat, filtered. Name unknown.
	void rva005130E2(UnicodeString text);

private:
	GameWindow *m_chatBox; // +0x27C
	GameWindow *m_chatEntry; // +0x280
	bool m_kickButtonsDirty; // +0x284
	bool m_quit; // +0x285
	bool m_kickButtons[8]; // +0x286
};

// Retail calls _mbscpy through the import thunk at 0x00629176 but atoi
// through the IAT.
#define _CRTIMP
#include <mbstring.h>
#undef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#include <stdlib.h>

class GameTextInterface
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual UnicodeString fetch(const char *label, bool *exists = 0);
	virtual void v16();
	virtual const UnicodeString *slot44(const char *label, bool *exists);
};

extern GameTextInterface *TheGameText;

void GadgetTextEntrySetText(GameWindow *textEntry, UnicodeString text);
UnicodeString GadgetTextEntryGetText(GameWindow *textEntry);
void GadgetListBoxReset(GameWindow *listBox);
void BfmeGadgetListBoxSetAudioFeedback(GameWindow *listBox, bool enable);
int GadgetListBoxAddEntryText(GameWindow *listBox, UnicodeString text, int color, int row, int column, bool overwrite);


// Rva0066B3E0Adj.cpp's slot translation (0x004D39F0).
int rva0066b3e0(int slot, int localSlot);

class LanguageFilter
{
public:
	void filterLine(UnicodeString &line);
};

extern LanguageFilter *TheLanguageFilter;

// Zero Hour's TheNetwork: vslot 46 is the local slot, vslot 47 a slot's
// player name, vslot 38 votes, vslot 37 quits, vslot 65 tells whether a
// slot is connected and vslot 27 sends disconnect chat.
class NetworkInterface
{
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26();
	virtual void v27(UnicodeString text);
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36();
	virtual void v37();
	virtual void v38(int slot);
	virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
	virtual void v43(); virtual void v44(); virtual void v45();
	virtual int v46();
	virtual UnicodeString v47(int slot);
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
	virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
	virtual void v64();
	virtual bool v65(int slot);
};

extern NetworkInterface *TheNetwork;

static inline bool unicodeIsEmpty(const UnicodeString &text)
{
	const unsigned char *data = *(const unsigned char *const *)&text;
	return data == 0 || *(const unsigned short *)(data + 4) == 0;
}

// Retail 0x00512D55, 66 bytes: "AptDisconnectScreen::Kick".
void AptDisconnectScreen::Kick(const char *slot)
{
	if (slot && *slot)
	{
		int index = atoi(slot);
		int target = rva0066b3e0(index, TheNetwork->v46());
		TheNetwork->v38(target);
	}
}

// Retail 0x0051321A, 184 bytes: bound as "DisconnectScreen::InitGadgets";
// keeps "ChatBox" and the emptied "ChatEntry", and fills "RulesBox" with
// the localized APT:DisconnectRules.
void AptDisconnectScreen::InitGadgets(const char *name, void *argument, GameWindow *window)
{
	if (strcmp(name, "ChatBox") == 0)
		m_chatBox = window;
	else if (strcmp(name, "ChatEntry") == 0)
	{
		m_chatEntry = window;
		GadgetTextEntrySetText(window, UnicodeString::TheEmptyString);
	}
	else if (strcmp(name, "RulesBox") == 0)
	{
		GadgetListBoxReset(window);
		BfmeGadgetListBoxSetAudioFeedback(window, true);
		GadgetListBoxAddEntryText(window, TheGameText->fetch("APT:DisconnectRules"), -1, -1, -1, true);
	}
}

// Retail 0x005130E2, 84 bytes. Name unknown. Zero Hour's
// DisconnectMenu::sendChat with the line passed through the language filter
// first.
void AptDisconnectScreen::rva005130E2(UnicodeString text)
{
	if (TheLanguageFilter)
		TheLanguageFilter->filterLine(text);
	TheNetwork->v27(text);
}

// Retail 0x005132D2, 176 bytes: "AptDisconnectScreen::Quit" announces the
// local player's leaving, votes out every unconnected slot and quits.
void AptDisconnectScreen::Quit(const char *unused)
{
	m_quit = true;
	UnicodeString text = TheNetwork->v47(TheNetwork->v46());
	text.concat(L" has left the game.");
	rva005130E2(text);
	for (int slot = 0; slot < 8; ++slot)
	{
		if (!TheNetwork->v65(slot))
			TheNetwork->v38(slot);
	}
	TheNetwork->v37();
}

// Retail 0x00513382, 171 bytes: "AptDisconnectScreen::Chat::OnBttnEnterText"
// takes and clears the chat entry and sends the trimmed line.
void AptDisconnectScreen::OnBttnEnterText(const char *unused)
{
	UnicodeString text;
	if (!m_chatEntry)
		return;
	text.set(GadgetTextEntryGetText(m_chatEntry));
	GadgetTextEntrySetText(m_chatEntry, UnicodeString::TheEmptyString);
	text.trim();
	if (!unicodeIsEmpty(text))
		rva005130E2(text);
}

// Retail 0x00512D97, 26 bytes: "DisconnectScreen:PlayerColor:%d" for each
// slot, an Apt query answering white.
void AptDisconnectScreen::PlayerColor(int slot, char *result, bool skip)
{
	if (!skip)
		_mbscpy(reinterpret_cast<unsigned char *>(result), reinterpret_cast<const unsigned char *>("0xFFFFFFFF"));
}
