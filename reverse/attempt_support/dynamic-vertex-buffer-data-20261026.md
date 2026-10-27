# Dynamic vertex-buffer storage identity and SDK cleanup

Control: `1429c1561086c13a97401526d32fb26fb90a77e1`.
Source: `Code/Libraries/Source/WWVegas/WW3D2/bfmedynamicvertexbuffer.cpp`.

The data picker selected this already matched and census-linked unit. Its ten
registered data findings remain: duplicate definitions and wrong names for five
internal globals. No data debt was retired and no linking or ownership gain is
claimed.

## Storage trials (restored)

The current data ledger assigns these addresses to existing owners:

| RVA | Selected source symbol | Existing owner symbol / unit |
| --- | --- | --- |
| 009F2A00 | `__VertexBufferTotalSize` | `G009F2A00`, `ConstGlobalGetters2.cpp` |
| 009F2A40 | `__VertexBufferCount` | `G009F2A40`, `ConstGlobalGetters2.cpp` |
| 009F2A84 | `__VertexBufferTotalVertices` | `G009F2A84`, `ConstGlobalGetters2.cpp` |
| 009F2A8C | `_bfmeSortingVB` | `bfmeSortingVB`, `DynamicVBAccessClassDeinit.cpp` |
| 009F2A94 | `_bfmeSortingVBOffset` | `BfmeDynamicSortingVertexArrayOffset`, `BoxDynamicVBAccessClassDestructor.cpp` |

These are ledger identities, not newly recovered original spellings. The three
statistics owners are under `Code/GameEngine/Source/Common/`; the pointer and
offset owners are under `Code/Libraries/Source/WWVegas/WW3D2/`.

Replacing all five statics with declarations of those existing symbols changed
five of 46 matched functions: the 187-byte base constructor at 00139350, the
58-byte base destructor at 00139410, both derived destructors and the 275-byte
sorting allocator at 0013A8E0. An offset-only extern trial still changed that
allocator. A pointer-only trial, with a local cast from the existing owner's
`BfmeDynamicVB *` to this unit's sorting view, emitted 316 bytes for the allocator
instead of 275. None was retained in `Code/`.

The changes affect loads/stores around object and reference-count operations.
Loss of the compiler's internal-linkage alias information is the working
explanation, consistent with the earlier allocator recovery documented in
`docs/reconstruction/dynamic-vertex-buffer.md`. The trials do not prove a
correct replacement layout or approve a TU merge. Next work should establish
the retail TU scope and reconcile existing owners while preserving the alias
contract; the mixed `ConstGlobalGetters2.cpp` is not an approved merge donor
merely because it owns these addresses. No alternate name, pin, extra storage
binding or identity-baseline edit was added.

## Verified SDK cleanup

The same file's blocked DirectX migration is repaired by reading the vendored
`d3d9.h` with both SDK include markers, replacing its hand-written device and
vertex-buffer COM prefixes with `IDirect3DDevice9` and
`IDirect3DVertexBuffer9`. Redundant ULONG/HANDLE definitions are removed. The
legacy DX8Wrapper device data declaration retains its existing owner identity.
This SDK is a compatible reconstruction input, not a recovered retail release.

Checks:

- `./build.sh <source>`: all 46 functions, the data row and five floating
  literals pass. The restored control also passed 46/46 before this edit.
- `tools/eh_verify.py <source>`: 14 EXACT exception graphs.
- `tools/dx_migration.py scan <source>`: no stand-in opens; the tool removes this
  source from its queue.
- `tools/data_check.py <source>`: ten findings, all already registered.
- `tools/data_check.py --converged <source>`: ten addresses, no second names or
  unjudged rows.
- `tools/link_check.py <source>`: ordinary preview remains clean at 6,860 bytes
  against census index `5ce093a71a` (2026-10-26 19:02). This is prediction, not a
  new census measurement.
- Read-only COFF comparison of the control object and SDK object: all 63 code
  sections retain their full bytes and relocation targets (local labels compared
  by section/value). Of 90 external symbol records, only two inline return-type
  spellings change: `bfmeGetDynamicDevice` and
  `BfmeDynamicNativeVB::Get_DX8_Vertex_Buffer`. Both now name SDK interfaces;
  their code is identical. Repository searches found no consumers of their old
  custom return types outside this unit.

The failed storage trials and successful SDK migration are separate results.
The existing internal storage bindings and all matched rows are preserved.

## Normal hook identity warning

The normal pre-commit gate passes, but its shadow identity scan reports
`uw_00765c90` calling `??1BfmeDynamicVBRefCount@@UAE@XZ` at retail target
00072892 as `wrong/unknown`. A read-only comparison through
`allowed_symbols.Identity.row_refs` returns exactly the same reference for the
saved control object and the SDK object: offset 4, relocation type 20, the same
symbol, target and classification. This is an existing local destructor
identity, not a new emitted binding or a label-resolution failure. The retail
target already belongs to `RefCountClass::~RefCountClass` in `hlod.cpp`.
Reconcile the local reference-count base with that owner in future class work;
the SDK cleanup adds no pin, alias, identity-register key or verifier change.
