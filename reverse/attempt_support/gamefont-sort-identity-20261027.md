# GameFont sort-call identity cleanup, 2026-10-27

Base: `6c951f5a5e`. Source: `Code/GameEngine/Source/GameClient/GUI/GameFont.cpp`.
Related obstacle: LINK-042, with the specialization recipe from LINK-083.

## Target facts

The picker served the registered `bfmeEachQR` (0x002178FD, 46 B) copy-constructor
binding. The current owning identity scan already accepts that binding as a fold
onto `MixFileCreator::FileInfoStruct`'s copy constructor at 0x00217624. It therefore
needs no new source change. Retirement initially refused the whole-source verdict:
the introsort row at 0x00218E09 (141 B) had two additional findings, the opaque
record's `__unguarded_partition` and `partial_sort` instantiations.

The native call operands target 0x00217AB0 (87 B) and 0x00218BD4 (27 B). Those
already have ledger owners: `Rva00217AB0Partition` in
`MixFileCreatorFileInfoStructAssign.cpp`, and `Rva00218BD4Sort` in this TU.
The former takes the sixteen-byte record by value. Its native caller also pushes
an unused comparator word; the typed cdecl cast retains that stack shape.

## Reference facts and change

The explicit specialization retains STLport 4.5.3's `__introsort_loop` control
flow from `vendor/stlport/stl/_algo.c`, binding the two helper calls directly to
those existing owners. The source's existing CRC/Offset/Size/Filename view,
copy-constructor alias and median fold remain. This does not establish a retail
source path or recover the opaque record's original template spelling.

## Validation

- The baseline full gate completed green: 98,276/98,276 function rows and
  2,227/2,227 data rows. Its function phase preceded the source change.
- Final scoped `./build.sh` passed 38/38 rows across GameFont and the partition
  provider, including string, float and import references. GameFont alone is 26/26.
- `allowed_symbols.py --source` reports 63 references: owner 44, fold 12,
  EH 4, alias 3, zero wrong bindings (before: owner 42, wrong 2).
- `repair_queue.py retire identity` accepted the current objects and retired the
  source's single registered key. No key was deleted by hand.
- The old object emitted both opaque helper symbols; the final object emits
  neither. Their two obsolete pins were removed. `pin_consistency.py --check`
  passes, and `hatch_counters.py --update` lowered pin count 15,313 -> 15,311.
- `check_csv.py` and the frozen-file check pass. No ledger function rows moved,
  changed extent or disappeared.

The initial specialization compile used STLport's local `__stl_threshold` macro,
which the header undefines. Spelling its literal value 16 resolved that compile
error; the resulting sort loop matches retail.

Both before and after the change, the index at `bf3dd31211` (2026-10-27 00:39,
retail-truth-4) predicts GameFont 1,758 -> 1,758 B and the partition provider
357 -> 357 B. These are link predictions, not census or ownership receipts.

The BFME 1 freshness check fetched official upstream `a0940f921b5b8d9029fc922b8032abcf4e60d240`.
The reference scope was claimed by another worker, so the pinned
`4fa9d591641a743b86f2320343b7a276585b814b` and freshness timestamp were retained.
