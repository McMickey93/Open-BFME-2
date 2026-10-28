# Subsystem registration code-identity repair

Inspected base `fb38c042b8b40769fdab4df0712d1caf75892808`, 2026-10-28.
The default picker claimed `0x001B5266` and its source lock for
`Code/Libraries/Source/subsystem/SubsystemInterface.cpp`.

## Target facts and repair

The complete 261-byte `SubsystemInterfaceList::initSubsystem` calls the
55-byte push-back body at `0x00539A2E`. Its local
`vector<pair<SubsystemInterface *, void *> >::push_back` copy has that extent,
but `allowed_symbols` reports `wrong/unknown`: its relocations at offsets 19
and 46 name unproven pair-specific `_Construct` and `_M_insert_overflow`
specializations. Retail targets are `0x0060C9D9` and `0x00057C80`.
The latter already belongs to the `vector<BfmeE8>` storage provider in
`WWLib/stlport_vector_e8_allocate_copy.cpp`, which also owns `0x00539A2E`.

Registration now constructs the same typed subsystem/slot pair and calls that
existing provider through its eight-byte storage view. The class layout and
pair fields are unchanged. `BfmeE8` is an existing structural provider name;
this repair asserts no original application element name or donor identity.
No pin, alias, row, shared header or source path changes.

## Verification

- Before and after `./build.sh`: 374/374 function rows exact. The source has
  376 ledger rows, including the two data rows. The frozen-file checks pass.
- `eh_verify.py`: all 181 EH graphs EXACT; no missing objects or baseline cases.
- `class_gate.py`: passes. Strict reusable receipts cover this source and the
  storage provider (378/378 function rows), plus `Common/AreaPolygonBase.cpp`.
- Object comparison: 540 external COMDAT fingerprints become 520. Of the
  retained fingerprints, 519 are unchanged; only `initSubsystem` changes its
  relocation name, while its entire retail extent remains exact. Twenty
  unused pair-container/placement helpers disappear. Exclusive definitions
  and weak bindings are unchanged. Two node-allocator dependencies disappear;
  the owned BfmeE8 push-back dependency is added.
- The identity retirement initially refused missing/stale evidence. Normal
  builds refreshed 66 sources (784/784 rows), then five newly participating
  provider sources (224/224 rows). The final owning-tool command
  `repair_queue.py retire identity Code/Libraries/Source/subsystem/SubsystemInterface.cpp`
  passes: one key retired, zero findings remain. The register was changed only
  by that command.
- Ordinary preview at index `41c28839bf` retains LINKS for the registration
  source's 22,023 authored bytes. This is debt retirement, not a measured
  linked-byte gain.

## Remaining verification limits

The unchanged storage-provider unit's preview reports an unresolved
`vector<BfmeE8>::insert` at `0x0030B9F3`. Its current owner is
`Common/AreaPolygonBase.cpp`, which has a strict receipt but is absent from
that census index; including it in the ordinary preview is refused as
unpreviewable. This broader provider closure awaits the normal census.

The staged outgoing batch audit is INCONCLUSIVE: index `41c28839bf` predates
the inspected base, and affected consumer
`Common/0CreateAHeroManager21FE49.cpp` lacks a current receipt. Carry the
changed registration binding, removed helper copies, storage provider and
affected consumers into the next normal census. Full consumer selection,
runtime behavior and new census-linked bytes are not claimed.
