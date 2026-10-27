# Mechanical consolidation handoff — 2026-10-27

The unpublished batch contains the verified merges into `debug_io_con.cpp`,
`AIUpgradeScienceBuilder.cpp`, and `HeightDieUpdate.cpp`, plus the earlier path
consumer audit commit. The current pending path range was reviewed with
`git diff --name-status --find-renames origin/master` and a combined search of
old basenames and destinations across `tools/`, `.githooks/`, `.github/`,
`Code/`, registries, build inputs and Doxygen inputs. No active consumer needed
an edit. Remaining hits are source provenance/comments and generated or
historical evidence (including `reverse/link_status.csv`); those were preserved.

The three prior merges were produced by `tu_skeleton.py --merge`; their accepted
trials passed its byte and link guards. `tu_ownership.py --replay origin/master
--ref origin/master` reports zero flagged commits. The commit hook's outgoing
`link_batch_audit.py` remains the batch-level provider/consumer and selected
implementation check before publication. No class declaration, include, or
header-adoption content changed in this batch.

## Apt trial blocked by full gate

A staged mechanical merge of `DogmaPoolBytes.cpp` and `DogmaPoolFreeBlock.cpp`
into `DogmaAllocator.cpp` moved two matched rows and their data/flag ownership.
`./build.sh Code/Libraries/Source/Apt/DogmaAllocator.cpp` passed all six rows,
one data row, and 10 string references; `find_declared_unmatched.py` passed.
Staged `tu_ownership.py`, `code_identity_gate.py`, and `data_check.py` reported
no new finding (identity: six rows checked; data: one source checked).

The required full pre-commit gate refused the trial at DIR32 consistency with
six new inconsistent vtable symbol bases:

- `??_7?$VectorClass@PAVFontCharsBuffer@@@@6B@`: `0xbd0d68`, `0xbd3b98`
- `??_7Rva002B31DB@@6B@`: `0xbfe090`, `0xc1c780`
- `??_7Rva0035A97EVisitor@@6B@`: `0xc153d4`, `0xc1c780`
- `??_7Rva003F498ACallback@@6B@`: `0xc1c780`, `0xc37080`
- `??_7Rva0040CFFF@@6B@`: `0xc1c780`, `0xc394c8`
- `??_7Rva0056ACAEVisitor@@6B@`: `0xc1c780`, `0xc6d0bc`

The failure is outside the Apt row set and needs investigation by the owner of
those DIR32/data identities before this trial can be retried. No checker,
baseline, or source repair was changed. The exact staged trial is preserved at
`build/session-recovery/apt-merge-blocked-20261027/trial.patch` (SHA-256
`8676cd9ca5ea38175dc4a0f04275394c12cdbed33cd23edba7d3572dc186119c`), and its
source/ledger changes were restored. The Apt destination, donors and two row
claims were released. Do not count this trial as a merge or source-file
reduction.

## Allocated `SlavedUpdate.cpp` candidate refused

The destination passed `consolidation_queue.py --check-tu` and its plan listed
28 approved rows, six donor files, five mixed files and no statically refused
files. The unchanged merge dry run accepted no donor and blocked with:

- LinkGuard: `SlavedUpdate.cpp` links at the census, but the merged object would
  no longer define `??_7SlavedUpdate@@6BBehaviorModuleInterface@@@`,
  `??_7SlavedUpdate@@6BObjectModule@@@`, and
  `??_7SlavedUpdate@@6BSlavedUpdateInterface@@@`, all still referenced by the
  census. The guard lists the SlavedUpdate destination and its five related
  census-linked units.
- `SlavedUpdateCtor.cpp`: `error C2039: 'rva0004A1875' : is not a member of
  'SlavedUpdate'`.
- `SlavedUpdateMoveToNewRepairSpot.cpp`: the same missing member, plus
  `error C2039: 'm_modelConditionWo...` (compiler output truncated by the tool).

The 13-row carve from `SlavedUpdateRepair.cpp` was refused because the residual
would lose matched rows `0x001E3459` and `0x0026C26D` (`blocked: the residual
loses matched rows (flag region or a shared helper)`). A carve from
`ModuleNameGetters.cpp` was refused because the destination TU itself holds one
unplaced row (`blocked: TU path exists and holds rows the map does not place
there: (unplaced) 1`). The other three mixed sources were inspected with
`--split FILE`; no manual declaration, path or flag repair was attempted.
No claims or source changes were made for this candidate. Continue with a
separate allocated TU; leave these donors for the prerequisite owner.

## Allocated `Geometry.cpp` candidate refused

`Geometry.cpp` passed its allocation check and the planner snapshot was current.
The plan had 35 approved rows and 13 donors (11 mixed). The merge dry run
accepted no donor and reported `blocked: the TU file's own rows do not match
under the verifier`. The five rejected clean donors had these exact blockers:

- `GeometryInfoExpandFootprint.cpp`: its `-O2` flag override is not the carried
  empty override.
- `GeometryInfoRva006BD9C0.cpp`: its `-Ox -G6` override is not the carried
  empty override.
- `GeometryInfoRva0087E370.cpp`: its `-O2 -G6` override is not the carried
  empty override.
- `GeometryInfoSet.cpp`: its `-O2` override is not the carried empty override.
- `Geometry.cpp`: no baseline match.

The dry run lists 13 census-linked units under LinkGuard; it did not report a
link regression, but it could not establish a merged composition because the
seed itself failed byte verification. No source/flag repairs or split trials
were attempted. Leave the task for prerequisite repair and continue with a
separate allocated TU.
