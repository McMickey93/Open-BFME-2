# Scripts reset cleanup, 2026-10-28

Inspected revision: `35eee2f3f0`. Owner: `yasinschroeder-codexb`.
The default picker selected `Scripts.cpp` consolidation and claimed its 98
file scopes. The naming planner covered the ScriptEngine subsystem; its
original-path and donor evidence were reviewed before the dry merge.

## Verified cleanup

| Reset row | Destructor provider | Change |
|---|---|---|
| `0x003B7647`, 36 B, `ScriptListSubrecordReset.cpp` | `0x003B7167`, `??1Rva003B8802Set@@QAE@XZ` | Replace the fake cleanup-method call and linker alias with an explicit destructor call. |
| `0x003B7C1E`, 36 B, `Rva003B7C1EReset.cpp` | `0x003B766B`, `??1Rva003B872ASet@@QAE@XZ` | Construct into stack storage, retain constructor-result forwarding to swap, and explicitly call the existing destructor owner. |

Both retail bodies call the existing constructor at `0x003B761E` and swap at
`0x003B56A5`. Their final calls target different, already-rowed destructors.
The source uses call-only destructor views; no donor name, common class
identity, inheritance or additional layout is inferred. No symbol or row
was renamed, added or moved.

Checks:

- `./build.sh` verifies each complete 36-byte row and its references.
- `find_declared_unmatched.py` passes for both edited files.
- `eh_verify.py` finds no EH rows or missing objects in either helper, as before.
- `data_check.py --converged` passes for both helpers.
- Ordinary `link_check.py`, using index `41c28839bf` from 2026-10-28 11:08,
  reports both helpers and both destructor providers LINKS. The previews retain
  36 + 36 helper bytes and 77 + 87 provider bytes; this is not a new census.
- The compiled helpers reference the respective destructor names directly;
  neither object contains a weak external or `/alternatename` directive.
- `hatch_counters.py --update` removes precisely these two register entries,
  lowering the alternatename count from 2,919 to 2,917.

## Consolidation prerequisites

The picker reports 97 potential donor removals and 266 mergeable rows; the
full approved plan contains 312 rows, 98 donor files and 20 mixed files.
The seed's ten code rows still byte-match. Its ordinary preview still has the
two LINK-063 blockers: unresolved protected `OrCondition` destructor and the
conflicting `OrCondition` vtable. The previously documented extra virtual pool
slot and destructor identity decision remain prerequisites; no unchanged
rename trial was repeated.

`tu_skeleton.py --merge .../Scripts.cpp --dry-run` was interrupted after more
than 17 minutes of active compilation, before it returned its donor verdicts.
This is an incomplete exploration, not evidence that every combination fails.
No merge was applied and no source-file reduction is claimed. The tool had
captured the source inputs before the two helper cleanups above; any future
merge trial must use the current sources and a fresh naming-planner report.

The claimed file scope has no code-identity debt, data debt or canonical-header
queue entries. Two Microsoft-header queue entries remain, in
`ScriptListRva003B766BDtor.cpp` and `ParameterReadParameter.cpp`.
The other hatches remain with their current source owners. No source path
changes were made, so no path-consumer rewrites or debt transfers are needed.
