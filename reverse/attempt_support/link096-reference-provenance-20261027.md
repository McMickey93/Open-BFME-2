# LINK-096: reference provenance for consolidation previews

Inspected source revision: `a7a4b19a7d`. Provider index: `bf3dd31211`,
2026-10-27 00:39, retail-truth-4. This is a verifier prerequisite; no game
source, function row, census rule, or headline figure changes.

## Reproduction and boundary

The default picker served the six-file W3DDisplayString consolidation scope.
All six files passed `find_declared_unmatched.py`. The supported name-lane
planner and `tu_skeleton.py --merge ... --dry-run` reproduced the private
`UnicodeString::str_RV` empty-character definition refusal already documented
in [the native-layout handoff](w3d-displaystring-consolidation-20261026.md).
Zero donors were accepted. No game-source edits were retained.

The census index has an aggregate edge graph and reachable set. Removing an
old provider's definitions without removing its old reference contribution
keeps its private constant live. Subtracting roots from the aggregate is
unsafe: an outside object can independently supply an identical root or a
different copy of the same inline helper can supply the same edge.

## Separate verifier repair

`link_check.write_index` now saves each census object's roots, COMDAT edges,
weak-default routes, and index object digest. It checks the reconstructed
aggregate against the census graph and rechecks object digests before replacing
the index. A disagreement leaves the prior index intact. The optional proof
does not alter census selection or counting rules.

`LinkGuard.view` uses complete contributions bound to every indexed object
digest to rebuild references after removing absorbed and gone objects. It
retains outside roots, outside copies' edges, weak defaults, remaining linker
aliases, retail-address COMDAT roots, and ledger-owner roots. The candidate
then contributes its current references, including its own linker aliases.
An older, incomplete, malformed, or digest-mismatched proof keeps the old
conservative aggregate. Any ordinary preview mutation discards the immutable
object proof so it cannot later be mistaken for current census evidence.

Regression coverage includes real COFF extraction and index serialization,
unchanged old-index refusals, overlapping outside references, weak/alias
routes, retained retail and owner roots, removed/gone objects, candidate
references, invalidated preview proof, and publication refusal when the
aggregate or object bytes change. Existing merge, split, COMDAT-selection and
gate-exploit tests remain required.

Verification: `python3 -m pytest -q -rs tools/tests/test_link_check*.py
tools/tests/test_link_census*.py tools/tests/test_tu_skeleton*.py
tools/tests/test_gate_exploits.py` passed 544 tests and 32 subtests. One existing
gate-exploit parameterization was skipped because its fixture set is empty.
`git diff --check` also passed.

## Remaining prerequisites

The current published index predates this optional provenance. Its refusal is
intentionally unchanged. A maintainer's next ordinary census/index publication
must supply the new contributions before retrying the supported merge.
No census or nightly measurement was started for this change.

Constructor/destructor declaration reconciliation remains independently
necessary. No claim is made that all W3DDisplayString donors now compile
together, that the consolidation has landed, or that linked/image-ownership
figures improved.

The shared `docs/linking_obstacles.md` scope was held by another worker when
this handoff was prepared, so its existing LINK-096 entry was not edited.
Its next update should link this handoff, retain the constructor/destructor
blocker, and require a new provenance-bearing index before retrying.
