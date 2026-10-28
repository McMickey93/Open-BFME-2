# Fold rows drag the census link order (LINK-132; recorded as LINK-131 before renumbering)

Seat claudeb2, 2026-10-28, master `739f3c6957`, census index `54b83e4f69`
(2026-10-28 09:35).

## Target fact

`Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DVideoStateAllocate.cpp`
(/O1, 0x000725BC `Rva000724AE::rva000725BC`) is byte-exact and its only census
blocker is `wrong_selected` on `??4W3DRadarResetSurface@@QAEAAV0@ABV0@@Z`.
Retail's copy is the 43-byte /O1 body at 0x00072381, owned by
`W3DMouse_loadD3DCursorTextures.cpp` (its second vtable load uses `ecx`).

## Why the wrong copy wins

Four other objects emit an out-of-line COMDAT of the same operator= compiled at
/O2 (second vtable load in `edx`, different digest):
`WWLib/mixfile.cpp`, `WW3D2/Render2DSentenceDrawBFME2.cpp`,
`WW3D2/Render2DSentenceGlyphSurfaceBFME2.cpp`,
`WW3D2/PendingSurfaceStructResize.cpp`.

`tools/link_census.py` `link_order` ranks code objects by their lowest matched
RVA. `Render2DSentenceDrawBFME2.cpp` carries the fold row
`??1RendererDataStruct@Render2DSentenceClass@@QAE@XZ` at 0x00001E13 (8 B,
`fold-proof=`, ICF twin of `??1Rva00001E13@@QAE@XZ` in
`ATL/Rva00001E13Dtor.cpp`). That one shared-address row places the object at
link index 27, ahead of every retail owner, so the first-copy rule keeps its
/O2 operator=.

## Source changes tried (all reverted)

* Declaration-only operator= in mixfile.cpp: 9/9 exact, but no gain alone.
* Declaration-only in the three WW3D2 units: byte mismatches, because
  `Draw_Sentence`, `Rva00158990` (0x158990) and
  `DynamicVectorClass<PendingSurfaceStruct>::Add` (0x157060) inline the
  operator in retail.
* MSVC 7.1 /O2 emits the out-of-line COMDAT for every used inline, even when
  fully inlined and even with `__forceinline` (scratch compiles under
  `build/scratch/`). /O1 and /Os give `ecx`; /O2, /Ob1 and /Og give `edx`.
  So no spelling of these /O2 units drops or reshapes the copy.

## Proposed census rule (maintainer decision)

Ignore `fold-proof=` rows when computing an object's link position (fall back
to them only for an object with no other matched row). `order_sim.py` here
re-ranks the current index under that rule; `order_sim.txt` is its output:

* 11 COMDAT names turn retail-first, 3 turn non-retail-first.
* 126 unlinked units (270,718 B, upper bound: new conflicts are not
  re-judged) are blocked only by `wrong_selected` on gained names, including
  W3DVideoStateAllocate.cpp, pathfinder.cpp (50,353), HordeContainIface11CSlots.cpp
  (23,871), seglinerenderer.cpp (18,478), GameEngineInit.cpp (9,424).
* 14 linked units (31,695 B, upper bound) touch a lost name, such as
  PeerThread.cpp (18,622) via `basic_string::append(const char *)`.

Ignoring every shared-RVA row instead is net negative (10 gains, 37 losses).

This is a census rule change: it lands only through
`tools/census_rebaseline.py`, run by a maintainer. Structural inference only;
no census confirmation is claimed.
