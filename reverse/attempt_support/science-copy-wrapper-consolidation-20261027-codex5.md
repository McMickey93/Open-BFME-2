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
