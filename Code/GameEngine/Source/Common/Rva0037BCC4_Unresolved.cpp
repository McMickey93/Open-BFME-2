// cl: /O1 /arch:SSE /G7 /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /Ireference/shims/sweep /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_STLP_NO_EXCEPTIONS
// Independent recorder version check. The constructor and CRC dispatcher
// retain their unresolved contracts in Rva0037BCC4DeferredCtorCRC.cpp.
// ?createRecorder@@YAPAVRecorderClass@@XZ @0x0037BCC4 53B
// Evidence: leaf lane; allocates 0xE7C via rowed ??2 0x0002FDA0 then pinned
// ctor 0x0037BB98 with null check and EH prolog; caller 0x0022F6A1 unclaimed;
// class layout copied from Rva0037BBEDDtor.cpp so sizeof is 0xE7C.
#include "ascii_string.h"
#include "unicode_string.h"
#include <windows.h>
#include "GameLogicObjectLookupView.h"
template <> int StringBase<unsigned short>::compare(const StringBase<unsigned short> &) const throw();

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

class GlobalData {public:AsciiString rva002360DE() const;char p0[0xc];AsciiString m_mapName;char p10[0xac0-0x10];AsciiString pendingFile;char pAC4[0xb04-0xac4];unsigned int field0b04;char pB08[0x1100-0xb08];bool field1100;char p1101[3];int field1104;};
extern GlobalData *TheWritableGlobalData;

// Same 0x5C string-bearing header as the independently rowed destructor,
// spelled as Recorder.cpp's view.
class Rva0037B5DF {
public:
 ~Rva0037B5DF();
 int start,end,frame,crcInterval,mode;
 bool quitEarly,disconnected[8];char pad1D[3];
 AsciiString options;int localIndex;UnicodeString filename;bool forPlayback;char pad2D[3];
 UnicodeString name;SYSTEMTIME time;UnicodeString version,versionTime;
 unsigned int crc4C;bool flag50;char pad51[3];int word54;UnicodeString str58;
};
class Version { public: UnicodeString getFullUnicodeVersion(); UnicodeString getUnicodeBuildTime(); };
extern Version *TheVersion;

// Native Ghidra 0x0037D0EF..0x0037D1E6; 247 bytes; thiscall RET 4.
// ZH Recorder::testVersionPlayback and BFME1 1399ad37 RecorderReadReplayHeader
// supply the comparison sequence. Target uses a Unicode filename and omits
// the donor's version-number/executable checks. The destructor proves header
// storage; retail proves forPlayback+2C, version+44/+48, and CRC+4C/global+B04.
bool Rva0037BBED::rva0037D0EF(UnicodeString filename)
{
    Rva0037B5DF header;
    header.forPlayback = true;
    header.filename = filename;
    bool success = rva0037CBB6(header);
    if (!success)
        return false;
    bool versionStringDiff = header.version.compare(TheVersion->getFullUnicodeVersion()) != 0;
    bool versionTimeStringDiff = header.versionTime.compare(TheVersion->getUnicodeBuildTime()) != 0;
    bool exeDifferent = versionStringDiff || versionTimeStringDiff;
    bool iniDifferent = header.crc4C != TheWritableGlobalData->field0b04;
    if (exeDifferent || iniDifferent)
        return true;
    return false;
}
