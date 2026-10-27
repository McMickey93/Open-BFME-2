// cl: /MD /DNDEBUG
// platformsdk
// ?? method at retail 0x001543E0 (14 B).
// Register-variant sibling of the rowed ?_Atomic_swap@_STL@@YAJPCJJ@Z
// 0x00006EF0 (17 B): both are two-operand wrapper calls whose only operand is
// a DIR32 IAT slot. The imported target here is gdi32!SelectObject, not
// InterlockedExchange, which the import gate proves from the PE import
// directory at 0x00BBA0D8 -- so this is a GDI object selection wrapper, not an
// atomic swap. The recipe difference is thiscall: the HDC member at +0 and
// the object member at +4 are loaded into eax/ecx and pushed object-then-DC,
// exactly the shape the template pushes its two values. Identity unproven (no
// caller, no symbol), so it is outlined under an honest address-derived name.

#include <windows.h>

class Rva001543E0
{
public:
	HGDIOBJ Apply();
private:
	HDC m_hdc;
	HGDIOBJ m_object;
};

HGDIOBJ Rva001543E0::Apply()
{
	return SelectObject(m_hdc, m_object);
}
