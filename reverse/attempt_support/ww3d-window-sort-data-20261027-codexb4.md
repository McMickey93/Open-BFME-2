# WW3D window and default-sort storage bindings

Inspected revision: `0054abc1930e`, 2026-10-27. Claimed scope:
`Code/Libraries/Source/WWVegas/WW3D2/ww3d.cpp`.

The consumer defined a private `_Hwnd` and `WW3D::DefaultStaticSortLists`,
although `WW3D_Init_Bfme.cpp` already owns and initializes `g_WW3D_Hwnd` and
the two-slot `g_WW3D_StaticSortGlobals`. The target screenshot operand at
RVA `0x001174F0 + 334` contains VA `0x00DEC408`; the reset-list operands at
`0x00117CC0 + 1` and `+6` contain VAs `0x00DEC3F0` and `0x00DEC3F4`.
These are address/binding facts supported by matched code and the existing
owner, rather than evidence of original retail global names.

Declare the existing window and sort-pair globals in this TU and use the
window owner in Get_Window/Make_Screen_Shot and the first sort-pair slot in
Reset_Current_Static_Sort_Lists_To_Default. The struct declaration mirrors
the owner's two `void *` fields. Other storage and shared headers are unchanged.
No other Code source uses the removed DefaultStaticSortLists member; the
remaining SimpleStreakRenderer declaration is unused. `_Hwnd` was TU-local.

Verification:

- The two-source normal build passes 36/36 function rows, three data rows,
  six string literals plus empty-string references, four float literals and
  four named imports. Both exception graphs are EXACT. The frozen-file check
  passes (the existing 31 unclaimed-definition exemptions remain).
- All 78 executable sections (2,786 bytes, including unrowed code) retain
  identical raw bytes. Exactly three global relocation referents change:
  the two window loads and the default-list load. A compiler-local EH label
  is renumbered; its target bytes/value are identical and EH verification passes.
- Shadow data findings fall from ten (two outside the baseline) to six
  (zero outside). The default-list duplicate/wrong-name findings disappear;
  `repair_queue.py retire data SOURCE` retires the two registered `_Hwnd`
  keys, leaving six Movie/PixelCenter keys. Converged-data checking passes
  for both sources with ten addresses and zero second names/unjudged rows.
- Code identity reports six references, zero wrong bindings. `check_csv.py`
  passes. The declaration-only binding introduces no hatch or data-ledger row.
- Ordinary paired preview against index `bf3dd31211` is unchanged: the init
  owner LINKS at 168 authored bytes; ww3d.cpp retains ten duplicate-provider
  names and selected Stop_Movie_Capture. The index still includes absorbed
  donor providers (LINK-017); this result does not establish a new regression
  or any census/image-ownership gain. Remaining storage cleanup is LINK-007.

Control/final objects and comparison receipt are in the untracked
`build/codexb4-ww3d-data-20261027/` directory.

## Earlier picker checks in this pass

WaterRenderObjInit.cpp passes all four function rows and its shader data row.
Alone it retains the historical selected BFME_DX8_Thread_Lock blocker; paired
with the repaired BfmeDX8ThreadLock.cpp it is 2/2 LINKS (297 + 247 authored
bytes), confirming LINK-106 without a source change. Both claims were released.

ScriptGlueRva003BE7ED.cpp still has its previously recorded registry-owner
blocker: two outside-register findings at RVA `0x009FE358`. No new identity
evidence was found, no source was changed and its file claim was released.

## Recovery reconciliation (2026-10-28)

Upstream `9d948e7e72` already binds the window consumers to `g_WW3D_Hwnd`
and retires the two window keys. It also resolves the sort storage in the
other direction: initialization and shutdown use the real
`WW3D::DefaultStaticSortLists` / `CurrentStaticSortLists` owners. Keep that
coherent upstream binding; do not resurrect `g_WW3D_StaticSortGlobals`.
The original checks above are historical evidence, not current census results.
No source or baseline edit from this saved commit remains to apply.
