# Unplaced help-movie rows: evidence boundary

Inspected BFME 2 revision `cef98283e1`, 2026-10-27. The default picker
claimed the no-signal run 0x00527AEB..0x00527B81: the wrapper in
`Code/GameEngine/Source/Common/Bfme/Rva00527AEBWrapper.cpp` and the methods
at 0x00527B03 and 0x00527B81 in `Rva00527827Constructor.cpp`.

`python3 tools/tu_evidence.py --source
Code/GameEngine/Source/Common/Bfme/Rva00527AEBWrapper.cpp` produces only
the CSV header: no retail layout signal reaches this source. The committed
map leaves the wrapper unplaced. The picker reports only proposed N anchors
below (InGameHelpBoxMovieClip.cpp, 0x005279DD) and above
(Holder00527BA2.cpp, 0x00527BA2); these are not approved brackets.

The current supported planner (`name_lane.py consolidate --under
Code/GameEngine/Source/Common/Bfme/`) reports 109 sources, 89 unresolved
files, no retail-routed rows, and no missing inputs. Its InGameHelpBoxMovieClip
investigation group concerns the separate 0x00527890 move body. The
WorldBuilder lead there cites an external InGameHelpBoxMovieClip.cpp path
with score 1. The selected addresses have no self-asserted WorldBuilder
name; 0x00527B03 has a score-3 unnamed callgraph lead. Neither sweep cache
contains a placement at 0x00527AEB, 0x00527B03, 0x00527B81 or 0x00527C04.
Prior reconstruction evidence explicitly leaves the original class and
concatenation aggregate names unestablished.

Target facts: the wrapper calls the existing help-movie reset and assigns
the reference at +0x1C; the constructor registers a `_Content` custom render;
the name method formats `_level%d`. These relationships do not prove an
original source path or a canonical class name. No source, row, pin, name
basis or TU assignment was changed. The frozen-file check reports all
defined functions matched.

Next useful work requires a re-checkable retail path/name anchor or new
same-body donor evidence. Repeating the same layout query without changed
anchors cannot place this run. Do not approve a TU from the nearby path or
from these behavioral relationships alone.
