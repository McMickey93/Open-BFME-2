# AIFlankAttackTactic consolidation prerequisite, 2026-10-27

Inspected revision: `0c1d21090b`. Default picker selected the approved
AIFlankAttackTactic TU and claimed it together with the destructor donor,
`Code/GameEngine/Source/Common/AIFlankAttackTactic.cpp`. The fresh
`name_lane.py consolidate --under` report for the destination's OffensiveTactics
directory finds its verified retail path operand at 0x005AA2EA. Its cached TU-map
entries are stale; `tu_skeleton.py` rebuilds placement in memory rather than
committing that map. No source paths or ledger rows move in this change.

## Merge remains blocked (LINK-119)

The ordinary dry run reports 19 approved rows, with two mixed donors left alone:
Rva004ECECDTacticCreate.cpp (32 total rows) and Rva004ECECDTacticCtors.cpp
(40 total rows). Its only clean donor is the three-row destructor unit.
Both existing sources pass `find_declared_unmatched.py`; the ordinary build
verifies all 11 rows across them before any edit.

Composition passes its byte trial but fails its link guard:

```
accepted: []
rejected: Code/GameEngine/Source/Common/AIFlankAttackTactic.cpp
  unresolved ?create@AITactic@@UAEPAV1@XZ
  comdat ??_7AIFlankAttackTactic@@6B@ (first)
blocked: no verified merge of two or more donors
```

Target facts: retail vftable RVA 0x00871EB0 has these eleven entries, followed
by string data. Values below are code RVAs.

| Slot | Target RVA |
| --- | --- |
| 0 | 0x005AA62B |
| 1 | 0x005AA0D8 |
| 2 | 0x000B3FD0 |
| 3 | 0x004ECE61 |
| 4 | 0x000910FB |
| 5 | 0x005AA60F |
| 6 | 0x005AA5AE |
| 7 | 0x005AA1EA |
| 8 | 0x004EDDAA |
| 9 | 0x005AA2A7 |
| 10 | 0x0047A699 |

Existing row identities establish slot 3 as
`AITactic::initializeTeamTemplate(void *, int)` and slot 9 as
`AIFlankAttackTactic::create()`. The destination declares a parameterless void
slot 3, placeholder slots 4/8, inherited `AITactic::create()` at slot 9 and no
slot 10. The standalone destructor and mixed constructor providers have only
the destructor slot. These private views need a complete contract reconciliation
before the destructor can cause the destination to emit a compatible table.
Shared trivial addresses at slots 2/4/10 do not prove original method names.
No virtual-slot trial, pin or alias was added.

The ordinary paired current-object preview also reports a duplicate
AIFlankAttackTacticImp::DoXfer for the destination: the old index retains its
pre-consolidation provider. This is an input-freshness limitation, not evidence
of a newly introduced duplicate. Index: `bf3dd31211`, 2026-10-27 00:39,
retail-truth-4, fetched during this pass. No current-ledger-wide or census
clearance is claimed. Recheck the complete provider cohort with current inputs
after class reconciliation.

## Completed destructor header cleanup

The donor's two local Microsoft declarations (`free`, global `operator delete`)
now come from `<stdlib.h>` and `<new>`. `/D_CRTIMP=` preserves the direct
game allocator call at RVA 0x00030830. `/GX` preserves the native EH frame:
the initial `/EHsc` trial with these headers removed it and failed 2/3 rows;
that trial is not retained. The final body, deleting destructor and handler
all byte-match with `/GX`. No shared header changes.

Verification:

- Ordinary `./build.sh` final result: 3/3 rows exact, all literal/import checks
  pass; no functions or rows added.
- Saved ordinary before/after objects: all four external COMDAT names, sizes
  and byte-plus-named-relocation digests are identical, with no additions or
  removals (`link_census._comdat_sections`).
- `find_declared_unmatched.py`: all defined functions already matched.
- `eh_verify.py`: EXACT 1, zero missing objects or baseline findings.
- `data_check.py`: zero shadow findings.
- `ms_header_audit.py`: zero local Microsoft declarations; scoped
  `refresh_queue` removes only this donor's queued row, preserving other rows.
- Ordinary `link_check.py` for the donor: LINKS, 108 -> 108 authored bytes.

No matched coverage, linked-byte or image-ownership gain is claimed. The
header cleanup is complete; the approved merge remains blocked. The normal
pre-push audit must carry index freshness limits into the next census.
