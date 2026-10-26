# Transport statistics header prerequisite, Sol B5, 2026-10-26

Allocated target: `Code/GameEngine/Source/GameNetwork/Transport.cpp`, family B,
shard 1/2. Queue reports unheld; claims cover Transport class, canonical header,
destination, statistics donor and this handoff. Parent-directory name_lane
planner reviewed and refreshed. No merge, source-path move or routing edit.

## Bounded repair

The canonical Transport header lacks the five existing statistics-method
declarations. Declare their current ledger names, replace the donor's private
Transport body with the canonical include, and use the existing header arrays.
The canonical arrays have signed int elements; explicitly convert to unsigned
before the float conversion, preserving retail's unsigned x87 correction.
No name recovery, field rename, layout change or new data symbol is asserted.

Target access evidence already documented in the donor maps its five averages
to statistics arrays 5, 2, 1, 3 and 0, respectively; skip index remains +0x40e6c.
All five bodies remain 68 bytes each, 340 existing bytes total.

`header_adopt_lane.py accept --class Transport` on
`Code/GameEngine/Source/GameNetwork/TransportRva004D5046.cpp` passes and retires
exactly its one header_queue row. This is a demonstrated header adoption,
not a completed TU consolidation or a downstream Luna landing.

`./build.sh` on that donor and Transport.cpp passes 25/25 rows, six float
literals and 14 imports. `find_declared_unmatched.py` passes both sources.
The donor's before/after receipts compare definitions, unsigned data bindings,
code bindings, undefined names, COMDAT selections and flags: all equal. The
five bodies have no external code references. Code identity reports five rows,
zero new findings (shadow). No code/data identity key is retired.

The staged header dependency walk reaches 42 ledger sources. Temporarily restore
only this repair's two source/header edits to HEAD (preserved in the preparation
backup), build all 42 baseline sources, collect object facts, restore the edits,
and build the same 42 again: both runs pass 490/490 rows, 277 string references,
12 float literals and 96 imports. The before/after consumer observer compares
1,954 code references and 1,371 selected-provider names, every source's external
definitions/undefined names/COMDAT flags, and data binding/definition facts:
all equal, including the 65 existing wrong-binding classifications in this
broad shadow scan. Those unrelated findings are preserved, not retired.
The donor's earlier standalone baseline separately proves its private-to-header
replacement. Final converged data check on donor/seed: two sources, ten
addresses, zero second names or unjudged rows. Class/MS-header checks, CSV,
whitespace checks and refreshed planner currency pass. No maintainer-only link,
smoke, nightly or ownership-record runner was invoked.

## Remaining guarded-composition blockers

The ordinary `tu_skeleton.py --merge .../Transport.cpp --dry-run` refuses
the seed: its census-linked input would acquire unresolved
`?Write@Rva00594C12@@QAEHPBDHKG@Z`. Encrypt/decrypt donors separately fail
because htonl is not declared in the composed environment. The AsciiString init
donor also needs coherent canonical overload declarations and keeps its existing
registered AsciiString destructor identity finding. No source or flag workaround
was applied to any of these blockers. The trial's adopted inputs changed while
it ran, so its output is a blocker lead, not a stable before/after merge receipt.
No accepted merged-row count or link improvement is claimed.

`docs/linking_obstacles.md` is held by another worker; its scope claim was
refused and the file was left untouched. Its owner should incorporate the
provider and declaration blockers above. The attempt log records the guarded
seed refusal and the verified statistics-header adoption separately.

## Other allocated probes and inherited recovery

- AptValueGCAllocator.cpp plans five rows with a Common allocator donor;
  W3DDisplayStringManager.cpp plans 16 rows with two Common donors. These need
  their family A owners; no claim, source edit or merge trial was made.
- dx8fvf.cpp also needs Common/GameLogic donors and mixed-source splits; left
  for coordinated ownership rather than a cross-family repair.
- W3DBufferManager.cpp now contains the earlier ReleaseResources prerequisite.
  Its next index-buffer argument-width/private-view issue remains described in
  sol-b5-buffer-release-prerequisite-20261026.md; no unchanged trial repeated.
- Previously landed Bridge/PropDraw work was recovered and its eight inherited
  file claims released. This is separate from new prerequisite work.

Quaternion normalization repair 15e8bf83b0 remains the other new commit in this
batch: ordinary dry-run acceptance 19 -> 20 existing rows, one exemption removed,
with iterator-emission and BuildMatrix4 SSE prerequisites still outstanding.

## Publication and measurements

The full pending range from merge-base bf442a3f7b plus this staged repair has no
source path changes. Active tools, hooks, workflows, includes, build inputs and
registries need no path-consumer repair; historical EA paths remain unchanged.
File reduction 0; recovered C++ bytes 0; code/data identity debt retired 0;
header queue rows retired 1. Across this batch, one present-unmatched hatch is
also removed by the separate Quaternion repair. Keep changed-source/class and
evidence claims until publication is confirmed; release unused Transport seed
claim when handing off. Ignored receipts and the preparation backup live under
`build/sol-b5-transport-*`.
