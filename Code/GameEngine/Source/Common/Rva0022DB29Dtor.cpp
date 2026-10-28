// cl: /DNDEBUG /MD /EHs
// ??1Rva0022DB29@@QAE@XZ @0x0022DC62 57B: hash-table scalar dtor clears via rowed 0x0022DB29 then inline bucket-handle member dtor frees array at +4. Evidence: chain packet plus outer 0x00418298 lea-ecx-+0xC call plus 5B jmp at 0x0022DE29.

// Retail calls free directly (the game allocator), not through the CRT
// import: read <stdlib.h> without dllimport. /EHs lets free throw,
// preserving retail's unwind states.
#define _CRTIMP
#include <stdlib.h>
#undef _CRTIMP

struct Rva0022D9B7Node;
struct Rva0022DB29BucketHandle
{
	~Rva0022DB29BucketHandle()
	{
		if (m_beginBuckets)
			free(m_beginBuckets);
	}
	Rva0022D9B7Node **m_beginBuckets;
	Rva0022D9B7Node **m_endBuckets;
	Rva0022D9B7Node **m_storageEnd;
};
class Rva0022DB29
{
public:
	~Rva0022DB29();
	void rva0022DB29();
private:
	int m_unk0;
	Rva0022DB29BucketHandle m_buckets;
	int m_count;
};
Rva0022DB29::~Rva0022DB29()
{
	rva0022DB29();
}
