// cl: /Od
// Open-BFME5 conversions.

extern "C" void *__cdecl bfmeMalloc1149(unsigned int n);

// g_bfmeHeapSize1149: matched references place it at VA 0xddf520 (zero-filled .bss).
extern "C" unsigned int g_bfmeHeapSize1149 = 0;
// g_bfmeHeapEnd1149: matched references place it at VA 0xddf524 (retail .data initial value 0).
extern "C" char *g_bfmeHeapEnd1149 = 0;
// g_bfmeHeapCur1149: matched references place it at VA 0xddf528 (retail .data initial value 0).
extern "C" char *g_bfmeHeapCur1149 = 0;
// The free-list table at 0x009DF530 is STLport's
// _STL::__node_alloc<false, 0>::_S_free_list (defined by BfmeSmallAllocPR.cpp).
namespace _STL
{
class _Node_alloc_obj;

template <bool __threads, int __inst>
class __node_alloc
{
public:
	static _Node_alloc_obj * volatile _S_free_list[16];
};
}

char *bfmeChunk1149(unsigned int size, int *nobjs)
{
	char *n8;
	unsigned int n7;
	unsigned int n6;

	n6 = size * *nobjs;
	n7 = g_bfmeHeapEnd1149 - g_bfmeHeapCur1149;

	if (n7 >= n6) {
		n8 = g_bfmeHeapCur1149;
		g_bfmeHeapCur1149 += n6;
		return n8;
	} else if (n7 >= size) {
		*nobjs = (int)(n7 / size);
		n6 = size * *nobjs;
		n8 = g_bfmeHeapCur1149;
		g_bfmeHeapCur1149 += n6;
		return n8;
	} else {
		unsigned int n5 = 2 * n6 + (((g_bfmeHeapSize1149 >> 4) + 7) & ~7);

		if (n7 > 0) {
			char **n4 = (char **)_STL::__node_alloc<false, 0>::_S_free_list + ((n7 - 1) >> 3);

			*(char **)g_bfmeHeapCur1149 = *n4;
			*n4 = g_bfmeHeapCur1149;
		}

		g_bfmeHeapCur1149 = (char *)bfmeMalloc1149(n5);

		if (g_bfmeHeapCur1149 == 0) {
			unsigned int n2;
			char **n1;
			char *n3;

			for (n2 = size; n2 <= 0x80; n2 += 8) {
				n1 = (char **)_STL::__node_alloc<false, 0>::_S_free_list + ((n2 - 1) >> 3);
				n3 = *n1;
				if (n3 != 0) {
					*n1 = *(char **)n3;
					g_bfmeHeapCur1149 = n3;
					g_bfmeHeapEnd1149 = g_bfmeHeapCur1149 + n2;
					return bfmeChunk1149(size, nobjs);
				}
			}

			g_bfmeHeapEnd1149 = 0;
			g_bfmeHeapCur1149 = (char *)bfmeMalloc1149(n5);
		}

		g_bfmeHeapSize1149 += n5;
		g_bfmeHeapEnd1149 = g_bfmeHeapCur1149 + n5;
		return bfmeChunk1149(size, nobjs);
	}
}
