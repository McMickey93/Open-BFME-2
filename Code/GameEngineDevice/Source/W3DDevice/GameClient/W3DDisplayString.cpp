// cl: /O1 /arch:SSE /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc
/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// BFME 2 declarations follow the existing draw and compute-extents units.
// Retail getWidth reads the first renderer at +0x14 and its font at +0x4C;
// Set_Word_Wrap_Centered accesses the renderer flag at +0x88. These native
// offsets replace the BFME 1 / Zero Hour include stack previously used here.
#include "unicode_string.h"
#include "../../../../Libraries/Include/Lib/ICoord2D.h"
#include "../../../../Libraries/Include/Lib/IRegion2D.h"
#include "../../../../../reference/shims/wwmath/Vector2.h"

typedef bool Bool;
typedef int Int;
typedef int Color;
class GameFont;
class FontCharsClass
{
public:
 int Get_Char_Spacing(unsigned short ch);
};

class RectClass
{
public:
	RectClass( float left, float top, float right, float bottom ) : Left( left ), Top( top ), Right( right ), Bottom( bottom ) {}
	float Left;
	float Top;
	float Right;
	float Bottom;
	RectClass &operator=( const RectClass &r );
};

class DisplayString
{
public:
	virtual ~DisplayString();
	virtual void setText( UnicodeString text );
	virtual UnicodeString getText( void );
	virtual Int getTextLength( void );
	virtual void notifyTextChanged( void );
	virtual void reset( void );
	virtual void setFont( GameFont *font ) { m_font = font; }
	virtual GameFont *getFont( void );
	virtual void setWordWrap( Int wordWrap ) = 0;
	virtual void setWordWrapCentered( Bool isCentered ) = 0;
	virtual void setColors( Color textColor, Color dropColor ) = 0;
	virtual void setTextColor( Color *colors ) = 0;
	virtual void setDropColor( Color *colors ) = 0;
	// MSVC lays out overloaded virtuals in reverse declaration order: the
	// two-argument draw is slot 13, the four-argument draw slot 14.
	virtual void draw( Int x, Int y, Color color, Color dropColor ) = 0;
	virtual void draw( Int x, Int y ) = 0;
	virtual void getSize( Int *width, Int *height ) = 0;
	virtual Int getWidth( Int charPos = -1 ) = 0;
	virtual void bfmeSetFloats17( float a, float b ) = 0;
	virtual void bfmeSetFloats18( float a, float b ) = 0;
	virtual void setUseHotkey( Bool useHotkey, Color hotKeyColor ) = 0;
	virtual void setClipRegion( IRegion2D *region );
	virtual void removeLastChar( void );
	virtual void appendChar( wchar_t c );
	virtual void appendString( const UnicodeString &text );
protected:
	UnicodeString m_textString;
	GameFont *m_font;
	DisplayString *m_next;
	DisplayString *m_prev;
};

class Render2DSentenceClass
{
public:
	~Render2DSentenceClass();
	Vector2 Get_Formatted_Text_Extents(const unsigned short *text);
	FontCharsClass *Peek_Font() { return Font; }
	bool Set_Word_Wrap_Centered(bool centered)
	{
		if (IsWordWrapCentered == centered)
			return false;
		IsWordWrapCentered = centered;
		return true;
	}
	virtual void Reset();
private:
	char m_unrecovered04[ 0x4C - 0x04 ];
	FontCharsClass *Font;
	char m_unrecovered50[ 0x84 - 0x50 ];
	float WrapWidth;																		///< 0x84
	bool IsWordWrapCentered;
	char m_unrecovered89[ 0x8C - 0x89 ];
	RectClass ClipRect;																	///< 0x8C
	char m_unrecovered9C[ 0xAC - 0x9C ];
	bool IsClippedEnabled;															///< 0xAC
	bool ParseHotKey;																		///< 0xAD
	bool UseHardWordWrap;																///< 0xAE
	char m_unrecoveredAF[ 0xC4 - 0xAF ];
};

class W3DDisplayString : public DisplayString
{
public:
	virtual ~W3DDisplayString();
	virtual Int getWidth(Int charPos = -1);
	virtual void setWordWrapCentered(Bool isCentered);
	virtual void notifyTextChanged();
	virtual void setWordWrap( Int wordWrap );
	virtual void setFont( GameFont *font );
	virtual void setColors( Color textColor, Color dropColor );
	virtual void setTextColor( Color *colors );
	virtual void setDropColor( Color *colors );
	virtual void draw( Int x, Int y );
	virtual void draw( Int x, Int y, Color color, Color dropColor );
	virtual void getSize( Int *width, Int *height );
	virtual void setUseHotkey( Bool useHotkey, Color hotKeyColor );
	virtual void setClipRegion( IRegion2D *region );
protected:
	void computeExtents();
public:
	Bool rva00106277( void );
private:
	Render2DSentenceClass m_textRenderer;								///< 0x14
	Render2DSentenceClass m_textRendererHotKey;					///< 0xD8
	UnicodeString m_hotkey;															///< 0x19C
	Bool m_textChanged;																	///< 0x1A0
	Bool m_fontChanged;																	///< 0x1A1
	Bool m_bfmeColorsChanged;														///< 0x1A2
	Bool m_useHotKey;																		///< 0x1A3
	ICoord2D m_hotKeyPos;																///< 0x1A4
	ICoord2D m_textPos;																	///< 0x1AC
	Color m_hotKeyColor;																///< 0x1B4
	Color m_textColors[ 4 ];														///< 0x1B8
	Color m_dropColors[ 4 ];														///< 0x1C8
	Int m_colorKey;																			///< 0x1D8, callback value of m_textColors[0]
	Int m_sizeX;																				///< 0x1DC
	Int m_sizeY;																				///< 0x1E0
	IRegion2D m_clipRegion;															///< 0x1E4
	unsigned int m_lastResourceFrame;										///< 0x1F4
};

// ?getWidth@W3DDisplayString@@UAEHH@Z
Int W3DDisplayString::getWidth( Int charPos )
{
	FontCharsClass *	font;
	Int width = 0;
	Int count = 0;

	font = m_textRenderer.Peek_Font();

	if ( font )
	{
		const unsigned short *text = m_textString.str();
		unsigned short ch;

		while ( (ch = *text++ ) != 0 && ( charPos == -1 || count < charPos ) )
		{
			if ( ch != (unsigned short)'\n' )
			{
				width += font->Get_Char_Spacing( ch );
			}
			count++;
		}
	}

	return width;
}


void W3DDisplayString::setWordWrapCentered( Bool isCentered )
{
	// set the Word Wrap
	 if( m_textRenderer.Set_Word_Wrap_Centered(isCentered) )
		notifyTextChanged();
}// void setWordWrap( Int wordWrap )
