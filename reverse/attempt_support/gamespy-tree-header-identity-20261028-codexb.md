# GameSpy preference map constructor identities

Inspected BFME 2 `35dfb290bb` on 2026-10-28. The default picker claimed
`GameSpyLoginPreferences` constructor 0x005CB1B3 (119 bytes), and the shared
string-pair tree provider was separately file-claimed.

## Target evidence and repair

The four constructor calls at +37, +49, +61 and +73 all reach the existing
25-byte map constructor at 0x0033C432. The first two maps contain AsciiString
values; the second two contain lists of AsciiString. Their emitted map bodies
have the same instruction bytes and relocation layout as retail, but recursively
reach differing tree-header allocation providers. Equal parent bytes alone did
not certify these folds: the identity scan reported four wrong/unknown calls
under two registered keys.

Retail's map constructor calls the 42-byte tree constructor at 0x001F068F,
which calls the 36-byte header constructor at 0x001F0534. The header constructs
its allocator proxy through 0x0014F3C4, then calls the established static byte
allocator at 0x000307F0 with `(24, 0)` and installs the returned header pointer.
The selected string-pair header copy in
`stlport_rb_tree_hint_asciistring_pair.cpp` instead called a typed node allocator
with count one. GameSpy's list-pair header copy called `__node_alloc::allocate`
with one argument and occupied only 33 bytes. Neither was the retail header.

Two explicit C++ specializations in GameSpy preserve STLport's allocator-proxy
initialization and allocate the native header through the existing BucketAlloc
binding, including its null hint. The shared string-pair provider declares its
constructor specialization without a competing body. Its consumers now select
GameSpy's corrected COMDAT. No compiler flag, layout, function row, shared
header or physical owner changes.

The two existing map constructor pins are removed and re-admitted through
`pin_admission.py --add` at their original address, with a GameSpy `fold-proof`
receipt. Admission proves each complete map/tree/header chain, all relocation
sites and recursively resolved callees against the existing owners. The pin
count is unchanged; no helper pin or alias is added. These are target-derived
allocator corrections, with no external donor recovery claim.

## Verification

- Normal `build.sh` passes all 88 GameSpy rows and all 19 shared-provider rows.
- `find_declared_unmatched.py` passes both sources before and after editing.
- `eh_verify.py` reports 18 EXACT graphs, zero exemptions and no missing objects.
- `pin_consistency.py --symbol` passes for each re-admitted pin; `--check`
  passes globally with zero new or baselined findings.
- The GameSpy identity scan changes from four wrong references to zero:
  258 references now comprise 215 owners, 16 aliases, 14 EH and 13 folds.
- Ordinary paired `link_check.py` previews preserve LINKS for GameSpy (3,715
  authored bytes), the shared provider (1,407 bytes), and UserPreferences
  (11,814 bytes). These are predictions; no new census coverage is claimed.

The initial identity retirement correctly refused without writing: 73 ledger
objects were missing and 13 participating provider objects were not current.
Normal scoped builds refresh those inputs before retrying the owning retirement
command. The refresh passes 1,775 rows across 86 sources and 14 data rows,
plus 602 string references, 73 floating literals and 323 named imports.
`repair_queue.py retire identity Code/GameEngine/Source/Common/GameSpyLoginPreferences.cpp`
then passes and removes exactly its two registered keys, with zero still found.
Only the owning retirement tool edits that register.

This retires constructor identity debt and corrects selected allocation helpers.
It claims no additional matched ranges, census-linked bytes, source-file reduction,
image ownership gain or runtime result. Remaining container-family work under
LINK-002 stays open.
