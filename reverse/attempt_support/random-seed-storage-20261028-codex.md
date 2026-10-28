# Shared random-seed storage

Inspected from `87c6af16d4`, 2026-10-28, seat codex.

The registered seed debt had been deferred because each reader and the chosen
owner defined its own file-static array. This pass claims all seven source
files together, exposing the three existing inventory owners with C linkage
and replacing the other seven array definitions with external declarations.
The decorated object names remain `_theGameClientSeed`, `_theGameAudioSeed`
and `_theGameLogicSeed`; no pin, alternate name or new address-global is added.
No function row or source path moves. This is binding repair across the current
split files, not a claim that retail declared external globals or that its
original RandomValue translation unit has been recovered.

| Seed RVA | Sole owner | Objects using symbol | Native reference sites |
| --- | --- | --- | --- |
| 0x009BA3A0 | GameClient/ClientRandomValue_getValueReal.cpp | 3 | 3 |
| 0x009BA3B8 | Common/GameClientAudioRandomValue_getValueInt.cpp | 3 | 3 |
| 0x009BA3D0 | Common/GameLogicRandomInit.cpp | 4 | 5 |

Target evidence: all 12 existing code rows pass unmasked byte verification.
Their native DIR32 operands identify the three seed arrays at these addresses.
Current COFF inspection finds exactly one external definition per name, with
all other users referencing that same external symbol. Each owner's 24-byte
initializer matches retail (72 bytes total). A Code-wide source search finds
only these seven files declaring or using the three seed identifiers.
The earlier donor comments identify source leads only; no donor storage-class
or original translation-unit inference is needed for this repair.

Checks:

- `./build.sh` over all seven sources: 12/12 rows, one data row, two strings,
  three float literals and three named imports pass.
- `find_declared_unmatched.py`: all defined functions are matched.
- `data_check.py --enforce`: seven sources, zero findings.
- `data_check.py --converged`: seven sources, 11 protected addresses,
  zero second names and zero unjudged rows.
- Paired ordinary `link_check.py` runs against census index `14dc3d2467`
  (2026-10-28 02:44): 7/7 LINKS before and after, 632 authored bytes retained.
  These are previews, not new census-linked bytes or runtime evidence.
- `data_ledger.py --out build/random-seed-storage-20261028/data_ledger.csv`
  generates three owned rows with the unchanged owners and one definition
  each; only those three rows are copied into the committed inventory.
  The generator reports two unrelated missing matched objects, so this is a
  scoped refresh, not a claim of tree-wide inventory freshness.
- `repair_queue.py retire data SOURCE` removes seven registered keys from
  six sources (two from GameLogicRandomInit). The client Real owner has no
  registered key. No baseline key is deleted by hand.

The three prior static-owner deferrals are resolved through re_log.py.
The split TU recovery and unrelated log-file/other data ownership remain open;
this change claims neither whole-image ownership nor runtime closure.
