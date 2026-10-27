# CreateAHero accessor storage ownership prerequisite

Inspected at `46e6a22e9f`, 2026-10-27, seat codexb5.

The data picker served `Code/GameEngine/Source/Common/Rva00219B9EAccessor.cpp`
with the historical guard-name finding at RVA `0x009FE434`. Its thirteen
registered keys retain pre-rename local-static names. Current objects instead
produce seventeen findings: thirteen compiler guards and four `AsciiString`
fallbacks. The compiler guards have sole local definitions after the DFE3xx
clearer retirement (`394b97a608`); the fallback strings still conflict with
explicit external owners in `reverse/data_rows.csv`.

| Fallback storage RVA | Existing atexit thunk RVA |
| --- | --- |
| 0x009FE3E8 | 0x007B7650 |
| 0x009FE420 | 0x007B76AA |
| 0x009FE440 | 0x007B766E |
| 0x009FE448 | 0x007B7678 |

`Code/GameEngine/Source/Common/Rva007B6A00AtexitThunks.cpp` still defines the
four address-named unsigned integers and owns their four-byte data rows. The
accessor object emits its own local `AsciiString` definitions at those native
placements. These are observed conflicting owners, not evidence for a new
donor name or a new body. Repair must reconcile the string lifetime, existing
thunks and registered owner before retiring the accessor's data debt.

A bounded trial copied the thirteen generated guard rows at RVAs
`0x009FE3EC` through `0x009FE44C` (stride eight) from
`data_ledger.py --out build/codexb5-createahero-data-ledger.csv`. This removed
their live findings, but `repair_queue.py retire data SOURCE` refused the
four post-rename fallback findings. The entire index trial was restored;
the debt register, function rows and game source are unchanged. This is a
blocked ownership repair, not a verifier false rejection.

Checks: all defined functions are rowed; `./build.sh` passes 87/87 rows and
thirteen literals, including float/import checks; `eh_verify.py` reports
13 EXACT graphs. Ordinary `link_check.py` reports LINKS and 3,046 authored
bytes against index `bf3dd31211` (2026-10-27 00:39, retail-truth-4). Clean symbol
resolution does not resolve the data-owner conflict. No census gain or
image-ownership receipt is claimed. The source claim was released.
