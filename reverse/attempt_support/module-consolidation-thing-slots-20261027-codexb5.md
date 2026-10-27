# Module constructor consolidation prerequisite

Inspected `9edb20acd6` on 2026-10-27. Claimed Module.cpp and both constructor
donors through `next_work.py --claim`. BFME 1 freshness receipt is dated
2026-10-26 at upstream `4fa9d591641a743b86f2320343b7a276585b814b`.

The current in-memory TU map approves ObjectModule's constructor at 0x00306AA7
and DrawableModule's constructor at 0x00306B19 for
`Code/GameEngine/Source/Common/Thing/Module.cpp`. Each parent is 108 bytes.
ObjectModule also owns its 10-byte handler. The name getter in
SubsystemNameGetters2.cpp remains a mixed donor and was not edited.

The supported planner under `Code/GameEngine/Source/Common/Thing/` flags imported
declarations, unrowed definitions, compiler settings and hatch ownership. The
seed has two matched bitset helpers and fourteen unrowed definitions, so this
is not an empty seed that can simply adopt the donors' private declarations.
No generated TU map was written or staged.

## Target facts and failed boundaries

Both native constructors dispatch through Thing. ObjectModule uses slot +8;
DrawableModule uses slot +0x10. Their existing private views encode exactly
those offsets. Ordinary builds verify all three ledger rows across the donors.

The first merge dry run rejected the private static AsObject/AsDrawable helpers
with C2375 (different linkage from the seed headers). Commit `9edb20acd6`
puts the same null-guarded expressions directly in the constructors and removes
two counted comment tokens that described the BFME 1 reference. Both sources
still preview LINKS: 118 and 108 authored bytes against index `bf3dd31211`
(2026-10-27 00:39, retail-truth-4). No linked-byte gain is claimed.

The next dry run rejects direct access to the seed Thing's protected
asObjectMeth/asDrawableMeth methods (C2248). A local friend-helper trial using
the seed's structure resolves access. Plain inline friends are outlined by the
donor build and fail bytes; __forceinline friends preserve all three donor rows
and the original EH verdicts. This trial was reverted after investigation.

A final stable-input merge dry run with those matching friends rejects BOTH
donors for bytes, accepts none and writes no source/ledger changes. Reading its
COFF objects gives a specific cause:

| Parent | Native and separate donor | Composition using seed headers |
| --- | --- | --- |
| ObjectModule constructor | `ff 50 08` | `ff 50 10` |
| DrawableModule constructor | `ff 50 10` | `ff 50 18` |

The 108-byte parent sections otherwise have the same raw bytes in this trial;
their constructor, throw, literal, vtable and EH relocations retain their names.
The retained local trial objects were `build/tu_skeleton/e0de8d7ee4f65a53.obj`
and `6f555b2bcbf63c79.obj`. These are scratch evidence, not accepted receipts.
An earlier intermediate strategy also reported a selected Module constructor
copy regression; that is an investigation lead, not the final stable verdict.

## Donor fact and remaining prerequisite

The Zero Hour Thing.h reached through BFME 1 defines friend inline AsObject and
AsDrawable wrappers. Its virtual-method ordering places the calls eight bytes
later than these two BFME 2 native constructors. This establishes a shared-view
ABI mismatch; it does not prove that deleting two virtual declarations is safe
for other users of the imported header.

Reconcile the seed's Thing interface against BFME 2 evidence, including all
matched consumers reached by any header change. Preserve the native dispatch
slots, constructor/vtable providers and the two seed bitset rows together. Then
rerun the supported planner, merge dry run and provider/consumer guard. Do not
relax the guard, widen access or replace the two matching donors with a
nonmatching composition.

Both constructors already carry EH baseline debt: bytes_differ in .text$x,
six bytes at 0x00779B71. Original, committed cleanup and matching friend trial
produce identical EH JSON verdicts; no EH key was removed. Declaration checks
are clean. The current outgoing batch has no source path moves, so no tooling
path rewrite is needed. Existing unpublished commits and the preexisting
obstacle-note edit were preserved.
