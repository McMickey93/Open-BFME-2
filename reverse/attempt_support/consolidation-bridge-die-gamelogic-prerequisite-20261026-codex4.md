# BridgeBehavior die GameLogic prerequisite, 2026-10-26

Allocated family A, shard 1/2 target:
`Code/GameEngine/Source/GameLogic/Object/Behavior/BridgeBehavior.cpp`.
The Behavior-scoped planner and ordinary `tu_skeleton.py --plan`/`--merge
--dry-run` identify 83 approved rows, 21 direct donor files, eleven mixed
files and one path-bound refused file. Routing is rebuilt in memory; no TU
map, source path, body, compiler flag or row placement changes.

## Repair and acceptance

`Rva004581FDOnDie.cpp` now includes the registered
`Common/GameLogicObjectLookupView.h` instead of privately defining GameLogic
and ObjectID. The unused private zero enumerator is removed. The target's
address-derived owner, Object/bridge interface views and raw frame access are
preserved; no name or complete receiver layout is inferred.

- Official `./build.sh Code/GameEngine/Source/GameLogic/Object/Behavior/Rva004581FDOnDie.cpp`
  passes before and after: 1/1 row, the exact 79-byte body, and all reference
  checks. Both frozen-file scans pass.
- `header_adopt_lane.py accept --class GameLogic SOURCE` passes and retires
  exactly one header-queue row through its acceptance path.
- `allowed_symbols.py --source SOURCE` before/after: three code references,
  all three bound to their owners, zero wrong bindings.
- `data_check.py SOURCE`: zero findings before/after. This donor has no
  code/data identity debt key; no such key is retired.
- The saved verified original object and official rebuilt object have identical
  `allowed_symbols._object_defs`: one code definition and four undefined
  external references. All external code/data fingerprints, sizes, exclusivity
  and actual `link_census._comdat_selections` policies are identical. The
  serialized `data_check.object_facts` also compares equal. Neither provider
  candidates nor consumer references change; no changed binding needs further
  consumer recompilation. No composed object is published.
- `check_csv.py` and `git diff --check` pass.

Local receipts: `build/codex4-bridge-die-{before-build,after-build,before-identity,
after-identity,before-data,after-data}.txt`, before/after JSON facts,
`build/codex4-bridge-die-before.obj`, and the binding proof script. The script
only inspects objects emitted by the official build; it never compiles.

## Remaining prerequisites and measurements

The original ordinary BridgeBehavior trial accepts no donors. Nine donors
lose rows under the carried `-G7 -arch:SSE` override; eleven others report
`no baseline match` in composition. The bridge-object handler additionally
needs canonical Coord3D/Region3D reconciliation (its derived constructor and
destructor/casts cannot be replaced by deleting declarations). Mixed donors
remain untouched, and BridgeBehaviorAreaEffects expands its historical
`__FILE__` path. This repair clears the die donor's recorded GameLogic header
prerequisite only; no new merge acceptance or later Luna landing is claimed.
The old diagnostics are not evidence of a standalone body regression: the
edited donor's ordinary 79-byte build passes both before and after.

File reduction 0; recovered C++ bytes 0; header debt retired 1; code/data
identity debt retirement 0. No census or image-ownership gain is claimed.

## Publication audit

The outgoing batch includes inherited docs commit `4ed8cb74c9` plus this
source/header-queue repair and handoff. `git diff --name-status --find-renames
origin/master..HEAD` and staged paths are reviewed together immediately before
the commit-and-publish call. No source path is added, removed or moved; active
tools, hooks, workflows, includes, build inputs and registries need no path
repoint. The new canonical include resolves from the donor's current path.
Historical EA paths and all code/data debt keys are preserved. Canonical
headers are unchanged, so the donor is the complete recompilation scope.
Unrelated untracked `reverse/zh_sweep/` is preserved.

Keep this source, the header queue, this handoff and inherited documentation
file claims until publication is confirmed; no RVA claims were taken.

## Other read-only allocated probes

ModelConditionUpgrade still accepts its previously documented five-row subset;
the constructor's ModuleData/getter boundary is unchanged. The prior evidence
shows why merely appending a virtual getter changes the ABI. No retry patch.
SlowDeathBehavior's canonical GameLogic adoption additionally needs a proved
hulk accessor; no shared-header guess was made.

LanguageFilter's ordinary dry-run (63 approved rows, two mixed donors) accepts
none: ReadWord/MapInsert/Map/Line fail composition bytes; UnHaxor has wcsrchr
linkage and StringBase redefinitions; Init has BadWordFileName storage conflicts;
Lifecycle redefines SubsystemInterface/methods. Its UnicodeString queue row
already records a body mismatch under canonical adoption. No donor was edited,
no unchanged failed adoption was retried, and no claim was retained for it.
The same-name header is not evidence that private inline choices can be deleted
without affecting code generation.

Two concurrent planner scans encountered disappearing temporary trial sources.
After the trial finished, the Behavior-scoped planner was regenerated and
`name_lane.py consolidate --check build/consolidation` passed. No planner or
routing gate was changed, and no temporary source remains.

## Next-session recovery audit

At the next session's start the two inherited commits are still unpublished:
`39c05b2f0d` (SlavedUpdate publication receipt) and `5d8dc4d8fc` (this repair),
rebased by the runner from their earlier SHAs. The worktree contains no inherited
source edits. `git pull --rebase origin master` and `check_csv.py` pass.
The pending range has no source moves; its sole changed source remains the
BridgeBehavior die donor above. This recovery receipt retries publication only
through the required commit-and-publish command. Claims remain held until the
runner confirms publication. Unrelated untracked `reverse/zh_sweep/` remains.
