// cl: /FIzh_ascii.h /Ireference/shims/bfme2_ascii_zh /Ireference/shims/bfme2_ascii /Ireference/shims/bfme2_ascii_common /O1 /DNDEBUG /MD /EHsc /Ireference/open-bfme-1/reference/shims/ini /Ireference/open-bfme-1/reference/shims/gamelod /Ireference/open-bfme-1/reference/shims/ini_noinline /Ireference/open-bfme-1/reference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib
// stlport
/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
//																																						//
//  (c) 2001-2003 Electronic Arts Inc.																				//
//																																						//
////////////////////////////////////////////////////////////////////////////////

// FILE: GameLOD.cpp ///////////////////////////////////////////////////////////
//
// Used to set detail levels of various game systems.
//
// Author: Mark Wilczynski, Sept 2002
//
//
///////////////////////////////////////////////////////////////////////////////

#include "PreRTS.h"	// This must go first in EVERY cpp file in the GameEngine

#include "Common/GameLOD.h"
#include "Common/INI.h"
#include "Common/INIException.h"
#include "GameClient/TerrainVisual.h"
#include "GameClient/GameClient.h"
#include "Common/UserPreferences.h"

// Retail dynamic LOD name comparison uses the MSVCR71 _memicmp import.
extern "C" __declspec(dllimport) int __cdecl _memicmp(
	const void *left, const void *right, unsigned int count);

extern "C" unsigned int __cdecl strlen(const char *text);
#pragma intrinsic(strlen)

#define DEFINE_PARTICLE_SYSTEM_NAMES
#include "GameClient/ParticleSys.h"

#ifdef _INTERNAL
// for occasional debugging...
//#pragma optimize("", off)
//#pragma MESSAGE("************************************** WARNING, optimization disabled for debugging purposes")
#endif

#define PROFILE_ERROR_LIMIT	0.94f	//fraction of profiled result needed to get a match.  Allows some room for error/fluctuation.

//Hack to get access to a static method on the W3DDevice side. -MW
extern Bool testMinimumRequirements(ChipsetType *videoChipType, CpuType *cpuType, Int *cpuFreq, Int *numRAM, Real *intBenchIndex, Real *floatBenchIndex, Real *memBenchIndex);

GameLODManager *TheGameLODManager=NULL;

static const FieldParse TheStaticGameLODFieldParseTable[] = 
{
	{ "MinimumFPS",						INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_minFPS)},
	{ "MinimumProcessorFps",			INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_minProcessorFPS)},
	{ "SampleCount2D",					INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_sampleCount2D ) },
	{ "SampleCount3D",					INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_sampleCount3D ) },
	{ "StreamCount",					INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_streamCount ) },
	{ "MaxParticleCount",				INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_maxParticleCount ) },
	{ "UseShadowVolumes",				INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useShadowVolumes ) },
	{ "UseShadowDecals",				INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useShadowDecals ) },
	{ "UseCloudMap",					INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useCloudMap ) },
	{ "UseLightMap",					INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useLightMap ) },
	{ "ShowSoftWaterEdge",				INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_showSoftWaterEdge ) },
	{ "MaxTankTrackEdges",				INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_maxTankTrackEdges) },
	{ "MaxTankTrackOpaqueEdges",		INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_maxTankTrackOpaqueEdges) },
	{ "MaxTankTrackFadeDelay",			INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_maxTankTrackFadeDelay) },
	{ "UseBuildupScaffolds",			INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useBuildupScaffolds ) },
	{ "UseTreeSway",					INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useTreeSway ) },
	{ "UseEmissiveNightMaterials",		INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useEmissiveNightMaterials ) },
	{ "UseHeatEffects",					INI::parseBool,					NULL,	offsetof( StaticGameLODInfo, m_useHeatEffects ) },
	{ "TextureReductionFactor",		INI::parseInt,					NULL,	offsetof( StaticGameLODInfo, m_textureReduction ) },
};

static const char *StaticGameLODNames[]=
{
	"Low",
	"Medium",
	"High",
	"Custom"
};

static const FieldParse TheDynamicGameLODFieldParseTable[] = 
{
	{ "MinimumFPS",						INI::parseInt,					NULL,	offsetof( DynamicGameLODInfo, m_minFPS)},
	{ "ParticleSkipMask",				INI::parseInt,					NULL,	offsetof( DynamicGameLODInfo, m_dynamicParticleSkipMask)},
	{ "DebrisSkipMask",					INI::parseInt,					NULL,	offsetof( DynamicGameLODInfo, m_dynamicDebrisSkipMask)},
	{ "SlowDeathScale",					INI::parseReal,					NULL,	offsetof( DynamicGameLODInfo, m_slowDeathScale)},
	{ "MinParticlePriority",			INI::parseIndexList, ParticlePriorityNames,	offsetof( DynamicGameLODInfo, m_minDynamicParticlePriority)},
	{ "MinParticleSkipPriority",		INI::parseIndexList, ParticlePriorityNames,	offsetof( DynamicGameLODInfo, m_minDynamicParticleSkipPriority)},
};

// BFME 2 keeps one five-entry level-name table (VeryLow..VeryHigh) at retail
// 0x009B969C; it is defined with getStaticGameLODIndex in
// GameLODManagerGetStaticGameLODIndex.cpp, and the dynamic-level parser and
// name getter read the same table.
extern const char *bfmeStaticLODNames[5];

//Keep this in sync with enum in GameLOD.h
// ?CPUNames@@3PAPBDA, retail 0x009B96B8 (XX P3 P4 K7 then NULL). External
// rather than Zero Hour's static: GameLODManager::init 0x002027EA (split out to
// GameLODManagerInit.cpp; in retail it sits between parseBenchProfile 0x002026D4
// and parseLODPreset 0x00202E23, as in Zero Hour's one GameLOD.cpp) reads it
// for the BenchProfile line. GameLODManagerInit.cpp owns the definition (data
// row 0x009B96B8); a second one here would not link.
extern const char *CPUNames[];

//Keep this in sync with enum in GameLOD.h
static char *VideoNames[] = 
{
	"XX","V2","V3","V4","V5","TNT","TNT2","GF2","R100","PS11","GF3","GF4","PS14","R200","PS20","R300", NULL
};

// parseReallyLowMHz lives in GameLODMHzParsers.cpp with the verified BFME 2 offset.

// parseAudioLowMHz lives in GameLODMHzParsers.cpp with the verified BFME 2 offset.

// ABI shim for target helper 0x0020200D; this type name is inferred.
// Retail bounds/increments count at +0x17C0 and returns a 20-byte profile.
struct RetailBenchProfileAllocator
{
	BenchProfile *newBenchProfile();
};

void INI::parseBenchProfile( INI* ini)
{
	if( TheGameLODManager )
	{
		BenchProfile *preset = reinterpret_cast<RetailBenchProfileAllocator *>(TheGameLODManager)->newBenchProfile();

			if (preset)
			{
				INI::parseIndexList(ini,NULL,&preset->m_cpuType,CPUNames);
				INI::parseInt(ini,NULL,&preset->m_mhz,NULL);
				INI::parseReal(ini,NULL,&preset->m_intBenchIndex,NULL);
				INI::parseReal(ini,NULL,&preset->m_floatBenchIndex,NULL);
				INI::parseReal(ini,NULL,&preset->m_memBenchIndex,NULL);
			}
	}
}

/**Parse a description of all the LOD settings for a given detail level*/
// ?parseLODPreset@INI@@SAXPAV1@@Z
// Retail 0x00202E23 226B. INI block-parse node for token LODPreset.
// Calls rowed getNextToken set copy-ctor rva00202B6C newLODPreset parse helpers.
class Rva00202B6C
{
public:
	Int rva00202B6C(AsciiString name);
};

void INI::parseLODPreset(INI *ini)
{
	AsciiString name;
	name.set(ini->getNextToken());

	if (TheGameLODManager)
	{
		Int index = reinterpret_cast<Rva00202B6C *>(TheGameLODManager)->rva00202B6C(name);
		if (index != -1)
		{
			void *preset = TheGameLODManager->newLODPreset((StaticGameLODLevel)index);
			if (preset)
			{
				INI::parseIndexList(ini, NULL, preset, CPUNames);
				INI::parseInt(ini, NULL, (char *)preset + 4, NULL);
				INI::parseIndexList(ini, NULL, (char *)preset + 0x0c, CPUNames + 6);
				INI::parseInt(ini, NULL, (char *)preset + 0x14, NULL);
				INI::parseInt(ini, NULL, (char *)preset + 0x10, NULL);
				INI::parseInt(ini, NULL, (char *)preset + 0x18, NULL);
				INI::parseInt(ini, NULL, (char *)preset + 0x1c, NULL);
			}
		}
	}
}

// The retail constructor is defined in Rva00201DC4LODDefaults.cpp.

GameLODManager::~GameLODManager()
{

}

// The native allocation and initialization bodies remain in
// GameLODManager_newLODPreset.cpp and GameLODManagerInit.cpp.

/**Convert LOD name to an index*/
// byte-exact reconstruction: Code/GameEngine/Source/Common/GameLODManagerGetStaticGameLODIndex.cpp
// GameLODManager::getStaticGameLODIndex: defined in GameLODManagerGetStaticGameLODIndex.cpp (its row's unit).

/**Parse a description of all the LOD settings for a given detail level*/
// ?parseStaticGameLODDefinition@INI@@SAXPAV1@@Z
// The "StaticGameLOD" block. BFME's field set is not Zero Hour's, so this table
// carries the offsets retail's own table at 0x00BE3478 holds rather than
// offsetof against a reconstructed struct. The matching retail parser passes
// TheGameLODManager + 0x1c8 + (index << 4) to initFromINI; this proves the
// address formula, not the complete layout of the parsed region.
static const FieldParse TheBFMEStaticGameLODFieldParseTable[] =
{
	{ "MaxParticleCount",			INI::parseInt,			NULL,	0x00 },
	{ "UseShadowVolumes",			INI::parseBool,			NULL,	0x04 },
	{ "UseShadowDecals",			INI::parseBool,			NULL,	0x05 },
	{ "UseAnisotropic",				INI::parseBool,			NULL,	0x06 },
	{ "UsePixelShaders",			INI::parseBool,			NULL,	0x07 },
	{ "UseLightMap",				INI::parseBool,			NULL,	0x08 },
	{ "ShowSoftWaterEdge",			INI::parseBool,			NULL,	0x09 },
	{ "MaxTankTrackEdges",			INI::parseInt,			NULL,	0x0c },
	{ "MaxTankTrackOpaqueEdges",	INI::parseInt,			NULL,	0x10 },
	{ "MaxTankTrackFadeDelay",		INI::parseInt,			NULL,	0x14 },
	{ "UseBuildupScaffolds",		INI::parseBool,			NULL,	0x18 },
	{ "UseTreeSway",				INI::parseBool,			NULL,	0x19 },
	{ "GrassDrawSkip",				INI::parseInt,			NULL,	0x1a },
	{ "ShowProps",					INI::parseBool,			NULL,	0x22 },
	{ "TextureReductionFactor",		INI::parseInt,			NULL,	0x1c },
	{ "UseHighQualityVideo",		INI::parseBool,			NULL,	0x23 },
	{ "AnimationDetail",			INI::parseStaticGameLODLevel,	NULL,	0x24 },
	{ "MinParticlePriority",		INI::parseIndexList,	NULL,	0x28 },
	{ "MinParticleSkipPriority",	INI::parseIndexList,	NULL,	0x2c },
	{ 0, 0, 0, 0 }
};

/*static*/ void INI::parseStaticGameLODDefinition( INI* ini )
{
	AsciiString name;
	((StringBase<char> *)&name)->set(ini->getNextToken());

	if( TheGameLODManager )
	{
		Int index = TheGameLODManager->getStaticGameLODIndex( name );
		if( index != STATIC_GAME_LOD_UNKNOWN )
		{
			// Retail computes manager + 0x1c8 + (index << 4) here.
			void *lodInfo = (char *)TheGameLODManager + index * 16 + 0x1c8;
			ini->initFromINI( lodInfo, TheBFMEStaticGameLODFieldParseTable );
		}
	}
}

/**Parse an LOD level*/
// ?parseStaticGameLODLevel@INI@@SAXPAV1@PAX1PBX@Z present-unmatched
void INI::parseStaticGameLODLevel( INI* ini, void * , void *store, const void*)
{
	const char *tok=ini->getNextToken();
	for (Int i=0; i<STATIC_GAME_LOD_COUNT; i++)
		if( _strcmpi(tok, StaticGameLODNames[i]) == 0 )
		{	*(StaticGameLODLevel*)store = (StaticGameLODLevel)i;
			return;
		}

	// The dynamic sibling at 0x0007C390 throws INIException(3, ...) here, and it
	// is tempting to assume this one does too -- but with that change the body
	// still does not appear anywhere in .text, so BFME's static parser differs by
	// more than the throw. Left as Zero Hour has it until a caller or a located
	// placement says otherwise.
	DEBUG_CRASH(("invalid GameLODLevel token %s -- expected LOW/MEDIUM/HIGH\n",tok));
	throw INI_INVALID_DATA;
}

/**Function which calculates the recommended LOD level for current hardware
configuration.*/
// The matched BFME 2 definition is in GameLODManagerFindStaticLODLevel.cpp.

// Preserve the shared pointer definition after retiring the obsolete setter.
class Shell;

extern Shell *TheShell;
// TheShell: matched references place it at VA 0xe01e48 (zero-filled .bss).
Shell * TheShell;

/**Parse an LOD level*/
void INI::parseDynamicGameLODLevel( INI* ini, void * , void *store, const void*)
{
	const char *tok=ini->getNextToken();
	for (Int i=0; i<DYNAMIC_GAME_LOD_COUNT; i++)
		if( _strcmpi(tok, bfmeStaticLODNames[i]) == 0 )
		{	*(DynamicGameLODLevel*)store = (DynamicGameLODLevel)i;
			return;
		}

	throw INIException( 3, "invalid GameLODLevel token %s -- expected LOW/MEDIUM/HIGH", tok );
}

const char *GameLODManager::getDynamicGameLODLevelName(DynamicGameLODLevel level)
{
	return bfmeStaticLODNames[level];
}

//-------------------------------------------------------------------------------------------------
// ?parseAudioLODDefinition@INI@@SAXPAV1@@Z
// The "AudioLOD" block, which BFME adds and Zero Hour has no counterpart for.
// Three fields, eight bytes per level, and the array sits at +0x170 in
// GameLODManager: retail addresses the element as
// TheGameLODManager + index*8 + 0x170.
//
// Unlike the static and dynamic variants, an unknown level name is fatal here
// rather than silently ignored.
static const FieldParse TheBFMEAudioLODFieldParseTable[] =
{
	{ "MaximumAmbientStreams",	INI::parseInt,	NULL,	0x00 },
	{ "AllowDolby",				INI::parseBool,	NULL,	0x04 },
	{ "AllowReverb",			INI::parseBool,	NULL,	0x05 },
	{ 0, 0, 0, 0 }
};

// INI::parseAudioLODDefinition: defined in INIParseAudioLODDefinition.cpp (its row's unit).
