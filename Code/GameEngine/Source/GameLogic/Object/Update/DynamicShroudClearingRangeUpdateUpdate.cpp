// cl: /DNDEBUG /MD /GX /Ireference/shims/dockupdate /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib /Ireference/shims/bfme_namekey /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/shims -ICode/Libraries/Source/Compression/LZHCompress/CompLibHeader /Ireference/shims/bfme2htree /Ireference/shims/bfme2renderobj /Ireference/shims/bfmecamera /Ireference/shims/bfmelight /Ireference/shims/bfmeparticlehandle /Ireference/shims/bfmeparticleload /Ireference/shims/bfmeparticlequat /Ireference/shims/bfmeparticlesave /Ireference/shims/bfmeparticleline /Ireference/shims/bfme2ray /Ireference/shims/bfme2scene /Ireference/shims/bfmefrustum /ICode/Libraries/Include /Ireference/shims/moduledata
// stlport
#include "DynamicShroudClearingRangeUpdateView.h"
//
// DynamicShroudClearingRangeUpdate::update (BFME 2), from the Generals Zero
// Hour DynamicShroudClearingRangeUpdate.cpp.
//
// Target facts. update is slot 0 of the UpdateModuleInterface vftable at
// 0x0084BEB0. The fields follow the ZH order from +0x20 (state, the state
// countdown, total frames, the grow/sustain/shrink deadlines, the done-forever
// frame, the change-interval countdown, the decals-created flag at +0x40 and
// the native and current clearing ranges at +0x48/+0x4C), as the rowed ctor
// 0x0048B067, xfer 0x0048B505 and animateGridDecals 0x0048B256 use them. The
// module data holds ShrinkTime +0xC, GrowTime +0x14, FinalVision +0x18,
// ChangeInterval +0x1C, GrowInterval +0x20 and the grid decal template +0x28.
typedef bool Bool;
typedef int Int;
typedef unsigned int UnsignedInt;
typedef float Real;

template <class T> inline const T &max(const T &lhs, const T &rhs)
{
	return lhs > rhs ? lhs : rhs;
}

#include "../../../Common/GameLogicObjectLookupView.h"

extern GameLogic *TheGameLogic;

// ?update@DynamicShroudClearingRangeUpdate@@UAE?AW4UpdateSleepTime@@XZ @0x0048B33F 454B
UpdateSleepTime DynamicShroudClearingRangeUpdate::update( void )
{
	if (m_state == DSCRU_SLEEPING) {
		return UPDATE_SLEEP_NONE;
	}
	//Housekeeping-----------------------------------------
	Object *me = getObject();
	const DynamicShroudClearingRangeUpdateModuleData *md = getDynamicShroudClearingRangeUpdateModuleData();
	UnsignedInt currentFrame = TheGameLogic->getFrame();

	if ( ! m_decalsCreated )
	{
		createGridDecals(md->getGridDecalTemplate(), 100, *(me->getPosition()));
		m_decalsCreated = true;
	}
	//-----------------------------------------------------


	if( m_stateCountDown <= 0 || currentFrame > m_doneForeverFrame )
		m_state = DSCRU_DONE_FOREVER;
	else if ( m_stateCountDown <= m_shrinkStartDeadline  )
		m_state = DSCRU_SHRINKING;
	else if ( m_stateCountDown <= m_sustainDeadline )
		m_state = DSCRU_SUSTAINING;
	else if ( m_stateCountDown <= m_growStartDeadline )
		m_state = DSCRU_GROWING;


	switch (m_state)
	{

		case DSCRU_NOT_STARTED_YET :
		{
			rva0048B256();

			break;
		}
		case DSCRU_GROWING :
		{
			rva0048B256();

			m_currentClearingRange += m_nativeClearingRange / max(1.0f, (Real)md->m_growTime);
			if (m_currentClearingRange >= m_nativeClearingRange)
				m_state = DSCRU_SUSTAINING;
			break;
		}
		case DSCRU_SUSTAINING :
		{
			m_currentClearingRange = m_nativeClearingRange;
			killGridDecals();
			break;
		}
		case DSCRU_SHRINKING :
		{
			m_currentClearingRange -= (m_nativeClearingRange-md->m_finalVision) / max(1.0f, (Real)md->m_shrinkTime);
			break;
		}
		case DSCRU_DONE_FOREVER :
		{
			killGridDecals();
			m_currentClearingRange = md->m_finalVision;
			break;
		}

	}

	if ( m_stateCountDown > 0 ) m_stateCountDown --;// it is important that this gets called every frame without sleeping
	//beacuse it handles animation and may need to respond to changing vision range from scripts & stuff


	if( m_changeIntervalCountdown > 0 )
		m_changeIntervalCountdown--;
	else
	{// reset per change timer
		m_changeIntervalCountdown = ( m_state == DSCRU_GROWING ? md->m_growInterval : md->m_changeInterval);
		me->setShroudClearingRange( m_currentClearingRange );
		if (m_state == DSCRU_DONE_FOREVER) { // We are done forever, and have done the final update, so sleep.+
			m_state = DSCRU_SLEEPING;
		}
	}

	return UPDATE_SLEEP_NONE;
}
