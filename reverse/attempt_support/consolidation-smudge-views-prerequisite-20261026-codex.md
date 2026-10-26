# Smudge manager declaration prerequisite

Seat codex, Sol family A shard 0/2, 2026-10-26. Allocated destination:
Code/GameEngine/Source/GameClient/System/Smudge.cpp. Reviewed the runner queue,
scoped GameClient/System planner's original-path evidence and alternatives,
current upstream --plan and ordinary --merge TU --dry-run. Current routing
rebuilt the stale TU map in memory. No merge, split or map update is committed.

The baseline ordinary trial accepted seed, ManagerReset and AddSmudgeSet:
6 existing rows / 275 retail bytes. ManagerCtor failed C2039 because its private
manager declaration omitted removeSmudgeSet; other class choices also produced
SmudgeManager::SmudgeSet parse errors. Four compatible fragments now include
one TU-local manager declaration in SmudgeViews.h. Its existing virtual slots
and constructor's hardware enum are retained. Target constructor/member accesses
place status at +4, 12-byte used/free lists at +8/+0x14 and count at +0x20.
No additional virtual method, donor layout/name inference or identity retirement
is introduced. The list templates and SmudgeSet views remain separate pending
their own evidence-backed reconciliation.

The final ordinary trial accepts seed, ManagerCtor, SetReset, ManagerReset and
AddSmudgeSet: **8 existing rows / 350 retail bytes**. Newly accepted donors are
SmudgeManagerCtor.cpp (40 bytes) and SmudgeSetReset.cpp (35 bytes): **2 rows /
75 existing bytes**. Leave these compatible donors for Luna. This demonstrates
an unblock, not a confirmed later Luna landing or new matched/linked coverage.

Verification:

- Before editing, find_declared_unmatched.py passed all eight affected/evidence
  sources and ./build.sh passed 34/34 rows. The four edited sources pass 7/7;
  with unchanged SetReset the accepted composition preserves 8/8 rows.
  Post-edit declared-unmatched and canonical class gates pass. Converged data
  check covers five sources / ten addresses, zero second names or unjudged rows.
  Staged code identity checks seven rows, zero new findings in shadow mode.
- Saved pre-edit/current standalone COFF comparisons preserve every non-debug
  section, byte, named relocation, COMDAT policy and SafeSEH handler identity
  across all five accepted sources (33 sections). All 13 code-reference facts
  and per-source data reference/definition facts remain identical.
- Composed object build/tu_skeleton/cedd4661606a70d4.obj preserves the standalone
  union's 22 external code definitions and all four external data definitions,
  bytes, relocations, policies, aliases and data bindings. SetReset additionally
  instantiates Add_Head<Smudge> and Insert_Before<Smudge>. Both extra providers
  exactly equal the byte-verified SmudgeListAddHead.cpp owner's normalized code,
  relocations and policy 2. The former external Add_Head call now resolves to
  this identical provider; no other external binding changes. The resulting
  24 providers, selection policies and unresolved references agree with that
  independently verified expected set. This comparison explicitly checks the
  changed template binding rather than treating matching rows as sufficient.
- Strict link_check.py --prepare-current uses the five explicit providers;
  census/index/status are unchanged. Preparation is performed after temporary
  composition/planner inputs settle; overlapping preparations that refused
  changed inputs are not accepted evidence. Normal hooks remain enabled.
- Scratch prefix build/codex-session9-smudge- contains before/after trials,
  before build and objects, standalone section/reference/data comparisons,
  composition-proof.py/json, strict preparation, identity/data checks and the
  complete pending-batch path audit. Comparisons use supported COFF, code
  identity and data readers; no hand compilation through build.compile_source.

Remaining prerequisites: Smudge_SmudgeSet_addSmudgeToSet.cpp still conflicts with
its real/shim DLListClass and DLNodeClass include environment (C2504/C2953).
ManagerDtor still models slot zero as deleteInstance while the seed models a
virtual destructor (C2039). Neither is fixed by inventing a virtual method.
Three mixed donors stay behind: RvaDeletingDtorBatch04, SmudgeListAddHead and
SmudgeRemoveSmudgeFromSet. SetReset and ManagerDtor's public/private static-list
name findings remain in data_check_baseline.txt; ManagerDtor's existing alias
and hatch count remain. A future merge must carry SetReset's key as printed by
the tool, then retire it only through the data register's verified path.
No header, identity or data debt is silently dropped by this prerequisite.

Pending-batch tooling audit covers the three inherited FireDead, ScienceBuilder
and RankInfo prerequisites plus this staged change. There are no source moves,
renames, deletions, ledger repoints or protected-register changes in this own
range. Combined new-header path/basename searches across tools, hooks, workflows,
source includes, build inputs, registries and documentation find only the direct
verified consumers. Existing source paths and historical EA evidence remain
valid. Concurrent upstream inverse differences in a two-endpoint diff are not
this seat's outgoing changes; the audit also enumerates own commits and index.
The scoped planner is regenerated after editing and checked for freshness.

No file reduction, new C++ bytes, debt retirement or census gain is claimed.
Keep file claims until publication is confirmed. This task holds eight source
scopes, SmudgeViews.h and this handoff; the inherited batch additionally holds
17 scopes recorded in its handoffs and build/codex-session8-pending-claims.txt.
After publication release scopes and run claims.py release --landed.


## Publication and static-list identity follow-up

The four prerequisite commits landed together at 99aec78239 (Smudge),
af217f51ad (RankInfo), c7c16d7aa3 (ScienceBuilder) and 108878443c (FireDead).
The push gate passed 71 rows across 15 sources, two data rows and eight EXACT
EH graphs. Its mandatory link_batch_audit.py found the index at d1f046749a,
older than outgoing base 503766b364, and three source objects without current
receipts (first Eva.cpp). Its selected-provider/lost-byte result is inconclusive;
carry this exact cohort to the next normal census. The bounded standalone and
composition proofs above are separate evidence, not a census replacement.
LINK-017 covers the stale-index/receipt cause. An attempted file claim for
updating docs/linking_obstacles.md was refused because another worker holds it;
that register was left untouched. Its owner can carry this audit receipt forward.
Published prerequisite file claims were released; only the current identity
follow-up's SetReset, ManagerDtor and this handoff scopes remain held.

The follow-up makes both consumers declare m_freeSmudgeList private, matching
its current defining owner SmudgeRemoveSmudgeFromSet.cpp and data_ledger.csv's
single primary symbol at RVA 0x009BCBF4. SmudgeManager is granted friend access
in its destructor view; no ABI/layout or virtual-interface change follows from
that source access. ManagerDtor's now-unneeded public-to-private linker alias
is removed. This directly fixes the relevant data prerequisite rather than
counting a source move as identity cleanup.

./build.sh SetReset.cpp ManagerDtor.cpp passes all four rows;
find_declared_unmatched.py passes both, data_check.py --enforce reports zero
findings, converged enforcement reports zero second names/unjudged rows, and
ManagerDtor has one EXACT EH graph. Saved pre-edit/current COFF comparison
preserves all 15 non-debug sections, bytes, COMDAT policies and SafeSEH handlers
after explicitly normalizing only the public static symbol to its existing
private owner and removing exactly its linker directive. No other binding or
directive changes. repair_queue.py retire data SOURCE independently accepts
and removes each of the two keys. hatch_counters.py --update verifies removal
of the one alias hatch; only that tool-generated deletion is retained, with
unrelated preexisting shrink findings restored verbatim from HEAD.

This retires two data keys and one alias hatch, separately from consolidation
or code-identity debt. It does not repair ManagerDtor's remaining deleteInstance
interface or add recovered C++ bytes. Scratch receipts use
build/codex-session9-smudge-data-; the final composition and publication status
are recorded below after verification.

Final follow-up ordinary trial retains the same five accepted sources and all
eight rows / 350 existing bytes. Composition 7b5f2edddeea4ad7.obj preserves the
24 independently verified expected providers, their policies, four data
symbols and all external bindings after internal resolution. The static data
reference now uses its primary private name in both standalone and composed
objects. ManagerDtor still needs a coherent SmudgeSet interface; the selected
private view now exposes missing reset/member declarations rather than resolving
that underlying destructor-model mismatch. The include conflict remains.
No further unchanged trial is needed. Staged code identity checks four rows
and zero new findings. The final planner is regenerated and freshness passes.
The pending-range/index path audit finds no new paths, moves or affected tooling
consumers. This follow-up carries the inconclusive publication audit above;
strict receipt checks do not claim to update that index or the census.
