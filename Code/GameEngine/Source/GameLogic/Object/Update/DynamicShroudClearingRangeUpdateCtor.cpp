// cl: /DNDEBUG /MD /GX /Ireference/shims/dockupdate /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib /Ireference/shims/bfme_namekey /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/shims -ICode/Libraries/Source/Compression/LZHCompress/CompLibHeader /Ireference/shims/bfme2htree /Ireference/shims/bfme2renderobj /Ireference/shims/bfmecamera /Ireference/shims/bfmelight /Ireference/shims/bfmeparticlehandle /Ireference/shims/bfmeparticleload /Ireference/shims/bfmeparticlequat /Ireference/shims/bfmeparticlesave /Ireference/shims/bfmeparticleline /Ireference/shims/bfme2ray /Ireference/shims/bfme2scene /Ireference/shims/bfmefrustum /ICode/Libraries/Include /Ireference/shims/moduledata
// stlport
#include "DynamicShroudClearingRangeUpdateView.h"
//
// ??0DynamicShroudClearingRangeUpdate@@QAE@PAVThing@@PBVModuleData@@@Z retail 0x0048B067
// 253 bytes. Behavior-side ctor completing the DynamicShroudClearingRangeUpdate
// file-unit (ModuleData proc/ctor/factory, poolkey, instance factory and
// killGridDecals are all rowed; this ctor is the pinned remainder).
//
// Transcribed from the BFME1 donor
// (reference/open-bfme-1/Code/GameEngine/Source/GameLogic/Object/Update/
// DynamicShroudClearingRangeUpdateCtorThunk.cpp), which names both calls in
// the tail: Object::getControllingPlayer (rowed at 0x28AFA9) and
// Object::getShroudClearingRange (pinned at 0x28DE87). Retail keeps the
// donor order exactly: change-interval/vision zeros, shrink+grow count,
// max(1) total, shrink/grow/sustain deadlines, done-forever frame off
// TheGameLogic, decals flag, 200.0f native range, 0.0f current range, state
// zero, then the object-gated range load and the 30-wide RadiusDecal clear
// loop over this+0x50 (killGridDecals proves the array base and stride).
// The RadiusDecal element ctor/dtor ride the rowed/pinned 0x330DA4/0x330DD6
// pair through the ehvec helper; clear resolves via its row.

#include "../../../Common/GameLogicObjectLookupView.h"

extern GameLogic *TheGameLogic;

template <class T>
static const T &bfmeMax(const T &left, const T &right)
{
	return right < left ? left : right;
}

// ??0DynamicShroudClearingRangeUpdate@@QAE@PAVThing@@PBVModuleData@@@Z @0x0048B067
DynamicShroudClearingRangeUpdate::DynamicShroudClearingRangeUpdate(
	Thing *thing, const ModuleData *moduleData)
	: UpdateModule(thing, moduleData)
{
	const DynamicShroudClearingRangeUpdateModuleData *md =
		(const DynamicShroudClearingRangeUpdateModuleData *)moduleData;
	m_changeIntervalCountdown = 0;
	m_visionChangePerInterval = 0.0f;
	m_stateCountDown = md->m_shrinkDelay + md->m_shrinkTime;
	m_totalFrames = bfmeMax(1, m_stateCountDown);
	m_shrinkStartDeadline = m_stateCountDown - md->m_shrinkDelay;
	m_growStartDeadline = m_stateCountDown - md->m_growDelay;
	m_sustainDeadline = m_growStartDeadline - md->m_growTime;
	m_doneForeverFrame = TheGameLogic->getFrame() + m_stateCountDown;
	m_decalsCreated = false;
	m_nativeClearingRange = 200.0f;
	m_currentClearingRange = 0.0f;
	m_state = DSCRU_NOT_STARTED_YET;

	Object *object = m_object;
	if (!object)
		return;
	Player *controller = object->getControllingPlayer();
	if (!controller)
		return;
	m_nativeClearingRange = object->getShroudClearingRange();

	RadiusDecal *decal = m_gridDecal;
	int decalsLeft = 30;
	do {
		decal->clear();
		++decal;
	} while (--decalsLeft != 0);
}
