# Science TU merge, 2026-10-26

Mechanical shard 1/5; destination `Code/GameEngine/Source/Common/RTS/Science.cpp`.
The current approved plan accepted unchanged donors
`ScienceStoreNameDescription.cpp`, `Rva001FF703CreateNode.cpp`, and
`ScienceStore_getScienceFromInternalName.cpp`; the tool merged 14 matched rows
and removed three source files. The allocator was refused because the provider
index was stale. No other destination was changed in that trial.

## Verification

- `./build.sh Code/GameEngine/Source/Common/RTS/Science.cpp`: 14/14 rows.
- `find_declared_unmatched.py`: all defined functions are matched.
- `check_csv.py`: OK; class gate: OK; allowed-symbol scan: 26 references,
  zero wrong bindings; staged code identity: zero new findings (shadow mode);
  data check: zero findings.
- `link_check.py --prepare-current` and `--new-variants`: pass for the TU.
- Refreshed the census object index to `bcb191bfeb83d1928d875191ecdf75a8917120aa`.
  `link_batch_audit.py` compared the complete source composition: one current
  object, three absorbed objects, no selected-provider change and no
  changed-unit unresolved blocker. This is a shadow comparison, not a census
  LINKED result.
- The combined path search across tools, hooks, workflows, Code, registries,
  build input and docs found no active consumer needing a path repair. The
  remaining donor-path comments in the TU are provenance; `link_status.csv`
  and prior handoffs are historical receipts.

## Rejected donors left for prerequisite owners

The dry run did not accept these unchanged donors; none was edited:

- `Rva001FF3DCFinish.cpp`: `C2039` — `m_sciencePurchasePointCostMP` and
  `m_sciencePurchasePointCost` are not members of `ScienceInfo`.
- `Rva001FF6D7List.cpp`: `C2039` — `rva001FF6D7` is not a member of
  `Rva001FF6D7`; `C2065` — `m_ptr` undeclared.
- `ScienceStoreFriendLookupScience.cpp`: `C2039` — `friend_lookupScience` is
  not a member of `ScienceStore`; `C2270` — modifiers not allowed.
- `StlSweepW4Rva001FF743.cpp`: byte mismatch.
- `stlport_rb_tree_science_base_001FF76E.cpp`: `C2953` — `_STL::allocator`
  already defined; `_STLP_alloc_proxy` also redefined.
- `stlport_vector_sciencevec_allocate_copy.cpp`: `_STL::__false_type`
  redefinition and duplicate `_STL::allocator` (`C2011`/`C2953`).
- `Rva001FFC38.cpp`: duplicate `_STL::allocator` and `_STL::vector`
  definitions (`C2953`).
- `StlSweepR3Rva001FFD6B.cpp`: byte mismatch.
- `ScienceStoreParseScienceDefinition.cpp`: `C2039` — `deleteOverrides` is
  not a member of `Overridable`; parser receiver declarations are also absent.
- `Rva001FFEE9Assign.cpp`: duplicate `_STL::vector` definition (`C2953`).

Purchase-cost fields, parser/receiver declarations, STL declaration conflicts,
and byte mismatches require the owning code seat. No identity debt retirement,
link census gain, or authored C++ bytes are claimed. The merge tool carried the
three donors' path-keyed hatch accounting and updated the MS-header queue.
