# VictorySystem.cpp consolidation (2026-10-28, claude-opus-5-5)

TU: `Code/GameEngine/Source/Common/VictorySystem.cpp` (52 approved rows,
`reverse/tu_map.csv`). Served by `tools/next_work.py --claim` (TU consolidation).

## Landed in this pass

- Merge of 3 files into the TU (`tu_skeleton.py --merge`, 14 rows, 15/15 exact,
  2 EXACT EH graphs): the seed, `GameLogic/System/VictorySystemCtor.cpp` and
  `Common/BfmeStringRecord00404BC5Ctor.cpp`.
- `tu_views.py`: one CellGrid and one Rva0040538FElement view across the seed,
  VictorySystemGridUpdates, VictorySystemNewMap and StlportCopy00404B71.
- One verified commit per remaining donor, each building under the TU's own
  `// cl:` flags against the TU's class spellings:
  - `VictorySystem_update.cpp`: the TU's VictorySystem (bases, `initialized134`).
  - `Rva00405337Clear.cpp`: the bfme2_ascii shim's `StringBase` with
    `/DBFME_SB_CLEAR_DECL`, which keeps the out-of-line `0x0048BA39` call. The TU
    takes the same define; no TU body calls `clear()`.
  - `StlportCopy00404B71.cpp`: specializes STLport's own random-access `__copy`
    instead of declaring a private `random_access_iterator_tag`.
  - `Rva00404D70Find.cpp`: the TU's `BfmeStringRecord00404BF3` (float slots), and
    `rva00404D70` declared `throw()` as its newMap caller needs.
  - The TU view gains method declarations only: `VictorySystem::rva00404B03`,
    `Rva00404781::AddDeath`/`rva00404CF5` (layout unchanged).
  - `VictorySystemGridUpdates.cpp`: TU flags (drops `_STLP_NO_EXCEPTIONS`), the
    TU's Rva00404781, superset `Player` (+0x54 index, +0x58 faction).
  - `VictorySystemNewMap.cpp`: the TU's VictorySystem/Rva00404D70/Player views;
    fields map to cellSize10, field14 (player count), field20 (radius), field24
    (bonus), playerParameterIndex28, grids12c, initialized134.
- All 7 sources: 28/28 rows exact after rebasing onto origin/master.

## Remaining merge prerequisite: census placement

The final `--merge --dry-run` composes and compiles all six remaining donors,
but LinkGuard rejects each: "a file without a census object would place the
merged unit earlier in link order than the guard can judge".

Cause (target/ledger facts): the first merge moved the 29-byte
`??0?$_Vector_base@URva0040538FElement@@...` row at `0x00211E58` (an ICF twin
emitted by the VictorySystem constructor) from VictorySystemCtor.cpp into the TU.
`link_check.link_rank` places an object by its lowest row, so the TU now ranks
5964, while the census index (`14dc3d2467`) still holds `VictorySystem.obj` at
its pre-merge place (13270) and the remaining donors at 13262..13269 (ranks
12984..12990). The guard cannot model the earlier slot and refuses.

Next step: after a maintainer's ordinary scheduled census records the merged
`VictorySystem.obj`, rerun
`python3 tools/tu_skeleton.py --merge Code/GameEngine/Source/Common/VictorySystem.cpp --dry-run`.
Do not bypass the guard or start a measurement. The 9 mixed files (Rva00404D70Init,
Rva00404781Method, Rva004051BC, RvaVectorDtorFamily, StringRecordCopyBFME2,
VectorClearInstances, VslotSmallBodiesAJ and two WWLib STLport footprint files)
still need splits before their rows can join.

## Audits

- Registers: no `code_identity_baseline.tsv`, `data_check_baseline.txt`,
  `hatch_baseline.tsv`, `flag_overrides.csv`, `header_queue.tsv` or
  `ms_header_queue.tsv` entry names any of the nine files.
- Tooling path audit over the outgoing range: the two deleted donor paths are
  referenced only by the TU's own `// ---- from` provenance comment.
- `tools/link_batch_audit.py --base origin/master --tip HEAD` over the 7 sources:
  INCONCLUSIVE (census index `14dc3d2467` lacks per-object consumer names).
  No linked-byte gain is claimed; carry the TU to the next census.
