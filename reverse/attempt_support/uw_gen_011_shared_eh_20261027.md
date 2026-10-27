# uw_gen_011 shared EH graph cleanup

Inspected `b29299d15c` on 2026-10-27 against the fetched `bf3dd31211`
provider index. The link picker selected `uw_0075b6d0` in
`Code/gen_small/uw_gen_011.cpp`. These are existing generated placeholders,
not lost rows or newly discovered code. This batch replaces six rows (51
bytes) through `tools/add_match.py --replace-rva`; generated source is left
untouched. The unit retains 366 generated rows, down from 372.

## Target evidence and chosen ownership

Each selected parent has a strictly matching complete body and an EXACT
`eh_verify` graph. Retail parent prologues lead to the following handler and
FuncInfo RVAs; the unwind entry identifies the compiler-local label's address.
This establishes placement even where several native parents share the same
EH graph. Neither adjacency nor identical cleanup bytes chooses the parent.

| Cleanup RVA | Bytes | Chosen parent RVA | Handler RVA | FuncInfo RVA | State | Emitted label |
| --- | ---: | --- | --- | --- | ---: | --- |
| `0x0075B6D0` | 8 | `0x00007850` | `0x0075B6D8` | `0x008FD644` | 0 | `$L412` |
| `0x0075C310` | 8 | `0x000177E0` | `0x0075C318` | `0x008FDC1C` | 0 | `$L543` |
| `0x0075F087` | 8 | `0x00079C23` | `0x0075F09A` | `0x009019D0` | 0 | `$L8251` |
| `0x0075F08F` | 11 | `0x00079C23` | `0x0075F09A` | `0x009019D0` | 1 | `$L8252` |
| `0x00786837` | 8 | `0x0041A5D2` | `0x0078683F` | `0x00933918` | 0 | `$L8284` |
| `0x00787441` | 8 | `0x00427F75` | `0x00787449` | `0x00934AE8` | 0 | `$L8296` |

The first parent is the narrow default string constructor in
`Code/Libraries/Source/WWVegas/WWLib/stlport_narrow_string_default_ctor.cpp`.
Its graph is also shared by the existing narrow copy/cstr and wide
default/copy/cstr constructors; all six graphs verify EXACT. The existing
handler row already uses the narrow default parent. The second parent is the
narrow range constructor in the adjacent `stlport_narrow_string_range_ctors.cpp`;
the native wide range constructor also uses that graph. The remaining four
labels are emitted by existing constructors in
`Code/GameEngine/Source/Common/NarrowStringRecordCopyBFME2.cpp`.
Other native prologues reaching these shared graphs do not make independent
cleanup bodies or justify duplicate rows.

All six full cleanup bodies match with no unresolved or masked relocation.
Their destructor transfers resolve to the existing free-first-member body at
`0x00142D70`: the first two name String_base destruction, and the other four
name narrow basic_string destruction. Existing rows and fold proofs establish
those names; this change adds none.

| Cleanup RVA | Full resolved bytes |
| --- | --- |
| `0x0075B6D0` | `8b4df0e998769eff` |
| `0x0075C310` | `8b4df0e9586a9eff` |
| `0x0075F087` | `8b4df0e9e13c9eff` |
| `0x0075F08F` | `8b4df083c10ce9d63c9eff` |
| `0x00786837` | `8b4df0e931c59bff` |
| `0x00787441` | `8b4df0e927b99bff` |

`parent=` records the selected proven graph and source. No new pin, alias,
class identity, original TU assignment or donor-source identity is inferred.
The stale committed TU map's generated assignment and `repair_queue dest`'s
neighbor fallback are not approvals; this uses the supported EH-parent
companion recovery path instead. A filtered ledger check finds exactly one
row at each of the six addresses and unchanged total matched-row count.

## Remaining prerequisite

`uw_00767c40` (8 bytes) stays generated. Its native shared graph belongs to
the BfmeAssignRecord32 constructor `0x001736D6`, copy constructor
`0x00173731` and destructor `0x0017330A`. The existing objects have EXACT
EH graphs and matching parent bodies, but all three cleanup relocations name
`??1Rva00087A93@@QAE@XZ`, currently rowed at `0x0007B724`. Retail instead
jumps to `??1?$RefCountPtr@VMeshClass@@@@QAE@XZ` at `0x0014A0D0`.
Reading the copy constructor's cleanup resolves `8b4df0e9dc3a91ff`, while
retail is `8b4df0e988249eff`. Reconcile the parent's member lifetime/type
before repointing; do not add another pin to force the wrong name to the
retail address. No parent source was edited. The blocked verdict is recorded
with `tools/re_log.py` and its unused claims released.

## Verification and compatibility audit

- `./build.sh` on the three destinations: 48/48 rows; string, float and
  import checks pass. Existing stale local-label hints in other rows remain
  validated through their own exact parent graphs.
- `tools/eh_verify.py` on those destinations: EXACT 16, zero baseline debt
  or missing objects. `find_declared_unmatched.py`: no frozen definitions.
- `tools/check_csv.py`: 98,276 functions, 15,313 symbols, 2,227 data rows.
- `tools/data_check.py` on the three destinations: zero findings.
- `tools/tu_ownership.py --staged`: passes. Code identity remains in shadow;
  its scoped scan reports duplicate narrow numpunct `do_truename` and
  `do_falsename` definitions in the existing range-constructor source. No
  source/object definition changed; no identity register entry is retired.
- Ordinary `link_check.py`: all three destinations LINKS before and after;
  111, 447 and 850 authored nonpadding bytes respectively, unchanged. This
  is a preview, not a new census or an ownership receipt.
- The outgoing source-path changes are ledger ownership repoints only.
  All old and new source files remain tracked, no includes or filenames move,
  and no source disappears with a debt key. Active `gen_uw` ownership derives
  from the ledger's generated source column, so these rows cease to be its
  inputs while their orphan generated bodies remain untouched as required.
  Existing source globs continue to find the retained files; no active path
  consumer needs changing. Combined path/basename search found source
  comments, TU-skeleton comments and an unchanged fixture for the existing
  range constructor; these intentionally continue naming retained files.
  The prior unpublished `b29299d15c` changes data ownership only and adds no
  source move. LINK-095 and the target follow-up retain the
  generated unit's census blockers and record this bounded repair.

Result: six placeholder rows replaced by existing C++ emissions, coverage
preserved. Whole-unit closure, new census-linked bytes and NOT OURS reduction
remain unmeasured.
