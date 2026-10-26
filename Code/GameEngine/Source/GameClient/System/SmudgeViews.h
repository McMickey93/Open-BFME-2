#ifndef BFME2_SMUDGE_MANAGER_VIEWS_H
#define BFME2_SMUDGE_MANAGER_VIEWS_H

// Shared manager declaration for the verified Smudge TU fragments.
// DLListClass is supplied by each fragment. Retail constructor stores locate
// the hardware status at +4, the two 12-byte lists at +8/+0x14 and count at +0x20.
struct SmudgeSet;

class SmudgeManager
{
public:
    SmudgeManager(void);
    virtual ~SmudgeManager();
    virtual void init(void);
    virtual void reset(void);

    SmudgeSet *addSmudgeSet(void);
    void removeSmudgeSet(SmudgeSet &mySmudge);

protected:
    enum HardwareSmudgeSupport { SMUDGE_SUPPORT_UNKNOWN, SMUDGE_SUPPORT_NO, SMUDGE_SUPPORT_YES };
    HardwareSmudgeSupport m_hardwareSupportStatus;
    DLListClass<SmudgeSet> m_usedSmudgeSetList;
    DLListClass<SmudgeSet> m_freeSmudgeSetList;
    Int m_smudgeCountLastFrame;
};

#endif
