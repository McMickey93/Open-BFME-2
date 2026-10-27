# W3DGhostObject vector prerequisite and consolidation

2026-10-27, codex3. Scope: W3DGhostObject.cpp and the three clean donors
served by next_work.py; all four file scopes claimed. Initial revision e1bc047e55.

## Seed prerequisite

The normal merge initially accepts no donor: the seed's private STLport types
conflict with W5/R3, and the Common copy loop also defines a private vector.
The current in-memory TU map approves 55 rows; eight mixed sources stay intact.
The naming planner supplies donor corroboration, not original BFME 2 path proof.

The 2026-10-26 sol-b5 handoff correctly identifies declaration-only suppression's
MSVC C1001 and the non-retail 53-byte allocate helper. Use the real STLport vector,
include vendored algobase before vector to retain reference-tag signatures, and
specialize allocate/copy with a default-initialized local tag. Defining the body
avoids the declaration-only compiler crash and the value-initialization stores.
The specialization and existing 0x00064432 owner both emit 45 bytes with identical
relocation-aware allowed_symbols digest e88cc41386d2. This is an existing helper
copy, not a second ledger claim or a newly recovered body. Helper identities,
FileInfoStruct layout and casts are retained; placeholder names are not recovered.

./build.sh seed: 4/4 exact; find_declared_unmatched: all definitions matched,
existing two anchor notes unchanged. Ordinary link_check against bf3dd31211
(2026-10-27 00:39, retail-truth-4) retains LINKS, 359 -> 359 bytes. Initial
four-file preview was 4/4 LINKS, 756 bytes. The normal dry run now accepts the
seed plus W5 and R3, seven rows, protecting all four census-linked inputs.
The remaining Common donor needs its private vector declaration reconciled.
No debt, hatch, pin, source path or measured coverage changes in this prerequisite.

BFME 1 official upstream was fetched: checked-out clean e74410b3738a versus
upstream 9116bca34d71, three source-only commits ahead. The reference scope is
held by another worker, so pinned inputs were retained and no freshness success
receipt was written. No maintainer-only runner or GitHub API was invoked.

## Common donor prerequisite

Replace its private 12-byte vector with STLport and declaration-only assignment
specializations. Both native assignment calls retain their original names.
./build.sh donor: 1/1 exact; declared-unmatched clean; ordinary preview retains
LINKS 112 -> 112 B. The object defines only the existing 112-byte copy body
(digest 62dd9c09fcc7), and references only the two existing vector assignments.
No emitted helper/provider, source-path or protected-register growth.
