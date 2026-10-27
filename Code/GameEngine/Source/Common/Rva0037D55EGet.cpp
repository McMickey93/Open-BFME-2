// cl: /O1 /G7 /arch:SSE /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
// Retail 0x0037D55E..0x0037D6E8 (394 bytes, RET0 with hidden UnicodeString
// return). Builds the first free default replay file name: the format text is
// L"%d" unless TheGameText fetches "GUI:DefaultReplayFileName"; for
// i = 1..99999998 it formats the name, joins the replay directory
// (Rva0037B9D4Get), the name and the replay extension (Rva0037BA48Get) through
// the rowed triple-concat builder (0x0037BA97) and its UnicodeString
// conversion (0x0037D3C9), and returns the first name whose wide path does not
// exist (doesWideFileExist 0x0060068A); L"0" when every name is taken.
// Identity: WorldBuilder twin 0xF5B870 (unnamed, string evidence); the name is
// address-derived. Target facts: literals, call targets, frame and EH states
// read off retail. The copy-initialisation from the triple (conversion result
// copied into the path) is what orders the hidden return push before the
// builder call as retail does; a direct-initialised ctor from the triple
// emits it after.
#include "unicode_string.h"

struct Pair8 { volatile int a; volatile int b; };
// The rowed builder takes Recorder.cpp's volatile aggregate; this caller
// builds the same eight bytes through constructors, as retail's slot order
// needs.
struct Pair8Ctor
{
	Pair8Ctor() {}
	Pair8Ctor(int x, int y) : a(x), b(y) {}
	int a, b;
};
struct Triple12 { Triple12() {} int a, b, c; };
inline Triple12 Rva0037BA97Init(const Pair8 *src, int c)
{
	Triple12 tmp;
	tmp.a = src->a;
	tmp.b = src->b;
	tmp.c = c;
	return tmp;
}
struct BFME2WideConcatTriple
{
	const UnicodeString *a, *b, *c;
	operator UnicodeString();
};
__forceinline Pair8Ctor makePair(const UnicodeString &unicodeString, const UnicodeString &y)
{
	Pair8Ctor pair((int)&unicodeString, (int)&y);
	return pair;
}
__forceinline const Pair8 *pairPtr(const Pair8Ctor &pair8) { return (const Pair8 *)&pair8; }
__forceinline int widePtr(const UnicodeString &unicodeString) { return (int)&unicodeString; }

UnicodeString Rva0037B9D4Get();
UnicodeString Rva0037BA48Get();

class FileSystem {public:bool rva0037BD2B(const UnicodeString &);};
extern FileSystem*TheFileSystem;
class BFME2FileSystemFacade
{
public:
	bool doesWideFileExist(const unsigned short *path);
};
class GameTextInterface {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
    virtual void slot10(); virtual void slot11(); virtual void slot12();virtual void slot13();virtual void slot14();
    virtual UnicodeString fetch(const char *, bool *exists=0);
};
extern GameTextInterface *TheGameText;

UnicodeString Rva0037D55EGet()
{
	UnicodeString formatText((const unsigned short *)L"%d");
	if (TheGameText)
		formatText = TheGameText->fetch("GUI:DefaultReplayFileName");
	for (int i = 1; i < 99999999; ++i)
	{
		UnicodeString filename;
		filename.format(&formatText, i);
		UnicodeString filepath = (BFME2WideConcatTriple &)Rva0037BA97Init(pairPtr(makePair(Rva0037B9D4Get(), filename)), widePtr(Rva0037BA48Get()));
		if (!((BFME2FileSystemFacade *)TheFileSystem)->doesWideFileExist(filepath.str()))
			return filename;
	}
	return UnicodeString((const unsigned short *)L"0");
}
