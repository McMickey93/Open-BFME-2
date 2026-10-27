// cl: /EHsc /DNDEBUG /MD
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

// GadgetSliderGetMinMax, retail 0x0051822B (27 bytes).
// Retain the rowed helper from the Zero Hour OptionsMenu port. The unrelated
// imported callbacks are not BFME 2 reconstructions; EnumeratedIP's folded
// string getter is provided by OptionPreferences_getLANIPAddress.cpp.

class GameWindow
{
public:
    void *winGetUserData();
};

// Zero Hour Gadget.h supplies these first two SliderData fields. The helper's
// retail loads independently confirm maxVal at +4 and minVal at +0.
struct SliderData
{
    int minVal;
    int maxVal;
};

// ?GadgetSliderGetMinMax@@YAXPAVGameWindow@@PAH1@Z
void GadgetSliderGetMinMax(GameWindow *window, int *min, int *max)
{
    SliderData *slider = (SliderData *)window->winGetUserData();
    *max = slider->maxVal;
    *min = slider->minVal;
}
