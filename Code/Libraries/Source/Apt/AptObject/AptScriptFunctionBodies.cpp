// cl: /O2 /MD /EHsc /GR-
#include "AptScriptFunction.h"

// PC vtable8EE9A0 slot20 points to709D30. Its21 bytes equal the original donor
// body; the single ret4 argument is the hidden structure-return pointer.
AptConstantPool AptScriptFunction2::GetConstantPool()
{
    return mpFunction->constantPool;
}

// Original donor virtual slots23 and PC full67/130B bodies establish both
// cleanup methods. The later source retains this frame restoration and register
// release loop. PC reads frame reserve+2C and saved frame/register pointers+0/+4.
// The inline base emits its own COMDAT and is inlined in Function2 as in retail.
extern AptValue *gpUndefinedValue;
inline void AptScriptFunctionBase::CleanupAfterExecution(_AptScriptFunctionState *pState)
{
    if(spFrameStack) {
        mnFrameStackReserve = (unsigned short)spFrameStack->GetNativeHashVirtual()->mnTotalSize;
        spFrameStack->Release();
    }
    spFrameStack = pState->mpFrameStack;
}
void AptScriptFunction2::CleanupAfterExecution(_AptScriptFunctionState *pState)
{
    AptScriptFunctionBase::CleanupAfterExecution(pState);
    for(int i=0; i<snRegBlockCurrentFrameCount; ++i) {
        AptValue *pValue=spRegBlockCurrentFrameBase[i];
        spRegBlockCurrentFrameBase[i]=gpUndefinedValue;
        pValue->Release();
    }
    snRegBlockCurrentFrameCount=spRegBlockCurrentFrameBase-pState->mpRegBlockPreviousFrameBase;
    spRegBlockCurrentFrameBase=pState->mpRegBlockPreviousFrameBase;
}

// Native E1835C starts at zero. Existing address-derived frame-root users
// bind this one definition through their linker aliases.
AptFrameStack *AptScriptFunctionBase::spFrameStack;

class EAStringC
{
public:
    EAStringC(const char *);
    ~EAStringC();
private:
    void *data;
};
EAStringC *Rva0070B4F0GetString(int);
extern AptValue *gpGlobalGlobalObject;
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *,const char *,int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
// Original PDB and PC vtable8EE9A0 slot21 establish the two-argument API.
// Later APT source supplies the preload algorithm; its override-this/super
// arguments were added after this version and are absent in the PC body.
// Native+0A flag tests and constant-string IDs A4/A0 establish the target data.
__forceinline AptValue **advanceRegisters(AptValue **aptValue,int n) { return aptValue+n; }
void AptScriptFunction2::SetupBeforeExecution(_AptScriptFunctionState *pState, AptValue *pContext)
{
    pState->mpFrameStack=spFrameStack;
    spFrameStack=0;
    pState->mpRegBlockPreviousFrameBase=spRegBlockCurrentFrameBase;
    spRegBlockCurrentFrameBase=advanceRegisters(spRegBlockCurrentFrameBase,snRegBlockCurrentFrameCount);
    snRegBlockCurrentFrameCount=0;
    AptValue *pTemp=0;
    int nStartReg=1;
    if(mpFunction->getDF2Flag(1)) {
        pTemp=((AptValue *)mpCIH)->findChild(Rva0070B4F0GetString(0xA4),0);
        AptScriptFunctionBase::SetRegisterValue(nStartReg++,pTemp);
    }
    if(mpFunction->getDF2Flag(4)) {
        g_bfmeAptAssertAtE17734("false && \"Arguments Array is unsupported in Apt at this time.\"", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptObject\\AptScriptFunction.cpp", 0x303);
        if(g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
        AptScriptFunctionBase::SetRegisterValue(nStartReg++,gpUndefinedValue);
    }
    if(mpFunction->getDF2Flag(0x10)) {
        pTemp=pContext->findChild(Rva0070B4F0GetString(0xA0),0);
        if(pTemp==0 || !pTemp->getIsDefined()) pTemp=((AptValue *)mpCIH)->findChild(Rva0070B4F0GetString(0xA0),0);
        AptScriptFunctionBase::SetRegisterValue(nStartReg++,pTemp);
    }
    if(mpFunction->getDF2Flag(0x40)) {
        EAStringC pTmpStr="_root";
        pTemp=((AptValue *)mpCIH)->findChild(&pTmpStr,0);
        AptScriptFunctionBase::SetRegisterValue(nStartReg++,pTemp);
    }
    if(mpFunction->getDF2Flag(0x80)) {
        EAStringC pTmpStr="_parent";
        pTemp=((AptValue *)mpCIH)->findChild(&pTmpStr,0);
        if(pTemp==0) pTemp=gpUndefinedValue;
        AptScriptFunctionBase::SetRegisterValue(nStartReg++,pTemp);
    }
    if(mpFunction->getDF2Flag(0x100)) AptScriptFunctionBase::SetRegisterValue(nStartReg++,gpGlobalGlobalObject);
}

// Existing providers own the predicate and the zero-initialized global storage.
#pragma comment(linker, "/alternatename:?gpGlobalGlobalObject@@3PAVAptValue@@A=?g_00E18650@@3VEAStringC@@A")

// The base constructors and their private views live in
// AptScriptFunctionBodies_AptScriptFunctionBase.cpp. Keep their shared storage
// here without reintroducing those constructors' unused inline helpers.
class AptPrototype;
// Native E180F0 is zero-filled; this unit owns the storage.
AptPrototype *gpObjectPrototype;
