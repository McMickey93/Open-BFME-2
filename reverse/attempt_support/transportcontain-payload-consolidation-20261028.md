# TransportContain payload parser consolidation, 2026-10-28

Inspected revision: `f8b430a969`. Destination:
`Code/GameEngine/Source/GameLogic/Object/Contain/TransportContain.cpp`.
The default picker claimed the destination and its thirteen remaining donors.

## Declaration prerequisite

The supported merge dry run rejects `Rva00467DE6PayloadParse.cpp` because its
private `_STL::list` declaration conflicts with the destination's STLport
headers (C2953/C2955). The parser now includes `<list>` and shares the
destination's declaration of the separately rowed node allocator. No new pin
or alias is introduced. VS2003 rejects an `extern template` suppression when
composed with the destination's explicit instantiation (C2929), so that trial
was discarded. Including the header alone preserves the callback bytes but
emits a non-retail allocator and an unresolved allocation import; that trial
was also discarded. The allocator declaration prevents those emissions.

This is declaration reconciliation, not recovery of the list's native element
identity. The existing address-derived names and pointer-list cast remain.
The callback's name/count interpretation and +0xA4 access are existing target
evidence; the Zero Hour comparison in its comment is a structural lead, not
proof of a BFME 2 name or source path.

Before the change, `./build.sh` verifies all 31 rows across the destination,
the payload parser and the upgrade parser. After the change, the payload
parser's two rows still match and its EH graph is EXACT. Comparing its saved
before object with the rebuilt object through `link_census.comdat_bodies`
shows all five original external COMDAT bodies and relocations unchanged.
The five newly emitted list/iterator COMDATs, including `push_back`, are each
identical to the destination's existing copies (body and relocation digest).
The allocator remains external and the two-unit link preview stays clean.
`find_declared_unmatched.py` reports all defined functions matched.

The ordinary link preview against measured index `14dc3d2467` (2026-10-28
02:44) reports LINKS for both original units: payload parser 133 -> 133 B,
destination 2,455 -> 2,534 B. The latter comparison reflects the index's
historical byte total, not a new census gain. The earlier getter duplicate
in LINK-031 does not reproduce in this scope. The destination's unreferenced
`Object::clearCondition` shadow diagnostic remains pre-existing.

The parser owns no code-identity, data, header-adoption, MS-header, hatch or
flag-override register entry. The destination's existing debt remains owned
by the destination. No debt retirement or census increase is claimed.

Local receipts: `build/transportcontain-before-build.txt`,
`build/transportcontain-payload-real-list-build.txt`,
`build/transportcontain-real-list-link.txt`, the rejected suppression trial
`build/transportcontain-payload-dry-run.txt`, and saved before objects in
`build/transportcontain-before/`. These scratch files are not progress.

## Applied guarded merge

After publishing the prerequisite, the consolidation planner was regenerated
and `--check build/consolidation` passed. `tu_skeleton --merge` rebuilt TU
assignments in memory and accepted the destination plus the payload parser.
It absorbed both parser rows, kept all 26 destination rows, and deleted the
donor. Only the two existing map source cells were repointed; the stale map
was not regenerated into the commit.

The ordinary build verifies 28/28 rows, including parent-proven renumbered
funclet labels. All five EH graphs are EXACT, the frozen-file check passes,
and CSV integrity passes. The merged object's 648 external COMDATs are
identical to the union of the two before objects: no missing, changed or new
body/relocation digest. The supported merge's provider/consumer guard accepts
the composition; all fourteen original candidate units are census-linked.
The ordinary after preview reports LINKS, own bytes 2,667, against the same
index. This combines the existing 2,534 B destination and 133 B parser; it
does not establish an increase in census-linked bytes.

The shadow data check has zero findings. No parser data or identity key
needed transfer, and no baseline debt is removed. The existing hatch register
is unchanged after the tool's total-keeping update. Header adoption has no
affected queue entry. The owning tool refreshed the MS-header row with
identical content; its original queue position is retained to avoid a
content-free reorder. Its allocator ABI warning remains. No new data name,
pin, fold proof or escape hatch is introduced.

`progress.py` reports SOURCE FILES -1 relative to HEAD and BYTE-MATCHED
100.00%; TU-APPROVED remains 42,695. Temporary compiler-trial sources can
inflate an absolute source count during a run, so the earlier scratch
snapshot's total is not used to claim additional reductions.

## Tooling compatibility audit

Audited `origin/master..HEAD` plus the staged move, with origin observed at
`a6874d8a6a`. The only removed path is
`Code/GameEngine/Source/Common/Rva00467DE6PayloadParse.cpp`, now owned by
`Code/GameEngine/Source/GameLogic/Object/Contain/TransportContain.cpp`.
An all-tracked-files, case-insensitive search for its basename/full path finds
no active tool, hook, workflow, include, configuration or source-registry
consumer. Generic source discovery still sees the destination under Code.
Functions and map source cells resolve to the new owner; no protected
register, active header queue or fold proof names the removed donor.
Remaining mentions are the destination's provenance comment, historical
attempts/handoffs, and measured `reverse/link_status.csv`, which is retained
as measurement history. This handoff also intentionally names the old path.

The outgoing batch audit still needs an index current at the outgoing base
and current affected-consumer receipts to prove batch-wide linking. The next
census must confirm the new owner. No nightly, link cycle or smoke was run.

## Remaining prerequisites

Twelve donors remain rejected and unchanged. The previous handoff's list in
`transportcontain-consolidation-20261027.md` remains applicable except that
the payload parser is now absorbed. The upgrade-parser diagnostic now also
names unavailable `Elem00467DCD` dependencies. The destructor still differs
in bytes; the other rejects remain class/header/view prerequisites. Mixed
sources were not split. The generated funclet at 0x0078AD97 remains owned by
`uw_gen_003.cpp`; the earlier missing destructor-identity blocker was not
worked around or claimed repaired.

Additional local receipts: `build/transportcontain-payload-merge.txt`,
`build/transportcontain-merged-{build,link,data}.txt`,
`build/transportcontain-premerge-providers.json`,
`build/transportcontain-progress-after.txt`, and
`build/transportcontain-path-audit.txt`.
