# SubsystemInterface registry dispatch prerequisite, 2026-10-26 (codex4)

Target: `Code/GameEngine/Source/Common/System/SubsystemInterface.cpp`.
Allocated by the family-A codex4 shard of `/opt/runner/consolidation_queue.py`.
This is a canonical-header prerequisite repair, not a merge or recovered body.

## Repair and evidence boundary

`SubsystemInterfaceListRva001B4FE9.cpp` and
`SubsystemInterfaceListRva001B505F.cpp` now include the canonical
`Code/Libraries/Source/subsystem/SubsystemInterface.h`. Registry entries use
that canonical type. The existing virtual calls retain their original slot
indices and argument types through separate dispatch-only views. Those views
have no instances, vtable definitions, data layout assertions or named method
definitions. The canonical header remains unchanged: its data variant does not
declare the non-destructor virtual slots. No donor name or complete class ABI
is inferred from the existing anonymous slot calls.

`header_adopt_lane.py accept --class SubsystemInterface` passed separately for
both sources and retired their two rows from `reverse/header_queue.tsv`.
No code-identity keys or data findings were retired. No ledger rows, pins,
hatches or source paths changed. File reduction: 0. Recovered C++ bytes: 0.

## Verification

- `./build.sh Code/GameEngine/Source/Common/SubsystemInterfaceListRva001B4FE9.cpp Code/GameEngine/Source/Common/SubsystemInterfaceListRva001B505F.cpp`:
  all five rows exact before and after (30 + 47 + 225 + 8 + 10 = 320 retail
  bytes preserved), including the collector's unwind and handler.
- `find_declared_unmatched.py` on both sources: passes before and after.
- `class_gate.py` on both sources: passes.
- `allowed_symbols.py --source` for both: 11 references, 8 owner, one EH,
  one fold and one alias; zero wrong-owner findings.
- `data_check.py --converged` for both: two sources, ten addresses, zero
  second symbols and zero unjudged bindings. `eh_verify.py`: one EXACT,
  zero missing and zero baseline findings. `check_csv.py` and
  `git diff --check` pass.

Scoped before/after object evidence is in
`build/codex4-subsystem-{before,after}.json` (identical), produced with upstream
`allowed_symbols._object_defs`, `build.row_object` and `data_check.object_facts`.
Saved pre-edit objects are `build/codex4-subsystem-{reset,collect}-before.obj`.
`build/codex4-subsystem-provider-proof.txt` records a second comparison using
`allowed_symbols.Obj`, `digest` and `link_census._comdat_selections` against the
rebuilt objects: all external code/data fingerprints, actual COMDAT selection
modes, exclusivity and undefined-reference sets are identical. The reset donor
has 18 external code definitions; the collector has 32. Thus this repair changes
no selected provider or consumer binding; no consumer recompilation beyond the
two changed sources is needed. This is scoped object evidence, not a new link
census or runtime result.

## Composition result and remaining prerequisites

The current-map `tu_skeleton.py --plan` approves 34 rows and identifies ten
clean donors and two mixed sources. The before/after
`tu_skeleton.py --merge Code/GameEngine/Source/Common/System/SubsystemInterface.cpp --dry-run`
reports are `build/codex4-subsystem-{before,after}-trial.txt`. Both accept no
pair. The before report's two `adopt_first: SubsystemInterface` entries are
cleared after this repair, but no downstream rows are yet accepted for merge.
No Luna landing is claimed.

The seed still has a private AsciiString declaration conflicting with the
canonical shim, and its SubsystemInterfaceList declaration lacks donor fields
and methods (`m_24`, `m_vec`, `m_records`, rva001B4E21, rva001B5018,
rva001B51C0). The collector also needs declaration ordering for ModuleData and
its local overflow helper reconciled by a separate verified repair. Mixed
sources must stay behind until supported split/routing checks authorize them.
The seed was claimed for investigation only and was not edited.

## Planner, other probes and publication audit

The scoped System planner and then the Common planner reviewed original-path
leads, alternatives, mixed routing, flags, includes and internal linkage.
`name_lane.py consolidate --check build/consolidation` passed immediately
before the final trial. Planner output is evidence, not merge approval. No
regenerated TU map is committed.

Other allocated read-only probes: FloatUpdate still rejects the pool's missing
member and the raw-vtable constructor; ProneUpdate still accepts only the
previously compatible five-row pair and rejects its pool and raw-vtable
constructor. These are unchanged recorded blockers, with no new edit or claim.
MessageStream was excluded pending the maintainer's issue #116 decision.

Before this commit, `git log origin/master..HEAD` has no unpublished commits;
upstream is six commits ahead and touches no path in this repair or changed
instructions. The complete pending batch has no moves, deletions or renamed
source paths. Reviewed the two basenames against active tools, hooks,
workflows and registers: no path consumer needs repointing. Both new canonical
header consumers were rebuilt together, and historical EA paths remain intact.
Only the two source edits, header-queue retirement and this handoff are staged.
The publisher will rebase and run the outgoing batch audit normally.
