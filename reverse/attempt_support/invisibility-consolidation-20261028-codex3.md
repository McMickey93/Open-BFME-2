# InvisibilityUpdate bounded composition, 2026-10-28

Seat: yasinschroeder-codex3. Inspected base: `b861a801d6`.
Approved provisional destination:
`Code/GameEngine/Source/GameLogic/Object/Update/InvisibilityUpdate.cpp`.

## Placement and prerequisites

The default picker claimed the destination and all six whole-file donors.
The scoped `name_lane.py consolidate` report was reviewed: its original-path
catalogue and donor hints do not prove this provisional BFME 2 filename.
The committed map is stale; `tu_skeleton.py` rebuilds current approval in
memory. The current plan contains 23 approved rows, six whole-file donors
and four mixed sources. No regenerated map is committed.

The first supported dry run accepts only InvisibilityUpdateSlots.cpp.
`tu_views.py --dry-run` reports incompatible UpdateModule and
InvisibilityUpdate bases and competing secondary-interface slot declarations.
The constructor uses an explicit-vptr view; a forced unified class is not
established. The destructor, wake helper and transfer fragments need base
and declaration ordering reconciliation. The mixed getters and field-parser
source remain outside this bounded merge.

The prerequisite change adds the existing NameKeyType enum and the two
already-rowed name-key member declarations to the callback view. No method
body or layout member changes. The second supported dry run accepts Slots
and PoolKey together, preserving all 13 rows; the other four whole-file
donors remain rejected for the above reasons. No rejected donor was edited.

## Prerequisite verification

All six original donor files pass find_declared_unmatched. The destination
does not yet exist, so its pre-edit frozen-file query cannot read a file;
the post-composition check will cover the new TU.

Strict preparation verifies Slots and PoolKey: 13/13 rows, two string
references, no named imports or compiler float literals. After the declaration
change, ./build.sh verifies Slots 7/7; its frozen-file check passes.
EH verification across both sources reports all three graphs EXACT.
Scoped data checks report zero findings. The callback object preserves all
15 external COMDAT byte-and-symbolic-relocation digests, four strong
external definitions, 19 undefined externals and both weak externals.

Ordinary preview against index `41c28839bf` (2026-10-28 11:08) retains
LINKS for both units, 378 + 158 = 536 authored bytes. This preserves a
preview result and does not claim any new census-linked bytes, ownership,
runtime result or debt retirement.

Code identity shadow reports seven callback rows and zero new findings. Both
original units have clean Microsoft-header audits. The first batch audit
found a stale strict callback receipt after the new handoff file changed its
include-search inventory; bounded preparation is refreshed before the final
audit. This initial audit is not a clean consumer result.

After refreshed strict preparation, the staged-tree batch audit is still
INCONCLUSIVE: index 41c28839bf predates the base, and affected consumer
Common/0CreateAHeroManager21FE49.cpp lacks a current receipt. Carry that
consumer and the name-key/provider scope into the next normal census. Full
consumer coverage remains unverified.
