// cl: /GX-
// Global word getters: seven-byte functions with one shape:
//
//     mov ax,[<GLOBAL>] / ret
//
// One unsigned word is read from a fixed .data global and returned in ax.
// Callers consume only ax (movzx ecx,ax), so the upper half of eax is
// unwitnessed; the return is spelled `unsigned short` to match that use.
// Identity unrecoverable, so globals and functions are address-derived
// (g_Va<VA> / Rva<RVA>Get) following the GlobalGetterSingles convention.
// Opaque names witness only the address and the global.

extern unsigned short g_Va00DFA2E6;
// g_Va00DFA2E6: matched references place it at VA 0xdf2a6e (zero-filled .bss).
unsigned short g_Va00DFA2E6;

// ?Get_Default_Vertex_Count@DynamicVBAccessClass@@SAGXZ @ 0x0013ABB0 (7B)
// over 0x00DFA2E6 (the dynamic vertex buffer size). CC-island (8xCC before and
// after), Ghidra-7; SortingRendererClass::Flush_Sorting_Pool and 0x0012E938
// call it (call then movzx ecx,ax), as ZH sortingrenderer.cpp calls
// DynamicVBAccessClass::Get_Default_Vertex_Count.
class DynamicVBAccessClass
{
public:
	static unsigned short Get_Default_Vertex_Count(void);
};

unsigned short DynamicVBAccessClass::Get_Default_Vertex_Count(void)
{
	return g_Va00DFA2E6;
}
