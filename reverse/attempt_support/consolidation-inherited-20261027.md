# Inherited TU merge handoff (2026-10-27)

Prepared publication of the pending ClickReactionBehavior and AIUnitBuilder merges from
`0bcdf574f6` and `c62b493a75` after rechecking them in the current checkout.

Both destination builds pass their matched rows (4/4 and 13/13), including the
AIUnitBuilder EH funclet pins. `find_declared_unmatched.py` reports no unmatched
definitions for either file. `data_check.py --converged` reports 0 duplicate
addresses across 10 addresses. The shadow data check still reports the existing
`_vtbl_00C4ED70` wrong-name finding in ClickReactionBehavior. The full code
identity gate still stops at an unverified `$L4775` funclet label; no identity
debt retirement is claimed.

The active tooling/path-consumer search found no references to absorbed source
paths outside the resulting AIUnitBuilder provenance comments and an existing
header comment. The previous consolidation review recorded no COMDAT shadow
findings. The outgoing link batch audit remains inconclusive against the stale
`bf3dd31211` census index; preserve that as pending next-census evidence rather
than claiming current census linkage.
