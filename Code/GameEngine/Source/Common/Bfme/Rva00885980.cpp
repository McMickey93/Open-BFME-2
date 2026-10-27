// cl: /DNDEBUG /MD /EHs-c-

extern "C" int __stdcall closesocket( int s );

class Rva00885980Class
{
public:
	char m_pad0[4];
	int m_socket; // at 0x4
	int m_socket8; // at 0x8

	int d_00885980( void );
	void d_00885960( void );
};

// ?Rva00885980Class::d_00885980 present-unmatched
int Rva00885980Class::d_00885980( void )
{
	closesocket( m_socket );
	return 0;
}

void Rva00885980Class::d_00885960( void )
{
	closesocket( m_socket8 );
	m_socket8 = 0;
}

class Cftp
{
public:
	char m_pad0[4];
	int m_iCommandSocket; // +0x04
	int m_iDataSocket; // +0x08

	void d_00885390( void );
};

void Cftp::d_00885390( void )
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
}
