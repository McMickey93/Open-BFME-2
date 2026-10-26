// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport

struct Rva00406B1DRecord
{
	~Rva00406B1DRecord();
};

#pragma inline_depth(0)
// ?_bfmeRva00406B1DAnchor@@YAXPAURva00406B1DRecord@@@Z absent-from-retail
void _bfmeRva00406B1DAnchor(Rva00406B1DRecord *p)
{
	delete p;
}
#pragma inline_depth()

// Retail 0x00406B1D is the scalar deleting destructor calling ~Rva00215E42 at 0x004059AC.
#pragma comment(linker, "/alternatename:??1Rva00406B1DRecord@@QAE@XZ=??1Rva00215E42@@UAE@XZ")

