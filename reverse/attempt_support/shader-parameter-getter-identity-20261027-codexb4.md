# Shader parameter getter lifetime and identity

Inspected `e0a165efdf` on 2026-10-27, under the identity picker's claims for
`0x001518D1` and `Code/GameEngine/Source/Common/Rva001518D1Get.cpp`, plus a
file claim for `Code/Libraries/Source/WWVegas/WW3D2/fxshadersetup.cpp`.

## Target evidence and repair

The 68-byte getter returns the vector at link offset `+0x0C`, or a guarded
function-local empty value. Its atexit argument at offset `+0x33` is native
callback `0x007B71AA`. That complete 10-byte callback loads the static at
RVA `0x009F6F10` and tail-jumps to `0x0007C632`. The existing row at that
address is the five-byte wrapper around the 63-byte
`vector<Rva0007BB16Record>` destructor at `0x0007C5D5`. Its record destructor
and range destroy use a 36-byte stride, with strings at offsets zero and eight.
These are target facts and existing row identities, not donor name evidence.

The old getter instead declared `vector<BfmeE16>` (16-byte elements), whose
destructor is rowed at `0x0007FAB3`. Its emitted local `_$E2` therefore could
not reproduce the native callback. The getter now uses the already rowed
`Rva00082EB8` parameter-vector wrapper. Its destructor is declaration-only
here and resolves to the existing verified alias row at `0x0007C632` in
`Rva00111DB6PostFXLookupTable.cpp`. No pin, alias row or separate storage was
added. The existing `Link`/`Mid` projection and guarded static lifetime remain.

The sole caller's declaration now returns the same wrapper pointer, removing
its former vector-element reinterpretation. The getter retains its existing
address-derived class and method identifiers; only its return-type ABI spelling
changes. The old spelling is tombstoned, and no canonical game name is claimed.

## Checks and remaining debt

`./build.sh` passes all **51/51** existing rows in the two changed units,
including 27 funclets recovered through their parents after label renumbering.
Both `find_declared_unmatched.py` checks are clean. The getter's code-identity
references now classify as:

- empty vector-base constructor `0x00211E58`: `fold`;
- local atexit callback `0x007B71AA`: `fold/static`;
- atexit registration `0x006291F8`: `owner`.

The callback certification includes its complete extent and resolved code and
local-data relocations. The caller has a separate `wrong/extent` finding in
`$L8585`: its vector destructor reference targets wrapper `0x0007C632`.
Rebuilding and scanning the original caller while this repair was stashed
reproduced that exact finding. It is not introduced or repaired here.

`repair_queue.py retire identity` refuses this repair before scanning because
`coverage_problems` compares row *names* with HEAD: it calls the corrected ABI
spelling a lost row, despite the same source, RVA, 68-byte extent and verified
caller. This is logged as `false-reject repair_queue coverage_problems`.
The register remains unchanged; no retirement, baseline transfer, check edit
or bypass is claimed. A tooling follow-up needs to judge proven signature
replacements without letting a genuinely lost row hide findings.

The initial retirement check also required four missing ledger objects. Normal
`./build.sh` restored those receipts and passed **86/86** rows before the
remaining coverage refusal was investigated.

An ordinary preview against index `bf3dd31211` (2026-10-27 00:39) reports both
changed units and the current `BfmeDX8ThreadLock.cpp` provider **3/3 LINKS**
(68, 2,869 and 247 authored bytes). Without the current thread provider, the
caller sees the historical selected-copy obstacle already recorded in
LINK-106. This confirms that existing repair, not a census increase. The
shared obstacle-register file is claimed by another worker, so this pass
records its additional caller evidence here without editing their scope.

`check_csv.py`, `pin_consistency.py --check` and normal commit hooks provide
the final integrity checks. No source paths move and no new matched coverage,
census gain, image ownership receipt or formal debt retirement is claimed.
