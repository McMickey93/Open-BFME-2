# ExperienceLevelSystem consolidation prerequisites, 2026-10-28

Inspected base: adc86f51cb. Preview census index: 41c28839bf.
Scope: GameLogic/System/ExperienceLevelSystem.cpp and
ExperienceLevelStoreRva00289BE0.cpp. The naming planner reports WorldBuilder
and BFME1 path leads; these are donor/structural evidence, not a retail path
string. The supported TU planner rebuilds the stale map in memory and approves
150 rows; no regenerated map is committed.

The initial supported dry run accepted no additional donor. Private STL
allocator declarations collide with the real headers; several larger class
views disagree on bases or container representation. The small store helper
also displaced the seed's Rva0028951F declaration during composition.

The prerequisite change unions that class's existing method declarations and
adds the helper declaration to ExperienceLevelStore. The tracker uses the
seed's existing m_currentLevel name at +0x0C and exposes the helper's existing
float m_experience at +0x10 inside the seed's padding. This is a private view
reconciliation, not a claim to recover the complete retail class. Two stale
present-unmatched markers for already-rowed Rva00288BF9Record bodies are
removed; hatch_counters --update lowers that hatch total from 3746 to 3744.

Verification: normal builds match all 32 rows across the two files, two data
rows and their literals/import; all four EH graphs are EXACT. Frozen-file and
CSV checks pass. The seed's 86 external COMDAT digests and helper's one digest
are unchanged, including relocations; external symbol sets are unchanged.
The ordinary same-index preview reports both units LINKS (2042 + 68 authored
bytes); this preserves the scoped preview, not a census gain.

Staged data checks report no findings, including the converged-global check.
Code identity shadow reports two pre-existing wrong bindings to the hashtable
find at 0x00148B27, from FindExperienceLevelList and rva002891DB. Their object
bytes, relocation digests and external names remain unchanged. No identity
register entry is retired. Both sources subsequently pass link_check --prepare-current with strict
reusable receipts and the normal byte gates. The refreshed batch audit remains
INCONCLUSIVE: its index predates the base and affected consumer
Common/0CreateAHeroManager21FE49.cpp lacks a current receipt. External consumer
selection and census confirmation remain pending.

The second supported dry run accepts exactly the seed and the 0x00289BE0
helper: 32 verified rows under the seed's existing flags, with the bounded
census-linked donor guard. Twenty other whole-file donors remain rejected;
twenty mixed sources are outside this merge. The prerequisite changes are
committed separately before applying the supported merge.

## Applied composition

After prerequisite commit ca2e880d96, the supported merge absorbs exactly
ExperienceLevelStoreRva00289BE0.cpp into ExperienceLevelSystem.cpp, removing
one source file. Only the helper's source field moves in functions.csv and
tu_map.csv; the map is not regenerated. No pin or symbol identity changes.
The tool refreshes affected header/MS-header queues; neither has a key for the
removed donor or destination. No code/data identity register key belongs to
the removed helper; protected registers and hatch totals are unchanged by the
merge. The seed's two unchanged shadow identity findings remain open.

The written TU passes 32/32 normal byte matches, two data rows, four EXACT EH
graphs, frozen-file, CSV, class and staged TU-ownership checks. Scoped and
converged data checks have no findings. The before-union and merged object
both expose 87 COMDATs with identical byte-and-relocation digests, 89 external
definitions and 60 unresolved dependencies; no additions, removals or changed
digests occur. The bounded donor link guard passes.

The tooling compatibility audit covers both commits' single removed source
path, its basename and destination. Repository-wide searches include tools,
hooks, workflows, source/header includes, build/configuration files, ledgers,
registers, header queues, fold-proof references and documentation. The only
remaining old-path mentions are the merged source's provenance comment, this
handoff, and the historical census snapshot reverse/link_status.csv. No active
consumer needs a path update; the census snapshot is intentionally retained
until the scheduled measurement. No affected register or queue names the
removed donor.

Final merge audit against outgoing base 161aae0a72: INCONCLUSIVE because the
index predates the base and affected ExperienceTracker.cpp and
W3DDisplayGatherDebugStats.cpp lack current receipts. The destination itself
has a strict reusable receipt and previews LINKS for the combined 2110 authored
bytes. Carry these consumers and moved-provider selection into the next
scheduled census. No measured linked-byte or runtime gain is claimed.
