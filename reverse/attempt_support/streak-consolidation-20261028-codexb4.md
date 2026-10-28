# StreakLine setter consolidation, 2026-10-28

Inspected source base: `9e87a05faf`; outgoing base: `48fed8267a`.
Owner: `yasinschroeder-codexb4`. Preview index: `54b83e4f69`,
2026-10-28 09:35. These checks do not record a new census.

## Prerequisite and supported merge

The default picker served the approved streak.cpp TU. The WW3D2 naming
planner was regenerated after the prerequisite commit and passed its currency
check. Its private-view and original-path leads are investigation evidence;
the supported merge rebuilds the stale TU map in memory and admits only
approved rows. The committed map is not regenerated.

The SetPoints donor's SimpleDynVecClass<Vector3>::Shrink specialization is
semantically identical to the seed's. The composer normalizes whitespace but
preserves spaces adjacent to punctuation, so it previously retained both
definitions and hit C2995. Prerequisite `9e87a05faf` makes their spelling agree.
Both donor rows byte-match, and all seven external COMDAT byte/relocation
digests remain identical. No template behavior or compiler setting changes.

The supported merge accepts streak.cpp and StreakLineSetPoints.cpp, removes
one source file and preserves all 66 matched rows. The moved functions are
Set_Locs at 0x00742910 (113 bytes) and Set_LocsWidthsColors at 0x00742A90
(74 bytes). Only their source cells move in functions.csv and tu_map.csv;
names, extents, approval and provenance evidence stay unchanged.

The normal merged build passes 66/66, 11 floating literals and one named
import. Eleven renumbered funclet labels resolve through verified parent EH
data; the separate EH check reports three EXACT graphs. Frozen-file,
canonical-class, TU-ownership and CSV checks pass. Data checking reports zero
findings; the converged check judges 11 addresses with zero second names or
unjudged rows. Strict current receipts were prepared through link_check.

## Providers and consumers

The premerge union has 276 external COMDAT bodies; the merged object retains
275 with identical names, sizes and byte/relocation digests. The sole removed
body is the donor-private five-byte StreakLineClass::
Invalidate_Cached_Bounding_Volumes helper, digest `77650353a8e7`. It has no
incoming relocation edge or root reference in either input, the output, or
the saved census reference graph. The donor's inline use becomes the seed's
inherited cache invalidation, and both callers remain byte-exact.

All 58 exclusive definitions, 86 external dependencies and nine weak
externals are unchanged. Relocation roots and every surviving COMDAT edge
are identical; only the unreferenced helper's graph node disappears. The
three shared Count helpers already have identical copies in the seed.
Delete_All<Vector3> moves with its unchanged digest `5cefffc86464`.
Overlaying the merged object and removing the donor in the saved index
changes only the two moved setters' selected-provider states, both from
`ok` to `ok`; it introduces zero wrong selected variants among the 275
surviving bodies. This is a bounded comparison against the stated index.

The destination, destructor and texture getter preview LINKS for 5,575
authored bytes, preserving the four premerge sources' aggregate scope.
The destination's increase from 5,028 to 5,215 is the moved 187 bytes.
LightningDrawModuleDoParticles.cpp and StreakDrawModuleDoParticles.cpp also
receive strict receipts: all six caller rows and one data row verify, and
their previews retain LINKS for 1,740 and 913 authored bytes respectively.

The final staged batch audit is INCONCLUSIVE: the index predates the outgoing
base, and an affected shared-helper consumer,
Code/GameEngine/Source/Common/0CreateAHeroManager21FE49.cpp, lacks a current
receipt. The broad helper scope reaches many unchanged sources beyond these
direct callers. Full consumer selection awaits the next normal census;
no new census-linked bytes or image-ownership receipt is claimed.

## Paths, registers and remaining prerequisites

The outgoing path audit covers the prerequisite and merge from `48fed8267a`.
The only removed path is StreakLineSetPoints.cpp. A tracked-tree search for
its basename/path finds no active tool, hook, workflow, include, build/config
or registry consumer. Remaining mentions are the merged provenance comment,
historical attempt evidence, re_attempts.log and the historical link_status
receipt. Two obsolete current-location comments were removed. The directory
remains in use. No fold proof names the removed donor.

Neither input has header-queue, code-identity or data-baseline keys. The merge
refreshes the header/MS-header reports and retains the destination's existing
unverified array-delete declaration item. It transfers the donor's compiler
override counts into the seed (62 rows / 21 default-lost); hatch counters
refresh without a baseline delta. No debt retirement or hatch admission is
claimed. All active ledger sources resolve to tracked files.

The texture getter remains separate because its -O2 override differs from
the carried flags. The destructor remains separate: explicit SimpleVecClass
destructor specializations occur after seed instantiation (C2908), and prior
attempts also establish conflicting inline/out-of-line SimpleDynVecClass
destructor requirements. The two mixed getter sources remain outside this
merge. Future work must reconcile these compiler/declaration contracts with
target evidence before another supported merge; no rejected reconstruction
is retained in Code/.

## Publication verification and rebase

The original publication hook passes the full gate: 98,941/98,941 functions,
2,203 data rows, 31,537 string literals plus 2,248 empty-string references,
9,117 floating literals and 6,423 named imports. Whole-tree converged-data
checking also passes for 21,849 sources. The identity check reports the
unregistered divergent Vector3 copy-constructor key in shadow mode. The saved
seed and merged object both contain its same 25-byte body, digest
`79571e26f4e7`; the census already contains that variant in many providers.
This merge adds no COMDAT variant and does not retire the existing discrepancy.

The runner's first publication attempt rebases onto `88160d0cb7` and stops
only on concurrent append operations in ms_header_queue.tsv. Resolution keeps
upstream's DataChunk, ini and Upgrade entries and this merge's streak entry.
The clean BFME 1 checkout is synchronized to upstream's new gitlink,
`7c48cfd167`. The earlier full-gate result describes the original source base;
the resolved tree receives fresh verification before publication is retried.
