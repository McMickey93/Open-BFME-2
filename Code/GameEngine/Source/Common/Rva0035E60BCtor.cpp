// cl: /MD
// ??0Rva0035E60B@@QAE@XZ @ 0x0035E60B 41B: derived ctor calling base ??0Rva001DBAA4 at 0x001DBAA4.
// Same family as 0x0035E2E6 plus clear +0x24; vtable 0x008165F0 same as dtor ??1Rva0035E378.
// Sets +0x24=0 +0xC=0 +0x20=-1 +0x4=0x11 +0x9=1. Gap between 0x0035E378 and 0x0035E634.
// Opaque address-derived name; base layout copied from Rva001DBAA4Ctor.cpp.
class GameWindow;
class Rva001DBAA4
{
public:
    virtual ~Rva001DBAA4();
    Rva001DBAA4();
    int m_frameLength;      // +0x04
    bool m_isFinished;      // +0x08
    bool m_isForward;       // +0x09
    bool m_isReversed;      // +0x0a
    unsigned char m_pad0B;  // +0x0b
    GameWindow *m_win;      // +0x0c
};
class Rva0035E60B : public Rva001DBAA4
{
public:
    virtual ~Rva0035E60B();
    Rva0035E60B();
    char m_pad10[0x10];
    int m_20;
    int m_24;
};
Rva0035E60B::Rva0035E60B()
{
    m_24 = 0;
    m_win = 0;
    m_20 = -1;
    m_frameLength = 0x11;
    m_isForward = true;
}
