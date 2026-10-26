// cl: /Ireference/shims/bfme2_ascii /O1 /arch:SSE /GX /MD /DNDEBUG /Ireference/shims/moduledata
// ??1W3DModelDrawModuleData@@UAE@XZ @0x000C8BE0 292B
// Banked attempt reverse/attempts/0x000c8be0.cpp, re-verified exact against the current ledger
// (its callees have since been rowed or pinned); landed unchanged by the
// banked-attempt sweep. Identity and evidence: see reverse/re_attempts.log.
//
// ??1W3DModelDrawModuleData@@UAE@XZ, retail 0x000C8BE0, 292 bytes (Ghidra FUN_004c8be0).
// W3DModelDraw ModuleData base dtor: reinstalls vtable 0xBCADE8, tears down
// the +0x160 array via ehvec 0x629110, 7 vectors, 9 strings via folded
// 0x36410, record 0x79554, then restores Snapshot base 0xBBB554.
// Anchors: 3 matched subclass dtors call base pin 0xC8BE0 (Supply 0xCAF30,
// Tank 0xCE764, Truck 0xCB28E) + matched deleting wrapper 0xC8DC3 (slot 0
// of 0xBCADE8, calls 0xC8BE0 + 0x2FD60). Primary guide: clean BFME1
// W3DModelDrawModuleDataDestructorThunk.cpp (empty dtor shape, /DNDEBUG
// /MD /EHsc, member-then-base ordering). Ghidra 292B boundary verified:
// C9 C3 at 0xC8D03, next FUN_004c8d04 (overflow 191B) at 0xC8D04, no overlap
// with writer-12 C8EEF (599B at 0xC8EEF). Seat-51 r23 596B funclet-conflated
// extent NOT used. No fake empty provider (DeletingDtors scaffold untouched).
// 51r24 recipe unavailable (no r24 file, only through r23).

#include "Common/Snapshot.h"

#include "ascii_string.h"

// Rowed providers (declare-only, resolve to ledger rows, no definitions here).
// Every vector member's default construction calls the one ICF-folded empty
// _Vector_base ctor at 0x00211E58 with a reused one-byte allocator temporary
// ([ebp-0xD] in retail). The fold has one primary row,
// _Vector_base<int, allocator<int> >'s ctor, so the declare-only views below
// reach it under that name; the folded bodies are byte-identical.
namespace _STL
{
template <class T> class allocator
{
public:
	allocator() {}
};

template <class T, class A> class _Vector_base;
template <> class _Vector_base<int, allocator<int> >
{
public:
	int *_M_start;
	int *_M_finish;
	int *_M_end_of_storage;
	_Vector_base(const allocator<int> &a) throw();
};

template <class T, class A = allocator<T> > class vector;
}

typedef _STL::_Vector_base<int, _STL::allocator<int> > Rva00211E58VectorBase;
typedef _STL::allocator<int> Rva00211E58Alloc;

struct Rva000C0495 : Rva00211E58VectorBase
{
	Rva000C0495(const Rva00211E58Alloc &alloc = Rva00211E58Alloc()) : Rva00211E58VectorBase(alloc) {}
	~Rva000C0495();
};

class BfmeNarrowRecord00079C23 { public: BfmeNarrowRecord00079C23(); };
struct Rva00079554Record
{
	unsigned char m_pad[0x2C];
	// Construction is the rowed ??0BfmeNarrowRecord00079C23, reached by a qualified call.
	__declspec(dllimport) __forceinline Rva00079554Record() { ((BfmeNarrowRecord00079C23 *)this)->BfmeNarrowRecord00079C23::BfmeNarrowRecord00079C23(); }
	~Rva00079554Record();
};

// Opaque 0x4C bulk-zero member (rowed ctor 0x00042526, no destructor).
class Rva0042526Member
{
public:
	Rva0042526Member() throw();
private:
	unsigned char m_bytes[0x4C];
};

// 248-byte record pushed once into the +0x24 vector (rowed ctor 0x000C6A4D,
// dtor 0x000C6D44); only its leading AsciiString is touched here.
struct BfmePod248
{
	AsciiString m_s00;
	unsigned char m_rest[0xF8 - 4];
	BfmePod248();
	~BfmePod248();
};

// Element types of the vector members whose rowed instantiations this unit
// calls; only their names matter here (the element bodies are elsewhere).
struct Rva000BEDF0Record;
struct BfmePod252;
struct Rva000C828CElement;

// Declare-only views of the rowed STLport vector instantiations: each
// member's out-of-line ~vector (0xC7720/0xC8216/0xC8B83/0x2CC70/0xC1C6A/
// 0xC68C2), the two range erases clear() reaches (0xC690C/0xC4D89) and
// push_back (0xC8DDF). Default construction is the folded empty base ctor.
#define BFME_DECLARE_ONLY_VECTOR_HEAD(T) \
	template <> class vector<T, allocator<T> > : public _Vector_base<int, allocator<int> > \
	{ \
	public: \
		vector(const allocator<int> &a = allocator<int>()) : _Vector_base<int, allocator<int> >(a) {} \
		~vector();

namespace _STL
{
BFME_DECLARE_ONLY_VECTOR_HEAD(Rva000C828CElement)
};
BFME_DECLARE_ONLY_VECTOR_HEAD(BfmePod252)
};
BFME_DECLARE_ONLY_VECTOR_HEAD(BfmePod248)
	void push_back(const BfmePod248 &value);
};
BFME_DECLARE_ONLY_VECTOR_HEAD(AsciiString)
};
BFME_DECLARE_ONLY_VECTOR_HEAD(Rva00079554Record)
	Rva00079554Record *erase(Rva00079554Record *first, Rva00079554Record *last);
	Rva00079554Record *begin() { return (Rva00079554Record *)_M_start; }
	Rva00079554Record *end() { return (Rva00079554Record *)_M_finish; }
	void clear() { erase(begin(), end()); }
};
BFME_DECLARE_ONLY_VECTOR_HEAD(Rva000BEDF0Record)
	Rva000BEDF0Record *erase(Rva000BEDF0Record *first, Rva000BEDF0Record *last);
	Rva000BEDF0Record *begin() { return (Rva000BEDF0Record *)_M_start; }
	Rva000BEDF0Record *end() { return (Rva000BEDF0Record *)_M_finish; }
	void clear() { erase(begin(), end()); }
};
}

#undef BFME_DECLARE_ONLY_VECTOR_HEAD

struct AssetList
{
	unsigned char m_pad[0x14];
	AssetList();
	~AssetList();
};

// AssetList's dtor is declared only, so the containing dtor emits the
// +0x160 array teardown through its provider; no donor identity is claimed.

// Full layout from retail byte decode (capstone) + rowed callee identities.
// Declaration order is increasing offset so the empty dtor tears down in
// reverse (retail states 0x11..0): +0x160 array, +0x11C vec, 4 strings
// +0x118..+0x10C, +0x8C record, +0x7C/+0x70 vecs, 4 strings +0x48..+0x3C,
// +0x30/+0x24/+0x18 vecs, +0x14 string, +0x08 vec. Scalar runs are padding;
// only member offsets matter for the dtor. Each vector member resolves to
// its rowed dtor (0xC0495/0xC68C2/0xC1C6A/0x2CC70/0xC8B83/0xC8216/0xC7720).
class W3DModelDrawModuleData : public Snapshot
{
public:
	W3DModelDrawModuleData();
	virtual ~W3DModelDrawModuleData();

private:
	unsigned char m_pad04[4]; // +0x04..+0x07 (Snapshot is vptr-only)
	_STL::vector<Rva000C828CElement> m_08; // +0x08
	AsciiString m_wadingParticleSys; // +0x14
	_STL::vector<BfmePod252> m_18; // +0x18 vector via rowed 0xC8216 shape
	_STL::vector<BfmePod248> m_24; // +0x24 vector<BfmePod248> via rowed 0xC8B83 shape
	_STL::vector<AsciiString> m_extraPublicBone; // +0x30 vector via rowed 0x2CC70 shape
	AsciiString m_trackMarks; // +0x3C
	AsciiString m_attachToBoneInAnotherModule; // +0x40
	AsciiString m_trackMarksLeftBone; // +0x44
	AsciiString m_trackMarksRightBone; // +0x48
	int m_4C; // +0x4C default state (-1)
	unsigned int m_projectileBoneFeedbackEnabledSlots; // +0x50
	float m_initialRecoilSpeed; // +0x54
	float m_maxRecoilDistance; // +0x58
	float m_recoilDamping; // +0x5C
	float m_recoilSettleSpeed; // +0x60
	int m_minLODRequired; // +0x64
	bool m_okToChangeModelColor; // +0x68
	bool m_noRotate; // +0x69
	bool m_useFiringArcRotation; // +0x6A
	bool m_animationsRequirePower; // +0x6B
	bool m_6C; // +0x6C
	unsigned char m_pad6D[3];
	_STL::vector<Rva00079554Record> m_70; // +0x70 vector via rowed 0xC1C6A shape
	_STL::vector<Rva000BEDF0Record> m_7C; // +0x7C vector via rowed 0xC68C2 shape
	bool m_randomTextureFixedRandomIndex; // +0x88
	unsigned char m_pad89[3];
	Rva00079554Record m_8C; // +0x8C record 0x2C
	bool m_useProducerTexture; // +0xB8
	unsigned char m_padB9[3];
	Rva0042526Member m_BC; // +0xBC opaque 0x4C member
	bool m_particlesAttachedToAnimatedBones; // +0x108
	unsigned char m_pad109[3];
	AsciiString m_wallBoundsMesh; // +0x10C
	AsciiString m_raisedWallMesh; // +0x110
	AsciiString m_rampMesh1; // +0x114
	AsciiString m_rampMesh2; // +0x118
	Rva000C0495 m_embedPortal; // +0x11C vector via rowed 0xC0495
	bool m_glowEnabled; // +0x128
	bool m_glowEmissive; // +0x129
	bool m_particleBonesCheckDrawable; // +0x12A
	bool m_shadowForceDisable; // +0x12B
	float m_highDetailLODThreshold; // +0x12C
	float m_lowDetailLODThreshold; // +0x130
	bool m_switchModelLODMode; // +0x134
	bool m_staticModelLODMode; // +0x135
	bool m_showShadowWhileContained; // +0x136
	bool m_useStandardModelNames; // +0x137
	bool m_useDefaultAnimation; // +0x138
	bool m_alphaRefAnimated; // +0x139
	unsigned char m_pad13A[2];
	int m_alphaRefRange; // +0x13C
	int m_140; // +0x140
	float m_alphaCameraFadeOuterRadius; // +0x144
	float m_alphaCameraFadeInnerRadius; // +0x148
	float m_alphaCameraAtInnerRadius; // +0x14C
	unsigned int m_birthFadeTime; // +0x150
	bool m_birthFadeAdditive; // +0x154
	unsigned char m_pad155[3];
	int m_staticSortLevelWhileFading; // +0x158
	bool m_zWriteDisableOverride; // +0x15C
	bool m_multiPlayerOnly; // +0x15D
	bool m_affectedByStealth; // +0x15E
	bool m_highDetailOnly; // +0x15F
	AssetList m_160[2]; // +0x160 array[2] 0x14 (ehvec 0x629110)
};

// ??1W3DModelDrawModuleData@@UAE@XZ @0xC8BE0
W3DModelDrawModuleData::~W3DModelDrawModuleData()
{
}

// ??0W3DModelDrawModuleData@@QAE@XZ @0x000C8EEF 599B
// Member initialisation in declaration order (EH states 0..0x12 in retail
// order), then the body: recoil constants 2/3/0.4/0.065 (BFME1
// W3DModelDraw.cpp donor semantics), both +0x70/+0x7C vectors cleared, and a
// default "<DefaultEmptyIdleAnimationState>" record pushed into +0x24.
W3DModelDrawModuleData::W3DModelDrawModuleData() :
	m_4C(-1),
	m_minLODRequired(0),
	m_okToChangeModelColor(false),
	m_noRotate(false),
	m_useFiringArcRotation(false),
	m_animationsRequirePower(true),
	m_6C(false),
	m_randomTextureFixedRandomIndex(false),
	m_useProducerTexture(false),
	m_particlesAttachedToAnimatedBones(false),
	m_glowEnabled(false),
	m_glowEmissive(false),
	m_particleBonesCheckDrawable(false),
	m_shadowForceDisable(false),
	m_alphaCameraFadeOuterRadius(0.0f),
	m_alphaCameraFadeInnerRadius(0.0f),
	m_alphaCameraAtInnerRadius(1.0f),
	m_birthFadeTime(0),
	m_birthFadeAdditive(false),
	m_staticSortLevelWhileFading(-1),
	m_multiPlayerOnly(false),
	m_affectedByStealth(true),
	m_highDetailOnly(false)
{
	m_projectileBoneFeedbackEnabledSlots = 0;
	m_initialRecoilSpeed = 2.0f;
	m_maxRecoilDistance = 3.0f;
	m_recoilDamping = 0.4f;
	m_recoilSettleSpeed = 0.065f;

	m_70.clear();
	m_7C.clear();

	m_highDetailLODThreshold = 0.0f;
	m_lowDetailLODThreshold = 0.0f;
	m_switchModelLODMode = false;
	m_staticModelLODMode = false;
	m_showShadowWhileContained = false;
	m_useStandardModelNames = false;
	m_useDefaultAnimation = false;

	BfmePod248 temp;
	temp.m_s00 = "<DefaultEmptyIdleAnimationState>";
	m_24.push_back(temp);

	m_alphaRefAnimated = false;
	m_alphaRefRange = m_140 = 0x60;
	m_zWriteDisableOverride = false;
}
