// cl: /DNDEBUG /MD /EHsc
// Retail RVA 0x00326CF0, 249 bytes.
// BFME2 multiline listbox helper: splits input UnicodeString at 0x0A/NUL and
// appends each line via GadgetListBoxAddEntryText (0x00326BEC), returning rows
// added. Ported from Open-BFME-1
// game/GameEngine/Source/GameClient/GUI/Gadget/Rva004BB670GadgetListBoxAddEntryTextLines.cpp.
// Evidence: callers at 0x0057CA02/0x0057D838, callees concat 0x00037410,
// copy ctor 0x00037050, releaseBuffer 0x00036E70, AddEntryText 0x00326BEC.
#include "../../../../../reference/shims/bfme2_ascii/unicode_string.h"

// Native inlines these operations here, while other consumers call their
// rowed out-of-line bodies. dllimport suppresses unused competing copies.
template <> __declspec(dllimport) __forceinline unsigned short
StringBase<unsigned short>::getCharAt(int index) const throw()
{
	return m_data ? m_data->data[index] : 0;
}
template <> __declspec(dllimport) __forceinline bool
StringBase<unsigned short>::isEmpty() const throw()
{
	return m_data == 0 || m_data->length == 0;
}
template <> __declspec(dllimport) __forceinline void
StringBase<unsigned short>::concat(unsigned short c)
{
	concat(&c, 1);
}

class GameWindow;

int GadgetListBoxAddEntryText(GameWindow *listbox, UnicodeString text, int color, int row, int column, bool overwrite);

int Rva00326CF0AddLines(GameWindow *listbox, UnicodeString text, int color, int row, int column, bool overwrite)
{
	int length = text.getLength();
	UnicodeString line;
	int rowsAdded = 0;
	for (int i = 0; i <= length; ++i) {
		unsigned short character = (i < length) ? text.getCharAt(i) : 0;
		if (character == 0x0A || character == 0) {
			if (line.isEmpty())
				line.concat((unsigned short)' ');
			GadgetListBoxAddEntryText(listbox, line, color, row++, column, overwrite);
			++rowsAdded;
			line.clear();
		} else {
			line.concat(character);
		}
	}
	return rowsAdded;
}
