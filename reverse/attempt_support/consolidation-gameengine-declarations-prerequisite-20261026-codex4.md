# GameEngine declaration prerequisite attempt, 2026-10-26

Allocated family A shard 1/2 TU:
`Code/GameEngine/Source/Common/GameEngine.cpp`. The current Common-scoped
planner and `--plan` identify 29 approved rows, nine direct donors and ten
mixed sources. Planner currency passed before the trial; routing was rebuilt
in memory. No merge, routing edit or TU-map regeneration was applied.

## Boundary and verified trial

The ordinary before dry-run accepts nothing. Even the seed fails compilation:
its `TheNetwork` self-cast macro expands inside declarations produced by
composition (unexpected NetworkInterface at line 26, then undeclared TheNetwork).
The frame-period helper donor also lacks the seed's nonvirtual rva00225D38
member declaration. The existing seed and helper both access the native period
at +0x34; no virtual slot or receiver layout change is needed for that member.

A two-line trial removed this redundant macro:

```cpp
#define TheNetwork (*(class NetworkInterface **)&TheNetwork)
```

and declared `bool rva00225D38(void);` beside the seed's existing private
frame-admission declaration. Its existing typed extern remains. No name, pin,
source path, compiler flag, virtual slot, global or data provider is introduced.

- Official before/after `./build.sh GameEngine.cpp Rva00225D38Check.cpp`
  passes all five existing rows / 837 bytes, one data row, four strings and
  nine named imports. Frozen-file scans pass.
- `allowed_symbols.py --source` before/after reports 13 references (11 owner,
  two alias), zero wrong bindings. `data_check.py` reports zero findings.
- Saved official before objects and official rebuilt objects have identical
  external code/data fingerprints, sizes, exclusivity, actual COMDAT policies,
  undefined references and all five row data-binding fact sets. Proof script:
  `build/codex4-gameengine-proof.py`; it only inspects official objects.
- The after ordinary merge trial now gets past seed compilation and byte
  verification, but the census-linked guard refuses the seed with unresolved
  `?BfmeClientFramesPerSecond@@3HA`. It accepts no donor, so there is no
  accepted composition whose selected-provider facts can be certified.

## Bank and handoff

The two-line source trial was reverted from the saved pre-attempt source,
then the official build and frozen scan were rerun. No trial C++ remains under
Code. Reapply only after resolving the provider-index/census discrepancy and
then repeat the ordinary merge trial plus full composition/binding proof.
The ledger records BfmeClientFramesPerSecond at VA 0x00DBA4E8 in
GameClient/LivingWorld/LivingWorldEyeTower.cpp and BfmeLogicFramesPerSecond at
RVA 0x009BA4E4 in ColdGlobalDwordGetters.cpp. These are existing ownership facts,
not permission to add another definition or alias. No cross-scope provider was
edited. `link_check.py --fetch-index` confirmed the published and local indexes are
both 2026-10-26 13:18 at d1f046749a; 21,951 published objects were imported.
It did not change the index, so the same blocked trial was not rerun.
The receipt is `build/codex4-gameengine-index-refresh.txt`.

Other prerequisites remain: GameEngineSlots canonical GameLogic adoption lacks
rva0024877A in the shared view; client-subsystem/frame-timing composition also
needs receiver members; deleting-destructor composition lacks EmitVtableTag.
Existing mixed sources remain intact. MessageStream identity issue #116 is
untouched. No downstream acceptance or Luna landing is claimed.

Local receipts: `build/codex4-gameengine-{before,after}-{trial,build,identity,data}.txt`,
`before-{0,1}.{cpp,obj}`, proof script/output and planner/plan. The after
trial's compile-to-link boundary is evidence only. File reduction 0; recovered
C++ bytes 0; debt retired 0. Release both attempt source claims; retain this
handoff claim until publication.

## Batch audit

Audit the complete pending range through PlayerTemplate commit 07aee9b190
and these staged documentation/log updates. There are no source moves,
deletions or renamed paths. The pending PlayerTemplate header's three actual
consumers and conservative six-source hook scope are recorded in its handoff;
all pass. Active tools, hooks, workflows, includes, build inputs and registries
need no path repoint. All debt keys, historical paths and unrelated untracked
reverse/zh_sweep are preserved. No binding-changing GameEngine object is
published, and no link/census result is substituted for composition proof.
