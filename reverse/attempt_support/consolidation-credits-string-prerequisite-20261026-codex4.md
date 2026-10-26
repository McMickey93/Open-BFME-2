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

## Follow-up: canonical list declaration (separate prerequisite commit)

After 37e6d07948, the remaining non-mixed donor Rva005B7DC3Box.cpp was claimed
and investigated. Its full class specialization for list<int> was incompatible
with Credits' existing instantiation. It now includes STLport's canonical list
and declares only the already rowed push_back specialization. Its three external
call symbols remain unchanged: scalar operator new, Rva0040C1F0's constructor,
and list<int>::push_back at 0x0005548F. No replacement alias or pin was added.

The initial canonical include exposed duplicate placement-new declarations;
the donor now uses the standard declaration. Its initial -Oy- build emitted an
eight-byte placement helper that differed from Credits' five-byte provider.
Removing that unnecessary flag preserves all 54 bytes of Run and emits the
same five-byte ANY COMDAT already present in Credits. The donor now uses the
canonical /EHsc /MD STLport environment. Its constructor declaration takes the
existing seed's throw() contract; the verified constructor at 0x005B72BE only
initializes scalar members. This avoids newly introducing EH machinery.

Composition next exposed the seed's opaque constructor view. Both call views
now expose the proven first int followed by 0x24 bytes, preserving total size
0x28; the actual constructor's stores and Run's first-word assignment establish
this prefix. The seed's unused box member view now uses the same canonical
one-word list<int> at +0x0C. No field offset or body changed. The original seed
and constructor/dtor naming remain unaltered.

Normal merge dry-run now accepts seed, destructor and box donors, **36 rows,
zero rejected donors**. The two mixed donors remain excluded. This supersedes
the C2908/C2766 blocker above; no merge was applied, so leave these compatible
donors for Luna and do not count a later landing yet.

Follow-up checks:

- `./build.sh <target> Common/Rva005B7DC3Box.cpp
  Code/Libraries/Source/WWVegas/WWLib/stlport_list_int_o1.cpp` (full Common path
  in the actual command): 51/51 exact, including the 19-row list provider.
- Frozen-file and class gates pass on both edited files. EH: five EXACT,
  zero missing/not-exact/baseline. Converged data: ten addresses, zero second
  names/unjudged. Allowed-symbol check on all three composition inputs:
  95 references, 79 owners, seven aliases, six EH, three folds, zero wrong.
- `build/codex4-credits-box-proof.py`: every existing seed/box code and external
  data fact, COMDAT selection and undefined reference survives. The only new
  box definition is the exact existing five-byte placement-new provider twin.
  The composed object d10b1d91426e9229.obj equals the standalone union: 81 code
  definitions, 19 external data definitions, 42 unresolved references. All 36
  row DIR32 binding sets agree before/after and in composition.
- Five separate fresh scoped objects (all three inputs, UnicodeString and
  list<int> providers) pass strict input receipts outside build/match.
  `build/codex4-credits-box-provider-proof.py` finds all five defined/referenced
  box symbol selections unchanged in the fresh scoped overlay. The saved
  census baseline remains provisional; no linked coverage is claimed.

The existing box MS-header queue item still describes the old hand-written
operator-new conflict. It was not hand-edited or counted as retired debt.
Neither edited file has data/code-identity debt keys. No baseline or TU-map
changes were made. The complete pending batch (a5e2a3ab10, 37e6d07948 and this
prerequisite) was re-audited across tools/hooks/workflows/includes/build inputs
and registries: still no moves or deletions and no newly invalid path consumer.
The only new source path remains OneRingPenaltyModuleDataView.h, with its two
verified includes. Historical EA paths remain unchanged.

Follow-up accounting: compatible composition 35 -> 36 rows; recovered bytes
+0; source reduction 0; identity debt retired 0. The additional box file claim
must also remain held until publication is confirmed.
