// cl: /O1 /arch:SSE /G7 /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_STLP_NO_EXCEPTIONS
// ?createRecorder@@YAPAVRecorderClass@@XZ @0x0037BCC4 53B
// Evidence: leaf lane; allocates 0xE7C via rowed ??2 0x0002FDA0 then pinned
// ctor 0x0037BB98 with null check and EH prolog; caller 0x0022F6A1 unclaimed;
// class layout copied from Rva0037BBEDDtor.cpp so sizeof is 0xE7C.
#include "ascii_string.h"
#include "unicode_string.h"

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

class RecorderClass;
RecorderClass *createRecorder()
{
    return reinterpret_cast<RecorderClass *>(new Rva0037BBED);
}


// Native Ghidra extent 0x0037B326..0x0037B3D1, 171 bytes, thiscall RET 0.
// The recorder vtable at VA 0x00C18828 places this method in slot 1.
// ZH Recorder::init supplies the clear/reset/map/seed sequence; retail proves
// every receiver/global offset and the additional CRC/analysis state stores.
// Separate setMap calls preserve retail's two by-value argument temporaries.
class GlobalData {public:AsciiString rva002360DE() const;char p0[0xc];AsciiString m_mapName;char p10[0xac0-0x10];AsciiString pendingFile;char pAC4[0xb04-0xac4];unsigned int field0b04;char pB08[0x1100-0xb08];bool field1100;char p1101[3];int field1104;};
extern GlobalData *TheWritableGlobalData;
extern int NET_CRC_INTERVAL;
unsigned int GetGameLogicRandomSeed();
void Rva0037BBED::init()
{
	m_file = 0;
	m_e74 = 9;
	m_1c = 2;
	m_14.clear();
	m_18 = 0;
	GameInfo *gi = &m_gameInfo;
	gi->clearSlotList();
	gi->reset();
	const GlobalData *wd = TheWritableGlobalData;
	if (((const StringBase<char> &)wd->pendingFile).isEmpty())
		gi->setMap(wd->m_mapName);
	else
		gi->setMap(wd->pendingFile);
	gi->setSeed(GetGameLogicRandomSeed());
	m_mode = -1;
	m_crcInterval = NET_CRC_INTERVAL;
	m_numPlayers = 0;
	m_localIndex = -1;
	m_e70 = 0;
}

extern "C" __declspec(dllimport) int __cdecl fgetc(_iobuf *file);

// Native Ghidra 0x0037B70A..0x0037B7C7; 189 bytes; hidden return buffer/RET 4.
// ZH GeneralsMD Code/GameEngine/Source/Common/Recorder.cpp readAsciiString
// (via BFME1 reference 1399ad37) supplies the zeroed 1024-byte buffer and loop.
// Retail proves FILE* storage at +0x10, fgetc IAT, terminal byte at 1023,
// and StringBase<char> text/copy/release workers. Shared AsciiString preserves
// the observed local temporary, copied return value, and unwind cleanup.
AsciiString Rva0037BBED::rva0037B70A()
{
    char str[1024] = "";
    int index = 0;
    int c = fgetc(m_file);
    if (c == -1)
        str[index] = 0;
    str[index] = c;
    while (index < 1024 && str[index] != 0)
    {
        ++index;
        int c = fgetc(m_file);
        if (c == -1)
        {
            str[index] = 0;
            break;
        }
        str[index] = c;
    }
    str[1023] = 0;
    AsciiString retval(str);
    return retval;
}
