# E036 containment cached-key data-index retirement

Inspected at `d67dec6909`, 2026-10-28, seat `yasinschroeder-codex`.

The data picker selected HealContainPoolKey.cpp's guard at RVA 0x00A03658.
Its index still selected the external definition in the deleted
GlobalFlagClearers_E036xx.cpp. Commit `2097e1bd13` replaced that source's
sixteen standalone clearers with their parents' compiler-generated rollback
funclets, verified against EXACT EH graphs, and removed its address globals.
The six standalone containment accessors below also have current
`getModuleNameKey` names while their key/guard index entries retain the old
static accessor manglings.

All six claimed sources are under
`Code/GameEngine/Source/GameLogic/Object/Contain/`:

| Source | Key RVA | Guard RVA |
| --- | --- | --- |
| CaveContainPoolKey.cpp | 0x00A03648 | 0x00A0364C |
| HealContainPoolKey.cpp | 0x00A03654 | 0x00A03658 |
| HordeContainPoolKey.cpp | 0x00A03678 | 0x00A0367C |
| HorseHordeContainPoolKey.cpp | 0x00A03694 | 0x00A03698 |
| HordeGarrisonContainPoolKey.cpp | 0x00A036E8 | 0x00A036EC |
| AODHordeContainPoolKey.cpp | 0x00A036F4 | 0x00A036F8 |

`python3 tools/data_ledger.py --out build/contain-e036-data-index/data-ledger.csv`
generated 34,334 addresses and reported five matched sources without objects.
This change adopts only the twelve complete, unmodified generated rows for the
addresses above. Every selected row has status owned, one definition, size four,
and two key or four guard relocation sites. The generated upper bound for
0x00A0367C tightens from eight to four bytes. These are index bounds, not
independently byte-verified data extents. No selected address has an explicit
data_rows.csv or data_converged.csv owner. This scoped refresh establishes
neither whole-index freshness nor broader data ownership.

Verification:

- All six frozen-file checks pass. The normal build passes 18/18 function rows,
  six string literals, and float/import checks. All six source SHA-256 hashes
  remain unchanged; every selected ledger source is tracked.
- EH verification reports six EXACT parent graphs, zero nonexact rows and
  zero rows without an object.
- Before the refresh, data_check reports twelve wrong-name findings: a key and
  guard for each renamed accessor. Afterward, enforced data_check reports six
  sources and zero findings, including zero findings outside the baseline.
  Converged mode checks eleven protected addresses with zero second names and
  zero unjudged rows.
- `repair_queue.py retire data SOURCE` independently passes for each source,
  removes its single registered key and reports zero remaining findings.
- Paired ordinary previews against the published `14dc3d2467` index
  (2026-10-28 02:44 UTC) retain 6/6 LINKS and 472 authored bytes: Cave 79,
  Heal 79, Horde 79, HorseHorde 79, HordeGarrison 78, AODHorde 78.

The initial default link pick, Rva00415704Ctor.cpp, still previews LINKS
(90 authored bytes) against that same index. LINK-112's existing repair needs
no new source change; its claim was released before selecting the data work.

At the inspected control, the six owning-tool retirements above removed six
stale data-debt keys. During publication, upstream `22ec257aa5` supplied all
six retirements and eleven of the twelve identical generated index rows.
The rebase preserves those upstream retirements and claims no additional
six-key debt reduction. At that first rebase, the remaining generated-row
change tightened HealContain's guard index upper bound at `0x00A03658` from
twelve to four bytes. The next publication rebase onto `13dcfaad91` also picked
up upstream `978df9538b`, which already supplied that bound correction.
The final batch therefore retains the independent evidence but contributes
no additional E036 index delta or debt retirement. Broader storage closure
and census confirmation remain open. No new census-linked bytes or
image-ownership gain is claimed.
