# Territory-details TU evidence

Inspected revision: `cb7bb8a689`, 2026-10-28. The default claim-aware picker
served the unmapped run at 0x005F1773..0x005F23B2: 29 main-text rows in
16 sources. No source, name, pin, row ownership or TU-map edit was made.

## Current target evidence

`tu_evidence.py --source` for
`Code/GameEngine/Source/GameClient/GUI/InGame/Strategic/StrategicHUDRegionDetailsTerritoryMovieClip.cpp`
returns only the CSV header: no structural signal reaches its rows. A fresh
in-memory `tu_map.build(tu_map.Layout(Path.cwd()))` gives all 63 code rows
(including handlers and funclets) in the 16 claimed files no assignment.
The main source accounts for 28 of those rows; its outer-constructor source
accounts for three. The committed map was not rewritten.

The supported `name_lane.py consolidate --under
Code/GameEngine/Source/GameClient/GUI/InGame/Strategic/` report finds no
verified retail path reference in the selected sources. Its path catalogue
has 173 retail CPP paths; the territory-details path appears only as a
WorldBuilder hint. The report also correctly flags the committed TU map as
stale, so the result above uses current inputs instead.

The native region-bonus helpers and constructor are already matched. Earlier
log entries saying their private-register callees were missing are historical;
they are not evidence of a current coverage regression. The main source and
outer constructor both pass `find_declared_unmatched.py`. Their paired normal
build passes **31/31 functions, nine data rows, eleven string literals and two
empty-string references** using current dependency-cache receipts.

## Donor facts and limits

WorldBuilder's constructor lead at retail 0x005F1DB0 names
`StrategicHUD::RegionDetailsTerritoryMovieClip::Impl::Impl`, score 4.25.
The current row explicitly cites WB0161D1A0. This cannot independently
corroborate the class identity it supplied.

`name_evidence.py --kinds wb` still grades the two placeholder member names
as hints: SetBonus at 0x005F1999 scores 1.25; Update at 0x005F1A2D scores 2.
The canonical threshold is 4. `wb_show.py 0x005F1999` displays the donor's
assertions at lines 232..240, its six-element bonus array at +0x2C and the
APT bonus-label format. These are useful pairing facts, not permission to
raise the recorded score or assign a retail translation unit.

`tu_map.demangle` returns no class for both the nested implementation
constructor and the namespaced outer constructor. Its CTOR/METHOD patterns
accept an unqualified class followed immediately by `@@`. Thus these rows
also lack an independent N hint. Simply extracting `Impl` would be wrong:
that token occurs in unrelated UI implementations, and the outer class's
spelling alone does not establish the StrategicHUD-prefixed original file.
The broader limitations are recorded in [the TU approval survey](tu_approval_20261028.md).

## Remaining prerequisite

No supported merge or rename is available from this evidence. Find an
independent retail anchor/bracket, or separately develop and validate qualified
class naming hints while preserving WB self-corroboration exclusions. A parser
extension alone does not prove this destination. The run extends beyond the
territory constructor into listener/tree helpers; adjacency cannot assign
all of it to the UI file.

Retry the current-input TU pass test only when such evidence changes. No
approved rows, source-file reduction, debt retirement or linking gain is claimed.
