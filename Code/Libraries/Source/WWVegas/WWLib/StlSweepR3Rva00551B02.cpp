// STLport 4.5.3 reference instantiation. Target boundary and byte comparison prove operation shape.
// Element spelling/layout is donor inference; opaque records have address-derived identity.
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport

#include <memory>

// Retail's record destructor is the rowed ??1GameSpyBuddyMessageQueue@@UAE@XZ (0x00551988,
// BuddyThread_Unresolved.cpp); dllimport+forceinline calls it by that name and emits
// no ??1Rva00551B02Record copy (FamilyDeletingDtors2.cpp precedent).
struct GameSpyBuddyMessageQueue { virtual ~GameSpyBuddyMessageQueue(); };
struct Rva00551B02Record { __declspec(dllimport) __forceinline ~Rva00551B02Record() { ((GameSpyBuddyMessageQueue *)this)->GameSpyBuddyMessageQueue::~GameSpyBuddyMessageQueue(); } char bytes[1]; };
// Scalar destruction also emits the compiler-generated deleting destructor.
template void _STL::_Destroy<Rva00551B02Record>(Rva00551B02Record *);
