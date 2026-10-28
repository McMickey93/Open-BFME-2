#include "AptObject/AptScriptFunction.h"
// cl: /MD
// May 2006 Xbox APT0.19.03 PDB supplies member names and class identity.
// Target startup 7B67A0 constructs global VA E182E0 with 6FE980, then registers
// cleanup 7B9C50, which passes the same global to destructor 6FE9C0. That
// destructor and AptActionInterpreter.cpp assertion caller 6FEB50 operate on
// debugCallStack at +34 (see AptInterpreterDebugStack.cpp).
// Target independently establishes zero initialization of five 12-byte stacks
// at 0/C/18/24/34, leaving +30 alone. Only the accessed prefix is modeled;
// donor names/types describe the stack roles, not a recovered full class ABI.
class AptValue;
class AptScriptFunctionBase;
class Rva006DB270;
struct AptInitParmsT
{
    int f00[8];
    int cap0;
    int capRest;
};
template<class T> struct AptValuePtrStack {
    int count, capacity;
    AptValue **items;
    AptValuePtrStack() : count(0), capacity(0), items(0) {}
};
class Rva006FBDB0;
struct AptCallDebugStack {
    int count, capacity;
    Rva006FBDB0 **items;
    AptCallDebugStack() : count(0), capacity(0), items(0) {}
};
template<class T> class AptDebugStack
{
    int m_nElements;
    int m_nCapacity;
    T **m_aElements;
public:
    void Rva006FE1D0(int nCapacity);
};
class AptBasePtrStack
{
public:
    int count, capacity;
    AptValue **items;
    AptBasePtrStack() : count(0), capacity(0), items(0) {}
    void rva006FDDB0(int nCapacity);
    void rva006FE0B0(int nSize);
};
struct AptActionInterpreter {
    struct DebugCallStackInfo_t;
    AptBasePtrStack stack;
    AptValuePtrStack<AptValue> withStack, setTargetStack, thisStack;
    AptScriptFunctionBase *mpCurrentFunction;
    AptCallDebugStack debugCallStack;
    unsigned char gap40[36];
    int mnStackFrameBase;
    unsigned char f68;
    void rva006FEAF0(const AptInitParmsT &parms);
    AptActionInterpreter();
};
AptActionInterpreter::AptActionInterpreter() {}

void AptActionInterpreter::rva006FEAF0(const AptInitParmsT &parms)
{
    stack.rva006FDDB0(parms.cap0);
    ((AptBasePtrStack *)&withStack)->rva006FE0B0(parms.capRest);
    ((AptBasePtrStack *)&setTargetStack)->rva006FE0B0(parms.capRest);
    ((AptBasePtrStack *)&thisStack)->rva006FE0B0(parms.capRest);
    f68 = 0;
    mnStackFrameBase = 0;
    ((AptDebugStack<DebugCallStackInfo_t> *)&debugCallStack)->Rva006FE1D0(parms.capRest);
    AptScriptFunctionBase::InitializeStaticData(parms);
}
