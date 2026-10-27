// cl: /MD /EHsc
// ?Rva00222C93Append@@YAAAVAsciiString@@AAV1@PBD@Z @0x00222C93 56B
// Free concat helper wrapping arg as CharSource then StringBase concat.
// Evidence: EH_prolog plus concat 0x00036A30 plus g_00BE6D5C vtable store plus caller 0x002250F9; same 56B shape as 0x0059B0DD and 0x00317C68.
extern "C" const void *const __identifier("??_7Rva00222A19@@6B@")[];
template <typename T>
class CharSource
{
public:
    virtual int getLength() const = 0;
    virtual void _gap() const = 0;
    virtual int getChars(T *dest) const = 0;
};
#include "../../../../reference/shims/bfme2_ascii/ascii_string.h"
// This view uses the external retail table throughout its lifetime; no
// separate table for the partial method declarations belongs in the link.
class __declspec(novtable) CharSourceNarrow00222C93 : public CharSource<char>
{
public:
    CharSourceNarrow00222C93(const char *s)
    {
        *(const void **)this = __identifier("??_7Rva00222A19@@6B@");
        m_str = s;
    }
    virtual ~CharSourceNarrow00222C93() { *(const void **)this = __identifier("??_7Rva00222A19@@6B@"); }
    int getLength() const;
    void _gap() const;
    int getChars(char *dest) const;
private:
    const char *m_str;
};
AsciiString &Rva00222C93Append(AsciiString &dst, const char *src)
{
    CharSourceNarrow00222C93 tmp(src);
    ((StringBase<char> *)&dst)->concat(tmp);
    return dst;
}

// The global(s) below are defined elsewhere under another name at the same
// address (the census owner of that DIR32 target); bind this unit's spelling.
