# Dynamic vertex-buffer allocation declarations

Control: `87d14902cfc83f1732db1a5ec7a09c54fb873cff`.
Source: `Code/Libraries/Source/WWVegas/WW3D2/bfmedynamicvertexbuffer.cpp`.
Ordinary-preview index: `bf3dd31211` (2026-10-27 00:39, retail-truth-4).

The default picker served this unit's historical thread-wrapper selected-copy
blocker. Including the current `BfmeDX8ThreadLock.cpp` and
`BfmeDX8ThreadCheck.cpp` providers already clears it before this change. The
three-source ordinary preview reports LINKS for all three sources at 6,860,
247 and 31 authored bytes respectively. This confirms LINK-106's existing
repair; it is not a new census measurement.

In the same claimed source, replace four handwritten scalar/array allocation
and deletion declarations with the compiler's `<new>` header. The header
preserves the deletion exception specifications and the distinct array-new
declaration required by the existing sorting constructor. A scoped
`ms_header_audit.refresh_queue` removes only this source's stale queue entry;
the earlier SDK cleanup had already removed its local ULONG/HANDLE copies.

Verification:

- `./build.sh <source>` passes all 46 functions, one data row and five floating
  literals before and after the change. Nine renumbered funclet labels resolve
  through their parents' EH data.
- Read-only COFF comparison of the saved control object and the new object:
  all 63 executable sections have identical full bytes and relocation targets.
  Local relocation symbols are compared by section/value, external symbols by
  name. All 90 external symbol records (name, section, value, storage) are
  identical. Comparison script and control object are local scratch under
  `build/dynamic-vb-header-20261027/`.
- `find_declared_unmatched.py <source>` reports no unrowed definitions.
- `eh_verify.py <source>` reports 14 EXACT graphs.
- `ms_header_audit.py scan <source>` finds zero locally declared Microsoft
  names. The scoped queue refresh preserves every unrelated queue row.
- `data_check.py --enforce <source>` reports ten existing findings and zero
  outside the register. `data_check.py --converged <source>` reports ten
  addresses, zero second names and zero unjudged rows.
- The same three-source ordinary link preview after cleanup remains 3/3 LINKS
  at 7,138 total authored bytes.

The ten storage-identity findings and their failed extern trials remain as
documented in [the previous handoff](dynamic-vertex-buffer-data-20261026.md).
This change retires a header queue entry while retaining matched coverage and
the current ordinary-preview link result. It makes no strict-link receipt,
census, image-ownership or runtime claim.

Publication: the runner rebased and pushed this cleanup as `c2ec6b636d`.
The normal push gate passed 84/84 rows across its four-source scope and all
18 EH graphs. Its mandatory link audit remained INCONCLUSIVE: index
`bf3dd31211` predates outgoing base
`324eb34f541bc40b41e67d73532e40aea44eea62`, and four scoped objects lacked
current receipts (first `Code/GameEngine/Source/GameClient/Eva.cpp`). The
hook explicitly reported linking UNVERIFIED. This is neither a proven loss
nor a clean current-master link result. Carry the publication scope and this
unit's thread-provider cohort into the next normal census/current-index audit;
complete the strict receipt prerequisites under LINK-008 before strict reuse.
