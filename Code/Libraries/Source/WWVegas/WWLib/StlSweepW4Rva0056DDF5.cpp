// STLport4.5.3 reference operation. Target boundary, calls and full bytes are verified.
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// stlport
//
// 0x0056DDF5 is pair<const UnicodeString, int>'s (key, value) constructor:
// the key is copied by a direct call to the StringBase<unsigned short> copy
// constructor at 0x00037050 (UnicodeString's copy constructor is inlined to
// exactly that call) and the four-byte value is stored at +4. The map of the
// same pair (the online country list, stlport_online_country_tree.cpp)
// inlines this constructor; this out-of-line copy has no direct caller.
#include <utility>
#include "unicode_string.h"

template _STL::pair<const UnicodeString, int>::pair(const UnicodeString &, const int &);
