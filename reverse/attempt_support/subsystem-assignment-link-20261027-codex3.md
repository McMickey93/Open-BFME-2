# SubsystemInterface assignment declaration

Control: `12b5b45db2c565a3443c190617922b4b351d0ba8`.
Ordinary-preview index: `bf3dd31211`, 2026-10-27 00:39 UTC,
`retail-truth-4`, clean-tree input. Follow-up to LINK-097's package c140
assignment handoff; no source or ledger path moves.

## Target evidence and change

The canonical `Code/Libraries/Source/subsystem/SubsystemInterface.h` declared
the copy constructor but omitted copy assignment. `SidesList::operator=` in
`Code/GameEngine/Source/GameLogic/Map/SidesList_sidesInfo.cpp` calls that
assignment and emitted an implicit definition. The existing out-of-line owner
is `Code/Libraries/Source/subsystem/SubsystemInterfaceCopy.cpp`, with its
31-byte row at RVA `0x00329880` and 37-byte copy-constructor row at `0x00329F5E`.

Before the edit, both objects defined
`??4SubsystemInterface@@QAEAAV0@ABV0@@Z` with identical 31-byte bodies and
one REL32 at offset 21 to `?set@?$StringBase@D@@QAEXABV1@@Z`. Their COFF
selection values differed: SidesList used ANY (2), the row owner
NODUPLICATES (1). The paired preview reported this duplicate in both units.
These are target object and ledger observations, not donor-name inferences.

Add only the existing assignment's declaration to the canonical header.
Keep the out-of-line implementation, its class view and both ledger rows.
No pins, hatches, baselines, compiler flags or class-layout changes.

## Verification scope

The staged `header_dependents.py` scan selects 548 ledger sources, identical
to the pre-edit scan. Include the unchanged out-of-line owner as a 549th
verification source. All three frozen-file checks (header, SidesList and
owner) pass. Normal `./build.sh` invocations verify this scope in two batches;
no compiler/cache helper is invoked directly.

The ordinary-preview cohort contains 547 dependent sources and the owner.
`Code/GameEngine/Source/Common/RTS/SpecialPower.cpp` has no census object and
is covered by byte/EH/data verification only. The baseline cohort reports
484/548 clean units and 302,305 preview-linked authored bytes. The paired
baseline reports 0 bytes for SidesList (1,714 own authored bytes) and the
owner (68 own bytes). The picker's ledger total for SidesList is 1,817 bytes;
it is not the preview's authored-byte accounting.

Baseline EH: 707 rows with EH data, 704 EXACT and three existing baselined
differences; no missing objects. Baseline converged-data check: 549 sources,
10 addresses, no second names or unjudged rows.

## Results

- `./build.sh` batches: 2,750/2,750 function rows in 379 sources and
  1,854/1,854 in 170 sources; 4,604/4,604 total. Data rows: 57 + 50 = 107
  exact. String, float and import checks pass in both batches. The second
  batch waited for the shared compiler lock and was polled to completion.
- After-edit EH: the same 707 rows, 704 EXACT and the same three registered
  differences, no missing objects. Converged data: the same 549 sources and
  10 addresses, zero second names and zero unjudged rows.
- COFF inspection: SidesList no longer defines the base assignment and keeps
  an undefined external reference to it. The owner's original 31-byte body,
  NODUPLICATES selection and relocation are unchanged. Across all 548
  previewed objects, only SidesList's function summary changes: the implicit
  SubsystemInterface and associated AsciiString assignments disappear, and
  local `$L`/EH referents renumber. Every ledger row and EH graph remains
  verified as above; no other object's function summary changes.
- The same 548-unit ordinary preview goes from 484 to 486 clean units and
  from 302,305 to 304,087 preview-linked authored bytes (+1,782). SidesList
  clears 0 -> 1,714 and SubsystemInterfaceCopy clears 0 -> 68. No previously
  clean unit regresses; all other blocker lists are identical. The 62
  remaining blocked units keep their existing prerequisites.
- `check_csv.py`: PASS, 98,276 function rows, 15,313 symbol rows and
  2,226 data rows. Staged dependency selection remains unchanged; all new
  evidence is tracked with the header repair.

Clearance is limited to LINK-097's assignment-duplicate pair in ordinary
preview scope. Census confirmation is pending; no measured LINKED, LINKING
or image-ownership gain is claimed.

Scratch commands, logs, source lists and object summaries are under
`build/codex3-20261027/`; this directory is not durable evidence.

## Reference freshness limitation

The BFME 1 freshness receipt was over 72 hours old. Official master was
fetched at `a0940f921b5b8d9029fc922b8032abcf4e60d240`; the clean pinned
checkout remains `4fa9d591641a743b86f2320343b7a276585b814b`.
The `file:reference/open-bfme-1` claim was refused because
`yasinschroeder-codex` holds it. Preserve that worker's scope: neither gitlink
nor receipt was changed. The preliminary old-input full gate was explicitly
interrupted before completion after abandoning that reference-update scope;
it is not a verification pass. The repair uses the dependency-scoped checks
above and makes no reference-freshness success claim.
