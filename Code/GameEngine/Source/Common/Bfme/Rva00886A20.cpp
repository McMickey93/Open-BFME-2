// cl: /DNDEBUG /MD /EHs-c-

#include <stdio.h>

class Rva00886A20Class
{
public:
	char pad[0x2C];
	int m_size2C;

	int d_00886a20( const char* name, int dummy );
};

class Cftp
{
public:
	char pad0[0x34];
	const char* m_dir34;
	void d_008859d0( const char* name, char* outBuf );
};

int Rva00886A20Class::d_00886a20( const char* name, int dummy )
{
	char buf[256];
	((Cftp *)this)->d_008859d0( name, buf );

	FILE *file = fopen( buf, "rb" );
	if ( !file )
	{
		m_size2C = (int)file;
		return (int)file;
	}

	fseek( file, 0, 2 );
	m_size2C = ftell( file );
	fclose( file );
	return m_size2C;
}
