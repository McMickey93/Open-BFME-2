# Army unit swapper split cleanup and TU prerequisite

Inspected base: `ac906b4dc688`; date: 2026-10-28; preview index: `41c28839bf`.

The default picker claimed the 0x005FD677..0x005FE1D7 TU-evidence run
(27 served rows, 16 files). `tu_evidence.py --source
Code/GameEngine/Source/Common/Rva005FD677Apt.cpp` emits no placement signal.
`name_lane.py consolidate --under Code/GameEngine/Source/Common/` records
WorldBuilder's StrategicHUDArmyUnitSwapperMovieClip.cpp as a hint, not an
independent BFME 2 anchor. A fresh `tu_map.py --dir` on the served file reports
one code/none row and zero approved TUs. The broad lower/upper bracket and
proposal-only rdata signal do not authorize a move. No TU map, path or row
ownership changes are made. Next placement work needs an independent retail
anchor; do not promote the WorldBuilder path on its own.

Within this scope, the callback/destructor fragment Rva005FD788Apt.cpp retained
unused concat-node types and operator definitions from its earlier constructor
split. Remove that unused block and the unused g_Va0087A290 declaration. The
constructor fragment Rva005FD788Apt_ArmyUnitSwapperMovieClip.cpp still uses its
concat operator; retain its body and remove its stale unmatched marker. The
exact operator spelling is already rowed at 0x00109CFD in Rva005D25F2Dtor.cpp,
as the complete 61-byte relocation twin of the RegistryAsciiPath.cpp owner.
This is existing-placeholder cleanup, not restoration of a lost row.

Verification:

- Before and after `./build.sh` for the two fragments: 47/47 function rows and
  the one data row pass; 13 literals and one empty-string reference verify.
- `find_declared_unmatched.py` passes both changed files after the edit.
- `eh_verify.py`: all six EH graphs EXACT. Compiler label renumbering is
  resolved by the existing parent-EH verifier; no ledger hints are added.
- Object comparisons using link_census.comdat_bodies preserve all 22 and 36
  external COMDAT byte-and-relocation fingerprints, respectively. External
  symbol sets (38 and 70 entries) and object_references graphs are identical.
- `data_check.py`: zero findings. The staged code-identity shadow check reports
  one outside-register divergent TreeHintRef00217D4C constructor. Its complete
  external COMDAT fingerprint is unchanged from the saved pre-edit object;
  this cleanup does not repair or introduce that identity finding.
- `link_check.py --prepare-current` provides strict reusable receipts for both
  changed units. Ordinary previews before and after both report LINKS for
  521 and 1189 authored bytes (1710 total). No census gain is claimed.
- `hatch_counters.py --update` retires one address_global occurrence and two
  present_unmatched occurrences; no hatch grows.
- The outgoing batch audit on the staged tree is INCONCLUSIVE: the index
  predates the base, and affected consumer
  Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp lacks a current
  receipt. Full consumer selection is unverified; carry this scope into the
  next normal census. No maintainer-only measurement was run.

No source paths, pins, code/data ledger rows, shared headers or active tooling
paths change. The remaining used slot-name global and class-view/TU recovery
work remain open. Credit is three retired hatch occurrences only; source-file,
TU-approved, census-linked and image-ownership gains are not claimed.
