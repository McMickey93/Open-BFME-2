// Two more tiny ones: a masked flag read through two guards and an unsigned
// count turned into a scaled double. (The third, bfmeSetSign 0x00039880, now
// lives in its approved unit Code/Libraries/Source/debug/debug_cmd.cpp.)

class BfmeThingBW
{
public:
	char m_bfmeHead[0x48];					// +0x00
	int m_bfmeReady;					// +0x48
	char m_bfmeGap[0x18];					// +0x4C
	int m_bfmeFlags;					// +0x64
};

// ?bfmeMask@@YAHPAVBfmeThingBW@@@Z
int __cdecl bfmeMask(BfmeThingBW *thing)
{
	if (!thing)
		return 0;

	if (!thing->m_bfmeReady)
		return 0;

	return thing->m_bfmeFlags & 0x20;
}


// ?bfmeScale@@YANI@Z
double __cdecl bfmeScale(unsigned int value)
{
	return value * 0.001;
}
