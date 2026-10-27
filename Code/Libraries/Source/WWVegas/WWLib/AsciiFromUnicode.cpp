// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// Reference: BFME1 ascii/unicode string construction/translation family.
// Explicit BFME2 export ??0AsciiString@@QAE@ABVUnicodeString@@@Z identifies
// RVA38250 (91 bytes). Its exported wide translate38170 distinguishes it
// from the masked-identical reverse conversion6CB6D0; no duplicate range.
typedef unsigned short Wide;
#include "unicode_string.h"
// The owned StringBase member supplies the null initialization and cleanup.
// Its lifetime preserves the constructor's exception handling.
template <> __declspec(dllimport) __forceinline
StringBase<char>::StringBase() : m_data(0) {}
#define BFME_ASCII_IMPLICIT_DTOR
#include "../../../../../reference/shims/bfme2_ascii/ascii_string.h"
AsciiString::AsciiString(const UnicodeString& text) {
    translate(text.str());
}
