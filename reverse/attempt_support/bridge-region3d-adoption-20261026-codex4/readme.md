Recovery reconciliation (2026-10-27): upstream commit `2a5ee5a0db` already identifies the AddBridge records as `Coord3D` and the bridge matrix rows as `Vector4`. Those upstream names and layouts are preserved; the opaque AddBridge replacement in the original evidence below is superseded. The canonical Region3D includes and three accepted header-debt retirements remain. Current byte verification is required after the rebase.

# Bridge Region3D header debt cleanup

Inspected BFME 2 `fff0ff229a07ae9eca32f65a7948a427fd967b2f`, 2026-10-26.
The picker claimed `class:Region3D`. This batch retires three header queue rows;
it does not claim a new match, native name recovery or linked-byte gain.

## Target evidence and existing owners

- `BridgeBehaviorHandleObjectsOnBridgeOnDie.cpp` and
  `W3DBridgeBufferAddBridge.cpp` carried a 12-byte private `Region3D` at
  `Rva0027C36A + 0x6c`, four elements through `+0x9c`. Native constructor
  `0x0027C36A` passes stride 12/count 4 to the iterator, with callback
  `0x0047A6A9`. `Rva0027C36ACtor.cpp` already owns that callback as
  `Rva0027C36ATwelve`, a neutral opaque type. The independently recovered
  assignment in `Rva0027C36AAssign.cpp` also has four 12-byte records there.
  These are not the canonical 24-byte region. Both consumers now use the
  existing opaque type; its real application identity remains unknown.
- `W3DBridgeCtor.cpp` passes stride 16/count 3 for matrix rows at `+0x3c`,
  `+0x80` and `+0xbc`, again using `0x0047A6A9`. The existing ledger owns
  `Vector4::Vector4()` there in `StreakRendererSetTextureBFME1.cpp`, with
  separate Matrix4 callback evidence. The Zero Hour W3DBridge/Matrix3D
  layouts cited in the source identify these particular matrix rows as
  Vector4. The constructor now declares that actual provider instead of
  pretending its 16-byte rows are Region3D. No new callback row or pin.

All three files now include canonical `Lib/Region3D.h` without defining a
private Region3D. BridgeBehavior retains its existing guarded
`Coord3DDerivedView.h`; including Region3D after it compiles without the
historical duplicate Coord3D definition. No shared header was changed.

## Verification

- Normal `./build.sh` for all three units: **9/9 matched**, before and after.
  Changed compiler-local funclet labels are independently rebound by the
  existing verified parent EH graph; no ledger labels were edited.
- `find_declared_unmatched.py` passes separately for all three sources.
- `eh_verify.py` reports **3 EXACT**, zero failures and zero baseline entries.
- `header_adopt_lane.py accept --class Region3D` passes each source and
  retires exactly three rows through the owning tool.
- Published index fetch retains `5ce093a71a`, 2026-10-26 19:02.
  Ordinary `link_check.py` before/after: **3/3 LINKS, 1,014 -> 1,014 authored
  bytes**, individually 448, 305 and 261. This is bounded ordinary-preview
  preservation, not strict closure or a new census.

Exact commands are the standard tools above with the three source paths;
raw outputs are adjacent. No maintainer-only measurement was run.

## Remaining class queue

Four Region3D rows remain untouched. `Rva00540E82Init.cpp` still uses a
six-word external-copy ABI carrier; replacing it with visible inline
Region3D copy code requires reconciling the rowed camera-track caller.
`Rva000747E5Method.cpp` uses a different 16-byte element whose original
identity is not established by size or the folded empty callback.
`W3DViewGetAxisAlignedViewRegion.cpp` retains its separate Coord3D lifetime
view and region data aggregate. `WWMath/region.cpp` retains the documented
Coord3D streamer class-key/provider prerequisite (LINK-018). These leads
are not fresh failed trials, and this batch does not clear those scopes.
