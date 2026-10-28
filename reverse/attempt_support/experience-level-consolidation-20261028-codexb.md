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
