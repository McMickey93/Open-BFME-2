// cl: /DNDEBUG /MD /EHsc /Od /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// Ported from the Generals Zero Hour reference
// (Libraries/Source/WWVegas/WWLib/wwfont.cpp); this unit had no counterpart under Code/.
// Retail BFME 2 rows no WWFontClass method: the Zero Hour bodies this port carried
// were unmatched Zero Hour reconstructions, and the TRect<int> members
// they called have no BFME 2 provider, so the unit could not link; they are left
// out. Its one row is the header inline TPoint2D<int>::TPoint2D(int,int)
// (0x00024800, placed by masked search), which those bodies emitted out of line;
// the explicit instantiation below emits it.
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

#include	"always.h"
#include	"point.h"

template TPoint2D<int>::TPoint2D(int, int);
