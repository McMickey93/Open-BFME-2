# DataChunk name lookup consolidation

Inspected base: `72d1fadb45`. Reconciliation: `b8d03811a7` on origin
(`39aef419d9` before runner publication). Destination:
`Code/GameEngine/Source/Common/System/DataChunk.cpp`.

## Scope and evidence

The default picker claimed the twelve clean DataChunk source files. All 83
ledger rows across them passed `./build.sh` before composition. The first merge
dry run accepted no donors. The current in-memory TU map approves the name
lookup at RVA `0x003070F1`, 53 bytes, for DataChunk.cpp. Only its existing source
column was repointed in the committed map; the map was not regenerated.

The consolidation planner records WorldBuilder and Zero Hour DataChunk paths
and BFME 1 source leads. These are donor/path evidence, not a newly discovered
retail BFME 2 `__FILE__` assertion. The approved map supplies move permission.
The planner was regenerated after the merge and its snapshot check passed.

The old getName donor declared `Mapping` independently, spelling its three
fields `next`, `name`, and `id`. The seed uses `m_next`, `m_name`, and `m_id`.
Reconciliation reuses the seed's private view; no new name basis is asserted.
Both compiler layouts are 16 bytes with these fields at +4, +8, and +12.
getName never constructs Mapping or uses its virtual slot, so adopting the
seed declaration does not assert new evidence for that slot's existing name.
The donor's three external COMDAT fingerprints and all external names remained
identical. Its frozen-file check and ordinary link preview passed.

`tu_skeleton.py --merge` then accepted the seed and
`DataChunkTableOfContentsGetName.cpp`, passed its bounded link guard, deleted
the donor and repointed getName. SOURCE FILES decreases by one. The tool reports
30 approved rows; the written destination verifies all 32 of its ledger rows,
including the existing funclet rows. No matched coverage was added or lost.

## Verification and outgoing path audit

- `./build.sh DataChunk.cpp`: 32/32 exact, four renumbered funclet labels
  resolved through parent EH data, one empty-string reference and three imports
  verified. Frozen-file, CSV, staged TU-ownership and diff checks pass.
- The merged object has the same 60 distinct external COMDAT names as the union
  of the original two objects. Every digest (bytes and relocations) is present
  in that original union. No external name is added or removed.
- The absorbed donor has no code-identity, data-identity, header, Microsoft-header,
  gate, flag-override or hatch register entry. The seed's three existing hatches
  and Microsoft-header findings remain. The merger refreshed header and
  Microsoft-header queues; the latter only reorders the unchanged seed entry.
  No debt is retired. Data owners and fold proofs require no transfer.
- Audited the local outgoing changes from `72d1fadb45` through the staged merge
  after fetching origin at `126c7dc48f`: only the DataChunk seed and absorbed
  donor change paths. Upstream had separately received the reconciliation;
  its other intervening source moves are not part of this batch.
- Searched the old full path, basename, DataChunk names and parent directory in
  active tools, hooks, workflows, source includes, build/configuration files,
  registries and docs. No active consumer requires an update beyond the
  merger's ledger repoints. Remaining old-path text is the merged provenance
  comment, the October 25 handoff, and historical census/attempt records.
  Fixture symbol names and a CopyProtect test in the same directory are unrelated.
- Ordinary preview against index `14dc3d2467` reports the merged TU LINKS,
  1,110 authored bytes. Before composition the current seed and donor separately
  previewed 1,057 and 53 bytes. The seed's unreferenced BfmeE12 vector-destructor
  relocation diagnostic already existed before this merge. This is preservation,
  not a claimed increase in the census headline.
- Whole-batch audit exits 2, INCONCLUSIVE: the index predates the outgoing base
  and lacks per-object consumer names. External selected-provider coverage is
  unverified; carry this scope to the next normal census. The bounded merge
  guard, exact object fingerprints and ordinary preview do not replace that
  consumer audit. No runtime or image-ownership result is claimed.

## Remaining prerequisites

Ten clean donors were rejected without being changed; eight mixed files stay
outside this merge. Keep repairs separate from the eventual mechanical merges.

- DataChunkInput: class/member-pointer declaration ordering; the view planner
  also reports InputChunk class-key, decrementDataLeft noinline, Mapping virtual
  slot and ChunkInputStream absoluteSeek signedness conflicts.
- ReadNameKey and ReadDict: missing input APIs and differing private views.
- ASCII/Unicode output: missing writer declarations and file-field agreement.
- OutputDestructor and WriteDict: stdio `fwrite` declaration conflict and
  incomplete output API/layout agreement. Output's by-value contents field
  disagrees between a one-byte incomplete view and a full 16-byte view.
- WriteNameKey: output contents/API agreement. The contents view planner also
  refuses an inline constructor colliding with the seed's out-of-line one.
- ID and writeArrayOfBytes donors: incompatible AsciiString header definitions.

The earlier getName attempt recorded a member-renaming refusal. This change
reconciles the donor with the existing seed view and verifies the unchanged
object; it does not establish canonical member names or retire identity debt.

## Publication checks

The normal commit hook also verifies all three parent EH graphs EXACT, zero
data findings, and pin consistency/admission. Its five shadow identity findings
concern the existing BfmeE12 vector swap binding and four helper definitions.
All affected external COMDAT fingerprints are in the unchanged original union;
these remain inherited identity work, with no register retirement claimed.

Publication rebased onto `936ea37ee8`. Conflicts were limited to concurrent
additions in the obstacle register and Microsoft-header queue; both workers'
entries were retained. No DataChunk source or ledger conflict occurred.
