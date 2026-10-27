# Vector insert-overflow family: bind existing owners

Base: `869445d043c3ef5dfae47e967edfd41e58a7f2f2`.
Source: `Code/Libraries/Source/WWVegas/WWLib/StlportVectorInsertOverflowFamily.cpp`.
Claims: the source scope and the served row at `0x001DF21C`.

The served clear-binding key was already repaired by an earlier forwarding
specialization. The whole-source check still found 19 wrong bindings in 18
rows. Current retail targets and existing rowed owners, rather than an apparent
missing body, determine this repair. The source's previous forwarding pattern
is extended to three placement copies, fifteen clear workers and one range
destroyer. No function rows, extents, names or pins change.

`bindings.tsv` records each caller RVA and relocation offset, unchanged native
target, former symbol and existing owner symbol. All 19 changed references
become `owner`. The complete scan retains 289 references: owners increase from
122 to 141, folds remain 147, the EH reference remains one, and wrong bindings
fall from 19 to zero. This establishes call ownership and the existing target
ABI; it does not recover the opaque elements' application identities or claim
that their footprint views are canonical layouts.

The clear owner at `0x0015373C` uses `vector<struct Rva005F8F96>`. Correcting
the local destructor-only declaration from `class` to `struct` preserves its
destructor symbol while producing that exact vector symbol. CameraMarker and
the other newly referenced vector elements are forward declarations only.
The range worker at `0x00214B09` uses the current `Rva00214ADC` owner; the
disproved historical two-string interpretation is not restored.

## Verification

- `find_declared_unmatched.py` passes before and after the source change.
- Normal `./build.sh` verifies all 55 rows in this file after the change,
  including strings, floats and imports. The ledger extents total 8,482 bytes.
- The full build begun before the patch completes with every check green:
  98,276 function rows and 2,227 data rows pass, along with references, pins,
  source claims, the module registry and the no-op patch. Its function phase
  checked the pre-edit source; the subsequent 55-row builds verify this repair.
- `allowed_symbols.py --source` reports zero wrong bindings after the change.
- The commit hook separately reports three divergent allocator COMDAT
  definitions in shadow mode. A controlled normal build of the saved pre-edit
  source reports the same three plus a fourth deallocation-helper finding;
  restoring and rebuilding the repaired source again passes 55/55 rows. These
  inherited definition findings are not cleared by the caller-binding repair.
- `repair_queue.py retire identity` passes and removes all 35 obsolete keys
  from `reverse/code_identity_baseline.tsv`, with zero still found. Initial
  attempts refused missing cached objects and changed finding classifications;
  no register was edited by hand. The normal full build refreshed the objects.
- Before and after ordinary `link_check.py` previews both link this source's
  8,480 authored nonpadding bytes, using census index `bf3dd31211` from
  2026-10-27 00:39 UTC. This repair claims no linked-byte gain, image ownership
  receipt, complete-image link or runtime result.

Ignored logs are `build/codex3-vector-build-after.log`,
`build/codex3-vector-identity-{before,after}.txt`,
`build/codex3-vector-retire-{current,after}.txt` and
`build/codex3-vector-link-{before,after}.txt`.
The original-source comparison is recorded in
`build/codex3-vector-original-{compare-build.log,definitions.txt}`; the final
restored-source build is `build/codex3-vector-restored-build.log`.
The full build log is `build/codex3-reference-before.log`.

## Reference freshness

Official BFME 1 master was fetched and compared with the clean verified
checkout `4fa9d591641a743b86f2320343b7a276585b814b`. Upstream had advanced to
`a0940f921b5b8d9029fc922b8032abcf4e60d240`. The reference scope claim was
refused because another worker (`yasinschroeder-codex`) owns it. The verified
pointer is retained and the success timestamp is not advanced. This work uses
retail and existing BFME 2 owner declarations, with no donor recovery claim.
