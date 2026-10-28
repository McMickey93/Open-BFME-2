// cl: /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /D_CRTIMP= -Ireference/open-bfme-1/inputs/reference/shims/sweep -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad -Ireference/open-bfme-1/game/GameEngine/Source/GameLogic/AI -Ireference/open-bfme-1/inputs/reference/shims/ini -Ireference/open-bfme-1/inputs/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression -Ireference/open-bfme-1/game/GameEngine/Source/Common/INI /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /Ireference/shims/moduledata /Ireference/shims/subsystem_bfme2 /Ireference/shims/bfmelist
// stlport
//
// AI::getAdjustedVisionRangeForObject, retail 0x002FDD0A (138 bytes), ported
// from Zero Hour's GameEngine/Source/GameLogic/AI/AI.cpp (GeneralsMD tree
// vendored under reference/open-bfme-1/inputs/reference). Callers include
// AIGuardMachine::getStdGuardRange and AIGuardOuterState::onEnter.
// BFME 2 deltas (target evidence): the float at Object +0xB8 is added to the
// vision range once the object is known to have an AI (Object +0x258); Zero
// Hour's AI_VISIONFACTOR_OWNERTYPE guard modifiers and the contained-by
// largest-weapon-range override are absent, so only the mood factor
// remains: sleep gives 0, alert and aggressive scale by the TAiData floats at
// +0x4C and +0x50. getMoodMatrixValue is the pinned 0x00264F5E.
// Built on the approved TU's (ai.cpp) prelude; the BFME 2 offsets are read
// through retail-offset views of the Zero Hour classes.
#define Matrix4x4 Matrix4  // BFME renamed it
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
#include "Common/CRCDebug.h"
#include "Common/GameState.h"
#include "Common/PerfTimer.h"
#include "Common/Player.h"
#include "Common/PlayerList.h"
#include "Common/ThingTemplate.h"
#include "Common/Xfer.h"
#include "Common/XferCRC.h"
#include "GameLogic/AI.h"
#include "GameLogic/PartitionManager.h"
#include "GameLogic/Module/AIUpdate.h"
#include "GameLogic/Module/ContainModule.h"
#include "GameLogic/ScriptEngine.h"
#include "GameLogic/SidesList.h"
#include "GameLogic/AIPathfind.h"
#include "GameLogic/Weapon.h"
#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")

#endif
#define Matrix4x4 Matrix4  // BFME renamed it
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
#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")

#endif
#include <stl/_algobase.h>
#include <list>


struct BfmeVisionObjectFields
{
	unsigned char m_unreconstructed_00[0xB8];
	Real m_visionBonus;				///< retail +0xB8
	unsigned char m_unreconstructed_BC[0x258 - 0xBC];
	AIUpdateInterface *m_ai;		///< retail +0x258
};

struct BfmeVisionTAiDataFields
{
	unsigned char m_unreconstructed_00[0x4C];
	Real m_alertRangeModifier;		///< retail +0x4C
	Real m_aggressiveRangeModifier;	///< retail +0x50
};

struct BfmeVisionAIFields
{
	unsigned char m_unreconstructed_00[0x18];
	const BfmeVisionTAiDataFields *m_aiData;	///< retail +0x18
};

//-------------------------------------------------------------------------------------------------
Real AI::getAdjustedVisionRangeForObject(const Object *object, Int factorsToConsider)
{
	Real originalRange = object->getVisionRange();
	const BfmeVisionObjectFields *fields = (const BfmeVisionObjectFields *)object;
	const AIUpdateInterface *ai = fields->m_ai;

	if (!ai)
	{
		return 0.0f;
	}

	originalRange += fields->m_visionBonus;

	UnsignedInt moodMatrixVal = ai->getMoodMatrixValue();

	if ((factorsToConsider & AI_VISIONFACTOR_MOOD) && ((moodMatrixVal & MM_Controller_Player) == 0) )
	{
		switch(moodMatrixVal & MM_Mood_Bitmask)
		{
			case MM_Mood_Sleep:
				return 0.0f;

			case MM_Mood_Passive:
			case MM_Mood_Normal:
				break;

			case MM_Mood_Alert:
				originalRange *= ((const BfmeVisionAIFields *)TheAI)->m_aiData->m_alertRangeModifier;
				break;

			case MM_Mood_Aggressive:
				originalRange *= ((const BfmeVisionAIFields *)TheAI)->m_aiData->m_aggressiveRangeModifier;
				break;
		}
	}

	return originalRange;
}
