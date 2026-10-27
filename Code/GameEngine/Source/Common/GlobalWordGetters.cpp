// cl: /GX-
// DynamicVBAccessClass::Get_Default_Vertex_Count, retail 0x0013ABB0 (7 B):
//
//     mov ax,[bfmeDynamicVBSizes+10] / ret
//
// CC-island (8xCC before and after), Ghidra-7; SortingRendererClass::
// Flush_Sorting_Pool and 0x0012E938 call it (call then movzx ecx,ax), as ZH
// sortingrenderer.cpp calls DynamicVBAccessClass::Get_Default_Vertex_Count.
// It reads entry 5 of the dynamic vertex-buffer size pool (0x009F2A64 + 10,
// dx8vertexbuffer.cpp); pool entry 5 holds FVF 0x252 (XYZ|NORMAL|DIFFUSE|TEX2),
// ZH's dynamic_fvf_type, whose buffer size ZH's version returns.
extern unsigned short bfmeDynamicVBSizes[15];

class DynamicVBAccessClass
{
public:
	static unsigned short Get_Default_Vertex_Count(void);
};

unsigned short DynamicVBAccessClass::Get_Default_Vertex_Count(void)
{
	return bfmeDynamicVBSizes[5];
}
