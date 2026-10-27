# Science copy-wrapper composition — 2026-10-27

Inspected BFME 2 `6cdcea926b`; published preview index `bf3dd31211`
(2026-10-27 00:39, retail-truth-4). The default picker claimed the Science
consolidation group. The Common/RTS naming planner supplies no verified retail
original-path reference for this group; donor paths are routing leads, and the
supported merge rebuilds the stale TU map in memory to judge approval.

## Prerequisite repair

The current baseline dry run accepts no merge. In particular,
`GameLogic/Object/Behavior/Rva001FFC38.cpp` defines empty private copies of
`_STL::allocator` and `_STL::vector`, which collide with Science.cpp's STLport
headers. Its 29-byte wrapper uses only pointers to these types. Replace both
empty definitions with forward declarations, preserving the existing callee,
signature and opaque element spelling. This proves no application-level type
identity and adds no new name, pin or alias.

The normal build and frozen-file check pass. Comparing preserved and rebuilt
objects through the existing COFF readers finds identical external definitions,
undefined names, both non-debug sections and every normalized relocation.
The ordinary link preview stays LINKS, 29 -> 29 authored bytes.

The supported full dry run now accepts Science.cpp and this donor: **15 rows**,
with the census-linked units and their external providers protected by its link
guard. This is a prerequisite improvement; the actual merge is a separate
change.

## Verification and remaining work

- All 26 rows and one data row across the original eleven-source group verify.
  Its ordinary current-object preview is 11/11 LINKS, 1,623 authored bytes.
- The two-source subset has one EXACT exception graph. Shadow data checking has
  zero findings; converged checking covers ten addresses with no second names
  or unjudged rows.
- Neither source has a header-adoption, code-identity or data-baseline key to
  transfer. Science.cpp retains its existing Microsoft-header queue item and
  two hatch keys; the donor has none. No debt is retired by this repair.
- The other nine clean donors remain separate: missing cost fields in the
  ScienceInfo view; incompatible list members; missing friend-lookup declaration;
  tree-destructor and vector-assignment byte failures; private tree-base,
  allocate-copy and assignment STL definitions; parser/Overridable declarations.
  Eleven mixed donors also stay intact. The earlier purchase-cost GameLogic
  adoption remains valid, without implying its remaining fields are reconciled.

Scratch receipts: `build/science-before-build.log`, `build/science-dry-run.log`
and `build/science-consolidation-20261027/` (preserved sources/objects, before
preview, after dry run and wrapper object comparison). No census, strict global
closure, new linked bytes or image-ownership gain is claimed.

## Applied consolidation and outgoing path audit

After the separate prerequisite commit, `tu_skeleton.py --merge` accepts only
Science.cpp and the wrapper, preserves their 15 rows, and deletes the absorbed
source. Only the wrapper's source cell changes in functions.csv and tu_map.csv;
the latter is not regenerated. All nine rejected clean donors and eleven mixed
donors stay intact. The merge refreshes Science.cpp's existing Microsoft-header
queue item without changing its content. There are no header-adoption, data or
code-identity keys on either source. The automatic whole-tree hatch refresh
also proposed unrelated stale-key deletions; those deletions were restored.
The existing Science hatch keys and all register totals are unchanged.

The normal build verifies all 26 group rows across ten surviving sources (and
the data row); the frozen-file check passes. Both exception graphs are EXACT.
Shadow data checking reports zero findings, and converged checking covers ten
addresses with zero second names or unjudged rows. Strict preparation verifies
all 15 merged rows and writes a reusable current receipt without modifying the
census or index. The union of both preserved objects' 51 external code
definitions has identical digest, size and COMDAT exclusivity after composition;
the undefined-name set is identical. A read-only current-object overlay omitting
the retired donor has no unresolved, duplicate, COMDAT, address or selected-body
blockers. The merge's own link guard protects the eleven census-linked sources
and external providers. Isolating the merge with the preserved objects and
current ledger order changes only the wrapper's selected provider from its
retired object to Science.cpp, retaining an `ok` retail verdict. Older-index
comparisons remain provisional until the
next scheduled census; no global link-closure result is asserted.

The complete pending source-path batch is the two commits based on
`6cdcea926b`, with one absorbed path. A tracked-tree search for the old path and
basename finds no active tooling, hook, workflow, include or build consumer.
Remaining mentions are provenance comments, historical attempt evidence and
the census-owned link_status.csv row, intentionally retained until its runner
refreshes it. The symbol's consumer declaration in Rva00339E80Finish.cpp still
uses the same name and ABI. Active function/TU ledgers resolve to Science.cpp;
protected registers and queues have no orphaned donor key. The pre-push batch
audit supplies the final selected-provider, lost-byte and freshness report;
an index older than the outgoing base cannot certify that base's census state.
