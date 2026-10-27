// cl: /DNDEBUG /MD /EHs-c-
//
// Cftp::~Cftp, retail 0x006CA600, 81 bytes (BFME1 donor Rva00885AF0;
// Zero Hour WWDownload ftp.cpp): close the data and control sockets and the
// transfer file. Written as the real virtual destructor, the compiler stores
// Cftp's vtable (0x00CE8A38) itself; Cftp::Cftp (ftp_constructor.cpp) and
// its vtable's deleting destructor reach this body by that name.
extern "C" int __stdcall closesocket( int );
#include <stdio.h>

class Cftp
{
public:
	virtual ~Cftp();
	int m_iCommandSocket; // +0x04
	int m_iDataSocket; // +0x08
	char padC[0x3AC];
	FILE *m_pfLocalFile; // +0x3B8
};

Cftp::~Cftp()
{
	if ( m_iDataSocket )
	{
		closesocket( m_iDataSocket );
		m_iDataSocket = 0;
	}
	if ( m_iCommandSocket )
	{
		closesocket( m_iCommandSocket );
		m_iCommandSocket = 0;
	}
	if ( m_pfLocalFile )
	{
		fclose( m_pfLocalFile );
		m_pfLocalFile = 0;
	}
}
