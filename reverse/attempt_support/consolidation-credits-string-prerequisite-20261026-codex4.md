# Credits string/declaration prerequisite, 2026-10-26

Seat codex4; allocated family A shard 1/2. Target:
`Code/GameEngine/Source/GameClient/Credits.cpp`. Allocation check returned 0;
the GameClient name-lane planner and current-routing merge trial were read.
The planner's original-path hints do not establish a recovered class name.
File claims cover the target, Common/Rva005B72E7Dtor.cpp and this handoff.

## Demonstrated prerequisite

The initial normal `tu_skeleton.py --merge <target> --dry-run` accepted no
donors: the composed seed's global pointer preceded DisplayStringManager's
definition. Both existing extern declarations now introduce the class with an
elaborated type. This preserves the symbol, pointer type and private class views.
That exposed the next compiler error: the destructor donor's private StringBase
copy redefined the canonical template already included by Credits.

The donor now includes the existing bfme2_ascii/unicode_string.h shim and uses
UnicodeString for its two four-byte wide-string members. No layout, virtual
slot, row name, source owner or implementation body was changed. Its existing
107-byte destructor remains exact. Normal dry-run now accepts the seed and
Rva005B72E7Dtor.cpp together, all 35 rows; this is a demonstrated compatible
donor, not a completed merge or subsequent Luna landing.

## Acceptance and scoped provider evidence

- `./build.sh <target> Code/GameEngine/Source/Common/Rva005B72E7Dtor.cpp`:
  35/35 exact before and after; two literal and two float references verified.
  Both files pass `find_declared_unmatched.py` and `class_gate.py`.
- `eh_verify.py` on the pair: six EXACT, zero missing/not-exact/baseline.
  `allowed_symbols.py --source` on the pair: 92 references, zero wrong bindings
  (76 owners, seven aliases, six EH, three folds).
- `data_check.py --converged` on the pair: ten addresses, zero second symbols
  and zero unjudged findings. `git diff --check` passes.
- `./build.sh Code/Libraries/Source/WWVegas/WWLib/unicode_string.cpp`: 14/14
  exact. Separate scoped objects for both consumers and that provider were
  compiled with `build.try_compile_source(..., inventory=True)` outside the
  shared build/match cache; all three have strict current compile receipts.
- Scoped before/after object evidence is saved under build/codex4-credits-*.
  Every surviving code definition, digest, size, exclusivity and reference,
  and every external data definition, is unchanged. The donor stops emitting
  its unused public private-copy StringBase destructor. Its replacement private
  StringBase destructor, UnicodeString destructor and validate copies exactly
  equal existing Credits providers, with the same ANY COMDAT selection 2.
  The two destructor versions are both five-byte twins; validate is one byte.
- `build/codex4-credits-proof.py` checks the current composition against the
  standalone union: 80 code definitions, 19 external data definitions and 42
  unresolved references. All 35 rows retain identical DIR32 data-binding sets
  before, after and in composition. This includes selected COMDAT properties;
  exact function bytes alone are not the provider evidence.
- `build/codex4-credits-provider-proof.py` overlays the same fresh seed and
  UnicodeString provider on both comparisons, replacing only the changed donor.
  All ten donor-defined/referenced symbol selections stay unchanged. Even the
  removed public helper retains another provider. The published index baseline
  is provisional; this is scoped selection evidence, not a fresh census or a
  claim of increased linked bytes.

## Remaining work and batch audit

Rva005B7DC3Box.cpp still fails C2908/C2766: explicit list specializations follow
an existing instantiation. Two mixed donors remain excluded by current routing:
R3ScalarFieldConstructors3.cpp (seven foreign rows) and VslotSmallBodiesG.cpp
(eight foreign rows). Use the supported split lane; no rows were moved here.
The existing MS-header queue item and all counted hatches remain unchanged.
Neither changed source has data/code-identity debt keys to retire.

The outgoing batch also contains the pending OneRingPenalty prerequisite
a5e2a3ab10. Audit of that commit plus these staged changes found no source
moves/deletions, hence no repointed ledger, registry or build-input consumer.
The only added source path is OneRingPenaltyModuleDataView.h, included by its
two checked sources; its header hook already verified all 32 dependent rows.
Active tools, hooks, workflows, includes and registries were searched across
the complete batch. Historical EA paths and the TU map remain untouched.

Accounting: 35 existing matched rows preserved; recovered bytes +0; source
file reduction 0; identity debt retired 0. Leave the compatible destructor
donor for Luna. Keep the three file claims until this commit is published;
the runner may batch it with the pending OneRing prerequisite.
