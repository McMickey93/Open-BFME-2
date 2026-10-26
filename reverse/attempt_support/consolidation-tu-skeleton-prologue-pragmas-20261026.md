# tu_skeleton compose: prologue pragmas and bodies stay between includes (2026-10-26, claude3)

## Blocker

`tools/tu_skeleton.py compose()` emitted every `#pragma optimize` and every
function body in the body section (after all includes), even when a donor
places them before its last `#include`. MSVC applies `#pragma optimize` to each
function at its definition, so a pragma that scopes a header's inline functions
only works around that `#include`. Composed, the inlines compiled under the
wrong optimization state, and a seed that verifies standalone lost bytes.

Target facts (compiler and byte verifier; no ledger change):

- `Code/Libraries/Source/WWVegas/WW3D2/mapper.cpp` wraps `refcount.h` in
  `#pragma optimize("s", on)` and `vector2.h` in `#pragma optimize("gsy", on)`,
  with its `??_H` anchor body between them. Composed alone (before the fix) it
  lost 0x001854E0 and 0x00186F10, and `--merge mapper.cpp --dry-run` stopped
  with "no verified merge of two or more donors; the seed itself fails under
  every merged flag set: bytes".
- Scan of approved multi-donor TUs: 100 TUs hold a donor with a def (185 donors)
  or an optimize pragma (171 donors) before its last include.

## Repair

A `def` or `body-pp` chunk before the file's last `#include` now stays in place
in the include block, as e633ca36a9 did for declarations. Such a body is emitted
there once and not again in the body section. Nothing after the last include
changes. Test: `PreludeOrderTests.test_pragmas_and_a_body_between_includes_stay_between_them`
fails before the change and passes after it.

## Scoped checks

Donor composed alone under its own flags (`build/scratch_c3/donor_alone.py`,
untracked), rows lost relative to the donor's standalone match:

| TU | donor | before | after |
|---|---|---|---|
| mapper.cpp | mapper.cpp (seed) | lost 0x001854E0, 0x00186F10 | 72/72 kept |
| hlod.cpp | HLodUpdateSubObjectTransforms.cpp | lost 0x0019D640 | kept |
| boxrobj.cpp, shader.cpp, matinfo.cpp | 15 donors | none lost | none lost |
| PartitionSolver.cpp | PartitionSolver_PartitionSolver.cpp | (not measured) | 6/6 kept |
| quat.cpp | quat.cpp (seed) | 17/17 lost | 17/17 lost (other blocker) |
| obbox.cpp | obbox.cpp (seed) | 0x00724610 lost | lost (other blocker) |
| streak.cpp | streak.cpp (seed) | 25/63 lost | 25/63 lost (other blocker) |
| part_ldr.cpp | 3 donors | C2162 compile error | C2162 (other blocker) |

Dry runs (`tu_skeleton.py --merge TU --dry-run --no-claim`):

- mapper.cpp: before, blocked (seed fails: bytes). After, 11 files accepted
  (seed plus 10 donors), 8 rejected on their own view and duplicate-body
  conflicts (TextureMapperSlot8, four GridTextureMapper* duplicate
  `TextureMapperClass` bodies, TextureMapperApply bytes, ResetAllTextureMappers
  `Mesh_View`, TextureMapperFXShaderConvert `rva00187690`).
- W3DTreeBuffer.cpp (control): unchanged, seed plus 1 donor accepted.
- `tools/tests/test_tu_skeleton.py` 56/56 OK; `tools/tests/test_gate_exploits.py` rc=0.

This is a verified tool repair and a demonstrated unblock for mapper.cpp. No
merge has landed and no file count has changed; the merge stays with its
owners.

## Remaining prerequisites

- quat.cpp, obbox.cpp, streak.cpp: the seed loses rows when composed alone even
  with the fix, so it has another compose difference. Not investigated yet.
- part_ldr.cpp: three donors fail with C2162 "expected macro formal parameter"
  in the composed text (a macro split or reordered by compose).
- mapper.cpp rejected donors: the views listed above.
