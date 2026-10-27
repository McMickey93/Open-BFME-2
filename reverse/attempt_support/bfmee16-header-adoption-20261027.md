# BfmeE16 header adoption

Inspected revision: `7ed44e8ffd`. Claim: `class:BfmeE16`.
Published preview index: `bf3dd31211`, 2026-10-27 00:39, retail-truth-4.

## Repairs

- `Code/GameEngine/Source/Common/Rva003F86F9Ctor.cpp` replaces its four-float
  private BfmeE16 definition with the registered header. The cleanup row at
  0x0078435C previously described its parent only in prose. `add_match.py
  --replace-existing` adds the actual `parent=` token for the already rowed
  parser at 0x003F90E4, keeping the existing name, extent, source and
  `object-symbol=$L5043` hint. Before the include change, `eh_verify` proves
  the parent graph EXACT and places `$L5043` at 0x0078435C. After the change,
  the same exact graph places `$L5044` there. The byte gate uses its supported
  parent-graph resolver; no label respelling or new hatch is needed.
- `Code/GameEngine/Source/Common/Rva00579731Dtor.cpp` replaces its private
  BfmeE16 definition with the registered header. The existing INI interface's
  FieldParse record supplies the typed token, callback, user-data and offset
  accesses. Its representation is passed to the existing vector<BfmeE16>
  storage helpers, as the terminator record already was. The vector helper
  identities and the record's four native word positions stay unchanged.
  This removes a conflicting private class definition; it does not establish
  an original name for the wider BfmeE16 helper family.

## Verification

- Normal `./build.sh` runs pass 3/3 rows (247 ledger bytes) and both data rows
  for the parser, and 23/23 rows (1,033 ledger bytes) for the stats display.
  All string, floating-literal and import-reference checks pass. The stats
  display already had four renumbered funclet hints before this change; after
  it, thirteen resolve through exact parent EH graphs. Those hints are retained.
- `eh_verify.py` reports five EXACT EH graphs, zero nonexact and zero missing
  objects across the two sources. `find_declared_unmatched.py` reports all
  defined functions matched in both sources. `check_csv.py` passes.
- The parser's ordinary preview is LINKS, retaining the census's 237 authored
  bytes. The stats display's current-object preview before adoption is LINKS
  for 862 authored bytes. Final combined preview is LINKS for both units,
  retaining 237 + 862 = 1,099 authored bytes. Its parser allocation-rebind
  diagnostic is unreferenced and is not a blocker.
- `header_adopt_lane.py accept --class BfmeE16` passes for both sources and
  retires their two queue entries through the owning tool. No BfmeE16 entry
  remains in the header queue.

The shared header, symbol pins, escape-hatch counts and existing helper names
are unchanged. This is header-debt retirement; no new matched bytes, census
gain, strict closure or image-ownership gain is claimed.

## Preparation recovery

Recovered the seven-path saved edit from stash
`b1db0a09c4964a063714e573239a8efc20c3e79c` onto `e1a73387fd`.
The retained backup `7ed44e8ffd` has no commits absent from upstream; its
already landed work was not reapplied. The obstacle-register conflict keeps
both upstream's c140 follow-up and this adoption's evidence. The stash and
preparation backup remain retained; there were no separately saved untracked
files.

Current recovery checks pass: 26/26 function rows, two data rows, five EXACT
EH graphs, no declared unmatched bodies, clean CSV and whitespace checks.
Both current-object previews remain LINKS for 237 + 862 authored bytes against
`bf3dd31211`; its unreferenced allocation-rebind diagnostic remains unchanged.
Replayed both queue retirements through `header_adopt_lane.py accept` against
current upstream rather than retaining the saved queue deletion on trust.
