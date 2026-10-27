# LINK-015: the VectorClass<Vector3> table's slot 5 is 0x000F0E20, not 0x001298B0 (2026-10-27)

Model claude-opus-5.5, seat halilkkaya-lk2. Base `d16a31e4dc`, census index
`73061d9452` (2026-10-27 14:34).

## Symptom

`Rva007B7280Siblings.cpp` (353 B) and `Rva007B73C0.cpp` (59 B) lose
`??_G?$VectorClass@VVector3@@@@UAEPAXI@Z`: their /O2 teardowns inline the
destructor, so cl synthesizes an inlined deleting destructor (digest
`ac2be0dc8c7c`, verdict `wrong`). Retail-truth-3 would let those copies stand
if the owner's copy (`vector_class_vector3_ctor.cpp`, first in link order)
were proven retail, but it is only `unknown`.

## Root cause (target facts)

The owner's `??_G` has a DIR32 to `??_7?$VectorClass@VVector3@@@@6B@`, which
has no ledger address, so RetailTruth judges the owner's own vtable copy at
retail's target 0x00BCEFAC slot by slot (`_defined_at`). Retail's table:

| slot | retail | what the ledger says for the Vector3 name |
|---|---|---|
| 0 `??_G` | 0x000F1CF7 | row, lands |
| 1 `operator==` | 0x000F1C16 | no address, and the owner declares it decl-only: unknown |
| 2 `Resize` | 0x000F0BF1 | row, lands |
| 3 `Clear` | 0x000F0CD4 | ICF pin, lands |
| 4 `ID(T const &)` | 0x000F0DC5 | no address, decl-only in the owner: unknown |
| 5 `ID(T const *)` | 0x000F0E20 | row at **0x001298B0** (pointgr.cpp): wrong |

(MSVC puts the two `ID` overloads in reverse declaration order.)

0x001298B0 is not VectorClass<Vector3>'s pointer `ID`:

- The only references to 0x005298B0 are slot 5 of 0x00BD1274 and of 0x00BD14EC.
  Those two tables belong to VectorClass<TextureStatisticsStruct> and
  DynamicVectorClass<TextureStatisticsStruct> (slots 0-4 are the rowed
  TextureStatisticsStruct bodies 0x0012A5C0, 0x00129950, 0x00129990, 0x00129B00,
  0x00129880 and 0x0012A620, 0x00129950, 0x00129B40, 0x0012A580, 0x0012A550).
- 0x001298B0 sits between 0x00129880 and 0x00129950, inside the
  statistics.cpp block that tu_map approves; TextureStatisticsStruct is 12
  bytes (a RefCountPtr plus two ints), hence `mul 0xAAAAAAAB; shr 3`.
- 0x000F0E20 is the /O1 shape of the same identification (`push 0Ch; pop ecx;
  div ecx`), referenced only from slot 5 of 0x00BCEFAC.

The owner unit, built with its own flags (/O1 /G7 /arch:SSE), compiles
VectorClass<Vector3>::operator==, ID(T const &) and ID(T const *) to exactly
retail's 0x000F1C16 (100 B), 0x000F0DC5 (91 B) and 0x000F0E20 (27 B)
(masked compare: EXACT). Those addresses carry TCBSpline3DClass::TCBClass rows
from tcbspline.cpp, the ICF twin with the same 12-byte float triple.

## Verified repair (not landed)

`link015-identity.patch` (applies to `d16a31e4dc`):

1. `vector_class_vector3_ctor.cpp` stops declaring operator==, ID(T const &)
   and ID(T const *) decl-only, so it emits retail's /O1 bodies with its vtable.
2. `pointgr.cpp` declares those three decl-only instead of explicitly
   instantiating its /G7 copies; `collect.cpp` and `DX8SkinClearVisibleList.cpp`
   declare operator== decl-only (collect.obj is before the owner in link order);
   both teardown units declare ID(T const *) decl-only.
3. The 0x001298B0 row becomes
   `?ID@?$VectorClass@UTextureStatisticsStruct@@@@UAEHPBUTextureStatisticsStruct@@@Z`,
   emitted by `TextureStatisticsVectorID.cpp` (WWLib's body plus an explicit
   instantiation; the DynamicVectorClass forwarder is WWLib's inline one), and
   that unit's two `/alternatename` lines onto the Vector3 name go
   (alternatename -2). The approved TU for 0x001298B0 is statistics.cpp, whose
   other donor TextureStatisticsVectorID.cpp already holds 0x00129880 and
   0x00129950; a landing may prefer statistics.cpp itself.

Results with all seven touched objects current:

- `./build.sh` on the seven sources: Functions OK 91/91 (0x001298B0 verifies
  from TextureStatisticsVectorID.cpp).
- `link_check.py` over 19 units: `Rva007B7280Siblings.cpp` 0 -> 353 B and
  `Rva007B73C0.cpp` 0 -> 59 B; TextureStatisticsVectorID.cpp 241 -> 274 B and
  pointgr.cpp 10,565 -> 10,532 B (the 33-byte row moves); the owner,
  DX8SkinClearVisibleList, PointGroupClassRva0017A890, mesh,
  FXShaderRendererSkin, vector_class_vector3_resize, vector_class_resize and
  the five TextureStatistics units keep linking; collect.cpp and tcbspline.cpp
  keep only their earlier, unrelated blockers. Total 30,747 -> 31,159 B.
- Without collect.cpp's current object the owner loses `??8` to collect's
  census copy, so collect.cpp must ride in the same batch.

## Why it was not landed

- `pointgr.cpp` and the 0x001298B0 claim were refused: seat
  `halilkkaya-pins2` holds RVA claims inside pointgr.cpp (0x0013EDB0,
  0x00179010, 0x0017F150, symbols.csv-only pin retirement), which locks the
  file.
- Moving a matched row to a new name and source has no tool path:
  `add_match.py --replace-rva` accepts scaffold rows only, and `rename.py
  function` changes the identifier only. The seat's brief allows only those
  two tools for row renames.

Next step: once pointgr.cpp is free, land the patch with the row moved (hand
ledger edit plus a deleted_rows.csv tombstone, or a tool that can move it),
then rerun the 19-unit link_check above.
