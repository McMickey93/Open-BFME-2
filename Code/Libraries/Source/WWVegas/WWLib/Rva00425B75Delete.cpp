// cl: /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

class LightPoint
{
public:
	~LightPoint();
};

#include <new>

void __stdcall Rva00425B75Delete(LightPoint *lightPoint)
{
	if (lightPoint != 0)
	{
		lightPoint->~LightPoint();
		operator delete(lightPoint);
	}
}
