# Mesh-model caps prerequisite — Sol family B, 2026-10-26

Allocated destination: Code/Libraries/Source/WWVegas/WW3D2/meshmdl.cpp.
Edited donor: MeshModelInitNPatch.cpp. Replace its private BfmeCurrentCaps
external alias with DX8Wrapper::Get_Current_Caps(), using the existing header
and preserving the already verified support byte at +0x13B. No new class
layout, data definition or name is inferred.

Evidence and checks:

- Fresh planner: `name_lane.py consolidate --under
  Code/Libraries/Source/WWVegas/WW3D2/ --out build/consolidation/meshmdl` and
  `--check build/consolidation/meshmdl`. Original meshmdl.cpp path evidence
  and all class, include, compiler and mixed-source prerequisites reviewed.
  Current `tu_skeleton.py --plan` rebuilds routing in memory: 59 approved
  rows, seven donors, seven mixed files. No committed TU map change.
- Target data ledger 0x009EDA7C owns
  `?CurrentCaps@DX8Wrapper@@1PAVDX8Caps@@A` in dx8wrapper.cpp. The old
  `?BfmeCurrentCaps@@3PAEA` alias has no independent definition.
- Before/after `./build.sh meshmdl.cpp MeshModelInitNPatch.cpp`: 14/14 exact,
  including six EH funclet pins verified by their parent data. Frozen-file
  checks pass; literal/float/import checks pass. Scoped code identity:
  14 rows, no problems in shadow mode.
- Scoped COFF proof preserves all 40 existing external code/data providers
  (nine seed, 31 donor): raw bytes, sizes, section flags, COMDAT selections,
  relocation bindings and undefined symbols, except exactly one DIR32 caps
  reference now names the owner. The added six-byte Get_Current_Caps copy
  equals the existing dx8wrapper.cpp copy, including its owner relocation,
  flags and COMDAT selection. It cannot substitute a different shared body.
  Reproduction: build/codexb-meshmdl-provider-proof.py,
  build/codexb-meshmdl-before.json and .before.obj snapshots.
- `./build.sh dx8wrapper.cpp`: 230/230 functions, 13 data rows, 80 string
  references, 26 floats and 24 named imports verify for the unchanged owner.
- `data_check.py --converged` on destination and donor: ten addresses,
  zero second names or unjudged references. `repair_queue.py retire data`
  retires exactly this donor's wrong-name key.

Data debt -1; identity debt retired 0; hatches 0; file reduction 0;
recovered bytes 0. This is an owner-binding prerequisite repair, not a
completed merge or a linked-byte claim.

Remaining destination prerequisites:

- Baseline ordinary merge trial accepts no donors. The N-patch and debugger
  donors conflict with seed placement new/delete definitions. Share-buffer
  donors leave Rva00172070Buffers before its ShareBufferClass declaration;
  the constructor donor loses its MeshGeometry base declaration; registration
  uses methods/fields missing from the seed's private class. Receipt:
  build/codexb-meshmdl-before-trial.txt. These compile conflicts are independent
  of the one corrected data reference; do not repeat the same trial until its
  class/include prerequisites change.
- `--split MeshModelInitNPatch.cpp --for meshmdl.cpp --dry-run` correctly
  refuses because every row belongs to this TU: use merge, not split.
- No downstream merge acceptance or Luna landing is claimed. Mixed donors
  retain every row and all existing register keys.

Publication audit: the entire pending font, Dogma, word-wrap and caps batch
contains no source move or deletion. Only the inherited font header introduces
an include consumer, verified in its recovery handoff. This donor adds no
include, path registry, build input, tool, hook or workflow change; historical
EA path strings are preserved. No maintainer-only link or smoke cycle run.

Keep MeshModelInitNPatch.cpp and this handoff claimed until publication. The
destination was inspected only and can be released after the repair commit.
