// cl: /Od /GZ /GS /MD /DNDEBUG
// platformsdk

#include <windows.h>
#include <string.h>

struct Rva00819F50Comm
{
	char m_head[ 0x7c ];
	HANDLE m_handle;
	OVERLAPPED m_readOverlapped;
	OVERLAPPED m_waitOverlapped;
	char m_gapA8[ 0x10 ];
	HANDLE m_event2;
	DWORD m_bytesRead;
	DWORD m_commMask;
	char m_gapC4[ 0x44 ];
	unsigned char m_buffer[ 0x800 ];
	int m_bufferLength;
};

struct Rva00819F50Record
{
	int m_length;
	unsigned int m_tick;
	unsigned char m_data[ 4 ];
};

extern "C"
{
	unsigned short __cdecl Rva0081A360( const unsigned char *data,
		int length );
}

extern "C" int __cdecl Rva00819F50( struct Rva00819F50Comm *comm,
	struct Rva00819F50Record *record )
{
	int state;
	int available;
	int packetLength;
	unsigned char *data;
	unsigned char *packet;

	available = comm->m_bufferLength;
	data = comm->m_buffer;
	state = 0;

	for ( ;; )
	{
		if ( state != 0 || available < 8 )
		{
			comm->m_readOverlapped.Internal = 0;
			comm->m_readOverlapped.InternalHigh = 0;
			comm->m_readOverlapped.Offset = 0;
			comm->m_readOverlapped.OffsetHigh = 0;

			if ( ReadFile( comm->m_handle, data + available,
				0x800 - available, &comm->m_bytesRead,
				&comm->m_readOverlapped ) == 0
				&& GetLastError() == 0x3e5 )
			{
				GetOverlappedResult( comm->m_handle,
					&comm->m_readOverlapped, &comm->m_bytesRead, 1 );
			}

			if ( comm->m_bytesRead > 0 )
			{
				available = available + comm->m_bytesRead;
				state = 0;
				continue;
			}

			if ( WaitForSingleObject( comm->m_waitOverlapped.hEvent, 0 ) == 0x102 )
			{
				comm->m_bufferLength = available;
				return 0;
			}

			comm->m_readOverlapped.Internal = 0;
			comm->m_readOverlapped.InternalHigh = 0;
			comm->m_readOverlapped.Offset = 0;
			comm->m_readOverlapped.OffsetHigh = 0;

			if ( WaitCommEvent( comm->m_handle, &comm->m_commMask,
				&comm->m_waitOverlapped ) == 0
				&& GetLastError() == 0x3e5 )
			{
				comm->m_bufferLength = available;
				return 0;
			}

			state = 1;
			continue;
		}

		if ( data[ 0 ] != 'G' || data[ 1 ] != 'S'
			|| data[ 2 ] != ( data[ 3 ] ^ 0xff ) )
		{
			if ( data[ 0 ] != 0 )
				OutputDebugStringA( "bogus packet\n" );
			data++;
			available--;
			goto rva00819f50_scan_condition;

	rva00819f50_scan_advance:
			data++;
			available--;

	rva00819f50_scan_condition:
			if ( available > 0 )
			{
				if ( data[ 0 ] != 'G' )
					goto rva00819f50_scan_advance;
				if ( available > 1 )
				{
					if ( data[ 1 ] != 'S' )
						goto rva00819f50_scan_advance;
				}
				if ( available > 3 )
				{
					if ( data[ 2 ] !=
						( data[ 3 ] ^ 0xff ) )
						goto rva00819f50_scan_advance;
				}
			}

	rva00819f50_scan_done:
			if ( available > 0 )
			{
				memcpy( comm->m_buffer, data, available );
			}
			data = comm->m_buffer;
			continue;
		}

		packetLength = data[ 2 ] + 8;
		if ( available < packetLength + 8 )
		{
			state = 1;
			continue;
		}

		packet = data + packetLength + 4;
		if ( packet[ 2 ] != 0x0d || packet[ 3 ] != 0x0a
			|| Rva0081A360( data + 4, packetLength )
			!= ( packet[ 0 ] | ( packet[ 1 ] << 8 ) ) )
		{
			data[ 0 ] = 0;
			state = 0;
			OutputDebugStringA( "bogus packet\n" );
			continue;
		}

		memcpy( (char *)record + 8, data + 4, packetLength );
		record->m_length = packetLength - 8;
		record->m_tick = GetTickCount();
		comm->m_bufferLength = available - ( packetLength + 8 );

		if ( comm->m_bufferLength != 0 )
			memcpy( comm->m_buffer, packet + 4, comm->m_bufferLength );

		return 1;
	}
}
