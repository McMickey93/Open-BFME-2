# RankInfo lookup, string and copy-provider prerequisite

Seat codex, Sol family A shard 0/2, 2026-10-26. Allocated destination:
Code/GameEngine/Source/GameLogic/System/RankInfo.cpp. The runner allocation,
scoped System planner's original-path evidence, alternatives, upstream --plan
and ordinary --merge TU --dry-run were reviewed. Placement comes from current
upstream routing, not the planner's same-name/adjacency hints. The stale TU map
was rebuilt in memory; no map, merge or split is committed here.

The baseline ordinary trial accepted no composition. SkillPoints failed on the
independently declared lookup receiver, and StoreDtor failed on the seed's
private StringBase template. The seed and SkillPoints now share an accessed
receiver prefix through RankInfoLookupView.h. Lookup 0x002000D7 establishes the
override link at +4; selection 0x00200157 establishes fallback +0x14 and the six
side overrides +0x18..30. Neither consumer sizes or constructs this view. These
are target access facts, not a complete recovered RankInfo/base layout. Existing
neutral names are retained; no donor-name inference or identity retirement is
claimed. The seed adopts the registered canonical StringBase header through
its existing public-destructor option.

The final ordinary trial accepts the seed, SkillPoints and StoreDtor:
**8 existing rows / 503 retail bytes**. Newly compatible donors are
RankInfoSkillPoints.cpp (1 row / 195 bytes) and RankInfoStoreDtor.cpp
(2 rows / 153 bytes), **3 rows / 348 existing bytes** in total. Leave these
donors for Luna. This is a demonstrated prerequisite unblock, not a later
confirmed Luna landing or new matched/linked coverage.

Provider verification found and repaired a separate include-environment hazard.
The ordinary trial carries RankInfoParse's bfmealloc include directory even
though that donor remains rejected. Its _algobase changes __copy_ptrs's tag
from const reference to value. An initially byte-exact trial therefore replaced
the existing destructor helper's decorated provider name. The seed now includes
the existing vendored _algobase explicitly before vector, with StoreDtor's
existing out-of-line __copy_trivial setting established first. This preserves
both the const-reference provider and its retail external copy binding under
standalone and composed flags. No shared/vendor/shim header is edited and no
alternate path, replacement implementation or linker alias is introduced.

Verification:

- ./build.sh on seed, SkillPoints and unchanged StoreDtor passes 8/8 functions
  and six string references. Two renumbered funclets remain verified through
  parent EH placement. find_declared_unmatched.py and class_gate.py pass all
  three; eh_verify.py reports EXACT 2 and no missing/non-exact objects.
  Enforced converged data checks three sources, ten addresses, zero second
  names and zero unjudged rows.
- header_adopt_lane.py accept --class StringBase RankInfo.cpp passes. There
  was no matching header queue entry to retire; no queue/register is changed.
- Saved pre-edit versus current standalone COFF comparisons preserve all 54
  existing non-debug sections, bytes, named relocations, COMDAT policies and
  SafeSEH handler identities. Canonical StringBase additionally emits its
  unreferenced one-byte validate<unsigned short> return COMDAT (c3, policy 2,
  no relocations). This is not new matched coverage. All 21 code-reference
  facts and all per-source data reference/definition facts remain identical.
- The final ordinary composed object build/tu_skeleton/8f62cc745366f604.obj
  has exactly the standalone union's 39 external code definitions, including
  identical normalized code/relocations and COMDAT selection policies. There
  are no conflicting, missing, added or changed providers. All seven external
  data definitions retain bytes, relocations and policies. Aliases, unresolved
  bindings after internal resolution, per-source data bindings and union data
  definitions agree exactly. The earlier wrong helper and extra copy-provider
  trials were rejected by this comparison despite their exact row builds.
- link_check.py --prepare-current passes strict receipts for three explicit
  providers / eight rows; --new-variants exits zero. Code identity reports six
  rows and zero new findings in the current shadow mode. An initial
  preparation ran while the trial's temporary inputs were changing and refused
  witnesses; it was rerun after that trial completed. No LINK closure, index
  publication, census or maintainer-only runner is used.
- Scratch prefix build/codex-session8-rankinfo- contains before/after-trial.txt,
  before/after-build.txt, before-objects/, section-proof.json,
  reference-delta.json, data-delta.json, composition-proof.json, header-accept.txt,
  prepare.txt, new-variants.txt, eh.txt and data.txt. The comparisons use the
  supported COFF/identity/data readers, never manual build.compile_source.

Remaining prerequisites are unchanged: Common/Rva0022CA74Slot9.cpp needs an
evidenced compatible Overridable::deleteOverrides declaration; Parse still
fails on its base/store model (C2504 and ranks undeclared). RankInfoCtor remains
mixed with two foreign rows. Do not guess a virtual interface to absorb them.
Its existing divergent vector-assignment identity key and Parse's wrong
push_back key remain in code_identity_baseline.tsv. RankInfo's free:abi
ms-header queue entry survives, as do all data and hatch findings.

Complete pending-batch compatibility audit:

The pending own range also contains 826df4ec9f (FireWeaponWhenDeadBehavior slot)
and 8afe4f0ce0 (ScienceBuilder shared declarations), before any rebase. There
are no source moves, renames, absorptions, deletions or ledger repoints in any
of the three prerequisites. Four new TU-local headers have direct consumers
verified with their affected donors. Combined path/basename/directory searches
across active tools, hooks, workflows, source includes, build inputs, registries
and documentation found no consumer needing a path update; the search receipt
is build/codex-session8-rankinfo-path-consumers.txt. Existing registry references
continue to resolve and historical EA paths/evidence are preserved. Origin can
advance independently; inverse upstream differences in a two-endpoint diff
are distinguished from this seat's commits with git log origin/master..HEAD.
The scoped planner is regenerated after the final trial. Normal hook header,
include, ownership, data, code-identity and byte checks remain enabled.
header_dependents.py --staged selects the two edited direct consumers and
conservatively adds Eva.cpp, ThreadClassLifecycle.cpp and thread.cpp through
macro-include widening; those three do not include the new view header.

No source-file reduction, new C++ coverage, identity debt retirement or census
gain is claimed. The combined three prerequisites demonstrate nine existing
donor rows / 1,055 retail bytes newly accepted by ordinary composition trials.
Keep all pending file claims until publication is confirmed: three FireDead
scopes, nine ScienceBuilder scopes and five RankInfo scopes (seed, SkillPoints,
unchanged StoreDtor, new header and this handoff). Then release those file scopes
and run claims.py release --landed. No downstream Luna landing is yet confirmed.
