# Draw cached-key data-index retirement

Inspected at `8b5a8a815e`, 2026-10-27, seat codex.

The default picker served W3DPropDrawPoolKey.cpp's guard at RVA 0x009EBBC4.
Its first supported retirement refused because the data index still preferred
the former external `g_Va00DEBBC4` in GlobalFlagClearers_DEAFxx.cpp. Commit
`f24c982181` already removed that standalone clearer and global, rowed the
parent's compiler-owned rollback and verified its EXACT EH graph. This is stale
data-identity debt, not a missing body or a new C++ recovery.

The same completed cleanup affects eleven other standalone cached-key units.
Commit `e8fedf7e30` also renamed those getters to getModuleNameKey. The current
objects retain their compiler-owned key and guard; no current source names any
of the twelve former external guard globals. None of these guard addresses has
a data_rows or data_converged owner.

`python3 tools/data_ledger.py --out build/codex-propdraw-data-ledger.csv`
generated 34,422 addresses without reporting missing objects. Only its exact
24 key/guard rows belonging to the following twelve claimed sources were copied
into reverse/data_ledger.csv. All are now four-byte `owned` globals with one
definition; each key has two references and each guard four. The PropDraw key
row was already current, so the committed index delta contains 23 changed rows.
The generated size is an index bound, not a new independently verified storage
ownership claim.

All sources are under
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Drawable/`:

| Source | Key RVA | Guard RVA |
| --- | --- | --- |
| W3DLaserDrawPoolKey.cpp | 0x009EBB60 | 0x009EBB64 |
| W3DQuadrupedDrawPoolKey.cpp | 0x009EBB6C | 0x009EBB70 |
| W3DTruckDrawPoolKey.cpp | 0x009EBB90 | 0x009EBB94 |
| W3DTankDrawPoolKey.cpp | 0x009EBB9C | 0x009EBBA0 |
| W3DBuffDrawPoolKey.cpp | 0x009EBBB4 | 0x009EBBB8 |
| W3DPropDrawPoolKey.cpp | 0x009EBBC0 | 0x009EBBC4 |
| W3DFloorDrawPoolKey.cpp | 0x009EBBCC | 0x009EBBD0 |
| W3DLightDrawPoolKey.cpp | 0x009EBBD8 | 0x009EBBDC |
| W3DStreakDrawPoolKey.cpp | 0x009EBBE4 | 0x009EBBE8 |
| W3DSailModelDrawPoolKey.cpp | 0x009EBBF0 | 0x009EBBF4 |
| W3DBoatWakeModelDrawPoolKey.cpp | 0x009EBC0C | 0x009EBC10 |
| W3DTornadoDrawPoolKey.cpp | 0x009EBC2C | 0x009EBC30 |

Validation:

- find_declared_unmatched passes every source. The normal build verifies all
  36 function rows and twelve literals; all twelve dependency receipts are
  current. The former clearer unit separately passes its one remaining
  function row and one data row.
- eh_verify reports twelve EXACT graphs, including the rowed rollbacks.
- data_check reports zero findings across the twelve sources; enforced
  converged checks pass with zero second names or unjudged rows.
- `repair_queue.py retire data SOURCE` passes for each of the twelve sources,
  retiring one registered key each with zero remaining findings. Only this
  owning tool removes register lines; the initial PropDraw refusal removed none.
- Ordinary link_check against index `bf3dd31211`, 2026-10-27 00:39,
  retail-truth-4, reports all twelve sources LINKS and preserves 946 authored
  bytes (FloorDraw 77, the other eleven 79 each).

The retained changes edit no C++ source, function row, pin, data ownership row,
converged name or source path. No new census-linked bytes or image-ownership
gain is claimed. Shared PropDraw ModuleData/DrawModule contract prerequisites
remain separate (LINK-102); this verification only covers the cached-key units.
RopeDraw's obsolete source-path debt was inspected but left for its owning
consolidation/retirement path; neither that index row nor its register is changed.
