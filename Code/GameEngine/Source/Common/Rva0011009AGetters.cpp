// cl: /GX-
// ?Rva0011009AGet@@YAHXZ @ 0x0011009A (6B): global dword getter reading
// 0x00DB5FD4 (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape).
// First of an adjacent pair (0x11009A/A0, themselves preceded by an A0-form
// global byte getter); dedicated TU so no caller inlines the load
// (Rva007EB810Get precedent).

// 0x00DB5FD4/0x00DB5FD8 are the data ledger's DX8Wrapper::ResolutionWidth
// and ResolutionHeight (dx8wrapper.cpp's protected statics, @@1): a minimal
// view of the real class reads them through an inline accessor.
class DX8Wrapper {
public:
	static __forceinline int Get_Device_Resolution_Width() { return ResolutionWidth; }
	static __forceinline int Get_Device_Resolution_Height() { return ResolutionHeight; }
protected:
	static int ResolutionWidth;
	static int ResolutionHeight;
};

int Rva0011009AGet(void)
{
	return DX8Wrapper::Get_Device_Resolution_Width();
}

// ?Rva001100A0Get@@YAHXZ @ 0x001100A0 (6B): same shape over 0x00DB5FD8.


int Rva001100A0Get(void)
{
	return DX8Wrapper::Get_Device_Resolution_Height();
}
