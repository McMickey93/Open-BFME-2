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

## Applied subset and remaining donor

Normal tu_skeleton.py --merge applied seed/W5/R3: seven rows, two donor files
removed. Its link guard protects all four original census-linked inputs. The
Common donor remains separate: even with real STL declarations, normal trials
report `compile: ` (the final diagnostic filter omits warnings/fatal context).
A diagnostic-only wrapper preserved try_compile_source results unchanged and
captured compiler output: declaration-union candidates contain premature
Rva00063BB2Element uses and malformed nested MixFileCreator view composition
(C2143/C2061, C1004/C1506). Other final candidates report C4164 because the
intrinsic pragma precedes its declaration. Moving that declaration before the
includes did not make the normal merger accept the donor; that trial was
reverted. No checker change, custom merge or unsupported row move was made.
Do not repeat the unchanged normal trial expecting an eight-row merge. A
composition-tool investigation should retain the actual failing candidate and
compiler message before deciding whether any correct composition is refused.

Post-apply ./build.sh destination Common: 8/8 exact. Both declared-unmatched
checks pass with the seed's two original anchor notes retained. Ordinary preview
against the same bf3dd31211 index: destination LINKS 644 B and Common LINKS
112 B; 756 B total equals the original four-file preview. All 35 external code
providers in the merged object have an identical digest/size/linkage tuple in
the premerge union; none added or lost. No new undefined names and no external
data definitions. Shadow and converged data checks have zero findings. No row
in this group carries EH data. The helper specialization remains the existing
45-byte twin, not a new ledger row.

Audit across the entire outgoing batch from its merge base through this merge:
the two library donors are the only deleted source paths. Combined full-path
and basename search over active tools, hooks, workflows, includes, configuration,
registries and docs finds no active consumer requiring migration. Remaining
mentions are merged-source provenance, historical link_status.csv census rows,
attempt history and the distinct surviving AssignTwin file. The merger repoints
three function rows, one allocator fold-proof source and two TU-map source cells;
no map regeneration. All current owners are tracked. Three optimize hatch keys
transfer with totals kept; identity/data/flag registers have no keys for this
scope. The owning merger refreshes header and Microsoft-header queues: no
entries changed. check_csv and git diff --check pass. Selected-provider and
outside-consumer protection are enforced by the normal apply-time link guard;
only the scheduled census can confirm measured figures. No measured gain claimed.

## Rebased publication checks

The commit hook's shadow identity scan reports the R3 assignment at 0x0006447D
calling its copy helper at 0x00063C72 as `wrong unknown` under the merged path.
Scanning the retained premerge R3 object with the same row reproduces that
finding; the provider/relocation comparison above is unchanged. This is a
preexisting donor warning transferred with its source, not a new debt key.

The first rebased push was refused before its batch audit: the inherited
BfmeConv1950 identity retirement could not judge kept copies while 290 ledger
objects were absent. Restore them through the normal ./build.sh: 2,984/2,984
rows over 290 sources pass, including literal, float and import checks. The
normal repair_queue.py verify-removed --range origin/master HEAD then passes.
No verifier, baseline or game source change was needed for that cache repair.
