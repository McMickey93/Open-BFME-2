# Saved string-record cleanup trial, recovery 2026-10-27

Preparation record: `.git/runner-prepare.json`; retained backup
`refs/runner/preparation/1793102191856419848` at `4c008f07bc`;
retained stash `e548186f597e25fef522f392834121f9a4c3483f`.
Rebased source revision before banking: `3396007bf2`.

The eight preserved commits rebased successfully onto `3ff1e68c73`.
The only conflict was reverse/ms_header_queue.tsv: retain both upstream's
Recorder.cpp entry and the ToppleUpdate.cpp entry produced by the merge.
No commit was skipped. The stash applied with --index without a conflict.
Its index held no additional edits, and its untracked tree was empty.
All three saved edits are reproduced exactly in the adjacent patch; the
stash and preparation backup remain intact. No other tracked, staged or
untracked work was present after restoration.

## Trial and bounded checks

The patch specializes vector<BfmeStringRecord0022074B>::_M_clear in
StringRecordVectorGrowthG7.cpp, LocomotorStoreParse.cpp and
stlport_vector_bfmestringrecord0022074b_pushback.cpp. It calls the existing
LocomotorStore range destroy at 0x00220AEB, then frees the buffer.
The comments identify cleanup owner 0x00220C56, currently rowed as
Rva00220C56's destructor. This existing owner must be reconciled before
claiming a new identity at that address. No new row or pin was added.

On the restored trial, the ordinary three-source build passes all 20
matched function rows and its one data row; string, float and import
checks pass. EH verification reports EXACT 2, with no failures or missing
objects. The declared-body check reports all defined functions matched.
These checks validate the existing rows; they do not establish the cleanup
specializations' complete emission, ownership, source-level record identity
or selected-provider behavior. The copy and parse views still differ.
The earlier ignored paired-after.log is empty, so it supplies no link proof.

Bank the exact saved patch rather than publish unproven extra emissions.
Restore all three Code sources to the recovered committed versions before
publishing. The patch is unfinished evidence, with no matched, linked,
identity-debt or census gain claimed. No source path was moved by banking.

Next check: claim the three sources, compare each emitted cleanup body and
its named relocations against the existing 30-byte owner and its consumers,
then establish current-provider closure and coherent element identity.
Use the retained patch as the starting point; do not infer a new application
name from the byte correspondence. LINK-002 remains the general container
identity prerequisite; this recovery does not clear it.

## Outgoing path-consumer audit

Across origin/master..3396007bf2 the only source-path change is the
ToppleUpdatePoolKey.cpp absorption into ToppleUpdate.cpp. A fresh tracked-tree search of the old full
path, basename and Update-directory consumers found no active consumer to
update. The remaining exact donor references are the provenance comment
and historical census; StructureTopple is distinct. Existing evidence in topple-pool-consolidation-20261027.md and
vegetation-binder-headers-20261027.md records historical references and the
separate StructureToppleUpdatePoolKey.cpp owner. Banking changes no consumer.
The normal pre-push audit supplies its current-input and provider verdict.

## Second recovery, 2026-10-28

The resynced preparation record stopped while replaying the Watchdog commit
onto `b472f3ccfe`. All nine retained commits were continued without a skip or
abort. Both workers' obstacle findings and upstream's newer LINK-112 clearance
were kept; the AIFlank consolidation note received an unnumbered heading to
avoid duplicating upstream's LINK-119 identifier. The AIFlank CRT-header change
was completed over upstream's partial allocator-header adoption. Upstream's
current ToppleUpdate data names and TU approval were preserved, only the
absorbed source was repointed, and already retired data keys stayed retired.
Unrelated header queue entries and baseline retirements were preserved while
removing the two repaired DX8Caps keys.

Applying the retained stash with `git stash apply --index` again restored
exactly the same three files without conflict. Its 48 added lines and the
complete saved patch are identical to the banked patch above. The stash index
has no additional edit and its untracked tree is empty. Only that banked trial
was reversed from Code after accounting for it; no unfinished source is lost
or admitted as progress. The stash and backup ref above remain intact.

At recovered tip `7c60df7bfb`, the five changed C++ sources pass 951/951 function
rows and 18 data rows. `check_csv.py` and whitespace checks pass. The complete
`git push --dry-run origin HEAD:master` hook exits zero: 989/989 functions
across eight affected sources, 20 data rows, nine EXACT EH graphs, and zero
converged-data second names or unjudged rows. Its link batch audit remains
INCONCLUSIVE because index `bf3dd31211` predates the outgoing base and lacks
per-object consumer names. Carry that limitation under LINK-017 into the next
scheduled census; no whole-batch link clearance is claimed.

The fresh whole-batch path audit again finds only ToppleUpdatePoolKey.cpp's
absorption. Remaining old-path mentions are provenance and historical census
or attempt records; StructureToppleUpdatePoolKey.cpp remains a distinct source.
No active tooling consumer needs a change. `/opt/runner/publish --now` reports
`publish: pushed`; the nine commits land as `da83d0f49c` through `05cc366d36`.
The publisher resync reaches `1a79a8b1fa` without changing these five sources.
