// platformsdk
// Ported from the BFME1 audio-event reconstruction.  The constructor's body
// is independently located and byte-verified in BFME2 at RVA 0x00051914.
#include <windows.h>
#include <new.h>
typedef long Long;

class AudioEventInfo
{
public:
	void *m_vtable;
	Long m_refCount;
};

class AudioEventInfoRef
{
public:
	AudioEventInfoRef(const AudioEventInfo *info);

	const AudioEventInfo *m_info;
};

// Select-any like every other TU's copy (a strong definition would duplicate theirs at link time);
// the anchor keeps the noinline body emitted.
__declspec(noinline) inline AudioEventInfoRef::AudioEventInfoRef(const AudioEventInfo *info)
	: m_info(info)
{
	if (m_info)
		InterlockedIncrement(&const_cast<AudioEventInfo *>(m_info)->m_refCount);
}

// ?bfmeAnchorAudioEventInfoRef absent-from-retail
void *bfmeAnchorAudioEventInfoRef(void *where, const AudioEventInfo *info)
{
	return new (where) AudioEventInfoRef(info);
}
