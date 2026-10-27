// cl: /MD
// ??0Rva0035F4A6@@QAE@XZ @ 0x0035F4A6 37B: derived ctor calling base ??0Rva001DBAA4 at 0x001DBAA4.
// Same shape as 0x0035E2E6/0x0035EE66/0x0035E60B; vtable 0x0081665C same as dtor ??1Rva0035F42E at 0x0035F42E.
// Clears +0xC then sets +0x20=-1 +0x4=0xA +0x9=1. Gap between 0x0035F42E and 0x0035F4CB in FamilyTailDtors1DBAC3.cpp.
// Factory 0x0035F4E7 news 0x24, sole caller 0x0035F509. Opaque address-derived name; base layout from Rva001DBAA4Ctor.cpp.
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
class Rva0035F4A6 : public Rva001DBAA4
{
public:
    virtual ~Rva0035F4A6();
    Rva0035F4A6();
    char m_pad10[0x10];
    int m_20;
};
Rva0035F4A6::Rva0035F4A6()
{
    m_win = 0;
    m_20 = -1;
    m_frameLength = 0xA;
    m_isForward = true;
}
