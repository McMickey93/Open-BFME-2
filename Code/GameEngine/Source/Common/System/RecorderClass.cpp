// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// ?logCRCMismatch@RecorderClass@@QAEXXZ @0x0037ADB6 152B: recorder file patch via ftell fseek fwrite rows plus globals NET_CRC_INTERVAL and TheGameLogic+0x40 into members +0xe60 +0xe64. Evidence: null FILE at +0x10 early out plus IAT ftell fseek fwrite plus fixed offsets 0x14 0x18 plus restore ftell pos; same FILE+0x10 family as Rva0037B287Write; caller 0x00240225.
#include "unicode_string.h"

#include <stdio.h>
#include <time.h>

class NetworkInterface;
extern NetworkInterface *TheNetwork;

extern int NET_CRC_INTERVAL;

#include "../GameLogicObjectLookupView.h"
extern GameLogic *TheGameLogic; // ?TheGameLogic@@3PAVGameLogic@@A

class RecorderClass
{
public:
	void logCRCMismatch();
	void logGameEnd();
	void stopRecording();
private:
	char m_pad00[0x10];
	FILE *m_file; // +0x10
	UnicodeString m_fileName; // +0x14
	char m_pad18[0xe60 - 0x18];
	int field0e60; // +0xe60
	int field0e64; // +0xe64
};

void RecorderClass::logCRCMismatch()
{
	if (m_file == 0)
		return;
	field0e60 = (int)NET_CRC_INTERVAL;
	field0e64 = TheGameLogic->getFrame();
	long pos = ftell(m_file);
	if (fseek(m_file, 0x14, 0) == 0)
		fwrite(&field0e60, 4, 1, m_file);
	if (fseek(m_file, 0x18, 0) == 0)
		fwrite(&field0e64, 4, 1, m_file);
	fseek(m_file, pos, 0);
}

// RecorderClass::logGameEnd, retail 0x0037AE4E (148 bytes): Zero Hour's
// Recorder.cpp body (WB names it): the end time goes to offset 0x0C and the
// frame count to 0x10 of the replay header, then the stream returns to its
// end.
void RecorderClass::logGameEnd()
{
	if (m_file == 0)
		return;

	long t;
	time(&t);
	unsigned int duration = TheGameLogic->getFrame();
	unsigned int fileSize = ftell(m_file);
	// move to appropriate offset
	if (!fseek(m_file, 0x0c, 0))
	{
		// save off end time
		fwrite(&t, sizeof(long), 1, m_file);
	}
	// move to appropriate offset
	if (!fseek(m_file, 0x10, 0))
	{
		// save off duration
		fwrite(&duration, sizeof(unsigned int), 1, m_file);
	}
	// move back to end of stream
	fseek(m_file, fileSize, 0);
}

// RecorderClass::stopRecording, retail 0x0037B42D (52 bytes): Zero Hour's
// Recorder.cpp body, as the quit menu's restart (0x0051B90B) calls it while
// recording: logs the game end, drops the mismatch frame in a network
// game, closes the replay and forgets its name.
void RecorderClass::stopRecording()
{
	logGameEnd();
	if (TheNetwork)
		field0e64 = -1;
	if (m_file != 0)
	{
		fclose(m_file);
		m_file = 0;
	}
	m_fileName.clear();
}
