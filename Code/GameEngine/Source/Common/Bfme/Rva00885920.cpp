// cl: /DNDEBUG /MD /EHs-c-

extern "C" int __stdcall accept( int, void*, void* );
extern "C" int __stdcall WSAGetLastError( void );

class Cftp
{
public:
	char m_pad0[4];
	int m_iCommandSocket; // +0x04
	int m_iDataSocket; // +0x08

	int d_00885920( void );
	int d_00885530( const char* command, int size );
};


int Cftp::d_00885920( void )
{
	if ( !m_iDataSocket )
	{
		return 0x80040001;
	}
	int s = accept( m_iDataSocket, 0, 0 );
	if ( s < 0 )
	{
		return ( WSAGetLastError() == 10035 ) ? 0x80040002 : 0x80040001;
	}
	m_iDataSocket = s;
	return 0;
}
