# SpecialDisguiseUpdate shared interface storage

Inspected source revision: `fb85f43469`; ordinary preview index:
`bf3dd31211` (2026-10-27 00:39 UTC, retail-truth-4).

The selected data-identity item had four registered keys in
`SpecialDisguiseUpdateCtor.cpp`. Earlier attempts stopped because
`ModuleUpdateDtors.cpp` supplied only file-static integers for the two
provisional owners. Exporting zero-filled integers would not recover the
native interface storage.

## Target facts and repair

- The constructor at RVA `0x004B0292` installs RVA `0x008562C8` at object
  offset `+0x88` and RVA `0x008562D8` at `+0x0C`. The rowed destructor at
  `0x004B0164` installs both, while the destructor at `0x004AD9B0` also uses
  the latter table.
- RVA `0x008562C8` contains four code pointers (16 bytes), immediately
  followed by the table at `0x008562D8`. That table has 47 code pointers
  (188 bytes), followed by a zero word at `0x00856394` and the next
  registered primary table at `0x00856398`.
- Both old scalar owners are replaced by complete constant pointer arrays,
  externally visible under the same provisional C symbol names
  `_s_dummy62C8` and `_s_dummy62D8`. Every slot uses an existing rowed code
  owner. New matched data rows verify all 204 bytes and every relocation.
  The tables' original class/interface names and the folded slots' original
  method names remain unproven; no rename, donor identity or new code match
  is claimed.
- The constructor references these shared arrays and the existing nine-slot
  `vtbl_00C552A4` owner in `GloriousChargeUpdateBehaviorDtor.cpp`.
  `ModuleUpdateDtors.cpp` also references that existing table instead of its
  local `s_dummy20`. This removes two current out-of-register findings
  from each changed source without adding a second table definition.

## Verification

- `./build.sh` on the constructor, destructor owner and existing nine-slot
  provider: **30/30 function rows**, **3/3 data rows** exact; no string,
  float or import-reference failures.
- `find_declared_unmatched.py` on each changed source: all defined functions
  already matched.
- `data_check.py` on both changed sources: two findings, zero outside the
  register. The constructor has zero findings. The destructor owner's two
  remaining keys concern `s_dummyDFD4` at RVA `0x0084DFD4`; its separate
  provisional owner is still file-static in `Rva00492402Ctor.cpp`, as
  recorded in prior attempts. That source and those keys are unchanged.
- `repair_queue.py retire data .../SpecialDisguiseUpdateCtor.cpp`:
  **PASS**, all four registered constructor keys retired by the owning tool.
- Ordinary `link_check.py` with all three current objects: **3/3 LINKS**,
  preserving **1,005 authored bytes** (85 + 860 + 60) against the index.
  This is the bounded preview scope, not strict executable closure.

No census-linked-byte or image-ownership gain is claimed. Remaining dummy
storage, method/class identity recovery and the sibling ToggleMounted binding
remain separate work. The data-register delta is four retired keys.
