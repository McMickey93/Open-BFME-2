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
| part_ldr.cpp | convert_version, definition_destructor, read_props | C2162 compile error | no row lost (second fix below) |

The quat.cpp, obbox.cpp and streak.cpp seeds lose rows in this measurement only:
all three are in `reverse/flag_overrides.csv`, and the script drops their
managed flags, which the real merge carries.

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

## Second fix: a directive continued onto a blank line

`chunks()` rstrips each directive. When a `#define` ends with a `\`
continuation onto a blank line (`SAFE_DELETE_ARRAY` in
particle_emitter_convert_version.cpp, particle_emitter_definition_destructor.cpp
and particle_emitter_read_props.cpp), the blank line was dropped and the macro
continued onto the next composed line, `#endif`, so the donor failed with C2162
"expected macro formal parameter". The dangling `\` is now dropped with its
blank line, which leaves the same macro. Test:
`DirectiveContinuationTests` fails before the change and passes after it. Files
with this pattern under Code/: the five part_ldr-family files, huffdecode.cpp and
LightSceneO1Inlines.cpp. This is a verified repair with no demonstrated merge
unblock: `--merge part_ldr.cpp --dry-run` is still refused for another reason
("TU path exists and holds rows of another TU (split it first)").

## Remaining prerequisites (real dry runs after both fixes)

- part_ldr.cpp: split the mixed TU file first.
- mapper.cpp: rejected donors' views, listed above.
- quat.cpp: 3 accepted (quat.cpp, bfme2_quaternion_nlerp.cpp, slerp_setup.cpp).
  Rejected: quat_BuildMatrix4.cpp (no baseline match) and QuaternionRandomize.cpp
  (`normalizeForRandomize` is not a member of the canonical Quaternion).
- streak.cpp: blocked. StreakLineGetTexture.cpp's flag override
  `-O2 -G7 -arch:SSE` differs from the carried `-arch:SSE -G7`.
  StreakLineDestructor.cpp fails with C2908 (an explicit `SimpleVecClass<T>`
  dtor specialization after instantiation). StreakLineSetPoints.cpp fails with
  C2995 (`SimpleDynVecClass<T>::Shrink` redefined).
- obbox.cpp: OBBoxTransformO1.cpp has no baseline match.
