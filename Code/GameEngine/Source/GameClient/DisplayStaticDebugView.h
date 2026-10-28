#ifndef BFME2_DISPLAY_STATIC_DEBUG_VIEW_H
#define BFME2_DISPLAY_STATIC_DEBUG_VIEW_H

#include <stdio.h>

// Shared prefix for the rowed static-image and debug-callback methods.
// Retail W3DDisplay vtable RVA 0x007C3C80, slot 74 (+0x128), contains
// VA 0x0065C6BD: Display::setDebugDisplayCallback. Unknown slots retain pads.
class DebugDisplayInterface;
typedef void DebugDisplayCallback(DebugDisplayInterface *, void *, FILE *);

class W3DDisplay;
class Image;

class Rva0025C6E2Elem
{
	friend class Display;
public:
	void rva0025C8D3(W3DDisplay *disp, int id, int color);
	void rva0025C829(W3DDisplay *disp, int id);
private:
	Image *m_00;
	float m_04;
	float m_08;
	float m_0c;
	float m_10;
	int m_14;
};
enum { MAX_STATIC_IMAGES = 3 };

class Display
{
public:
	virtual void pad00();
	virtual void pad01();
	virtual void pad02();
	virtual void pad03();
	virtual void pad04();
	virtual void pad05();
	virtual void pad06();
	virtual void pad07();
	virtual void pad08();
	virtual void pad09();
	virtual void pad10();
	virtual void pad11();
	virtual void pad12();
	virtual void pad13();
	virtual void setWidth(unsigned int width);
	virtual void setHeight(unsigned int height);
	virtual unsigned int getWidth();
	virtual unsigned int getHeight();
	virtual void pad18();
	virtual void pad19();
	virtual void pad20();
	virtual bool getWindowed();
	virtual bool setDisplayMode(unsigned int xres, unsigned int yres, unsigned int bitdepth, bool windowed);
	virtual void pad23();
	virtual void pad24();
	virtual void pad25();
	virtual void pad26();
	virtual void pad27();
	virtual void pad28();
	virtual void pad29();
	virtual void pad30();
	virtual void pad31();
	virtual void pad32();
	virtual void pad33();
	virtual void pad34();
	virtual void pad35();
	virtual void pad36();
	virtual void pad37();
	virtual void pad38();
	virtual void pad39();
	virtual void pad40();
	virtual void pad41();
	virtual void pad42();
	virtual void pad43();
	virtual void pad44();
	virtual void pad45();
	virtual void pad46();
	virtual void pad47();
	virtual void pad48();
	virtual void pad49();
	virtual void pad50();
	virtual void pad51();
	virtual void pad52();
	virtual void pad53();
	virtual void pad54();
	virtual void pad55();
	virtual void pad56();
	virtual void pad57();
	virtual void pad58();
	virtual void pad59();
	virtual void pad60();
	virtual void pad61();
	virtual void pad62();
	virtual void pad63();
	virtual void pad64();
	virtual void pad65();
	virtual void pad66();
	virtual void pad67();
	virtual void pad68();
	virtual void pad69();
	virtual void pad70();
	virtual void pad71();
	virtual void pad72();
	virtual void pad73();
	virtual void setDebugDisplayCallback(DebugDisplayCallback *callback, void *userData = NULL);
	void DrawStaticImage(int index, int arg);
	void SetMovieImage(int image, int index, float x0, float y0, float x1, float y1);
	void SetStaticImage(int image, int index, float x0, float y0, float x1, float y1);
	void rva0025C776(int a8, float fc, float f10, float f14, float f18, int a1c, int a20);

private:
	unsigned char m_pad04[8];
	unsigned int m_height; // +0x0c
	unsigned int m_width; // +0x10
	unsigned char m_pad14[0x30 - 0x14];
	DebugDisplayCallback *m_debugDisplayCallback; // +0x30
	void *m_debugDisplayUserData; // +0x34
	unsigned char m_pad38[0x68 - 0x38];
	Rva0025C6E2Elem m_staticImages[MAX_STATIC_IMAGES]; // +0x68
	unsigned char m_padB0[0x110 - 0xB0];
	int m_110;
	unsigned char m_pad114[4];
	int m_118;
	float m_11c;
	float m_120;
	int m_124;
	float m_128;
	float m_12c;
	float m_130;
	float m_134;
	int m_138;
};

#endif
