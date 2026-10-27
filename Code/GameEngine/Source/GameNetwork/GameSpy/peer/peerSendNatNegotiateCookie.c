// cl: /Ob2 /DNDEBUG /MD
// platformsdk
/* GameSpy Peer SDK -- peerSB.c */

#include <windows.h>

typedef struct PEERConnection
{
	unsigned char pad_0000[0x0BA0];
	int sbInitialized;
	unsigned char gameList[1];
} PEERConnection;

typedef PEERConnection *PEER;

void SBSendNatNegotiateCookieToServer(
	void *serverList,
	unsigned int ip,
	unsigned short port,
	int cookie);

void piSendNatNegotiateCookie(
	PEER peer,
	unsigned int ip,
	unsigned short port,
	int cookie)
{
	if (!peer->sbInitialized)
		return;

	SBSendNatNegotiateCookieToServer(
		&peer->gameList,
		ip,
		htons(port),
		cookie);
}
