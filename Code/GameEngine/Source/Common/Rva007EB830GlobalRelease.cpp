// Open-BFME: global pointer release reconstructed from retail RVA 0x007EB830.

class Rva007EB830Target
{
public:
    virtual void unused0(void);
    virtual void unused1(void);
    virtual void unused2(void);
    virtual void unused3(void);
    virtual void unused4(void);
    virtual void release(int value);
};

extern int g_FeslDiagReporter;

void Rva007EB830Release(void)
{
    if (g_FeslDiagReporter != 0)
    {
        ((Rva007EB830Target *)g_FeslDiagReporter)->release(1);
    }
    g_FeslDiagReporter = 0;
}
