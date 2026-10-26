# Canonical mask storage in the 0x0050775B constructor

Selected by `tools/next_work.py --tier data` at upstream
`13cfa404dfe65a062e2e5effe030ff826b905adc`. The served duplicate-definition
key and the same file's wrong-name key both refer to retail RVA `0x009FEFA4`
(VA `0x00DFEFA4`). Neither key is a new function recovery.

`ThingIsAnyKindOf.cpp` already owns `BitFlags<116> KINDOFMASK_NONE`.
`Rva003B1101Ctor.cpp` supplies an existing independently verified consumer
pattern: forward-declare `BitFlags`, declare that owner extern, and pass its
address through the witnessed 28-byte fixed-storage view. The selected
constructor now follows that pattern instead of defining a second byte array.
No layout, initializer or new data binding is invented.

## Native verification

Windows run [40353079647](https://github.com/McMickey93/Open-BFME-1/actions/runs/40353079647),
job `experiment (b2)`, immutable control commit
`6dcb9adc800a9951e3651706ee9eb818b2196f4c`:

- `bash build.sh` on the constructor and canonical owner passes before and
  after the change: 7/7 rows, 259 bytes. The constructor's five rows retain
  224 bytes, including its 172-byte parent, handler and three unwind actions.
- The normal verifier independently rebinds the three renumbered compiler
  labels through their verified parent EH graph; no ledger labels are edited.
- `find_declared_unmatched.py` reports every defined function already matched.
- `repair_queue.py retire data Code/GameEngine/Source/Common/Rva00507823Ctor.cpp`
  passes and removes exactly the two selected file keys; no new key is found.
  The committed register is the native tool's output, not a hand deletion.
- The normal source flags and original MSVC 7.1 toolchain are retained.
  BFME 1 build dependency remains the previously validated pinned
  `de077dd5dd8339716a6abe453a1d81dfdf77e651`; this scoped check does not
  qualify a reference-pointer update or a full shared-header build.

Artifact `12664098288` contains both build logs, dependency/object evidence,
the retirement verdict and resulting files. ZIP SHA-256:
`2fd5710afd3649d9852eebc0a2b17440c8d862d4a323019124f21a24fce0feb7`.

Result: two data-identity debt keys retired, no new C++ bytes or census linking
credit claimed. Claims and publication use the ordinary fenced protocol;
the native workflow itself has read-only repository permissions.
