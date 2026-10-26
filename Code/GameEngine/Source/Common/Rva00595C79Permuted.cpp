// The complete native parents and associative EH code/data graphs prove
// the naturally emitted handlers recorded with this unit. Each has one
// primary owner and its full 10-byte extent.
// cl: /Ireference/shims/bfme2_ascii /GX /MD /D_CRTIMP=
//
// ?formatAddress@@YA?AVAsciiString@@PBUNetworkAddress@@@Z, retail 0x00595c79, 34 bytes. Banked partial (score 0.9) closed by tools/permute.py;
// the body is the banked one up to statement/operand order and local types.
#include "ascii_string.h"

typedef unsigned int UnsignedInt;
typedef unsigned short UnsignedShort;

struct NetworkAddress
{
	UnsignedInt m_ip;
	UnsignedShort m_port;
};

AsciiString formatIPPort( UnsignedInt ip, UnsignedShort port )
{
	AsciiString str;
	str.format( "%d.%d.%d.%d:%d", ip >> 24, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff, port );
	return str;
}

AsciiString formatAddress( const NetworkAddress *address )
{
	return formatIPPort( address->m_ip, address->m_port );
}

AsciiString formatIP( UnsignedInt ip )
{
	AsciiString str;
	str.format( "%d.%d.%d.%d", ip >> 24, (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff );
	return str;
}
