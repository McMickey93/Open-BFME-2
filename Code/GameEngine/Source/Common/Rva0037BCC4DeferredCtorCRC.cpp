// cl: /O1 /arch:SSE /G7 /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_STLP_NO_EXCEPTIONS
// Constructor and CRC dispatch retain unresolved provider contracts here.
// The independent version check stays in Rva0037BCC4_Unresolved.cpp.
// ?createRecorder@@YAPAVRecorderClass@@XZ @0x0037BCC4 53B
// Evidence: leaf lane; allocates 0xE7C via rowed ??2 0x0002FDA0 then pinned
// ctor 0x0037BB98 with null check and EH prolog; caller 0x0022F6A1 unclaimed;
// class layout copied from Rva0037BBEDDtor.cpp so sizeof is 0xE7C.
#include "ascii_string.h"
#include "unicode_string.h"
#include "GameLogicObjectLookupView.h"

// Base ctor 0x001B4E63 / dtor 0x001B4E74 by their row names ??0/??1SubsystemInterface (SubsystemInterface.cpp).
#include "../../../Libraries/Source/subsystem/SubsystemInterface.h"

struct _iobuf;

typedef _iobuf FILE;

// Recorder.cpp's GameInfo view, spelled as it is there.
struct BfmeNetAddress { unsigned int address,port;bool Rva00248CBF(const BfmeNetAddress*) const;};
class CreateAHeroData;
class GameSlot { public: char pad000[0x38]; BfmeNetAddress address;char pad40[0x60-0x40];bool heroPresent;char pad61[3];void rva0037AD8D(const CreateAHeroData&);bool isOccupied() const; };
class GameInfo {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void reset();virtual void startGame(int);virtual void slot12();virtual int getLocalSlotNum();
    int field0004;int field0008; int m_crcInterval;
    char pad010[0x38-0x10]; BfmeNetAddress address;
    char pad040[0x50-0x40]; unsigned int m_seed;
    AsciiString getMap() const;
    GameSlot *getSlot(int);const GameSlot *getConstSlot(int) const;void enterGame();void endGame();
    void clearSlotList(); void setMap(AsciiString s); void setSeed(int);
    void setCRCInterval(int n) { m_crcInterval = n < 100 ? n : 100; }
};

// ZH ReplayGameInfo derives from GameInfo; its ctor/dtor are rowed at 0x0037BADD / 0x0037BB53.
class Rva0037BB53 : public GameInfo
{
public:
    Rva0037BB53();
    virtual ~Rva0037BB53();
    char m_pad[0xE3C - sizeof(GameInfo)];
};

class Rva0037D097CRCView
{
public:
    void rva0037D097(unsigned int crc);
    unsigned int rva0037BD64();
};

class Rva0037B5DF;

// Recorder: SubsystemInterface base (ctor 0x0037BB98, vtable 0x00C18828).
// Retail new pushes 0xE7C; the constructor explicitly clears the final +0xE78 word.
class Rva0037BBED : public SubsystemInterface
{
public:
    Rva0037BBED();
    virtual ~Rva0037BBED();
    virtual void init();
    UnicodeString rva0037BCA8();
    AsciiString rva0037B70A();
    bool rva0037CBB6(Rva0037B5DF &header);
    bool rva0037D0EF(UnicodeString filename);
    void rva0037D0A7(unsigned int crc, int player, bool fromPlayback, unsigned int frame);
    Rva0037D097CRCView *m_0c;
    FILE *m_file;
    UnicodeString m_14;
    int m_18;
    int m_1c;
    UnicodeString m_20;
    Rva0037BB53 m_gameInfo;
    int m_crcInterval, m_mode, m_numPlayers, m_localIndex;
    unsigned char m_e70;
    char m_padE71[3];
    int m_e74;
    int m_frameE78;
};

// The CRC queue's list wrappers at 0x0037D097/0x0037BD64 are rowed (ICF-shared)
// under FXList's names; bind to those owners and cast at the call.
class FXNugget;
class FXList
{
public:
    void addFXNugget(FXNugget *nugget);
    int rva0037BD64();
};
class RecorderClass;
RecorderClass *createRecorder();

// Native Ghidra extent 0x0037BB98..0x0037BBED, 85 bytes, thiscall RET 0.
// The existing allocator and destructor establish this receiver and vtable.
// Two default UnicodeStrings and the +0x24 GameInfo-shaped member explain
// EH states 0..3; native calls identify its constructor and the reset worker.
// The ZH Recorder constructor has the same member/reset relationship; target
// offsets and the final +0xE78 clear are taken from retail rather than the donor.
Rva0037BBED::Rva0037BBED()
{
    m_frameE78 = 0;
    init();
}

class GameLogic;
extern GameLogic *TheGameLogic;
class Rva00241529CRCView
{
public:
    char opaque00[0x71];
    bool crcProcessing71;
};

// Native Ghidra 0x0037D0A7..0x0037D0EF; 72 bytes; thiscall RET 16.
// Reference: BFME 1 1399ad37d42ea52a63829e417c46a1ba9ed2cd20,
// game/GameEngine/Source/Common/System/RecorderHandleCRCMessage.cpp.
// The four argument roles and processing sequence follow that readable donor;
// retail proves +0xC receiver storage, +0x71 flag and all three call targets.
// Native rva0037BD64 already checks the queue before removing its front value.
// Its folded list wrappers are named opaquely here: the FXList ledger spelling
// at those addresses does not establish a recorder's CRC storage as FXList.
void Rva0037BBED::rva0037D0A7(unsigned int crc, int player, bool fromPlayback, unsigned int frame)
{
    if (fromPlayback)
        reinterpret_cast<FXList *>(m_0c)->addFXNugget(reinterpret_cast<FXNugget *>(crc));
    reinterpret_cast<FXList *>(m_0c)->rva0037BD64();
    if (frame > 0)
    {
        Rva00241529CRCView *logic = reinterpret_cast<Rva00241529CRCView *>(TheGameLogic);
        if (!logic->crcProcessing71)
            TheGameLogic->ProcessCRC(crc, player, frame, 0, false, 0);
    }
}

