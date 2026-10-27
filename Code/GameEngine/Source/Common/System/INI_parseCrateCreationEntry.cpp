// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii_common /Ireference/shims/bfme2_ascii /Ireference/open-bfme-1/inputs/reference/shims/ini /Ireference/open-bfme-1/inputs/reference/shims/sweep /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/shims/bfmelist /Ireference/shims/bfmealloc
// stlport
#define Matrix4x4 Matrix4  // BFME renamed it
#define __PLACEMENT_VEC_NEW_INLINE
#include <vector>	// before PreRTS.h so node_alloc freelist is used (not NEWALLOC)
#define __KINDOF_H_
#include "Common/BitFlags.h"
enum KindOfType
{
	KINDOF_INVALID = -1,
	KINDOF_FIRST = 0,
	KINDOF_COUNT = 224						///< width pin only; see below
};
typedef BitFlags<KINDOF_COUNT>	KindOfMaskType;
#define MAKE_KINDOF_MASK(k) KindOfMaskType(KindOfMaskType::kInit, (k))
#define CLEAR_KINDOFMASK(m) ((m).clear())
// PreRTS.h reaches Common/Overridable.h (through Science.h), so the BFME view
// below has to come first; these are PreRTS.h's own leading includes, in its order.
#include <windows.h>
#include "Lib/BaseType.h"
#include "Common/STLTypedefs.h"
#include "Common/Errors.h"
#include "Common/Debug.h"
#include "Common/AsciiString.h"
#include "Common/SubsystemInterface.h"
#include "Common/GameCommon.h"
#include "Common/GameMemory.h"
// BFME's Overridable is 0x10 bytes where Zero Hour's is 0x0C. CrateTemplate's
// ctor (0x0035CC36) inlines the base ctor as +0x04 = NULL, +0x08 = false and
// +0x0C = -1, its assignment (0x0035CE52) and every member access put the
// name at +0x10, and the destructor 0x001E3624 is public (??1Overridable@@UAE@XZ).
// Nothing in this TU reads +0x0C, so it carries no name. getFinalOverride and
// deleteOverrides are out of line in retail (0x001E35DF, 0x001E35ED), and so is
// the 5-byte base assignment (0x001FD28E).
#define _OVERRIDABLE_H_
class Overridable : public MemoryPoolObject
{
	private:
		Overridable *m_nextOverride;
		Bool m_isOverride;
		Int m_field0C;

	public:
		Overridable() : m_nextOverride(NULL), m_isOverride(false), m_field0C(-1) {}
		virtual ~Overridable();
		Overridable &operator=(const Overridable &that);

		const Overridable *getNextOverride( void ) const { return m_nextOverride; }
		const Overridable *getFinalOverride( void ) const;
		void setNextOverride(Overridable *nextOverridable) { m_nextOverride = nextOverridable; }
		Overridable *friend_getNextOverride( void ) { return m_nextOverride; }
		Overridable *friend_getFinalOverride( void );
		const Overridable *friend_getFinalOverride( void ) const;
		void markAsOverride( void ) { m_isOverride = true; }
		Overridable *deleteOverrides( void );
};
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine
// BFME de-pooled this glue: retail's per-class `operator delete(void*, MagicEnum)`
// is one 12-byte body (0x007EFFF0) that calls the CRT free IMPORT THUNK -- a
// `call rel32` into `jmp [__imp__free]` -- where ::operator delete (0x00881EB0)
// is a different function. <stdlib.h> declares free __declspec(dllimport) under
// /MD, which compiles to the `ff 15` indirect form instead, so the C-linkage
// redeclaration below is what names `_free` for the linker's thunk; it is
// namespaced so every other free() call in this TU keeps the indirect form
// retail also uses. Same TU-scoped override Team.cpp already carries.
namespace BfmePoolGlue { extern "C" void __cdecl free(void *); }
#undef MEMORY_POOL_GLUE_WITHOUT_GCMP
#define MEMORY_POOL_GLUE_WITHOUT_GCMP(ARGCLASS) \
protected: \
	virtual ~ARGCLASS(); \
public: \
	enum ARGCLASS##MagicEnum { ARGCLASS##_GLUE_NOT_IMPLEMENTED = 0 }; \
public: \
	inline void *operator new(size_t s, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) \
	{ return MP_GLUE_ALLOCATE(ARGCLASS); } \
public: \
	inline void operator delete(void *p, ARGCLASS##MagicEnum e DECLARE_LITERALSTRING_ARG2) \
	{ BfmePoolGlue::free(p); } \
protected: \
	inline void *operator new(size_t s) { return ::operator new(s); } \
	inline void operator delete(void *p) { ::operator delete(p); } \
private: \
	virtual MemoryPool *getObjectMemoryPool() { return ARGCLASS::getClassMemoryPool(); } \
public:
#define DEFINE_VETERANCY_NAMES				// for TheVeterancyNames[]
#include "GameLogic/CrateSystem.h"
// ?parseCrateCreationEntry@CrateTemplate@@SAXPAVINI@@PAX1PBX@Z, retail
// 0x0035CD23, 188 bytes. Serves the CrateObject entry of the table at
// 0x8162A0. Zero Hour CrateSystem.cpp proves the name and shape: read two
// tokens, build an AsciiString crate name, sscanf a float crate value
// (INIException(3, ...) plus _CxxThrowException on failure, scanReal
// precedent), fill a crateCreationEntry and push it onto the
// list<crateCreationEntry> m_possibleCrates at instance+0x3c (ZH
// CrateSystem.h: crateCreationEntryList). The store push lowers to the
// list push_back at 0x0035CBFE (sole caller). The prelude above is
// CrateSystem.cpp's own (its BFME Overridable and KindOfMaskType views), so
// the real CrateTemplate, crateCreationEntry and list types serve this body
// and the file compiles as part of that TU.

#include <stdio.h>
#include "Common/INIException.h"

// ?parseCrateCreationEntry@CrateTemplate@@SAXPAVINI@@PAX1PBX@Z
void CrateTemplate::parseCrateCreationEntry(INI *ini, void *instance, void *, const void *)
{
	CrateTemplate *self = (CrateTemplate *)instance;

	const char *token = ini->getNextToken();
	AsciiString crateName = token;

	token = ini->getNextToken();
	Real crateValue;
	if (sscanf(token, "%f", &crateValue) != 1) {
		throw INIException(3, "Floating point value expected instead of '%s'", token);
	}

	crateCreationEntry newEntry;
	newEntry.crateName = crateName;
	newEntry.crateChance = crateValue;

	self->m_possibleCrates.push_back(newEntry);
}
