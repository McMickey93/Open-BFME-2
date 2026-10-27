# Sorting renderer data alias cleanup

2026-10-27; control revision `25d156a07fd6da02156d6adbfdd345906b0a31de`.
Claim: `file:Code/Libraries/Source/WWVegas/WW3D2/SortingRendererBFME1.cpp`.

The picker served the `g_00DEDA4C` data-identity key. The current source
also had aliases for the render-state dirty mask and capabilities pointer.
The existing DX8Wrapper header already declares their ledger owners:

| Previous reference | Existing owner | Retail RVA |
| --- | --- | --- |
| `g_00DEDA4C` | `DX8Wrapper::matrix_changes` | 0x009EDA4C |
| `TheBoxTextureDirtyMask` | `DX8Wrapper::render_state_changed` | 0x009EC4F4 |
| `BfmeCurrentCaps` | `DX8Wrapper::CurrentCaps` | 0x009EDA7C |

The repair exposes the two protected counters through a local derived access
shim's using-declarations. It has no instances or new storage, and is not
identified as a retail subclass. Capabilities reads use the existing inline
Get_Current_Caps and retain the target's byte offset 0x2b0. No shared header,
row, pin, data owner or source path changes. Four alternatename occurrences
(the dirty-mask directive was duplicated) leave the hatch register through
`tools/hatch_counters.py --update`: total 3188 -> 3184.

## Verification

- `find_declared_unmatched.py` before and after: all defined functions already
  matched (26 rows; the same two existing exemptions remain).
- `./build.sh Code/Libraries/Source/WWVegas/WW3D2/SortingRendererBFME1.cpp`:
  all 26 rows pass, including both renumbered funclets; three float literals
  pass. The sum of row extents is unchanged.
- `eh_verify.py` on the source: one EXACT graph, zero nonexact or missing.
- Saved pre-edit COFF compared with the normally rebuilt object: the same
  77 code-symbol names after excluding compiler labels and unwind-label
  symbols, all with identical raw instruction bytes. Relocation names differ
  only at seven references to the three data aliases and compiler-generated
  `$L`/`$T` label ordinals. The attached
  [comparison](sorting-renderer-data-aliases-20261027-codexb4.json) lists the
  seven data references. This extra comparison does not prove additional
  retail bodies; the normal row and EH gates provide retail verification.
- `data_check.py --converged` on the source: ten protected addresses,
  zero second names, zero unjudged rows.
- Ordinary `link_check.py` before and after: LINKS, 13,227 -> 13,227 authored
  nonpadding bytes against index `bf3dd31211` (2026-10-27 00:39).
  The unchanged Get_Transform diagnostic is unreferenced and not a blocker.
  This is a bounded ordinary preview, not a new census or runtime result.

## Retirement prerequisite

The normal data scan decreases from eight findings to five. The three active
alias findings disappear. Two other registered keys (`g_00DEDA98` and
`g_d3dDevice`) already had no finding in the control object. All five original
keys remain in `reverse/data_check_baseline.txt`: the supported
`repair_queue.py retire data SOURCE` correctly refuses retirement because
the following five findings, already present before this repair, are outside
the register:

| Check | Symbol | Retail RVA | Current data-index ownership |
| --- | --- | --- | --- |
| duplicate-def | `_DEFAULT_SORTING_VERTEX_COUNT` | 0x009B61FC | sortingrenderer.cpp, provisional |
| duplicate-def | `_temp_index_array` | 0x009EE948 | sortingrenderer.cpp, provisional |
| duplicate-def | `_temp_index_array_count` | 0x009F2950 | sortingrenderer.cpp, provisional |
| wrong-name | `_sorted_list` | 0x009B6200 | unowned `?g_00DB6200@@3PAXA` |
| wrong-name | `_clean_list` | 0x009B620C | unowned `?g_00DB620C@@3PAXA` |

The current data index lists static copies in both SortingRendererBFME1.cpp
and sortingrenderer.cpp for these addresses. Next claim both sources, reconcile
the sorting-state ownership and list identities with native layout evidence,
and verify every affected row before retrying the same retirement command.
Do not remove the old keys by hand or weaken the check. No source or index
trial for that broader ownership repair was made here.

Progress claimed: four fewer hatch occurrences, three direct data-owner
bindings, matched coverage and ordinary-preview linking preserved. No data
register retirement, new census-linked bytes or image-ownership receipt.
