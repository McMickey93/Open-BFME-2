# Vector range-erase identity retirement

Inspected BFME 2 `f643d446a00817810dfb4c29ea62bb06c4b84a73`.
Claim: `file:Code/Libraries/Source/WWVegas/WWLib/StlportVectorEraseRangeFamily.cpp`.
Model: gpt-6.1-sol. This is identity cleanup of existing matched coverage.

## Target evidence and retained repair

The 24-byte `_Destroy<TreeHintRef00217D4C *>` at 0x005F97BC calls
0x004F72ED at body offset 15, pushing the two range pointers and an empty
tag reference. The 27-byte callee already belongs to
`Rva004F72EDDestroy(void *, void *)` in
`Code/GameEngine/Source/Common/Rva004F72EDDestroy.cpp`. Its native loop
consumes the two pointers and advances by four; it does not consume the
third stack argument. The typed `__destroy_aux` name previously used by
the forwarder is not that owner.

Call the existing owner through a cdecl function pointer retaining the
native third argument. No pin, alias, new owner name, layout claim or row
move is required. The whole 24-byte caller and its relocation remain exact.
The identity scan changes from 17 owner / 3 wrong references to 18 owner /
2 wrong references, with the same 29 total references. Its new direct
reference at offset 15 is classified `owner` for 0x004F72ED.

The source register originally held 24 keys. Twenty-one refer to callers
already moved out of this source: 19 keys now name rows in
StlportVectorEraseRangeDeferred.cpp, one in Rva002B6066Erase.cpp and one
in Rva00538E22Ctor.cpp. The history and original provider exclusions are
recorded in vector-erase-isolation-link-20261024.md and
vector-erase-providers-20261024/readme.md. This pass does not edit those
destinations or claim that their identity debt is resolved.

After normal verification refreshed the stale CaveSystem.cpp provider,
`repair_queue.py retire identity` accepted the current objects and removed
22 source keys: the 21 stale keys and the repaired destroy binding. The
two remaining source keys are preserved. No register was edited by hand.

## Rejected copy-binding trials and next step

The remaining 51-byte erase bodies are at 0x0007A7AA and 0x003F6975.
They call 0x0007A401 and 0x003F6619, whose existing owners are respectively
`copy<const NarrowString *, NarrowString *>` in stlport_copy_narrow_string.cpp
and the `rva003F6619Copy` object symbol in VectorRangeEraseRva003F6975.cpp.
Both callers still use differently spelled `__copy_ptrs` bindings.

Tried inline-only explicit `__copy_ptrs` specializations forwarding to
those owners, preserving the fourth cdecl argument. Both trials introduced
a local tag slot and `xor`/`stosb` initialization instead of native
`lea [ebp+0Bh]`, breaking the callers' bytes. Both trials were reverted;
their blocked verdicts were recorded through re_log.py. The source's
existing comment already explains why the visible original helper body
lets VC7.1 eliminate this initialization. Reconcile that visible-body
optimization and the owner signatures together before retrying; do not
repeat declaration-only or the same inline-forwarding trials unchanged.
No application record equivalence or donor identity is established here.

## Verification and limits

- `./build.sh` passes 14/14 rows in the edited source and 5/5 rows across
  Rva004F72EDDestroy.cpp, stlport_copy_narrow_string.cpp and
  VectorRangeEraseRva003F6975.cpp. CaveSystem.cpp refresh passes 8/8 rows.
- `find_declared_unmatched.py`: all definitions already matched.
- `eh_verify.py`: one EXACT graph, zero baseline entries or missing objects.
- The owning retirement tool passes: 22 keys retired, two still found.
- Ordinary preview against index `bf3dd31211` (2026-10-27 00:39,
  retail-truth-4): edited source 614 -> 614 authored bytes; all four
  repair/provider units LINKS, 800 -> 800 bytes together.

Scratch diagnostics: build/erase-family-identity-before.log,
build/erase-family-identity-after.log, build/erase-family-link-before.log
and build/erase-family-link-after.log. Source and provider byte verification
support the cleanup; no new census-linked bytes, ownership receipt, strict
closure, runtime test or application-name recovery is claimed.
