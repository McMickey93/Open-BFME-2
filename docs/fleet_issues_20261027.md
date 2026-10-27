# Byte-match regression on 2026-10-27: 14 funclet rows dropped

`reverse/progress_v2_history.csv` shows `byte_matched` falling from 7,978,500
(e1ecb55890) to 7,978,351 (a7a0d01885). It had been at 100% since 2026-10-24.
A diff of the bytes covered by matched rows (`reverse/functions.csv` plus the
`.text` rows of `reverse/data_rows.csv`) between the two commits finds 150
bytes that no matched row claims any more. No new bytes are covered. All 150
bytes are EH unwind funclets, and master at 0b9c34c270 still lacks them.

## Cause

Six commits of the "canonical Snapshot base; repoint funclet(s)" and
"ICF-folded dtors" series moved funclets off the `uw_gen` scaffolds onto
their parents' compiler labels. A parent's labels renumber when its EH graph
changes, so the rows of its other funclets have to be relabelled as well. In
each of these commits the old sibling rows were removed, but some of the
relabelled rows were never added. Several commit messages announce them, for
example "sibling uw_0079121a follows the renumber to $L503". No
`reverse/deleted_rows.csv` tombstone was written, and no gate stopped a
matched row from disappearing.

## Missing rows

| Address | Bytes | Unit | Parent | Old row (label) | Dropped by | Label to add |
|---|---|---|---|---|---|---|
| 0x007634F7 | 11 | Rva000E6AC0Ctor.cpp | `??0Rva000E6AC0@@QAE@XZ` | Unwind@00b634f7 ($L5738) | 50b7b29f94 | from eh_verify |
| 0x00763502 | 11 | Rva000E6AC0Ctor.cpp | `??0Rva000E6AC0@@QAE@XZ` | Unwind@00b63502 ($L5739) | 50b7b29f94 | from eh_verify |
| 0x0076350D | 11 | Rva000E6AC0Ctor.cpp | `??0Rva000E6AC0@@QAE@XZ` | Unwind@00b6350d ($L5740) | 50b7b29f94 | from eh_verify |
| 0x00763523 | 11 | Rva000E6AC0Ctor.cpp | `??0Rva000E6AC0@@QAE@XZ` | uw_00763523 ($L5704) | 50b7b29f94 | from eh_verify |
| 0x0076357E | 11 | Rva000E6AC0Ctor.cpp | `??1Rva000E6AC0@@UAE@XZ` | Unwind@00b6357e ($L5818) | 50b7b29f94 | from eh_verify |
| 0x00763589 | 11 | Rva000E6AC0Ctor.cpp | `??1Rva000E6AC0@@UAE@XZ` | Unwind@00b63589 ($L5819) | 50b7b29f94 | from eh_verify |
| 0x00763594 | 11 | Rva000E6AC0Ctor.cpp | `??1Rva000E6AC0@@UAE@XZ` | Unwind@00b63594 ($L5820) | 50b7b29f94 | from eh_verify |
| 0x0076359F | 11 | Rva000E6AC0Ctor.cpp | `??1Rva000E6AC0@@UAE@XZ` | uw_0076359f ($L5782) | 50b7b29f94 | from eh_verify |
| 0x007635AA | 11 | Rva000E6AC0Ctor.cpp | `??1Rva000E6AC0@@UAE@XZ` | uw_007635aa ($L5783) | 50b7b29f94 | from eh_verify |
| 0x0077D4DB | 11 | Rva00355B61Ctor.cpp | `??0Rva00355B61@@QAE@XZ` | uw_0077d4db ($L380) | b5ad8b612c | $L1278 per the message |
| 0x007881E6 | 11 | Rva000D3FA0Destructor.cpp | `??1Rva000D3FA0Map@@UAE@XZ` | uw_007881e6 ($L5665) | 0dada5701d | $L5475 per the message |
| 0x0079121A | 10 | TurretAICtor.cpp | `??0TurretAI@@QAE@PAVObject@@PBVTurretAIData@@W4WhichTurretType@@@Z` | uw_0079121a ($L483) | 67a53654ed | $L503 per the message |
| 0x00792F90 | 11 | TunnelTrackerDtor.cpp | `??1TunnelTracker@@MAE@XZ` | uw_00792f90 ($L3481) | 8846bc744a | $L3502 per the message |
| 0x00793B03 | 8 | StagingRoomGameInfo.cpp, probably | `?GetLocalChatConnectionAddress@@YA_NVAsciiString@@GAAI@Z` (0x004FE987), probably | uw_00793b03 in uw_gen_000.cpp ($L5969) | ffde306e75 | from eh_verify |

Together these come to 150 bytes. The parent of 0x00793B03 is inferred from
the layout: it sits between `$L5807` (0x00793AFB, a funclet of
`GetLocalChatConnectionAddress`) and that function's `__ehhandler` at
0x00793B0B.

## Repair

Rebuild each parent unit, take the label that `eh_verify` binds to each
address, and add the rows back as `gen-funclet` rows with the same `parent=`
as their siblings. `progress_v2` should then return to 7,978,500. Labels that
come from the commit messages hold only while the units are unchanged, so take
the labels from `eh_verify` at repair time. This note does not repair the
rows, to avoid racing the series that is still relabelling these units.

## Gate suggestion

A commit that removes a matched `functions.csv` row should add a row covering
the same bytes or write a tombstone. A check that matched `.text` coverage may
not shrink, computed as in `tools/progress.py` `coverage()`, would have caught
this at commit time.
