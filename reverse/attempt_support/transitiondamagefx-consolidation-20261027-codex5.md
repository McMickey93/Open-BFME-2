# TransitionDamageFX copy-range consolidation

2026-10-27, seat yasinschroeder-codex5; inspected revision 456a35502c.
Destination: `Code/GameEngine/Source/GameLogic/Object/Damage/TransitionDamageFX.cpp`.

## Applied change and evidence

`name_lane.py consolidate --under Code/GameEngine/Source/GameLogic/Object/Damage/`
supplied original-path leads and competing private views. The committed TU map
was stale; `tu_skeleton.py` rebuilt routing in memory and approved the wrapper's
destination from current inputs. No regenerated map is committed: its one
changed source cell follows the moved ledger row.

The supported dry run and applied merge accept the destination plus
`Code/GameEngine/Source/Common/Rva004BA324CopyRange.cpp`. The latter's existing
29-byte wrapper at 0x004BA324 now lives with its existing STLport copy provider.
The donor is deleted. This completes the prerequisite documented in
`consolidation-transition-copy-prerequisite-20261026-codex.md`.
Names, signatures, compiler flags, pins and hatches are unchanged.

The composition retains all 29 ledger rows (21 non-alias rows and eight existing
aliases). These are existing matches, with zero new coverage or retired debt.
The tool's LinkGuard accepts the composition against the published census index
bf3dd31211, 2026-10-27 00:39, retail-truth-4.

## Verification and ownership audit

- `./build.sh` on the destination and `Common/Rva004BA399EraseRange.cpp`:
  30/30 exact, including all 29 destination rows and the unchanged caller.
  Six funclet pins resolve through their verified parent EH data.
- Destination `find_declared_unmatched.py`: all definitions matched.
  `check_csv.py`: 98,276 function, 15,313 symbol and 2,227 data rows valid.
- Destination `eh_verify.py`: EXACT 1, no missing object or baselined failure.
- Saved standalone objects versus the final destination, using
  `allowed_symbols.definitions(strict=True)`: the same 57 external code
  definitions, fingerprints, sizes and exclusive-definition classifications; no added,
  removed or changed code definition. The same 20 external references remain
  after resolving definitions internal to the scope.
- `data_check.object_facts` over every row in both saved objects and the final
  object: identical data bindings and definitions, with no unreadable body.
  The existing table-symbol and exception-list bindings are preserved.
- The absorbed donor has no protected data/identity/flag/hatch key or canonical
  header queue row to transfer. Surviving destination and satellite debt stays
  with its existing owner. `tu_skeleton.py` refreshes the Microsoft-header queue:
  the destination remains `adapt / unknown`, now reporting its real iterator
  header include. No canonical header queue row is retired.

Scratch evidence is under `build/codex5-transition/`: merge JSON/log, original
objects and scoped rows, before/after code/data facts, comparison JSON and build
and link logs. The first broad refreshed link check overlapped the merge's
ledger repointing and donor deletion, so its duplicate-wrapper diagnostic is an
intermediate-state observation. It is not a baseline or a regression claim.
The final whole-tree preview's limit is recorded below.

The subsequent `link_check.py --refresh --current-ledger` refuses its whole-tree
preview because 12,203 current-ledger objects lack current compiler evidence.
This broader preview is inconclusive. The accepted merge's census-backed
LinkGuard and exact scoped provider comparison above establish preservation;
they do not claim a fresh whole-tree link measurement. The normal pre-push
batch audit still judges the final changed object and retired donor together.

## Outgoing path-consumer audit

Audited the sole pending source move from 456a35502c through this staged batch:
Common/Rva004BA324CopyRange.cpp -> Damage/TransitionDamageFX.cpp. Combined old
path, basename and case-variant searches cover tools, hooks, workflows, source
and header includes, build.sh, documentation, ledgers and registers. No tool,
include, build rule or other active path consumer requires an extra edit.

The ledger and TU-map source column now resolve to the destination. The donor
had no body-owner, data-row, symbol-source or Doxygen input to repoint. Remaining
old-path strings are the historical census row in link_status.csv, the
tool-generated provenance comment, old attempt/handoff evidence (including the
old log's fold-proof), and this audit. Symbol spellings in the naming reports,
caller declarations and comparison comments remain valid. The active copy
provider and its erase-range consumer were verified together at current paths.
Header queues were refreshed through their owning tool as described above.

## Remaining prerequisites

The tool rejects these nine donors without modifying them:

| Donor basename | Current composition blocker |
| --- | --- |
| TransitionDamageFXXfer.cpp | Duplicate BODYDAMAGETYPE_COUNT enumerator and incompatible receiver views |
| TransitionDamageFXRva004B9DA9.cpp | Selected class view lacks bfmeUseFDE and the other FDE members |
| TransitionDamageFXCtor.cpp | Constructor/base view conflicts with existing FDE members |
| TransitionDamageFXDtor.cpp | Destructor/base view conflicts with existing FDE members |
| TransitionDamageFXPoolKey.cpp | Selected receiver view lacks getModuleNameKey |
| Rva004BA399EraseRange.cpp | Byte mismatch under the composed compiler settings |
| TransitionDamageFXModuleDataDestructorThunk.cpp | Byte mismatch under the composed compiler settings |
| TransitionDamageFXModuleData_NeighborIDSubobjectNameDataAppend.cpp | Private allocator/template definitions conflict with real STLport |
| TransitionDamageFX_mapLoadPostProcess.cpp | Private allocator/template definitions conflict with real STLport |

Reconcile each rejected donor in its own verified prerequisite commit before
retrying consolidation. Nine mixed donors and the generated unwind satellites
remain in their existing sources. No absent body or lost coverage was found.

`docs/linking_obstacles.md` was claimed by another worker when this seat tried
to claim it. Its owner should incorporate this verified one-donor consolidation
and the remaining prerequisites above; the shared file is left to that owner.
Census confirmation remains pending; no headline linking or image-ownership
gain is claimed.
