// cl: /O1 /G7 /arch:SSE /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// BFME1 9cbfb551 System/RecorderPlaybackFile.cpp semantic lead.
// Native37D1E6..37D3C9,483B; Unicode by-value filename is witnessed at
// GameEngine::init and the existing playbackFile pin. BFME1 supplies purpose
// and sequence; retail supplies fields24/C/E70/E74, seed74, MessageStream48,
// TheGameInfo assignment and saved GlobalData1100/1104 values. Unknown
// callee identities retain their existing address-derived ABI views.
// Header5C has the six inline null string slots and existing out-of-line dtor.
// CRC state constructor37D076 consumes12B; only local-player field08 is used.
// Saved values are TU statics, independently inferred from the native stores.
#include <stdio.h>
#include "ascii_string.h"
#include "unicode_string.h"
#include "../GameLogicObjectLookupView.h"
class Rva0037B5DF {public:
 ~Rva0037B5DF();
 int start,end,frame,crcInterval,mode;bool quitEarly,disconnected[8];char pad1D[3];
 AsciiString options;int localIndex;UnicodeString filename;bool forPlayback;char pad2D[3];
 UnicodeString name;char time[16];UnicodeString version,versionTime;unsigned int crc4C;
 bool flag50;char pad51[3];int word54;UnicodeString str58;
};
class Rva0037BBED {public:bool rva0037CBB6(Rva0037B5DF &);};
class Rva0037B7C7 {public:void rva0037B7C7();};
class Rva0037D076 {public:
 Rva0037D076();unsigned char m_b0,m_b1;char m_pad2[2];void *m_list;int m_i8;
};
class GameInfo {public:
 AsciiString getMap()const;
 char unknown00[0xc];int m_crcInterval;char unknown10[0x50-0x10];
 unsigned int m_seed;char unknown54[0xe3c-0x54];
};
class GlobalData {public:
 char p0[0xac0];AsciiString pendingFile;
 char pAC4[0x1100-0xac4];bool field1100;char p1101[3];int field1104;
};
class GameMessage {public:
 enum Type {MSG_NEW_GAME=0x1e};void appendIntegerArgument(int v);
};
class MessageStream {public:
#define V(n) virtual void v##n();
 V(00) V(01) V(02) V(03) V(04) V(05) V(06) V(07) V(08)
 V(09) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17)
#undef V
 virtual GameMessage *v18(int type);
};
extern GlobalData *TheWritableGlobalData;
extern GameLogic *TheGameLogic;
extern GameInfo *TheGameInfo;
extern MessageStream *TheMessageStream;
int REPLAY_CRC_INTERVAL;
static int recorderSavedGlobalValue;
static bool recorderSavedGlobalFlag;
void InitRandom(unsigned int);
class RecorderClass {public:
 bool playbackFile(UnicodeString filename);
 void rva0037AEE2();
 char pad004[0xc];Rva0037D076 *m_crcInfo;FILE *m_file;
 UnicodeString m_fileName;int field0018;int m_mode;UnicodeString m_currentReplayFilename;
 GameInfo m_gameInfo;int field0e60,field0e64;char padE68[8];
 bool m_doingAnalysis;char padE71[3];int m_gameMode;
};
bool RecorderClass::playbackFile(UnicodeString filename)
{
 if(!m_doingAnalysis)TheGameLogic->clearGameData(false,false);
 m_mode=1;
 Rva0037B5DF header;
 header.forPlayback=true;header.filename=filename;
 bool success=reinterpret_cast<Rva0037BBED *>(this)->rva0037CBB6(header);
 if(!success)return false;
 recorderSavedGlobalFlag=TheWritableGlobalData->field1100;
 recorderSavedGlobalValue=TheWritableGlobalData->field1104;
 TheWritableGlobalData->field1100=header.flag50;
 TheWritableGlobalData->field1104=header.word54;
 TheWritableGlobalData->pendingFile=m_gameInfo.getMap();
 m_crcInfo=new Rva0037D076;
 m_crcInfo->m_i8=header.localIndex;
 REPLAY_CRC_INTERVAL=m_gameInfo.m_crcInterval;
 int difficulty=0;fread(&difficulty,4,1,m_file);
 fread(&m_gameMode,4,1,m_file);
 int rankPoints=0;fread(&rankPoints,4,1,m_file);
 int maxFPS=0;fread(&maxFPS,4,1,m_file);
 reinterpret_cast<Rva0037B7C7 *>(this)->rva0037B7C7();
 if(!m_doingAnalysis){
  TheGameInfo=&m_gameInfo;
  GameMessage *message=TheMessageStream->v18(GameMessage::MSG_NEW_GAME);
  message->appendIntegerArgument(3);
  message->appendIntegerArgument(difficulty);
  message->appendIntegerArgument(rankPoints);
  if(maxFPS!=0)message->appendIntegerArgument(maxFPS);
  InitRandom(m_gameInfo.m_seed);
 }
 m_currentReplayFilename=filename;
 return true;
}

void RecorderClass::rva0037AEE2()
{
 TheWritableGlobalData->field1100=recorderSavedGlobalFlag;
 TheWritableGlobalData->field1104=recorderSavedGlobalValue;
}
