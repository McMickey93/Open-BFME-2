// WW3D dword option setter with change notification, retail 0x00117BB0.
// Dedicated TU (ww3d.cpp is another lane; the setter must not capture globals
// or the notify pin locally): `mov eax,[esp+4]; cmp [glob],eax; je; cmp-flag;
// mov-glob; je; jmp notify` -- the flag cmp schedules above the store while
// the je still tests it (mov preserves flags).

// cl: /MD

extern int g_Va00DEC40C;
void Rva00117BB0SetOption(int value);

class WW3D
{
	friend void Rva00117BB0SetOption(int value);
	static bool IsInitted;	// 0x00DEC3D4, defined in ww3d.cpp
};

void rva001171B0Notify();

void Rva00117BB0SetOption(int value)
{
	if (g_Va00DEC40C != value) {
		g_Va00DEC40C = value;
		if (WW3D::IsInitted) {
			rva001171B0Notify();
		}
	}
}
