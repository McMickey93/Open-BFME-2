# SlaughterHordeContain TU-evidence handoff

Inspected BFME 2 `e0a165efdf` on 2026-10-27. The default picker claimed
the run starting at RVA 0x004803B6 and these four Contain sources:
SlaughterHordeContainPoolKey.cpp, SlaughterHordeContainDtor.cpp,
SlaughterHordeContainIsValidContainerFor.cpp and
SlaughterHordeContainRva004804DD.cpp. No source, ownership, pin or map
change was retained. The scope and two briefly investigated data addresses
were released after verification.

## Routing prerequisite

`name_lane.py consolidate --under Code/GameEngine/Source/GameLogic/Object/Contain/`
generated a current snapshot; `consolidate --check build/consolidation`
passed. All four sources remain unresolved. The selected pool-key body,
its EH handler and its guard rollback funclet have no current placement
evidence. `tu_evidence.py --source` likewise prints no derived signals.

The retail image contains the original path
`Code/GameEngine/Source/GameLogic/Object/Contain/HordeContain/SlaughterHordeContain.cpp`
at string RVA 0x00848D48 (file offset 0x00848148). The planner records the
retail image SHA-256
`f008b587570bad693981dc7218588c81d192a1e064b0f7f861539c51156a7640`.
Path existence does not place these four sources. No selected body has a
verified instruction reference to that path.

The AddHordeMember row at 0x004808E8 has a WorldBuilder file/name lead and
the same spelling in BFME 1 EA evidence. The planner grades this as a hint,
not target routing. BFME 1's `ea_evidence.csv:7064` is a donor file fact;
its address does not transfer to BFME 2. The WB lead names the same function
whose reconstruction already used that lead, so it is not independent
corroboration. The class-derived SlaughterHordeContain.cpp and
CitadelSlaughterHordeContain.cpp guesses also interleave. No TU assignment
was asserted and no regenerated map was committed.

Next: obtain an independent target anchor or a supported layout bracket
for the actual HordeContain path, then rebuild the map and rerun the four
sources' routing checks before any merge. Do not interpret the old map's
proposed Citadel brackets or displaced Slaughter hints as approval.

## Data identity remains open

The selected pool-key source still defines its key and compiler guard
under the recovered `getModuleNameKey` name. The generated data ledger
retains the old static-function spelling and a guard owner in the deleted
GlobalFlagClearers_E037xx.cpp. Current data checking reports two findings:

| Datum | Current symbol | RVA |
| --- | --- | --- |
| Cached key | `?TheSlaughterHordeContainPoolKey@?1??getModuleNameKey@SlaughterHordeContain@@UBE?AW4NameKeyType@@XZ@4W43@A` | 0x00A03764 |
| Compiler guard | `?$S1@?1??getModuleNameKey@SlaughterHordeContain@@UBE?AW4NameKeyType@@XZ@4IA` | 0x00A03768 |

Both are STATIC-storage symbols in their own four-byte .bss COMDAT
sections. The parent's DIR32 sites at +0x30/+0x38 place the key; +0x0C/+0x15
place the guard. Its exact 13-byte rollback funclet at 0x0078B971 also
places the same guard through +0x01/+0x08. All in-place addends are zero.
These facts identify the current compiler data bindings; they do not
justify deleting the stale registered key while replacement findings
remain. No data row, baseline retirement or global alias was added.

## Checks and scope

- `check_csv.py`: passed, 98,384 function rows and 2,228 data rows.
- `find_declared_unmatched.py`: all defined functions matched in each of
  the four selected sources.
- `./build.sh` on the four sources: 11/11 function rows exact; the one
  string reference also verifies. The destructor's renumbered funclet
  label was resolved through its existing parent EH data.
- Pool-key ordinary link preview against index `bf3dd31211`: already
  LINKS, 78 -> 78 authored bytes. This is not a new census or gain.
- `data_check.py` on the pool-key source: two wrong-name findings, both
  outside the old baseline spelling; no debt retired.

This is a blocked routing investigation, not a new match, consolidation,
link repair or image-ownership result.
