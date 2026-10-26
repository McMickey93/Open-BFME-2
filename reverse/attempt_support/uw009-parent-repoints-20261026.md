# Generated unwind ownership cleanup, 2026-10-26

Inspected revision: `39e752ed5b`. Census index: 2026-10-26 19:02 at
`5ce093a71a`. Scope: rows in `Code/gen_small/uw_gen_009.cpp`; no generated
source was edited. This is placeholder cleanup, not recovery of missing bytes.

## Water parameter cleanups

Retail's FuncInfo/unwind maps and the complete matched parent EH graphs place
these compiler labels in
`Code/GameEngineDevice/Source/W3DDevice/GameClient/Water/W3DWaterAreaRenderables.cpp`:

| Funclet RVA | Bytes | Parent RVA | FuncInfo RVA | State | Current label |
| --- | ---: | --- | --- | ---: | --- |
| 0x0075F9EE | 8 | 0x00083780 | 0x00902534 | 1 | $L6478 |
| 0x0075FA12 | 8 | 0x0008385F | 0x00902568 | 2 | $L6528 |
| 0x0075FA36 | 8 | 0x00083959 | 0x0090259C | 2 | $L6603 |
| 0x0075FA48 | 8 | 0x00083A7A | 0x009025C0 | 0 | $L6671 |

All four tail-call 0x005F8F96. Initial repoint admission correctly failed:
`Rva00082BE6Element` and `Rva00082C1DElement` destructors were emitted but had
no address binding. Each existing destructor COMDAT is exactly 12 bytes:
`8b 09 85 c9 74 05 e9 <rel32> c3`. Its sole relocation, at +7, names
`ReleaseTreeHintRef00217D4C`; retail's relocation targets 0x0007DEEF. Resolving
that relocation makes the entire body equal retail at 0x005F8F96, including
the final ret. The existing `TreeHintRef00217D4C` destructor row in
`Code/GameEngine/Source/Common/Rva002833A3C5.cpp` provides the fold owner.

Registered the two complete emitted destructor twins with `add_match.py
--icf-owner`, exact `gen-alias` notes and the existing owner's ledger source as
fold proof. Then `add_match_batch.py` replaced the four generated rows with
parent-bound `Unwind@` rows. The final water unit passes all 21 rows. These
folds preserve the existing opaque element names; no original type name or
additional unique byte coverage is inferred.

## Asset-manager duplicate rows

`f943117658` already rowed the four 14-byte cleanup actions at 0x007A7724,
0x007A7732, 0x007A7740 and 0x007A774E in
`Code/Libraries/Source/assetmanager/AssetManagerImplCtor.cpp`. The generated
copies are redundant claims over precisely the same extents.

Current parent `??0AssetManagerImpl@@QAE@XZ` at 0x00624DB0 verifies with an
EXACT EH graph: FuncInfo 0x009610A8, handler 0x007A775C, states 5..8 place
current labels $L62250..$L62253 at those addresses. The existing rows' older
labels $L12315..$L12318 resolve through their recorded parent. All 12 rows in
the surviving unit pass. Removed only the four generated rows, recorded them
in `deleted_rows.csv`, and retained each existing C++ owner.

## Blocked vector cleanup batch

The parent at 0x000C47F4 in
`Code/GameEngine/Source/Common/System/Rva000C38F8Ctor.cpp` has an EXACT graph
(FuncInfo 0x0090530C, handler 0x00761D7B). It places these actions:

| Funclet RVA | Bytes | State | Current label |
| --- | ---: | ---: | --- |
| 0x00761CB3 | 11 | 0 | $L6626 |
| 0x00761D00 | 11 | 7 | $L6633 |
| 0x00761D0B | 14 | 8 | $L6634 |
| 0x00761D19 | 14 | 9 | $L6635 |
| 0x00761D27 | 14 | 10 | $L6636 |
| 0x00761D35 | 14 | 11 | $L6637 |

Full row verification rejects the unresolved `vector<PlayerAITypeEntry>`
destructor. Every retail action calls 0x0002CC70, already owned by the complete
63-byte `vector<AsciiString>` destructor in `StlportAsciiStringVectorDtor.cpp`.
The constructor's common three-pointer vector shape does not establish element
destruction semantics or a destructor fold. Reconcile the element/storage
view against this native destructor before retrying. The failed batch was
rolled back; all six rows remain generated, and blocked verdicts are logged.
No nonmatching source, pin or alias was retained for this batch.

## Verification and remaining scope

- Generated ownership falls from 181 rows / 1,733 bytes to 173 / 1,645: four
  parent repoints (32 bytes) and four duplicate removals (56 bytes). Each moved
  or retired range still has exactly one funclet row. The two new destructor
  spellings are proved ICF twins of an existing 12-byte range.
- `check_csv.py`, declaration checks and scoped byte verification pass
  (216/216 rows across the generator and the three inspected parent sources).
  `eh_verify.py` reports all six parent graphs EXACT across water and assetmanager.
- `link_check.py --prepare-current` verified strict receipts for both parents.
  The paired ordinary preview reports water LINKS (1,124 bytes) and assetmanager
  LINKS (666 bytes), unchanged from the cited census. The generated harness
  remains blocked by 113 unresolved names. No census headline gain is claimed.
- The rest of the generated unit remains open. The scan of retail EH tables
  found parent graph candidates for its other rows, but graph agreement alone
  does not establish external destructor identity, as the blocked batch shows.
  The picker's first row 0x0075C9DA was left untouched because both candidate
  parent sources were held by other workers.
- Path-consumer audit: only four ledger source bindings move; every source path
  stays present. No includes, tooling paths, generated source, protected debt
  keys or source registry entries move. The historical target-table census
  figures are retained, with this partial cleanup recorded separately.
